/*
 * RoboCar_Framework.c
 *
 * Created: 04/08/2021
 *  Author: Lee Chang Yoon
 */ 

#include "Robot.h"

int main ()
{
	Initialize_Me();
	ms_delay(3000);
	BEEP_ON();
	ms_delay(100);
	BEEP_OFF();
	ms_delay(100);
	unsigned char* c = (unsigned char*)"PTH 4,F,2,R,1,F$";
	Split_Data(c);
	//sendbytes(c);
	sei();
	while(1);
	//unsigned char* c = (unsigned char*)"CTS#";
	//Split_Command(c);
	
}
