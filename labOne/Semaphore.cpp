//Author: Joseph Kehoe
//Edited by:
//Name: Marcel Zama
//College ID: C00260146
//Date: 14/11/2023
//License: GPL-3.0 (See LICENSE text for the full LICENSE)
//GitHub Link:https://github.com/MarcelZama/Concurrent-Dev/tree/main

#include "Semaphore.h"

/*! \file
    \brief Implementation of the Semaphore class.
*/

/*! \class Semaphore
    \brief A Semaphore Implementation.

    Uses C++11 features such as mutex and condition variables to implement Semaphore.
*/

/*! \fn Semaphore::Wait()
    \brief Wait on the semaphore.

    This function waits on the semaphore until the count is greater than 0.
    Decreases the count by 1 when successfully acquiring the semaphore.

    \return void
*/
void Semaphore::Wait() {
    std::unique_lock<std::mutex> lock(m_mutex);
    m_condition.wait(lock, [&]() -> bool { return m_uiCount > 0; });
    --m_uiCount;
}

/*! \fn Semaphore::Wait(const std::chrono::duration<R, P>& crRelTime)
    \brief Wait on the semaphore with a timeout.

    This function waits on the semaphore until the count is greater than 0 or until the specified timeout duration elapses.
    Decreases the count by 1 when successfully acquiring the semaphore.

    \param crRelTime The relative timeout duration.
    \return True if the semaphore is acquired within the timeout, false otherwise.
*/
template <typename R, typename P>
bool Semaphore::Wait(const std::chrono::duration<R, P>& crRelTime) {
    std::unique_lock<std::mutex> lock(m_mutex);
    if (!m_condition.wait_for(lock, crRelTime, [&]() -> bool { return m_uiCount > 0; })) {
        return false;
    }
    --m_uiCount;
    return true;
}

/*! \fn Semaphore::Signal()
    \brief Signal (release) the semaphore.

    This function increases the count by 1 and notifies one waiting thread.

    \return void
*/
void Semaphore::Signal() {
    std::unique_lock<std::mutex> lock(m_mutex);
    ++m_uiCount;
    m_condition.notify_one();
}
