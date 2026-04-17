#include <stdio.h>
void dobrar(int*p);
void oApontador();

typedef struct Aluno {
    int matricula;
    char nome[50];
    float nota;
} Aluno;

int main(){
    //Missão 1
    int x = 10;
    int *p = &x;
    printf("Valor: %d Endereco: %p\n", x, p );

    //Missão 2
    dobrar(p);
    printf("Valor Dobrado: %d \n", x);

    oApontador();
    
    return 0;
}

//Função da Missão 3
void oApontador() {
    Aluno aluno1; // Declarando struct
    Aluno *pa; //Apontador
    
    pa = &aluno1; //Endereço
    
    printf("Digite o nome: ");
    scanf("%s", pa->nome);
    
    printf("Digite a nota: ");
    scanf("%f", &pa->nota);
    
    printf("Digite a matricula: ");
    scanf("%i", &pa->matricula);
    
    
    printf("Nome do Aluno: %s\n", pa->nome);
    printf("Nota do Aluno: %f\n", pa->nota);
    printf("Matricula: %i\n", pa->matricula);
    
}

//Função da Missão 2
void dobrar(int *p){
    *p = (*p) * 2;
}