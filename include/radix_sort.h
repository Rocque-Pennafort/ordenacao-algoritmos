#ifndef RADIX_SORT_H
#define RADIX_SORT_H

#include <time.h>

// Structure to hold sorting results
typedef struct {
    double executionTime;
    int comparisons;
    int swaps;
} RadixSortResult;

// Function prototypes for radix sort
RadixSortResult radixSort(int arr[], int size);

#endif
