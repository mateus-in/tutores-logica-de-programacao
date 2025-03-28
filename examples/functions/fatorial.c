/*
  Título: Cálculo de Fatorial
  Descrição: Programa que demonstra o uso de uma função para calcular o fatorial de um número
  Entrada: Um número inteiro positivo
  Saída: Fatorial do número informado
  Exemplo:
    Entrada:
      Digite um número: 5
    Saída:
      Fatorial de 5 é 120
    Entrada:
      Digite um número: 3
    Saída:
      Fatorial de 3 é 6
*/

#include <stdio.h>

/**
 * Calcula o fatorial de um número inteiro
 * @param n Número para calcular o fatorial
 * @return Fatorial do número informado
 */
int fatorial(int n)
{
  int fat = 1;  // Inicializa o resultado com 1

  // Calcula o fatorial multiplicando os números de 1 até n
  for (int i = 1; i <= n; i++)
    fat *= i;

  return fat;
}

int main()
{
  int num;

  printf("Digite um número: ");
  scanf("%d", &num);

  printf("Fatorial de %d é %d\n", num, fatorial(num));

  return 0;
}