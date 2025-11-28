#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "../include/file_generator.h"
#include "../include/bubble_sort.h"
#include "../include/insertion_sort.h"
#include "../include/selection_sort.h"
#include "../include/shell_sort.h"
#include "../include/sorting_algorithms.h"

// Function to clear input buffer
void clearInputBuffer() {
    int c;
    while ((c = getchar()) != '\n' && c != EOF);
}

// Function to safely read an integer
int safeReadInt() {
    int value;
    while (scanf("%d", &value) != 1) {
        printf("Entrada invalida! Digite um numero: ");
        clearInputBuffer();
    }
    clearInputBuffer(); // Clear any remaining characters
    return value;
}

void displayMainMenu() {
    printf("\n=== SISTEMA DE ORDENACAO ===\n");
    printf("1. Gerar arquivos de numeros\n");
    printf("2. Ler arquivo e ordenar com Bubble Sort\n");
    printf("3. Ler arquivo e ordenar com Insertion Sort\n");
    printf("4. Ler arquivo e ordenar com Selection Sort\n");
    printf("5. Ler arquivo e ordenar com Shell Sort\n");
    printf("6. Comparar algoritmos\n");
    printf("0. Sair\n");
    printf("Escolha uma opcao: ");
}

void displayGeneratorMenu() {
    printf("\n=== GERADOR DE ARQUIVOS ===\n");
    printf("1. Gerar arquivo ordenado\n");
    printf("2. Gerar arquivo invertido\n");
    printf("3. Gerar arquivo randomico\n");
    printf("4. Gerar todos os tipos\n");
    printf("0. Voltar ao menu principal\n");
    printf("Escolha uma opcao: ");
}

void handleFileGeneration() {
    int option, size;
    
    do {
        displayGeneratorMenu();
        option = safeReadInt();
        
        if (option >= 1 && option <= 4) {
            printf("Informe o tamanho do arquivo: ");
            size = safeReadInt();
            
            if (size <= 0) {
                printf("Tamanho invalido!\n");
                continue;
            }
            
            switch (option) {
                case 1:
                    generateOrderedFile(size);
                    break;
                case 2:
                    generateInvertedFile(size);
                    break;
                case 3:
                    generateRandomFile(size);
                    break;
                case 4:
                    generateOrderedFile(size);
                    generateInvertedFile(size);
                    generateRandomFile(size);
                    break;
            }
        } else if (option != 0) {
            printf("Opcao invalida!\n");
        }
    } while (option != 0);
}

void handleSorting(int algorithm) {
    char filename[255];
    int size;
    
    printf("Digite o nome do arquivo: ");
    fgets(filename, sizeof(filename), stdin);
    
    // Remove newline character if present
    filename[strcspn(filename, "\n")] = 0;
    
    int* arr = readFileToArray(filename, &size);
    if (arr == NULL) return;
    
    printf("Arquivo lido com %d elementos\n", size);
    printf("Primeiros elementos: ");
    printArray(arr, size);
    
    // Create copy for sorting
    int* sortArr = (int*)malloc(size * sizeof(int));
    for (int i = 0; i < size; i++) {
        sortArr[i] = arr[i];
    }
    
    if (algorithm == 1) {
        printf("\nExecutando Bubble Sort...\n");
        BubbleSortResult result = bubbleSort(sortArr, size);
        printf("Ordenacao concluida!\n");
        printf("Tempo de execucao: %.7f segundos\n", result.executionTime);
        printf("Comparacoes: %d\n", result.comparisons);
        printf("Trocas: %d\n", result.swaps);
    } else if (algorithm == 2) {
        printf("\nExecutando Insertion Sort...\n");
        InsertionSortResult result = insertionSort(sortArr, size);
        printf("Ordenacao concluida!\n");
        printf("Tempo de execucao: %.7f segundos\n", result.executionTime);
        printf("Comparacoes: %d\n", result.comparisons);
        printf("Trocas: %d\n", result.swaps);
    } else if (algorithm == 3) {
        printf("\nExecutando Selection Sort...\n");
        SelectionSortResult result = selectionSort(sortArr, size);
        printf("Ordenacao concluida!\n");
        printf("Tempo de execucao: %.7f segundos\n", result.executionTime);
        printf("Comparacoes: %d\n", result.comparisons);
        printf("Trocas: %d\n", result.swaps);
    } else if (algorithm == 4) {
        printf("\nExecutando Shell Sort...\n");
        ShellSortResult result = shellSort(sortArr, size);
        printf("Ordenacao concluida!\n");
        printf("Tempo de execucao: %.7f segundos\n", result.executionTime);
        printf("Comparacoes: %d\n", result.comparisons);
        printf("Trocas: %d\n", result.swaps);
    }
    
    printf("Primeiros elementos ordenados: ");
    printArray(sortArr, size);
    
    free(arr);
    free(sortArr);
}

