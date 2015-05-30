
#include <stdio.h>
#include <math.h>
#include <time.h>

#include "tick.h"

#include <wiringPi.h>

#include "BrickPi.h"

//#include <unistd.h>  
//#include <errno.h>  
//#include <stdio.h>  
//#include <stdlib.h>  
#include <linux/i2c-dev.h>  
//#include <sys/ioctl.h>  
#include <fcntl.h>

// gcc -o program "Test BrickPi lib.c" -lrt -lm -L/usr/local/lib -lwiringPi
// gcc -o program "Test BrickPi lib.c" -lrt
// ./program

int result,val;
#undef DEBUG

void enable_motors(void);
void go_forward(void);
void go_back(void);
void go_right(void);
void go_left(void);
void delay_ms(int);

int main() {

/*******************************brick pi init code*********************************/
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
  }
/*********************************************************************************/ 
 
  if(!result){
  	turn_around();
  	usleep(3000000);	
  	//go_right();
  	//usleep(3000000);	
  	//go_back();
		if(0){
			printf("started\n");
			BrickPi.EncoderOffset[PORT_D] = BrickPi.Encoder[PORT_D];  
    		BrickPi.EncoderOffset[PORT_A] = BrickPi.Encoder[PORT_A];
			usleep(100000);
			BrickPiUpdateValues();
			printf("intial value= A= %d  D=%d\n",BrickPi.Encoder[PORT_A],BrickPi.Encoder[PORT_D]);
	
	
			int master_power=100;
			int slave_power=100;
			int error;
	
			BrickPiUpdateValues();
			while(BrickPi.Encoder[PORT_A]<700){	
				error=BrickPi.Encoder[PORT_A]-BrickPi.Encoder[PORT_D];	
				slave_power=slave_power+error/7;
				BrickPi.MotorSpeed[PORT_A]=master_power;
				BrickPi.MotorSpeed[PORT_D]=slave_power;
				BrickPiUpdateValues();
				usleep(100000);
			}
			usleep(1000);
			BrickPiUpdateValues();
			printf("difference=A_D %d  ",BrickPi.Encoder[PORT_A]-BrickPi.Encoder[PORT_D]);
		}
  
	   /*
	   go_right();
	   usleep(2000000);
	   go_forward();
	   go_left();
       usleep(100);
	   */
    }
  
  return 0;
}

void enable_motors(void){
	BrickPi.MotorEnable[PORT_A] = 1;
	BrickPi.MotorEnable[PORT_D] = 1;
	BrickPi.Timeout=0;
	BrickPiUpdateValues();
}

void delay_ms(int ms){
	usleep(ms*1000);
}

void turn_around(void){
	printf("\nTurning around...\n");	
	BrickPiUpdateValues();
	usleep(1000);
	printf("before loop loop A= %d  D=%d\n",BrickPi.Encoder[PORT_A],BrickPi.Encoder[PORT_D]);
	
	while(BrickPi.Encoder[PORT_A]!=0 || BrickPi.Encoder[PORT_D]!=0){
		BrickPi.EncoderOffset[PORT_A] = BrickPi.Encoder[PORT_A];
		BrickPi.EncoderOffset[PORT_D] = BrickPi.Encoder[PORT_D]; 
		usleep(1000);
		BrickPi.MotorSpeed[PORT_A]=0;
		BrickPi.MotorSpeed[PORT_D]=0;
		BrickPiUpdateValues();
		printf("in loop A= %d  D=%d\n",BrickPi.Encoder[PORT_A],BrickPi.Encoder[PORT_D]);
	}	
	
	printf("after offset= A= %d  D=%d\n",BrickPi.Encoder[PORT_A],BrickPi.Encoder[PORT_D]);
	
	int master_power=100;
	int slave_power=-100;
	int error;
	ClearTick();

	while(BrickPi.Encoder[PORT_D]>-720){
		error=(BrickPi.Encoder[PORT_A])-(-BrickPi.Encoder[PORT_D]);	
		slave_power=slave_power-error/7;
		BrickPi.MotorSpeed[PORT_A]=master_power;
		BrickPi.MotorSpeed[PORT_D]=slave_power;
		BrickPiUpdateValues();
		usleep(100000);
	}
	usleep(1000);
	BrickPiUpdateValues();
	printf("At the end value=%d\n",BrickPi.Encoder[PORT_D]);
	printf("difference=A_D %d \n ",(BrickPi.Encoder[PORT_A])-(-BrickPi.Encoder[PORT_D]));
	printf("\nTurning around completed.\n");
	printf("\n");
}

