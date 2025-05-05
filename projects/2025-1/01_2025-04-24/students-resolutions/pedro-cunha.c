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
  printf("**Gestão de Pets**\n\n");
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

// Função para listar os tutores cadastrados

void listarTutores()
{
  if (totaldetutores == 0)
  {
    printf("Nenhum tutor cadastrado.\n");
  }
  else
  {
    for (int i = 0; i < totaldetutores; i++)
    {
      printf("ID: %s\n | Nome: %s\n", tutores[i].ID, tutores[i].nome);
    }
  }
  aguardarTecla();
}

// Cadastrar tutor


void cadastrarTutor()

{
    if (totaldetutores >= MAX_TUTORES)
    {
        printf("Número máximo de tutores atingido!\n");
        aguardarTecla();
        return;
    }

   Tutor novoTutor;//O novoTutor é uma variável declarada dentro da função cadastrarTutor()


    printf("Digite o ID do tutor: ");
    scanf("%s", novoTutor.ID);
    limparBuffer();

    printf("Digite o nome do tutor: ");
    fgets(novoTutor.nome, sizeof(novoTutor.nome), stdin);//stdin= define que a entrada deve vir do teclado
    
    novoTutor.nome[strcspn(novoTutor.nome, "\n")] = '\0';//Substitui o \n por \0 indicando fim da string
 

    // Verificar se já existe um tutor com o mesmo nome
    for (int i = 0; i < totaldetutores; i++)
    {
        if (strcmp(tutores[i].nome, novoTutor.nome) == 0)//strcmp compara
        {
            printf("\nJá existe um tutor com esse nome no sistema!\n");
            aguardarTecla();
            return;
        }
    }

    novoTutor.numPets = 0;
    tutores[totaldetutores++] = novoTutor;

    printf("Tutor cadastrado com sucesso!\n");
    aguardarTecla();
}


// Função para atualizar um tutor cadastrado

void atualizarTutor() {
  char IDbusca[15];
  printf("Digite o ID do tutor que deseja atualizar:");
  scanf("%s", IDbusca);
  limparBuffer();

  int encontrado = 0; // Variável para rastrear se o tutor foi encontrado

  for (int i = 0; i < totaldetutores; i++) {
      if (strcmp(tutores[i].ID, IDbusca) == 0) { // Compara o ID digitado com os existentes
          printf("\nDigite o novo nome para o tutor: ");
          fgets(tutores[i].nome, sizeof(tutores[i].nome), stdin);
          tutores[i].nome[strcspn(tutores[i].nome, "\n")] = '\0';
          printf("\nTutor atualizado com sucesso!\n");
          aguardarTecla();
          return; // Sai da função imediatamente após encontrar e atualizar
      }
  }

  // Se nenhum tutor for encontrado após o loop, exibe a mensagem correta
  printf("\nTutor não encontrado!\n");
  aguardarTecla();
}

// Função para excluir um tutor cadastrado

void excluirTutor()
{
    char buscarnome[50];
    int encontrado = 0;

    printf("\nDigite o nome do tutor a ser excluído: ");
    fgets(buscarnome, sizeof(buscarnome), stdin);
    buscarnome[strcspn(buscarnome, "\n")] = '\0';

    for (int i = 0; i < totaldetutores; i++)
    {
        if (strcmp(tutores[i].nome, buscarnome) == 0)
        {
            encontrado = 1;

            // Remover tutor e seus pets
            for (int j = i; j < totaldetutores - 1; j++)
            {
                tutores[j] = tutores[j + 1];
            }

            totaldetutores--;

            printf("\nTutor e seus pets excluídos com sucesso!\n");
            aguardarTecla();
            return; // Sai da função após excluir o tutor
        }
    }

    if (!encontrado) {
        printf("\nTutor não encontrado!\n");
        aguardarTecla();
    }
}
// Função para listar os pets cadastrados

void listarPets()
{
  if (totaldetutores == 0)
  {
    printf("Nenhum pet e tutor cadastrado.");
  }
  else
  {
    for (int i = 0; i < totaldetutores; i++)
    {
      printf("\nTutor: %s | ID: %s\n", tutores[i].nome, tutores[i].ID);
      if (tutores[i].numPets == 0)
      {
        printf("  Nenhum pet cadastrado.\n");
      }
      else
      {
        for (int j = 0; j < tutores[i].numPets; j++)
        {
          printf("  Pet: %s\n", tutores[i].pets[j].nome);
        }
      }
    }
  }
  aguardarTecla();
}

// Função para cadastrar um novo pet

