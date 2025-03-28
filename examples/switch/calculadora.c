/*
  Título: Calculadora Simples
  Descrição: Programa que realiza operações básicas de matemática (soma, subtração, multiplicação e divisão)
  Entrada: 
    - Opção da operação (1 a 4)
    - Dois números para realizar o cálculo
  Saída: Resultado da operação escolhida ou mensagem de erro
  Exemplo:
    Entrada:
      Calculadora Simples:
      1 - Soma
      2 - Subtracao
      3 - Multiplicacao
      4 - Divisao
      Escolha uma opcao: 1
      Digite dois numeros: 10.5 4.5
    Saída:
      Resultado da soma: 15.00
    Entrada:
      Calculadora Simples:
      1 - Soma
      2 - Subtracao
      3 - Multiplicacao
      4 - Divisao
      Escolha uma opcao: 4
      Digite dois numeros: 10.0 0.0
    Saída:
      Erro: divisao por zero nao permitida.
*/

#include <stdio.h>

int main()
{
  int opcao;            // Opção da operação escolhida
  float num1, num2;     // Números para o cálculo
  float resultado;      // Resultado da operação

  // Exibição do menu
  printf("Calculadora Simples:\n");
  printf("1 - Soma\n");
  printf("2 - Subtracao\n");
  printf("3 - Multiplicacao\n");
  printf("4 - Divisao\n");
  printf("Escolha uma opcao: ");
  scanf("%d", &opcao);

  // Processamento da operação escolhida
  switch (opcao)
  {
    case 1:  // Soma
      printf("Digite dois numeros: ");
      scanf("%f %f", &num1, &num2);
      resultado = num1 + num2;
      printf("Resultado da soma: %.2f\n", resultado);
      break;

    case 2:  // Subtração
      printf("Digite dois numeros: ");
      scanf("%f %f", &num1, &num2);
      resultado = num1 - num2;
      printf("Resultado da subtracao: %.2f\n", resultado);
      break;

    case 3:  // Multiplicação
      printf("Digite dois numeros: ");
      scanf("%f %f", &num1, &num2);
      resultado = num1 * num2;
      printf("Resultado da multiplicacao: %.2f\n", resultado);
      break;

    case 4:  // Divisão
      printf("Digite dois numeros: ");
      scanf("%f %f", &num1, &num2);
      if (num2 == 0)  // Verifica divisão por zero
      {
        printf("Erro: divisao por zero nao permitida.\n");
      }
      else
      {
        resultado = num1 / num2;
        printf("Resultado da divisao: %.2f\n", resultado);
      }
      break;

    default:  // Opção inválida
      printf("Opcao invalida.\n");
      break;
  }

  return 0;
}