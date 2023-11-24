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

/*! \file
    \brief Declaration of the Semaphore class.
*/

/*! \class Semaphore
    \brief A Semaphore Implementation.

    Uses C++11 features such as mutex and condition variables to implement Semaphore.
*/

class Semaphore
{
private:
    unsigned int m_uiCount; /*!< Holds the Semaphore count */
    std::mutex m_mutex;
    std::condition_variable m_condition;

public:
    /*! \fn Semaphore(unsigned int uiCount = 0)
        \brief Constructor for Semaphore.

        Initializes the Semaphore with an optional initial count.

        \param uiCount The initial count of the semaphore.
    */
    Semaphore(unsigned int uiCount = 0);

    /*! \fn void Wait()
        \brief Wait on the semaphore.

        This function waits on the semaphore until the count is greater than 0.
        Decreases the count by 1 when successfully acquiring the semaphore.

        \return void
    */
    void Wait();

    /*! \fn template <typename R, typename P> bool Wait(const std::chrono::duration<R, P>& crRelTime)
        \brief Wait on the semaphore with a timeout.

        This function waits on the semaphore until the count is greater than 0 or until the specified timeout duration elapses.
        Decreases the count by 1 when successfully acquiring the semaphore.

        \param crRelTime The relative timeout duration.
        \return True if the semaphore is acquired within the timeout, false otherwise.
    */
    template <typename R, typename P>
    bool Wait(const std::chrono::duration<R, P>& crRelTime);

    /*! \fn void Signal()
        \brief Signal (release) the semaphore.

        This function increases the count by 1 and notifies one waiting thread.

        \return void
    */
    void Signal();
};

#endif
