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
 * This Header file provides a basic manipulation of data
 *
 * @author Ashraf Abdalraheem
 * @date Nov 14 2018
 *
 */
 #ifndef __DATA_H__
 #define __DATA_H__
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
 * 2- Convert the integer into signle decimal digits and store them in memory 
 * 		Most significant digit should be stored first.
 * 3- Change the data into ASCII with base 10. 
 * 4- If the base is not 10 convert to the correct.
 * 5- Return the length.
 * 
 * @param data integer data for conversion
 * @param ptr Pointer to memory location where result of conversion is saved
 * @param base of converted data from 2 to 16. 
 *
 * @return void.
 */
 uint8_t my_itoa(int32_t data, uint8_t * ptr, uint32_t base);
 #endif /*DATA.H*/