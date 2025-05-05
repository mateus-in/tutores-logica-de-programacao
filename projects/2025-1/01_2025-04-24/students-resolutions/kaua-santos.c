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
  printf("\nPressione qualquer tecla para voltar ao menu...");
  getchar();
}
void continuar() {
  printf("\nPressione qualquer tecla para prosseguir...");
  getchar();
}


void limparBuffer() {
  int c;
  while ((c = getchar()) != '\n' && c != EOF);
}

void exibirMenu() {
  limparTela();
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


void listarTutores(Tutor tutores[], int totalTutores) {
  limparTela();
  if (totalTutores == 0) {
    printf("Nenhum tutor cadastrado.\n");
  } else {
    for (int i = 0; i < totalTutores; i++) {
      printf("ID: %d\n | Nome: %s\n | Pets: %d\n", tutores[i].id, tutores[i].nome, tutores[i].numPets);
      printf("\n");
    }
  }
  aguardarTecla();
}


void cadastrarTutor (Tutor tutores[], int *totalTutores) {
  limparTela();
  if (*totalTutores >= MAX_TUTORES) {
    printf("Número máximo de tutores atingido.\n");
    aguardarTecla();
    limparTela();
    return;
  }

  char nome[50];
  printf("Digite o nome do tutor: ");
  fgets(nome, sizeof(nome), stdin);
  nome[strcspn(nome, "\n")] = 0;

  for (int i = 0; i < *totalTutores; i++) {
    if (strcmp(tutores[i].nome, nome) == 0) {
      printf("Tutor já cadastrado.\n");
      limparTela();
      aguardarTecla();
      return;
    }
  }

  Tutor novo;
  strcpy(novo.nome, nome);
  
  printf("digite o id do tutor:");
  scanf("%d" , &novo.id);
  limparBuffer();
  int numero;
  for(int k=0;k<3;k++) {
      if(novo.id == tutores[k].id){
         printf("Outro tutor já possui esse Id");
         aguardarTecla();
         limparTela();
         return;
      }
     
  }
  
  tutores[*totalTutores] = novo;
  (*totalTutores)++;
  
  limparTela();
  
  
  printf("digite se ele possui pet: \n 1.Sim \n 2.Não \n Resposta: ");
  scanf(" %d", &numero);
  limparBuffer();
  limparTela();
  
  if(numero == 1 ) {
      for (int i = 0; i < *totalTutores; i++) {
        if (strcmp(tutores[i].nome, novo.nome) == 0) {
        
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
      
          printf("digite o id do pet:");
          scanf("%d" , &novo.id);
          limparBuffer();
          
          for(int k=0;k<3;k++) {
              for(int l=0; l<3; l++) {
                  if(novo.id == tutores[k].pets[l].id){
                      printf("Outro pet já possui esse Id");
                      aguardarTecla();
                      limparTela();
                      return;
                  }
              }
          }
      
      
          strcpy(novo.nome, nomePet);
          tutores[i].pets[tutores[i].numPets] = novo;
          tutores[i].numPets++;
          limparTela();

          printf("Pet cadastrado com sucesso.\n");
          getchar();
        }
      }
  } 

  printf("Tutor cadastrado com sucesso!\n");
  getchar();
  aguardarTecla();
  limparTela();
}

void atualizarTutor(Tutor tutores[], int totalTutores) {
  int numero;
  printf("digite se deseja atualizar o Tutor por: \n 1.nome \n 2.id \n Resposta: ");
  scanf(" %d", &numero);
  limparBuffer();
  limparTela();
  
  if(numero == 1 ) {
      char nome[50];
      printf("Digite o nome do tutor que deseja atualizar: ");
      fgets(nome, sizeof(nome), stdin);
      nome[strcspn(nome, "\n")] = 0;
  
   for (int i = 0; i < totalTutores; i++) {
     if (strcmp(tutores[i].nome, nome) == 0) {
      printf("Digite o novo nome: ");
      fgets(tutores[i].nome, sizeof(tutores[i].nome), stdin);
      tutores[i].nome[strcspn(tutores[i].nome, "\n")] = 0;
      for (int u = 0; u < totalTutores; u++) {
          if (strcmp(tutores[u].nome, nome) == 0) {
              printf("Tutor já cadastrado.\n");
              limparTela();
              aguardarTecla();
              return;
          }
      }
    
  
      Tutor novo;
      
      printf("Digite o novo id:");
      scanf("%d", & novo.id);
      void limparBuffer();
      
      for(int k=0;k<3;k++) {
       if(novo.id == tutores[k].id){
         printf("Outro tutor já possui esse Id");
         aguardarTecla();
         limparTela();
         return;
       }
      }
      
      tutores[i].id= novo.id;
      
      printf("Tutor atualizado com sucesso.\n");
      getchar();
      aguardarTecla();
      limparTela();
      return;
    }
    
   } 

   printf("Tutor não encontrado.\n");
   aguardarTecla();
 } else if(numero==2) {
     int id;
     printf("Digite o Id do tutor que deseja atualizar: ");
     scanf("%d",&id);
     limparBuffer();
     limparTela();
     
     for (int i = 0; i < totalTutores; i++) {
        if (tutores[i].id == id) {
          char nome[50];
          printf("Digite o novo nome: ");
          fgets(tutores[i].nome, sizeof(tutores[i].nome), stdin);
          tutores[i].nome[strcspn(tutores[i].nome, "\n")] = 0;
          for (int u = 0; u < totalTutores; u++) {
              if (strcmp(tutores[u].nome, nome) == 0) {
               printf("Tutor já cadastrado.\n");
               limparTela();
               aguardarTecla();
               return;
             }
          }
          
          
         Tutor novo;
         printf("Digite o novo id:");
         scanf("%d", &novo.id);
         limparBuffer();
      
         for(int k=0;k<3;k++) {
          if(novo.id == tutores[k].id){
             printf("Outro tutor já possui esse Id");
             aguardarTecla();
             limparTela();
             return;
          }
         }
         tutores[i].id= novo.id;
      
         printf("Tutor atualizado com sucesso.\n");
         getchar();
         aguardarTecla();
         limparTela();
         return;
        }
     }
     printf("Tutor não encontrado.\n");
     aguardarTecla();
 }
        
 
}
      


void excluirTutor(Tutor tutores[], int *totalTutores) {
  int id;
  int numero;
  printf("digite se deseja atualizar o Tutor por: \n 1.id \n 2.nome \n Resposta: ");
  scanf(" %d", &numero);
  limparBuffer();
  limparTela();
  
 if(numero ==1){
  printf("Digite o id do tutor que deseja excluir: ");
  scanf("%d",&id);

  for (int i = 0; i < *totalTutores; i++) {
    if (tutores[i].id == id) {
      for (int j = i; j < *totalTutores - 1; j++) {
        tutores[j] = tutores[j + 1];
      }
      (*totalTutores)--;
      printf("Tutor excluído com sucesso.\n");
      aguardarTecla();
      limparTela();
      return;
    }
    
    printf("Tutor não encontrado.\n");
    aguardarTecla();
    limparTela();
   return;
  } 
 }else if (numero==2) {
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
      limparTela();
      return;
    }
   
   }
   printf("Tutor não encontrado.\n");
   aguardarTecla();
   limparTela();
   return;
 } else {
       printf("opção invalida");
       limparTela();
       return;
 }

   
  
}
  


