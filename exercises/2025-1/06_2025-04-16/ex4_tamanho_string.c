#include <stdio.h>

#define MAX_STR 51 // 50 caracteres + \0

int main() {
    char str[MAX_STR];
    int tamanho = 0;

    // Lê a string (fgets é mais seguro que scanf para strings)
    // Lê até MAX_STR - 1 caracteres ou até encontrar newline
    if (fgets(str, MAX_STR, stdin) != NULL) {
        // Remove o newline no final, se existir
        // (fgets inclui o newline se houver espaço)
        int i = 0;
        while (str[i] != '\0' && str[i] != '\n') {
            i++;
        }
        if (str[i] == '\n') {
            str[i] = '\0'; // Substitui newline por fim de string
        }

        // Calcula o tamanho manualmente
        tamanho = 0;
        while (str[tamanho] != '\0') {
            tamanho++;
        }
    }

    // Imprime o tamanho
    printf("%d\n", tamanho);

    return 0;
} 