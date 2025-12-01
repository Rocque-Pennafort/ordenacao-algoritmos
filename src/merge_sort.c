#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include "../include/merge_sort.h"

void merge(int arr[], int l, int m, int r, int *comparisons, int *swaps) {
    int i, j, k;
    int n1 = m - l + 1;
    int n2 = r - m;
    
    // Create temp arrays
    int *L = (int*)malloc(n1 * sizeof(int));
    int *R = (int*)malloc(n2 * sizeof(int));
    
    if (L == NULL || R == NULL) {
        // Handle allocation failure if necessary, though simple implementation might skip
        return;
    }

    for (i = 0; i < n1; i++)
        L[i] = arr[l + i];
    for (j = 0; j < n2; j++)
        R[j] = arr[m + 1 + j];
        
    i = 0; 
    j = 0; 
    k = l; 
    while (i < n1 && j < n2) {
        (*comparisons)++;
        if (L[i] <= R[j]) {
            arr[k] = L[i];
            i++;
        } else {
            arr[k] = R[j];
            j++;
        }
        (*swaps)++; // Counting assignment as swap/move
        k++;
    }
    
    while (i < n1) {
        arr[k] = L[i];
        i++;
        k++;
        (*swaps)++;
    }
    
    while (j < n2) {
        arr[k] = R[j];
        j++;
        k++;
        (*swaps)++;
    }
    
    free(L);
    free(R);
}

void mergeSortRecursive(int arr[], int l, int r, int *comparisons, int *swaps) {
    if (l < r) {
        int m = l + (r - l) / 2;
        
        mergeSortRecursive(arr, l, m, comparisons, swaps);
        mergeSortRecursive(arr, m + 1, r, comparisons, swaps);
        
        merge(arr, l, m, r, comparisons, swaps);
    }
}

MergeSortResult mergeSort(int arr[], int size) {
    clock_t start, end;
    MergeSortResult result = {0, 0, 0};
    
    start = clock();
    mergeSortRecursive(arr, 0, size - 1, &result.comparisons, &result.swaps);
    end = clock();
    
    result.executionTime = ((double)(end - start)) / CLOCKS_PER_SEC;
    
    return result;
}
