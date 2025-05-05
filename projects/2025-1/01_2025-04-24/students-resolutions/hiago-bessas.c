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
Verifica se há tutores cadastrados.
Se houver tutores:
Percorre o vetor de tutores e exibe os dados de cada tutor (ID/CPF e nome).
Se não houver tutores:
Exibe a mensagem "Nenhum tutor cadastrado.".
Ao final, aguarda a entrada de uma tecla do usuário para voltar ao menu.
*/
void listarTutores(Tutor tutores[], int totalTutores) {
    limparTela();

    if (totalTutores == 0) {
      printf("Nenhum tutor cadastrado.\n");
    } else {
      printf("Tutores cadastrados:\n\n");
      for (int i = 0; i < totalTutores; i++) {
        printf("CPF (ID): %d\n", tutores[i].id);       // Mostra o ID do tutor do pet
        printf("Nome: %s\n", tutores[i].nome);         // Mostra o nome que cadastrei
        printf("---------------------------\n");
      }
    }
  
    aguardarTecla();
  }
  
/*
Verifica se ainda há espaço para cadastrar tutor
Pede CPF e nome
Verifica se já existe um tutor com o mesmo CPF
Se estiver tudo certo, adiciona ao vetor e incrementa o contador.
*/
void cadastrarTutor(Tutor tutores[], int *totalTutores) {
    limparTela();

    if (*totalTutores >= MAX_TUTORES) {
      printf("Limite máximo de tutores atingido.\n");  // Verifica se já atingiu o limite
      aguardarTecla();
      return;
    }
  
    int novoId;
    char novoNome[50];
  
    printf("Digite o CPF do tutor (somente números): ");
    scanf("%d", &novoId); // Lê o CPF como ID
    limparBuffer();
  
    // Verifica se já existe um tutor com o mesmo CPF
    for (int i = 0; i < *totalTutores; i++) {
      if (tutores[i].id == novoId) {
        printf("Já existe um tutor com esse CPF.\n");
        aguardarTecla();
        return;
      }
    }
  
    printf("Digite o nome do tutor: ");
    fgets(novoNome, sizeof(novoNome), stdin); // Lê o nome com espaços
    novoNome[strcspn(novoNome, "\n")] = '\0'; // Remove o '\n' do final
  
    // Cadastra o novo tutor
    tutores[*totalTutores].id = novoId;
    strcpy(tutores[*totalTutores].nome, novoNome);
    tutores[*totalTutores].numPets = 0; // Inicializa sem pets cadastrados
  
    (*totalTutores)++; // Atualiza o contador de tutores
  
    printf("Tutor cadastrado com sucesso!\n");
    aguardarTecla();
  }

/*
Pede o CPF do tutor que será atualizado
Busca esse tutor no vetor
Se encontrar, permite editar o nome
Se não encontrar, mostra uma mensagem de erro
*/
void atualizarTutor(Tutor tutores[], int totalTutores) {
    limparTela();

    int cpfBusca;
    printf("Digite o CPF do tutor que deseja atualizar: ");
    scanf("%d", &cpfBusca);
    limparBuffer();
  
    int encontrado = 0;
  
    for (int i = 0; i < totalTutores; i++) {
      if (tutores[i].id == cpfBusca) {
        char novoNome[50];
  
        printf("Tutor encontrado: %s\n", tutores[i].nome);
        printf("Digite o novo nome do tutor: ");
        fgets(novoNome, sizeof(novoNome), stdin);      // Lê o novo nome
        novoNome[strcspn(novoNome, "\n")] = '\0';       // Remove o '\n' do final
  
        strcpy(tutores[i].nome, novoNome);              // Atualiza o nome
        printf("Nome atualizado com sucesso!\n");
  
        encontrado = 1;
        break;
      }
    }
  
    if (!encontrado) {
      printf("Tutor com CPF %d não encontrado.\n", cpfBusca);
    }
  
    aguardarTecla();
  }

