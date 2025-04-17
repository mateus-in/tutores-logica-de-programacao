#include <stdio.h>

#define MAX_DIM 50

int main() {
    int m, n;
    int matriz[MAX_DIM][MAX_DIM];
    int transposta[MAX_DIM][MAX_DIM];
    int i, j;

    // Lê as dimensões da matriz
    scanf("%d %d", &m, &n);

    // Lê os elementos da matriz original
    for (i = 0; i < m; i++) {
        for (j = 0; j < n; j++) {
            scanf("%d", &matriz[i][j]);
        }
    }

    // Calcula a matriz transposta
    for (i = 0; i < m; i++) {
        for (j = 0; j < n; j++) {
            transposta[j][i] = matriz[i][j];
        }
    }

    // Imprime a matriz transposta (dimensões N x M)
    for (i = 0; i < n; i++) {
        for (j = 0; j < m; j++) {
            printf("%d", transposta[i][j]);
            if (j < m - 1) {
                printf(" "); // Adiciona espaço entre os elementos da linha
            }
        }
        printf("\n"); // Nova linha após cada linha da transposta
    }

    return 0;
} 