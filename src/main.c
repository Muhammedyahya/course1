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
 * @file main.c
 * @brief main call course1 function if COURSE1 is passed at compile time
 * This file contains the main code for the course1 assesment
 * Modified By Ashraf Abubaker Mohammed for Embededd Software Course 
 * @date Nov  10 2018
 */



#include "course1.h"
#include <stdlib.h>
#include "platform.h"
/* A pretty short main file */
int main(void) {
  #ifdef COURSE1   // Use compile time switch to execute this function	
	course1();
  #endif
  return 0;
}

