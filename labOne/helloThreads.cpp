#include "Semaphore.h"
#include <iostream>
#include <thread>
#include <unistd.h>

//Name: Marcel Zama
//College ID: C00260146
//Date: 04/10/2023
//Summary: This C++ code demonstrates the use of a semaphore for synchronization between two threads (threadOne and threadTwo).
//License: GPL-3.0 (See LICENSE text for the full LICENSE)

/*! \file
    \brief Main program to demonstrate semaphore usage between two threads.
*/

/*! \brief Function to execute taskOne.
 *
 * This function displays a message after a specified delay and then signals that taskOne has finished.
 *
 * \param theSemaphore A shared pointer to the semaphore for synchronization.
 * \param delay The delay in seconds before printing the message.
 */
void taskOne(std::shared_ptr<Semaphore> theSemaphore, int delay) {
    sleep(delay); // Program sleeps for 'delay' seconds.

    std::cout << "I ";
    std::cout << "must ";
    std::cout << "print ";
    std::cout << "first" << std::endl;

    theSemaphore->Signal(); // Releases the lock from the Semaphore

    // Signal that taskOne has finished
}

/*! \brief Function to execute taskTwo.
 *
 * This function waits for taskOne to finish, then ensures proper sequencing by waiting for a bit,
 * and finally displays a message.
 *
 * \param theSemaphore A shared pointer to the semaphore for synchronization.
 */
void taskTwo(std::shared_ptr<Semaphore> theSemaphore) {
    // Wait for taskOne to finish
    theSemaphore->Wait(); // Will let threads go only after theSemaphore->Signal(); from taskOne will be executed by the other thread.

    // Wait for a bit to ensure proper sequencing
    sleep(1); // Program sleeps for one second

    std::cout << "This ";
    std::cout << "will ";
    std::cout << "appear ";
    std::cout << "second" << std::endl;
}

/*! \brief Main function.
 *
 * Launches two threads (threadOne and threadTwo) and demonstrates the use of a semaphore for synchronization.
 *
 * \return 0 on successful execution.
 */
int main(void) {
    std::thread threadOne;
    std::thread threadTwo;
    std::shared_ptr<Semaphore> sem(new Semaphore);

    /**< Launch the threads */
    int taskOneDelay = 5;
    threadOne = std::thread(taskTwo, sem); // Task Two is launched first
    threadTwo = std::thread(taskOne, sem, taskOneDelay); // Task One is launched with a delay

    std::cout << "Launched from the main\n";

    /**< Wait for the threads to finish */
    threadOne.join();
    threadTwo.join();

    return 0;
}
