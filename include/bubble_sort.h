#ifndef BUBBLE_SORT_H
#define BUBBLE_SORT_H

#include <time.h>

// Structure to hold sorting results
typedef struct {
    double executionTime;
    int comparisons;
    int swaps;
} BubbleSortResult;

// Function prototypes for bubble sort
BubbleSortResult bubbleSort(int arr[], int size);
double getBubbleSortExecutionTime(clock_t start, clock_t end);

#endif
