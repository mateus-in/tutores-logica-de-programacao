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
void listarTutores(Tutor tutores[], int *totalTutores) {
  if(totalTutores == 0){
    printf("O numero de tutores cadastrados atualmente é 0 \n");
    aguardarTecla();
    return;
  }
  printf("Lista de tutores:\n\n");
  for (int i = 0; i < totalTutores; i++) {
    printf("ID: %d\n", tutores[i].id);
    printf("Nome: %s\n", tutores[i].nome);
    printf("Número de pets: %d\n", tutores[i].numPets);
    printf("------------------------\n");
  }

  aguardarTecla();
}

/*
  Função para cadastrar um novo tutor
  Essa função deve solicitar os dados do tutor (nome, pets, etc.) e armazená-los no array de tutores.
  Deve verificar se o número máximo de tutores foi atingido antes de cadastrar um novo.
  Não deve permitir cadastrar um tutor com o mesmo nome de outro já cadastrado.
*/
void cadastrarTutor(Tutor tutores[], int *totalTutores) {
  if (*totalTutores >= MAX_TUTORES) {
    printf("Limite de tutores atingido.\n");
    aguardarTecla();
    return;
  }

  char nomeNovo[50];
  printf("Nome do novo tutor: ");
  fgets(nomeNovo, sizeof(nomeNovo), stdin);
  nomeNovo[strcspn(nomeNovo, "\n")] = '\0'; // remover newline

  // Verificar duplicado
  for (int i = 0; i < *totalTutores; i++) {
    if (strcmp(tutores[i].nome, nomeNovo) == 0) {
      printf("Já existe um tutor com esse nome.\n");
      aguardarTecla();
      return;
    }
  }

  Tutor novoTutor;
  novoTutor.id = *totalTutores + 1;
  strcpy(novoTutor.nome, nomeNovo);
  novoTutor.numPets = 0;

  tutores[*totalTutores] = novoTutor;
  (*totalTutores)++;

  printf("Tutor cadastrado com sucesso!\n");
  aguardarTecla();
}
/*
  Função para atualizar um tutor cadastrado
  Essa função deve solicitar o nome do tutor a ser atualizado e os novos dados (nome, pets, etc.).
  Deve verificar se o tutor existe antes de tentar atualizá-lo.
  Se o tutor não existir, deve exibir uma mensagem informando isso.
*/
void atualizarTutor(Tutor tutores[], int *totalTutores) {

  /*
    Verifica se há tutores cadastrados. Se não houver, exibe uma mensagem e retorna.

    Isso é importante para evitar tentativas de atualização em um array vazio,
    o que poderia causar erros ou comportamentos inesperados.
  */
  if (*totalTutores == 0) {
    printf("Não há tutores cadastrados para atualizar.\n");
    aguardarTecla();
    return;
  }
  /*
    Solicita o nome do tutor a ser atualizado. A função fgets() é usada para ler a entrada do usuário,
    e strcspn() é utilizada para remover o caractere de nova linha ('\n') que pode ser deixado na string.

    Isso garante que o nome seja comparado corretamente, sem caracteres indesejados.

    A variável "encontrado" é inicializada com -1 para indicar que o tutor não foi encontrado.

    Se o tutor for encontrado, seu índice é armazenado na variável "encontrado".

    Após o loop, se "encontrado" ainda for -1, significa que o tutor não foi encontrado.

    Nesse caso, uma mensagem de erro é exibida e a função retorna sem fazer alterações no array.
    Isso evita que o programa tente acessar um índice inválido no array de tutores,
    o que poderia causar um erro de segmentação ou comportamento inesperado.

    Se o tutor for encontrado, a função exibe uma mensagem de confirmação e
    atualiza o tutor no array. Isso é feito sobrescrevendo os dados do tutor encontrado
  */
  char nomeAtual[50];
  printf("Digite o nome do tutor a ser atualizado: ");
  fgets(nomeAtual, sizeof(nomeAtual), stdin);
  nomeAtual[strcspn(nomeAtual, "\n")] = '\0'; // Remover newline

  int encontrado = -1;
  for (int i = 0; i < *totalTutores; i++) {
    if (strcmp(tutores[i].nome, nomeAtual) == 0) {
      encontrado = i;
      break;
    }
  }

  if (encontrado == -1) {
    printf("Tutor não encontrado.\n");
    aguardarTecla();
    return;
  }

  printf("Digite o novo nome do tutor: ");
  char novoNome[50];
  fgets(novoNome, sizeof(novoNome), stdin);
  novoNome[strcspn(novoNome, "\n")] = '\0'; // Remover newline

  // Atualizar o nome do tutor
  strcpy(tutores[encontrado].nome, novoNome); //A função strncpy() é uma alternativa mais segura, que permite controlar o número de caracteres a serem copiados.
 
  printf("Atualização concluída com sucesso!\n");
  aguardarTecla();
}

