/*
  Título: Cálculo de Imposto de Renda
  Descrição: Programa que calcula o imposto de renda baseado no salário mensal, seguindo uma tabela simplificada
  Entrada: 
    - Salário mensal (valor real)
  Saída: Valor do imposto de renda a pagar
  Exemplo:
    Entrada:
      Digite o salario: 1500.00
    Saída:
      Imposto devido: R$0.00
    Entrada:
      Digite o salario: 2500.00
    Saída:
      Imposto devido: R$50.00
    Entrada:
      Digite o salario: 4000.00
    Saída:
      Imposto devido: R$250.00
*/

#include <stdio.h>

int main()
{
  float salario;      // Salário mensal
  float imposto = 0.0f;  // Valor do imposto a pagar
  float faixa10;      // Valor da faixa com 10% de imposto
  float faixa20;      // Valor da faixa com 20% de imposto

  // Leitura do salário
  printf("Digite o salario: ");
  scanf("%f", &salario);

  // Cálculo do imposto baseado nas faixas
  if (salario <= 2000.0f)  // Faixa isenta
  {
    imposto = 0.0f;
  }
  else if (salario <= 3500.0f)  // Faixa de 10%
  {
    // Aplica 10% somente na parte que excede 2000
    imposto = (salario - 2000.0f) * 0.10f;
  }
  else  // Faixa de 10% + 20%
  {
    // Faixa entre 2000 e 3500 (10%)
    faixa10 = 1500.0f;  // (3500 - 2000)
    // Excedente acima de 3500 (20%)
    faixa20 = salario - 3500.0f;

    imposto = (faixa10 * 0.10f) + (faixa20 * 0.20f);
  }

  printf("Imposto devido: R$%.2f\n", imposto);

  return 0;
}