#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_PETS 3
#define MAX_TUTORES 10

int quantidadeTutores = 0;
int quantidadePets = 0;

// Definição da struct Pet
typedef struct {
  int id;
  char nome[50];
} Pet;
Pet pets[MAX_PETS];

// Definição da struct Tutor
typedef struct {
  int id;
  char nome[50];
  Pet pets[MAX_PETS];
  int numPets;
} Tutor;
Tutor tutores[MAX_TUTORES];

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
  printf("\nPressione Enter para voltar ao menu...");
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
  printf("*****Gestao de Pets*****\n\n");
  printf("1 - Listar os tutores cadastrados\n");
  printf("2 - Cadastrar um novo tutor\n");
  printf("3 - Atualizar um tutor cadastrado\n");
  printf("4 - Excluir um tutor cadastrado\n");
  printf("5 - Listar os pets cadastrados\n");
  printf("6 - Cadastrar um novo pet\n");
  printf("7 - Atualizar um pet cadastrado\n");
  printf("8 - Excluir um pet cadastrado\n");
  printf("0 - Sair\n\n");
  printf("Escolha uma opcao: ");
}

/*
  Função para listar os tutores cadastrados
  Essa função deve percorrer o array de tutores e exibir os dados de cada um.
  Se não houver tutores cadastrados, deve exibir uma mensagem informando isso.
*/
void listarTutores() {
  //"Titulo"
  printf("*****Listar Tutores*****\n\n");

  if(quantidadeTutores == 0){
    printf("Nenhum Tutor cadastrado.\n");
  }else{
    printf("---Listar Tutores---\n");

    for(int i = 0; i < quantidadeTutores; i++){
      printf("ID: %d\n", tutores[i].id);
      printf("Nome: %s\n", tutores[i].nome);
      printf("Numero de Pets: %d\n", tutores[i].numPets);
    }
  }

  aguardarTecla();
}

/*
  Função para cadastrar um novo tutor
  Essa função deve solicitar os dados do tutor (nome, pets, etc.) e armazená-los no array de tutores.
  Deve verificar se o número máximo de tutores foi atingido antes de cadastrar um novo.
  Não deve permitir cadastrar um tutor com o mesmo nome de outro já cadastrado.
*/
void cadastrarTutor() {
//"Titulo"
  printf("*****Cadastrar Tutor*****\n\n");

  if(quantidadeTutores >= MAX_TUTORES){
  printf("***Erro*** Numero maximo de tutore atingido.\n");
  aguardarTecla();
  return; 
  }

  char novoTutor[50];
  int novoId;

//Nome do novo tutor

  printf("Digite o nome do novo tutor: ");
  fgets(novoTutor, sizeof(novoTutor), stdin);
  novoTutor[strcspn(novoTutor, "\n")] = '\0';

//ID do novo tutor

  printf("Digite o novo Id do respectivo tutor: ");
  scanf("%d", &novoId);
  limparBuffer();
  

  //ver se existe 2 tutores com msm nome
  for(int i = 0; i < quantidadeTutores; i++){
    if(strcmp(tutores[i].nome, novoTutor) == 0 || tutores[i].id == novoId){
      printf("Ja existe um tutor com esse nome ou ID.\n");
      aguardarTecla();
      return;
    }
  }
Tutor novo;
novo.id = novoId; //Adiciona ID  a um tutor
strcpy(novo.nome, novoTutor);
novo.numPets = 0;

//Array
tutores[quantidadeTutores++] = novo;

//finalizando
printf("\n***Novo Tutor cadastrado com sucesso***\n");

aguardarTecla();

}

