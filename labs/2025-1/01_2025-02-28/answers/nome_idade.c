/*
  Título: Saudação com Nome e Idade
  Descrição: Programa que lê o nome e a idade do usuário e exibe uma mensagem de saudação
  Entrada: 
    - Nome (string sem espaços)
    - Idade (número inteiro)
  Saída: Mensagem de saudação personalizada
  Exemplo:
    Entrada:
      Digite seu primeiro nome (sem espacos): Maria
      Digite sua idade: 25
    Saída:
      Ola, Maria! Voce tem 25 anos.
*/

#include <stdio.h>

int main()
{
  char nome[50];  // Array para armazenar o nome
  int idade;      // Variável para armazenar a idade

  // Solicita e lê o nome
  printf("Digite seu primeiro nome (sem espacos): ");
  scanf("%s", nome);

  // Solicita e lê a idade
  printf("Digite sua idade: ");
  scanf("%d", &idade);

  // Exibe a mensagem de saudação
  printf("Ola, %s! Voce tem %d anos.\n", nome, idade);

  return 0;
}