/*
  Título: Conversor de Unidades de Comprimento
  Descrição: Programa que converte valores entre diferentes unidades de comprimento (quilômetros, metros, centímetros e milímetros)
  Entrada: 
    - Opção do menu (1 a 4)
    - Valor a ser convertido (para opções 1, 2 e 3)
  Saída: Valor convertido para a unidade escolhida ou mensagem de encerramento
  Exemplo:
    Entrada:
      === Conversor de Unidades de Comprimento ===
      1 - Quilometros para Metros
      2 - Metros para Centimetros
      3 - Centimetros para Milimetros
      4 - Sair
      Escolha uma opcao: 1
      Digite o valor em quilometros: 2.5
    Saída:
      2.50 km = 2500.00 m
    Entrada:
      === Conversor de Unidades de Comprimento ===
      1 - Quilometros para Metros
      2 - Metros para Centimetros
      3 - Centimetros para Milimetros
      4 - Sair
      Escolha uma opcao: 2
      Digite o valor em metros: 3.0
    Saída:
      3.00 m = 300.00 cm
*/

#include <stdio.h>

int main()
{
  int opcao;            // Opção escolhida no menu
  float valor;          // Valor a ser convertido
  float resultado;      // Resultado da conversão

  do
  {
    // Exibição do menu
    printf("\n=== Conversor de Unidades de Comprimento ===\n");
    printf("1 - Quilometros para Metros\n");
    printf("2 - Metros para Centimetros\n");
    printf("3 - Centimetros para Milimetros\n");
    printf("4 - Sair\n");
    printf("Escolha uma opcao: ");
    scanf("%d", &opcao);

    // Processamento da opção escolhida
    switch (opcao)
    {
      case 1:  // Quilômetros para Metros
        printf("Digite o valor em quilometros: ");
        scanf("%f", &valor);
        resultado = valor * 1000;  // 1 km = 1000 m
        printf("%.2f km = %.2f m\n", valor, resultado);
        break;

      case 2:  // Metros para Centímetros
        printf("Digite o valor em metros: ");
        scanf("%f", &valor);
        resultado = valor * 100;   // 1 m = 100 cm
        printf("%.2f m = %.2f cm\n", valor, resultado);
        break;

      case 3:  // Centímetros para Milímetros
        printf("Digite o valor em centimetros: ");
        scanf("%f", &valor);
        resultado = valor * 10;    // 1 cm = 10 mm
        printf("%.2f cm = %.2f mm\n", valor, resultado);
        break;

      case 4:  // Sair do programa
        printf("Encerrando o programa...\n");
        break;

      default:  // Opção inválida
        printf("Opcao invalida. Tente novamente.\n");
        break;
    }
  } while (opcao != 4);  // Continua até o usuário escolher sair

  return 0;
}