/*
  Título: Soma Simples
  Descrição: Programa que demonstra o uso de uma função para somar dois números inteiros
  Entrada: Nenhuma (valores definidos no código)
  Saída: Resultado da soma dos dois números
  Exemplo:
    Entrada:
      a = 10
      b = 15
    Saída:
      A soma é 25
*/

#include <stdio.h>

/**
 * Calcula a soma de dois números inteiros
 * @param a Primeiro número
 * @param b Segundo número
 * @return Soma dos dois números
 */
int soma(int a, int b)
{
  return a + b;
}

int main()
{
  int resultado = soma(10, 15);
  printf("A soma é %d\n", resultado);
  return 0;
}
