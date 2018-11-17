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
#include "platform.h"


uint8_t data_set1[20] = {1 , 2 , 3 , 4 , 5 ,
			6 , 7 , 8 , 9 , 10,
			11, 12, 13, 14, 15,
			16, 17, 18, 19, 20};

/***********************************************************
 Function Definitions
***********************************************************/
int8_t course1(){
	//test_data1();
	//test_data2();
	test_memmove1();
	test_memmove2();
	test_memmove3();
	test_memcopy();
	/*test_memset();
	test_reverse();*/
	return 0;
}

int8_t test_data1(){
	uint8_t * local_ptr = (uint8_t*) malloc(34*sizeof(int8_t));
	uint8_t length;
	
	length = my_itoa(12345, local_ptr, 10);
	print_array_uint8(local_ptr,length);
	
	#ifdef VERBOSE
		PRINTF("\n Test Data is: %d", my_atoi(local_ptr, length, 10));
	#endif
	length = my_itoa(-12345, local_ptr, 10);
	print_array_uint8(local_ptr,length);
	
	#ifdef VERBOSE
		PRINTF("\n Test Data is: %d", my_atoi(local_ptr, length, 10));
	#endif
	length = my_itoa(-123, local_ptr, 2);
	print_array_uint8(local_ptr,length);
	
	#ifdef VERBOSE
		PRINTF("\n Test Data is: %d", my_atoi(local_ptr, length, 10));
	#endif
	length = my_itoa(-1234567, local_ptr, 16);
	print_array_uint8(local_ptr,length);
	
	#ifdef VERBOSE
		PRINTF("\n Test Data is: %d", my_atoi(local_ptr, length, 10));
	#endif
	free((void*)local_ptr);
	return 0;
}
/****************************************************************/
int8_t test_data2(){
	return 0;
}
/****************************************************************/
int8_t test_memmove1(){
	uint8_t *source=data_set1;
	uint8_t *destination = source + 25;
	
	destination = my_memmove(source,destination,20);
	#ifdef VERBOSE
		PRINTF("\n Test Movement No overlap ");
		PRINTF("\n Before Movement:\n ");
	#endif
	print_array_uint8(source,20);
	#ifdef VERBOSE
		PRINTF("\n After Movement:\n ");
	#endif
	print_array_uint8(destination,20);
	return 0;
}
/****************************************************************/
int8_t test_memmove2(){
	uint8_t *source=data_set1;
	uint8_t *destination = source - 5; // Destination start is before sourse start by 5 memory locations
	destination = my_memmove(source,destination,20);
	#ifdef VERBOSE
		PRINTF("\n Test Movement overlap End Dest, Start Source ");
		PRINTF("\n Before Movement:\n ");
	#endif
	print_array_uint8(source,20);
	#ifdef VERBOSE
		PRINTF("\n After Movement:\n ");
	#endif
	print_array_uint8(destination,20);
	return 0;
}
/****************************************************************/
int8_t test_memmove3(){
	uint8_t *source=data_set1;
	uint8_t *destination = source + 5;  // Destination start is after sourse start by 5 memory locations
	destination = my_memmove(source,destination,20);
	#ifdef VERBOSE
		PRINTF("\n Test Movement overlap Start Dest, End source ");
		PRINTF("\n Before Movement:\n ");
	#endif
	print_array_uint8(source,20);
	#ifdef VERBOSE
		PRINTF("\n After Movement:\n ");
	#endif
	print_array_uint8(destination,20);
	return 0;
}
/****************************************************************/
int8_t test_memcopy(){
	uint8_t *source=data_set1;
	uint8_t *destination = source + 25;  
	destination = my_memcopy(source,destination,20);
	#ifdef VERBOSE
		PRINTF("\n Test Copy No-overlap ");
		PRINTF("\n Before Copy:\n ");
	#endif	
	print_array_uint8(source,20);
	#ifdef VERBOSE
		PRINTF("\n After Copy:\n ");
	#endif
	print_array_uint8(destination,20);
	destination = source + 5;
	destination = my_memcopy(source,destination,20);
	#ifdef VERBOSE
		PRINTF("\n Test Copy overlap Start Dst, End Source ");
		PRINTF("\n Before Copy:\n ");
	#endif	
	print_array_uint8(source,20);
	#ifdef VERBOSE
		PRINTF("\n After Copy:\n ");
	#endif
	print_array_uint8(destination,20);
	return 0;
}
/****************************************************************/
int8_t test_memset(){
	uint8_t *my_memory = (uint8_t*) malloc(10*sizeof(int8_t));
	my_memory = my_memset(my_memory,10,6);
	print_array_uint8(my_memory,10);
	my_memory = my_memzero(my_memory,10);
	print_array_uint8(my_memory,10);
	free((void*)my_memory);
	return 0;
}

/****************************************************************/
int8_t test_reverse(){
	uint8_t *my_memory = (uint8_t*) malloc(20*sizeof(int8_t));
	my_memory = my_memzero(my_memory,20);
	my_memory = my_memcopy(data_set1,my_memory,15);
	print_array_uint8(my_memory,20);
	my_memory = my_reverse(my_memory,20);
	print_array_uint8(my_memory,20);
	free((void*)my_memory);
	return 0;
}

