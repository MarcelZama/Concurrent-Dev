#include <mutex>
#include <condition_variable>

//Name : Marcel Zama
//College ID : C00260146
//Date : 10/10/2023
//Check Licence file for Licence details

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

