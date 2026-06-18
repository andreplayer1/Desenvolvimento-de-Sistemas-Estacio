#include <stdio.h>
#include "lista.h"

int main() {
    ListaClientes lista;

    inicializarLista(&lista);

    Cliente c1 = { 101, "Maria Silva", "11999999999" };
    Cliente c2 = { 102, "Joao Souza", "11888888888" };
    Cliente c3 = { 103, "Ana Costa", "11777777777" };

    printf("=== TESTE DE INSERCAO ===\n");
    if(inserirCliente(&lista, c1)) printf("Cliente Maria Silva inserido.\n");
    if(inserirCliente(&lista, c2)) printf("Cliente Joao Souza inserido.\n");
    if(inserirCliente(&lista, c3)) printf("Cliente Ana Costa inserido.\n");

    printf("\nTotal de clientes: %d\n\n", lista.tamanho);

    printf("=== LISTA DE CLIENTES ===\n");
    listarClientes(&lista);

    printf("\n=== TESTE DE BUSCA ===\n");
    int posicao = buscarCliente(&lista, 102);
    if(posicao != -1) {
        printf("Cliente encontrado na posicao %d.\n", posicao);
    } else {
        printf("Cliente nao encontrado.\n");
    }

    printf("\n=== TESTE DE BUSCA INEXISTENTE ===\n");
    posicao = buscarCliente(&lista, 999);
    if(posicao == -1) {
        printf("Cliente de codigo 999 nao encontrado.\n");
    }

    printf("\n=== TESTE DE REMOCAO ===\n");
    if(removerCliente(&lista, 1)) {
        printf("Cliente removido com sucesso.\n");
    }

    printf("\n=== LISTA APOS REMOCAO ===\n");
    listarClientes(&lista);

    printf("\n=== TESTE DE INDICE INVALIDO ===\n");
    if(!removerCliente(&lista, 10)) {
        printf("Erro: indice invalido.\n");
    }

    printf("\nPrograma finalizado com sucesso.\n");

    return 0;
}