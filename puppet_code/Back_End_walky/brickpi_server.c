#include <stdio.h>
#include <stdlib.h>
#include <libwebsockets.h>

#include <math.h>
#include <time.h>
#include "tick.h"
#include <wiringPi.h>
#include "BrickPi.h"
#include <linux/i2c-dev.h>    
#include <fcntl.h>
#include "myBrickPiLibrary.h"
static int callback_http(struct libwebsocket_context * this,
                         struct libwebsocket *wsi,
                         enum libwebsocket_callback_reasons reason, void *user,
                         void *in, size_t len)
{
	return 0;
}

static int callback_dumb_increment(struct libwebsocket_context * this,
                                   struct libwebsocket *wsi,
                                   enum libwebsocket_callback_reasons reason,
                                   void *user, void *in, size_t len)
{
   
    switch (reason) {
        case LWS_CALLBACK_ESTABLISHED: // just log message that someone is connecting
            printf("connection established\n");
            break;
        case LWS_CALLBACK_RECEIVE: { // the funny part
            // create a buffer to hold our response
            // it has to have some pre and post padding. You don't need to care
            // what comes there, libwebsockets will do everything for you. For more info see
            // http://git.warmcat.com/cgi-bin/cgit/libwebsockets/tree/lib/libwebsockets.h#n597
            unsigned char *buf = (unsigned char*) malloc(LWS_SEND_BUFFER_PRE_PADDING + len +
                                                         LWS_SEND_BUFFER_POST_PADDING);
           
            int i;
			int length=0;
		
            // pointer to `void *in` holds the incomming request
            // we're just going to put it in reverse order and put it in `buf` with
            // correct offset. `len` holds length of the request.
            for (i=0; i < len; i++){
            	buf[LWS_SEND_BUFFER_PRE_PADDING + (len - 1) - i ] = ((char *) in)[i];
            }
			
			//((char *) in)[len-1]='#';
			printf("came here");
			printf("data received =%s",(char*)in);
			//char* data;
			//data=(char*)in;
			
			/*i=0;
			char command_data[50];
			int j=0;
			while(data[i]!='#'){
				if(data[i]!=',')
				{
					command_data[j]=data[i];
					printf("command %d =%c\n",j,command_data[j]);
					j++;
				}
				i++;
			}*/
			/*
			for(i=0;i<j;i++){
				if(command_data[i]=='8'){
					printf("go forward %d \n",i);
					go_forward();
				}
				else if(command_data[i]=='6'){
					printf("go right %d \n",i);
					go_right();
				}
			
				else if(command_data[i]=='4'){
					printf("go left %d \n",i);
					go_left();
				}
				else if(command_data[i]=='2'){
					printf("go back %d \n",i);
					go_back();
				}
				else if(command_data[i]=='0'){
					printf("turn around %d \n",i);
					turn_around();
				}
				else if(command_data[i]=='9'){
					printf("stopping %d \n",i);
					complete_stop();
				}
				
			usleep(3000000);
			
			}//end of for loop*/

            
			// log what we recieved and what we're going to send as a response.
            // that disco syntax `%.*s` is used to print just a part of our buffer
            // http://stackoverflow.com/questions/5189071/print-part-of-char-array
            printf("received data: %s, \n", (char *)in);
			printf("waiting for next command\n");
            // send response
            // just notice that we have to tell where exactly our response starts. That's
            // why there's `buf[LWS_SEND_BUFFER_PRE_PADDING]` and how long it is.
            // we know that our response has the same length as request because
            // it's the same message in reverse order.
            //libwebsocket_write(wsi, &buf[LWS_SEND_BUFFER_PRE_PADDING], len, LWS_WRITE_TEXT);
           
            // release memory back into the wild
            free(buf);
            break;
        }
        default:
            break;
    }
   
   
    return 0;
}

static struct libwebsocket_protocols protocols[] = {
    /* first protocol must always be HTTP handler */
    {
        "http-only",   // name
        callback_http, // callback
        0              // per_session_data_size
    },
    {
        "dumb-increment-protocol", // protocol name - very important!
        callback_dumb_increment,   // callback
        0                          // we don't use any per session data

    },
    {
        NULL, NULL, 0   /* End of list */
    }
};

void enable_motors(void){
	BrickPi.MotorEnable[PORT_A] = 1;
	BrickPi.MotorEnable[PORT_D] = 1;
	BrickPi.Timeout=0;
	BrickPiUpdateValues();
}

int main(){
	struct libwebsocket_context *context;
	struct lws_context_creation_info info;
	const char* interface= NULL;
	//memset(&info, 0, sizeof( info));
	info.port = 9000;
	info.iface = interface;
	info.protocols = protocols;
	info.extensions = NULL;
	info.ssl_cert_filepath = NULL;
	info.ssl_private_key_filepath = NULL;
	info.options = NULL;
	context = libwebsocket_create_context(&info);
	if (context == NULL){
		fprintf(stderr, "libwebsocket init failed\n");
		return -1;
	}
/*******************************brick pi init code*********************************/
/*int result=0; 
 ClearTick();
  result = BrickPiSetup();
  printf("BrickPiSetup: %d\n", result);
  if(result)
    return 0;
  BrickPi.Address[0] = 1;
  BrickPi.Address[1] = 2;
  enable_motors();
  result = BrickPiSetupSensors();
  printf("BrickPiSetupSensors: %d\n", result);
  if(!result){
  printf("BRICKPI_LOG:success\n");
  }*/
/*********************************************************************************/ 
 
printf("starting server...\n");
while (1) {
libwebsocket_service(context, 50);
} 
libwebsocket_context_destroy(context);
return 0;
}