void listarPets(Tutor tutores[], int totalTutores) {
  int nenhumPet = 1;
  for (int i = 0; i < totalTutores; i++) {
    for (int j = 0; j < tutores[i].numPets; j++) {
      printf("Tutor: %s\n | Pet ID: %d\n | Nome do Pet: %s\n", tutores[i].nome, tutores[i].pets[j].id, tutores[i].pets[j].nome);
      printf("\n");
      nenhumPet = 0;
    }
  }
  if (nenhumPet)
    printf("Nenhum pet cadastrado.\n");
  aguardarTecla();
  limparTela();
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
        limparTela();
        
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
          limparTela();
          return;
        }
      }

      Pet novo;
      
      printf("digite o id do pet:");
      scanf("%d" , &novo.id);
      limparBuffer();
      
      for(int k=0;k<3;k++) {
          for(int l=0; l<3; l++) {
              if(novo.id == tutores[k].pets[l].id){
              printf("Outro pet já possui esse Id");
              aguardarTecla();
              limparTela();
              return;
              }
          }
      }
      getchar();
      strcpy(novo.nome, nomePet);
      tutores[i].pets[tutores[i].numPets] = novo;
      tutores[i].numPets++;
      
      limparTela();
      printf("Pet cadastrado com sucesso.\n");
      aguardarTecla();
      
      return;
    }
  }

  printf("Tutor não encontrado.\n");
  getchar();
  limparTela();
  aguardarTecla();
}


