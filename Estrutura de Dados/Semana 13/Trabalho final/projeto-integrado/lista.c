#include <stdio.h>
#include "lista.h"

// Inicializa a lista
void inicializarLista(ListaClientes *lista) {
    lista->tamanho = 0;
    printf("Lista inicializada com sucesso!\n\n");
}

// Insere cliente (com trava de segurança para o máximo de clientes)
int inserirCliente(ListaClientes *lista, Cliente novo) {
    if(lista->tamanho >= MAX_CLIENTES) {
        return 0;
    }
    lista->clientes[lista->tamanho] = novo;
    lista->tamanho++;
    return 1;
}

// Remove cliente por índice aplicando o deslocamento (Shift)
int removerCliente(ListaClientes *lista, int indice) {
    int i;
    if(indice < 0 || indice >= lista->tamanho) {
        return 0;
    }
    for(i = indice; i < lista->tamanho - 1; i++) {
        lista->clientes[i] = lista->clientes[i + 1];
    }
    lista->tamanho--;
    return 1;
}

// Busca cliente pelo código de forma iterativa
int buscarCliente(ListaClientes *lista, int codigo) {
    int i;
    for(i = 0; i < lista->tamanho; i++) {
        if(lista->clientes[i].codigo == codigo) {
            return i;
        }
    }
    return -1;
}

// Exibe todos os clientes navegando até o Tamanho Lógico
void listarClientes(ListaClientes *lista) {
    int i;
    if(lista->tamanho == 0) {
        printf("A lista esta vazia.\n");
        return;
    }
    for(i = 0; i < lista->tamanho; i++) {
        printf("\nCliente %d\n", i + 1);
        printf("Codigo: %d\n", lista->clientes[i].codigo);
        printf("Nome: %s\n", lista->clientes[i].nome);
        printf("Telefone: %s\n", lista->clientes[i].telefone);
        printf("---------------------------\n");
    }
}