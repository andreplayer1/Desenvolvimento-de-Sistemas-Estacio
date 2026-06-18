#ifndef LISTA_H
#define LISTA_H

#define MAX_CLIENTES 100

// Estrutura Cliente
typedef struct {
    int codigo;
    char nome[50];
    char telefone[20];
} Cliente;

// Estrutura Lista
typedef struct {
    Cliente clientes[MAX_CLIENTES];
    int tamanho;
} ListaClientes;

// Assinaturas das funções (Contrato)
void inicializarLista(ListaClientes *lista);
int inserirCliente(ListaClientes *lista, Cliente novo);
int removerCliente(ListaClientes *lista, int indice);
int buscarCliente(ListaClientes *lista, int codigo);
void listarClientes(ListaClientes *lista);

#endif