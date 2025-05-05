#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_PETS 3
#define MAX_TUTORES 10

// Definição da struct Pet
typedef struct
{
  char ID[15];
  char nome[50];
} Pet;

// Definição da struct Tutor
typedef struct
{
  char ID[15];
  char nome[50];
  Pet pets[MAX_PETS];
  int numPets;
} Tutor;
Tutor tutores[MAX_TUTORES];
int totaldetutores = 0;
int totaldepets = 0;

// Função para limpar a tela
void limparTela()
{
#ifdef _WIN32
  system("cls");
#else
  system("clear");
#endif
}

// Função para aguardar o usuário digitar uma tecla
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

// Função para exibir o menu principal
void exibirMenu()
{
  printf("*Gestão de Pets*\n\n");
  printf("1 - Listar os tutores cadastrados\n\n");
  printf("2 - Cadastrar um novo tutor\n\n");
  printf("3 - Atualizar um tutor cadastrado\n\n");
  printf("4 - Excluir um tutor cadastrado\n\n");
  printf("5 - Listar os pets cadastrados\n\n");
  printf("6 - Cadastrar um novo pet\n\n");
  printf("7 - Atualizar um pet cadastrado\n\n");
  printf("8 - Excluir um pet cadastrado\n\n");
  printf("0 - Sair\n\n");
  printf("Escolha uma opção: ");
}



// Função para listar todos os tutores cadastrados
void listarTutores() {
    // Verifica se não há tutores cadastrados
    if (totaldetutores == 0) {
        // Exibe uma mensagem indicando que não há tutores registrados no sistema
        printf("Nenhum tutor cadastrado.\n");
    } else {
        // Se houver tutores cadastrados, percorre a lista de tutores
        for (int i = 0; i < totaldetutores; i++) {
            // Exibe o ID e o nome de cada tutor
            printf("ID: %s\n | Nome: %s\n", tutores[i].ID, tutores[i].nome);
        }
    }
    // Aguarda o usuário pressionar uma tecla antes de continuar
    aguardarTecla();
}

// Cadastrar tutor


void cadastrarTutor() {
    // Verifica se o número máximo de tutores já foi atingido
    if (totaldetutores >= MAX_TUTORES) {
        printf("Número máximo de tutores atingido!\n");
        aguardarTecla(); // Aguarda interação do usuário antes de continuar
        return; // Sai da função, pois não é possível cadastrar mais tutores
    }

    Tutor novoTutor; // Declara uma variável para armazenar os dados do novo tutor

    // Solicita o ID do tutor ao usuário
    printf("Digite o ID do tutor: ");
    scanf("%s", novoTutor.ID); // Lê o ID digitado
    limparBuffer(); // Limpa o buffer para evitar problemas na próxima leitura

    // Solicita o nome do tutor ao usuário
    printf("Digite o nome do tutor: ");
    fgets(novoTutor.nome, sizeof(novoTutor.nome), stdin); // Lê o nome digitado pelo usuário
    novoTutor.nome[strcspn(novoTutor.nome, "\n")] = '\0'; // Remove o caractere de nova linha (\n) da string

    // Verifica se o ID informado já está cadastrado no sistema
    for (int i = 0; i < totaldetutores; i++) {
        if (strcmp(tutores[i].ID, novoTutor.ID) == 0) { // Compara o ID com os já cadastrados
            printf("\nJá existe um tutor com esse ID no sistema!\n");
            aguardarTecla(); // Aguarda interação do usuário
            return; // Sai da função, pois o ID já está registrado
        }
    }

    // Verifica se o nome informado já está cadastrado no sistema
    for (int i = 0; i < totaldetutores; i++) {
        if (strcmp(tutores[i].nome, novoTutor.nome) == 0) { // Compara o nome com os já cadastrados
            printf("\nJá existe um tutor com esse nome no sistema!\n");
            aguardarTecla(); // Aguarda interação do usuário
            return; // Sai da função, pois o nome já está registrado
        }
    }

    // Inicializa o número de pets do tutor como zero
    novoTutor.numPets = 0;

    // Adiciona o novo tutor ao sistema e incrementa a quantidade total de tutores
    tutores[totaldetutores++] = novoTutor;

    // Confirma que o tutor foi cadastrado com sucesso
    printf("\nTutor cadastrado com sucesso!\n");
    aguardarTecla(); // Aguarda interação do usuário antes de continuar
}




