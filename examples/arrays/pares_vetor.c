/*
  Título: Identificação de Números Pares em um Vetor
  Descrição: Programa que lê 10 números inteiros e exibe apenas os valores pares
  Entrada: 10 números inteiros
  Saída: Os números pares encontrados no vetor
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
      Digite um número: 9
      Digite um número: 10
    Saída:
      Números pares digitados:
      2 4 6 8 10
*/

#include <stdio.h>

int main()
{
  int numeros[10];

  // Entrada de dados
  for (int i = 0; i < 10; i++)
  {
    printf("Digite um número: ");
    scanf("%d", &numeros[i]);
  }

  // Saída: Exibir apenas números pares
  printf("Números pares digitados:\n");
  for (int i = 0; i < 10; i++)
  {
    if (numeros[i] % 2 == 0)
    {
      printf("%d ", numeros[i]);
    }
  }
  printf("\n");

  return 0;
}
