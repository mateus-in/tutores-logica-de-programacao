/*
  Título: Leitura de Números até Zero
  Descrição: Programa que lê números inteiros continuamente até que o usuário digite zero
  Entrada: Números inteiros (um por vez)
  Saída: Cada número digitado e mensagem de encerramento
  Exemplo:
    Entrada:
      Digite numeros inteiros (0 para sair):
      5
      Voce digitou: 5
      -3
      Voce digitou: -3
      10
      Voce digitou: 10
      0
    Saída:
      Encerrando o programa.
*/

#include <stdio.h>

int main()
{
  int numero;  // Número digitado pelo usuário

  // Inicia a leitura dos números
  printf("Digite numeros inteiros (0 para sair):\n");
  scanf("%d", &numero);

  // Continua lendo enquanto não for digitado zero
  while (numero != 0)
  {
    printf("Voce digitou: %d\n", numero);
    scanf("%d", &numero);  // Lê o próximo número
  }

  // Mensagem de encerramento
  printf("Encerrando o programa.\n");

  return 0;
}