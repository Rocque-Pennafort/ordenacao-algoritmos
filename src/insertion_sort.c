#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include "../include/insertion_sort.h"

double getInsertionSortExecutionTime(clock_t start, clock_t end) {
    return ((double)(end - start)) / CLOCKS_PER_SEC;
}

InsertionSortResult insertionSort(int arr[], int size) {
    clock_t start, end;
    InsertionSortResult result = {0, 0, 0};
    
    start = clock();
    
    for (int i = 1; i < size; i++) {
        int key = arr[i];
        int j = i - 1;
        
        while (j >= 0) {
            result.comparisons++;
            if (arr[j] > key) {
                arr[j + 1] = arr[j];
                result.swaps++;
                j--;
            } else {
                break;
            }
        }
        arr[j + 1] = key;
    }
    
    end = clock();
    result.executionTime = getInsertionSortExecutionTime(start, end);
    
    return result;
}
