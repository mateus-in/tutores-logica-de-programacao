/*
  Título: Soma de Vetor com Ponteiros
  Descrição: Programa que demonstra o uso de ponteiros para calcular a soma dos elementos de um vetor
  Entrada: Cinco números inteiros
  Saída: Soma dos elementos do vetor
  Exemplo:
    Entrada:
      Digite 5 números: 1 2 3 4 5
    Saída:
      Soma do vetor: 15
*/

#include <stdio.h>

/**
 * Calcula a soma dos elementos de um vetor usando ponteiros
 * @param vetor Ponteiro para o início do vetor
 * @param tamanho Tamanho do vetor
 * @return Soma dos elementos do vetor
 */
int somarVetor(int *vetor, int tamanho)
{
  int soma = 0;  // Inicializa a soma

  // Percorre o vetor usando aritmética de ponteiros
  for (int i = 0; i < tamanho; i++)
    soma += *(vetor + i);  // Acessa o elemento usando deslocamento

  return soma;
}

int main()
{
  int numeros[5];  // Vetor para armazenar os números

  // Leitura dos números
  printf("Digite 5 números: ");
  for (int i = 0; i < 5; i++)
    scanf("%d", &numeros[i]);

  // Calcula e exibe a soma
  int soma = somarVetor(numeros, 5);
  printf("Soma do vetor: %d\n", soma);

  return 0;
}
