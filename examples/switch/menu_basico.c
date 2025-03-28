/*
  Título: Menu de Operações Básicas
  Descrição: Programa que exibe um menu com operações básicas (soma e subtração) e permite ao usuário escolher a operação desejada
  Entrada: 
    - Opção do menu (1, 2 ou 3)
    - Dois números (para opções 1 e 2)
  Saída: Resultado da operação escolhida ou mensagem de encerramento
  Exemplo:
    Entrada:
      Menu de Operacoes:
      1 - Soma
      2 - Subtracao
      3 - Finalizar
      Escolha uma opcao: 1
      Digite dois numeros: 5.5 3.2
    Saída:
      Resultado da soma: 8.70
    Entrada:
      Menu de Operacoes:
      1 - Soma
      2 - Subtracao
      3 - Finalizar
      Escolha uma opcao: 2
      Digite dois numeros: 10.0 4.5
    Saída:
      Resultado da subtracao: 5.50
    Entrada:
      Menu de Operacoes:
      1 - Soma
      2 - Subtracao
      3 - Finalizar
      Escolha uma opcao: 3
    Saída:
      Encerrando o programa...
*/

#include <stdio.h>

int main()
{
  int opcao;           // Opção escolhida no menu
  float num1, num2;    // Números para as operações
  float resultado;     // Resultado da operação

  // Exibição do menu
  printf("Menu de Operacoes:\n");
  printf("1 - Soma\n");
  printf("2 - Subtracao\n");
  printf("3 - Finalizar\n");
  printf("Escolha uma opcao: ");
  scanf("%d", &opcao);

  // Processamento da opção escolhida
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

    case 3:  // Encerrar
      printf("Encerrando o programa...\n");
      break;

    default:  // Opção inválida
      printf("Opcao invalida.\n");
      break;
  }

  return 0;
}