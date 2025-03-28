/*
  Título: Dia da Semana
  Descrição: Programa que converte um número de 1 a 7 no dia da semana correspondente
  Entrada: Um número inteiro entre 1 e 7
  Saída: Nome do dia da semana correspondente ou mensagem de erro
  Exemplo:
    Entrada:
      Digite um numero (1 a 7) para o dia da semana: 1
    Saída:
      Domingo
    Entrada:
      Digite um numero (1 a 7) para o dia da semana: 4
    Saída:
      Quarta
    Entrada:
      Digite um numero (1 a 7) para o dia da semana: 8
    Saída:
      Valor invalido.
*/

#include <stdio.h>

int main()
{
  int dia;  // Número do dia da semana (1-7)

  // Leitura do número do dia
  printf("Digite um numero (1 a 7) para o dia da semana: ");
  scanf("%d", &dia);

  // Conversão do número para o nome do dia
  switch (dia)
  {
    case 1:  // Domingo
      printf("Domingo\n");
      break;

    case 2:  // Segunda
      printf("Segunda\n");
      break;

    case 3:  // Terça
      printf("Terca\n");
      break;

    case 4:  // Quarta
      printf("Quarta\n");
      break;

    case 5:  // Quinta
      printf("Quinta\n");
      break;

    case 6:  // Sexta
      printf("Sexta\n");
      break;

    case 7:  // Sábado
      printf("Sabado\n");
      break;

    default:  // Valor inválido
      printf("Valor invalido.\n");
      break;
  }

  return 0;
}