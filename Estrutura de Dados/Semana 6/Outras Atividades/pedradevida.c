#include <stdio.h>

// A função mágica que altera duas coisas ao mesmo tempo usando ponteiros
void usarPedraDeVida(int *vida, int *raiva) {
    *vida = *vida + 50;
    *raiva = *raiva - 20;
}

int main() {
    // As gavetas originais na memória do jogo
    int vidaKratos = 30;
    int raivaKratos = 80;

    printf("Antes da Pedra: Vida %d | Raiva %d\n", vidaKratos, raivaKratos);
    
    // DESAFIO: Como você chama a função aqui enviando os endereços corretos?
    // ESCREVA ESTA LINHA:
    usarPedraDeVida(&vidaKratos, &raivaKratos);

    printf("Depois da Pedra: Vida %d | Raiva %d\n", vidaKratos, raivaKratos);
    
    return 0;
}