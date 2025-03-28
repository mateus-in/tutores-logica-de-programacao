/*
  Título: Verificação de Número Par ou Ímpar
  Descrição: Programa que verifica se um número inteiro é par ou ímpar
  Entrada: Um número inteiro
  Saída: Mensagem indicando se o número é par ou ímpar
  Exemplo:
    Entrada:
      Digite um numero inteiro: 7
    Saída:
      O numero 7 eh impar.
*/

#include <stdio.h>

int main()
{
  int numero;  // Número digitado pelo usuário

  // Solicita e lê o número
  printf("Digite um numero inteiro: ");
  scanf("%d", &numero);

  // Verifica se o número é par ou ímpar
  if (numero % 2 == 0)
  {
    printf("O numero %d eh par.\n", numero);
  }
  else
  {
    printf("O numero %d eh impar.\n", numero);
  }

  return 0;
}