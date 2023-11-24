/**
 * @file Semaphore.h
 * @brief Header file for the Semaphore class.
 *
 * This file defines the Semaphore class, which is an implementation of a semaphore using C++11 features
 * such as mutex and condition variables. It provides methods for waiting on the semaphore, waiting with a timeout,
 * and signaling (releasing) the semaphore.
 *
 * @author Joseph Kehoe
 * @editor Marcel Zama
 * @date 14/11/2023
 * @license GPL-3.0 (See LICENSE text for the full LICENSE)
 * @link https://github.com/MarcelZama/Concurrent-Dev/tree/main
 */

#ifndef SEMAPHORE_H
#define SEMAPHORE_H

#include <mutex>
#include <condition_variable>
#include <chrono>

/**
 * @class Semaphore
 * @brief A class representing a semaphore.
 */
class Semaphore
{
private:
    unsigned int m_uiCount; /*!< Holds the Semaphore count */
    std::mutex m_mutex; /**< Mutex for thread safety */
    std::condition_variable m_condition; /**< Condition variable for signaling */

public:
    /**
     * @brief Constructor for the Semaphore class.
     * @param uiCount The initial count of the semaphore.
     */
    Semaphore(unsigned int uiCount = 0);

    /**
     * @brief Function to wait on the semaphore.
     */
    void Wait();

    /**
     * @brief Function to wait on the semaphore with a timeout.
     * @tparam R The type of the clock's duration.
     * @tparam P The type of the clock's period.
     * @param crRelTime The relative time duration to wait.
     * @return True if the wait is successful; false if the wait times out.
     */
    template <typename R, typename P>
    bool Wait(const std::chrono::duration<R, P>& crRelTime);

    /**
     * @brief Function to signal (release) the semaphore.
     */
    void Signal();
};

#endif
