#include <stdio.h>

// Função que deveria dar o desconto
void aplicarDesconto(float *preco) {
    *preco = *preco - 15.0;
}

int main() {
    float precoMouse = 50.0;
    printf("Preco original: %.2f\n", precoMouse);
    
    // Chamando a função do estagiário
    aplicarDesconto(&precoMouse);
    
    // Verificando se o desconto funcionou
    printf("Preco na Black Friday: %.2f\n", precoMouse);
    
    return 0;
}