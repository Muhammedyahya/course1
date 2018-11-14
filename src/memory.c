/******************************************************************************
 * Copyright (C) 2017 by Alex Fosdick - University of Colorado
 *
 * Redistribution, modification or use of this software in source or binary
 * forms is permitted as long as the files maintain this copyright. Users are 
 * permitted to modify this and use it to learn about the field of embedded
 * software. Alex Fosdick and the University of Colorado are not liable for any
 * misuse of this material. 
 *
 *****************************************************************************/
/**
 * @file memory.c
 * @brief Abstraction of memory read and write operations
 *
 * This implementation file provides an abstraction of reading and
 * writing to memory via function calls. There is also a globally
 * allocated buffer array used for manipulation.
 *
 * @author Alex Fosdick
 * @date April 1 2017
 *
 */
#include "memory.h"

/***********************************************************
 Function Definitions
***********************************************************/
void set_value(char * ptr, unsigned int index, char value){
  ptr[index] = value;
}

void clear_value(char * ptr, unsigned int index){
  set_value(ptr, index, 0);
}

char get_value(char * ptr, unsigned int index){
  return ptr[index];
}

void set_all(char * ptr, char value, unsigned int size){
  unsigned int i;
  for(i = 0; i < size; i++) {
    set_value(ptr, i, value);
  }
}

void clear_all(char * ptr, unsigned int size){
  set_all(ptr, 0, size);
}


uint8_t * my_memmove(uint8_t * src, uint8_t * dst, size_t length){
	/*   Check Validity of Data */
	if(src==NULL)||(dst==NULL)||(length<=0){
		return NULL; // Parameters are invalid
	}
	/*
	 * Check if there is overlapping Then start the move from
	 * The bottom
	*/
	size_t i=1;
	uint8_t * temp_dst = dst; // To return dst address 
	if((src - dst)<length){ 
		for(i=1;i <= length;i++){
			// Poiting to the Bottom, 
			dst++; // This guarantee the increment will be based on size of pointer 
			src++;
		}
		for(i=1;i <= length;i++){
			*(dst) = *(src);
			dst--;
			src--;
		}
	}else{
	/*
	 * No Overlap Start from the Top
	*/	
		for(i=1;i <= length;i++){
			*(dst) = *(src);
			dst++;
			src++;
		}
	}
	return temp_dst;
}

uint8_t * my_memcopy(uint8_t * src, uint8_t * dst, size_t length){
	/*   Check Validity of Data */
	if(src==NULL)||(dst==NULL)||(length<=0){
		return NULL; // Parameters are invalid
	}
	size_t i=1;
	uint8_t * temp_dst = dst; // To return dst address 
	for(i=1;i <= length;i++){
		*(dst) = *(src);
		dst++;
		src++;
	}
	return temp_dst;
}

uint8_t * my_memset(uint8_t * src, size_t length, uint8_t value){
	/*   Check Validity of Data */
	if(src==NULL)||(length<=0){
		return NULL; // Parameters are invalid
	}
	size_t i=1;
	uint8_t * temp_src = src; // To return src address 
	for(i=1;i <= length;i++){
		*(src) = value;
		src++;
	}
	return temp_src;
	
}

uint8_t * my_memzero(uint8_t * src, size_t length){
	
	return my_memset(src,length,0);
}

uint8_t * my_reverse(uint8_t * src, size_t length){
	/*   Check Validity of Data */
	if(src==NULL)||(length<=0){
		return NULL; // Parameters are invalid
	}
	size_t i=1;
	uint8_t * temp_src = src;
	uint8_t * temp2_src = src; // To return src address 
	for(i=1;i <= length;i++){
		// Poiting to the Bottom, 
		temp_src++; // This guarantee the increment will be based on size of pointer 
	}
	for(i=1;i <= (length/2);i++){
		swap(src, temp_src);
		src++;
		temp_src--;
	}
	return temp2_src;
}
int32_t * reserve_words(size_t length){
	return ((int32_t*)malloc(length*sizeof(int32_t));
}

void free_words(int32_t * src){
	free((void*) src);
}