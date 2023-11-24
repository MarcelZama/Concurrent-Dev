//Author: Joseph Kehoe
//Edited by:
//Name: Marcel Zama
//College ID: C00260146
//Date: 14/11/2023
//License: GPL-3.0 (See LICENSE text for the full LICENSE)
//GitHub Link:https://github.com/MarcelZama/Concurrent-Dev/tree/main

#ifndef SEMAPHORE_H
#define SEMAPHORE_H 

#include <mutex>
#include <condition_variable>
#include <chrono>

/*! \class Semaphore
    \brief A Semaphore Implementation

   Uses C++11 features such as mutex and condition variables to implement Semaphore
*/

class Semaphore
{
private:
    unsigned int m_uiCount; /*!< Holds the Semaphore count */
    std::mutex m_mutex;
    std::condition_variable m_condition;

public:
    Semaphore(unsigned int uiCount = 0)
          : m_uiCount(uiCount) { };

    // Function to wait on the semaphore
    void Wait();

    // Function to wait on the semaphore with a timeout
    template <typename R, typename P>
    bool Wait(const std::chrono::duration<R, P>& crRelTime);

    // Function to signal (release) the semaphore
    void Signal();

    // Function to get the current count of the semaphore
    // int getCount();
};

#endif
