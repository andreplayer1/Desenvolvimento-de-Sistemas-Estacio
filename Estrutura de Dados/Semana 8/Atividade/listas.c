#include <stdio.h>
#define TAM_MAX 10

struct Lista {
    int dados[TAM_MAX];
    int tamanho;
};

void inicializarLista(struct Lista *l){
    l-> tamanho = 0;
}

void inserir(struct Lista *l, int valor){
    if(l-> tamanho < TAM_MAX){
        l-> dados[l-> tamanho] = valor;

        l-> tamanho ++;
    } else {
        printf("Erro: Lista cheia!\n");
    }
}

void remover(struct Lista *l){
    if(l-> tamanho > 0){
        l-> tamanho --;
    } else {
        printf("Erro: Lista vazia!\n");
    }
}

void listar(struct Lista *l){
    printf("\n--- ESTADO ATUAL DA LISTA ---\n");
    printf("Ocupacao: %d de %d capacidade.\n", l->tamanho, TAM_MAX);
    printf("Dados: [ ");
    for(int i = 0; i < l->tamanho; i++){
        printf("%d ", l->dados[i]);
    }
    printf("]\n-----------------------------\n");
}

int main(){
    struct Lista minhaLista;
    inicializarLista(&minhaLista);

    int opcao, valor;

do{
    printf("\n1-Inserir\n2-Remover\n3-Listar\n0-Sair\nOpcao: ");
    scanf("%d", &opcao);

    switch(opcao){
        case 1:
        printf("Valor: ");
        scanf("%d", &valor);
        inserir(&minhaLista, valor);
        break;

        case 2:
        remover(&minhaLista);
        break;

        case 3:
        listar(&minhaLista);
        break;

        default:
        printf("Opcao Invalida!\n");
    }
} while(opcao != 0);

return 0;
}