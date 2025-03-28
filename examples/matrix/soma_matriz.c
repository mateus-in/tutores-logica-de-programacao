/*
  Título: Soma dos Elementos de uma Matriz
  Descrição: Programa que lê uma matriz 3x3 e calcula a soma de todos os seus elementos
  Entrada: 9 números inteiros (matriz 3x3)
  Saída: 
    - A matriz digitada
    - A soma de todos os elementos
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
      Matriz digitada:
      1 2 3
      4 5 6
      7 8 9
      Soma de todos os elementos: 45
*/

#include <stdio.h>

int main()
{
  int matriz[3][3], soma = 0;

  // Entrada de dados
  for (int i = 0; i < 3; i++)
  {
    for (int j = 0; j < 3; j++)
    {
      printf("Digite um número para posição [%d][%d]: ", i, j);
      scanf("%d", &matriz[i][j]);
      soma += matriz[i][j];
    }
  }

  // Saída
  printf("Matriz digitada:\n");
  for (int i = 0; i < 3; i++)
  {
    for (int j = 0; j < 3; j++)
    {
      printf("%d ", matriz[i][j]);
    }
    printf("\n");
  }

  printf("Soma de todos os elementos: %d\n", soma);

  return 0;
}
