#******************************************************************************
# Copyright (C) 2017 by Alex Fosdick - University of Colorado
#
# Redistribution, modification or use of this software in source or binary
# forms is permitted as long as the files maintain this copyright. Users are 
# permitted to modify this and use it to learn about the field of embedded
# software. Alex Fosdick and the University of Colorado are not liable for any
# misuse of this material. 
# Modified by Ashraf Abubaker for Coursera Course in Embedded software design
# NOV 2018
# You can obtain this file from the Git Repository
# https://github.com/ashrafmalraheem/course1
#*****************************************************************************

#*****************************************************************************

# Add your Source files to this variable
SOURCES = src/main.c\
	  src/memory.c\
	  src/course1.c\
	  src/data.c\
	  src/stats.c

# Add your include paths to this variable
INCLUDES =    -I include/common

#Additional sources and include paths for MSP432 Platform
ifeq ($(PLATFORM),MSP432)
  SOURCES += src/interrupts_msp432p401r_gcc.c\
 	     src/startup_msp432p401r_gcc.c   \
 	     src/system_msp432p401r.c	
  INCLUDES += -I include/CMSIS\
 	      -I include/msp432
endif
