/**
 * @file Semaphore.cpp
 * @brief Implementation file for the Semaphore class.
 *
 * This file contains the implementation of the Semaphore class methods, including waiting on the semaphore,
 * waiting with a timeout, and signaling (releasing) the semaphore.
 *
 * @author Joseph Kehoe
 * @editor Marcel Zama
 * @date 14/11/2023
 * @license GPL-3.0 (See LICENSE text for the full LICENSE)
 * @link https://github.com/MarcelZama/Concurrent-Dev/tree/main
 */

#include "Semaphore.h"

/**
 * @brief Function to wait on the semaphore.
 */
void Semaphore::Wait()
{
    std::unique_lock<std::mutex> lock(m_mutex);
    m_condition.wait(lock, [&]()->bool { return m_uiCount > 0; });
    --m_uiCount;
}

/**
 * @brief Function to wait on the semaphore with a timeout.
 * @tparam R Type of duration representing seconds.
 * @tparam P Type of duration representing periods.
 * @param crRelTime Relative time duration to wait.
 * @return True if the semaphore was successfully acquired within the specified time, false otherwise.
 */
template <typename R, typename P>
bool Semaphore::Wait(const std::chrono::duration<R, P>& crRelTime)
{
    std::unique_lock<std::mutex> lock(m_mutex);
    if (!m_condition.wait_for(lock, crRelTime, [&]()->bool { return m_uiCount > 0; })) {
        return false;
    }
    --m_uiCount;
    return true;
}

/**
 * @brief Function to signal (release) the semaphore.
 */
void Semaphore::Signal()
{
    std::unique_lock<std::mutex> lock(m_mutex);
    ++m_uiCount;
    m_condition.notify_one();
}
