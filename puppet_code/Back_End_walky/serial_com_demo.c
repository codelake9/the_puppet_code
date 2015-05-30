#include "my_walky_lib.h"
int main (void)
{
setup_walky();
int user_input;
  while(1)
  {
  printf("\nuser_input=");
	
		scanf("%d",&user_input);
	
	fflush(stdin);
	
	if(user_input==1)
	{
	go_forward(3);
	}	
  
  }
 
  
  serialPuts (handle,"THIS IS THE MSG FROM RASPI :)");
  serialClose(handle);
printf("\n********************COMPORT CLOSED*********************\n");	
  printf("\n**********************END**************************************\n");
 return 0 ;
 }

