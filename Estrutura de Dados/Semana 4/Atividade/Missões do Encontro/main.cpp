#include <iostream>
#include <string>
#include <iomanip>
using namespace std;

//1- Crie uma matrix 3x3 de inteiros e exiba a soma de todos os seus elementos.
int m[3][3];

void soma(){
    int sum = 0;

    cout << "Digite as notas dos alunos: "<< endl;
    
    for(int i = 0; i < 3; i++){
        for(int j = 0; j < 3; j++){
            cin >> m[i][j];
            sum += m[i][j];
        }
    }

    cout <<"A soma e: " << sum << endl;
}

//2- Modifique o codigo para somar e exibir apenas o elementos da diagonal principal.
void diagonal(){
    int sum = 0;

    cout << "Digite as notas dos alunos: "<< endl;
    
    for(int i = 0; i < 3; i++){
        for(int j = 0; j < 3; j++){
            cin >> m[i][j];
            if(i == j){
                sum += m[i][j];
            }
        }
    }

    cout <<"A soma dos numeros na diagonal e: "<< sum << endl;
    }

//3- Vasculhe a matriz e encontre o maior valor inserido pelo usuario.
void maior_valor(){
    cout << "Digite as notas dos alunos: "<< endl;
    
    for(int i = 0; i < 3; i++){
        for(int j = 0; j < 3; j++){
            cin >> m[i][j];
        }
    }

    int maior = m[0][0];

    for(int i = 0; i < 3; i++){
        for(int j = 0; j < 3; j++){
            if(m[i][j] > maior){
                maior = m[i][j];
            }
        }
    }

    cout << "A maior nota foi: "<< maior << endl;
}

//4- Implemente o caso de notas [alunos][provas] e calcule a media de cada aluno.
void boletim(){
    cout << "Digite as notas dos alunos: "<< endl;
    
    for(int i = 0; i < 3; i++){
        for(int j = 0; j < 3; j++){
            cin >> m[i][j];
        }
    }

//Calcula a média.
    for(int i = 0; i < 3; i++){

        int soma_aluno = 0;

        for(int j = 0; j < 3; j++){
            soma_aluno +=  m[i][j];
        }

        float media = soma_aluno / 3.0;
        cout << "A media do aluno foi: "<< fixed << setprecision(2)<< media << endl;
    }
}

int main() {
int opcao = 0;
do{
    cout << "ESCOLHA UMA OPCAO" << endl;
    cout << " 1 - SOMA" << endl;
    cout << " 2 - SOMA NA DIAGONAL" << endl;
    cout << " 3 - MAIOR VALOR" << endl;
    cout << " 4 - MEDIA OS ALUNOS" << endl;
    cout << "-1 - SAIR" << endl;

    cin >> opcao;

    switch (opcao) {
        case 1:
            soma();
            break;

        case 2:
            diagonal();
            break;

        case 3:
            maior_valor();
            break;

        case 4:
            boletim();
            break;

        default:
            cout << "ENCERRANDO PROGRAMA..." << endl;
    }
} while (opcao != -1);

    return 0;
}