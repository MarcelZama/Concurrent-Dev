/**
 * @file stencil.cpp
 * @brief A program to perform a stencil operation using OpenMP.
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

using namespace std;

// array dimension
const int DIM = 1000;
const int SIZE = 4;

/**
 * @brief Calculates the neighbors of a given element in the input vector.
 *
 * @param in The input vector.
 * @param index The index of the element for which neighbors are calculated.
 * @param out The vector to store the calculated neighbors.
 * @return 1 for successful calculation.
 */
int calcNeighbours(vector<float> const &in, int index, vector<float>& out) {
    int amount = out.size();
    for (int i = 0; i < out.size(); ++i) {
        int k = i - amount / 2;
        if (k < 0) {
            k = in.size() + k;
        } else if (k >= in.size()) {
            k = k - in.size();
        }
        out[i] = in[k];
    }
    return 1;
}

/**
 * @brief Performs the stencil operation on the input vector using a given function.
 *
 * @param in The input vector.
 * @param out The output vector.
 * @param f The function to apply for the stencil operation.
 * @param size The size of the stencil.
 */
void stencil(vector<float> const &in, vector<float> &out, function<float(vector<float>)> f, int size) {
    #pragma omp parallel for
    for (int i = 0; i < in.size(); ++i) {
        vector<float> neighbours(size);
        calcNeighbours(in, i, neighbours);
        out[i] = f(neighbours);
    }
}

/**
 * @brief Calculates the average value of a vector.
 *
 * @param currentValues The vector for which the average value is calculated.
 * @return The average value of the vector.
 */
float getNewValue(vector<float> currentValues) {
    float average = 0.0;
    float total = 0.0;
    for (auto const& value : currentValues) {
        total += value;
    }
    return total / currentValues.size();
}

/**
 * @brief Main function to perform a stencil operation and display the results.
 *
 * @return 0 if the program executes successfully.
 */
int main(void) {
    vector<float> first(DIM), second(DIM);

    // initialize vectors
    srand(time(NULL));

    for (auto& value : first) {
        value = (float)rand() / ((float)(RAND_MAX) + (float)(1));
    }

    for (auto it = second.begin(); it < second.end(); ++it) {
        *it = 0.0f;
    }

    float sum = 0.0f;
    for (auto const& value : first) {
        sum += value;
    }
    cout << sum << endl;

    stencil(first, second, getNewValue, SIZE);

    sum = 0.0f;
    for (auto const& value : second) {
        sum += value;
    }
    cout << sum << endl;

    return 0;
}

// stencil.cpp ends here
