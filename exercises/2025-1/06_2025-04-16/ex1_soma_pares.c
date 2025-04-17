#include <stdio.h>

int main() {
    int n;
    int numero;
    int soma_pares = 0;
    int i;

    // Lê o número N
    scanf("%d", &n);

    // Lê N números e soma os pares
    for (i = 0; i < n; i++) {
        scanf("%d", &numero);
        if (numero % 2 == 0) {
            soma_pares += numero;
        }
    }

    // Imprime a soma dos pares
    printf("%d\n", soma_pares);

    return 0;
} 