# Author: Joseph Kehoe
# Edited by:
# Name: Marcel Zama
# College ID: C00260146
# Date: 14/11/2023
# License: GPL-3.0 (See LICENSE text for the full LICENSE)
# GitHub Link: https://github.com/MarcelZama/Concurrent-Dev/tree/main

# List of C source files
CFILES = saxpy.cpp

# List of header files
HFILES =

# Compiler
CC = g++

# Compiler flags
CFLAGS = -std=c++11 -pthread -fopenmp

# Debug flags
DEBUGFLAGS =

# Rule for creating object files
# This rule says that each .o file depends on a .cpp file of the same name
%.o: %.cpp
	$(CC) -c -o $@ $< $(CFLAGS) $(DEBUGFLAGS)

# Rule to build the SAXPY executable
SAXPY: saxpy.o
	$(CC) -o saxpy.out saxpy.o $(CFLAGS) $(DEBUGFLAGS)

# Rule to build the MANDEL executable
MANDEL: mandelbroit.o
	$(CC) -o mandelbroit.out mandelbroit.o $(CFLAGS) $(DEBUGFLAGS)

# Rule to build the SAXPY executable with debugging information
DSAXPY: DEBUGFLAGS = -g -O0
DSAXPY: SAXPY

# Rule to clean up all object files
CLEAN:
	rm *.o
