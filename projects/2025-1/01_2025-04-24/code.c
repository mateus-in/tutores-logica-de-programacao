#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_PETS 3
#define MAX_TUTORES 10

// Definição da struct Pet
typedef struct {
  int id;
  char nome[50];
} Pet;

// Definição da struct Tutor
typedef struct {
  int id;
  char nome[50];
  Pet pets[MAX_PETS];
  int numPets;
} Tutor;

// Função para limpar a tela
void limparTela() {
  #ifdef _WIN32
    system("cls");
  #else
    system("clear");
  #endif
}

// Função para aguardar o usuário digitar uma tecla
void aguardarTecla() {
  printf("\nPressione qualquer tecla para voltar ao menu...");
  getchar();
}

/*
  Função para limpar o buffer de entrada
  (para evitar problemas com o scanf)
  Essa função é chamada após cada scanf para garantir que o buffer de entrada esteja limpo
  e não cause problemas nas próximas leituras.
  Ela lê todos os caracteres até encontrar um '\n' ou EOF.
  Isso é importante para evitar que o buffer de entrada contenha dados indesejados,
  que poderiam interferir na leitura de dados subsequentes.
  Essa função é especialmente útil quando se utiliza scanf para ler strings,
  pois o scanf não consome o caractere de nova linha ('\n') deixado pelo Enter.
  Assim, se não limparmos o buffer, o próximo scanf pode ler esse caractere de nova linha
  e não esperar pela entrada do usuário, causando um comportamento inesperado.
*/
void limparBuffer() {
  int c;
  while ((c = getchar()) != '\n' && c != EOF)
    ;
}

// Função para exibir o menu principal
void exibirMenu() {
  printf("*****Gestão de Pets*****\n\n");
  printf("1 - Listar os tutores cadastrados\n");
  printf("2 - Cadastrar um novo tutor\n");
  printf("3 - Atualizar um tutor cadastrado\n");
  printf("4 - Excluir um tutor cadastrado\n");
  printf("5 - Listar os pets cadastrados\n");
  printf("6 - Cadastrar um novo pet\n");
  printf("7 - Atualizar um pet cadastrado\n");
  printf("8 - Excluir um pet cadastrado\n");
  printf("0 - Sair\n\n");
  printf("Escolha uma opção: ");
}

/*
  Função para listar os tutores cadastrados
  Essa função deve percorrer o array de tutores e exibir os dados de cada um.
  Se não houver tutores cadastrados, deve exibir uma mensagem informando isso.
*/
void listarTutores() {
  // BATATINHA
  aguardarTecla();
}

/*
  Função para cadastrar um novo tutor
  Essa função deve solicitar os dados do tutor (nome, pets, etc.) e armazená-los no array de tutores.
  Deve verificar se o número máximo de tutores foi atingido antes de cadastrar um novo.
  Não deve permitir cadastrar um tutor com o mesmo nome de outro já cadastrado.
*/
void cadastrarTutor() {
  // BATATINHA
  aguardarTecla();
}

/*
  Função para atualizar um tutor cadastrado
  Essa função deve solicitar o nome do tutor a ser atualizado e os novos dados (nome, pets, etc.).
  Deve verificar se o tutor existe antes de tentar atualizá-lo.
  Se o tutor não existir, deve exibir uma mensagem informando isso.
*/
void atualizarTutor() {
  // BATATINHA
  aguardarTecla();
}

/*
  Função para excluir um tutor cadastrado
  Essa função deve solicitar o nome do tutor a ser excluído.
  Deve verificar se o tutor existe antes de tentar excluí-lo.
  Se o tutor não existir, deve exibir uma mensagem informando isso.
  Após excluir o tutor, deve liberar a memória alocada para os pets desse tutor.
*/
void excluirTutor() {
  // BATATINHA
  aguardarTecla();
}

/*
  Função para listar os pets cadastrados
  Essa função deve percorrer o array de tutores e exibir os dados dos pets de cada um.
  Se não houver pets cadastrados, deve exibir uma mensagem informando isso.
*/
void listarPets() {
  // BATATINHA
  aguardarTecla();
}

/*
  Função para cadastrar um novo pet
  Essa função deve solicitar os dados do pet (nome, tutor, etc.) e armazená-los no array de pets.
  Deve verificar se o número máximo de pets foi atingido antes de cadastrar um novo.
  Não deve permitir cadastrar um pet com o mesmo nome de outro já cadastrado.
*/
void cadastrarPet() {
  // BATATINHA
  aguardarTecla();
}

/*
  Função para atualizar um pet cadastrado
  Essa função deve solicitar o nome do pet a ser atualizado e os novos dados (nome, tutor, etc.).
  Deve verificar se o pet existe antes de tentar atualizá-lo.
  Se o pet não existir, deve exibir uma mensagem informando isso.
*/
void atualizarPet() {
  // BATATINHA
  aguardarTecla();
}

/*
  Função para excluir um pet cadastrado
  Essa função deve solicitar o nome do pet a ser excluído.
  Deve verificar se o pet existe antes de tentar excluí-lo.
  Se o pet não existir, deve exibir uma mensagem informando isso.
*/
void excluirPet() {
  // BATATINHA
  aguardarTecla();
}

int main() {
  // Variáveis locais
  Tutor tutores[MAX_TUTORES];
  int totalTutores = 0;
  int opcao;

  do {
    limparTela();
    exibirMenu();
    scanf("%d", &opcao);
    limparBuffer();

    limparTela();

    switch (opcao)
    {
    case 1:
      listarTutores();
      break;
    case 2:
      cadastrarTutor();
      break;
    case 3:
      atualizarTutor();
      break;
    case 4:
      excluirTutor();
      break;
    case 5:
      listarPets();
      break;
    case 6:
      cadastrarPet();
      break;
    case 7:
      atualizarPet();
      break;
    case 8:
      excluirPet();
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
