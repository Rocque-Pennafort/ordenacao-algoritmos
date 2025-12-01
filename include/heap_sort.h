#ifndef HEAP_SORT_H
#define HEAP_SORT_H

#include <time.h>

// Structure to hold sorting results
typedef struct {
    double executionTime;
    int comparisons;
    int swaps;
} HeapSortResult;

// Function prototypes for heap sort
HeapSortResult heapSort(int arr[], int size);

#endif
