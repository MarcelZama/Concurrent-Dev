/**
 * @file quicksort.cpp
 * @brief A program to perform parallel quicksort using OpenMP.
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

const int LENGTH = 2000;

/**
 * @brief Partitions the vector for quicksort.
 *
 * @param myArray The vector to be partitioned.
 * @param low The lower index of the partition.
 * @param high The higher index of the partition.
 * @return The index of the pivot element after partitioning.
 */
int partition(vector<int>& myArray, int low, int high) {
    int pivot = myArray[high];
    int k = high;
    int i = low;
    int temp = 0;

    while (i < k) {
        while (myArray[i] < pivot && i < k) ++i;
        while (myArray[k] > pivot && i < k) --k;

        if (i < k) {
            temp = myArray[i];
            myArray[i] = myArray[k];
            myArray[k] = temp;
            i++; // do not decrement k here OR ELSE!!
        }
    }
    return i - 1;
}

/**
 * @brief Recursive function for parallel quicksort.
 *
 * @param myArray The vector to be sorted.
 * @param low The lower index of the vector to be sorted.
 * @param high The higher index of the vector to be sorted.
 * @return 1 for successful sorting.
 */
int quicksort(vector<int>& myArray, int low, int high) {
    if (low < high) {
        int pivot = partition(myArray, low, high);

        // really we should only do this if each partition is above a certain size (1000 elements?)
        // otherwise the overhead outweighs any gains from using threads
        #pragma omp task shared(myArray)
        quicksort(myArray, low, pivot);
        quicksort(myArray, pivot + 1, high);

        #pragma omp taskwait
        return 1;
    }
}

/**
 * @brief Main function to execute parallel quicksort and display the results.
 *
 * @return 0 if the program executes successfully.
 */
int main(void) {
    srand(time(NULL));
    vector<int> data(LENGTH);

    for (auto& value : data) {
        value = rand() % 1000;
    }

    cout << "Original Array:" << endl;
    for (auto& value : data) {
        cout << value << " ";
    }

    cout << endl << "*******************************" << endl;

    quicksort(data, 0, data.size() - 1);

    cout << "Sorted Array:" << endl;
    for (auto& value : data) {
        cout << value << " ";
    }

    cout << endl;

    return 0;
}

// quicksort.cpp ends here
