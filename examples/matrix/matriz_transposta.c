/*
  Título: Matriz Transposta
  Descrição: Programa que lê uma matriz 3x3 e exibe sua matriz transposta (troca linhas por colunas)
  Entrada: 9 números inteiros (matriz 3x3)
  Saída: A matriz transposta (onde as linhas se tornam colunas e vice-versa)
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
      Matriz Transposta:
      1 4 7
      2 5 8
      3 6 9
*/

#include <stdio.h>

int main()
{
  int matriz[3][3], transposta[3][3];

  // Entrada de dados
  for (int i = 0; i < 3; i++)
  {
    for (int j = 0; j < 3; j++)
    {
      printf("Digite um número para posição [%d][%d]: ", i, j);
      scanf("%d", &matriz[i][j]);
    }
  }

  // Gerando a matriz transposta
  for (int i = 0; i < 3; i++)
  {
    for (int j = 0; j < 3; j++)
    {
      transposta[j][i] = matriz[i][j]; // Inverte os índices
    }
  }

  // Exibindo a matriz transposta
  printf("Matriz Transposta:\n");
  for (int i = 0; i < 3; i++)
  {
    for (int j = 0; j < 3; j++)
    {
      printf("%d ", transposta[i][j]);
    }
    printf("\n");
  }

  return 0;
}
