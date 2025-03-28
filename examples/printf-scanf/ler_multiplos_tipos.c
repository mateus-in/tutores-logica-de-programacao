/*
  Título: Leitura de Múltiplos Tipos de Dados
  Descrição: Programa que demonstra o uso de scanf para leitura de diferentes tipos de dados
  Entrada: 
    - Um número inteiro
    - Um número real (float)
    - Um caractere
  Saída: Os valores lidos são exibidos em uma única linha, separados por |
  Exemplo:
    Entrada:
      Digite um numero inteiro: 10
      Digite um numero real: 5.50
      Digite um caractere: A
    Saída:
      Numero inteiro: 10 | Numero real: 5.50 | Caractere: A
*/

#include <stdio.h>

int main()
{
  int inteiro;
  float real;
  char caractere;

  printf("Digite um numero inteiro: ");
  scanf("%d", &inteiro);

  printf("Digite um numero real: ");
  scanf("%f", &real);

  printf("Digite um caractere: ");
  scanf(" %c", &caractere);
  // Note o espaco antes de %c para ignorar o caractere de nova linha pendente.

  printf("Numero inteiro: %d | Numero real: %.2f | Caractere: %c\n",
         inteiro, real, caractere);

  return 0;
}