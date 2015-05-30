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

#undef DEBUG

void delay_ms(int ms)
{
}
void go_forward()
{
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
	int slave_power=100;
	int error;
	ClearTick();
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
	printf("\nGoing forward completed.\n");
	printf("\n");
}

void go_back(void){
	printf("\nGoing back...\n");
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
	
	int master_power=-100;
	int slave_power=-100;
	int error;
	ClearTick();
	while(BrickPi.Encoder[PORT_A]>-700){
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
	printf("\nGoing back completed.\n");
	printf("\n");
}

void go_left(void){
	printf("\nTurning left...\n");	
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
	
	int master_power=-100;
	int slave_power=100;
	int error;
	ClearTick();

	while(BrickPi.Encoder[PORT_D]<140){
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
	printf("\nTurning left completed.\n");
	printf("\n");
}

void go_right(void){
	printf("\nTurning right...\n");	
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

	while(BrickPi.Encoder[PORT_A]<140){
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
	printf("\nTurning right completed.\n");
	printf("\n");
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

void complete_stop(void){
	printf("\nStopping...\n");	
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
	
	int master_power=0;
	int slave_power=0;
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
	printf("\nStop completed.\n");
	printf("\n");
}
