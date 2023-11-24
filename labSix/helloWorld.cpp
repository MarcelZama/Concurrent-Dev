/**
 * @file helloThreads.cpp
 * @brief An OpenMP program to print "Hello World" using C language with parallel threads.
 *
 * @author Joseph Kehoe
 * @editor Marcel Zama
 * @date 14/11/2023
 * @license GPL-3.0 (See LICENSE text for the full LICENSE)
 * @link https://github.com/MarcelZama/Concurrent-Dev/tree/main
 */

// OpenMP header
#include <omp.h>

#include <stdio.h>
#include <stdlib.h>

/**
 * @brief Main function to execute the Hello World program with parallel threads.
 *
 * @param argc The number of command-line arguments.
 * @param argv An array of command-line arguments.
 * @return 0 if the program executes successfully.
 */
int main(int argc, char* argv[])
{
    // Beginning of parallel region
    #pragma omp parallel
    {
        printf("Hello World... from thread = %d\n", omp_get_thread_num());
    }
    // Ending of parallel region

    return 0;
}

// helloThreads.cpp ends here