/*
Solicita o CPF  do tutor que vai ser apagado
Verifica se esse tutor ta cadastrado
Se existir, remove ele e todos os seus pets zera
Realoca os tutores seguintes no vetor para não deixar buracos
Atualiza a contagem de tutores.
*/
void excluirTutor(Tutor tutores[], int *totalTutores) {
    limparTela();

    int cpfBusca;
    printf("Digite o CPF do tutor que deseja excluir: ");
    scanf("%d", &cpfBusca);
    limparBuffer();
  
    int encontrado = 0;
  
    for (int i = 0; i < *totalTutores; i++) {
      if (tutores[i].id == cpfBusca) {
        encontrado = 1;
  
        // Exibe os dados antes de excluir
        printf("Tutor encontrado:\n");
        printf("CPF: %d\n", tutores[i].id);
        printf("Nome: %s\n", tutores[i].nome);
  
        // Confirmação (pode ser opcional, mas é boa prática)
        char confirmacao;
        printf("Tem certeza que deseja excluir este tutor? (s/n): ");
        scanf(" %c", &confirmacao);
        limparBuffer();
  
        if (confirmacao == 's' || confirmacao == 'S') {
          // Realoca os tutores no vetor, removendo o atual
          for (int j = i; j < *totalTutores - 1; j++) {
            tutores[j] = tutores[j + 1];
          }
  
          (*totalTutores)--;  // Decrementa a contagem de tutores
  
          printf("Tutor excluído com sucesso.\n");
        } else {
          printf("Exclusão cancelada.\n");
        }
  
        break;
      }
    }
  
    if (!encontrado) {
      printf("Tutor com CPF %d não encontrado.\n", cpfBusca);
    }
  
    aguardarTecla();
  }

/*
anda por todos os tutores
Para cada tutor, anda seus pets
Exibe o nome do pet + nome e CPF do tutor
Se nenhum pet for encontrado, mostra mensagem.
*/
void listarPets(Tutor tutores[], int totalTutores) {
    limparTela();

    int petsEncontrados = 0; // Variável para verificar se algum pet foi listado
  
    // Percorre os tutores
    for (int i = 0; i < totalTutores; i++) {
      // Percorre os pets de cada tutor
      for (int j = 0; j < tutores[i].numPets; j++) {
        printf("Nome do Pet: %s\n", tutores[i].pets[j].nome); // Exibe o nome do pet
        printf("Tutor: %s\n", tutores[i].nome); // Exibe o nome do tutor
        printf("CPF do Tutor: %d\n", tutores[i].id); // Exibe o CPF do tutor
        printf("---------------------------\n");
        petsEncontrados = 1; // Marca que pelo menos um pet foi listado
      }
    }
  
    // Caso não haja pets cadastrados
    if (!petsEncontrados) {
      printf("Nenhum pet cadastrado.\n");
    }
  
    aguardarTecla();
  }

/*
Pede o CPF do tutor
Verifica se o tutor existe
Verifica se ele já tem o número máximo de pets
Pede o nome do pet
Verifica se o nome do pet já existe para esse tutor 
Cadastra o pet.
*/
void cadastrarPet(Tutor tutores[], int totalTutores) {
    limparTela();

  int cpfTutor;
  printf("Digite o CPF do tutor do pet: ");
  scanf("%d", &cpfTutor);
  limparBuffer(); 

  int encontrado = 0; // Variável para verificar se o tutor foi encontrado

  // Procura pelo tutor com o CPF fornecido
  for (int i = 0; i < totalTutores; i++) {
    if (tutores[i].id == cpfTutor) {
      encontrado = 1;

      // Verifica se o tutor já atingiu o número máximo de pets
      if (tutores[i].numPets >= MAX_PETS) {
        printf("Esse tutor já possui o número máximo de pets (%d).\n", MAX_PETS);
        aguardarTecla();
        return;
      }

      char nomePet[50];
      printf("Digite o nome do pet: ");
      fgets(nomePet, sizeof(nomePet), stdin); // Lê o nome do pet
      nomePet[strcspn(nomePet, "\n")] = '\0'; // Remove o caractere de nova linha

      // Verifica se o nome do pet já está cadastrado para este tutor
      for (int j = 0; j < tutores[i].numPets; j++) {
        if (strcmp(tutores[i].pets[j].nome, nomePet) == 0) {
          printf("Esse tutor já possui um pet com esse nome.\n");
          aguardarTecla();
          return;
        }
      }

      // Cadastra o novo pet
      Pet novoPet;
      novoPet.id = tutores[i].numPets + 1; // Define um ID para o pet (opcional)
      strcpy(novoPet.nome, nomePet); // Atribui o nome do pet

      tutores[i].pets[tutores[i].numPets] = novoPet; // Adiciona o pet ao vetor de pets do tutor
      tutores[i].numPets++; // Incrementa o número de pets do tutor

      printf("Pet cadastrado com sucesso!\n");
      aguardarTecla(); 
      return;
    }
  }

  // Caso o tutor não seja encontrado
  if (!encontrado) {
    printf("Tutor com CPF %d não encontrado.\n", cpfTutor);
    aguardarTecla();
  }
}
/*
Solicita o CPF do tutor
Busca o tutor
Solicita o nome atual do pet
Busca o pet na lista de pets do tutor
Solicita o novo nome e atualiza.
*/
void atualizarPet(Tutor tutores[], int totalTutores) {
    limparTela();

    int cpfTutor;
    char nomeAntigo[50];
  
    printf("Digite o CPF do tutor do pet: ");
    scanf("%d", &cpfTutor);
    limparBuffer();
  
    int tutorEncontrado = 0; // Variável para verificar se o tutor foi encontrado
  
    // Procura pelo tutor com o CPF fornecido
    for (int i = 0; i < totalTutores; i++) {
      if (tutores[i].id == cpfTutor) {
        tutorEncontrado = 1;
  
        printf("Digite o nome atual do pet: ");
        fgets(nomeAntigo, sizeof(nomeAntigo), stdin); // Lê o nome atual do pet
        nomeAntigo[strcspn(nomeAntigo, "\n")] = '\0'; // Remove o caractere de nova linha
  
        int petEncontrado = 0; // Variável para verificar se o pet foi encontrado
  
        // Procura pelo pet com o nome fornecido
        for (int j = 0; j < tutores[i].numPets; j++) {
          if (strcmp(tutores[i].pets[j].nome, nomeAntigo) == 0) {
            petEncontrado = 1;
  
            char novoNome[50];
            printf("Digite o novo nome do pet: ");
            fgets(novoNome, sizeof(novoNome), stdin); // Lê o novo nome do pet
            novoNome[strcspn(novoNome, "\n")] = '\0'; // Remove o caractere de nova linha
  
            // Atualiza o nome do pet
            strcpy(tutores[i].pets[j].nome, novoNome);
            printf("Nome do pet atualizado com sucesso!\n");
            aguardarTecla();
            return;
          }
        }
  
        // Caso o pet não seja encontrado
        if (!petEncontrado) {
          printf("Pet com nome '%s' não encontrado para este tutor.\n", nomeAntigo);
          aguardarTecla();
          return;
        }
      }
    }
  
    // Caso o tutor não seja encontrado
    if (!tutorEncontrado) {
      printf("Tutor com CPF %d não encontrado.\n", cpfTutor);
      aguardarTecla();
    }
  }

