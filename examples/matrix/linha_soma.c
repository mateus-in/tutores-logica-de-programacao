/*
  Título: Soma das Linhas de uma Matriz
  Descrição: Programa que lê uma matriz 3x3 e calcula a soma dos elementos de cada linha
  Entrada: 9 números inteiros (matriz 3x3)
  Saída: A soma dos elementos de cada linha da matriz
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
      Soma da linha 0: 6
      Soma da linha 1: 15
      Soma da linha 2: 24
*/

#include <stdio.h>

int main()
{
  int matriz[3][3], soma;

  // Entrada de dados
  for (int i = 0; i < 3; i++)
  {
    for (int j = 0; j < 3; j++)
    {
      printf("Digite um número para posição [%d][%d]: ", i, j);
      scanf("%d", &matriz[i][j]);
    }
  }

  // Processamento e saída
  for (int i = 0; i < 3; i++)
  {
    soma = 0;
    for (int j = 0; j < 3; j++)
    {
      soma += matriz[i][j];
    }
    printf("Soma da linha %d: %d\n", i, soma);
  }

  return 0;
}
