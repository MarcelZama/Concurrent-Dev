#include <mutex>
#include <condition_variable>

//Author: Joseph Kehoe
//Edited by:
//Name: Marcel Zama
//College ID: C00260146
//Date: 14/11/2023
//License: GPL-3.0 (See LICENSE text for the full LICENSE)
//GitHub Link:https://github.com/MarcelZama/Concurrent-Dev/tree/main

/*! \class Semaphore
    \brief A Semaphore Implementation

   Uses C++11 features such as mutex and condition variables to implement Semaphore
*/

class Semaphore
{
private:
    unsigned int m_uiCount; /*!< Holds the Semaphore count */
    std::mutex m_mutex; /*!< Mutex for thread synchronization */
    std::condition_variable m_condition; /*!< Condition variable for thread synchronization */

public:
    /*!
        brief Constructor for Semaphore
        
        param uiCount Initial count for the Semaphore (default is 0)
    */
    Semaphore(unsigned int uiCount=0)
      : m_uiCount(uiCount) { };

    void Wait();
    void Signal();
    int getCount();
};

