#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_PETS 3
#define MAX_TUTORES 10


typedef struct {
  int id;
  char nome[50];
} Pet;

typedef struct {
  int id;
  char nome[50];
  Pet pets[MAX_PETS];
  int numPets;
} Tutor;



void limparTela() {
  #ifdef _WIN32
    system("cls");
  #else
    system("clear");
  #endif
}

void aguardarTecla() {
  printf("\nVolte ao meno precionando qualquer tecla");
  getchar();
}
void continuar() {
  printf("\nProssiga pressionando qualquer tecla");
  getchar();
}


void limparBuffer() {
  int c;
  while ((c = getchar()) != '\n' && c != EOF);
}

void exibirMenu() {
  printf("Menu de Pets:\n\n");
  printf("1 - Listar tutores\n");
  printf("2 - Cadastrar novo tutor\n");
  printf("3 - Atualizar tutor\n");
  printf("4 - Excluir tutor\n");
  printf("5 - Listar pets\n");
  printf("6 - Cadastrar novo pet\n");
  printf("7 - Atualizar pet\n");
  printf("8 - Excluir pet\n");
  printf("0 - Sair\n\n");
  printf("Escolha uma opção:");
}


void listarTutores(Tutor tutores[], int totalTutores) {
  if (totalTutores == 0) {
    printf("Nenhum tutor cadastrado.\n");
  } else {
    for (int i = 0; i < totalTutores; i++) {
      printf("ID: %d | Nome: %s | Pets: %d\n", tutores[i].id, tutores[i].nome, tutores[i].numPets);
    }
  }
  aguardarTecla();
}


void cadastrarTutor (Tutor tutores[], int *totalTutores) {
  if (*totalTutores >= MAX_TUTORES) {
    printf("Número máximo de tutores atingido.\n");
    aguardarTecla();
    return;
  }

  char nome[50];
  printf("Digite o nome do tutor: ");
  fgets(nome, sizeof(nome), stdin);
  nome[strcspn(nome, "\n")] = 0;

  for (int i = 0; i < *totalTutores; i++) {
    if (strcmp(tutores[i].nome, nome) == 0) {
      printf("Tutor já cadastrado.\n");
      aguardarTecla();
      return;
    }
  }

  Tutor novo;
  strcpy(novo.nome, nome);
  
  printf("digite o id do tutor:");
  scanf("%d" , &novo.id);
  
  printf("digite número de pets:");
  scanf("%d", &novo.numPets);
  
  if(novo.numPets > 0) {
      for(int i = 0;  i< novo.numPets; i++) {
          printf("digite o nome do pet número %d:", i+1);
          fgets(novo.pets[i].nome, sizeof(novo.pets[i].nome), stdin);
          novo.pets[i].nome[strcspn(novo.pets[i].nome, "\n")] = 0;
          getchar();
          limparTela();
          
          printf("digite o id do pet número %d", i+1);
          scanf("%d", &novo.pets[i].id);
          
          limparTela();
      }

  }
  
  
  tutores[*totalTutores] = novo;
  (*totalTutores)++;

  printf("Tutor cadastrado com sucesso!\n");
  aguardarTecla();
  limparTela();
}

void atualizarTutor(Tutor tutores[], int totalTutores) {
  char nome[50];
  printf("Digite o nome do tutor que deseja atualizar: ");
  fgets(nome, sizeof(nome), stdin);
  nome[strcspn(nome, "\n")] = 0;

  for (int i = 0; i < totalTutores; i++) {
    if (strcmp(tutores[i].nome, nome) == 0) {
      printf("Digite o novo nome: ");
      fgets(tutores[i].nome, sizeof(tutores[i].nome), stdin);
      tutores[i].nome[strcspn(tutores[i].nome, "\n")] = 0;
      
      printf("Tutor atualizado com sucesso.\n");
      aguardarTecla();
      return;
    }
  }

  printf("Tutor não encontrado.\n");
  aguardarTecla();
}

void excluirTutor(Tutor tutores[], int *totalTutores) {
  char nome[50];
  printf("Digite o nome do tutor que deseja excluir: ");
  fgets(nome, sizeof(nome), stdin);
  nome[strcspn(nome, "\n")] = 0;

  for (int i = 0; i < *totalTutores; i++) {
    if (strcmp(tutores[i].nome, nome) == 0) {
      for (int j = i; j < *totalTutores - 1; j++) {
        tutores[j] = tutores[j + 1];
      }
      (*totalTutores)--;
      printf("Tutor excluído com sucesso.\n");
      aguardarTecla();
      return;
    }
  }

  printf("Tutor não encontrado.\n");
  aguardarTecla();
}

