/*
  Título: Verificação de Número Primo
  Descrição: Programa que demonstra o uso de uma função para verificar se um número é primo
  Entrada: Um número inteiro positivo
  Saída: Mensagem indicando se o número é primo ou não
  Exemplo:
    Entrada:
      Digite um número: 17
    Saída:
      17 é primo.
    Entrada:
      Digite um número: 12
    Saída:
      12 não é primo.
*/

#include <stdio.h>

/**
 * Verifica se um número é primo
 * @param num Número a ser verificado
 * @return 1 se o número é primo, 0 caso contrário
 */
int primo(int num)
{
  // Números menores que 2 não são primos
  if (num < 2)
    return 0;

  // Verifica divisibilidade até a raiz quadrada do número
  for (int i = 2; i < num; i++)
    if (num % i == 0)
      return 0;

  return 1;
}

int main()
{
  int numero;

  printf("Digite um número: ");
  scanf("%d", &numero);

  if (primo(numero))
    printf("%d é primo.\n", numero);
  else
    printf("%d não é primo.\n", numero);

  return 0;
}