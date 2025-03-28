/*
  Título: Estrutura Aluno Simples
  Descrição: Programa que demonstra a criação e uso de uma estrutura (struct) para armazenar dados de um aluno
  Entrada: Nenhuma (dados definidos no código)
  Saída: Dados do aluno (nome, idade e média)
  Exemplo:
    Saída:
      Aluno: Maria Clara
      Idade: 19
      Média: 8.50
*/

#include <stdio.h>
#include <string.h>

struct Aluno
{
  char nome[50];  // Nome do aluno (até 49 caracteres + \0)
  int idade;      // Idade do aluno
  float media;    // Média das notas
};

int main()
{
  struct Aluno aluno;

  // Inicialização dos dados do aluno
  strcpy(aluno.nome, "Maria Clara");
  aluno.idade = 19;
  aluno.media = 8.5;

  // Exibição dos dados
  printf("Aluno: %s\n", aluno.nome);
  printf("Idade: %d\n", aluno.idade);
  printf("Média: %.2f\n", aluno.media);

  return 0;
}