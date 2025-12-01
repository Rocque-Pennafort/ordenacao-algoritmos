#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include "../include/quick_sort.h"

void quickSortRecursive(int arr[], int low, int high, int *comparisons, int *swaps) {
    if (low < high) {
        int pivot = arr[high];
        int i = (low - 1);
        
        for (int j = low; j <= high - 1; j++) {
            (*comparisons)++;
            if (arr[j] < pivot) {
                i++;
                // Swap
                int temp = arr[i];
                arr[i] = arr[j];
                arr[j] = temp;
                (*swaps)++;
            }
        }
        // Swap pivot
        int temp = arr[i + 1];
        arr[i + 1] = arr[high];
        arr[high] = temp;
        (*swaps)++;
        
        int pi = i + 1;
        
        quickSortRecursive(arr, low, pi - 1, comparisons, swaps);
        quickSortRecursive(arr, pi + 1, high, comparisons, swaps);
    }
}

QuickSortResult quickSort(int arr[], int size) {
    clock_t start, end;
    QuickSortResult result = {0, 0, 0};
    
    start = clock();
    quickSortRecursive(arr, 0, size - 1, &result.comparisons, &result.swaps);
    end = clock();
    
    result.executionTime = ((double)(end - start)) / CLOCKS_PER_SEC;
    
    return result;
}
