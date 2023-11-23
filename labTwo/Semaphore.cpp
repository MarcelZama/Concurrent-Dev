#include "Semaphore.h"

/*! 
    \class Semaphore
    \brief A Semaphore Implementation

    Uses C++11 features such as mutex and condition variables to implement Semaphore
*/

void Semaphore::Wait() {
    // Acquire a unique lock on the mutex
    std::unique_lock<std::mutex> lock(m_mutex);

    // Wait until the condition (m_uiCount > 0) is satisfied
    m_condition.wait(lock, [&]() -> bool {
        return m_uiCount > 0;
    });

    // Decrement the semaphore count after acquiring the lock
    --m_uiCount;
}

/*! 
    \brief Waits for the semaphore with a timeout.
    
    Acquires a unique lock on the mutex and waits for a specified duration until
    the condition (m_uiCount > 0) is satisfied. Returns false if the wait times out.
    
    \tparam R The type of the duration's rep (usually a placeholder for a floating-point type).
    \tparam P The type of the duration's period (usually a ratio representing seconds).
    \param crRelTime The relative time duration to wait.
    \return true if the wait is successful, false if it times out.
*/
template <typename R, typename P>
bool Semaphore::Wait(const std::chrono::duration<R, P>& crRelTime) {
    // Acquire a unique lock on the mutex
    std::unique_lock<std::mutex> lock(m_mutex);

    // Wait for a specified duration until the condition (m_uiCount > 0) is satisfied
    if (!m_condition.wait_for(lock, crRelTime, [&]() -> bool {
            return m_uiCount > 0;
        })) {
        // Return false if the wait times out
        return false;
    }

    // Decrement the semaphore count after acquiring the lock
    --m_uiCount;
    
    // Return true to indicate successful wait
    return true;
}

/*! 
    \brief Signals (releases) the semaphore.
    
    Acquires a unique lock on the mutex, increments the semaphore count, and
    notifies one waiting thread that the condition might have changed.
*/
void Semaphore::Signal() {
    // Acquire a unique lock on the mutex
    std::unique_lock<std::mutex> lock(m_mutex);

    // Increment the semaphore count
    ++m_uiCount;

    // Notify one waiting thread that the condition might have changed
    m_condition.notify_one();
}
