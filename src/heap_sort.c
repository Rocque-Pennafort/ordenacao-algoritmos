#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include "../include/heap_sort.h"

void heapify(int arr[], int n, int i, int *comparisons, int *swaps) {
    int largest = i;
    int left = 2 * i + 1;
    int right = 2 * i + 2;

    (*comparisons)++;
    if (left < n && arr[left] > arr[largest])
        largest = left;

    (*comparisons)++;
    if (right < n && arr[right] > arr[largest])
        largest = right;

    if (largest != i) {
        int temp = arr[i];
        arr[i] = arr[largest];
        arr[largest] = temp;
        (*swaps)++;

        heapify(arr, n, largest, comparisons, swaps);
    }
}

HeapSortResult heapSort(int arr[], int size) {
    clock_t start, end;
    HeapSortResult result = {0, 0, 0};
    
    start = clock();

    // Build heap (rearrange array)
    for (int i = size / 2 - 1; i >= 0; i--)
        heapify(arr, size, i, &result.comparisons, &result.swaps);

    // One by one extract an element from heap
    for (int i = size - 1; i > 0; i--) {
        // Move current root to end
        int temp = arr[0];
        arr[0] = arr[i];
        arr[i] = temp;
        result.swaps++;

        // call max heapify on the reduced heap
        heapify(arr, i, 0, &result.comparisons, &result.swaps);
    }
    
    end = clock();
    result.executionTime = ((double)(end - start)) / CLOCKS_PER_SEC;
    
    return result;
}
