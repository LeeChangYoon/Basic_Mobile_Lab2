/*
 * CommandExecutor.h
 *
 * Created: 04/08/2021
 * Author: Lee Chang Yoon
 */ 


#include "avr_lib.h"
#include "Robot.h"
#include "UART.h"
#include "Utilities.h"

#ifndef COMMANDEXECUTOR_H_
#define COMMANDEXECUTOR_H_

u08 (*Command_Function)(unsigned char** ,u08);
u08 (*Data_Function)(unsigned char** ,u08);
u08 Execute_Command(unsigned char* p_CommandSignature , unsigned char** p_ArrayOfParameter , int p_NumberOfParameters);
u08 Process_Data(unsigned char* p_CommandSignature , unsigned char** Data , u08 p_NumberOfData);



#endif /* COMMANDEXECUTOR_H_ */
