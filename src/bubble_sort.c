#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include "../include/bubble_sort.h"

double getBubbleSortExecutionTime(clock_t start, clock_t end) {
    return ((double)(end - start)) / CLOCKS_PER_SEC;
}

BubbleSortResult bubbleSort(int arr[], int size) {
    clock_t start, end;
    BubbleSortResult result = {0, 0, 0};
    
    start = clock();
    
    for (int i = 0; i < size - 1; i++) {
        for (int j = 0; j < size - i - 1; j++) {
            result.comparisons++;
            if (arr[j] > arr[j + 1]) {
                // Swap elements
                int temp = arr[j];
                arr[j] = arr[j + 1];
                arr[j + 1] = temp;
                result.swaps++;
            }
        }
    }
    
    end = clock();
    result.executionTime = getBubbleSortExecutionTime(start, end);
    
    return result;
}
