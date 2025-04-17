#include <stdio.h>

#define TAMANHO 5

int main() {
    int vetor[TAMANHO];
    int x;
    int contagem = 0;
    int i;

    // Lê os 5 números para o vetor
    for (i = 0; i < TAMANHO; i++) {
        scanf("%d", &vetor[i]);
    }

    // Lê o número X
    scanf("%d", &x);

    // Conta quantas vezes X aparece no vetor
    for (i = 0; i < TAMANHO; i++) {
        if (vetor[i] == x) {
            contagem++;
        }
    }

    // Imprime a contagem
    printf("%d\n", contagem);

    return 0;
} 