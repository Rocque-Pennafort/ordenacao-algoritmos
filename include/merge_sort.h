#ifndef MERGE_SORT_H
#define MERGE_SORT_H

#include <time.h>

// Structure to hold sorting results
typedef struct {
    double executionTime;
    int comparisons;
    int swaps;
} MergeSortResult;

// Function prototypes for merge sort
MergeSortResult mergeSort(int arr[], int size);

#endif
