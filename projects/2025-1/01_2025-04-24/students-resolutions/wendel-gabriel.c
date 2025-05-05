// Definição de constantes para o número máximo de pets e tutores
#define MAX_PETS 3
#define MAX_TUTORES 10
// Definição da estrutura Pet
typedef struct {
int id;
char nome[50];
} Pet;
// Definição da estrutura Tutor
typedef struct {
int id;
char cpf[15];
char nome[50];
Pet pets[MAX_PETS];
int numPets;
} Tutor;
// Função para limpar a tela dependendo do sistema operacional
void limparTela() {
#ifdef _WIN32
system("cls");
#else
system("clear");
#endif
}
// Função para aguardar o usuário pressionar uma tecla para retornar ao menu
void aguardarTecla() {
printf("\nPressione qualquer tecla para voltar ao menu...");
getchar();
}
// Função para limpar o buffer de entrada
void limparBuffer() {
int ch;
while ((ch = getchar()) != '\n' && ch != EOF);
}
// Função que exibe o menu principal
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
// Função para listar os tutores cadastrados
void listarTutores(Tutor tutores[], int totaltutores) {
if(totaltutores == 0) {
printf("Nenhum Tutor Cadastrado no momento. \n");
} else {
for (int i = 0; i < totaltutores; i++) {
tutores[i].numPets);
printf("CPF: %s\n-----------\n Nome: %s\n-----------\n Pets: %d\n-----------\n", tutores[i].cpf, tutores[i].nome,
}
}
aguardarTecla();
}
// Função para cadastrar um novo tutor
void cadastrarTutor(Tutor tutores[MAX_TUTORES], int *totaltutores) {
if(*totaltutores >= MAX_TUTORES) {
printf("A Quantidade de Tutores cadastrados chegou ao limite. \n");
}
char cpf[15];
printf("Digite o CPF do tutor que deseja cadastar: ");
fgets(cpf, sizeof(cpf), stdin);
cpf[strcspn(cpf, "\n")] = '\0';
for (int i = 0; i < *totaltutores; i++) {
if (strcmp(tutores[i].cpf, cpf) == 0) {
printf("Já existe um tutor com esse CPF.\n");
aguardarTecla();
return;
}
}
Tutor adicionar;
adicionar.id = *totaltutores + 1;
strcpy(adicionar.cpf, cpf);
limparBuffer();
printf("Digite o nome do tutor que deseja cadastrar: ");
fgets(adicionar.nome, sizeof(adicionar.nome), stdin);
adicionar.nome[strcspn(adicionar.nome, "\n")] = '\0';
adicionar.numPets = 0;
tutores[*totaltutores] = adicionar;
(*totaltutores)++;
printf("Tutor cadastrado com sucesso!\n");
aguardarTecla();
}
// Função para atualizar um tutor cadastrado
void atualizarTutor(Tutor tutores[MAX_TUTORES], int *totaltutores) {
char nome[50];
if(*totaltutores == 0) {
printf("Nenhum Tutor Cadastrado no momento. \n");
aguardarTecla();
return;
}
printf("Digite o nome do Tutor que deseja atualizar: \n");
fgets(nome, sizeof(nome), stdin);
nome[strcspn(nome, "\n")] = '\0';
for(int i = 0; i < *totaltutores; i++) {
if(strcmp(tutores[i].nome, nome) == 0) {
printf("Digite o nome do novo tutor: \n");
fgets(tutores[i].nome, sizeof(tutores[i].nome), stdin);
tutores[i].nome[strcspn(tutores[i].nome, "\n")] = '\0';
printf("Digite o CPF do novo tutor: \n");
fgets(tutores[i].cpf, sizeof(tutores[i].cpf), stdin);
tutores[i].cpf[strcspn(tutores[i].cpf, "\n")] = '\0';
printf("Tutor Atualizado com Sucesso!\n");
aguardarTecla();
return;
}
}
printf("Tutor não encontrado!\n");
aguardarTecla();
}
// Função para excluir um tutor cadastrado
void excluirTutor(Tutor tutores[MAX_TUTORES], int *totaltutores) {
char nome[50];
if (*totaltutores == 0) {
printf("Nenhum Tutor Cadastrado no momento.\n");
aguardarTecla();
return;
}
printf("Digite o nome do Tutor que deseja excluir: ");
limparBuffer();
printf("Digite o nome novamente para confirmar: ");
fgets(nome, sizeof(nome), stdin);
nome[strcspn(nome, "\n")] = '\0';
for (int i = 0; i < *totaltutores; i++) {
if (strcasecmp(tutores[i].nome, nome) == 0) {
for (int j = i; j < *totaltutores - 1; j++) {
tutores[j] = tutores[j + 1];
}
(*totaltutores)--;
printf("O Tutor foi Excluído com Sucesso!.\n");
aguardarTecla();
return;
}
}
printf("Tutor não Encontrado!\n");
aguardarTecla();
}
// Função para listar os pets cadastrados
void listarPets(Tutor tutores[MAX_TUTORES], int totaltutores) {
int encontrar_pet = 0;
for (int i = 0; i < totaltutores; i++) {
for (int j = 0; j < tutores[i].numPets; j++) {
printf("Pet: %s\n-----------\nTutor: %s\n-----------\nCPF: %s\n", tutores[i].pets[j].nome, tutores[i].nome, tutores[i].cpf);
encontrar_pet = 1;
}
}
if (!encontrar_pet) {
printf("Nenhum pet cadastrado.\n");
}
aguardarTecla();
}
// Função para cadastrar um novo pet
void cadastrarPet(Tutor tutores[MAX_TUTORES], int totaltutores) {
char cpf[15];
printf("Digite o cpf do tutor: ");
limparBuffer();
printf("Confirme o CPF do Tutor: ");
fgets(cpf, sizeof(cpf), stdin);
cpf[strcspn(cpf, "\n")] = '\0';
for(int i = 0; i < totaltutores; i++) {
if(strcmp(tutores[i].cpf, cpf) == 0) {
if (tutores[i].numPets >= MAX_PETS) {
printf("Este Tutor já atingiu o limite de pets!\n");
aguardarTecla();
return;
}
char nome_Pet[50];
printf("Digite o nome do pet: ");
limparBuffer();
fgets(nome_Pet, sizeof(nome_Pet), stdin);
nome_Pet[strcspn(nome_Pet, "\n")] = '\0';
for(int j = 0; j < tutores[i].numPets; j++) {
if (strcmp(tutores[i].pets[j].nome, nome_Pet) == 0) {
printf("Esse pet já está cadastrado no CPF de um tutor.\n");
aguardarTecla();
return;
}
}
Pet novo_Pet;
novo_Pet.id = tutores[i].numPets + 1;
strcpy(novo_Pet.nome, nome_Pet);
tutores[i].pets[tutores[i].numPets++] = novo_Pet;
printf("Pet Cadastrado com Sucesso!\n");
aguardarTecla();
return;
}
}
printf("Tutor não encontrado!\n");
aguardarTecla();
}
// Função para excluir um pet cadastrado
void excluirPet(Tutor tutores[MAX_TUTORES], int totaltutores) {
char cpf[15], nome_pet[50];
printf("Digite o CPF do tutor do Pet: ");
limparBuffer();
printf("Confirme o CPF do Tutor: ");
fgets(cpf, sizeof(cpf), stdin);
cpf[strcspn(cpf, "\n")] = '\0';
for(int i = 0; i < totaltutores; i++) {
if(strcmp(tutores[i].cpf, cpf) == 0) {
printf("Digite o Nome do Pet que Deseja Excluir: ");
limparBuffer();
fgets(nome_pet, sizeof(nome_pet), stdin);
nome_pet[strcspn(nome_pet, "\n")] = '\0';
for(int j = 0; j < tutores[i].numPets; j++) {
if(strcmp(tutores[i].pets[j].nome, nome_pet) == 0) {
for(int k = j; k < tutores[i].numPets - 1; k++) {
tutores[i].pets[k] = tutores[i].pets[k + 1];
}
tutores[i].numPets--;
printf("Pet excluído com Sucesso!\n");
aguardarTecla();
return;
}
}
printf("Pet não Encontrado.\n");
aguardarTecla();
return;
}
}
printf("Tutor não encontrado.\n");
aguardarTecla();
}
// Função principal que gerencia o menu e as opções
int main() {
Tutor tutores[MAX_TUTORES];
int totaltutores = 0;
int opcao;
do {
limparTela();
exibirMenu();
scanf("%d", &opcao);
limparBuffer();
limparTela();
switch (opcao) {
case 1:
listarTutores(tutores, totaltutores);
break;
case 2:
cadastrarTutor(tutores, &totaltutores);
break;
case 3:
atualizarTutor(tutores, &totaltutores);
break;
case 4:
excluirTutor(tutores, &totaltutores);
break;
case 5:
listarPets(tutores, totaltutores);
break;
case 6:
cadastrarPet(tutores, totaltutores);
break;
case 7:
atualizarPet(tutores, totaltutores);
break;
case 8:
excluirPet(tutores, totaltutores);
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