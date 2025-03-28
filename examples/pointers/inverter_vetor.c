/*
  Título: Inversão de Vetor com Ponteiros
  Descrição: Programa que demonstra o uso de ponteiros para inverter a ordem dos elementos de um vetor
  Entrada: Nenhuma (valores definidos no código)
  Saída: Vetor com os elementos em ordem inversa
  Exemplo:
    Entrada:
      vetor = [1, 2, 3, 4, 5]
    Saída:
      Vetor invertido: 5 4 3 2 1
*/

#include <stdio.h>

/**
 * Inverte a ordem dos elementos de um vetor usando ponteiros
 * @param vet Ponteiro para o início do vetor
 * @param tamanho Tamanho do vetor
 */
void inverter(int *vet, int tamanho)
{
  int temp;                    // Variável temporária para troca
  int *inicio = vet;          // Ponteiro para o início do vetor
  int *fim = vet + tamanho - 1; // Ponteiro para o fim do vetor

  // Inverte os elementos até os ponteiros se encontrarem
  while (inicio < fim)
  {
    temp = *inicio;    // Armazena o valor do início
    *inicio = *fim;    // Move o valor do fim para o início
    *fim = temp;       // Move o valor temporário para o fim

    inicio++;  // Avança o ponteiro do início
    fim--;     // Recua o ponteiro do fim
  }
}

int main()
{
  int vetor[5] = {1, 2, 3, 4, 5};  // Vetor inicial

  inverter(vetor, 5);  // Inverte o vetor

  // Exibe o vetor invertido
  printf("Vetor invertido: ");
  for (int i = 0; i < 5; i++)
    printf("%d ", vetor[i]);
  printf("\n");

  return 0;
}
