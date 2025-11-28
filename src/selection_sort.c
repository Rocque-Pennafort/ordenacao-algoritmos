#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include "../include/selection_sort.h"

double getSelectionSortExecutionTime(clock_t start, clock_t end) {
    return ((double)(end - start)) / CLOCKS_PER_SEC;
}

SelectionSortResult selectionSort(int arr[], int size) {
    clock_t start, end;
    SelectionSortResult result = {0, 0, 0};
    
    start = clock();
    
    for (int x = 0; x < size - 1; x++) {
        int min = x;
        for (int y = x + 1; y < size; y++) {
            result.comparisons++;
            if (arr[y] < arr[min]) {
                min = y;
            }
        }
        
        if (min != x) {
            int temp = arr[x];
            arr[x] = arr[min];
            arr[min] = temp;
            result.swaps++;
        }
    }
    
    end = clock();
    result.executionTime = getSelectionSortExecutionTime(start, end);
    
    return result;
}
