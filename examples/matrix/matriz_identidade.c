/*
  Título: Matriz Identidade
  Descrição: Programa que gera e exibe uma matriz identidade 4x4
  Entrada: Nenhuma (a matriz é gerada automaticamente)
  Saída: Uma matriz identidade 4x4 (diagonal principal com 1, demais elementos com 0)
  Exemplo:
    Saída:
      Matriz Identidade 4x4:
      1 0 0 0
      0 1 0 0
      0 0 1 0
      0 0 0 1
*/

#include <stdio.h>

int main()
{
  int matriz[4][4];

  // Construção da matriz identidade
  for (int i = 0; i < 4; i++)
  {
    for (int j = 0; j < 4; j++)
    {
      if (i == j)
      {
        matriz[i][j] = 1; // Diagonal principal recebe 1
      }
      else
      {
        matriz[i][j] = 0; // Demais posições recebem 0
      }
    }
  }

  // Exibindo a matriz identidade
  printf("Matriz Identidade 4x4:\n");
  for (int i = 0; i < 4; i++)
  {
    for (int j = 0; j < 4; j++)
    {
      printf("%d ", matriz[i][j]);
    }
    printf("\n");
  }

  return 0;
}
