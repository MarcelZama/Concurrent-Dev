#Name: Marcel Zama
#College ID: C00260146
#Date: 6/10/2023

CC = g++
CFLAGS = -std=c++11 -pthread -Wall -Wextra -pedantic

HELLO_FILES = helloThreads.o Semaphore.o
MUTUAL_FILES = mutualEx.o Semaphore.o

# Inform make that .o files require .cpp files of the same name
%.o: %.cpp
	$(CC) -c -o $@ $< $(CFLAGS) $(DEBUGFLAGS)

# Compile two separate projects with corresponding targets
RELEASE: $(HELLO_FILES) $(MUTUAL_FILES)
	$(CC) -o helloThreads $(HELLO_FILES) $(CFLAGS) $(DEBUGFLAGS)
	$(CC) -o mutualEx $(MUTUAL_FILES) $(CFLAGS) $(DEBUGFLAGS)

# Set Debug Flags and compile both projects in debug mode
DEBUG: DEBUGFLAGS += -DDEBUG
DEBUG: RELEASE

# Remove used .o files that are no longer needed + test if the .o files were removed or not
CLEAN:
	@echo "Removing .o files..."
	@rm -f *.o || true
	@echo "Cleanup complete."
