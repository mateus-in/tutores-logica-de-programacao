/*
  Título: Leitura de String e Inteiro
  Descrição: Programa que demonstra o uso de scanf para leitura de string e número inteiro
  Entrada: 
    - Uma string (nome)
    - Um número inteiro (idade)
  Saída: Uma mensagem personalizada com o nome e idade
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
  char nome[50]; // Vetor de char para armazenar o nome (até 49 caracteres + terminador)
  int idade;

  printf("Digite seu primeiro nome (sem espacos): ");
  scanf("%s", nome); // Lê string até encontrar um espaço ou quebra de linha

  printf("Digite sua idade: ");
  scanf("%d", &idade);

  printf("Ola, %s! Voce tem %d anos.\n", nome, idade);

  return 0;
}