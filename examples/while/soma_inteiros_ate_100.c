/*
  Título: Soma de Números até 100
  Descrição: Programa que soma números inteiros até atingir ou ultrapassar 100
  Entrada: Números inteiros (um por vez)
  Saída: Soma total quando atingir ou ultrapassar 100
  Exemplo:
    Entrada:
      Digite um numero inteiro: 30
      Digite um numero inteiro: 25
      Digite um numero inteiro: 20
      Digite um numero inteiro: 40
    Saída:
      A soma atingiu ou ultrapassou 100. Valor acumulado: 115
    Entrada:
      Digite um numero inteiro: 50
      Digite um numero inteiro: 60
    Saída:
      A soma atingiu ou ultrapassou 100. Valor acumulado: 110
*/

#include <stdio.h>

int main()
{
  int numero;     // Número digitado pelo usuário
  int soma = 0;   // Acumulador para a soma

  // Soma números até atingir ou ultrapassar 100
  while (soma < 100)
  {
    printf("Digite um numero inteiro: ");
    scanf("%d", &numero);
    soma += numero;  // Adiciona o número à soma
  }

  // Exibe o resultado final
  printf("A soma atingiu ou ultrapassou 100. Valor acumulado: %d\n", soma);

  return 0;
}