void atualizarPet(Tutor tutores[], int totalTutores) {
  char nome[50];
  printf("Digite o nome do tutor que deseja atualizar o pet: ");
  fgets(nome, sizeof(nome), stdin);
  nome[strcspn(nome, "\n")] = 0;

  for (int i = 0; i < totalTutores; i++) {
   if(strcmp(tutores[i].nome, nome)== 0){
    for (int j = 0; j < tutores[i].numPets; j++) {
        char nomepet[50];
        
      printf("Digite o nome do pet que sera atualizado: ");
      fgets(nomepet, sizeof(nomepet), stdin);
      nomepet[strcspn(nomepet, "\n")] = 0;
        
      if (strcmp(tutores[i].pets[j].nome, nomepet) == 0) {
        printf("Digite o novo nome do pet: ");
        fgets(tutores[i].pets[j].nome, sizeof(tutores[i].pets[j].nome), stdin);
        tutores[i].pets[j].nome[strcspn(tutores[i].pets[j].nome, "\n")] = 0;
        
        for (int w = 0; w < tutores[i].numPets; w++) {
         if (strcmp(tutores[i].pets[w].nome, nomepet) == 0) {
          printf("Pet já cadastrado para este tutor.\n");
          aguardarTecla();
          limparTela();
          return;
         }
        }
        Pet novo;
        printf("digite o novo id do pet: ");
        scanf("%d",&tutores[i].pets[j].id);
        limparBuffer();
        
        for(int k=0;k<3;k++) {
          for(int l=0; l<3; l++) {
              if(novo.id == tutores[k].pets[l].id){
              printf("Outro pet já possui esse Id");
              aguardarTecla();
              limparTela();
              return;
              }
          }
        }
        
        printf("Pet atualizado com sucesso.\n");
        limparTela();
        aguardarTecla();
        return;
      }
    }
   }
  }

  printf("Pet não encontrado.\n");
  getchar ();
  limparTela();
  aguardarTecla();
}

void excluirPet(Tutor tutores[], int totalTutores) {
  char nome[50];
  printf("Digite o nome do tutor que deseja atualizar o pet: ");
  fgets(nome, sizeof(nome), stdin);
  nome[strcspn(nome, "\n")] = 0;

 for (int i = 0; i < totalTutores; i++) {
  if(strcmp(tutores[i].nome, nome)== 0){
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
        getchar();
        aguardarTecla();
        limparTela();
        return;
      }
    }
   }
  }
  printf("Pet não encontrado.\n");
  limparTela();
  aguardarTecla();
 }

}
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
          excluirPet(tutores, totalTutores); 
          break;
      case 0:
          printf("Encerrando o programa...\n"); 
          break;
      default:
           printf("Opção inválida!\n"); 
          aguardarTecla();
          break;
    }
  } while (opcao != 0);

  return 0;
}