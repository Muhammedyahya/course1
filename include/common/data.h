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
 * @file data.h
 * @brief Basic Data Manipulation
 *
 * This abstraction file provides interface to funtion perform basic manipulation of data
 *
 * @author Ashraf Abdalraheem
 * @date Nov 14 2018
 *
 */
 #ifndef __DATA_H__
 #define __DATA_H__
 #include <stdint.h>
 /**
 * @brief Integer to ASCII Conversion Function 
 *
 * This function will take singed integer number and converts it to ASCII with defined 
 * base. 
 * It saves the converted data  in 8 bit memory locations assigned by pointer. 
 * The string of data is terminated by NULL.
 * It returns the length of data converted including the terminator\
 * 
 * Algorithm: 
 * 1- Check if the number is negative: 
 * 		-if it is negative the first byte is negative sign.
 * 2- Convert the integer into single digits and store them in memory in
 * ASCII equivelant
 * 3- Reverse the order as the Most significant digit should be stored first. 
 * 4- Return the length.
 * 
 * @param data integer data for conversion
 * @param ptr Pointer to memory location where result of conversion is saved
 * @param base of converted data from 2 to 16. 
 *
 * @return length.
 */
 uint8_t my_itoa(int32_t data, uint8_t * ptr, uint32_t base);

/**
 * @brief ASCII to Integer Conversion Function 
 *
 * This function will take ASCII string of memory locations and converts it to integer with defined 
 * base. 
 * It returns the converted data  in 32 bit signed integer. 
 * 
 * 
 * Algorithm: 
 * 1- Check if the number is negative: 
 * 		-if it is negative the first byte is negative sign.
 * 2- Convert the integer into single digits and store them in memory in
 * ASCII equivelant
 * 3- Reverse the order as the Most significant digit should be stored first. 
 * 4- Return the length.
 * 
 * @param ptr Pointer to memory location where string of ASCII number is placed
 * @param digits no. of data to be converted
 * @param base of converted data from 2 to 16. 
 *
 * @return data in 32 bit signed.
 */
int32_t my_atoi(uint8_t * ptr, uint8_t digits, uint32_t base);

 #endif /*DATA.H*/
