#include <stdio.h>
#include <wiringPi.h>
#include <wiringSerial.h>
#define STATUS_PIN  27
int handle;
char buffer[32];
int  setup_walky()
{
if (wiringPiSetupSys() == -1)
return 1 ;
else
printf("done initing wiring pi\n");
pinMode (STATUS_PIN, INPUT);


  handle = serialOpen ("/dev/ttyAMA0", 9600) ;
  if(handle<0)
  printf("\n********************Unable to open comport*******************\n");
  else 
  printf("\n********************SUCCESS FOUND COMPORT*********************\n");
}

void go_forward(int steps_count)
{
sprintf(buffer,"1%02d.",steps_count);
	printf("msg=%s",buffer);
serialPuts(handle,buffer);
printf("msg sent waiting now for status to become 1!\n");
sleep(1);
while(digitalRead(STATUS_PIN)==0);
printf("got status =1\n");
}

void go_back(int steps_count)
{
sprintf(buffer,"2%02d.",steps_count);
	printf("msg=%s",buffer);
serialPuts(handle,buffer);
printf("msg sent waiting now for status to become 1!\n");
sleep(1);
while(digitalRead(STATUS_PIN)==0);
printf("got status =1\n");
}

void go_left(int steps_count)
{
sprintf(buffer,"4%02d.",steps_count);
	printf("msg=%s",buffer);
serialPuts(handle,buffer);
printf("msg sent waiting now for status to become 1!\n");
sleep(1);
while(digitalRead(STATUS_PIN)==0);
printf("got status =1\n");
}
void go_right(int steps_count)
{
sprintf(buffer,"3%02d.",steps_count);
	printf("msg=%s",buffer);
serialPuts(handle,buffer);
printf("msg sent waiting now for status to become 1!\n");
sleep(1);
while(digitalRead(STATUS_PIN)==0);
printf("got status =1\n");
}