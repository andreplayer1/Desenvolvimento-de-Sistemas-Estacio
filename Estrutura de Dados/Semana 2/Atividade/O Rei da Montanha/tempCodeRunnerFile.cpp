#include <iostream>
using namespace std;

int main() {
    int numeros [10];

    for(int i= 0; i <= 9; i++) {
        cin >> numeros[i];
    }

        cout << "Numeros Invertidos:" << endl;

    for(int i= 9; i>= 0; i--) {
        cout << numeros[i] << endl;
    }

    return 0;
}