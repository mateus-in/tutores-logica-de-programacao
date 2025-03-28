/*
  Título: Soma de Números até Limite
  Descrição: Programa que soma números inteiros até que a soma atinja ou ultrapasse 100
  Entrada: Números inteiros (um por vez)
  Saída: Soma total quando atingir ou ultrapassar 100
  Exemplo:
    Entrada:
      Digite um numero: 30
      Digite um numero: 40
      Digite um numero: 35
    Saída:
      A soma chegou a 105. Encerrando.
*/

#include <stdio.h>

int main()
{
  int numero;     // Número digitado pelo usuário
  int soma = 0;   // Acumulador para a soma

  printf("Digite numeros inteiros para somar (encerra quando soma >= 100):\n");

  // Lê e soma números até atingir ou ultrapassar 100
  while (soma < 100)
  {
    printf("Digite um numero: ");
    scanf("%d", &numero);
    soma += numero;  // Adiciona o número à soma
  }

  // Exibe o resultado final
  printf("A soma chegou a %d. Encerrando.\n", soma);

  return 0;
}