void go_forward(void){	
	printf("i am go forward\n");
	BrickPiUpdateValues();
	usleep(1000);
	printf("before loop loop A= %d  D=%d\n",BrickPi.Encoder[PORT_A],BrickPi.Encoder[PORT_D]);
	while(BrickPi.Encoder[PORT_A]!=0 || BrickPi.Encoder[PORT_D]!=0)
	{
	BrickPi.EncoderOffset[PORT_A] = BrickPi.Encoder[PORT_A];
	BrickPi.EncoderOffset[PORT_D] = BrickPi.Encoder[PORT_D]; 
	usleep(1000);
	BrickPi.MotorSpeed[PORT_A]=0;
	BrickPi.MotorSpeed[PORT_D]=0;
	BrickPiUpdateValues();
	printf("in loop A= %d  D=%d\n",BrickPi.Encoder[PORT_A],BrickPi.Encoder[PORT_D]);
}
	
	printf("after offset= A= %d  D=%d\n",BrickPi.Encoder[PORT_A],BrickPi.Encoder[PORT_D]);
	//while(1);
	
	int master_power=100;
	int slave_power=100;
	int error;
	ClearTick();
	while(BrickPi.Encoder[PORT_A]<700)
	{
		
		error=BrickPi.Encoder[PORT_A]-BrickPi.Encoder[PORT_D];	
		slave_power=slave_power+error/7;
		BrickPi.MotorSpeed[PORT_A]=master_power;
		BrickPi.MotorSpeed[PORT_D]=slave_power;
		BrickPiUpdateValues();
		usleep(100000);
	
	}
	usleep(1000);
	BrickPiUpdateValues();
	printf("difference=A_D %d  ",BrickPi.Encoder[PORT_A]-BrickPi.Encoder[PORT_D]);
}

void go_back(void)
{
		printf("beep beep going back\n");
	BrickPiUpdateValues();
	usleep(1000);
	printf("before loop loop A= %d  D=%d\n",BrickPi.Encoder[PORT_A],BrickPi.Encoder[PORT_D]);
	while(BrickPi.Encoder[PORT_A]!=0 || BrickPi.Encoder[PORT_D]!=0)
	{
	BrickPi.EncoderOffset[PORT_A] = BrickPi.Encoder[PORT_A];
	BrickPi.EncoderOffset[PORT_D] = BrickPi.Encoder[PORT_D]; 
	usleep(1000);
	BrickPi.MotorSpeed[PORT_A]=0;
	BrickPi.MotorSpeed[PORT_D]=0;
	BrickPiUpdateValues();
	printf("in loop A= %d  D=%d\n",BrickPi.Encoder[PORT_A],BrickPi.Encoder[PORT_D]);
	}
	
	printf("after offset= A= %d  D=%d\n",BrickPi.Encoder[PORT_A],BrickPi.Encoder[PORT_D]);
	//while(1);
	
	int master_power=-100;
	int slave_power=-100;
	int error;
	ClearTick();
	while(BrickPi.Encoder[PORT_A]>-700)
	{
		
		error=(-BrickPi.Encoder[PORT_A])-(-BrickPi.Encoder[PORT_D]);	
		slave_power=slave_power-error/7;
		BrickPi.MotorSpeed[PORT_A]=master_power;
		BrickPi.MotorSpeed[PORT_D]=slave_power;
		BrickPiUpdateValues();
		usleep(100000);
	
	}
	usleep(1000);
	BrickPiUpdateValues();
	printf("difference=A_D %d  ",BrickPi.Encoder[PORT_A]-BrickPi.Encoder[PORT_D]);

}