/*
  Função para excluir um tutor cadastrado
  Essa função deve solicitar o nome do tutor a ser excluído.
  Deve verificar se o tutor existe antes de tentar excluí-lo.
  Se o tutor não existir, deve exibir uma mensagem informando isso.
  Após excluir o tutor, deve liberar a memória alocada para os pets desse tutor.
*/
void excluirTutor(Tutor tutores[], int *totalTutores) {
  /*  
    Verifica se há tutores cadastrados. Se não houver, exibe uma mensagem e retorna.

      Isso é importante para evitar tentativas de exclusão em um array vazio,
      o que poderia causar erros ou comportamentos inesperados.
  */
  if (*totalTutores == 0) {
    printf("Não há tutores cadastrados para excluir.\n");
    aguardarTecla();
    return;
  }
/*
  Solicita o nome do tutor a ser excluído. A função fgets() é usada para ler a entrada do usuário,
  e strcspn() é utilizada para remover o caractere de nova linha ('\n') que pode ser deixado na string.

  Isso garante que o nome seja comparado corretamente, sem caracteres indesejados.
*/
  char nomeExcluir[50];
  printf("Digite o nome do tutor a ser excluído: ");
  fgets(nomeExcluir, sizeof(nomeExcluir), stdin);
  nomeExcluir[strcspn(nomeExcluir, "\n")] = '\0'; // Remover newline

  int encontrado = -1;
  for (int i = 0; i < *totalTutores; i++) {
    if (strcmp(tutores[i].nome, nomeExcluir) == 0) {
      encontrado = i;
      break;
    }
  }
/*
    Se o tutor não for encontrado, exibe uma mensagem informando isso e retorna.

    Isso é importante para evitar tentativas de exclusão em um array vazio,
    o que poderia causar erros ou comportamentos inesperados.

    A variável "encontrado" é inicializada com -1 para indicar que o tutor não foi encontrado.

    Se o tutor for encontrado, seu índice é armazenado na variável "encontrado".

    Após o loop, se "encontrado" ainda for -1, significa que o tutor não foi encontrado.

    Nesse caso, uma mensagem de erro é exibida e a função retorna sem fazer alterações no array.

    Isso evita que o programa tente acessar um índice inválido no array de tutores,
    o que poderia causar um erro de segmentação ou comportamento inesperado.
    */

  if (encontrado == -1) {
    printf("Tutor não encontrado.\n");
    aguardarTecla();
    return;
  }
  /*
    Se o tutor for encontrado, a função exibe uma mensagem de confirmação e
    remove o tutor do array. Isso é feito deslocando todos os tutores após o
    encontrado uma posição para a esquerda, efetivamente sobrescrevendo o tutor
    que está sendo excluído. O número total de tutores é decrementado em 1.
    Isso garante que o array de tutores permaneça consistente e não contenha
    espaços vazios ou dados inválidos.
  */
  // Remover o tutor encontrado e ajustar o array
  for (int i = encontrado; i < *totalTutores - 1; i++) {
    tutores[i] = tutores[i + 1];
  }

  (*totalTutores)--;

  printf("Tutor excluído com sucesso!\n");
  aguardarTecla();
}
/*
  Função para listar os pets cadastrados
  Essa função deve percorrer o array de tutores e exibir os dados dos pets de cada um.
  Se não houver pets cadastrados, deve exibir uma mensagem informando isso.
*/
void listarPets(Tutor tutores[], int totalTutores) {
  int totalPets = 0;

  for (int i = 0; i < totalTutores; i++) {
    totalPets += tutores[i].numPets;
  }

  if (totalPets == 0) {
    printf("Não há pets cadastrados no momento.\n");
    aguardarTecla();
    return;
  }

  printf("Lista de pets cadastrados:\n\n");
  for (int i = 0; i < totalTutores; i++) {
    if (tutores[i].numPets > 0) {
      printf("Tutor: %s\n", tutores[i].nome);
      for (int j = 0; j < tutores[i].numPets; j++) {
        printf("  Pet ID: %d\n", tutores[i].pets[j].id);
        printf("  Nome do Pet: %s\n", tutores[i].pets[j].nome);
        printf("------------------------\n");
      }
    }
  }

  aguardarTecla();
}

