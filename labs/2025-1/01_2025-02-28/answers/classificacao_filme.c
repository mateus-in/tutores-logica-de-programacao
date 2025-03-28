/*
  Título: Classificação Indicativa de Filmes
  Descrição: Programa que exibe um menu com classificações indicativas de filmes
             e mostra a classificação selecionada pelo usuário
  Entrada: Número inteiro representando a opção do menu (1 a 6)
  Saída: Classificação indicativa correspondente à opção selecionada
  Exemplo:
    Entrada:
      Selecione uma opcao: 3
    Saída:
      Classificacao: 12 anos.
*/

#include <stdio.h>

int main()
{
  int opcao;  // Opção selecionada pelo usuário

  // Exibe o menu de classificações
  printf("Classificacao indicativa:\n");
  printf("1 - Livre\n");
  printf("2 - 10 anos\n");
  printf("3 - 12 anos\n");
  printf("4 - 14 anos\n");
  printf("5 - 16 anos\n");
  printf("6 - 18 anos\n");
  printf("Selecione uma opcao: ");
  scanf("%d", &opcao);

  // Processa a opção selecionada
  switch (opcao)
  {
    case 1:
      printf("Classificacao: Livre.\n");
      break;
    case 2:
      printf("Classificacao: 10 anos.\n");
      break;
    case 3:
      printf("Classificacao: 12 anos.\n");
      break;
    case 4:
      printf("Classificacao: 14 anos.\n");
      break;
    case 5:
      printf("Classificacao: 16 anos.\n");
      break;
    case 6:
      printf("Classificacao: 18 anos.\n");
      break;
    default:
      printf("Opcao invalida.\n");
      break;
  }

  return 0;
}