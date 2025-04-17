#include <stdio.h>
#include <ctype.h> // Para usar isspace
#include <stdbool.h> // Para usar bool, true, false

#define MAX_FRASE 201 // 200 caracteres + \0

int main() {
    char frase[MAX_FRASE];
    int contagem_palavras = 0;
    bool dentro_palavra = false; // Estado: estamos dentro de uma palavra?
    int i = 0;

    // Lê a linha de texto
    if (fgets(frase, MAX_FRASE, stdin) != NULL) {
        // Percorre a string caractere por caractere
        while (frase[i] != '\0' && frase[i] != '\n') {
            if (isspace(frase[i])) {
                // Se encontrou espaço, está fora de uma palavra
                dentro_palavra = false;
            } else {
                // Se encontrou um não-espaço...
                if (!dentro_palavra) {
                    // ...e estava fora de uma palavra antes, então começa uma nova palavra
                    contagem_palavras++;
                    dentro_palavra = true; // Agora está dentro de uma palavra
                }
                // Se já estava dentro de uma palavra, continua nela, não faz nada.
            }
            i++;
        }
    }

    // Imprime a contagem de palavras
    printf("%d\n", contagem_palavras);

    return 0;
} 