// Função para atualizar o nome de um tutor cadastrado
void atualizarTutor() {
    char IDbusca[15]; // Variável para armazenar o ID do tutor que será atualizado

    // Solicita ao usuário o ID do tutor que deseja atualizar
    printf("Digite o ID do tutor que deseja atualizar: ");
    scanf("%s", IDbusca); // Lê o ID digitado pelo usuário
    limparBuffer(); // Limpa o buffer do teclado para evitar problemas na próxima leitura

    // Percorre a lista de tutores para encontrar o tutor com o ID fornecido
    for (int i = 0; i < totaldetutores; i++) {
        if (strcmp(tutores[i].ID, IDbusca) == 0) { // Compara o ID digitado com os IDs cadastrados
            // Se encontrar o tutor, solicita o novo nome
            printf("\nDigite o novo nome para o tutor: ");
            fgets(tutores[i].nome, sizeof(tutores[i].nome), stdin); // Lê o novo nome digitado
            tutores[i].nome[strcspn(tutores[i].nome, "\n")] = '\0'; // Remove o caractere de nova linha (\n) da string

            // Confirma que o tutor foi atualizado
            printf("\nTutor atualizado!\n");
            aguardarTecla(); // Aguarda interação do usuário antes de continuar
            return; // Sai da função após atualizar o nome do tutor
        }
    }

    // Caso o tutor não seja encontrado, exibe uma mensagem de erro
    printf("\nTutor não encontrado!\n");
    aguardarTecla(); // Aguarda interação do usuário antes de continuar
}


// Função para excluir um tutor
void excluirTutor() {
    char buscarnome[50]; // Variável para armazenar o nome do tutor a ser excluído
    int encontrado = 0;  // Variável para verificar se o tutor foi encontrado

    // Solicita ao usuário o nome do tutor que deseja excluir
    printf("\nDigite o nome do tutor a ser excluído: ");
    fgets(buscarnome, sizeof(buscarnome), stdin); // Lê o nome digitado
    buscarnome[strcspn(buscarnome, "\n")] = '\0'; // Remove o caractere de nova linha (\n) para evitar problemas na comparação

    // Percorre a lista de tutores para encontrar aquele que deve ser excluído
    for (int i = 0; i < totaldetutores; i++) {
        if (strcmp(tutores[i].nome, buscarnome) == 0) { // Compara os nomes
            encontrado = 1; // Marca que o tutor foi encontrado

            // Remove o tutor deslocando os elementos seguintes uma posição para trás
            for (int j = i; j < totaldetutores - 1; j++) {
                tutores[j] = tutores[j + 1];
            }

            // Decrementa o número total de tutores, efetivamente removendo-o do sistema
            totaldetutores--;

            // Exibe a confirmação da exclusão do tutor e seus pets
            printf("\nTutor e seus pets excluídos!\n");
            aguardarTecla(); // Aguarda interação do usuário antes de continuar
            return; // Sai da função após excluir o tutor
        }
    }

    // Caso o tutor não tenha sido encontrado, exibe uma mensagem de erro
    if (!encontrado) {
        printf("\nTutor não encontrado!\n");
        aguardarTecla(); // Aguarda interação do usuário antes de prosseguir
    }
}

