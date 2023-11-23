# Name: Marcel Zama
# College ID: C00260146
# Date : 10/10/2023

# Compiler and flags
CC=g++
CFLAGS=-std=c++11 -pthread -Wall -Wextra -pedantic

# Source files
CPPFILES=Semaphore.cpp rendezvous.cpp

# Rule to build object files from source files
%.o: %.cpp
	$(CC) -c -o $@ $< $(CFLAGS) $(DEBUGFLAGS)

# Rule to build the SIMPLE version
SIMPLE: $(CPPFILES:.cpp=.o)
	$(CC) -o rendezvous $^ $(CFLAGS) $(DEBUGFLAGS)

# Set Debug Flags as the first step of the debug rule
DEBUG: DEBUGFLAGS = -DDEBUG

# Call SIMPLE rule with the Debug Flags as the second step of the debug rule
DEBUG: SIMPLE

# Rule to clean up object files and the executable
CLEAN:
	rm -f *.o rendezvous
