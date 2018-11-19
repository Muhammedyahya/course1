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
 * @file <stats.h> 
 * @brief <Statistics Header file >
 * <Interface to functions do statistics>
 * <It contains Only Function defintion>
 *
 * @author <Ashraf Abubaker>
 * @date <10 Oct 2017 >
 *
 */
#ifndef __STATS_H__
#define __STATS_H__
#include <stdint.h>
/* Add Your Declarations and Function Comments here */ 

/**
 * @brief <Add Brief Description of Function Here>
 *
 * <Add Extended Description Here>
 *
 * @param <Add InputName> <add description here>
 * @param <Add InputName> <add description here>
 * @param <Add InputName> <add description here>
 * @param <Add InputName> <add description here>
 *
 * @return <Add Return Informaiton here>
 */

/*print_statistics */

/* @breif Print prints the statistics of an array including minimum, maximum,
 * mean, and median.
 * This fuction takes a pointer to the desired array and it prints the 
 * statistics of the array
 * @param array is the pointer to selected array
 * @return It don't return any thing, it only display the statistics
 * */
void print_statistics(unsigned char* array, unsigned int length);


/* print_array */ 
/**
 * @breif  Given an array of data and a length, prints the array to the screen
 * It takes a pointer to the arrray and the lenght of that array and print that
 * array in ordered format. 
 * With its overrides
 * @param array is the pointer to the first element in the desired array
 * @param length is the length of data to be printed
 * @return <It don't return any thing>
 */ 
void print_array(unsigned char* array, unsigned int length);
void print_array_uint8(uint8_t* array, uint8_t temp_length);


/* find_median */     
/**
 * @breif <Given an array of data and a length, returns the median value>
 * It takes a pointer to array and the length of the array to acquire the 
 * median of that array
 * @param <pointer to array>
 * @param <data length>
 * @return <It returns the median>
 * */
char find_median(unsigned char* array, unsigned int length);

/* find_mean */
/**
 * @breif <Given an array of data and a length, returns the mean value>
 * It takes a pointer to array and the length of that array and calculate 
 * the mean
 * @param <pointer to array>
 * @param <data length>
 * @return <It returns the mean as a float number>
 * */
char find_mean(unsigned char* array, unsigned int length);

/* find_minimum */
/**
 * @breif <Given an array of data and a length, returns the minimum value>
 * @param <pointer to array>
 * @param <data length>
 * @return <It returns the minimum>
 **/
long int find_minimum(unsigned char* array, unsigned int length);

/* find_maximum */
/**
 * @breif <Given an array of data and a length, returns the maximum value>
 * @param <pointer to array>
 * @param <data length>
 * @return <It returns the maximum>
 **/
long int find_maximum(unsigned char* array, unsigned int length);


/*sort_array */

/* @breif < Given an array of data and a length, sorts the array from largest to smallest. (The zeroth Element should be the largest value, and the last element  (n-1) should be the smallest value.) >
 * @param <pointer to array>
 * @return <It don't return any thing>
 * */
void sort_array(unsigned char* array,unsigned int length);

/*swap*/

/* @breif <it took two variables and swap its location in an array if they are not NULL>
 * @param <pointer to the first variable>
 * @param <pointer to the seconde variable>
 * @return <It don't return any thing>
 * */
void swap(unsigned char* variable1,unsigned char* variable2);
/*swap Override*/

/* @breif <it took two variables and swap its location in an array if they are not NULL>
 * @param <pointer to the first variable>
 * @param <pointer to the seconde variable>
 * @return <It don't return any thing>
 * */
void swap_uint8(uint8_t* variable1,uint8_t* variable2);

/* check_validity */
/* @brief < it takes the array pointer and length to check the validity of the two variables. If valid it returns 1 if not it returns 0>
* @param <pointer to array>
* @param <array length>
* @return <the validity result either 0 or 1>
* */
int check_validity(unsigned char* variable1 , unsigned int variable2);
#endif /* __STATS_H__ */