/*
  Função para cadastrar um novo pet
  Essa função deve solicitar os dados do pet (nome, tutor, etc.) e armazená-los no array de pets.
  Deve verificar se o número máximo de pets foi atingido antes de cadastrar um novo.
  Não deve permitir cadastrar um pet com o mesmo nome de outro já cadastrado.
*/
void cadastrarPet(Pet pets[], int *totalPets, Tutor tutores[], int totalTutores) {
  if (totalTutores == 0) {
    printf("Não há tutores cadastrados. Cadastre um tutor antes de adicionar um pet.\n");
    aguardarTecla();
    return;
  }

  char nomeNovo[50];
  printf("Nome do novo pet: ");
  fgets(nomeNovo, sizeof(nomeNovo), stdin);
  nomeNovo[strcspn(nomeNovo, "\n")] = '\0'; // Remover newline

  // Verificar duplicado no array de pets global
  for (int i = 0; i < *totalPets; i++) {
    if (strcmp(pets[i].nome, nomeNovo) == 0) {
      printf("Já existe um pet com esse nome.\n");
      aguardarTecla();
      return;
    }
  }

  printf("Digite o nome do tutor responsável pelo pet: ");
  char nomeTutor[50];
  fgets(nomeTutor, sizeof(nomeTutor), stdin);
  nomeTutor[strcspn(nomeTutor, "\n")] = '\0'; // Remover newline

  int tutorEncontrado = -1;

  for (int i = 0; i < totalTutores; i++) {
    if (strcmp(tutores[i].nome, nomeTutor) == 0) {
      tutorEncontrado = i;
      break;
    }
  }

  if (tutorEncontrado == -1) {
    printf("Tutor não encontrado. Cadastre o tutor antes de adicionar o pet.\n");
    aguardarTecla();
    return;
  }

  if (tutores[tutorEncontrado].numPets >= MAX_PETS) {
    printf("O tutor já atingiu o limite máximo de %d pets.\n", MAX_PETS);
    aguardarTecla();
    return;
  }

  // Cadastrar o pet
  Pet novoPet;
  novoPet.id = *totalPets + 1;
  strcpy(novoPet.nome, nomeNovo);

  pets[*totalPets] = novoPet;
  (*totalPets)++;

  // Associar o pet ao tutor
  tutores[tutorEncontrado].pets[tutores[tutorEncontrado].numPets] = novoPet;
  tutores[tutorEncontrado].numPets++;

  printf("Pet cadastrado com sucesso!\n");
  aguardarTecla();
}

/*
  Função para atualizar um pet cadastrado
  Essa função deve solicitar o nome do pet a ser atualizado e os novos dados (nome, tutor, etc.).
  Deve verificar se o pet existe antes de tentar atualizá-lo.
  Se o pet não existir, deve exibir uma mensagem informando isso.
*/
void atualizarPet(Pet pets[], int *totalPets, Tutor tutores[], int totalTutores) {
  if (*totalPets == 0) {
    printf("Nenhum pet cadastrado no momento.\n");
    aguardarTecla();
    return;
  }

  char nomeAtual[50];
  printf("Digite o nome do pet a ser atualizado: ");
  fgets(nomeAtual, sizeof(nomeAtual), stdin);
  nomeAtual[strcspn(nomeAtual, "\n")] = '\0'; // Remover newline

  int petIndex = -1;
  for (int i = 0; i < *totalPets; i++) {
    if (strcmp(pets[i].nome, nomeAtual) == 0) {
      petIndex = i;
      break;
    }
  }

  if (petIndex == -1) {
    printf("Pet não encontrado.\n");
    aguardarTecla();
    return;
  }

  printf("Digite o novo nome do pet: ");
  char novoNome[50];
  fgets(novoNome, sizeof(novoNome), stdin);
  novoNome[strcspn(novoNome, "\n")] = '\0'; // Remover newline

  // Verificar duplicidade do novo nome
  for (int i = 0; i < *totalPets; i++) {
    if (strcmp(pets[i].nome, novoNome) == 0 && i != petIndex) {
      printf("Já existe um pet com esse nome.\n");
      aguardarTecla();
      return;
    }
  }

  printf("Digite o nome do novo tutor responsável pelo pet: ");
  char nomeTutor[50];
  fgets(nomeTutor, sizeof(nomeTutor), stdin);
  nomeTutor[strcspn(nomeTutor, "\n")] = '\0'; // Remover newline

  int tutorNovo = -1;
  for (int i = 0; i < totalTutores; i++) {
    if (strcmp(tutores[i].nome, nomeTutor) == 0) {
      tutorNovo = i;
      break;
    }
  }

  if (tutorNovo == -1) {
    printf("Tutor não encontrado. Atualização cancelada.\n");
    aguardarTecla();
    return;
  }

  // Verifica se o tutor novo já atingiu o limite de pets
  if (tutores[tutorNovo].numPets >= MAX_PETS) {
    printf("O tutor já possui o número máximo de %d pets.\n", MAX_PETS);
    aguardarTecla();
    return;
  }

  // Encontrar tutor antigo e remover o pet dele
  for (int i = 0; i < totalTutores; i++) {
    for (int j = 0; j < tutores[i].numPets; j++) {
      if (strcmp(tutores[i].pets[j].nome, nomeAtual) == 0) {
        // Remover deslocando os demais
        for (int k = j; k < tutores[i].numPets - 1; k++) {
          tutores[i].pets[k] = tutores[i].pets[k + 1];
        }
        tutores[i].numPets--;
        break;
      }
    }
  }

  // Atualizar globalmente o nome
  strcpy(pets[petIndex].nome, novoNome);

  // Associar ao novo tutor
  tutores[tutorNovo].pets[tutores[tutorNovo].numPets] = pets[petIndex];
  tutores[tutorNovo].numPets++;

  printf("Pet atualizado com sucesso!\n");
  aguardarTecla();
}

