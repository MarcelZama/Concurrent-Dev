# Name: Marcel Zama
# College ID: C00260146
# Date : 14/10/2023

# Compiler and flags
CC=g++
CFLAGS=-std=c++11 -pthread -I. -Wall

# Source files
SOURCE_FILES=main.cpp Semaphore.cpp Barrier.cpp

# Rule to build object files from source files
%.o: %.cpp
	$(CC) -c -o $@ $< $(CFLAGS) $(DEBUGFLAGS)

# Our main build rule
RELEASE: $(SOURCE_FILES:.cpp=.o)
	$(CC) -o main $^ $(CFLAGS) $(DEBUGFLAGS)

# Set Debug Flags & Build Debug Build
DEBUG: DEBUGFLAGS = -g -O0

# Call RELEASE rule with the Debug Flags as the second step of the debug rule
DEBUG: RELEASE

# Remove used .o files that are no longer needed
CLEAN:
	rm -f *.o

