/*
  Título: Encontrar Maior Valor em um Vetor
  Descrição: Programa que lê 10 números inteiros, armazena-os em um vetor e encontra o maior valor
  Entrada: 10 números inteiros
  Saída: O maior valor encontrado no vetor
  Exemplo:
    Entrada:
      Digite um número: 5
      Digite um número: 2
      Digite um número: 8
      Digite um número: 1
      Digite um número: 9
      Digite um número: 3
      Digite um número: 7
      Digite um número: 4
      Digite um número: 6
      Digite um número: 0
    Saída:
      O maior número digitado foi: 9
*/

#include <stdio.h>

int main()
{
  int numeros[10], maior;

  // Entrada de dados
  for (int i = 0; i < 10; i++)
  {
    printf("Digite um número: ");
    scanf("%d", &numeros[i]);
  }

  // Processamento: encontrar o maior valor
  maior = numeros[0];
  for (int i = 1; i < 10; i++)
  {
    if (numeros[i] > maior)
    {
      maior = numeros[i];
    }
  }

  // Saída
  printf("O maior número digitado foi: %d\n", maior);

  return 0;
}