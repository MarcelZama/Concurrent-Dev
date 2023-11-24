# Author: Joseph Kehoe
# Edited by:
# Name: Marcel Zama
# College ID: C00260146
# Date: 17/11/2023
# License: GPL-3.0 (See LICENSE text for the full LICENSE)
# GitHub Link: https://github.com/MarcelZama/Concurrent-Dev/tree/main

# List of C source files
CFILES = stencil.cpp

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

# Rule to build the STENCIL executable
STENCIL: stencil.o
	$(CC) -o stencil.out stencil.o $(CFLAGS) $(DEBUGFLAGS)

# Rule to build the MANDEL executable
MANDEL: mandelbroit.o
	$(CC) -o mandelbroit.out mandelbroit.o $(CFLAGS) $(DEBUGFLAGS)

# Rule to build the STENCIL executable with debugging information
DSTENCIL: DEBUGFLAGS = -g -O0
DSTENCIL: STENCIL

# Rule to clean up all object files
CLEAN:
	rm *.o