/*
  Função para atualizar um tutor cadastrado
  Essa função deve solicitar o nome do tutor a ser atualizado e os novos dados (nome, pets, etc.).
  Deve verificar se o tutor existe antes de tentar atualizá-lo.
  Se o tutor não existir, deve exibir uma mensagem informando isso.
*/
void atualizarTutor() {
//"Titulo"
  printf("*****Atualizar Tutor*****\n\n");

  //Vê se tem algum tutor cadastrado para atualizar
  if(quantidadeTutores == 0){
    printf("Nenum Tutor cadastrado para atualizar.\n");
    aguardarTecla();
    return;
  }

  //Verifica o tutor para atualizar pelo ID
  int atualizarID;
  printf("Digite o ID do Tutor que deseja atualizar: ");
  scanf("%d", &atualizarID);
  limparBuffer();

  //"Contador de tutores"
  int indicetutor = -1;

  //Procura tutor pelo ID
  for(int i = 0; i < quantidadeTutores; i++){
    if(tutores[i].id == atualizarID){
      indicetutor = i;
      break;
    }
  }

  //Se não encontrar tutor
  if(indicetutor == -1){
    printf("Tutor com ID: %d nao encontrado.\n", atualizarID);
    aguardarTecla();
    return;
  }

  //Mostrar se o tutor for encontrado
  printf("Tutor encontrado: %s\n", tutores[indicetutor].nome);

  //Cadastrar novo tutor
  char novoNome[50];
  printf("Digite o novo nome do tutor (Se apertar Enter mantera o nome atual): ");
  fgets(novoNome, sizeof(novoNome), stdin);
  novoNome[strcspn(novoNome, "\n")] = '\0'; //Para remover o \n

  //Manter nome atual se apertar enter
  if(strlen(novoNome) == 0){
    printf("Nome mantido: %s\n", tutores[indicetutor].nome);
  }else{

//Verifica se ja existe um tutor com o mesmo nome
for(int i = 0; i < quantidadeTutores; i++){
  if(i != indicetutor && strcmp(tutores[i].nome, novoNome) == 0){
    printf("Ja existe um tutor com esse nome.\n");
    aguardarTecla();
    return;
  }
}
  //Mostra que o nome foi atualizado
  strcpy(tutores[indicetutor].nome, novoNome);
  printf("Nome atualizado com sucesso!!\n");
  }
  
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
//"Titulo"
  printf("*****Excluir Tutor*****\n\n");

  //Verifica se existe algum tutor para excluir
  if(quantidadeTutores == 0){
    printf("Nenum tutor cadastrado.\n");
    printf("Precisa cadastrar um tutor primeiro, antes de tentar excluir.\n");
    aguardarTecla();
    return;
  }

  //Encontra o tutor para excluir pelo ID
  int excluirID;
  printf("Digite o ID do Tutor que deseja excluir: ");
  scanf("%d", &excluirID);
  limparBuffer();
  
  //Variáveis locais
  int indicetutor = -1;

  for(int i = 0; i < quantidadeTutores; i++){
    if(tutores[i].id == excluirID){
      indicetutor = i;
      break;
    }
  }

  //Se não encontrar tutor
  if(indicetutor == -1){
    printf("Tutor com ID: %d nao encontrado.\n", excluirID);
    aguardarTecla();
    return;
  } 

  //Mostrar tutor encontrado
    printf("Tutor encontrado:%s\n", tutores[indicetutor].nome);
    printf("Id: %d \n", tutores[indicetutor].id);
    printf("Numero de Pets: %d\n", tutores[indicetutor].numPets);
    

//Confirma se realmente é para excluir o tutor
  char confirmacao;
  
  printf("Realmente deseja excluir esse tutor? (S/N): \n");
  scanf(" %c", &confirmacao);
  limparBuffer();
//Se Sim excuir tutor
  if(confirmacao == 'S' || confirmacao == 's'){  
    tutores[indicetutor].id = 0;  
    tutores[indicetutor].numPets = 0;
    tutores[indicetutor].nome[0] = '\0';

    printf("Tutor excluido com sucesso!!\n");
//Se Não voltar ao menu
  }else{
    printf("\nOperação cancelada.\n");
  }

  aguardarTecla();
}
/*
  Função para listar os pets cadastrados
  Essa função deve percorrer o array de tutores e exibir os dados dos pets de cada um.
  Se não houver pets cadastrados, deve exibir uma mensagem informando isso.
*/
void listarPets() {
//"Titulo"
  printf("*****Listar Pets*****\n\n");

  int nenhumPet = 1;
//Verifica se existe algum pet cadastrado
  for(int i = 0; i < quantidadeTutores; i++){
    if(tutores[i].id != 0 && tutores[i].numPets > 0){
      printf("\n-Tutor: %s\n -Id: %d", tutores[i].nome, tutores[i].id);
//Exibe os pets cadastrados
      for(int j = 0; j < tutores[i].numPets; j++){
        printf("\n\n-Pet %d: %s\n -Id: %d", j + 1, tutores[i].pets[j].nome, tutores[i].pets[j].id);
      }
      nenhumPet = 0;
    }
  }if(nenhumPet == 1){
    printf("Nenhum Pet cadastrado.\n");
  }
    
  aguardarTecla();
}

