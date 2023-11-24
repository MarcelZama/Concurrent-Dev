#include "Barrier.h"

// Name: Marcel Zama
// College ID: C00260146
// Date: 10/10/2023
// Check Licence file for Licence details

/*! \class Barrier
    \brief An Implementation of a barrier Using Semaphores 

    Uses C++11 features such as mutex and condition variables to implement a barrier using Semaphores with N number of threads
*/

/*! \brief Barrier constructor
*/
Barrier::Barrier() {
    this->count = 0;
    threadNum = 0;
    condition = false;
    mutex = std::make_shared<Semaphore>(1);
    barrier1 = std::make_shared<Semaphore>(0);
    barrier2 = std::make_shared<Semaphore>(1);
}

/*! \brief Barrier constructor with parameter
    \param count The number of threads to synchronize
*/
Barrier::Barrier(int count) {
    this->count = count;
    threadNum = 0;
    condition = false;
    mutex = std::make_shared<Semaphore>(1);
    barrier1 = std::make_shared<Semaphore>(0);
    barrier2 = std::make_shared<Semaphore>(1);
}

/*! \brief Barrier destructor
*/
Barrier::~Barrier() {
}

/*! \brief Sets the count value
    \param x The new count value
*/
void Barrier::setCount(int x) {
    this->count = x;
}

/*! \brief Gets the current count value
    \return The current count value
*/
int Barrier::getCount() {
    return this->count;
}

/*! \brief Gets the count of the mutex semaphore
    \return The count of the mutex semaphore
*/
int Barrier::getMutexCount() {
    return mutex->getCount();
}

/*! \brief Gets the count of the entry barrier semaphore
    \return The count of the entry barrier semaphore
*/
int Barrier::getEntryCount() {
    return barrier1->getCount();
}

/*! \brief Gets the count of the exit barrier semaphore
    \return The count of the exit barrier semaphore
*/
int Barrier::getExitCount() {
    return barrier2->getCount();
}

/*! \brief Waits for all the threads before starting the second half of the code
*/
void Barrier::waitForAll() {
    mutex->Wait();
    threadNum++;

    if (threadNum == count) {
        barrier1->Signal();
        threadNum = 0;
    }

    mutex->Signal();
    barrier1->Wait();
    barrier1->Signal();
    mutex->Wait();
    threadNum--;

    if (threadNum == 0) {
        barrier1->Wait();
        barrier2->Signal();
    }

    mutex->Signal();
    barrier2->Wait();
    barrier2->Signal();
}
