/*
  Título: Elementos da Diagonal Principal
  Descrição: Programa que lê uma matriz 3x3 e exibe os elementos da diagonal principal
  Entrada: 9 números inteiros (matriz 3x3)
  Saída: Os elementos da diagonal principal da matriz
  Exemplo:
    Entrada:
      Digite um número para posição [0][0]: 1
      Digite um número para posição [0][1]: 2
      Digite um número para posição [0][2]: 3
      Digite um número para posição [1][0]: 4
      Digite um número para posição [1][1]: 5
      Digite um número para posição [1][2]: 6
      Digite um número para posição [2][0]: 7
      Digite um número para posição [2][1]: 8
      Digite um número para posição [2][2]: 9
    Saída:
      Diagonal principal:
      1 5 9
*/

#include <stdio.h>

int main()
{
  int matriz[3][3];

  // Entrada de dados
  for (int i = 0; i < 3; i++)
  {
    for (int j = 0; j < 3; j++)
    {
      printf("Digite um número para posição [%d][%d]: ", i, j);
      scanf("%d", &matriz[i][j]);
    }
  }

  // Saída: Exibir diagonal principal
  printf("Diagonal principal:\n");
  for (int i = 0; i < 3; i++)
  {
    printf("%d ", matriz[i][i]);
  }
  printf("\n");

  return 0;
}
