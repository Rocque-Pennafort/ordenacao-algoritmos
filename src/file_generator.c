#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include "../include/file_generator.h"

void generateOrderedFile(int size) {
    FILE *file;
    char filename[255];
    
    sprintf(filename, "Ordenado%05d.txt", size);
    file = fopen(filename, "w");
    
    if (file == NULL) {
        printf("Erro ao criar arquivo %s\n", filename);
        return;
    }
    
    for (int i = 1; i <= size; i++) {
        fprintf(file, "%d\n", i);
    }
    
    fclose(file);
    printf("Arquivo %s criado com sucesso!\n", filename);
}

void generateInvertedFile(int size) {
    FILE *file;
    char filename[255];
    
    sprintf(filename, "Invertido%05d.txt", size);
    file = fopen(filename, "w");
    
    if (file == NULL) {
        printf("Erro ao criar arquivo %s\n", filename);
        return;
    }
    
    for (int i = size; i >= 1; i--) {
        fprintf(file, "%d\n", i);
    }
    
    fclose(file);
    printf("Arquivo %s criado com sucesso!\n", filename);
}

void generateRandomFile(int size) {
    FILE *file;
    char filename[255];
    
    sprintf(filename, "Randomico%05d.txt", size);
    file = fopen(filename, "w");
    
    if (file == NULL) {
        printf("Erro ao criar arquivo %s\n", filename);
        return;
    }
    
    srand(time(NULL));
    
    for (int i = 0; i < size; i++) {
        fprintf(file, "%d\n", rand() % (size * 10) + 1);
    }
    
    fclose(file);
    printf("Arquivo %s criado com sucesso!\n", filename);
}