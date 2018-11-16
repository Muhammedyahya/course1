/******************************************************************************
 * Copyright (C) 2018 by Ashraf Abdalraheem
 *
 * Redistribution, modification or use of this software in source or binary
 * forms is permitted as long as the files maintain this copyright. Users are 
 * permitted to modify this and use it to learn about the field of embedded
 * software. Ashraf Abdalraheem are not liable for any
 * misuse of this material. 
 * This code is designed as a part of assignment belongs to the online course of Introduction to 
 * Embedded Software & Development Environment which is a part of Embedded Software Essential Specialization
 * Provided by University of Colorado Boulder and Coursera By Alex Fosdick
 *****************************************************************************/
/**
 * @file course1.c
 * @brief Test memory and data manipulation
 *
 * This implementation file provides functions to test the data and memory manipulation functions
 *
 * @author Ashraf Abdalraheem
 * @date Nov 16 2018
 *
 */
#include "course1.h"
#include "memory.h"
#include "data.h"
#include "stats.h"
#include <stdlib.h>

int8_t data_set1[20] = {1 , 2 , 3 , 4 , 5 ,
			6 , 7 , 8 , 9 , 10,
			20, 22, 24, 26, 28,
			33, 33, 44, 44, 55};

/***********************************************************
 Function Definitions
***********************************************************/
int8_t course1(){
	test_data1();
	test_data2();
	test_memmove1();
	test_memmove2();
	test_memmove3();
	test_memcopy();
	test_memset();
	test_memreverse();
	return NULL;
}

int8_t test_data1(){
	int8_t *local_ptr = (*int8_t) malloc(34*sizeof(int8_t));
	uint8_t length;
	int32_t local_data;
	length = my_itoa(12345, locat_ptr, 10);
	print_array(local_ptr,length);
	local_data = my_atoi(local_ptr, length, 10);
	#ifdef VERBOSE
		printf("\n Test Data is: %ld", local_data);
	#endif
	length = my_itoa(-12345, locat_ptr, 10);
	print_array(local_ptr,length);
	local_data = my_atoi(local_ptr, length, 10);
	#ifdef VERBOSE
		printf("\n Test Data is: %ld", local_data);
	#endif
	length = my_itoa(-123, locat_ptr, 2);
	print_array(local_ptr,length);
	local_data = my_atoi(local_ptr, length, 10);
	#ifdef VERBOSE
		printf("\n Test Data is: %ld", local_data);
	#endif
	length = my_itoa(-1234567, locat_ptr, 16);
	print_array(local_ptr,length);
	local_data = my_atoi(local_ptr, length, 10);
	#ifdef VERBOSE
		printf("\n Test Data is: %ld", local_data);
	#endif
	free((void*)local_ptr);
	return NULL;
}
/****************************************************************/
int8_t test_data2(){
	return NULL;
}
/****************************************************************/
int8_t test_memmove1(){
	int8_t *source=data_set1;
	int8_t *destination = source + 25;
	destination = my_memmove(source,destination,20);
	print_array(source,20);
	print_array(destination,20);
	return NULL;
}
/****************************************************************/
int8_t test_memmove2(){
	int8_t *source=data_set1;
	int8_t *destination = source - 5; // Destination start is before sourse start by 5 memory locations
	destination = my_memmove(source,destination,20);
	print_array(source,20);
	print_array(destination,20);
	return NULL;
}
/****************************************************************/
int8_t test_memmove3(){
	int8_t *source=data_set1;
	int8_t *destination = source + 5;  // Destination start is after sourse start by 5 memory locations
	destination = my_memmove(source,destination,20);
	print_array(source,20);
	print_array(destination,20);
	return NULL;
}
/****************************************************************/
int8_t test_memcopy(){
	int8_t *source=data_set1;
	int8_t *destination = source + 25;  
	destination = my_memcopy(source,destination,20);
	print_array(source,20);
	print_array(destination,20);
	destination = source + 5;
	destination = my_memcopy(source,destination,20);
	print_array(source,20);
	print_array(destination,20);
	return NULL;
}
/****************************************************************/
int8_t test_memset(){
	int8_t *my_memory = (*int8_t) malloc(10*sizeof(int8_t));
	my_memory = my_memset(my_memory,10,6);
	print_array(my_memory,10);
	my_memory = my_memzero(my_memory,10);
	print_array(my_memory,10);
	free((*void)my_memory);
	return NULL;
}

/****************************************************************/
int8_t test_memreverse(){
	int8_t *my_memory = (*int8_t) malloc(20*sizeof(int8_t));
	my_memory = my_memzero(my_memory,20);
	my_memory = my_memcopy(data_set1,my_memory,15);
	print_array(my_memory,20);
	my_memory = my_memreverse(my_memory,20);
	print_array(my_memory,20);
	free((*void)my_memory);
	return NULL;
}

