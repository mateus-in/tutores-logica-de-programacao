/*
  Título: Verificação de Sinal
  Descrição: Programa que verifica se um número é positivo, negativo ou zero
  Entrada: Um número inteiro
  Saída: Mensagem indicando se o número é positivo, negativo ou zero
  Exemplo:
    Entrada:
      Digite um numero inteiro: 42
    Saída:
      O numero 42 e positivo.
    Entrada:
      Digite um numero inteiro: -15
    Saída:
      O numero -15 e negativo.
    Entrada:
      Digite um numero inteiro: 0
    Saída:
      O numero e zero.
*/

#include <stdio.h>

int main()
{
  int numero;  // Variável para armazenar o número

  // Leitura do número
  printf("Digite um numero inteiro: ");
  scanf("%d", &numero);

  // Verificação do sinal do número
  if (numero > 0)
  {
    printf("O numero %d e positivo.\n", numero);
  }
  else if (numero < 0)
  {
    printf("O numero %d e negativo.\n", numero);
  }
  else
  {
    printf("O numero e zero.\n");
  }

  return 0;
}