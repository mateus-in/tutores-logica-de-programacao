/*
  Título: Comparação de Strings
  Descrição: Programa que compara duas palavras ignorando maiúsculas e minúsculas
  Entrada: Duas palavras (strings)
  Saída: Mensagem indicando se as palavras são iguais ou diferentes
  Exemplo:
    Entrada:
      Digite a primeira palavra: Python
      Digite a segunda palavra: python
    Saída:
      As palavras são iguais.
*/

#include <stdio.h>
#include <string.h>
#include <ctype.h>

// Função que converte uma string para minúsculas
void toLowerCase(char *str)
{
  while (*str)
  {
    *str = tolower(*str);
    str++;
  }
}

int main()
{
  char str1[100];  // Array para primeira palavra (até 99 caracteres + \0)
  char str2[100];  // Array para segunda palavra (até 99 caracteres + \0)

  printf("Digite a primeira palavra: ");
  scanf("%s", str1);
  printf("Digite a segunda palavra: ");
  scanf("%s", str2);

  // Converte ambas as strings para minúsculas antes de comparar
  toLowerCase(str1);
  toLowerCase(str2);

  // Compara as strings já convertidas para minúsculas
  if (strcmp(str1, str2) == 0)
  {
    printf("As palavras são iguais.\n");
  }
  else
  {
    printf("As palavras são diferentes.\n");
  }

  return 0;
}
