#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include "../include/radix_sort.h"

int getMax(int arr[], int n, int *comparisons) {
    int mx = arr[0];
    for (int i = 1; i < n; i++) {
        (*comparisons)++;
        if (arr[i] > mx)
            mx = arr[i];
    }
    return mx;
}

void countSort(int arr[], int n, int exp, int *comparisons, int *swaps) {
    int *output = (int*)malloc(n * sizeof(int));
    int i, count[10] = {0};

    if (output == NULL) return;

    // Store count of occurrences in count[]
    for (i = 0; i < n; i++)
        count[(arr[i] / exp) % 10]++;

    // Change count[i] so that count[i] now contains actual
    // position of this digit in output[]
    for (i = 1; i < 10; i++)
        count[i] += count[i - 1];

    // Build the output array
    for (i = n - 1; i >= 0; i--) {
        output[count[(arr[i] / exp) % 10] - 1] = arr[i];
        count[(arr[i] / exp) % 10]--;
        (*swaps)++; // Counting assignment to output array as a move/swap
    }

    // Copy the output array to arr[], so that arr[] now
    // contains sorted numbers according to current digit
    for (i = 0; i < n; i++) {
        arr[i] = output[i];
        (*swaps)++; // Counting assignment back to original array
    }
    
    free(output);
}

RadixSortResult radixSort(int arr[], int size) {
    clock_t start, end;
    RadixSortResult result = {0, 0, 0};
    
    start = clock();

    int m = getMax(arr, size, &result.comparisons);

    // Do counting sort for every digit. Note that instead
    // of passing digit number, exp is passed. exp is 10^i
    // where i is current digit number
    for (int exp = 1; m / exp > 0; exp *= 10)
        countSort(arr, size, exp, &result.comparisons, &result.swaps);
    
    end = clock();
    result.executionTime = ((double)(end - start)) / CLOCKS_PER_SEC;
    
    return result;
}
