/*
  Título: Tabuada
  Descrição: Programa que gera a tabuada de multiplicação de um número inteiro (de 1 a 10)
  Entrada: Um número inteiro
  Saída: Tabuada de multiplicação do número (de 1 a 10)
  Exemplo:
    Entrada:
      Digite um numero inteiro para gerar a tabuada: 5
    Saída:
      5 x 1 = 5
      5 x 2 = 10
      5 x 3 = 15
      5 x 4 = 20
      5 x 5 = 25
      5 x 6 = 30
      5 x 7 = 35
      5 x 8 = 40
      5 x 9 = 45
      5 x 10 = 50
*/

#include <stdio.h>

int main()
{
  int num;  // Número para gerar a tabuada
  int i;    // Contador do laço

  // Leitura do número
  printf("Digite um numero inteiro para gerar a tabuada: ");
  scanf("%d", &num);

  // Geração da tabuada
  for (i = 1; i <= 10; i++)
  {
    printf("%d x %d = %d\n", num, i, num * i);
  }

  return 0;
}