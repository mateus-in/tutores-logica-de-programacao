/*
  Título: Exibir Números de 1 até N
  Descrição: Programa que exibe todos os números inteiros de 1 até N, usando while
  Entrada: Um número inteiro positivo N
  Saída: Números de 1 até N ou mensagem de erro
  Exemplo:
    Entrada:
      Digite um numero inteiro: 5
    Saída:
      1
      2
      3
      4
      5
    Entrada:
      Digite um numero inteiro: 0
    Saída:
      Valor invalido.
*/

#include <stdio.h>

int main()
{
  int N;        // Número limite para exibição
  int i = 1;    // Contador do laço

  // Leitura do número limite
  printf("Digite um numero inteiro: ");
  scanf("%d", &N);

  // Validação da entrada
  if (N <= 0)
  {
    printf("Valor invalido.\n");
  }
  else
  {
    // Exibe os números de 1 até N
    while (i <= N)
    {
      printf("%d\n", i);
      i++;  // Incrementa o contador
    }
  }

  return 0;
}