/*
  Função para cadastrar um novo pet
  Essa função deve solicitar os dados do pet (nome, tutor, etc.) e armazená-los no array de pets.
  Deve verificar se o número máximo de pets foi atingido antes de cadastrar um novo.
  Não deve permitir cadastrar um pet com o mesmo nome de outro já cadastrado.
*/
void cadastrarPet() {
//"Titulo"
  printf("*****Cadastrar Pet*****\n\n");

  //Verifica se existe um tutor cadastrado
  if(quantidadeTutores == 0){
    printf("Nenum tutor cadastrado.\n");
    printf("Antes de cadastrar um Pet e necessario cadastrar um Tutor.\n");
    aguardarTecla();
    return;
  }

  //Pede o id do tutor para associa-lo ao Pet
  int tutorID;
  printf("Digite o Id do tutor para associar ao Pet: ");
  scanf("%d", &tutorID);
  limparBuffer();

  //Procura tutor pelo ID
  int indicetutor = -1;
  for(int i = 0; i < quantidadeTutores; i++){
    if(tutores[i].id == tutorID){
    indicetutor = i;
    break;
  }

  }if(indicetutor == -1){
    printf("Tutor com ID: %d nao encontrado.\n", tutorID);
    aguardarTecla();
    return;
  }

//Verifica se o tutor ja possui o maximo de pets cadastrados
  if(tutores[indicetutor].numPets == MAX_PETS){
    printf("Tutor: %s, com Id: %d, ja possui o maximo de pets cadastrados.\n", tutores[indicetutor].nome, tutores[indicetutor].id);
    aguardarTecla();
    return;
  }

//Cadastrar Pet
char novonome_Pet[50];
  printf("Digite o nome do Pet: ");
  fgets(novonome_Pet, sizeof(novonome_Pet), stdin);
  novonome_Pet[strcspn(novonome_Pet, "\n")] = '\0';

  printf("Digite o Id do respectivo Pet: ");
  int novoId_pet;
  scanf("%d", &novoId_pet);
  limparBuffer();

//Verifica se ja existe um pet com mesmo nome ou ID
  for(int i = 0; i < quantidadeTutores; i++){
    for(int j = 0; j < tutores[i].numPets; j++){
      if(strcmp(tutores[i].pets[j].nome, novonome_Pet) == 0 || tutores[i].pets[j].id == novoId_pet){
        printf("Ja existe um Pet com o mesmo nome ou ID cadastrado.\n");
      
      aguardarTecla();
      return;
    }
  }
}
//Associar novo pet ao tutor
Pet novoPet;
novoPet.id = novoId_pet;
strcpy(novoPet.nome, novonome_Pet);

tutores[indicetutor].pets[tutores[indicetutor].numPets] = novoPet;
tutores[indicetutor].numPets++;

  printf("Novo Pet cadastrado com sucesso.\n");
  aguardarTecla();
}

