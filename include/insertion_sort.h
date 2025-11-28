#ifndef INSERTION_SORT_H
#define INSERTION_SORT_H

#include <time.h>

// Structure to hold sorting results
typedef struct {
    double executionTime;
    int comparisons;
    int swaps;
} InsertionSortResult;

// Function prototypes for insertion sort
InsertionSortResult insertionSort(int arr[], int size);
double getInsertionSortExecutionTime(clock_t start, clock_t end);

#endif
