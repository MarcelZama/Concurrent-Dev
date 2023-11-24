# Author: Joseph Kehoe
# Edited by:
# Name: Marcel Zama
# College ID: C00260146
# Date: 15/11/2023
# License: GPL-3.0 (See LICENSE text for the full LICENSE)
# GitHub Link: https://github.com/MarcelZama/Concurrent-Dev/tree/main

# List of C++ source files
CPPFILES = reduction.cpp

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
	$(CC) -c -o $@ $< $(CFLAGS) -lgomp $(DEBUGFLAGS)

# Rule to build the REDUCE executable
REDUCE: reduction.o
	$(CC) -o reduce.out reduction.o $(CFLAGS) $(DEBUGFLAGS)

# Rule to build the REDUCE executable with debugging information
DREDUCE: DEBUGFLAGS = -g -O0
DREDUCE: REDUCE

# Rule to clean up all object files
CLEAN:
	rm *.o
