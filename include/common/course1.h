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
 * @file course1.h
 * @brief Test memory and data manipulation
 *
 * This abstraction file provides interface to function declaration to test the data and memory manipulation functions
 *
 * @author Ashraf Abdalraheem
 * @date Nov 16 2018
 *
 */
#ifndef __COURSE1_H__
#define __COURSE1_H__
#include <stdint.h>
/*
 * @brief Test Data and memory manipulation
 *
 * This function will call a set of functions ment to test other functions that manipulate 
 * the data in memroy using pointers such as memory move and memory copy. Also it will test 
 * the data manipulation function such as ASCII to integer conversion and vice versa.
 * 
 * @parm nothing to pass
 * @return 
 */
int8_t course1();

/*
 * @brief Test ASCII to integer and integer to ASCII conversion
 *
 * This function will call atoi() and itoa() functions to test the ASCII to integer 
 * and integer to ASCII covertion. 
 * 
 * @parm nothing to pass
 * @return 
 */
int8_t test_data1();

/*
 * @brief Test ASCII to integer and integer to ASCII conversion
 *
 * This function will call atoi() and itoa() functions to test the ASCII to integer 
 * and integer to ASCII covertion. 
 * 
 * @parm nothing to pass
 * @return 
 */
int8_t test_data2();

/*
 * @brief Test Memory move function
 *
 * This function will call memory move function with non-overlapped memory locations and test the 
 * result of the movement.
 * 
 * @parm nothing to pass
 * @return 
 */
int8_t test_memmove1();

/*
 * @brief Test Memory move function
 *
 * This function will call memory move function with overlapped memory locations and test the 
 * result of the movement.
 * The overlap occur in the end of the destination and the start of the source.
 * 
 * @parm nothing to pass
 * @return 
 */
int8_t test_memmove2();

/*
 * @brief Test Memory move function
 *
 * This function will call memory move function with overlapped memory locations and test the 
 * result of the movement.
 * The overlap occur in the start of the destination and the end of the source.
 * 
 * @parm nothing to pass
 * @return 
 */
int8_t test_memmove3();

/*
 * @brief Test Memory copy function
 *
 * This function will call memory copy function and display the results
 * 
 * @parm nothing to pass
 * @return 
 */
int8_t test_memcopy();

/*
 * @brief Test Memory memory set and memory zero set functions
 *
 * This function will call memset and memzero functions and diplay the results
 * 
 * @parm nothing to pass
 * @return 
 */
int8_t test_memset();

/*
 * @brief Test Memory memory reverse functions
 *
 * This function will call memreverse function and diplay the results
 * 
 * @param nothing to pass
 * @return 
 */
int8_t test_reverse();
/*
 * @brief Test Data between two memory location if equal return TRUE, Else return false
 *
 * 
 * @param source1 pointer to first memory location
 * @param source2 pointer to second memory location
 * @return TRUE/FALSE
 */
int8_t my_compare(uint8_t* source1,uint8_t* source2, uint8_t length);
/*
 * @brief Test Data between a memory location and value if equal return TRUE, Else return false
 *
 * 
 * @param source1 pointer to first memory location
 * @param value to compare with
 * @return TRUE/FALSE
 */
int8_t my_compare_set(uint8_t* source1,uint8_t value, uint8_t length);

#endif /*__COURSE1_H__*/