void go_left(void)
{
	printf("\n go left\n");	
	BrickPiUpdateValues();
	usleep(1000);
	printf("before loop loop A= %d  D=%d\n",BrickPi.Encoder[PORT_A],BrickPi.Encoder[PORT_D]);
	while(BrickPi.Encoder[PORT_A]!=0 || BrickPi.Encoder[PORT_D]!=0)
	{
	BrickPi.EncoderOffset[PORT_A] = BrickPi.Encoder[PORT_A];
	BrickPi.EncoderOffset[PORT_D] = BrickPi.Encoder[PORT_D]; 
	usleep(1000);
	BrickPi.MotorSpeed[PORT_A]=0;
	BrickPi.MotorSpeed[PORT_D]=0;
	BrickPiUpdateValues();
	printf("in loop A= %d  D=%d\n",BrickPi.Encoder[PORT_A],BrickPi.Encoder[PORT_D]);
	}	
	
	
	
	printf("after offset= A= %d  D=%d\n",BrickPi.Encoder[PORT_A],BrickPi.Encoder[PORT_D]);
	int master_power=-100;
	int slave_power=100;
	int error;
	ClearTick();
	while(BrickPi.Encoder[PORT_D]<140)
	{
		
		error=(-BrickPi.Encoder[PORT_A])-BrickPi.Encoder[PORT_D];	
		slave_power=slave_power+error/7;
		BrickPi.MotorSpeed[PORT_A]=master_power;
		BrickPi.MotorSpeed[PORT_D]=slave_power;
		BrickPiUpdateValues();
		usleep(100000);
	
	}
	usleep(1000);
	BrickPiUpdateValues();
	printf("difference=A_D %d  ",(-BrickPi.Encoder[PORT_A])-BrickPi.Encoder[PORT_D]);
}

void go_right(void)
{
printf("\n go right\n");	
	BrickPiUpdateValues();
	usleep(1000);
	printf("before loop loop A= %d  D=%d\n",BrickPi.Encoder[PORT_A],BrickPi.Encoder[PORT_D]);
	while(BrickPi.Encoder[PORT_A]!=0 || BrickPi.Encoder[PORT_D]!=0)
	{
	BrickPi.EncoderOffset[PORT_A] = BrickPi.Encoder[PORT_A];
	BrickPi.EncoderOffset[PORT_D] = BrickPi.Encoder[PORT_D]; 
	usleep(1000);
	BrickPi.MotorSpeed[PORT_A]=0;
	BrickPi.MotorSpeed[PORT_D]=0;
	BrickPiUpdateValues();
	printf("in loop A= %d  D=%d\n",BrickPi.Encoder[PORT_A],BrickPi.Encoder[PORT_D]);
	}	
	
	
	
	printf("after offset= A= %d  D=%d\n",BrickPi.Encoder[PORT_A],BrickPi.Encoder[PORT_D]);
	int master_power=100;
	int slave_power=-100;
	int error;
	ClearTick();
	while(BrickPi.Encoder[PORT_A]<140)
	{
		
		error=(BrickPi.Encoder[PORT_A])-(-BrickPi.Encoder[PORT_D]);	
		slave_power=slave_power-error/7;
		BrickPi.MotorSpeed[PORT_A]=master_power;
		BrickPi.MotorSpeed[PORT_D]=slave_power;
		BrickPiUpdateValues();
		usleep(100000);
	
	}
	usleep(1000);
	BrickPiUpdateValues();
	printf("difference=A_D %d  ",(-BrickPi.Encoder[PORT_A])-BrickPi.Encoder[PORT_D]);


}

