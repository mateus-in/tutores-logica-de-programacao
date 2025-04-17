#include <stdio.h>
#include <ctype.h> // Para usar isupper, islower, isdigit

int main() {
    char caractere;

    // Lê o caractere
    scanf("%c", &caractere);

    // Verifica e classifica o caractere
    if (isupper(caractere)) {
        printf("MAIUSCULA\n");
    } else if (islower(caractere)) {
        printf("MINUSCULA\n");
    } else if (isdigit(caractere)) {
        printf("DIGITO\n");
    } else {
        printf("OUTRO\n");
    }

    return 0;
} 