/*
  Título: Soma de Valores com Parada
  Descrição: Programa que permite ao usuário somar vários números,
             perguntando após cada entrada se deseja continuar
  Entrada: Números reais e resposta S/N para continuar
  Saída: Soma total dos números digitados
  Exemplo:
    Entrada:
      Digite um numero: 5.5
      Deseja adicionar outro numero? (S/N): S
      Digite um numero: 3.2
      Deseja adicionar outro numero? (S/N): S
      Digite um numero: 1.8
      Deseja adicionar outro numero? (S/N): N
    Saída:
      Soma total: 10.50
*/

#include <stdio.h>

int main()
{
  float numero;     // Número digitado pelo usuário
  float soma = 0.0f; // Acumulador para a soma
  char resposta;     // Resposta do usuário para continuar

  // Lê e soma números até que o usuário decida parar
  do
  {
    printf("Digite um numero: ");
    scanf("%f", &numero);
    soma += numero;  // Adiciona o número à soma

    printf("Deseja adicionar outro numero? (S/N): ");
    scanf(" %c", &resposta); // Espaço antes de %c para ignorar enter
  } while (resposta == 'S' || resposta == 's');

  // Exibe o resultado final
  printf("Soma total: %.2f\n", soma);

  return 0;
}