//Função listar pets
void listarPets() {
    // Verifica se há tutores cadastrados no sistema
    if (totaldetutores == 0) {
        // Se não houver tutores, exibe uma mensagem informando que não há registros
        printf("Nenhum pet e tutor cadastrado.");
    } else {
        // Percorre a lista de tutores cadastrados
        for (int i = 0; i < totaldetutores; i++) {
            // Exibe o nome e ID do tutor atual
            printf("\nTutor: %s | ID: %s\n", tutores[i].nome, tutores[i].ID);

            // Verifica se o tutor possui pets cadastrados
            if (tutores[i].numPets == 0) {
                // Se o tutor não tem pets, exibe uma mensagem informando isso
                printf("  Nenhum pet cadastrado.\n");
            } else {
                // Caso o tutor tenha pets, percorre a lista de pets cadastrados para aquele tutor
                for (int j = 0; j < tutores[i].numPets; j++) {
                    // Exibe o nome de cada pet
                    printf("  Pet: %s\n", tutores[i].pets[j].nome);
                }
            }
        }
    }
    // Aguarda interação do usuário antes de continuar
    aguardarTecla();
}
// Função para cadastrar um novo pet
void cadastrarPet() {
    char IDTutor[15], nomePet[50]; // Variáveis para armazenar o ID do tutor e o nome do pet

    // Solicita ao usuário o ID do tutor ao qual deseja cadastrar um pet
    printf("\nDigite o ID do tutor para cadastrar um pet: ");
    scanf("%s", IDTutor); // Lê o ID digitado pelo usuário
    limparBuffer(); // Limpa o buffer para evitar problemas na leitura seguinte

    int tutorIndex = -1; // Índice do tutor encontrado (inicialmente -1 para indicar que não foi encontrado)

    // Percorre a lista de tutores para verificar se o ID informado existe
    for (int i = 0; i < totaldetutores; i++) {
        if (strcmp(tutores[i].ID, IDTutor) == 0) { // Compara o ID informado com os IDs cadastrados
            tutorIndex = i; // Armazena o índice do tutor encontrado
            break; // Sai do loop ao encontrar o tutor
        }
    }

    // Se o tutor não for encontrado, exibe uma mensagem de erro e encerra a função
    if (tutorIndex == -1) {
        printf("\nTutor não encontrado!\n");
        aguardarTecla();
        return;
    }

    // Verifica se o tutor já atingiu o limite de pets cadastrados
    if (tutores[tutorIndex].numPets >= MAX_PETS) {
        printf("\nEsse tutor já atingiu o limite de pets cadastrados!\n");
        aguardarTecla();
        return;
    }

    // Solicita o nome do pet ao usuário
    printf("\nDigite o nome do pet: ");
    fgets(nomePet, sizeof(nomePet), stdin); // Lê o nome digitado pelo usuário
    nomePet[strcspn(nomePet, "\n")] = '\0'; // Remove o caractere de nova linha (\n) da string

    // Verifica se já existe um pet com esse nome no sistema para evitar duplicações
    for (int i = 0; i < totaldetutores; i++) {
        for (int j = 0; j < tutores[i].numPets; j++) {
            if (strcmp(tutores[i].pets[j].nome, nomePet) == 0) { // Compara os nomes dos pets
                printf("\nJá existe um pet com esse nome no sistema!\n");
                aguardarTecla();
                return; // Sai da função caso o pet já esteja cadastrado
            }
        }
    }

    // Cadastrar o novo pet na lista de pets do tutor
    strcpy(tutores[tutorIndex].pets[tutores[tutorIndex].numPets].nome, nomePet); // Copia o nome do pet para a estrutura
    tutores[tutorIndex].numPets++; // Incrementa o número de pets do tutor

    // Confirmação do cadastro
    printf("\nPet cadastrado!\n");
    aguardarTecla(); // Aguarda interação do usuário antes de continuar
}
//  Função para atualizar o pet

