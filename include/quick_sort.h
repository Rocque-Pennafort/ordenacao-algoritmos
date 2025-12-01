#ifndef QUICK_SORT_H
#define QUICK_SORT_H

#include <time.h>

// Structure to hold sorting results
typedef struct {
    double executionTime;
    int comparisons;
    int swaps;
} QuickSortResult;

// Function prototypes for quick sort
QuickSortResult quickSort(int arr[], int size);

#endif
