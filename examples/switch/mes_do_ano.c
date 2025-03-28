/*
  Título: Mês do Ano e Quantidade de Dias
  Descrição: Programa que converte um número de 1 a 12 no mês correspondente e mostra quantos dias tem o mês
  Entrada: Um número inteiro entre 1 e 12
  Saída: Nome do mês e quantidade de dias ou mensagem de erro
  Exemplo:
    Entrada:
      Digite um numero (1 a 12) para o mes do ano: 1
    Saída:
      Mes: Janeiro - 31 dias
    Entrada:
      Digite um numero (1 a 12) para o mes do ano: 2
    Saída:
      Mes: Fevereiro - 28 dias (ano nao bissexto)
    Entrada:
      Digite um numero (1 a 12) para o mes do ano: 13
    Saída:
      Mes invalido.
*/

#include <stdio.h>

int main()
{
  int mes;  // Número do mês (1-12)

  // Leitura do número do mês
  printf("Digite um numero (1 a 12) para o mes do ano: ");
  scanf("%d", &mes);

  // Conversão do número para o nome do mês e quantidade de dias
  switch (mes)
  {
    case 1:  // Janeiro
      printf("Mes: Janeiro - 31 dias\n");
      break;

    case 2:  // Fevereiro
      printf("Mes: Fevereiro - 28 dias (ano nao bissexto)\n");
      break;

    case 3:  // Março
      printf("Mes: Marco - 31 dias\n");
      break;

    case 4:  // Abril
      printf("Mes: Abril - 30 dias\n");
      break;

    case 5:  // Maio
      printf("Mes: Maio - 31 dias\n");
      break;

    case 6:  // Junho
      printf("Mes: Junho - 30 dias\n");
      break;

    case 7:  // Julho
      printf("Mes: Julho - 31 dias\n");
      break;

    case 8:  // Agosto
      printf("Mes: Agosto - 31 dias\n");
      break;

    case 9:  // Setembro
      printf("Mes: Setembro - 30 dias\n");
      break;

    case 10:  // Outubro
      printf("Mes: Outubro - 31 dias\n");
      break;

    case 11:  // Novembro
      printf("Mes: Novembro - 30 dias\n");
      break;

    case 12:  // Dezembro
      printf("Mes: Dezembro - 31 dias\n");
      break;

    default:  // Valor inválido
      printf("Mes invalido.\n");
      break;
  }

  return 0;
}