/*
Solicita o CPF do tutor e o nome do pet
Verifica se o tutor existe
Verifica se o pet existe
Exclui o pet (deslocando os pets restantes para "vaziar" a posição do pet excluído)
*/
void excluirPet(Tutor tutores[], int *totalTutores) {
    limparTela();

    int cpfTutor;
    char nomePet[50];
  
    printf("Digite o CPF do tutor do pet: ");
    scanf("%d", &cpfTutor);
    limparBuffer();
  
    int tutorEncontrado = 0;
  
    for (int i = 0; i < *totalTutores; i++) {
      if (tutores[i].id == cpfTutor) {
        tutorEncontrado = 1;
  
        printf("Digite o nome do pet a ser excluído: ");
        fgets(nomePet, sizeof(nomePet), stdin);
        nomePet[strcspn(nomePet, "\n")] = '\0';
  
        int petEncontrado = 0;
  
        for (int j = 0; j < tutores[i].numPets; j++) {
          if (strcmp(tutores[i].pets[j].nome, nomePet) == 0) {
            petEncontrado = 1;
  
            // Exclui o pet: desloca os pets para "remover" o pet
            for (int k = j; k < tutores[i].numPets - 1; k++) {
              tutores[i].pets[k] = tutores[i].pets[k + 1];
            }
  
            tutores[i].numPets--;  // Atualiza o número de pets
            printf("Pet '%s' excluído com sucesso!\n", nomePet);
            aguardarTecla();
            return;
          }
        }
  
        if (!petEncontrado) {
          printf("Pet com nome '%s' não encontrado para este tutor.\n", nomePet);
          aguardarTecla();
          return;
        }
      }
    }
  
    if (!tutorEncontrado) {
      printf("Tutor com CPF %d não encontrado.\n", cpfTutor);
      aguardarTecla();
    }
  }
int main() {
  // Variáveis daqui
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
       listarTutores(tutores, totalTutores);
      break;
    case 2:
    cadastrarTutor(tutores, &totalTutores);
      break;
    case 3:
    atualizarTutor(tutores, totalTutores);
      break;
    case 4:
    excluirTutor(tutores, &totalTutores);
      break;
    case 5:
    listarPets(tutores, totalTutores);
      break;
    case 6:
    cadastrarPet(tutores, totalTutores);
      break;
    case 7:
    atualizarPet(tutores, totalTutores);
      break;
    case 8:
    excluirPet(tutores, &totalTutores);
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