CC=g++
CFLAGS= -std=c++11 -pthread -Wall
MUTFILES = mutualEx.cpp Semaphore.cpp Semaphore.h
DFLAGS = -08 -g


#This rule says that each .o file depends on a .cpp file of the same name
%.o: %.cpp
	$(CC) -c -o $@ $< $(CFLAGS) $(DEBUGFLAGS)


HELLO: helloThreads.cpp Semaphore.cpp
	g++ -std=c++11 -pthread helloThreads.cpp

MUTUAL: $(MUTFILES)
	$(CC) $(CFLAGS) $(MUTFILES) -o muty

DEBUG: $(MUTFILES)
	$(CC) $(CFLAGS) $(DFLAGS) mutualEx.cpp Semaphore.cpp -o muty
CLEAN:
	rm .o
	rm~