void listarPets(Tutor tutores[], int totalTutores) {
  int nenhumPet = 1;
  for (int i = 0; i < totalTutores; i++) {
    for (int j = 0; j < tutores[i].numPets; j++) {
      printf("Tutor: %s | Pet ID: %d | Nome do Pet: %s\n",
             tutores[i].nome, tutores[i].pets[j].id, tutores[i].pets[j].nome);
      nenhumPet = 0;
    }
  }
  if (nenhumPet)
    printf("Nenhum pet cadastrado.\n");
  aguardarTecla();
}

void cadastrarPet(Tutor tutores[], int totalTutores) {
  char nomeTutor[50];
  printf("Digite o nome do tutor: ");
  fgets(nomeTutor, sizeof(nomeTutor), stdin);
  nomeTutor[strcspn(nomeTutor, "\n")] = 0;

  for (int i = 0; i < totalTutores; i++) {
    if (strcmp(tutores[i].nome, nomeTutor) == 0) {
      if (tutores[i].numPets >= MAX_PETS) {
        printf("Número máximo de pets atingido para este tutor.\n");
        aguardarTecla();
        return;
      }

      char nomePet[50];
      printf("Digite o nome do pet: ");
      fgets(nomePet, sizeof(nomePet), stdin);
      nomePet[strcspn(nomePet, "\n")] = 0;

      for (int j = 0; j < tutores[i].numPets; j++) {
        if (strcmp(tutores[i].pets[j].nome, nomePet) == 0) {
          printf("Pet já cadastrado para este tutor.\n");
          aguardarTecla();
          return;
        }
      }

      Pet novo;
      novo.id = tutores[i].numPets + 1;
      strcpy(novo.nome, nomePet);
      tutores[i].pets[tutores[i].numPets] = novo;
      tutores[i].numPets++;

      printf("Pet cadastrado com sucesso.\n");
      aguardarTecla();
      return;
    }
  }

  printf("Tutor não encontrado.\n");
  aguardarTecla();
}


void atualizarPet(Tutor tutores[], int totalTutores) {
  char nomePet[50];
  printf("Digite o nome do pet que deseja atualizar: ");
  fgets(nomePet, sizeof(nomePet), stdin);
  nomePet[strcspn(nomePet, "\n")] = 0;

  for (int i = 0; i < totalTutores; i++) {
    for (int j = 0; j < tutores[i].numPets; j++) {
      if (strcmp(tutores[i].pets[j].nome, nomePet) == 0) {
        printf("Digite o novo nome do pet: ");
        fgets(tutores[i].pets[j].nome, sizeof(tutores[i].pets[j].nome), stdin);
        tutores[i].pets[j].nome[strcspn(tutores[i].pets[j].nome, "\n")] = 0;
        printf("Pet atualizado com sucesso.\n");
        aguardarTecla();
        return;
      }
    }
  }

  printf("Pet não encontrado.\n");
  aguardarTecla();
}

void excluirPet(Tutor tutores[], int totalTutores) {
  char nomePet[50];
  printf("Digite o nome do pet que deseja excluir: ");
  fgets(nomePet, sizeof(nomePet), stdin);
  nomePet[strcspn(nomePet, "\n")] = 0;

  for (int i = 0; i < totalTutores; i++) {
    for (int j = 0; j < tutores[i].numPets; j++) {
      if (strcmp(tutores[i].pets[j].nome, nomePet) == 0) {
        for (int k = j; k < tutores[i].numPets - 1; k++) {
          tutores[i].pets[k] = tutores[i].pets[k + 1];
        }
        tutores[i].numPets--;
        printf("Pet excluído com sucesso.\n");
        aguardarTecla();
        return;
      }
    }
  }

  printf("Pet não encontrado.\n");
  aguardarTecla();
}

// MAIN
int main() {
  Tutor tutores[MAX_TUTORES];
  int totalTutores = 0;
  int opcao;

  do {
    limparTela();
    exibirMenu();
    scanf("%d", &opcao);
    limparBuffer();
    limparTela();

    switch (opcao) {
      case 1: listarTutores(tutores, totalTutores); 
          break;
      case 2: cadastrarTutor(tutores, &totalTutores); 
          break;
      case 3: atualizarTutor(tutores, totalTutores);     
          break;
      case 4: excluirTutor(tutores, &totalTutores); 
          break;
      case 5: listarPets(tutores, totalTutores); 
          break;
      case 6: cadastrarPet(tutores, totalTutores); 
          break;
      case 7: atualizarPet(tutores, totalTutores); 
          break;
      case 8: excluirPet(tutores, totalTutores); 
          break;
      case 0: printf("Encerrando o programa...\n"); 
          break;
      default: printf("Opção inválida!\n"); 
          aguardarTecla();
          break;
    }
  } while (opcao != 0);

  return 0;
}