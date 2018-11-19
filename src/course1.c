/******************************************************************************
 * Copyright (C) TEST_ARRAY_SIZE18 by Ashraf Abdalraheem
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
 * @date Nov 16 TEST_ARRAY_SIZE18
 *
 */
#include "course1.h"
#include "memory.h"
#include "data.h"
#include "stats.h"
#include "platform.h"



/* 	LOCAL FUNCTION
 * @brief Test Data between two memory location if equal return TRUE, Else return false
 *
 * 
 * @param source1 pointer to first memory location
 * @param source2 pointer to second memory location
 * @return TRUE/FALSE
 */
static int8_t my_compare(uint8_t* source1,uint8_t* source2, uint8_t length);
/*
 * @brief Test Data between a memory location and value if equal return TRUE, Else return false
 *
 * 
 * @param source1 pointer to first memory location
 * @param value to compare with
 * @return TRUE/FALSE
 */
static int8_t my_compare_set(uint8_t* source1,uint8_t value, uint8_t length);
/***********************************************************
 Define const
***********************************************************/
#define OVERLAP1 7
#define OVERLAP2 11
#define TEST_ARRAY_SIZE 20
#define NO_OVER_LAP 25
#define SET_VALUE 7
#define TRUE 1
#define FALSE 0
/***********************************************************
 Global variables
***********************************************************/
uint8_t data_set1[TEST_ARRAY_SIZE+20]= {1 , 2 , 3 , 4 , 5 ,
					6 , 7 , 8 , 9 , 10,
					11, 12, 13, 14, 15,
					16, 17, 18, 19, 20};
uint8_t data_set2[TEST_ARRAY_SIZE] =   {1 , 2 , 3 , 4 , 5 ,
					6 , 7 , 8 , 9 , 10,
					11, 12, 13, 14, 15,
					16, 17, 18, 19, 20};
const char *test_result[2] = {"FAIL", "PASS"};
/***********************************************************
 Function Definitions
***********************************************************/
int8_t course1(){	
	PRINTF("\nTest Data 1 function result: %s\n\n",test_result[test_data1()]);
	PRINTF("\nTest Data 2 function result: %s\n\n",test_result[test_data2()]);
	PRINTF("\nTest Move Data 1 function result: %s\n\n",test_result[test_memmove1()]);
	PRINTF("\nTest Move Data 2 function result: %s\n\n",test_result[test_memmove2()]);
	PRINTF("\nTest Move Data 3 function result: %s\n\n",test_result[test_memmove3()]);
	PRINTF("\nTest Copy Data function result: %s\n\n",test_result[test_memcopy()]);
	PRINTF("\nTest Set Data function result: %s\n\n",test_result[test_memset()]);
	PRINTF("\nTest Memory Reverse function result: %s\n\n\n",test_result[test_reverse()]);
	/*
	test_data2();
	test_memmove1();
	test_memmove2();
	test_memmove3();
	test_memcopy();
	test_memset();
	test_reverse();
	*/
	return 0;
}

