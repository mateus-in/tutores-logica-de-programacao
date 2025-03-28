/*
  Título: Números Ímpares de 1 a 99
  Descrição: Programa que exibe todos os números ímpares de 1 até 99
  Entrada: Nenhuma
  Saída: Lista de números ímpares, um por linha
  Exemplo:
    Saída:
      1
      3
      5
      ...
      97
      99
*/

#include <stdio.h>

int main()
{
  int i;  // Contador do loop

  // Exibe os números ímpares de 1 a 99
  for (i = 1; i <= 99; i += 2)
  {
    printf("%d\n", i);
  }

  return 0;
}