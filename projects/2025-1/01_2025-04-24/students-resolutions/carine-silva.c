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
  char cpf[13];
/*
  Acrescentado o dado 'CPF' que não constava no código base.
  O ideal seria 12 caracteres, 11 para os números do CPF e 1 para \0,
  porém assim houve um erro que não consegui identificar o porque.
  Ao invés de solicitar o nome do tutor, aparecia o printf seguinte.
  Com 13 caracteres deu certo. Será que está relacionado a \n? 
*/
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
  EOF: ???
*/
void limparBuffer() {
  int c;
  while ((c = getchar()) != '\n' && c != EOF);
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
void listarTutores(Tutor *tutores, int totalTutores) {
	printf("\n   ***Tutores cadastrados:***\n\n");
		
	if (totalTutores == 0){
		printf("\nNenhum tutor cadastrado!\n");
		aguardarTecla();
		return;
	}
	
	int i;
	for (i = 0; i < totalTutores; i++) {
        printf("- Tutor %d:\n", i + 1);
        printf("- Nome: %s\n", tutores[i].nome);
        printf("- CPF: %s\n", tutores[i].cpf);
        printf("- Pets:");

        if (tutores[i].numPets > 0) {
            printf("\n");
            int j;
            for (j = 0; j < tutores[i].numPets; j++) {
                printf(" '%s\n", tutores[i].pets[j].nome);
            }
        } else {
            printf("Nenhum pet cadastrado.\n");
        }

        printf("\n");
    }
  
  aguardarTecla();
}

/*
  Função para cadastrar um novo tutor
  Essa função deve solicitar os dados do tutor (nome, pets, etc.) e armazená-los no array de tutores.
  Deve verificar se o número máximo de tutores foi atingido antes de cadastrar um novo.
  Não deve permitir cadastrar um tutor com o mesmo nome de outro já cadastrado.
*/

/*
   Verificar se já existe um cadastro com este CPF. Uma função não pode existir dentro de outra função.
   Neste caso, foi mais adequado coloca-lo antes da funcão cadastrar tutor, assim como para verificar o nome.
*/
  int cpfExiste(Tutor tutores[], int totalTutores, char *cpf)
  {
  	int i;
  	for(i=0; i<totalTutores; i++){
  	    if (strcmp(tutores[i].cpf, cpf)==0) {
            return 1;
        }
    }
    return 0;
}

int nomeExiste(Tutor tutores[], int totalTutores, char *nome)
  {
  	int i;
  	for(i=0; i<totalTutores; i++){
  	    if (strcmp(tutores[i].nome, nome)==0) {
            return 1;
        }
    }
    return 0;
}

void cadastrarTutor(Tutor *tutores, int *totalTutores) {
	
	if(*totalTutores>=MAX_TUTORES)
	{
		printf("\nErro! Número máximo de tutores atingido!\n");
		aguardarTecla();
		return;
	}
	
	Tutor novoTutor;
	
	printf("\n   ***Cadastro de Tutor***\n\n");
	
	printf("CPF do tutor (11 números):");
	fgets(novoTutor.cpf, sizeof(novoTutor.cpf), stdin);
	
	// Remover \n, se houver
    size_t lenCpf = strlen(novoTutor.cpf);
    if (lenCpf > 0 && novoTutor.cpf[lenCpf - 1] == '\n') {
        novoTutor.cpf[lenCpf - 1] = '\0';
    }
	

  // Validar se o CPF não está vazio
  if (strlen(novoTutor.cpf) == 0)
  {
    printf("\nErro: O CPF do tutor não pode estar vazio!\n");
    aguardarTecla();
    return;
  }
  
  
  if (cpfExiste(tutores, *totalTutores, novoTutor.cpf)) {
        printf("\nErro: Já existe um tutor com esse CPF!\n");
        aguardarTecla();
        return;
  }

	
  printf("Nome do tutor:");
  fgets(novoTutor.nome, MAX_TUTORES, stdin);
	
	// Remover o \n do final da string
  size_t lenNome = strlen(novoTutor.nome);
  if (lenNome > 0 && novoTutor.nome[lenNome - 1] == '\n')
  {
    novoTutor.nome[lenNome - 1] = '\0';
  }

  // Validar se o nome não está vazio
  if (strlen(novoTutor.nome) == 0)
  {
    printf("\nErro: O nome do tutor não pode estar vazio!\n");
    aguardarTecla();
    return;
  }
  
  if (nomeExiste(tutores, *totalTutores, novoTutor.nome)) {
        printf("\nErro: Já existe um tutor com esse nome!\n");
        aguardarTecla();
        return;
  }

   novoTutor.numPets = 0; // Nenhum pet cadastrado inicialmente 

    // Adicionar novo tutor ao array
    tutores[*totalTutores] = novoTutor;
    (*totalTutores)++;

    printf("\nTutor cadastrado com sucesso!\n");
  
  aguardarTecla();
}

/*
  Função para atualizar um tutor cadastrado.
  Essa função deve pesquisar o tutor pelo CPF e exibir o nome atual do tutor e permitir altera-lo.
  Deve verificar se o tutor existe antes de tentar atualizá-lo.
  Se o tutor não existir, deve exibir uma mensagem informando isso.
*/
void atualizarTutor(Tutor *tutores, int totalTutores) {
	printf("\n   ***Atualizar tutor:***\n\n");
	
    //Pesquisar tutor que sera alterado
	char cpf[13];
    printf("Digite o CPF do tutor:");
    fgets(cpf, sizeof(cpf), stdin);
   
	// Remove \n se houver
    size_t lentutor = strlen(cpf);
    if (lentutor > 0 && cpf[lentutor - 1] == '\n') {
        cpf[lentutor - 1] = '\0';
    }
    
    //Verificar se tem algum tutor com o CPF pesquisado
    int indiceTutor = -1;
    int i;
    for (i=0; i<totalTutores; i++) {
    	if (strcmp(tutores[i].cpf, cpf) ==0 ){
    		indiceTutor = i;
    		break;
		}
	}
	
	if (indiceTutor == -1){
        printf("\nErro: Tutor com CPF %s não encontrado!\n", cpf);
        aguardarTecla();
        return;
    }

    Tutor *tutor = &tutores[indiceTutor];
      
    printf("Nome atual: %s\n", tutor->nome);
    printf("Digite o novo nome do tutor: ");
    fgets(tutor->nome, sizeof(tutor->nome), stdin);

    // Remover \n do final do novo nome
    size_t lenNome = strlen(tutor->nome);
    if (lenNome > 0 && tutor->nome[lenNome - 1] == '\n') {
        tutor->nome[lenNome - 1] = '\0';
    }

    // Validar se o novo nome não está vazio
    if (strlen(tutor->nome) == 0) {
        printf("\nErro: O nome do tutor não pode estar vazio!\n");
    } else {
        printf("\nDados do tutor atualizados com sucesso!\n");
    }
	
  aguardarTecla();
}

/*
  Função para excluir um tutor cadastrado.
  Essa função deve solicitar o nome do tutor a ser excluído.
  Deve verificar se o tutor existe antes de tentar excluí-lo.
  Se o tutor não existir, deve exibir uma mensagem informando isso.
  Após excluir o tutor, deve liberar a memória alocada para os pets desse tutor.
*/
void excluirTutor(Tutor *tutores, int *totalTutores) {
	printf("\n   ***Excluir tutor:***\n\n");
	
  //Pesquisar tutor que sera alterado
	char nome[50];
    printf("Digite o nome do tutor:");
    fgets(nome, sizeof(nome), stdin);
   
	// Remove \n se houver
    size_t lentutor = strlen(nome);
    if (lentutor > 0 && nome[lentutor - 1] == '\n') {
        nome[lentutor - 1] = '\0';
    }
    
    //Verificar tem algum tutor com o nome pesquisado
    int indiceTutor = -1;
    int i;
    for (i=0; i<*totalTutores; i++) {
    	if (strcmp(tutores[i].nome, nome) ==0 ){
    		indiceTutor = i;
    		break;
		}
	}
	
	if (indiceTutor == -1){
        printf("\nErro: Tutor com nome %s não encontrado!\n", nome);
        aguardarTecla();
        return;
    }

    // Deslocar os tutores seguintes uma posição para trás
    for (i = indiceTutor; i < *totalTutores - 1; i++) {
        tutores[i] = tutores[i + 1];
    }

    (*totalTutores)--;

    printf("\nTutor excluído com sucesso!\n");
  
  aguardarTecla();
}

/*
  Função para listar os pets cadastrados.
  Essa função deve percorrer o array de tutores e exibir os dados dos pets de cada um.
  Se não houver pets cadastrados, deve exibir uma mensagem informando isso.
*/
void listarPets(Tutor *tutores, int totalTutores) {
	printf("\n   ***Lista de pets cadastrados:\n\n");
	
	int existePet = 0;
    int i;
    for (i = 0; i < totalTutores; i++) {
        if (tutores[i].numPets > 0) {
            printf("Tutor: %s (CPF: %s)\n", tutores[i].nome, tutores[i].cpf);
            int j;
            for (j = 0; j < tutores[i].numPets; j++) {
                printf(" - Pet %d: %s\n", j + 1, tutores[i].pets[j].nome);
            }
            printf("\n");
            existePet = 1;
        }
    }

    if (!existePet) {
        printf("\nNenhum pet cadastrado!\n");
    }
  
  aguardarTecla();
}

/*
 A função abaixo vai impedir o cadastro de mais de um pet com o mesmo nome para o mesmo tutor.
 Esse impedimento sera apenas para a lista de cada tutor, pois diversos tutores podem ter
 pets com o mesmo nome.
*/

int nomePetExisteParaTutor(Tutor *tutor, const char *nomePet) {
    int i;
    for (i = 0; i < tutor->numPets; i++) {
        if (strcmp(tutor->pets[i].nome, nomePet) == 0) {
            return 1; // Pet com nome repetido encontrado
        }
    }
    return 0; // Nome está disponível
}

/*
  Função para cadastrar um novo pet.
  Essa função deve solicitar os dados do pet (nome, tutor, etc.) e armazená-los no array de pets.
  Deve verificar se o número máximo de pets foi atingido antes de cadastrar um novo.
  Não deve permitir cadastrar um pet com o mesmo nome de outro já cadastrado.
*/
/*
 A lista de pets deve ser incluida no cadastro do respectivo tutor, 
 ou seja, já exixte uma lista para os pets dentro dos cadastros de tutores,
 não é necessário criar mais um espaço para a lista de pets.
*/
void cadastrarPet(Tutor *tutores, int totalTutores) {
	printf("\n   ***Cadastro de Pet***\n\n");

	//Pesquisar tutor do novo pet cadastrado
	char cpf[13];
    printf("Digite o CPF do tutor para vincular o pet:");
    fgets(cpf, sizeof(cpf), stdin);
   
	// Remove \n se houver
    size_t lentutor = strlen(cpf);
    if (lentutor > 0 && cpf[lentutor - 1] == '\n') {
        cpf[lentutor - 1] = '\0';
    }
    
    //Verificar se tem algum tutor com o CPF pesquisado
    int indiceTutor = -1;
    int i;
    for (i=0; i<totalTutores; i++) {
    	if (strcmp(tutores[i].cpf, cpf) ==0 ){
    		indiceTutor = i;
    		break;
		}
	}
	
	if (indiceTutor == -1){
        printf("\nErro: Tutor com CPF %s não encontrado!\n", cpf);
        aguardarTecla();
        return;
    }

      Tutor *tutor = &tutores[indiceTutor]; 

	//Verificar se já foi cadastrado para o tutor informado o número máximo de pets permitido.
	if (tutor->numPets >= MAX_PETS) {
		printf("\nErro! Número máximo de pets atingido!\n");
		aguardarTecla();
		return;
	}

	Pet novoPet;
	
    printf("Nome do pet:");
    fgets(novoPet.nome, sizeof(novoPet.nome), stdin);
    
    //Remover o \n do final da string
    size_t lenNovoPet = strlen(novoPet.nome);
    if (lenNovoPet> 0 && novoPet.nome[lenNovoPet - 1] == '\n') {
        novoPet.nome[lenNovoPet - 1] = '\0';
    }

  // Validar se o nome não está vazio
  if (strlen(novoPet.nome) == 0)
  {
    printf("Erro: O nome do pet não pode estar vazio!\n");
    aguardarTecla();
    return;
  }

if (nomePetExisteParaTutor(&tutores[indiceTutor], novoPet.nome)) {
    printf("\nErro: Já existe um pet com esse nome!\n");
    aguardarTecla();
    return;
}

  // Adicionar o pet ao tutor
    tutor->pets[tutor->numPets] = novoPet;
    tutor->numPets++;

    printf("Pet cadastrado e vinculado com sucesso!\n");
    aguardarTecla();
}

/*
  Função para atualizar um pet cadastrado.
  Essa função solicita o CPF do tutor do pet a ser atualizado.
  O usuario escolhe qual pet da lista desse tutor ser atualizado
  e permite atualizar o nome do pet.
  Deve verificar se o pet existe antes de tentar atualizá-lo.
  Se o pet não existir, deve exibir uma mensagem informando isso.
*/
void atualizarPet(Tutor *tutores, int totalTutores) {
	printf("\n   ***Atualizar pet:***\n\n");
	
	//Primeiro deve ser informado o tutor do qual o pet será atualizado
	char cpf[13];
    printf("Digite o CPF do tutor: ");
    fgets(cpf, sizeof(cpf), stdin);
	
	// Remove \n se houver
    size_t lentutor = strlen(cpf);
    if (lentutor > 0 && cpf[lentutor - 1] == '\n') {
        cpf[lentutor - 1] = '\0';
    }
    
     //Verificar tem algum tutor com o CPF pesquisado
    int indiceTutor = -1;
    int i;
    for (i=0; i<totalTutores; i++) {
    	if (strcmp(tutores[i].cpf, cpf) ==0 ){
    		indiceTutor = i;
    		break;
		}
	}
	
	if (indiceTutor == -1){
        printf("Erro: Tutor com CPF %s não encontrado!\n", cpf);
        aguardarTecla();
        return;
    }

    Tutor *tutor = &tutores[indiceTutor];
    
    if (tutor->numPets == 0) {
        printf("Este tutor não possui pets cadastrados!\n");
        aguardarTecla();
        return;
    }

    // Listar os pets cadastrados
    printf("Pets cadastrados para o tutor %s:\n", tutor->nome);
    for (i = 0; i < tutor->numPets; i++) {
        printf(" - %d. %s\n", i + 1, tutor->pets[i].nome);
    }

    // Selecionar qual pet atualizar
    int escolha;
    printf("Digite o número do pet que deseja atualizar:");
    scanf("%d", &escolha);
    limparBuffer();

    if (escolha < 1 || escolha > tutor->numPets) {
        printf("Erro: Número inválido de pet!\n");
        aguardarTecla();
        return;
    }

    Pet *pet = &tutor->pets[escolha - 1];

	int existePet = 0;
    if (!existePet) {
        printf("Nenhum pet cadastrado!\n");
    }
	
    printf("Nome atual: %s\n", pet->nome);
    printf("Digite o novo nome do pet:");
    fgets(pet->nome, sizeof(pet->nome), stdin);

    // Remover \n do final do novo nome
    size_t lenNome = strlen(pet->nome);
    if (lenNome > 0 && pet->nome[lenNome - 1] == '\n') {
        pet->nome[lenNome - 1] = '\0';
    }

    // Validar se o novo nome não está vazio
    if (strlen(pet->nome) == 0) {
        printf("Erro: O nome do pet não pode estar vazio!\n");
    } else {
        printf("Dados do pet atualizados com sucesso!\n");
    }
	
  aguardarTecla();
}


/*
  Função para excluir um pet cadastrado
  Essa função solicita o CPF do tutor do pet a ser excluído.
  O usuario escolhe qual pet da lista desse tutor sera excluido.
  Deve verificar se o pet existe antes de tentar excluí-lo.
  Se o pet não existir, deve exibir uma mensagem informando isso.
*/
void excluirPet(Tutor *tutores, int totalTutores) {
	printf("\n   ***Excluir pet:***\n\n");
  
   //Pesquisar tutor cujo pet sera excluido
	char cpf[13];
    printf("Digite o CPF do tutor:");
    fgets(cpf, sizeof(cpf), stdin);
   
	// Remove \n se houver
    size_t lentutor = strlen(cpf);
    if (lentutor > 0 && cpf[lentutor - 1] == '\n') {
        cpf[lentutor - 1] = '\0';
    }
    
    //Verificar tem algum tutor com o CPF pesquisado
    int indiceTutor = -1;
    int i;
    for (i=0; i<totalTutores; i++) {
    	if (strcmp(tutores[i].cpf, cpf) ==0 ){
    		indiceTutor = i;
    		break;
		}
	}
	
	if (indiceTutor == -1){
        printf("Erro: Tutor com CPF %s não encontrado!\n", cpf);
        aguardarTecla();
        return;
    }
    
     Tutor *tutor = &tutores[indiceTutor];
    
    if (tutor->numPets == 0) {
        printf("Este tutor não possui pets cadastrados!\n");
        aguardarTecla();
        return;
    }

    // Listar os pets cadastrados
    printf("Pets cadastrados para o tutor %s:\n", tutor->nome);
    for (i = 0; i < tutor->numPets; i++) {
        printf(" - %d. %s\n", i + 1, tutor->pets[i].nome);
    }

    // Selecionar qual pet atualizar
    int escolha;
    printf("Digite o número do pet que deseja excluir:");
    scanf("%d", &escolha);
    limparBuffer();

    if (escolha < 1 || escolha > tutor->numPets) {
        printf("Erro: Número inválido de pet!\n");
        aguardarTecla();
        return;
    }

    Pet *pets = &tutor->pets[escolha - 1];

	int existePet = 0;
    if (!existePet) {
        printf("Nenhum pet cadastrado!\n");
    }

    // Deslocar os pets seguintes uma posição para trás
    for (i = tutor->numPets; i < tutor->numPets - 1; i++) {
        pets[i] = pets[i + 1];
    }

    tutor->numPets--;

    printf("Pet excluído com sucesso!\n");
  
  aguardarTecla();
}

/*
 O programa executa o que está dentro do int main.
 */
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
