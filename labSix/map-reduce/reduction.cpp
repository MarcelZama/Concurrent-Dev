/**
 * @file reduction.cpp
 * @brief A program to demonstrate parallel reduction using OpenMP.
 *
 * @author Joseph Kehoe
 * @editor Marcel Zama
 * @date 14/11/2023
 * @license GPL-3.0 (See LICENSE text for the full LICENSE)
 * @link https://github.com/MarcelZama/Concurrent-Dev/tree/main
 */

#include <iostream>
#include <stdlib.h>     /* srand, rand */
#include <complex>      /* complex number data type */
#include <time.h>       /* time */
#include <functional>   /* function type */
#include <limits>
#include <vector>       /* vectors used instead of arrays */
#include <omp.h>

using namespace std;

const int LENGTH = 2000;
int NumThreads = 1;

/**
 * @brief Gets the number of threads currently running in the parallel region.
 *
 * @return The number of threads.
 */
int get_num_threads(void) {
    int num_threads = 1;

    // must ask in parallel region otherwise 1 is returned
    #pragma omp parallel
    {
        #pragma omp single
        num_threads = omp_get_num_threads();
    }
    return num_threads;
}

/**
 * @brief Calculates the sum of elements in a vector using serial execution.
 *
 * @param data The vector to calculate the sum.
 * @return The sum of elements in the vector.
 */
float getSerialSum(vector<int> data) {
    float sum = 0.0;
    for (auto& value : data) {
        sum += value;
    }
    return sum;
}

/**
 * @brief Calculates the sum of elements in a vector using parallel execution.
 *
 * @param data The vector to calculate the sum.
 * @return The sum of elements in the vector.
 */
float getParallelSum(vector<int> data) {
    float sum = 0.0;

    #pragma omp parallel for reduction(+:sum)
    for (int i = 0; i < data.size(); ++i) {
        sum += data[i];
    }

    return sum;
}

/**
 * @brief Calculates the sum of elements in a vector using tiled parallel execution.
 *
 * @param data The vector to calculate the sum.
 * @return The sum of elements in the vector.
 */
float getTiledParallelSum(vector<int> data) {
    float result = 0.0;
    NumThreads = get_num_threads();
    float tileResult[NumThreads];

    for (int i = 0; i < NumThreads; ++i)
        tileResult[i] = 0.0;

    // map step here
    #pragma omp parallel for
    for (int i = 0; i < data.size(); ++i) {
        int tid = omp_get_thread_num();
        tileResult[tid] = tileResult[tid] + data[i];
    }

    // reduce step here
    for (int i = 0; i < NumThreads; ++i) {
        std::cout << i << ":" << tileResult[i] << "- ";
        result += tileResult[i];
    }

    std::cout << std::endl;
    return result;
}

/**
 * @brief Main function to demonstrate parallel reduction and display the results.
 *
 * @return 0 if the program executes successfully.
 */
int main(void) {
    float sum = 0.0;
    int average = 0;
    NumThreads = omp_get_num_threads();

    srand(time(NULL));
    vector<int> data(1000);

    for (auto& value : data) {
        value = 10; // rand()%1000;
    }

    sum = getSerialSum(data);
    average = sum / data.size();
    cout << "Serial Average is: " << average << endl;

    sum = getParallelSum(data);
    average = sum / data.size();
    cout << "Parallel Average is: " << average << endl;
    cout << endl;

    sum = getTiledParallelSum(data);
    average = sum / data.size();
    cout << "Tiled Parallel Average is: " << average << endl;
    cout << endl;

    return 0;
}

// reduction.cpp ends here
