#ifndef SHELL_SORT_H
#define SHELL_SORT_H

#include <time.h>

// Structure to hold sorting results
typedef struct {
    double executionTime;
    int comparisons;
    int swaps;
} ShellSortResult;

// Function prototypes for shell sort
ShellSortResult shellSort(int arr[], int size);
double getShellSortExecutionTime(clock_t start, clock_t end);

#endif
