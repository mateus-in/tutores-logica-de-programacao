/*
  Título: Tamanho de uma String
  Descrição: Programa que lê uma palavra e exibe seu tamanho (número de caracteres)
  Entrada: Uma palavra (string)
  Saída: O número de caracteres na palavra
  Exemplo:
    Entrada:
      Digite uma palavra: Python
    Saída:
      Tamanho da string: 6 caracteres
*/

#include <stdio.h>
#include <string.h>

int main()
{
  char palavra[100];  // Array para armazenar até 99 caracteres + \0

  printf("Digite uma palavra: ");
  fgets(palavra, sizeof(palavra), stdin);

  // Remove o '\n' inserido pelo fgets()
  palavra[strcspn(palavra, "\n")] = '\0';

  printf("Tamanho da string: %lu caracteres\n", strlen(palavra));

  return 0;
}