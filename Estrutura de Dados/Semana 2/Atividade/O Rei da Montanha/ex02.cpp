#include <iostream>
using namespace std;

int main() {
    int numeros[10];
    
    for(int i = 0; i <= 9; i++ ){
        cout << "Digite um numero: "<< endl;
        cin >> numeros[i];
    }
    int maior = numeros[0];
    int menor = numeros[0];

    for(int i = 9; i >= 0; i--){
        cout << numeros[i]<<"-";
    }

    for(int i = 0; i <= 9; i++){
        if(numeros[i] > maior){
            maior = numeros[i];
        }
        if(numeros[i] < menor){
            menor = numeros[i];
        }
    }
    cout << "O numero maior e: " << maior << endl;
    cout << "O numero menor e: " << menor << endl;
   return 0;
};