#include <iostream>
#include <string>
#include <iomanip>
#include <locale.h>

using namespace std;

int main() {
    setlocale(LC_ALL, "pt_BR.UTF-8");
    
    string nome;
    int idade;
    double nota;

    cout << "Digite seu nome: ";
    getline(cin, nome);
    cout << "Digite sua idade: ";
    cin >> idade;
    cout << "Digite sua nota: ";
    cin >> nota;

    cout << "Nome do Aluno: " << nome << endl;
    cout << "Idade: " << idade << endl;
    cout << fixed << setprecision(2) << "Nota: " << nota << endl;

    if (nota >= 6)
    {
        cout << "Parabéns, " << nome << " você foi aprovado!";
    }
    else if (nota >= 4)
    {
        cout << "Você está na AVR, estude mais para passar!";
    }
    else
    {
        cout << "Você está reprovado direto!";
    }

    return 0;
}