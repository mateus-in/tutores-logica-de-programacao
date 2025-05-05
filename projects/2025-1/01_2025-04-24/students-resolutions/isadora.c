#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_PETS 3
#define MAX_TUTORES 10

// Definição da struct Pet
typedef struct {
  int id;
  char nome[50];
  int ativo ;
} Pet;

// Definição da struct Tutor
typedef struct {
  int id;
  char nome[50];
  Pet pets[MAX_PETS];
  int numPets;
  int ativo;
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
void listarTutores(Tutor *tutores)
 {
   printf("*****Lista de Tutores *****\n\n");
   
   int encontrado =0;
   
   for (int i =0; i < MAX_TUTORES; i ++)
   {
      if(tutores[i].ativo )
      {
         
         printf("Nome:%s\n\n",tutores[i].nome);
         printf("id: %d\n",tutores[i].id);
         
         encontrado ++ ;
      }
      //modificação feita .
      for (int i =0; i < MAX_PETS; i ++)
         if(tutores[i].ativo)
         {
            printf("Nome:%s\n\n",tutores[i].nome);
            
         }
   }
   
     if (encontrado==0)
     {
       printf("Nenhum tutor cadrastado. \n");
     }
   
  aguardarTecla();
}

/*
  Função para cadastrar um novo tutor
  Essa função deve solicitar os dados do tutor (nome, pets, etc.) e armazená-los no array de tutores.
  Deve verificar se o número máximo de tutores foi atingido antes de cadastrar um novo.
  Não deve permitir cadastrar um tutor com o mesmo nome de outro já cadastrado.
*/
void cadastrarTutor(Tutor *tutores,int *totalTutores)
 {
  printf("*****Cadastrar Tutores *****\n\n");
   
   if (*totalTutores>=MAX_TUTORES)
   {
     printf("Erro:Número maximo de cadrastados atingidos !\n");
     aguardarTecla();
     return;
   }
   
   Tutor novotutor;
   
   printf("Nome: ");
   fgets(novotutor.nome,50,stdin);
   
   size_t len = strlen(novotutor.nome);
   if (len > 0 && novotutor.nome[len-1]=='\n')
   {
       novotutor.nome[len-1 ] = '\0';
   }
   novotutor.ativo =1;
   
   for(int i=0;i <MAX_TUTORES;i++)
   {
      if(tutores[i].ativo && strcmp(tutores [i].nome,novotutor.nome)==0 )
      {
         printf("Erro:Nome já cadrastrado!\n");
         aguardarTecla();
         return;
      }
   }
   printf("Id:");
   scanf("%d",&novotutor.id);
   limparBuffer();
   
    printf("Numero de pets deseja cadastrar(max %d):",MAX_PETS);
    scanf("%d",&novotutor.numPets);
    limparBuffer();
        Pet novoPet;
    if (novotutor.numPets <= 0 || novotutor.numPets > MAX_PETS) {
        printf("Erro: Numero invalido! Digite um valor entre 1 e %d.\n", MAX_PETS);
        aguardarTecla();
        return;
    }
        
    for (int i = 0; i >= novotutor.numPets; i++) {
        printf("\nNome do pet: ");
        fgets(novoPet.nome, 50, stdin);
        size_t len = strlen(novoPet.nome);
          if (len > 0 && novoPet.nome[len-1] == '\n') {
             novoPet.nome[len-1] = '\0';
       
      
        printf("Id:");
        scanf("%d",&novoPet.id);
        limparBuffer();
        aguardarTecla();
        
          int indiceTutor= -1 ;
          
     for (int i = 0; i < tutores[indiceTutor].numPets; i++) {
        if (strcmp(tutores[indiceTutor].pets[i].nome, novoPet.nome) == 0) ;
        }
      
   for (int i=0;i < MAX_TUTORES;i++)
   {
    if(!tutores[i].ativo)
    {
      tutores[i] = novotutor;
      (*totalTutores)++;
      break;
    }
   }
   
   printf("\n Tutor cadrastrado com sucesso ! \n");
  aguardarTecla();
}
}

/*
  Função para atualizar um tutor cadastrado
  Essa função deve solicitar o nome do tutor a ser atualizado e os novos dados (nome, pets, etc.).
  Deve verificar se o tutor existe antes de tentar atualizá-lo.
  Se o tutor não existir, deve exibir uma mensagem informando isso.
*/
void atualizarTutor(Tutor*tutores) {
    printf("*****Atualizar Tutor *****\n\n");
    
    int id ;
    
    printf("Digite o id :");
    scanf("%d",&id);
    limparBuffer();
    
   
    
    int encontrado = 0;
    for(int i =0 ;i < MAX_TUTORES;i++)
    {
      if(tutores[i].ativo && tutores[i].id==id)
        {
          printf("Nome atual: %s\n",tutores[i].nome);
          printf("Novo id:");
          scanf ("%d",&id);
          limparBuffer();
          printf("Novo nome: ");
          fgets(tutores[i].nome,50,stdin);
   
   size_t len = strlen(tutores[i].nome);
   if (len > 0 && tutores[i].nome[len-1]=='\n')
   {
       novotutor.nome[len-1 ] = '\0';
   }
   }
   
   printf("\n Tutor atualizado com sucesso !\n");
   encontrado =1;
   break;
   }
   
   
   if(!encontrado)
   {   
      printf("Erro:Tutor não encontrado!\n");
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
void excluirTutor(Tutor *tutores,int *totalTutores)
 {
   printf("*****Excluir Tutor*****\n\n");
   
   int nome ;
   printf("Digite o nome do tutor: ");
   fgets(tutores[i].nome,50,stdin);
   
   size_t len = strlen(tutores[i].nome);
   if (len > 0 && tutores[i].nome[len-1]=='\n')
   {
       tutores[i].nome[len-1 ] = '\0';
   }
   
   int encontrado = 0;
   int posicao =-1;
   
   for (int i =0;i <MAX_TUTORES;i ++)
   {
      if (tutores[i].ativo && tutores[i].nome==nome)
      {
         posicao = i;
         encontrado =1;
         break;
      }
   } 
   
   if(encontrado)
   {
     printf("Tutor encontrado:\n");
     printf("Nome:%s\n\n",tutores[posicao].nome);
     printf("Id:%d\n",tutores[posicao].id);
     
     char confirmacao;
     printf ("Deseja realmente excluir este tutor ?(S/N)");
     scanf("%c",&confirmacao);
     limparBuffer();
     
     if(confirmacao == 'S'|| confirmacao == 's')
     {
       tutores[posicao].ativo =0;
       (*totalTutores)--;
       printf("\nTutor excluido com sucesso!\n");
       
     }
     else 
     {  
        printf("\n Operação cancelada.\n");
     }
   }   
   else 
   {
        printf("Erro:Tutor não encontrado!\n");
   }
  
  aguardarTecla();
}

/*
  Função para listar os pets cadastrados
  Essa função deve percorrer o array de tutores e exibir os dados dos pets de cada um.
  Se não houver pets cadastrados, deve exibir uma mensagem informando isso.
*/
void listarPets(Pet *pets) 
  {
  printf("*****Lista de Pets *****\n\n");
   
   int encontrado =0;
   
   for (int i =0; i < MAX_PETS; i ++)
   {
      if(pets[i].ativo )
      {
         
         printf("Nome:%s\n\n",pets[i].nome);
         printf("id: %d\n",pets[i].id);
         
         encontrado ++ ;
      }
      
   }
   
     if (encontrado==0)
     {
       printf("Nenhum pet cadrastado. \n");
     }
  aguardarTecla();
}

/*
  Função para cadastrar um novo pet
  Essa função deve solicitar os dados do pet (nome, tutor, etc.) e armazená-los no array de pets.
  Deve verificar se o número máximo de pets foi atingido antes de cadastrar um novo.
  Não deve permitir cadastrar um pet com o mesmo nome de outro já cadastrado.
*/
void cadastrarPet(Tutor*tutores,int *totalTutores ) 
{
  
  printf("*****Cadastrar Pet *****\n\n");
   
   // Verificar se existem tutores cadastrados
    if (*totalTutores == 0) {
        printf("Erro: Nenhum tutor cadastrado. Cadastre um tutor primeiro!\n");
        aguardarTecla();
        return;
    }
    // Solicitar ID do tutor
    int idTutor;
    
    printf("\nDigite o ID do tutor: ");
    scanf("%d", &idTutor);
    limparBuffer();
    
    
    int indiceTutor = -1;
    for (int i = 0; i < MAX_TUTORES; i++) 
    {
      if (tutores[i].ativo && tutores[i].id == idTutor) 
      {
            indiceTutor = i;
            break;
        }
    }
      if (indiceTutor == -1) {
        printf("Erro: Tutor não encontrado!\n");
        aguardarTecla();
        return;
    }
      if (tutores[indiceTutor].numPets >= MAX_PETS)
       {
        printf("Erro: Este tutor já atingiu o número máximo de pets (%d)!\n", MAX_PETS);
        aguardarTecla();
        return;
    }
      Pet novoPet;
    
      printf("\nNome do pet: ");
      fgets(novoPet.nome, 50, stdin);
      size_t len = strlen(novoPet.nome);
      if (len > 0 && novoPet.nome[len-1] == '\n') {
        novoPet.nome[len-1] = '\0';
    }
      
      printf("Id:");
      scanf("%d",&novoPet.id);
      limparBuffer();
   
     for (int i = 0; i < tutores[indiceTutor].numPets; i++) {
        if (strcmp(tutores[indiceTutor].pets[i].nome, novoPet.nome) == 0)
   
   
  
  aguardarTecla();
}
}
/*
  Função para atualizar um pet cadastrado
  Essa função deve solicitar o nome do pet a ser atualizado e os novos dados (nome, tutor, etc.).
  Deve verificar se o pet existe antes de tentar atualizá-lo.
  Se o pet não existir, deve exibir uma mensagem informando isso.
*/
void atualizarPet(Tutor *tutores,int *totalTutures ) {
    printf("***** Atualizar Pet *****\n\n");
    
    //busquei pelo id do pet .
    int idPet;
    printf("Digite o id do Pet :");
    scanf("%d",&idPet);
    limparBuffer();
    
     
    
     int encontrado = 0;
    for(int i =0 ;i < MAX_PETS;i++)
    {
      if(tutores[i].pets[i].ativo && tutores[i].pets[i].id==idPet )
        {
          printf("Nome atual: %s\n",tutores[i].pets[i].nome);
          printf("Novo tutor :");
          fgets(tutores[i].nome,50,stdin);
   
        size_t len = strlen(tutores[i].nome);
       if (len > 0 && tutores[i].nome[len-1]=='\n')
   {
       tutores[i].nome[len-1 ] = '\0';
   }
          printf("Novo id do pet :");
          scanf ("%d",&idPet);
          limparBuffer();
          }
      if(tutores[i].ativo && tutores[i].id==idPet )
      {
          printf("Novo nome: ");
          fgets(tutores[i].nome,50,stdin);
   
   size_t len = strlen(tutores[i].nome);
   if (len > 0 && tutores[i].nome[len-1]=='\n')
   {
       tutores[i].nome[len-1 ] = '\0';
   }
   
   printf("\n Pet atualizado com sucesso !\n");
   encontrado =1;
   break;
   }
   }
   if(!encontrado)
   {   
      printf("Erro:Pet não encontrado!\n");
   }
  aguardarTecla();
    
           
    
}


/*
  Função para excluir um pet cadastrado
  Essa função deve solicitar o nome do pet a ser excluído.
  Deve verificar se o pet existe antes de tentar excluí-lo.
  Se o pet não existir, deve exibir uma mensagem informando isso.
*/
void excluirPet(Pet *pets ,int *totalTutures) 
{
printf("*****Excluir Pets*****\n\n");
   
   int nome ;
   printf("Digite o nome do pet: ");
   fgets(pets[i].nome,50,stdin);
   
   size_t len = strlen(pets[i].nome);
   if (len > 0 && pets[i].nome[len-1]=='\n')
   {
       pets[i].nome[len-1 ] = '\0';
   }
   
   int encontrado = 0;
   int posicao =-1;
   
   for (int i =0;i <MAX_PETS;i ++)
   {
      if (pets[i].ativo && petd[i].nome==nome)
      {
         posicao = i;
         encontrado =1;
         break;
      }
   } 
   
   if(encontrado)
   {
     printf("Pet encontrado:\n");
     printf("Nome:%s\n\n",pets[posicao].nome);
     printf("Id:%d\n",pets[posicao].id);
     
     char confirmacao;
     printf ("Deseja realmente excluir este pet ?(S/N)");
     scanf("%c",&confirmacao);
     limparBuffer();
     
     if(confirmacao == 'S'|| confirmacao == 's')
     {
       pets[posicao].ativo =0;
       (*totalTutores)--;
       printf("\nPets excluido com sucesso!\n");
       
     }
     else 
     {  
        printf("\n Operação cancelada.\n");
     }
   }   
   else 
   {
        printf("Erro:Pet não encontrado!\n");
   }
  
  aguardarTecla();

}

int main() {
  // Variáveis locais
  Tutor tutores[MAX_TUTORES];
  Pet pets[MAX_PETS];
  int totalTutores = 0;
  int opcao;
  
  for (int i=0 ;i < MAX_TUTORES ; i++)
  {
      tutores[i].ativo =0;
  }
  

  do {
    limparTela();
    exibirMenu();
    scanf("%d", &opcao);
    limparBuffer();

    limparTela();

    switch (opcao)
    {
    case 1:
      listarTutores(tutores);
      break;
    case 2:
      cadastrarTutor(tutores,&totalTutores);
      //Inserir id e nome de Tutor 
      break;
    case 3:
      atualizarTutor(tutores);
      break;
    case 4:
      excluirTutor(tutores,&totalTutores);
      break;
    case 5:
      listarPets(pets);
      break;
    case 6:
      cadastrarPet(tutores,&totalTutores);
      break;
    case 7:
      atualizarPet(tutores,&totalTutores);
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