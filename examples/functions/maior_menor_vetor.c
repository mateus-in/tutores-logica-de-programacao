/*
  Título: Maior e Menor Valor em Vetor
  Descrição: Programa que demonstra o uso de funções para encontrar o maior e o menor valor em um vetor
  Entrada: Nenhuma (valores definidos no código)
  Saída: Maior e menor valor encontrados no vetor
  Exemplo:
    Entrada:
      vetor = [7, 2, 5, 9, 4]
    Saída:
      Maior número: 9
      Menor número: 2
*/

#include <stdio.h>

/**
 * Encontra o maior valor em um vetor de inteiros
 * @param v Vetor de números inteiros
 * @param tam Tamanho do vetor
 * @return Maior valor encontrado
 */
int maior(int v[], int tam)
{
  int maior = v[0];  // Inicializa com o primeiro elemento

  for (int i = 1; i < tam; i++)
    if (v[i] > maior)
      maior = v[i];

  return maior;
}

/**
 * Encontra o menor valor em um vetor de inteiros
 * @param v Vetor de números inteiros
 * @param tam Tamanho do vetor
 * @return Menor valor encontrado
 */
int menor(int v[], int tam)
{
  int menor = v[0];  // Inicializa com o primeiro elemento

  for (int i = 1; i < tam; i++)
    if (v[i] < menor)
      menor = v[i];

  return menor;
}

int main()
{
  int numeros[5] = {7, 2, 5, 9, 4};  // Vetor com 5 números

  printf("Maior número: %d\n", maior(numeros, 5));
  printf("Menor número: %d\n", menor(numeros, 5));

  return 0;
}