int8_t test_data1(){
	uint8_t * local_ptr = (uint8_t*) malloc(34*sizeof(int8_t));
	uint8_t length;
	int32_t ItoA_number = -3341209;
	int32_t AtoI_number;
	uint8_t base;
	base = 2;
	length = my_itoa(ItoA_number, local_ptr, base);
	AtoI_number = my_atoi(local_ptr, length, base);
	#ifdef VERBOSE 
		PRINTF("\n ************************************************************************\n ");		
		PRINTF("\n------------------- test_data1 -------------------- ");		
		PRINTF("\n Test 5 Data is: %d  Base is : %d \n Converted Back: %d", ItoA_number,base,AtoI_number);
		print_array_uint8(local_ptr,length);
	#endif	
	free((void*)local_ptr);
	if(AtoI_number != ItoA_number)
	{
		return FALSE;
	}
	return TRUE;
}
/****************************************************************/
int8_t test_data2(){
	 
	uint8_t * local_ptr = (uint8_t*) malloc(34*sizeof(int8_t));
	uint8_t length;
	int32_t ItoA_number = 1209;
	int32_t AtoI_number;
	uint8_t base;
	base = 8;
	length = my_itoa(ItoA_number, local_ptr, base);
	AtoI_number = my_atoi(local_ptr, length, base);
	#ifdef VERBOSE 
		PRINTF("\n ************************************************************************\n ");		
		PRINTF("\n-------------------------- test_data2 ----------------------------- ");		
		PRINTF("\n Test 5 Data is: %d  Base is : %d \n Converted Back: %d", ItoA_number,base,AtoI_number);
		print_array_uint8(local_ptr,length);
	#endif	
	free((void*)local_ptr);
	if(AtoI_number != ItoA_number)
	{
		return FALSE;
	}
	return TRUE;
}
/****************************************************************/
int8_t test_memmove1(){
	uint8_t * source = data_set1;
	uint8_t * destination = source + NO_OVER_LAP;
	int8_t result;
	destination = my_memmove(source,destination,TEST_ARRAY_SIZE);
	result = my_compare(source,destination,TEST_ARRAY_SIZE);
	#ifdef VERBOSE
		PRINTF("\n ************************************************************************\n ");		
		PRINTF("\n Test Movement 1 No overlap ");
		PRINTF("\n Before Movement @ Location %#08X\n ",(unsigned int)((long int)source%10000));
		print_array_uint8(source,TEST_ARRAY_SIZE);
		PRINTF("\n After Movement @ location %#08X\n ",(unsigned int)((long int)destination%10000));
		print_array_uint8(destination,TEST_ARRAY_SIZE);
	#endif
	return result;
}
/****************************************************************/
int8_t test_memmove2(){
	uint8_t * source = data_set1;	
	uint8_t * destination = source - OVERLAP1; // Destination start is before sourse start by 5 memory locations	
	int8_t result;
	#ifdef VERBOSE
		PRINTF("\n ************************************************************************\n ");			
		PRINTF("\n Test Movement 2 overlap End of Dest Before Start of Source ");
		PRINTF("\n Before Movement @ Location %#08X\n ",(unsigned int)((long int)source%10000));
		print_array_uint8(source,TEST_ARRAY_SIZE);
	#endif
	destination = my_memmove(source,destination,TEST_ARRAY_SIZE);	
	result = my_compare(data_set2,destination,TEST_ARRAY_SIZE);
	#ifdef VERBOSE
		PRINTF("\n After Movement @ location %#08X\n ",(unsigned int)((long int)destination%10000));
		print_array_uint8(destination,TEST_ARRAY_SIZE);
	#endif
	my_memmove(destination,data_set1,TEST_ARRAY_SIZE); // Return the data to its place!
	return result;
}
/****************************************************************/
int8_t test_memmove3(){
	uint8_t *source = data_set1;
	uint8_t *destination = source + OVERLAP2;  // Destination start is after sourse start by 5 memory locations
	int8_t result;

	#ifdef VERBOSE
		PRINTF("\n ************************************************************************\n ");		
		PRINTF("\n Test Movement 3 overlap Start of Dest before End of source ");
		PRINTF("\n Before Movement @ Location %#08X\n ",(unsigned int)((long int)source%10000));
		print_array_uint8(source,TEST_ARRAY_SIZE);
	#endif
	destination = my_memmove(data_set1,destination,TEST_ARRAY_SIZE);
	result = my_compare(data_set2,destination,TEST_ARRAY_SIZE);	
	#ifdef VERBOSE
		PRINTF("\n After Movement @ location %#08X\n ",(unsigned int)((long int)destination%10000));
		print_array_uint8(destination,TEST_ARRAY_SIZE);	
		
	#endif
	my_memmove(destination,data_set1,TEST_ARRAY_SIZE); // Return the data to its place!
	return result;
}
/****************************************************************/
int8_t test_memcopy(){
	
	uint8_t *source=data_set1;
	uint8_t *destination = source + NO_OVER_LAP;  
	destination = my_memcopy(source,destination,TEST_ARRAY_SIZE);	
	#ifdef VERBOSE
		PRINTF("\n ************************************************************************\n ");		
		PRINTF("\n Test Copy No-Overlap ");
		PRINTF("\n Before Copy @ Location %#08X\n ",(unsigned int)((long int)source%10000));
		print_array_uint8(source,TEST_ARRAY_SIZE);
		PRINTF("\n After Copy @ location %#08X\n ",(unsigned int)((long int)destination%10000));
		print_array_uint8(destination,TEST_ARRAY_SIZE);
	#endif
	return my_compare(source,destination,TEST_ARRAY_SIZE);
}
/****************************************************************/
int8_t test_memset(){
	uint8_t *my_memory = (uint8_t*) malloc(TEST_ARRAY_SIZE*sizeof(int8_t));
	int8_t result;
	
	#ifdef VERBOSE
		PRINTF("\n ************************************************************************\n ");		
		PRINTF("\n Test of MemSet ");
		PRINTF("\n Before Set @ Location %#08X\n ",(unsigned int)((long int)my_memory%10000));
		print_array_uint8(my_memory,TEST_ARRAY_SIZE);
	#endif
	my_memory = my_memset(my_memory,TEST_ARRAY_SIZE,SET_VALUE);
	result = my_compare_set(my_memory,SET_VALUE,TEST_ARRAY_SIZE);
	#ifdef VERBOSE
		PRINTF("\n After Set @ Location %#08X\n ",(unsigned int)((long int)my_memory%10000));
		print_array_uint8(my_memory,TEST_ARRAY_SIZE);
	#endif
	my_memory = my_memset(my_memory,TEST_ARRAY_SIZE,SET_VALUE+3);
	#ifdef VERBOSE
		PRINTF("\n Test of MemZero ");
		PRINTF("\n Before Set Zero @ Location %#08X\n ",(unsigned int)((long int)my_memory%10000));
		print_array_uint8(my_memory,TEST_ARRAY_SIZE);
	#endif
	my_memory = my_memzero(my_memory,TEST_ARRAY_SIZE);
	result = my_compare_set(my_memory,0,TEST_ARRAY_SIZE);
	#ifdef VERBOSE
		PRINTF("\n After Set Zero @ Location %#08X\n ",(unsigned int)((long int)my_memory%10000));
		print_array_uint8(my_memory,TEST_ARRAY_SIZE);
	#endif
	free((void*)my_memory);
	return result;
}