void atualizarPet()
{
  char IDTutor[15], nomePet[50], novoNomePet[50];
  int i, j, tutorIndex = -1, petIndex = -1;

  // Solicita o ID do tutor para identificar o tutor no sistema
  printf("\nDigite o ID do tutor do pet: ");
  scanf("%s", IDTutor);
  limparBuffer(); // Função para limpar o buffer de entrada

  // Procura o tutor pelo ID fornecido
  for (i = 0; i < totaldetutores; i++)
  {
    if (strcmp(tutores[i].ID, IDTutor) == 0)
    {
      tutorIndex = i; 
      break;
    }
  }
  
  // Se o tutor não for encontrado, exibe mensagem e retorna
  if (tutorIndex == -1)
  {
    printf("\nTutor não encontrado!\n");
    aguardarTecla();
    return;
  }

  // Solicita o nome do pet que será atualizado
  printf("\nDigite o nome do pet que deseja atualizar: ");
  fgets(nomePet, sizeof(nomePet), stdin);
  nomePet[strcspn(nomePet, "\n")] = '\0'; // Remove o caractere de nova linha

  // Procura o pet pelo nome dentro da lista de pets do tutor identificado
  for (j = 0; j < tutores[tutorIndex].numPets; j++)
  {
    if (strcmp(tutores[tutorIndex].pets[j].nome, nomePet) == 0)
    {
      petIndex = j;
      break;
    }
  }

  // Se o pet não for encontrado, exibe mensagem e retorna
  if (petIndex == -1)
  {
    printf("\nPet não encontrado!\n");
    aguardarTecla();
    return;
  }

  // Solicita o novo nome para o pet
  printf("\nDigite o novo nome do pet: ");
  fgets(novoNomePet, sizeof(novoNomePet), stdin);
  novoNomePet[strcspn(novoNomePet, "\n")] = '\0'; // Remove o caractere de nova linha

  // Verifica se já existe um pet com esse nome no sistema
  for (i = 0; i < totaldetutores; i++)
  {
    for (j = 0; j < tutores[i].numPets; j++)
    {
      if (strcmp(tutores[i].pets[j].nome, novoNomePet) == 0)
      {
        printf("\nJá existe um pet com esse nome no sistema!\n");
        aguardarTecla();
        return;
      }
    }
  }

  // Atualiza o nome do pet no sistema
  strcpy(tutores[tutorIndex].pets[petIndex].nome, novoNomePet);
  printf("\nPet atualizado!\n");
  aguardarTecla();
}
// Função para excluir um pet cadastrado

void excluirPet() 
{
    char IDtutor[15], nomePet[50];
    int i, j, tutorIndex = -1, petIndex = -1;

    // Solicita ao usuário o ID do tutor do pet que será excluído
    printf("\nDigite o ID do tutor do pet: ");
    scanf("%s", IDtutor); 
    limparBuffer(); // Evita problemas com o buffer do teclado

    // Procura o tutor pelo ID fornecido
    for (i = 0; i < totaldetutores; i++) 
    {
        if (strcmp(tutores[i].ID, IDtutor) == 0) 
        {
            tutorIndex = i; // Se encontrado, armazena o índice do tutor
            break;
        }
    }

    // Se o tutor não for encontrado, exibe mensagem e encerra a função
    if (tutorIndex == -1) 
    {
        printf("\nTutor não encontrado!\n");
        aguardarTecla();
        return;
    }

    // Solicita ao usuário o nome do pet a ser excluído
    printf("\nDigite o nome do pet a ser excluído: ");
    fgets(nomePet, sizeof(nomePet), stdin);
    nomePet[strcspn(nomePet, "\n")] = '\0'; // Remove o caractere de nova linha

    // Procura o pet pelo nome fornecido dentro do tutor identificado
    for (j = 0; j < tutores[tutorIndex].numPets; j++) 
    {
        if (strcmp(tutores[tutorIndex].pets[j].nome, nomePet) == 0) 
        {
            petIndex = j; // Se encontrado, armazena o índice do pet
            break;
        }
    }

    // Se o pet não for encontrado, exibe mensagem e encerra a função
    if (petIndex == -1) 
    {
        printf("\nPet não encontrado!\n");
        aguardarTecla();
        return;
    }

    // Remove o pet deslocando os elementos do array para preencher a lacuna
    for (j = petIndex; j < tutores[tutorIndex].numPets - 1; j++) 
    {
        tutores[tutorIndex].pets[j] = tutores[tutorIndex].pets[j + 1];
    }

    // Decrementa o número total de pets do tutor
    tutores[tutorIndex].numPets--;

    // Exibe mensagem confirmando a exclusão
    printf("\nPet excluído!\n");
    aguardarTecla();
}

int main()
{
  // Variaveis locais
  int opcao;

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