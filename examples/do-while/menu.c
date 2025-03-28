/*
  Título: Menu Interativo
  Descrição: Programa que implementa um menu simples com três opções,
             permitindo ao usuário escolher entre elas até que decida sair
  Entrada: Número inteiro representando a opção do menu (1, 2 ou 3)
  Saída: Mensagem correspondente à opção selecionada ou erro
  Exemplo:
    Entrada:
      Escolha uma opcao: 1
      Opcao 1 selecionada.
      Escolha uma opcao: 4
      Opcao invalida.
      Escolha uma opcao: 2
      Opcao 2 selecionada.
      Escolha uma opcao: 3
    Saída:
      Encerrando...
*/

#include <stdio.h>

int main()
{
  int opcao;  // Opção selecionada pelo usuário

  // Menu interativo que se repete até que o usuário escolha sair
  do
  {
    // Exibe o menu de opções
    printf("\n---- MENU ----\n");
    printf("1 - Opcao 1\n");
    printf("2 - Opcao 2\n");
    printf("3 - Sair\n");
    printf("Escolha uma opcao: ");
    scanf("%d", &opcao);

    // Processa a opção selecionada
    switch (opcao)
    {
      case 1:
        printf("Opcao 1 selecionada.\n");
        break;
      case 2:
        printf("Opcao 2 selecionada.\n");
        break;
      case 3:
        printf("Encerrando...\n");
        break;
      default:
        printf("Opcao invalida.\n");
    }
  } while (opcao != 3);

  return 0;
}