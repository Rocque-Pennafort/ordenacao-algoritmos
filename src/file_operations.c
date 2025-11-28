#include <stdio.h>
#include <stdlib.h>
#include "../include/sorting_algorithms.h"

int* readFileToArray(const char* filename, int* size) {
    FILE *file = fopen(filename, "r");
    if (file == NULL) {
        printf("Erro ao abrir arquivo %s\n", filename);
        return NULL;
    }
    
    // Count lines to determine array size
    int count = 0;
    int temp;
    while (fscanf(file, "%d", &temp) == 1) {
        count++;
    }
    
    // Allocate memory for array
    int* arr = (int*)malloc(count * sizeof(int));
    if (arr == NULL) {
        printf("Erro ao alocar memoria\n");
        fclose(file);
        return NULL;
    }
    
    // Reset file pointer and read data
    rewind(file);
    for (int i = 0; i < count; i++) {
        fscanf(file, "%d", &arr[i]);
    }
    
    *size = count;
    fclose(file);
    return arr;
}

void printArray(int arr[], int size) {
    printf("Array: ");
    int limit = size > 20 ? 20 : size; // Print only first 20 elements
    
    for (int i = 0; i < limit; i++) {
        printf("%d ", arr[i]);
    }
    
    if (size > 20) {
        printf("... (showing first 20 of %d elements)", size);
    }
    printf("\n");
}