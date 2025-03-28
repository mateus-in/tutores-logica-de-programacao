/*
  Título: Triângulo de Asteriscos
  Descrição: Programa que desenha um triângulo isósceles formado por asteriscos
  Entrada: Número de linhas do triângulo (N)
  Saída: Triângulo de asteriscos com N linhas
  Exemplo:
    Entrada:
      Digite o numero de linhas do triangulo: 5
    Saída:
        *
       ***
      *****
     *******
    *********
    Entrada:
      Digite o numero de linhas do triangulo: 3
    Saída:
      *
     ***
    *****
*/

#include <stdio.h>

int main()
{
  int N;           // Número de linhas do triângulo
  int i;           // Contador para as linhas
  int j;           // Contador para espaços e asteriscos
  int espacos;     // Quantidade de espaços em cada linha
  int asteriscos;  // Quantidade de asteriscos em cada linha

  // Leitura do número de linhas
  printf("Digite o numero de linhas do triangulo: ");
  scanf("%d", &N);

  // Construção do triângulo
  for (i = 1; i <= N; i++)
  {
    // Calcula a quantidade de espaços e asteriscos para a linha atual
    espacos = N - i;           // Espaços diminuem a cada linha
    asteriscos = (2 * i) - 1;  // Asteriscos aumentam em quantidade ímpar

    // Imprime os espaços antes dos asteriscos
    for (j = 0; j < espacos; j++)
    {
      printf(" ");
    }

    // Imprime os asteriscos da linha atual
    for (j = 0; j < asteriscos; j++)
    {
      printf("*");
    }

    // Quebra de linha após cada linha do triângulo
    printf("\n");
  }

  return 0;
}