/*
  Função para excluir um pet cadastrado
  Essa função deve solicitar o nome do pet a ser excluído.
  Deve verificar se o pet existe antes de tentar excluí-lo.
  Se o pet não existir, deve exibir uma mensagem informando isso.
*/
void excluirPet(Pet pets[], int *totalPets, Tutor tutores[], int totalTutores) {
  if (*totalPets == 0) {
    printf("Não há pets cadastrados para excluir.\n");
    aguardarTecla();
    return;
  }

  char nomeExcluir[50];
  printf("Digite o nome do pet a ser excluído: ");
  fgets(nomeExcluir, sizeof(nomeExcluir), stdin);
  nomeExcluir[strcspn(nomeExcluir, "\n")] = '\0'; // Remover newline

  int encontrado = -1;
  for (int i = 0; i < *totalPets; i++) {
    if (strcmp(pets[i].nome, nomeExcluir) == 0) {
      encontrado = i;
      break;
    }
  }

  if (encontrado == -1) {
    printf("Pet não encontrado.\n");
    aguardarTecla();
    return;
  }

  // Remover o pet da lista de pets do tutor
  for (int i = 0; i < totalTutores; i++) {
    for (int j = 0; j < tutores[i].numPets; j++) {
      if (strcmp(tutores[i].pets[j].nome, nomeExcluir) == 0) {
        for (int k = j; k < tutores[i].numPets - 1; k++) {
          tutores[i].pets[k] = tutores[i].pets[k + 1];
        }
        tutores[i].numPets--;
        break;
      }
    }
  }

  // Remover o pet da lista global
  for (int i = encontrado; i < *totalPets - 1; i++) {
    pets[i] = pets[i + 1];
  }

  (*totalPets)--;

  printf("Pet excluído com sucesso!\n");
  aguardarTecla();
}

void salvarDadosEmArquivo(Tutor tutores[], int totalTutores) {
  FILE *arquivo = fopen("dados.txt", "w");

  if (arquivo == NULL) {
    printf("Erro ao abrir o arquivo para escrita.\n");
    return;
  }

  for (int i = 0; i < totalTutores; i++) {
    fprintf(arquivo, "Tutor ID: %d\n", tutores[i].id);
    fprintf(arquivo, "Nome: %s\n", tutores[i].nome);
    fprintf(arquivo, "Número de Pets: %d\n", tutores[i].numPets);
    
    for (int j = 0; j < tutores[i].numPets; j++) {
      fprintf(arquivo, "  Pet ID: %d\n", tutores[i].pets[j].id);
      fprintf(arquivo, "  Nome do Pet: %s\n", tutores[i].pets[j].nome);
    }

    fprintf(arquivo, "--------------------------\n");
  }

  fclose(arquivo);
  printf("Dados salvos em 'dados.txt'.\n");
}

int main() {
  // Variáveis locais
  Tutor tutores[MAX_TUTORES];
  int totalTutores = 0;
  int opcao;
  Pet pets[MAX_PETS];
  int totalPets = 0;

  do {
    limparTela();
    exibirMenu();
    scanf("%d", &opcao);
    limparBuffer();

    limparTela();

    switch (opcao)
    {
    case 1:
    listarTutores(tutores, totalTutores);
      break;
    case 2:
    cadastrarTutor(tutores, &totalTutores);
      break;
    case 3:
      atualizarTutor(tutores, &totalTutores);
      break;
    case 4: 
      excluirTutor(tutores, &totalTutores);
      break;
    case 5:
      listarPets(tutores, totalTutores);
      break;
    case 6:
      cadastrarPet(pets, &totalPets, tutores, totalTutores);
      break;
    case 7:
      atualizarPet(pets, &totalPets, tutores, totalTutores);
      break;
    case 8:
      excluirPet(pets, &totalPets, tutores, totalTutores);
      break;
    case 0:
      salvarDadosEmArquivo(tutores, totalTutores);
      printf("Encerrando o programa...\n");
      break;
    default:
      printf("Opção inválida!\n");
      aguardarTecla();
    }
  } while (opcao != 0);

  return 0;
}