/****************************************************************/
int8_t test_reverse(){
	uint8_t *my_memory = (uint8_t*) malloc(TEST_ARRAY_SIZE*sizeof(int8_t));
	uint8_t result; 
	my_memory = my_memmove(data_set2,my_memory,TEST_ARRAY_SIZE);
	#ifdef VERBOSE
		PRINTF("\n ************************************************************************\n ");		
		PRINTF("\n Test of Memory Reverse ");
		PRINTF("\n Before Reverse @ Location %#08X\n ",(unsigned int)((long int)my_memory%10000));
		print_array_uint8(my_memory,TEST_ARRAY_SIZE);
	#endif
	my_memory = my_reverse(my_memory,TEST_ARRAY_SIZE);
	#ifdef VERBOSE
		PRINTF("\n After Reverse @ Location %#08X\n ",(unsigned int)((long int)my_memory%10000));
		print_array_uint8(my_memory,TEST_ARRAY_SIZE);
	#endif
	my_memory = my_reverse(my_memory,TEST_ARRAY_SIZE); // Reverse Again to compare with the original one
	result = my_compare(my_memory,data_set2,TEST_ARRAY_SIZE);
	free((void*)my_memory);
	return result;
}
static int8_t my_compare(uint8_t* source1,uint8_t* source2, uint8_t length){
	uint8_t * src1_temp = source1;
	uint8_t * src2_temp = source2;
	for(int i =1;i<length;i++){
		if(*src1_temp != *src2_temp){
			return FALSE;
		}
		src1_temp++;
		src2_temp++;
	}
	return TRUE;
}
static int8_t my_compare_set(uint8_t* source1,uint8_t value, uint8_t length){
	for(int i =1;i<length;i++){
		if(*source1 != value){
			return FALSE;
		}
		source1++;
	}
	return TRUE;
}
