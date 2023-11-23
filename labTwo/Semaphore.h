#ifndef SEMAPHORE_H
#define SEMAPHORE_H 

#include <mutex>
#include <condition_variable>
#include <chrono>

/*! 
    \class Semaphore
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
    /*!
        \brief Constructor for Semaphore class
        
        \param uiCount Initial count for the semaphore (default is 0)
    */
    Semaphore(unsigned int uiCount = 0)
        : m_uiCount(uiCount) { };

    /*!
        \brief Waits on the semaphore indefinitely
        
        Acquires a lock on the mutex, waits until the semaphore count is greater than 0, and then decrements the count.

        \sa Signal()
    */
    void Wait();

    /*!
        \brief Waits on the semaphore with a timeout
        
        Acquires a lock on the mutex, waits for a specified duration until the semaphore count is greater than 0, and then decrements the count.
        
        \tparam R Type representing the number of ticks in the duration
        \tparam P Type representing the period of the duration

        \param crRelTime The duration to wait

        \return true if the wait was successful, false if it timed out

        \sa Signal()
    */
    template <typename R, typename P>
    bool Wait(const std::chrono::duration<R, P>& crRelTime);

    /*!
        \brief Signals (releases) the semaphore
        
        Acquires a lock on the mutex, increments the semaphore count, and notifies one waiting thread that the condition might have changed.

        \sa Wait()
    */
    void Signal();
};

#endif
