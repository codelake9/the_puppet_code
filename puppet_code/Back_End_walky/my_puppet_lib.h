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



void Say_Hello(void)
{
sprintf(buffer,"%c",'a');
printf("msg=%s",buffer);
serialPuts(handle,buffer);
printf("msg sent waiting now for status to become 1!\n");
sleep(1);
while(digitalRead(STATUS_PIN)==0);
printf("got status =1\n");
}


void Jump(void)
{
sprintf(buffer,"%c",'1');
printf("msg=%s",buffer);
serialPuts(handle,buffer);
printf("msg sent waiting now for status to become 1!\n");
sleep(1);
while(digitalRead(STATUS_PIN)==0);
printf("got status =1\n");
}


void Dance(void)
{
sprintf(buffer,"%c",'C');
printf("msg=%s",buffer);
serialPuts(handle,buffer);
printf("msg sent waiting now for status to become 1!\n");
sleep(1);
while(digitalRead(STATUS_PIN)==0);
printf("got status =1\n");
}



void Take_a_Pic(void)
{
sprintf(buffer,"%c",'d');
printf("msg=%s",buffer);
serialPuts(handle,buffer);
printf("msg sent waiting now for status to become 1!\n");
sleep(1);
while(digitalRead(STATUS_PIN)==0);
printf("got status =1\n");
}


void Green_Goblin(void)
{
sprintf(buffer,"%c",'e');
printf("msg=%s",buffer);
serialPuts(handle,buffer);
printf("msg sent waiting now for status to become 1!\n");
sleep(1);
while(digitalRead(STATUS_PIN)==0);
printf("got status =1\n");
}

void See_my_Costume(void)
{
sprintf(buffer,"%c",'f');
printf("msg=%s",buffer);
serialPuts(handle,buffer);
printf("msg sent waiting now for status to become 1!\n");
sleep(1);
while(digitalRead(STATUS_PIN)==0);
printf("got status =1\n");
}

void Say_Bye(void)
{
sprintf(buffer,"%c",'g');
printf("msg=%s",buffer);
serialPuts(handle,buffer);
printf("msg sent waiting now for status to become 1!\n");
sleep(1);
while(digitalRead(STATUS_PIN)==0);
printf("got status =1\n");
}

void Walk(void)
{
sprintf(buffer,"%c",'h');
printf("msg=%s",buffer);
serialPuts(handle,buffer);
printf("msg sent waiting now for status to become 1!\n");
sleep(1);
while(digitalRead(STATUS_PIN)==0);
printf("got status =1\n");
}




