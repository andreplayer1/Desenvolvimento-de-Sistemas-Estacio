#include <stdio.h>
#include <string.h>

typedef struct Aluno {
    int matricula;
    char nome[50];
    float nota1;
    float nota2;
    float media;
} Aluno;

void lerDados(Aluno turma[], int quantAlunos);
float calcularMedia(float nota1, float nota2);
void exibirAluno(Aluno a);

int main(){
    int opcao;

    do {

    Aluno turma[10];
    lerDados(turma, 3);

    for(int i = 0; i <= 2; i++) {
        turma[i].media = calcularMedia(turma[i].nota1, turma[i].nota2);
        exibirAluno(turma[i]);
    }

    printf("\n1 Reiniciar\n0 Encerrar\nEscolha uma opcao:");
    scanf("%i", &opcao);

    if( opcao == 0){
        printf("Programa encerrado!");
    }

    } while (opcao == 1);
    return 0;
}

//Missão 1 Leitura de Dados
void lerDados(Aluno turma[], int quantAlunos) {
    for(int i = 0; i < quantAlunos; i++){
        printf("Nome do Aluno: ");
        scanf(" %49[^\n]", turma[i].nome);
        
        printf("Primeira nota: ");
        scanf("%f", &turma[i].nota1);
        
        printf("Segunda nota: ");
        scanf("%f", &turma[i].nota2);

        printf("Matricula: ");
        scanf("%i", &turma[i].matricula);
        printf("============================\n");
    }
}

//Missão 2 Calculo da Média com Retorno

float calcularMedia(float nota1, float nota2) {
    float media = (nota1 + nota2) / 2.0;
    return media;
}

//Missão 3 Exibir dados do aluno

void exibirAluno(Aluno a) {
    printf("\nINFORMACOES DO ALUNO\n");
    printf("Aluno: %s\n", a.nome);
    printf("Matricula: %i\n", a.matricula);
    printf("Notas 1: %.2f \nNota2: %.2f\n", a.nota1, a.nota2);
    printf("Matricula: %i\n", a.matricula);
    printf("Media: %.2f\n", a.media);
    printf("----------------------------------------\n");
}