/*
  Título: Leitura de Números até Zero
  Descrição: Programa que lê números inteiros continuamente até que o usuário digite zero,
             garantindo pelo menos uma leitura usando do-while
  Entrada: Números inteiros (um por vez)
  Saída: Cada número digitado e mensagem de encerramento
  Exemplo:
    Entrada:
      Digite um numero inteiro (0 para sair): 5
      Voce digitou: 5
      Digite um numero inteiro (0 para sair): -3
      Voce digitou: -3
      Digite um numero inteiro (0 para sair): 0
    Saída:
      Encerrando programa.
*/

#include <stdio.h>

int main()
{
  int numero;  // Número digitado pelo usuário

  // Lê números até que seja digitado zero
  do
  {
    printf("Digite um numero inteiro (0 para sair): ");
    scanf("%d", &numero);

    if (numero != 0)
    {
      printf("Voce digitou: %d\n", numero);
    }
  } while (numero != 0);

  // Mensagem de encerramento
  printf("Encerrando programa.\n");

  return 0;
}
