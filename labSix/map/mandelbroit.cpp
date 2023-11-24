/**
 * @file mandelbrot.cpp
 * @brief A program to generate the Mandelbrot set using OpenMP for parallelization.
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
#include <limits>

using namespace std;

const int ROW = 1000;
const int COL = 1000;
const int DEPTH = 10;

/**
 * @brief Calculates the Mandelbrot set value for a given complex number.
 *
 * @param c The complex number for which the Mandelbrot set value is calculated.
 * @param depth The depth or maximum number of iterations for the calculation.
 * @return The Mandelbrot set value for the given complex number.
 */
int calc(complex<int> c, int depth) {
    int count = 0;
    complex<int> z = 0;
    
    for (int i = 0; i < depth; ++i) {
        if (abs(z) > 2.0) {
            break;
        }
        z = z * z + c;
        count++;
    }
    return count;
}

/**
 * @brief Generates the Mandelbrot set and stores the result in a 2D array.
 *
 * @param p The 2D array to store the Mandelbrot set values.
 * @param depth The depth or maximum number of iterations for the Mandelbrot set calculation.
 */
void mandel(int p[ROW][COL], int depth) {
    #pragma omp parallel for collapse(2)
    for (int i = 0; i < ROW; ++i) {
        for (int k = 0; k < COL; ++k) {
            p[i][k] = calc(complex<int>(i, k), depth);
        }
    }
}

/**
 * @brief Main function to execute the Mandelbrot set generation and measure the execution time.
 *
 * @return 0 if the program executes successfully.
 */
int main(void) {
    int myArray[ROW][COL];

    /* initialize random seed: */
    srand(time(NULL));

    clock_t begin = clock();
    mandel(myArray, DEPTH);
    clock_t end = clock();

    double timeSec = (end - begin) / static_cast<double>(CLOCKS_PER_SEC);
    std::cout << timeSec << std::endl;

    return 0;
}

// mandelbroit.cpp ends here
