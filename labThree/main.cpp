#include "Barrier.h"
#include <thread>
#include <vector>

//Author: Joseph Kehoe
//Edited by:
//Name: Marcel Zama
//College ID: C00260146
//Date: 14/11/2023
//License: GPL-3.0 (See LICENSE text for the full LICENSE)
//GitHub Link:https://github.com/MarcelZama/Concurrent-Dev/tree/main

/*! 
    \brief Displays the first function in the barrier being executed 
*/
void task(std::shared_ptr<Barrier> barrierObj) {
    std::cout << "first " << std::endl;

    // Wait for all threads to reach the barrier
    barrierObj->waitForAll();

    std::cout << "second" << std::endl;
}

int main(void) {
    // An array of threads
    std::vector<std::thread> threadArray(5);

    // Pointer to the barrier object
    std::shared_ptr<Barrier> barrierObj(new Barrier);

    // Set the count for synchronization
    barrierObj->setCount(5);

    // Launch threads
    for (int i = 0; i < threadArray.size(); i++) {
        threadArray[i] = std::thread(task, barrierObj);
    }

    // Wait for all threads to finish
    for (int i = 0; i < threadArray.size(); i++) {
        threadArray[i].join();
    }

    return 0;
}
