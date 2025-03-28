/*
  Título: Controle Acadêmico Completo
  Descrição: Sistema básico de controle acadêmico usando estruturas aninhadas para cadastrar alunos e suas disciplinas
  Entrada: 
    - Nome do aluno (string)
    - Matrícula (int)
    - Para cada disciplina:
      - Nome (string)
      - Carga horária (int)
      - Média (float)
  Saída: Dados completos dos alunos cadastrados com suas respectivas disciplinas
  Exemplo:
    Entrada:
      Nome do aluno: João Silva
      Matrícula: 12345
      Nome da disciplina 1: Programação
      Carga horária: 60
      Média: 8.5
      Nome da disciplina 2: Matemática
      Carga horária: 80
      Média: 7.0
      Nome do aluno: Maria Santos
      Matrícula: 12346
      Nome da disciplina 1: Física
      Carga horária: 90
      Média: 9.0
      Nome da disciplina 2: Química
      Carga horária: 70
      Média: 8.0
    Saída:
      Dados dos Alunos:
      Aluno: João Silva (Matrícula 12345)
        Disciplina: Programação | CH: 60 | Média: 8.50
        Disciplina: Matemática | CH: 80 | Média: 7.00
      Aluno: Maria Santos (Matrícula 12346)
        Disciplina: Física | CH: 90 | Média: 9.00
        Disciplina: Química | CH: 70 | Média: 8.00
*/

#include <stdio.h>
#include <string.h>

struct Disciplina
{
  char nome[50];         // Nome da disciplina (até 49 caracteres + \0)
  int carga_horaria;     // Carga horária em horas
  float media;           // Média do aluno na disciplina
};

struct Aluno
{
  char nome[50];                    // Nome do aluno (até 49 caracteres + \0)
  int matricula;                    // Número da matrícula
  struct Disciplina disciplinas[2]; // Array de 2 disciplinas
};

int main()
{
  struct Aluno alunos[2];  // Vetor de 2 alunos
  int i, j;

  // Cadastro dos alunos e suas disciplinas
  for (i = 0; i < 2; i++)
  {
    printf("Nome do aluno: ");
    fgets(alunos[i].nome, sizeof(alunos[i].nome), stdin);
    alunos[i].nome[strcspn(alunos[i].nome, "\n")] = '\0';

    printf("Matrícula: ");
    scanf("%d", &alunos[i].matricula);
    getchar();  // Limpa o buffer do teclado

    for (j = 0; j < 2; j++)
    {
      printf("Nome da disciplina %d: ", j + 1);
      fgets(alunos[i].disciplinas[j].nome, sizeof(alunos[i].disciplinas[j].nome), stdin);
      alunos[i].disciplinas[j].nome[strcspn(alunos[i].disciplinas[j].nome, "\n")] = '\0';

      printf("Carga horária: ");
      scanf("%d", &alunos[i].disciplinas[j].carga_horaria);

      printf("Média: ");
      scanf("%f", &alunos[i].disciplinas[j].media);
      getchar();  // Limpa o buffer do teclado
    }
  }

  // Exibição dos dados cadastrados
  printf("\nDados dos Alunos:\n");
  for (i = 0; i < 2; i++)
  {
    printf("Aluno: %s (Matrícula %d)\n", alunos[i].nome, alunos[i].matricula);
    for (j = 0; j < 2; j++)
    {
      printf("\tDisciplina: %s | CH: %d | Média: %.2f\n", 
             alunos[i].disciplinas[j].nome, 
             alunos[i].disciplinas[j].carga_horaria, 
             alunos[i].disciplinas[j].media);
    }
  }

  return 0;
}
