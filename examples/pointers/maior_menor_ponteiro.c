/*
  Título: Maior e Menor Valor com Ponteiros
  Descrição: Programa que demonstra o uso de ponteiros para encontrar o maior e o menor valor em um vetor
  Entrada: Nenhuma (valores definidos no código)
  Saída: Maior e menor valor encontrados no vetor
  Exemplo:
    Entrada:
      vetor = [4, 1, 9, 5, 7]
    Saída:
      Maior valor: 9
      Menor valor: 1
*/

#include <stdio.h>

/**
 * Encontra o maior e o menor valor em um vetor usando ponteiros
 * @param vet Ponteiro para o início do vetor
 * @param tamanho Tamanho do vetor
 * @param maior Ponteiro para armazenar o maior valor
 * @param menor Ponteiro para armazenar o menor valor
 */
void maiorEMenor(int *vet, int tamanho, int *maior, int *menor)
{
  *maior = *menor = vet[0];  // Inicializa com o primeiro elemento

  // Percorre o vetor para encontrar maior e menor valores
  for (int i = 1; i < tamanho; i++)
  {
    if (vet[i] > *maior)
      *maior = vet[i];  // Atualiza o maior valor
    if (vet[i] < *menor)
      *menor = vet[i];  // Atualiza o menor valor
  }
}

int main()
{
  int vetor[5] = {4, 1, 9, 5, 7};  // Vetor inicial
  int maior, menor;                 // Variáveis para armazenar os resultados

  maiorEMenor(vetor, 5, &maior, &menor);  // Chama a função passando os endereços

  // Exibe os resultados
  printf("Maior valor: %d\n", maior);
  printf("Menor valor: %d\n", menor);

  return 0;
}
