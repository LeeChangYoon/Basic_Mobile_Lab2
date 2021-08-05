/*
 * Utilities.h
 *
 * Created: 04/08/2021
 * Author: Lee Chang Yoon
 */ 


#ifndef UTILITIES_H_
#define UTILITIES_H_

#include "avr_lib.h"

#define MAX_NUMBER_OF_DIGITS 10

int Convert_From_String_To_Int(unsigned char* p_number);
u08 Compare_Two_Strings(unsigned char* first , unsigned char* second);


#endif /* UTILITIES_H_ */
