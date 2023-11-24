# Author: Joseph Kehoe
# Edited by:
# Name: Marcel Zama
# College ID: C00260146
# Date: 13/11/2023
# License: GPL-3.0 (See LICENSE text for the full LICENSE)
# GitHub Link: https://github.com/MarcelZama/Concurrent-Dev/tree/main

# List of C++ source files
CPPFILES = quicksort.cpp

# List of header files
HFILES =

# Compiler
CC = g++

# Compiler flags
CFLAGS = -std=c++11 -fopenmp

# Debug flags
DEBUGFLAGS =

# Rule for creating object files
# This rule says that each .o file depends on a .cpp file of the same name
%.o: %.cpp
	$(CC) -c -o $@ $< $(CFLAGS) $(DEBUGFLAGS)

# Rule to build the QUICK executable
QUICK: quicksort.o
	$(CC) -o qsort.out quicksort.o $(CFLAGS) $(DEBUGFLAGS)

# Rule to build the QUICK executable with debugging information
DSORT: DEBUGFLAGS = -g -O0
DSORT: QUICK

# Rule to clean up all object files
CLEAN:
	rm *.o
