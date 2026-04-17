#include <iostream>
#include <string>
#include <iomanip>
using namespace std;

struct Produto {
    int codigo;
    string nome;
    float preco;
};

int main() {
    Produto inventario[5];

    for(int i = 0; i < 5; i++){
        cout << "Codigo: ";
        cin >> inventario[i].codigo;
        cin.ignore();

        cout << "Nome: ";
        getline(cin, inventario[i].nome);

        cout << "Preco: ";
        cin >> inventario[i].preco;
    }

    int produto_mais_caro = 0;

    for(int i = 0; i < 5; i++){
        if(inventario[i].preco > inventario[produto_mais_caro].preco){
            produto_mais_caro = i;
        }
    }

    cout << "\nPRODUTO MAIS CARO" << endl;
    cout << "Codigo: " << inventario[produto_mais_caro].codigo << endl;
    cout << "Nome: " << inventario[produto_mais_caro].nome << endl;
    cout << "Preco: R$ " << fixed << setprecision(2) << inventario[produto_mais_caro].preco << endl;

    return 0;
}