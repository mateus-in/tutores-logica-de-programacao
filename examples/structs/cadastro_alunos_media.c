/*
  Título: Cadastro de Alunos com Média
  Descrição: Programa que cadastra alunos com nome, matrícula e três notas, calculando e exibindo a média final
  Entrada: 
    - Nome do aluno (string)
    - Matrícula (int)
    - Três notas (float)
  Saída: Nome, matrícula e média final de cada aluno cadastrado
  Exemplo:
    Entrada:
      Nome do aluno: João Silva
      Matrícula: 12345
      Notas:
      Nota 1: 8.5
      Nota 2: 7.0
      Nota 3: 9.0
      Nome do aluno: Maria Santos
      Matrícula: 12346
      Notas:
      Nota 1: 9.0
      Nota 2: 8.5
      Nota 3: 7.5
      Nome do aluno: Pedro Oliveira
      Matrícula: 12347
      Notas:
      Nota 1: 7.0
      Nota 2: 8.0
      Nota 3: 9.5
    Saída:
      Médias dos Alunos:
      João Silva (Matrícula 12345): Média 8.17
      Maria Santos (Matrícula 12346): Média 8.33
      Pedro Oliveira (Matrícula 12347): Média 8.17
*/

#include <stdio.h>
#include <string.h>

struct Aluno
{
  char nome[50];      // Nome do aluno (até 49 caracteres + \0)
  int matricula;      // Número da matrícula
  float notas[3];     // Array com as três notas
};

int main()
{
  struct Aluno alunos[3];  // Vetor de 3 alunos
  float media;             // Média das notas
  int i, j;

  // Cadastro dos alunos
  for (i = 0; i < 3; i++)
  {
    printf("Nome do aluno: ");
    fgets(alunos[i].nome, sizeof(alunos[i].nome), stdin);
    alunos[i].nome[strcspn(alunos[i].nome, "\n")] = '\0';

    printf("Matrícula: ");
    scanf("%d", &alunos[i].matricula);

    printf("Notas:\n");
    for (j = 0; j < 3; j++)
    {
      printf("Nota %d: ", j + 1);
      scanf("%f", &alunos[i].notas[j]);
    }
    getchar();  // Limpa o buffer do teclado
  }

  // Cálculo e exibição das médias
  printf("\nMédias dos Alunos:\n");
  for (i = 0; i < 3; i++)
  {
    media = 0.0;
    for (j = 0; j < 3; j++)
    {
      media += alunos[i].notas[j];
    }
    media /= 3;
    printf("%s (Matrícula %d): Média %.2f\n", 
           alunos[i].nome, alunos[i].matricula, media);
  }

  return 0;
}