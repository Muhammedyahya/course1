/******************************************************************************
 * Copyright (C) 2017 by Alex Fosdick - University of Colorado
 *
 * Redistribution, modification or use of this software in source or binary
 * forms is permitted as long as the files maintain this copyright. Users are 
 * permitted to modify this and use it to learn about the field of embedded
 * software. Alex Fosdick and the University of Colorado are not liable for any
 * misuse of this material. 
 *
 * This code is designed as a part of assignment belongs to the online course of Introduction to 
 * Embedded Software & Development Environment which is a part of Embedded Software Essential Specialization
 * Provided by University of Colorado Boulder and Coursera By Alex Fosdick
 *****************************************************************************/
/**
 * @file memory.h
 * @brief Abstraction of memory read and write operations
 *
 * This header file provides an abstraction of reading and
 * writing to memory via function calls. 
 *
 * @author Alex Fosdick
 * @date April 1 2017
 * @modified by Ashraf Abdalraheem	
 * @date November 14 2018
 */
#ifndef __MEMORY_H__
#define __MEMORY_H__
#include <stdint.h>
#include <stdlib.h>
#include "stats.h"
/**
 * @brief Sets a value of a data array 
 *
 * Given a pointer to a char data set, this will set a provided
 * index into that data set to the value provided.
 *
 * @param ptr Pointer to data array
 * @param index Index into pointer array to set value
 * @param value value to write the the locaiton
 *
 * @return void.
 */
void set_value(char * ptr, unsigned int index, char value);

/**
 * @brief Clear a value of a data array 
 *
 * Given a pointer to a char data set, this will clear a provided
 * index into that data set to the value zero.
 *
 * @param ptr Pointer to data array
 * @param index Index into pointer array to set value
 *
 * @return void.
 */
void clear_value(char * ptr, unsigned int index);

/**
 * @brief Returns a value of a data array 
 *
 * Given a pointer to a char data set, this will read the provided
 * index into that data set and return the value.
 *
 * @param ptr Pointer to data array
 * @param index Index into pointer array to set value
 *
 * @return Value to be read.
 */
char get_value(char * ptr, unsigned int index);

/**
 * @brief Sets data array elements to a value
 *
 * Given a pointer to a char data set, this will set a number of elements
 * from a provided data array to the given value. The length is determined
 * by the provided size parameter.
 *
 * @param ptr Pointer to data array
 * @param value value to write the the locaiton
 * @param size Number of elements to set to value
 *
 * @return void.
 */
void set_all(char * ptr, char value, unsigned int size);

/**
 * @brief Clears elements in a data array
 *
 * Given a pointer to a char data set, this will set a clear a number
 * of elements given the size provided. Clear means to set to zero. 
 *
 * @param ptr Pointer to data array
 * @param size Number of elements to set to zero
 *
 * @return void.
 */
void clear_all(char * ptr, unsigned int size);


/**
 * @brief Move Data From Source location to Destination
 *
 * Given a pointer to an int data set, this will move a number
 * of elements to another destination given the length provided and it returns pointer * to the destination. 
 * The function gurantee the overlap between source and destination don't result in  
 * data corruption.
 *
 * @param src Pointer to source
 * @param dst Pointer to destination
 * @param length The length of data need to be moved.
 *
 * @return pointer to destination.
 */
uint8_t * my_memmove(uint8_t * src, uint8_t * dst, size_t length);

/**
 * @brief Copy Data From Source location to Destination
 *
 * Given a pointer to an int data set, this will copy a number
 * of elements to another destination given the length provided and it returns pointer * to the destination. 
 *
 * @param src Pointer to source
 * @param dst Pointer to destination
 * @param length The length of data need to be moved.
 *
 * @return pointer to destination.
 */
uint8_t * my_memcopy(uint8_t * src, uint8_t * dst, size_t length);

/**
 * @brief Set in memory indicated by Source and Length to a given value
 *
 * Given a pointer to an int data set, this will set number
 * of elements to specific value; given the length provided and it returns pointer * to  
 * the source. 
 *
 * @param src Pointer to source
 * @param length The length of data need to be moved.
 * @param value should be written in memory locations
 *
 * @return pointer to source.
 */
uint8_t * my_memset(uint8_t * src, size_t length, uint8_t value);
/**
 * @brief Clear memory indicated by Source and Length to Zero
 *
 * Given a pointer to an int data set, this will clear number
 * of elements to Zero; given the length provided and it returns pointer * to  
 * the source. 
 *
 * @param src Pointer to source
 * @param length The length of data need to be moved.
 *
 * @return pointer to source.
 */
uint8_t * my_memzero(uint8_t * src, size_t length);
/**
 * @brief Take a pointer to Data and length and reverse the order of Data in memory.
 *
 * Given a pointer to an int data set, this will the order 
 * of elements ; given the length provided and it returns pointer * to  
 * the source. 
 *
 * @param src Pointer to source
 * @param length The length of data need to be moved.
 *
 * @return pointer to source.
 */
uint8_t * my_reverse(uint8_t * src, size_t length);

/**
 * @brief Reserve a number of memory location (32bit word) and return pointer.
 *
 * This function take a length and reserve memory location with that length. 
 * It returns the pointer to that memory location and if it fails it will return NULL   
 *
 * @param length The length of location to be reserved.
 *
 * @return pointer to memory location.
 */
int32_t * reserve_words(size_t length);

/**
 * @brief Free memory location.
 *
 * This function take a pointer to a memory location and make it free for new 
 * allocation   
 *
 * @param src The pointer to memory location.
 *
 */
void free_words(int32_t * src);
#endif /* __MEMORY_H__ */
