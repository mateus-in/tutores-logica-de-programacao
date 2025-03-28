#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_ALUNOS 10
#define MAX_NOME 50

// Definição da struct Aluno
typedef struct
{
  int matricula;
  char nome[MAX_NOME + 1];
  int ativo; // 0 = inativo, 1 = ativo
} Aluno;

void limparTela()
{
#ifdef _WIN32
  system("cls");
#else
  system("clear");
#endif
}

void aguardarTecla()
{
  printf("\nPressione qualquer tecla para voltar ao menu...");
  getchar();
}

void limparBuffer()
{
  int c;
  while ((c = getchar()) != '\n' && c != EOF)
    ;
}

void exibirMenu()
{
  printf("*****CRUD Alunos*****\n\n");
  printf("1 - Listar os alunos cadastrados\n");
  printf("2 - Cadastrar um novo aluno\n");
  printf("3 - Atualizar um aluno cadastrado\n");
  printf("4 - Excluir um aluno cadastrado\n");
  printf("0 - Sair\n\n");
  printf("Escolha uma opção: ");
}

void listarAlunos(Aluno *alunos)
{
  printf("*****Lista de Alunos*****\n\n");

  int encontrados = 0;

  for (int i = 0; i < MAX_ALUNOS; i++)
  {
    if (alunos[i].ativo)
    {
      printf("Matrícula: %d\n", alunos[i].matricula);
      printf("Nome: %s\n\n", alunos[i].nome);
      encontrados++;
    }
  }

  if (encontrados == 0)
  {
    printf("Nenhum aluno cadastrado.\n");
  }

  aguardarTecla();
}

void cadastrarAluno(Aluno *alunos, int *totalAlunos)
{
  printf("*****Cadastrar aluno*****\n\n");

  if (*totalAlunos >= MAX_ALUNOS)
  {
    printf("Erro: Número máximo de alunos atingido!\n");
    aguardarTecla();
    return;
  }

  Aluno novoAluno;

  printf("Matrícula: ");
  scanf("%d", &novoAluno.matricula);
  limparBuffer();

  // Verificar se a matrícula já existe
  for (int i = 0; i < MAX_ALUNOS; i++)
  {
    if (alunos[i].ativo && alunos[i].matricula == novoAluno.matricula)
    {
      printf("Erro: Matrícula já cadastrada!\n");
      aguardarTecla();
      return;
    }
  }

  printf("Nome: ");
  fgets(novoAluno.nome, MAX_NOME, stdin);

  // Remover o \n do final da string
  size_t len = strlen(novoAluno.nome);
  if (len > 0 && novoAluno.nome[len - 1] == '\n')
  {
    novoAluno.nome[len - 1] = '\0';
  }

  novoAluno.ativo = 1;

  // Encontrar posição disponível
  for (int i = 0; i < MAX_ALUNOS; i++)
  {
    if (!alunos[i].ativo)
    {
      alunos[i] = novoAluno;
      (*totalAlunos)++;
      break;
    }
  }

  printf("\nAluno cadastrado com sucesso!\n");
  aguardarTecla();
}

void atualizarAluno(Aluno *alunos)
{
  printf("*****Atualizar aluno*****\n\n");

  int matricula;
  printf("Digite a matrícula do aluno: ");
  scanf("%d", &matricula);
  limparBuffer();

  int encontrado = 0;

  for (int i = 0; i < MAX_ALUNOS; i++)
  {
    if (alunos[i].ativo && alunos[i].matricula == matricula)
    {
      printf("Nome atual: %s\n", alunos[i].nome);
      printf("Novo nome: ");
      fgets(alunos[i].nome, MAX_NOME, stdin);

      // Remover o \n do final da string
      size_t len = strlen(alunos[i].nome);
      if (len > 0 && alunos[i].nome[len - 1] == '\n')
      {
        alunos[i].nome[len - 1] = '\0';
      }

      printf("\nAluno atualizado com sucesso!\n");
      encontrado = 1;
      break;
    }
  }

  if (!encontrado)
  {
    printf("Erro: Aluno não encontrado!\n");
  }

  aguardarTecla();
}

void excluirAluno(Aluno *alunos, int *totalAlunos)
{
  printf("*****Excluir aluno*****\n\n");

  int matricula;
  printf("Digite a matrícula do aluno: ");
  scanf("%d", &matricula);
  limparBuffer();

  int encontrado = 0;
  int posicao = -1;

  for (int i = 0; i < MAX_ALUNOS; i++)
  {
    if (alunos[i].ativo && alunos[i].matricula == matricula)
    {
      posicao = i;
      encontrado = 1;
      break;
    }
  }

  if (encontrado)
  {
    printf("Aluno encontrado:\n");
    printf("Matrícula: %d\n", alunos[posicao].matricula);
    printf("Nome: %s\n\n", alunos[posicao].nome);

    char confirmacao;
    printf("Deseja realmente excluir este aluno? (S/N): ");
    scanf("%c", &confirmacao);
    limparBuffer();

    if (confirmacao == 'S' || confirmacao == 's')
    {
      alunos[posicao].ativo = 0;
      (*totalAlunos)--;
      printf("\nAluno excluído com sucesso!\n");
    }
    else
    {
      printf("\nOperação cancelada!\n");
    }
  }
  else
  {
    printf("Erro: Aluno não encontrado!\n");
  }

  aguardarTecla();
}

int main()
{
  // Variáveis locais
  Aluno alunos[MAX_ALUNOS];
  int totalAlunos = 0;
  int opcao;

  // Inicializar todos os alunos como inativos
  for (int i = 0; i < MAX_ALUNOS; i++)
  {
    alunos[i].ativo = 0;
  }

  do
  {
    limparTela();
    exibirMenu();
    scanf("%d", &opcao);
    limparBuffer();

    limparTela();

    switch (opcao)
    {
    case 1:
      listarAlunos(alunos);
      break;
    case 2:
      cadastrarAluno(alunos, &totalAlunos);
      break;
    case 3:
      atualizarAluno(alunos);
      break;
    case 4:
      excluirAluno(alunos, &totalAlunos);
      break;
    case 0:
      printf("Encerrando o programa...\n");
      break;
    default:
      printf("Opção inválida!\n");
      aguardarTecla();
    }
  } while (opcao != 0);

  return 0;
}