void cadastrarPet()
{
  char IDTutor[15], nomePet[50];

  printf("\nDigite o ID do tutor para cadastrar um pet: ");
  scanf("%s", IDTutor);
  limparBuffer();

  // Procurar tutor pelo ID
  int tutorIndex = -1;//tutorIndex Salva o índice do tutor.

  for (int i = 0; i < totaldetutores; i++)
  {
    if (strcmp(tutores[i].ID, IDTutor) == 0)
    {
      tutorIndex = i;
      break;
    }
  }

  if (tutorIndex == -1)
  {
    printf("\nTutor não encontrado!\n");
    aguardarTecla();
    return;
  }

  if (tutores[tutorIndex].numPets >= MAX_PETS)
  {
    printf("\nEsse tutor já atingiu o limite de pets cadastrados!\n");
    aguardarTecla();
    return;
  }

  printf("\nDigite o nome do pet: ");
  fgets(nomePet, sizeof(nomePet), stdin);
  nomePet[strcspn(nomePet, "\n")] = '\0';

  // Verificar se o pet já existe no sistema
  for (int i = 0; i < totaldetutores; i++)
  {
    for (int j = 0; j < tutores[i].numPets; j++)
    {
      if (strcmp(tutores[i].pets[j].nome, nomePet) == 0)
      {
        printf("\nJá existe um pet com esse nome no sistema!\n");
        aguardarTecla();
        return; //Impede o cadastro duplicado do pet
      }
  
      }
    }

    // Cadastrar o novo pet
    strcpy(tutores[tutorIndex].pets[tutores[tutorIndex].numPets].nome, nomePet);// Copia o nome do pet para a posição correta dentro do tutor.


    tutores[tutorIndex].numPets++;

    printf("\nPet cadastrado com sucesso!\n");
    aguardarTecla();
  }

//  Função para atualizar um pet cadastrado

void atualizarPet()
{
  char IDTutor[15], nomePet[50], novoNomePet[50];
  int i, j, tutorIndex = -1, petIndex = -1;
  //tutorIndex=-1 foi usado para indicar que o tutor ainda não foi encontrado.
  //petIndex=-1 foi usado para indicar que o pet ainda não foi encontrado.



  printf("\nDigite o ID do tutor do pet: ");
  scanf("%s", IDTutor);
  limparBuffer();

  // Procurar tutor pelo ID
  for (i = 0; i < totaldetutores; i++)
  {
    if (strcmp(tutores[i].ID, IDTutor) == 0)
    {
      tutorIndex = i; // Se encontrar um tutor com o ID correspondente, ele salva o índice (tutorIndex = i).


      break;
    }
  }

  if (tutorIndex == -1)//se ficar assim significa que nenhum tutor foi encontrado
  {
    printf("\nTutor não encontrado!\n");
    aguardarTecla();
    return;
  }

  printf("\nDigite o nome do pet que deseja atualizar: ");
  fgets(nomePet, sizeof(nomePet), stdin);
  nomePet[strcspn(nomePet, "\n")] = '\0';

  // Procurar pet dentro do tutor
  for (j = 0; j < tutores[tutorIndex].numPets; j++)
  {
    if (strcmp(tutores[tutorIndex].pets[j].nome, nomePet) == 0)
    {
      petIndex = j;
      break;
    }
  }

  if (petIndex == -1)//verifica se o pet existe
  {
    printf("\nPet não encontrado!\n");
    aguardarTecla();
    return;
  }

  printf("\nDigite o novo nome do pet: ");
  fgets(novoNomePet, sizeof(novoNomePet), stdin);
  novoNomePet[strcspn(novoNomePet, "\n")] = '\0';

  // Verificar se o novo nome já existe no sistema
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

  // Atualizar nome do pet
  strcpy(tutores[tutorIndex].pets[petIndex].nome, novoNomePet);//copia o novo nome
  printf("\nPet atualizado com sucesso!\n");
  aguardarTecla();
}

// Função para excluir um pet cadastrado

void excluirPet()
{
  char IDtutor[15], nomePet[50];
  int i, j, tutorIndex = -1, petIndex = -1;

  printf("\nDigite o ID do tutor do pet: ");
  scanf("%s", IDtutor);
  limparBuffer();

  // Procurar tutor pelo ID
  for (i = 0; i < totaldetutores; i++)
  {
    if (strcmp(tutores[i].ID, IDtutor) == 0)
    {
      tutorIndex = i;
      break;
    }
  }

  if (tutorIndex == -1)
  {
    printf("\nTutor não encontrado!\n");
    aguardarTecla();
    return;
  }

  printf("\nDigite o nome do pet a ser excluído: ");
  fgets(nomePet, sizeof(nomePet), stdin);
  nomePet[strcspn(nomePet, "\n")] = '\0';

  // Procurar pet dentro do tutor
  for (j = 0; j < tutores[tutorIndex].numPets; j++)
  {
    if (strcmp(tutores[tutorIndex].pets[j].nome, nomePet) == 0)
    {
      petIndex = j; //se encontrar um pet com o nome correspondente, salva seu índice (petIndex = j).


      break;
    }
  }

  if (petIndex == -1)//se continuar =-1, significa que não foi encontrado nenhum pet
  {
    printf("\nPet não encontrado!\n");
    aguardarTecla();
    return;
  }

  // Remover pet do array e ajustar os elementos seguintes
  for (j = petIndex; j < tutores[tutorIndex].numPets - 1; j++)
  //O loop começa em petIndex (posição do pet a ser excluído) e move os elementos seguintes uma posição para trás.


  {
    tutores[tutorIndex].pets[j] = tutores[tutorIndex].pets[j + 1];
  }

  // Atualizar quantidade de pets do tutor
  tutores[tutorIndex].numPets--;

  printf("\nPet excluído com sucesso!\n");
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
