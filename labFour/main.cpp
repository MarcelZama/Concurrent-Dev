/**
 * @file main.cpp
 * @brief Main file for the concurrent programming example.
 *
 * @author Joseph Kehoe
 * @editor Marcel Zama
 * @date 14/11/2023
 * @license GPL-3.0 (See LICENSE text for the full LICENSE)
 * @link https://github.com/MarcelZama/Concurrent-Dev/tree/main
 */

#include "Barrier.h"
#include "Event.h"
#include <iostream>
#include <thread>
#include <vector>

static const int num_threads = 100;
const int size = 20;

/**
 * @brief Producer function that creates events and adds them to the buffer.
 * @param theBuffer Shared pointer to the buffer.
 * @param numLoops Number of loops for the producer.
 */
void producer(std::shared_ptr<SafeBuffer<std::shared_ptr<Event>>> theBuffer, int numLoops) {
    for (int i = 0; i < numLoops; ++i) {
        // Produce event and add to the buffer
        std::shared_ptr<Event> e = std::make_shared<Event>(i);
        theBuffer->put(e);
    }
}

/**
 * @brief Consumer function that takes events from the buffer and consumes them.
 * @param theBuffer Shared pointer to the buffer.
 * @param numLoops Number of loops for the consumer.
 */
void consumer(std::shared_ptr<SafeBuffer<std::shared_ptr<Event>>> theBuffer, int numLoops) {
    for (int i = 0; i < numLoops; ++i) {
        // Take event from the buffer and consume it
        std::shared_ptr<Event> e = theBuffer->get();
        e->consume();
    }
}

/**
 * @brief Main function that launches producer and consumer threads.
 */
int main(void) {
    // Create a vector of threads
    std::vector<std::thread> vt(num_threads);

    // Create a shared pointer to a buffer of shared pointers to events
    std::shared_ptr<SafeBuffer<std::shared_ptr<Event>>> aBuffer(new Buffer<std::shared_ptr<Event>>(size));

    /**< Launch the threads */
    int i = 0;
    for (std::thread& t : vt) {
        // Assuming you have an 'updateTask' function, replace it with 'producer' or 'consumer' accordingly
        t = std::thread(updateTask, aBarrier, 10);
    }

    /**< Join the threads with the main thread */
    for (auto& v : vt) {
        v.join();
    }

    std::cout << sharedVariable << std::endl; // Assuming 'sharedVariable' is defined somewhere in your code

    return 0;
}
