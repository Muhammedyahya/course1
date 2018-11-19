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
 * @file <Stats.C> 
 * @brief <Array Statistics >
 *
 * This program will take an array of char and make statistics on it: it calculate the mean, median, maximum and minimum of that array. It also sort that array in descending order and could print the array in 4*10 matrix. Before making any calculation or printing, it checks the validity of the data first:
	-if the pointer is not assigned
	-if the length is negative
	-if the length is greater than the size.
	it will return an error and display the cause of error. else it will contiue ot work.
 *
 * @author <Ashraf Abubaker >
 * @date <11 Oct 2017 >
 *
 */


#include "stats.h"
#include <stdlib.h>
#include "platform.h"
/* Size of the Data Set */
#define SIZE (40)
/* Add other Implementation File Code Here */

char find_mean(unsigned char* array,unsigned int temp_length){
	if(check_validity(array,temp_length)){
		unsigned int length= (unsigned int) temp_length;
		long long int sum=0;
		for(unsigned int i=0;i<length;){
			sum+=(long int)array[i];
			++i;
		}
		return (sum/length);
	}
	return 0;
}
void swap(unsigned char* variable1,unsigned char* variable2){
	if((variable1==NULL)||(variable2==NULL)){
		PRINTF("\n Error:Pointers are not valid!");
	}
	else{
		char temp=0;
		temp = *variable2;
		*variable2 = *variable1;
		*variable1 = temp;
	}
}
// Function Override to Take integer variables
void swap_uint8(uint8_t* variable1,uint8_t* variable2){
	swap((unsigned char*)variable1, (unsigned char*)variable2);
}
long int find_minimum(unsigned char* array, unsigned int temp_length){
	if(check_validity(array,temp_length)){
		unsigned int length = (unsigned int) temp_length;
		unsigned int i=1;
	    long int mini=array[0];
	    for(;i<length;i++){
			if(mini>(long int)array[i]){
			  mini=(long int)array[i];
			}
	    }
	return mini;
	}
	return 0;
}
long int find_maximum(unsigned char* array, unsigned int temp_length){
	if(check_validity(array,temp_length)){
		unsigned int length=(unsigned int)temp_length;
		unsigned int i=1;
        long int max=array[0];
        for(;i<length;i++){
			if(max<(long int)array[i]){
			  max=(long int)array[i];
			}
		}
	return max;
	}
	return 0;	
}
			       
void sort_array(unsigned char* array, unsigned int temp_length){
	if(check_validity(array,temp_length)){
		unsigned int length=(unsigned int)temp_length;
		unsigned int i=0;
		for(i=0;i<length;i++){
			for(unsigned int j=0;j<length;j++){
				if(array[j]<array[j+1]){
					swap(array+j,array+j+1);
				}
			}
		}
	}
}
void print_array(unsigned char* array, unsigned int temp_length){
		if(check_validity(array,temp_length)){
			unsigned int length=(unsigned int)temp_length;
			#ifdef VERBOSE  // Print Only if Debugging is enabled!
				PRINTF("\n");
			#endif 
			for(unsigned int i=0;i<length;i++){
				if((i%5)==0){
					#ifdef VERBOSE  // Print Only if Debugging is enabled!
						PRINTF("\n");
					#endif 
				}
				#ifdef VERBOSE  // Print Only if Debugging is enabled!
					PRINTF("	%d",array[i]);
				#endif
			}
			#ifdef VERBOSE  // Print Only if Debugging is enabled!
				PRINTF("\n");
			#endif 
		}
}
/****************************************************************/
//*** Function override to print uint8 variable types ****// 
void print_array_uint8(uint8_t* array, uint8_t temp_length){
	print_array((unsigned char*)array,(unsigned int) temp_length);
}

/****************************************************************/
char find_median(unsigned char* array,unsigned int temp_length){
	if(check_validity(array,temp_length)){
		unsigned int length=(unsigned int)temp_length;
		sort_array(array,length);
		if((length%2)==0){
			PRINTF("\n There is two medians %d , %d",array[length/2-1],array[length/2]);
		return (array[length/2-1]+array[length/2])/2;
		}
		return array[(length+1)/2]; //bug here!!
		}
return 0;
}
void print_statistics(unsigned char* array,unsigned int length){
	if(check_validity(array,length)){
		PRINTF("\n******************* The Statistics *************** \n The mean is : %d",find_mean(array,length));
		PRINTF("\n The max is : %ld",find_maximum(array,length));
		PRINTF("\n The Mini is: %ld",find_minimum(array,length));
		PRINTF("\n The median is: %d\n",find_median(array,length));
	}
}	
int check_validity(unsigned char* array , unsigned int length){
	if(array == NULL){
		PRINTF("\n The pointer is not pointing to anything");
		return 0; // The pointer is not pointing to anything 
	}
	if(length <1){
		PRINTF("\n Length is negative, ERROR");
		return 0; 
	}
	if(length > SIZE){
		PRINTF("\n Length is very large, ERROR");
		return 0; 
	}
	return 1;
}
