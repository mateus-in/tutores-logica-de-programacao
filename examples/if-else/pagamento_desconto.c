/*
  Título: Cálculo de Pagamento com Desconto
  Descrição: Programa que calcula o valor final de um produto com desconto baseado na forma de pagamento
  Entrada: 
    - Forma de pagamento (1 para a vista, 2 para cartão)
  Saída: Valor final a ser pago (com desconto de 10% para pagamento a vista)
  Exemplo:
    Entrada:
      Forma de pagamento:
      1 - A vista (dinheiro/PIX)
      2 - Cartao
      Escolha: 1
    Saída:
      Valor final: R$90.00
    Entrada:
      Forma de pagamento:
      1 - A vista (dinheiro/PIX)
      2 - Cartao
      Escolha: 2
    Saída:
      Valor final: R$100.00
*/

#include <stdio.h>

int main()
{
  float precoBase = 100.0;  // Preço base do produto
  float valorFinal;         // Valor final após desconto
  int formaPagamento;      // Forma de pagamento escolhida

  // Apresentação das opções de pagamento
  printf("Forma de pagamento:\n");
  printf("1 - A vista (dinheiro/PIX)\n");
  printf("2 - Cartao\n");
  printf("Escolha: ");
  scanf("%d", &formaPagamento);

  // Cálculo do valor final baseado na forma de pagamento
  if (formaPagamento == 1)
  {
    valorFinal = precoBase - (precoBase * 0.10);  // 10% de desconto para pagamento a vista
    printf("Valor final: R$%.2f\n", valorFinal);
  }
  else if (formaPagamento == 2)
  {
    valorFinal = precoBase;  // Sem desconto para pagamento no cartão
    printf("Valor final: R$%.2f\n", valorFinal);
  }
  else
  {
    printf("Opcao invalida.\n");
  }

  return 0;
}