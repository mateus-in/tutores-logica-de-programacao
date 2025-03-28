/*
  Título: Leitura de Número Inteiro
  Descrição: Programa que demonstra o uso básico de scanf para leitura de números inteiros
  Entrada: Um número inteiro digitado pelo usuário
  Saída: O número digitado é exibido na tela
  Exemplo:
    Entrada:
      Digite um numero inteiro: 42
    Saída:
      Voce digitou: 42
*/

#include <stdio.h>

int main()
{
  int numero;

  printf("Digite um numero inteiro: ");
  scanf("%d", &numero); // Lê um número inteiro e armazena em "numero"

  printf("Voce digitou: %d\n", numero); // Exibe o valor armazenado

  return 0;
}