#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_PETS 3
#define MAX_TUTORES 10

typedef struct {
  int id;
  char nome[20];
} Pet;

typedef struct {
  char cpf[12];
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

void limparBuffer() {
  int c;
  while ((c = getchar()) != '\n' && c != EOF);
}

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

void listarTutores(Tutor tutores[], int totalTutores) {
  printf("*****Lista de Tutores*****\n\n");

  if(totalTutores==0){
    printf("Não possui nenhum Tutor cadastrado!\n");
  }else{ 

    for(int i=0; i<totalTutores; i++){

      printf("Nome: %s\n", tutores[i].nome);
      printf("CPF: %s\n", tutores[i].cpf);
        
    }
        
  }
  aguardarTecla();
}


void cadastrarTutor(Tutor *tutores, int *totalTutores) {
  printf("*****Cadastro de Tutor*****\n\n");
    
  if(*totalTutores>=MAX_TUTORES){
    printf("Número máximo de Tutores atingidos!\n");
    aguardarTecla();
    return;
  }

  char novoNome[20];
  printf("Digite o nome do tutor: ");
  fgets(novoNome,sizeof(novoNome), stdin);
  novoNome[strcspn(novoNome, "\n")]= '\0';

  for(int i=0;i<*totalTutores; i++){
      
    if(strcmp(tutores[i].nome, novoNome) == 0){
      printf("Esse nome já foi cadastrado!\n");
      aguardarTecla();
      return;
    }
  }

  strcpy(tutores[*totalTutores].nome, novoNome);

  printf("Digite o CPF do tutor(somente números): ");
  fgets(tutores[*totalTutores].cpf,sizeof(tutores[*totalTutores].cpf),stdin);
  tutores[*totalTutores].cpf[strcspn(tutores[*totalTutores].cpf, "\n")] = '\0'; 

  (*totalTutores)++; 

  printf("\nTutor cadastrado com sucesso!\n");

  aguardarTecla();
}


void atualizarTutor(Tutor *tutores, int totalTutores){
  printf("*****Atualizar Tutor*****\n\n");

  if(totalTutores == 0){
    printf("Não possui nenhum Tutor cadastrado!\n");
    aguardarTecla();
    return;
  }

  char nomeNovo[20];
  char nomeBusca[20];
 
  printf("Digite um nome: ");
  fgets(nomeBusca,sizeof(nomeBusca),stdin);
  nomeBusca[strcspn(nomeBusca, "\n")]= '\0';
  

  int encontrado=0;


  for(int i=0;i<totalTutores; i++){

    if(strcmp(tutores[i].nome, nomeBusca) == 0){

      encontrado=1;
      

      printf("Digite um novo nome: ");
      
      fgets(nomeNovo,sizeof(nomeNovo),stdin);
      nomeNovo[strcspn(nomeNovo, "\n")]= '\0';
      strcpy(tutores[i].nome, nomeNovo);
      
      printf("Digite um novo CPF: ");
      fgets(tutores[i].cpf,sizeof(tutores[i].cpf),stdin);
      tutores[i].cpf[strcspn(tutores[i].cpf, "\n")] = '\0';

      printf("Dados atualizados com sucesso!\n");
      aguardarTecla();
      return;
    }
  }
  
  if(encontrado == 0){
  printf("Esse nome não existe!\n");
  aguardarTecla();
  return;
  }
}


void excluirTutor(Tutor *tutores, int *totalTutores) {
  printf("*****Excluir Tutor*****\n\n");

  if(*totalTutores==0){
    printf("Não possui nenhum Tutor cadastrado!\n");
    aguardarTecla();
    return;
  }

  char sim[4];
  char nomeBusca[20];
  printf("Digite um nome: ");
  fgets(nomeBusca,sizeof(nomeBusca),stdin);
  nomeBusca[strcspn(nomeBusca, "\n")]= '\0';
  
  int encontrado=0;

  for(int i=0;i<*totalTutores; i++){

    if(strcmp(tutores[i].nome, nomeBusca) == 0){

      encontrado=1;

      printf("Você deseja excluir o tutor %s ?(S/N)\n", nomeBusca);
      fgets(sim, sizeof(sim), stdin);
      sim[strcspn(sim, "\n")] = '\0';

      if(strcmp(sim, "s") == 0 || strcmp(sim, "S") == 0 ){

        for(int j=i;j<(*totalTutores)-1;j++){
          tutores[j]=tutores[j+1];
        }
        (*totalTutores)--;

        printf("Tutor excluido com sucesso!\n");
        aguardarTecla();
        return;
 
      }else{
        printf("Ação cancelada!\n");
        aguardarTecla();
        return;
      }
    }
  }
  
  
  if(encontrado == 0){
  printf("Esse nome não existe!\n");
  aguardarTecla();
  return;
  }
  
}


void listarPets(Tutor tutores[], int totalTutores) {
  printf("*****Lista de Pets*****\n\n");
  
  int temPets = 0;
  for (int i = 0; i < totalTutores; i++) {
    if (tutores[i].numPets > 0) {
      printf("Tutor: %s\n", tutores[i].nome);
      for (int j = 0; j < tutores[i].numPets; j++) {
        printf("  Pet %d: %s (ID:%d)\n", j+1, tutores[i].pets[j].nome, tutores[i].pets[j].id);
      }
      temPets = 1;
    }
  }

  if (!temPets) {
    printf("Nenhum pet cadastrado ainda.\n");
  }

  aguardarTecla();
}


void cadastrarPet(Tutor tutores[], int totalTutores) {
  printf("*****Cadastrar Pet*****\n\n");

  if(totalTutores == 0){
    printf("Nenhum tutor cadastrado ainda.\n");
    aguardarTecla();
    return;
  }

  char nomeTutor[20];
  printf("Digite o nome do tutor para associar os pets: ");
  fgets(nomeTutor, sizeof(nomeTutor), stdin);
  nomeTutor[strcspn(nomeTutor, "\n")] = '\0';

  for(int i = 0; i < totalTutores; i++) {
    if(strcmp(tutores[i].nome, nomeTutor) == 0) {
      if(tutores[i].numPets >= MAX_PETS) {
        printf("Este tutor já possui o número máximo de pets!\n");
        aguardarTecla();
        return;
      }

      int qtd;
      printf("Quantos pets deseja cadastrar (máx: %d)? ", MAX_PETS - tutores[i].numPets);
      scanf("%d", &qtd);
      limparBuffer();

      if(qtd + tutores[i].numPets > MAX_PETS) {
        printf("Número total de pets excede o limite permitido.\n");
        aguardarTecla();
        return;
      }

      for(int j = 0; j < qtd; j++) {
        printf("Digite o nome do pet: ");
        fgets(tutores[i].pets[tutores[i].numPets].nome, sizeof(tutores[i].pets[tutores[i].numPets].nome), stdin);
        tutores[i].pets[tutores[i].numPets].nome[strcspn(tutores[i].pets[tutores[i].numPets].nome, "\n")] = '\0';
        tutores[i].pets[tutores[i].numPets].id = tutores[i].numPets + 1;
        tutores[i].numPets++;
      }

      printf("Pets cadastrados com sucesso!\n");
      aguardarTecla();
      return;
    }
  }

  printf("Tutor não encontrado.\n");
  aguardarTecla();
}


void atualizarPet(Tutor tutores[], int totalTutores) {
  printf("*****Atualizar Pet*****\n\n");

  if(totalTutores == 0) {
    printf("Nenhum tutor cadastrado.\n");
    aguardarTecla();
    return;
  }

  char nomeTutor[50];
  printf("Digite o nome do tutor: ");
  fgets(nomeTutor, sizeof(nomeTutor), stdin);
  nomeTutor[strcspn(nomeTutor, "\n")] = '\0';

  for (int i = 0; i < totalTutores; i++) {
    if (strcmp(tutores[i].nome, nomeTutor) == 0) {
      if (tutores[i].numPets == 0) {
        printf("Esse tutor não possui pets cadastrados.\n");
        aguardarTecla();
        return;
      }

      printf("Pets do tutor %s:\n", tutores[i].nome);
      for (int j = 0; j < tutores[i].numPets; j++) {
        printf("  Pet %d: %s (ID: %d)\n", j + 1, tutores[i].pets[j].nome, tutores[i].pets[j].id);
      }

      char nomePet[20];
      printf("Digite o nome do pet a ser atualizado: ");
      fgets(nomePet, sizeof(nomePet), stdin);
      nomePet[strcspn(nomePet, "\n")] = '\0';

      for (int j = 0; j < tutores[i].numPets; j++) {
        if (strcmp(tutores[i].pets[j].nome, nomePet) == 0) {
          char novoNome[20];
          printf("Digite o novo nome do pet: ");
          fgets(novoNome, sizeof(novoNome), stdin);
          novoNome[strcspn(novoNome, "\n")] = '\0';

          strcpy(tutores[i].pets[j].nome, novoNome);

          printf("Pet atualizado com sucesso!\n");
          aguardarTecla();
          return;
        }
      }

      printf("Pet não encontrado.\n");
      aguardarTecla();
      return;
    }
  }

  printf("Tutor não encontrado.\n");
  aguardarTecla();
}


void excluirPet(Tutor tutores[], int totalTutores) {
  printf("*****Excluir Pet*****\n\n");

  if(totalTutores == 0){
    printf("Nenhum tutor cadastrado ainda.\n");
    aguardarTecla();
    return;
  }

  char nomeTutor[50];
  printf("Digite o nome do tutor: ");
  fgets(nomeTutor, sizeof(nomeTutor), stdin);
  nomeTutor[strcspn(nomeTutor, "\n")] = '\0';

  for(int i = 0; i < totalTutores; i++) {
    if(strcmp(tutores[i].nome, nomeTutor) == 0) {
      if(tutores[i].numPets == 0) {
        printf("Esse tutor não possui pets cadastrados.\n");
        aguardarTecla();
        return;
      }

      char nomePet[20];
      printf("Digite o nome do pet a ser excluído: ");
      fgets(nomePet, sizeof(nomePet), stdin);
      nomePet[strcspn(nomePet, "\n")] = '\0';

      for(int j = 0; j < tutores[i].numPets; j++) {
        if(strcmp(tutores[i].pets[j].nome, nomePet) == 0) {
          for(int k = j; k < tutores[i].numPets - 1; k++) {
            tutores[i].pets[k] = tutores[i].pets[k + 1];
          }
          tutores[i].numPets--;
          printf("Pet excluído com sucesso!\n");
          aguardarTecla();
          return;
        }
      }

      printf("Pet não encontrado.\n");
      aguardarTecla();
      return;
    }
  }

  printf("Tutor não encontrado.\n");
  aguardarTecla();
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
      excluirPet(tutores, totalTutores);
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