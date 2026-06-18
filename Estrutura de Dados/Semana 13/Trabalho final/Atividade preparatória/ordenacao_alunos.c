#include <stdio.h>
#include <string.h>

//Definição da Estrutura (aumentamos o char de 5 para 10 para caber "Daniel")
typedef struct {
    int matricula;
    char nome[10]; 
    float nota;
} Aluno;

// Função auxiliar para imprimir a turma toda
void imprimirTurma(Aluno turma[], int n) {
    for (int i = 0; i < n; i++) {
        printf("  [Mat: %d | Nome: %-6s | Nota: %.1f]\n", 
               turma[i].matricula, turma[i].nome, turma[i].nota);
    }
    printf("-------------------------------------------------\n");
}

// Implementação do Selection Sort adaptado para Structs
void selectionSortAlunos(Aluno v[], int n) {
    int i, j, min_idx;
    Aluno aux; // A mágica acontece aqui: aux agora é uma struct inteira!

    for (i = 0; i < n - 1; i++) {
        min_idx = i;
        
        // Assume que a matrícula atual é a menor
        for (j = i + 1; j < n; j++) {
            // Comparamos APENAS o campo matricula
            if (v[j].matricula < v[min_idx].matricula) {
                min_idx = j;
            }
        }
        
        // Realiza a troca (swap) da struct inteira de uma vez
        if (min_idx != i) {
            aux = v[i];
            v[i] = v[min_idx];
            v[min_idx] = aux;
        }
        
        printf("Passo %d da Ordenacao por Matricula:\n", i + 1);
        imprimirTurma(v, n);
    }
}

int main() {
    // Vetor de struct previamente definido pelo professor
    Aluno turma[4] = {
        {104, "Ana", 8.5},
        {103, "Beto", 7.0},
        {102, "Carla", 9.5},
        {101, "Daniel", 6.5}
    };
    int tamanho = 4;

    printf("--- Turma Inicial (Desordenada) ---\n");
    imprimirTurma(turma, tamanho);

    // Chamando a nossa ordenação adaptada
    selectionSortAlunos(turma, tamanho);

    printf("Ordenacao concluida com sucesso!\n");

    return 0;
}