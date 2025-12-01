#ifndef SORTING_ALGORITHMS_H
#define SORTING_ALGORITHMS_H

#include "bubble_sort.h"
#include "insertion_sort.h"
#include "selection_sort.h"
#include "shell_sort.h"
#include "quick_sort.h"
#include "merge_sort.h"
#include "heap_sort.h"
#include "radix_sort.h"

// General functions for file operations and utilities
int* readFileToArray(const char* filename, int* size);
void printArray(int arr[], int size);

#endif
