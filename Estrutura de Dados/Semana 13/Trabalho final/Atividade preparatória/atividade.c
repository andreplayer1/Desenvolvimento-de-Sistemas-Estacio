#include <stdio.h>

// Função auxiliar
void imprimir(int v[], int n) {
    printf("[ ");
    for (int i = 0; i < n; i++) {
        printf("%d ", v[i]);
    }
    printf("]\n");
}

// Implementação do Selection Sort
void selectionSort(int v[], int n) {
    int i, j, min_idx, aux;
    for (i = 0; i < n - 1; i++) {
        min_idx = i;
        // Assume que o elemento atual é o menor
        for (j = i + 1; j < n; j++) {
            if (v[j] < v[min_idx]) min_idx = j;
            // Busca o índice do menor real
        }
        // Realiza a troca (swap) do menor encontrado com a posição i
        aux = v[i];
        v[i] = v[min_idx];
        v[min_idx] = aux;
        printf("Selection - Passo %d: ", i + 1); 
        imprimir(v, n);
    }
}

// Implementação do Insertion Sort
void insertionSort(int v[], int n) {
    int i, j, aux;
    for (i = 1; i < n; i++) {
        aux = v[i];
        // Elemento a ser inserido na parte ordenada
        j = i - 1;
        // Desloca elementos maiores para a direita para "abrir espaço"
        while (j >= 0 && v[j] > aux) {
            v[j + 1] = v[j];
            j--;
        }
        v[j + 1] = aux;
        // Insere o elemento na posição correta
        printf("Insertion - Passo %d: ", i);
        imprimir(v, n);
    }
}

// Implementação do Bubble Sort
void bubbleSort(int v[], int n) {
    int i, j, aux;
    // Laço externo: controla o número de passagens pelo vetor (n-1 passagens)
    for (i = 0; i < n - 1; i++) {
        // Laço interno: percorre o vetor comparando pares adjacentes
        for (j = 0; j < n - 1 - i; j++) {
            // Realiza a troca se os elementos estiverem na ordem errada ("bolha" sobe)
            if (v[j] > v[j + 1]) {
                aux = v[j];
                v[j] = v[j + 1];
                v[j + 1] = aux;
            }
        }
        // Exibe o estado do vetor após cada passagem externa para visualizar o processo
        printf("Bubble - Passo %d: ", i + 1);
        imprimir(v, n);
    }
}

int main() {
    // Vetor inicial do Exercício 1
    int v[5] = {25, 10, 40, 5, 20};
    int tamanho = 5;

    printf("--- Testando Bubble Sort ---\n");
    printf("Vetor Inicial: ");
    imprimir(v, tamanho);
    printf("\n");
    
    // Vamos chamar apenas o Bubble Sort primeiro para analisar
    insertionSort(v, tamanho);
    
    return 0;
}