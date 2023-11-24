/**
 * @file saxpy.cpp
 * @brief A program to perform SAXPY (Single-precision A * X Plus Y) operation using OpenMP for parallelization.
 *
 * @author Joseph Kehoe
 * @editor Marcel Zama
 * @date 14/11/2023
 * @license GPL-3.0 (See LICENSE text for the full LICENSE)
 * @link https://github.com/MarcelZama/Concurrent-Dev/tree/main
 */

#include <iostream>
#include <stdlib.h>     /* srand, rand */
#include <time.h>       /* time */
#include <limits>

/**
 * @brief Performs the SAXPY operation in parallel.
 *
 * @param n The size of the arrays.
 * @param a The scalar multiplier.
 * @param y The array to be updated.
 * @param x The input array.
 */
void saxpy(unsigned long n, float a, float y[], float x[]) {
    #pragma omp parallel for
    for (unsigned long i = 0; i < n; ++i) {
        y[i] = a * x[i] + y[i];
    }
}

/**
 * @brief Main function to execute the SAXPY operation and measure the execution time.
 *
 * @return 0 if the program executes successfully.
 */
int main(void) {
    const unsigned long size = 1000000;
    const float A = 1.234;

    float y[size];
    float x[size];

    /* initialize random seed: */
    srand(time(NULL));

    for (unsigned long long int i = 0; i < size; ++i) {
        y[i] = i * i;
        /* generate secret number between 1 and 1000000: */
        x[i] = rand() % 1000000 + 1;
    }

    clock_t begin = clock();
    saxpy(size, A, y, x);
    clock_t end = clock();

    double timeSec = (end - begin) / static_cast<double>(CLOCKS_PER_SEC);
    std::cout << timeSec << std::endl;

    return 0;
}

// saxpy.cpp ends here
