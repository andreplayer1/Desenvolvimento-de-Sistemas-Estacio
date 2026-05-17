#include <stdio.h>
#include <string.h>

/**
 * DISCIPLINA: TEC0790 – Estruturas de Dados
 * SEMANA 9: TAD Lista Sequencial - Inserções e Remoções Internas
 */

#define TAM_MAX 10

// 1. DEFINIÇÃO DA ENTIDADE E DO TAD (Slide 6)
typedef struct {
    int codigo;
    char descricao[13];
    float preco;
} Produto;

typedef struct {
    Produto itens[TAM_MAX];
    int tamanho;
} Lista;

// 2. FUNÇÕES DO TAD (Slide 7)

void inicializar(Lista *l) {
    l->tamanho = 0;
}

// Lógica de Inserção com Deslocamento à Direita (Slide 3)
int inserir_pos(Lista *l, int pos, Produto p) {
    if (l->tamanho == TAM_MAX) return 0; // Lista cheia
    if (pos < 0 || pos > l->tamanho) return 0; // Posição inválida

    // DESLOCAMENTO: Começa do fim para não sobrescrever os dados
    for (int i = l->tamanho; i > pos; i--) {
        l->itens[i] = l->itens[i - 1];
    }

    l->itens[pos] = p;
    l->tamanho++;
    return 1;
}

// Lógica de Remoção com Deslocamento à Esquerda (Slide 4)
int remover_pos(Lista *l, int pos) {
    if (l->tamanho == 0) return 0; // Lista vazia
    if (pos < 0 || pos >= l->tamanho) return 0; // Posição inválida

    // DESLOCAMENTO: Traz os elementos da direita para a esquerda
    for (int i = pos; i < l->tamanho - 1; i++) {
        l->itens[i] = l->itens[i + 1];
    }

    l->tamanho--;
    return 1;
}

void imprimir(Lista l) {
    printf("\n--- LISTA DE PRODUTOS (Tam: %d) ---\n", l.tamanho);
    for (int i = 0; i < l.tamanho; i++) {
        printf("[%d] Cod: %d | %-15s | R$ %.2f\n", 
               i, l.itens[i].codigo, l.itens[i].descricao, l.itens[i].preco);
    }
}

int main() {
    Lista cadastro;
    Produto p1 = {10, "Teclado", 150.0}, p2 = {20, "Mouse", 80.0}, p3 = {30, "Monitor", 900.0};
    
    inicializar(&cadastro);

    // Demonstração de inserções em diferentes posições
    inserir_pos(&cadastro, 0, p1); // Insere no início
    inserir_pos(&cadastro, 1, p2); // Insere no fim atual
    inserir_pos(&cadastro, 1, p3); // Insere no meio (desloca o Mouse)

    imprimir(cadastro);

    // 3. ATIVIDADE VERIFICADORA (Slide 10)
    int pos_rem;
    printf("\nDigite uma posicao para remover (0 a %d): ", cadastro.tamanho - 1);
    scanf("%d", &pos_rem);

    if (remover_pos(&cadastro, pos_rem)) {
        printf("Remocao realizada com sucesso!\n");
    } else {
        printf("Erro: Posicao invalida ou lista vazia.\n");
    }

    imprimir(cadastro);

    return 0;
}