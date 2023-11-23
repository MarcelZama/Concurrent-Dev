#include "Semaphore.h"
#include <thread>
#include <vector>
#include <iostream>

// Name: Marcel Zama
// College ID: C00260146
// Date: 10/10/2023
// Check License for License details

/*! \file
    \brief Implementation of a barrier synchronization mechanism using semaphores.
*/

/*! 
    \fn void task(std::shared_ptr<Semaphore> mutexSem, std::shared_ptr<Semaphore> barrierSem, int *threadCount)
    \brief Displays the first function in the barrier being executed.

    \param mutexSem A semaphore to control access to the critical section.
    \param barrierSem A semaphore for barrier synchronization.
    \param threadCount A pointer to the count of active threads.
    \return void
*/
void task(std::shared_ptr<Semaphore> mutexSem, std::shared_ptr<Semaphore> barrierSem, int *threadCount) {
    mutexSem->Wait(); // The first thread closes the door after entering the function
    --(*threadCount); // Counting the number of the thread in execution

    if (*threadCount > 0) {
        std::cout << "First" << std::endl;
        mutexSem->Signal(); // Let other threads pass the mutexSem
    } else {
        std::cout << "First" << std::endl;
        barrierSem->Signal(); // When the last thread comes in, it opens the barrier for other threads to continue executing.
    }

    barrierSem->Wait(); // Locks the lock, here all threads wait for the last thread to finish executing
    std::cout << "Second" << std::endl;
    barrierSem->Signal(); // Barriers one by one open the door after executing the door
}

/*! 
    \fn int main(void)
    \brief Main function to demonstrate the barrier synchronization mechanism.

    \return 0 on successful execution.
*/
int main(void) {
    std::shared_ptr<Semaphore> mutexSem;
    std::shared_ptr<Semaphore> barrierSem;
    int threadCount = 5;
    mutexSem = std::make_shared<Semaphore>(1);
    barrierSem = std::make_shared<Semaphore>(0);

    // An array of threads
    std::vector<std::thread> threadArray(threadCount);

    for (int i = 0; i < threadArray.size(); i++) {
        threadArray[i] = std::thread(task, mutexSem, barrierSem, &threadCount);
    }

    for (int i = 0; i < threadArray.size(); i++) {
        threadArray[i].join();
    }

    return 0;
}
