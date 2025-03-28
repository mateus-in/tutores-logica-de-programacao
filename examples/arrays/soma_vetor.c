/*
  Título: Soma de Elementos de um Vetor
  Descrição: Programa que lê 5 números inteiros, armazena-os em um vetor e calcula a soma de todos os elementos
  Entrada: 5 números inteiros
  Saída: A soma de todos os elementos do vetor
  Exemplo:
    Entrada:
      Digite um número: 1
      Digite um número: 2
      Digite um número: 3
      Digite um número: 4
      Digite um número: 5
    Saída:
      Soma dos números: 15
*/

#include <stdio.h>

int main()
{
  int numeros[5], soma = 0;

  // Entrada de dados
  for (int i = 0; i < 5; i++)
  {
    printf("Digite um número: ");
    scanf("%d", &numeros[i]);
  }

  // Processamento: soma dos valores
  for (int i = 0; i < 5; i++)
  {
    soma += numeros[i];
  }

  // Saída
  printf("Soma dos números: %d\n", soma);

  return 0;
}
