#include "Semaphore.h"
#include <iostream>
#include <thread>
#include <vector>
#include <stdlib.h>     /* srand, rand */
#include <time.h>       /* time */
#include <unistd.h>

const int COUNT = 5;
const int THINKTIME = 3;
const int EATTIME = 5;
std::vector<Semaphore> forks(COUNT);
std::vector<std::string> philosopherStates(COUNT, "Thinking");

/**
 * @brief Function to simulate the philosopher thinking
 * 
 * @param myID The ID of the philosopher
 */
void think(int myID) {
    int seconds = rand() % THINKTIME + 1;
    std::cout << "Philosopher " << myID << " is thinking! " << std::endl;
    philosopherStates[myID] = "Thinking";
    sleep(seconds);
}

/**
 * @brief Function to simulate a philosopher picking up forks
 * 
 * @param philID The ID of the philosopher
 */
void get_forks(int philID) {
    forks[philID].Wait();
    forks[(philID + 1) % COUNT].Wait();

    philosopherStates[philID] = "Holding Forks";
    philosopherStates[(philID + 1) % COUNT] = "Holding Forks";

    std::cout << philID << " is holding forks! " << std::endl;
}

/**
 * @brief Function to simulate a philosopher putting down forks
 * 
 * @param philID The ID of the philosopher
 */
void put_forks(int philID) {
    forks[philID].Signal();
    forks[(philID + 1) % COUNT].Signal();

    philosopherStates[philID] = "Thinking";
    philosopherStates[(philID + 1) % COUNT] = "Thinking";

    std::cout << philID << " put down forks! " << std::endl;
}

/**
 * @brief Function to simulate the philosopher eating
 * 
 * @param myID The ID of the philosopher
 */
void eat(int myID) {
    int seconds = rand() % EATTIME + 1;
    std::cout << "Philosopher " << myID << " is eating! " << std::endl;
    philosopherStates[myID] = "Eating";
    sleep(seconds);
}

/**
 * @brief Function to represent the life cycle of a philosopher
 * 
 * @param id The ID of the philosopher
 */
void philosopher(int id) {
    while (true) {
        think(id);
        get_forks(id);
        eat(id);
        put_forks(id);
    }
}

/**
 * @brief Main function
 * 
 * @return 0 upon successful execution
 */
int main(void) {
    srand(time(NULL)); // Initialize random seed:

    // Initialize forks
    for (Semaphore& s : forks) {
        s.Signal();
    }

    int id = 0;
    std::vector<std::thread> vt(COUNT);

    // Launch philosopher threads
    for (std::thread& t : vt) {
        t = std::thread(philosopher, id++);
    }

    // Join the philosopher threads with the main thread
    for (auto& v : vt) {
        v.join();
    }

    return 0;
}
