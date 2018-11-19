/******************************************************************************
 * Copyright (C) 2018 by Ashraf Abdalraheem
 *
 * Redistribution, modification or use of this software in source or binary
 * forms is permitted as long as the files maintain this copyright. Users are 
 * permitted to modify this and use it to learn about the field of embedded
 * software. Ashraf Abdalraheem are not liable for any
 * misuse of this material. 
 *
 * This code is designed as a part of assignment belongs to the online course of Introduction to 
 * Embedded Software & Development Environment which is a part of Embedded Software Essential Specialization
 * Provided by University of Colorado Boulder and Coursera By Alex Fosdick
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
#include <stdlib.h> 
#include "memory.h"
/***********************************************************
 Function Definitions
***********************************************************/

uint8_t my_itoa(int32_t data, uint8_t * ptr, uint32_t base){
	// Check the validty of data
	if (ptr==NULL){
		return 0; // pointer is not assigned to any memory location;
	}
	if((base>16)||(base<2)){
		return 0; // base is not correct
	}
	uint8_t *start_address = ptr;
	uint8_t length=1;
	uint8_t temp_length;
	uint8_t ASCII_start;
	if(data<0){ // If the data is negative the MSD is the negative sign
		*ptr = 45; // Decimal equivelant of "-" sign
		ptr++;
		data=data*-1; // Convert the data into positive
		length++;
	}
	while(length<=32) // Dismantle the number into individual digits by dividing by base;
	{                 // The most significant digit will be at the last location.
		
		*ptr = data%base;  // Store the modulus	
		data = data/base;  // Shift the data to the right
		if(*ptr>9){
			ASCII_start = 65; // if the number is 10 and above it should be A, B, ...
		}else{
			ASCII_start = 48;
		}
		
		*ptr = *ptr + ASCII_start; // Convert to the ASCII equivelant.
		ptr++;            // point to the next location
		length++;    
		if((data==0)){    // The number division is completed
			(*ptr) = 0; // Terminate by NULL
			break; 
		}
	}
	temp_length = length;
	if(*start_address==45){ // If the number is negative point to the next location
		ptr = start_address+1;
		temp_length = temp_length -2;
	}else{
		ptr = start_address;
		temp_length = temp_length -1;
	}	
	ptr = my_reverse(ptr, temp_length); // Reverse the order so That the first location 
	 				    // Points to the most significant digit (MSD)
	
	return length;
}

int32_t my_atoi(uint8_t * ptr, uint8_t digits, uint32_t base){
	// Check the validty of data
	if (ptr==NULL){
		return 0; // pointer is not assigned to any memory location;
	}
	if((base>16)||(base<2)){
		return 0; // base is not correct
	}	
	uint8_t *start_address = ptr;
	uint8_t length = 1;
	uint8_t ASCII_start = 48;
	int32_t data,integer_number=0;
	int32_t data_sign = 1;
	if(*start_address == 45){ // check the if negative sign is proceeding the string data
		data_sign = -1;
		ptr++;  // point to the next location
	}
	
	while((length<digits)&&(*ptr != 0)){
		data = *ptr - ASCII_start;
		if(data > 9){ //  base is more than 10 and digit is A, B, ...
			data -= 17; // To obtain the decimal equivelant of A, B, ...
		}
		if((data > 15)||(data < 0)){		
			break; // Data is not correct the conversion stops here only. 
		}
		integer_number = integer_number*base +data;
		ptr++; // point to the next location;
		length++;
	}
	ptr = start_address; // point to the first location again
	return data_sign*integer_number;
}
