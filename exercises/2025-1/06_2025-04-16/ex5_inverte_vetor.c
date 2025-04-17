#include <stdio.h>

// Função para inverter o vetor in-place
void inverteVetor(int vet[], int tamanho) {
    int inicio = 0;
    int fim = tamanho - 1;
    int temp;

    while (inicio < fim) {
        // Troca os elementos das pontas
        temp = vet[inicio];
        vet[inicio] = vet[fim];
        vet[fim] = temp;

        // Move os índices para o centro
        inicio++;
        fim--;
    }
}

int main() {
    int n;
    int i;

    // Lê o tamanho do vetor
    scanf("%d", &n);

    int vetor[n]; // Declara o vetor após ler N (C99 ou posterior)

    // Lê os elementos do vetor
    for (i = 0; i < n; i++) {
        scanf("%d", &vetor[i]);
    }

    // Chama a função para inverter o vetor
    inverteVetor(vetor, n);

    // Imprime o vetor invertido
    for (i = 0; i < n; i++) {
        printf("%d", vetor[i]);
        if (i < n - 1) {
            printf(" "); // Adiciona espaço entre os elementos
        }
    }
    printf("\n");

    return 0;
} 