/*
  Função para atualizar um pet cadastrado
  Essa função deve solicitar o nome do pet a ser atualizado e os novos dados (nome, tutor, etc.).
  Deve verificar se o pet existe antes de tentar atualizá-lo.
  Se o pet não existir, deve exibir uma mensagem informando isso.
*/
void atualizarPet() {
//"Titulo"
   printf("*****Atualizar Pet*****\n\n");

   // Verifica se tem um Pet cadastrado
   int tempPet = 0;
   for (int i = 0; i < quantidadeTutores; i++) {
     if (tutores[i].numPets > 0) {
       tempPet = 1;
       break;
     }
   }
 
   //Verifica se tem algum pet cadastrado e avisa
   if (!tempPet) {
     printf("Nao tem nenhum pet cadastrado.\n");
     aguardarTecla();
     return;
   }
 
   // Solicita o nome do pet a ser atualizado
   char nomePet[50];
   printf("Digite o nome do Pet para atualizar: ");
   fgets(nomePet, sizeof(nomePet), stdin);
   nomePet[strcspn(nomePet, "\n")] = '\0';
 
   int encontrado = 0;
 
   // Procura o pet
   for (int i = 0; i < quantidadeTutores; i++) {
     for (int j = 0; j < tutores[i].numPets; j++) {
       if (strcmp(tutores[i].pets[j].nome, nomePet) == 0) {
         encontrado = 1;
 
         printf("Pet %s, encontrado.\n", tutores[i].pets[j].nome);
 
//Pede o novo nome do pet  
   char novoNome[50];
    printf("Digite o novo nome do Pet: ");
    fgets(novoNome, sizeof(novoNome), stdin);
  novoNome[strcspn(novoNome, "\n")] = '\0';
 
    if (strlen(novoNome) > 0) {
      strcpy(tutores[i].pets[j].nome, novoNome);
}
 
//Pede o novo ID do pet
  int novoIdPet;
    printf("Digite o novo ID do Pet: ");
    scanf("%d", &novoIdPet);
    limparBuffer();
 
//Verifica se outro pet ja possui esse ID
  int idRepetido = 0;
    for (int x = 0; x < quantidadeTutores; x++) {
      for (int y = 0; y < tutores[x].numPets; y++) {
        if (tutores[x].pets[y].id == novoIdPet && (x != i || y != j)) {
          idRepetido = 1;
            break;
             }

    }if (idRepetido) break;
         }
 
    if (idRepetido) {
       printf("Ja existe um Pet com esse ID cadastrado. Atualizacao cancelada.\n");
        aguardarTecla();   
        return;     
      }     
 
  tutores[i].pets[j].id = novoIdPet;
 
        printf("Pet atualizado com sucesso.\n");
      aguardarTecla();
      return;
       }
     }
   }
 
   if (!encontrado) {
     printf("Pet nao encontrado.\n");
     aguardarTecla();
   }
 }

/*
  Função para excluir um pet cadastrado
  Essa função deve solicitar o nome do pet a ser excluído.
  Deve verificar se o pet existe antes de tentar excluí-lo.
  Se o pet não existir, deve exibir uma mensagem informando isso.
*/
void excluirPet() {
  printf("*****Excluir Pet*****\n\n");

// Verifica se tem algum pet cadastrado
  int temPet = 0;
  for (int i = 0; i < quantidadeTutores; i++) {
    if (tutores[i].numPets > 0) {
      temPet = 1;
      break;
    }
  }

// Se não tem pets cadastrados avisa
  if (!temPet) {
    printf("Nao tem nenhum pet cadastrado.\n");
    aguardarTecla();
    return;
  }

//Pede nome do Pet
  char nomePet[50];
  printf("Digite o nome do Pet para excluir: ");
  fgets(nomePet, sizeof(nomePet), stdin);
  nomePet[strcspn(nomePet, "\n")] = '\0';

  int encontrado = 0;

//Procura o pet e exclui
  for (int i = 0; i < quantidadeTutores; i++) {
    for (int j = 0; j < tutores[i].numPets; j++) {
      if (strcmp(tutores[i].pets[j].nome, nomePet) == 0) {
        encontrado = 1;
        printf("Pet %s, encontrado.\n", tutores[i].pets[j].nome);

//Substitui o Pet excluido pelo ultimo Pet cadastrado
        tutores[i].pets[j] = tutores[i].pets[tutores[i].numPets - 1];
        tutores[i].numPets--;

//Avisa que o Pet foi excluido
      printf("Pet excluido com sucesso.\n");
      aguardarTecla();
      return;
      }
    }
  }

  if (!encontrado) {
    printf("Pet nao encontrado.\n");
  }

  aguardarTecla();
}

int main() {
  // Variáveis locais
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