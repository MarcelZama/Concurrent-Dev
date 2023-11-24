//Author: Joseph Kehoe
//Edited by:
//Name: Marcel Zama
//College ID: C00260146
//Date: 14/11/2023
//License: GPL-3.0 (See LICENSE text for the full LICENSE)
//GitHub Link:https://github.com/MarcelZama/Concurrent-Dev/tree/main

#include "Semaphore.h"

/*! 
    \class Semaphore
    \brief A Semaphore Implementation

    Uses C++11 features such as mutex and condition variables to implement Semaphore
*/

// Function to wait on the semaphore
void Semaphore::Wait() {
    std::unique_lock<std::mutex> lock(m_mutex);
    m_condition.wait(lock, [&]()->bool { return m_uiCount > 0; });
    --m_uiCount;
}

// Function to wait on the semaphore with a timeout
template <typename R, typename P>
bool Semaphore::Wait(const std::chrono::duration<R, P>& crRelTime) {
    std::unique_lock<std::mutex> lock(m_mutex);
    if (!m_condition.wait_for(lock, crRelTime, [&]()->bool { return m_uiCount > 0; })) {
        return false;
    }
    --m_uiCount;
    return true;
}

// Function to signal (release) the semaphore
void Semaphore::Signal() {
    std::unique_lock<std::mutex> lock(m_mutex);
    ++m_uiCount;
    m_condition.notify_one();
}

// Function to get the current count of the semaphore
// int Semaphore::getCount() {
//     return m_uiCount;
// }