void compareAlgorithms() {
    char filename[255];
    int size;
    
    printf("Digite o nome do arquivo para comparacao: ");
    fgets(filename, sizeof(filename), stdin);
    
    // Remove newline character if present
    filename[strcspn(filename, "\n")] = 0;
    
    int* arr = readFileToArray(filename, &size);
    if (arr == NULL) return;
    
    printf("Arquivo lido com %d elementos\n", size);
    printf("Primeiros elementos: ");
    printArray(arr, size);
    
    // Create copies for each sorting algorithm
    int* bubbleArr = (int*)malloc(size * sizeof(int));
    int* insertionArr = (int*)malloc(size * sizeof(int));
    int* selectionArr = (int*)malloc(size * sizeof(int));
    int* shellArr = (int*)malloc(size * sizeof(int));
    
    for (int i = 0; i < size; i++) {
        bubbleArr[i] = arr[i];
        insertionArr[i] = arr[i];
        selectionArr[i] = arr[i];
        shellArr[i] = arr[i];
    }
    
    printf("\n=== COMPARACAO DE ALGORITMOS ===\n");
    
    // Test Bubble Sort
    printf("\nTestando Bubble Sort...\n");
    BubbleSortResult bubbleResult = bubbleSort(bubbleArr, size);
    
    // Test Insertion Sort
    printf("Testando Insertion Sort...\n");
    InsertionSortResult insertionResult = insertionSort(insertionArr, size);

    // Test Selection Sort
    printf("Testando Selection Sort...\n");
    SelectionSortResult selectionResult = selectionSort(selectionArr, size);

    // Test Shell Sort
    printf("Testando Shell Sort...\n");
    ShellSortResult shellResult = shellSort(shellArr, size);
    
    // Display comparison results
    printf("\n=== RESULTADOS DA COMPARACAO ===\n");
    printf("Bubble Sort:\n");
    printf("  Tempo: %.7f s | Comp: %d | Trocas: %d\n", 
           bubbleResult.executionTime, bubbleResult.comparisons, bubbleResult.swaps);
    
    printf("Insertion Sort:\n");
    printf("  Tempo: %.7f s | Comp: %d | Trocas: %d\n", 
           insertionResult.executionTime, insertionResult.comparisons, insertionResult.swaps);

    printf("Selection Sort:\n");
    printf("  Tempo: %.7f s | Comp: %d | Trocas: %d\n", 
           selectionResult.executionTime, selectionResult.comparisons, selectionResult.swaps);

    printf("Shell Sort:\n");
    printf("  Tempo: %.7f s | Comp: %d | Trocas: %d\n", 
           shellResult.executionTime, shellResult.comparisons, shellResult.swaps);
    
    free(arr);
    free(bubbleArr);
    free(insertionArr);
    free(selectionArr);
    free(shellArr);
}

int main() {
    int option;
    
    do {
        displayMainMenu();
        option = safeReadInt();
        
        switch (option) {
            case 1:
                handleFileGeneration();
                break;
            case 2:
                handleSorting(1); // Bubble Sort
                break;
            case 3:
                handleSorting(2); // Insertion Sort
                break;
            case 4:
                handleSorting(3); // Selection Sort
                break;
            case 5:
                handleSorting(4); // Shell Sort
                break;
            case 6:
                compareAlgorithms(); // Compare algorithms
                break;
            case 0:
                printf("Saindo...\n");
                break;
            default:
                printf("Opcao invalida!\n");
        }
    } while (option != 0);
    
    return 0;
}