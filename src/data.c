/******************************************************************************
 * Copyright (C) 2018 by Ashraf Abdalraheem
 *
 * Redistribution, modification or use of this software in source or binary
 * forms is permitted as long as the files maintain this copyright. Users are 
 * permitted to modify this and use it to learn about the field of embedded
 * software. Ashraf Abdalraheem are not liable for any
 * misuse of this material. 
 *
 *****************************************************************************/
/**
 * @file data.c
 * @brief Basic Data Manipulation
 *
 * This implementation file provides a basic manipulation of data
 *
 * @author Ashraf Abdalraheem
 * @date Nov 14 2018
 *
 */
#include "data.h"

/***********************************************************
 Function Definitions
***********************************************************/

uint8_t my_itoa(int32_t data, uint8_t * ptr, uint32_t base){
	uint8_t *Start_Address = ptr;
	uint8_t length=1;
	uint8_t temp_length;
	if(data<0){ // If the data is negative the MSD is the negative sign
		*ptr = 45; // Decimal equivelant of "-" sign
		ptr++;
		data=data*-1; // Convert the data into positive
		length++;
	}
	while(length<=32) // Dismantle the number into individual digits by dividing by 10;
	{                 // The most significant digit will be at the last location.
		
		*ptr = data%10;  // Store the modulus
		data = data/10;  // Shift the data to the right
		*ptr = *ptr + 48; // Convert to the decimal ASCII equivelant.
		ptr++;            // point to the next location
		length++;    
		if((data==0)){ // The number division is completed
			*ptr=NULL; // Terminate by NULL
			break; 
		}
	}
	temp_length = length;
	if(*Start_Address==45){ // If the number is negative point to the next location
		ptr = Start_Address+1;
		temp_length = temp_length -2;
	}else{
		ptr = Start_Address;
		temp_length = temp_length -1;
	}
	ptr = my_reverse(ptr, temp_length); // Reverse the order so That the first location 
										// Points to the most significant digit (MSD)
	
	
	
	return length;
}