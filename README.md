# Análise de Algoritmos de Ordenação

## Descrição
Este projeto consiste em uma implementação em linguagem C de diversos algoritmos de ordenação clássicos e eficientes. O objetivo principal é fornecer uma ferramenta para gerar conjuntos de dados de teste (aleatórios, ordenados ou invertidos), executar algoritmos de ordenação individualmente e comparar o desempenho entre eles em termos de tempo de execução, número de comparações e número de trocas.

## Algoritmos Implementados

O projeto inclui a implementação dos seguintes algoritmos:

1.  **Bubble Sort**: Algoritmo simples de comparação e troca.
2.  **Insertion Sort**: Algoritmo eficiente para pequenos conjuntos de dados ou dados quase ordenados.
3.  **Selection Sort**: Algoritmo que seleciona o menor elemento repetidamente.
4.  **Shell Sort**: Uma generalização do Insertion Sort que permite trocas de itens distantes.
5.  **Quick Sort**: Algoritmo de divisão e conquista eficiente (pivô fixo).
6.  **Merge Sort**: Algoritmo de divisão e conquista estável.
7.  **Heap Sort**: Algoritmo baseado em estrutura de heap binária.
8.  **Radix Sort**: Algoritmo de ordenação não comparativo (LSD) para inteiros.

## Estrutura do Projeto

A organização dos diretórios é a seguinte:

*   **src/**: Contém os arquivos de código fonte (.c) de cada algoritmo e o programa principal.
*   **include/**: Contém os arquivos de cabeçalho (.h) com as definições de funções.
*   **output/**: Diretório destinado aos binários compilados e aos arquivos de texto gerados durante a execução.
*   **Makefile**: Script de automação para compilação do projeto.

## Requisitos

*   Compilador GCC (GNU Compiler Collection)
*   GNU Make

## Compilação

Para compilar o projeto, utilize o terminal na raiz do diretório e execute o comando:

```bash
make
Este comando irá compilar todos os arquivos fonte e gerar o executável main dentro da pasta output.
Para limpar os arquivos objetos e o executável gerado, utilize: make clean

Execução
Após a compilação, execute o programa com o seguinte comando:
./output/main

Funcionalidades
O programa apresenta um menu interativo com as seguintes opções:

Gerar arquivos: Permite criar arquivos de texto contendo números inteiros para teste.
Opções de geração: Ordenado, Invertido ou Randômico.
O usuário define o tamanho do vetor (quantidade de elementos).
Executar algoritmo específico: Permite escolher um dos 8 algoritmos para ordenar um arquivo gerado anteriormente. O programa exibirá o tempo de execução, número de comparações e trocas.
Comparar algoritmos: Executa todos os algoritmos em sequência sobre o mesmo arquivo de entrada e apresenta uma tabela comparativa de desempenho.
Observações Técnicas
Os algoritmos Quick Sort, Merge Sort, Heap Sort e Radix Sort são recomendados para grandes volumes de dados (acima de 100.000 elementos).
Algoritmos quadráticos (Bubble, Insertion, Selection) podem apresentar tempos de execução elevados para entradas grandes.
O Radix Sort é implementado especificamente para ordenação de números inteiros.

