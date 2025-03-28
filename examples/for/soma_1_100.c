/*
  Título: Soma dos Números de 1 a 100
  Descrição: Programa que calcula a soma de todos os números inteiros de 1 até 100
  Entrada: Nenhuma
  Saída: Resultado da soma dos números de 1 a 100
  Exemplo:
    Saída:
      A soma dos numeros de 1 a 100 eh: 5050
  Nota: O resultado é sempre 5050, pois é a soma de uma progressão aritmética
        de 1 até 100, que pode ser calculada pela fórmula: (n * (n + 1)) / 2,
        onde n = 100
*/

#include <stdio.h>

int main()
{
  int i;          // Contador do laço
  int soma = 0;   // Acumulador para a soma

  // Soma os números de 1 a 100
  for (i = 1; i <= 100; i++)
  {
    soma += i;  // Adiciona o número atual à soma
  }

  // Exibe o resultado
  printf("A soma dos numeros de 1 a 100 eh: %d\n", soma);

  return 0;
}