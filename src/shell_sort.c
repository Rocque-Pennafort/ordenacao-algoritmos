#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include "../include/shell_sort.h"

double getShellSortExecutionTime(clock_t start, clock_t end) {
    return ((double)(end - start)) / CLOCKS_PER_SEC;
}

ShellSortResult shellSort(int arr[], int size) {
    clock_t start, end;
    ShellSortResult result = {0, 0, 0};
    int h, i, j, aux;
    
    start = clock();
    
    // Calcula h inicial
    for (h = 1; h < size; h = 3 * h + 1);
    
    while (h > 0) {
        h = (h - 1) / 3;
        
        for (i = h; i < size; i++) {
            aux = arr[i];
            j = i;
            
            while (1) {
                // Se (j < h) interrompa;
                if (j < h) break;
                
                result.comparisons++;
                if (arr[j - h] > aux) {
                    arr[j] = arr[j - h];
                    result.swaps++; // Counting moves as swaps/operations
                    j -= h;
                } else {
                    break;
                }
            }
            arr[j] = aux;
        }
    }
    
    end = clock();
    result.executionTime = getShellSortExecutionTime(start, end);
    
    return result;
}
