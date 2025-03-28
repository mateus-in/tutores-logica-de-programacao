/*
  Título: Inversão de Elementos de um Vetor
  Descrição: Programa que lê 8 números inteiros e os exibe na ordem inversa
  Entrada: 8 números inteiros
  Saída: Os números na ordem inversa da entrada
  Exemplo:
    Entrada:
      Digite um número: 1
      Digite um número: 2
      Digite um número: 3
      Digite um número: 4
      Digite um número: 5
      Digite um número: 6
      Digite um número: 7
      Digite um número: 8
    Saída:
      Números na ordem inversa:
      8 7 6 5 4 3 2 1
*/

#include <stdio.h>

int main()
{
  int numeros[8];

  // Entrada de dados
  for (int i = 0; i < 8; i++)
  {
    printf("Digite um número: ");
    scanf("%d", &numeros[i]);
  }

  // Saída: imprimir ao contrário
  printf("Números na ordem inversa:\n");
  for (int i = 7; i >= 0; i--)
  {
    printf("%d ", numeros[i]);
  }
  printf("\n");

  return 0;
}
