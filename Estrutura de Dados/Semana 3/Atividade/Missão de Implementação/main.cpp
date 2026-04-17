#include <iostream>
using namespace std;

int buscar(int v[], int n, int chave) {
    for(int i = 0; i <= n; i++) {
        if(v[i] == chave) {
            return i;
        }
    }
    return -1;
    }

    int contador(int v[], int n, int chave) {
        int qtd = 0;
        for(int i = 0; i < n; i++) {
            if(v[i] == chave) {
                qtd++;
            }
        }
        return qtd;
    }

int main() {
    int vetor;
    int chave;

    cout << "Qual o tamanho do vetor?" << endl;
    cin >> vetor;

    int lista[vetor];

    cout << "Digite os numeros: " << endl;
    for(int i = 0; i < vetor; i++){
        cin >> lista[i];
    }

    cout << "Qual numero você quer pesquisar?";
    cin >> chave;

    cout << "O numero achado foi achado na posição: " << buscar(lista, vetor, chave) << endl;
    cout << "O numero apareceu " << contador(lista, vetor, chave) << " vezes" << endl;

    return 0;
}