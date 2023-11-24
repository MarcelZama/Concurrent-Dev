#include "Semaphore.h"
#include <iostream>
#include <stdio.h>

// Name: Marcel Zama
// College ID: C00260146
// Date: 10/10/2023
// Check Licence file for Licence details

/*! \class Barrier
    \brief A Barrier Implementation

    Uses C++11 features such as mutex and condition variables to implement a Barrier class using Semaphores
*/
class Barrier
{
private:
    int count;                          /*!< The number of threads to synchronize */
    int threadNum;                      /*!< The current thread number */
    bool condition;                     /*!< A condition variable for synchronization */
    std::shared_ptr<Semaphore> mutex;   /*!< Mutex for critical sections */
    std::shared_ptr<Semaphore> barrier1; /*!< Semaphore for the entry barrier */
    std::shared_ptr<Semaphore> barrier2; /*!< Semaphore for the exit barrier */

public:
    /*! \brief Default constructor */
    Barrier();

    /*! \brief Destructor */
    ~Barrier();

    /*! \brief Constructor with count parameter */
    Barrier(int count);

    /*! \brief Setter for the count variable */
    void setCount(int count);

    /*! \brief Getter for the count variable */
    int getCount();

    /*! \brief Function to wait for all threads to reach the barrier */
    void waitForAll();

    // Test-related functions

    /*! \brief Getter for the count of the mutex semaphore */
    int getMutexCount();

    /*! \brief Getter for the count of the entry barrier semaphore */
    int getEntryCount();

    /*! \brief Getter for the count of the exit barrier semaphore */
    int getExitCount();
};
