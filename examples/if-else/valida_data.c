/*
  Título: Validação de Data
  Descrição: Programa que valida uma data inserida pelo usuário, verificando se os valores são coerentes
  Entrada: 
    - Dia (1-31)
    - Mês (1-12)
    - Ano (maior que 0)
  Saída: Mensagem indicando se a data é válida ou inválida
  Exemplo:
    Entrada:
      Digite o dia: 15
      Digite o mes: 3
      Digite o ano: 2024
    Saída:
      Data valida
    Entrada:
      Digite o dia: 32
      Digite o mes: 1
      Digite o ano: 2024
    Saída:
      Data invalida
    Entrada:
      Digite o dia: 15
      Digite o mes: 13
      Digite o ano: 2024
    Saída:
      Data invalida
*/

#include <stdio.h>

int main()
{
  int dia;   // Dia do mês (1-31)
  int mes;   // Mês do ano (1-12)
  int ano;   // Ano (deve ser maior que 0)

  // Leitura da data
  printf("Digite o dia: ");
  scanf("%d", &dia);
  printf("Digite o mes: ");
  scanf("%d", &mes);
  printf("Digite o ano: ");
  scanf("%d", &ano);

  // Validação da data
  if (dia >= 1 && dia <= 31)  // Verifica se o dia é válido
  {
    if (mes >= 1 && mes <= 12)  // Verifica se o mês é válido
    {
      if (ano > 0)  // Verifica se o ano é válido
      {
        printf("Data valida\n");
      }
      else
      {
        printf("Data invalida\n");
      }
    }
    else
    {
      printf("Data invalida\n");
    }
  }
  else
  {
    printf("Data invalida\n");
  }

  return 0;
}