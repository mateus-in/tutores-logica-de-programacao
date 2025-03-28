/*
  Título: Números de 1 a 10
  Descrição: Programa que exibe os números de 1 a 10 em sequência, utilizando o laço for
  Entrada: Nenhuma
  Saída: Números de 1 a 10, um por linha
  Exemplo:
    Saída:
      1
      2
      3
      4
      5
      6
      7
      8
      9
      10
*/

#include <stdio.h>

int main()
{
  int i;  // Contador do laço

  // Exibe os números de 1 a 10
  for (i = 1; i <= 10; i++)
  {
    printf("%d\n", i);
  }

  return 0;
}
