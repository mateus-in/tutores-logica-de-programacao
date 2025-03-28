/*
  Título: Inversão de String
  Descrição: Programa que lê uma palavra e a exibe invertida (da direita para a esquerda)
  Entrada: Uma palavra (string)
  Saída: A palavra invertida
  Exemplo:
    Entrada:
      Digite uma palavra: Python
    Saída:
      String invertida: nohtyP
*/

#include <stdio.h>
#include <string.h>

int main()
{
  char palavra[100];  // Array para armazenar até 99 caracteres + \0

  printf("Digite uma palavra: ");
  scanf("%s", palavra);

  // Inverte a string
  int tamanho = strlen(palavra);
  printf("String invertida: ");
  for (int i = tamanho - 1; i >= 0; i--)
  {
    printf("%c", palavra[i]);
  }
  printf("\n");

  return 0;
}
