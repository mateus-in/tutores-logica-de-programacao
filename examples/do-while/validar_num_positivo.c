/*
  Título: Validação de Número Positivo
  Descrição: Programa que solicita ao usuário um número inteiro positivo, 
             repetindo a solicitação até que um valor válido seja fornecido
  Entrada: Números inteiros (repetidamente até que seja positivo)
  Saída: Número positivo válido digitado
  Exemplo:
    Entrada:
      Digite um numero inteiro positivo: -5
      Valor invalido, tente novamente.
      Digite um numero inteiro positivo: 0
      Valor invalido, tente novamente.
      Digite um numero inteiro positivo: 10
    Saída:
      Voce digitou: 10
*/

#include <stdio.h>

int main()
{
  int numero;  // Número digitado pelo usuário

  // Solicita um número positivo até que seja válido
  do
  {
    printf("Digite um numero inteiro positivo: ");
    scanf("%d", &numero);

    if (numero <= 0)
    {
      printf("Valor invalido, tente novamente.\n");
    }
  } while (numero <= 0);

  // Exibe o número válido digitado
  printf("Voce digitou: %d\n", numero);

  return 0;
}