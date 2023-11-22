# Name: Marcel Zama
# College ID: C00260146
# Date : 10/11/2023

# Compiler and flags
CC=g++
CFLAGS= -std=c++11 -pthread -Wall

# Source files
MAIN_FILES=main.o Semaphore.o

# Rule to build object files from source files
%.o: %.cpp Semaphore.h
	$(CC) -c -o $@ $< $(CFLAGS) $(DEBUGFLAGS)

# Main build rule
RELEASE: $(MAIN_FILES)
	$(CC) -o main $(MAIN_FILES) $(CFLAGS) $(DEBUGFLAGS)

# Debug Flags for debugging information
DEBUGFLAGS = -g -O0

# Debug rule, calling RELEASE rule with Debug Flags
DEBUG: RELEASE

# Rule to clean up object files
CLEAN:
	rm -f *.o main