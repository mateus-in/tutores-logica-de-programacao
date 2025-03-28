/*
  Título: Operações Básicas com Números Reais
  Descrição: Programa que demonstra operações aritméticas básicas com números reais
  Entrada: Dois números reais (float)
  Saída: 
    - Soma dos números
    - Subtração dos números
    - Multiplicação dos números
    - Divisão dos números (se o segundo número não for zero)
  Exemplo:
    Entrada:
      Digite dois valores reais (ex: 3.2 4.5): 3.2 4.5
    Saída:
      Soma: 7.70
      Subtracao: -1.30
      Multiplicacao: 14.40
      Divisao: 0.71
*/

#include <stdio.h>

int main()
{
  float num1, num2;

  printf("Digite dois valores reais (ex: 3.2 4.5): ");
  scanf("%f %f", &num1, &num2); // Lê dois valores float

  printf("Soma: %.2f\n", (num1 + num2));
  printf("Subtracao: %.2f\n", (num1 - num2));
  printf("Multiplicacao: %.2f\n", (num1 * num2));

  if (num2 != 0)
  {
    printf("Divisao: %.2f\n", (num1 / num2));
  }
  else
  {
    printf("Divisao: nao e possivel dividir por zero.\n");
  }

  return 0;
}