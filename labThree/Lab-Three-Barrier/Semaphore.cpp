#include "Semaphore.h"

//Name : Marcel Zama
//College ID : C00260146
//Date : 10/10/2023
//Check Licence file for Licence details

/*! \class Semaphore
    \brief A Semaphore Implementation

   Uses C++11 features such as mutex and condition variables to implement Semaphore
*/

/*! 
    \brief Closes the thread

    This method is used to implement the Wait operation of a Semaphore.
    It waits until the count is greater than 0, and then decrements the count.
*/
void Semaphore::Wait()
{
      std::unique_lock< std::mutex > lock(m_mutex);
      m_condition.wait(lock,[&]()->bool{ return m_uiCount>0; });
      --m_uiCount; 
}

/*! 
    \brief Allows a thread to open

    This method is used to implement the Signal operation of a Semaphore.
    It increments the count and notifies one waiting thread.
*/
void Semaphore::Signal() 
{
      std::unique_lock< std::mutex > lock(m_mutex);
      ++m_uiCount;
      m_condition.notify_one();
}

int Semaphore::getCount() {
      return m_uiCount;
}
