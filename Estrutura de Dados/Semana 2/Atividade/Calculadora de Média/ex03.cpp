#include <iostream>
using namespace std;

int main() {
    float nota[3];
    float soma = 0;

    for(int i = 0; i <= 2; i++ ){
        cout << "Digite uma nota: "<< endl;
        cin >> nota[i];

        soma = soma + nota[i];
    }
        cout << "A Media e :" << soma / 3<< endl;
    return 0;
}