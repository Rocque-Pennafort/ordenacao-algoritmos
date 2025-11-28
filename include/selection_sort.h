#ifndef SELECTION_SORT_H
#define SELECTION_SORT_H

#include <time.h>

// Structure to hold sorting results
typedef struct {
    double executionTime;
    int comparisons;
    int swaps;
} SelectionSortResult;

// Function prototypes for selection sort
SelectionSortResult selectionSort(int arr[], int size);
double getSelectionSortExecutionTime(clock_t start, clock_t end);

#endif
