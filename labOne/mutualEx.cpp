//Author: Joseph Kehoe
//Edited by:
//Name: Marcel Zama
//College ID: C00260146
//Date: 14/11/2023
//License: GPL-3.0 (See LICENSE text for the full LICENSE)
//GitHub Link:https://github.com/MarcelZama/Concurrent-Dev/tree/main

#include "Semaphore.h"
#include <iostream>
#include <thread>
#include <vector>

static const int num_threads = 100;
int sharedVariable = 0;

/*! \file
    \brief Main program demonstrating Mutual Exclusion using Semaphores.
*/

/*! \fn updateTask
    \brief An Implementation of Mutual Exclusion using Semaphores.

    Uses C++11 features such as mutex and condition variables to implement an example of a rendezvous for threads.
    
    \param firstSem A shared pointer to the semaphore for synchronization.
    \param numUpdates The number of updates to the shared variable.
*/
void updateTask(std::shared_ptr<Semaphore> firstSem, int numUpdates) {
    firstSem->Wait(); // The first thread closes the door after it.

    for (int i = 0; i < numUpdates; i++) {
        // UPDATE SHARED VARIABLE HERE!
        sharedVariable++;
    }

    firstSem->Signal(); // The first thread opens the door and exits the method.
}

/*! \brief Main function.
 *
 * Launches multiple threads to demonstrate mutual exclusion using semaphores.
 * The last thread signals the semaphore to allow other threads to proceed.
 *
 * \return 0 on successful execution.
 */
int main(void) {
    std::vector<std::thread> vt(num_threads);
    std::shared_ptr<Semaphore> aSemaphore(new Semaphore);

    /**< Launch the threads */
    int i = 0;
    for (std::thread& t : vt) {
        t = std::thread(updateTask, aSemaphore, 1000);
        if (i == (num_threads - 1)) {
            aSemaphore->Signal(); // The last thread signals the semaphore.
        }
        i++;
    }

    std::cout << "Launched from the main\n";

    /**< Join the threads with the main thread */
    for (auto& v : vt) {
        v.join();
    }

    std::cout << sharedVariable << std::endl;
    return 0;
}
