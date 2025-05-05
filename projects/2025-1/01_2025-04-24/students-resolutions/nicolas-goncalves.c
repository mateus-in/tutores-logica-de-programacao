nicolas
#include <stdio.h>    
#include <stdlib.h>
#include <string.h>

#define MAX_PET 3      //maximo de pet por tutor
#define MAX_TUTORES 10

//struct Pet
typedef struct {
    int id;
    char nome[50];
} Pet;

//struct do tutor
typedef struct{
    int id;
    char nome[50];
    char cpf[15];   
    Pet pets[MAX_PET];
    int NumPets;
} Tutor;

//Função para limpar a tela
void limpar_Tela(){
    #ifdef _WIN32
       system("cls");
    #else
       system("clear");
    #endif
}

//função para aguardar o usuario digitar uma tecla
void Aguardar_Tecla(){
    printf("\nPressione Enter para voltar ao menu");
    while(getchar() != '\n'); // Limpa o buffer e espera Enter
}

//função para limpar buffer
void Limpar_Buffer(){
    int c;
    while ((c = getchar()) != '\n' && c != EOF);
}

//menu
void exibir_Menu(){
    printf("******Gestao de Pets****\n\n");
    printf("1 - Listar tutores cadastrados\n");
    printf("2 - Cadastrar novo tutor\n");
    printf("3 - Atualizar tutor cadastrado\n");
    printf("4 - Excluir tutor cadastrado\n");
    printf("5 - Listar pets cadastrados\n");
    printf("6 - Cadastrar novo pet\n");
    printf("7 - Atualizar pet cadastrado\n");
    printf("8 - Excluir pet cadastrado\n");
    printf("0 - Sair\n\n");
    printf("Escolha uma opcao: ");
}

//verificar se tem tutor cadastrado
void ListarTutores(Tutor tutores[], int totaltutores){
    if (totaltutores == 0){
        printf("Nenhum tutor cadastrado.\n");
    } else {
        for (int i = 0; i < totaltutores; i++){
            printf("ID: %d | CPF: %s | Nome: %s | Pets: %d\n", tutores[i].id, tutores[i].cpf, tutores[i].nome, tutores[i].NumPets);
        }
    }
    Aguardar_Tecla();
}

//cadastrar tutor
void cadastrarTutor(Tutor tutores[], int *totaltutores){
    if (*totaltutores >= MAX_TUTORES) {
        printf("Limite de tutores atingido.\n");
        Aguardar_Tecla();
        return;
    }

    char cpf[15];
    printf("Digite o CPF do tutor: ");
    fgets(cpf, sizeof(cpf), stdin);
    cpf[strcspn(cpf, "\n")] = '\0';

    for (int i = 0; i < *totaltutores; i++){
        if (strcmp(tutores[i].cpf, cpf) == 0){
            printf("Ja existe um tutor com esse CPF.\n");
            Aguardar_Tecla();
            return;
        }
    }

    Tutor novo;
    novo.id = *totaltutores + 1;
    strcpy(novo.cpf, cpf);

    printf("Digite o nome do tutor: ");
    fgets(novo.nome, sizeof(novo.nome), stdin);
    novo.nome[strcspn(novo.nome, "\n")] = '\0';

    novo.NumPets = 0;
    tutores[*totaltutores] = novo;
    (*totaltutores)++;

    printf("Tutor cadastrado com sucesso!\n");
    Aguardar_Tecla();
}

//atualizar tutor
void atualizarTutor(Tutor tutores[], int totalTutores){
    char cpf[15];
    printf("Digite o CPF do tutor que deseja atualizar: ");
    fgets(cpf, sizeof(cpf), stdin);
    cpf[strcspn(cpf, "\n")] = '\0';

    for(int i = 0; i < totalTutores; i++){
        if(strcmp(tutores[i].cpf, cpf) == 0){
            printf("Novo nome do tutor: ");
            fgets(tutores[i].nome, sizeof(tutores[i].nome), stdin);
            tutores[i].nome[strcspn(tutores[i].nome, "\n")] = '\0';
            printf("Tutor atualizado.\n");
            Aguardar_Tecla();
            return;
        }
    }

    printf("Tutor nao encontrado.\n");
    Aguardar_Tecla();
}

//excluir tutores
void excluirTutor(Tutor tutores[], int *totalTutores){
    char cpf[15];
    printf("Digite o CPF do tutor para ser excluido: ");
    fgets(cpf, sizeof(cpf), stdin);
    cpf[strcspn(cpf, "\n")] = '\0';

    for (int i = 0; i < *totalTutores; i++) {
        if (strcmp(tutores[i].cpf, cpf) == 0) {
            for (int j = i; j < *totalTutores - 1; j++) {
                tutores[j] = tutores[j + 1];
                tutores[j].id = j + 1; // Atualiza os IDs
            }
            (*totalTutores)--;
            printf("Tutor excluido.\n");
            Aguardar_Tecla();
            return;
        }
    }
    printf("Tutor nao encontrado.\n");
    Aguardar_Tecla();
}

//listar pet
void listarPets(Tutor tutores[], int totalTutores) {
    int encontrou = 0;
    for (int i = 0; i < totalTutores; i++){
        for (int j = 0; j < tutores[i].NumPets; j++){
            printf("ID: %d | Pet: %s | Tutor: %s | CPF: %s\n", 
                   tutores[i].pets[j].id, tutores[i].pets[j].nome,
                   tutores[i].nome, tutores[i].cpf);
            encontrou = 1;
        }
    }

    if (!encontrou) {
        printf("Nenhum pet cadastrado.\n");
    }
    Aguardar_Tecla();
}

//cadastrar pet
void cadastrarPet(Tutor tutores[], int totalTutores){
    char cpf[15];
    printf("Digite o cpf do tutor: ");
    fgets(cpf, sizeof(cpf), stdin);
    cpf[strcspn(cpf, "\n")] = '\0';

    for(int i = 0; i < totalTutores; i++){
        if(strcmp(tutores[i].cpf, cpf) == 0){
            if (tutores[i].NumPets >= MAX_PET) {
                printf("Limite de Pets para esse tutor.\n");
                Aguardar_Tecla();
                return;
            }

            char nomePet[50];
            printf("Digite o nome do pet: ");
            fgets(nomePet, sizeof(nomePet), stdin);
            nomePet[strcspn(nomePet, "\n")] = '\0';

            for(int j = 0; j < tutores[i].NumPets; j++){
                if (strcmp(tutores[i].pets[j].nome, nomePet) == 0){
                    printf("Esse pet ja foi cadastrado para o tutor.\n");
                    Aguardar_Tecla();
                    return;
                }
            }

            Pet novoPet;
            novoPet.id = tutores[i].NumPets + 1;
            strcpy(novoPet.nome, nomePet);
            tutores[i].pets[tutores[i].NumPets++] = novoPet;

            printf("Pet cadastrado com sucesso.\n");
            Aguardar_Tecla();
            return;
        }
    }
    printf("Tutor nao encontrado.\n");
    Aguardar_Tecla();
}

//atualizar pet
void atualizarPet(Tutor tutores[], int totalTutores) {
    char cpf[15], nomePet[50];
    printf("Digite o CPF do tutor: ");
    fgets(cpf, sizeof(cpf), stdin);
    cpf[strcspn(cpf, "\n")] = '\0';

    for (int i = 0; i < totalTutores; i++) {
        if (strcmp(tutores[i].cpf, cpf) == 0) {
            printf("Digite o nome do pet: ");
            fgets(nomePet, sizeof(nomePet), stdin);
            nomePet[strcspn(nomePet, "\n")] = '\0';

            for (int j = 0; j < tutores[i].NumPets; j++) {
                if (strcmp(tutores[i].pets[j].nome, nomePet) == 0) {
                    printf("Novo nome do pet: ");
                    fgets(tutores[i].pets[j].nome, sizeof(tutores[i].pets[j].nome), stdin);
                    tutores[i].pets[j].nome[strcspn(tutores[i].pets[j].nome, "\n")] = '\0';
                    printf("Pet atualizado com sucesso!\n");
                    Aguardar_Tecla();
                    return;
                }
            }

            printf("Pet nao encontrado.\n");
            Aguardar_Tecla();
            return;
        }
    }

    printf("Tutor nao encontrado.\n");
    Aguardar_Tecla();
}

//excluir pet
void excluirPet(Tutor tutores[], int totalTutores){
    char cpf[15], nomePet[50];
    printf("Digite o cpf do tutor: ");
    fgets(cpf, sizeof(cpf), stdin);
    cpf[strcspn(cpf, "\n")] = '\0';

    for(int i = 0; i < totalTutores; i++){
        if(strcmp(tutores[i].cpf, cpf) == 0) {
            printf("Digite o nome do pet para ser excluido: ");
            fgets(nomePet, sizeof(nomePet), stdin);
            nomePet[strcspn(nomePet, "\n")] = '\0';

            for(int j = 0; j < tutores[i].NumPets; j++){
                if(strcmp(tutores[i].pets[j].nome, nomePet) == 0){
                    for(int k = j; k < tutores[i].NumPets - 1; k++){
                        tutores[i].pets[k] = tutores[i].pets[k + 1];
                        tutores[i].pets[k].id = k + 1; // Atualiza os IDs
                    }
                    tutores[i].NumPets--;
                    printf("Pet excluido.\n");
                    Aguardar_Tecla();
                    return;
                }
            }
            printf("Pet nao encontrado.\n");
            Aguardar_Tecla();
            return;
        }
    }
    printf("Tutor nao encontrado.\n");
    Aguardar_Tecla();
}

// parte final
int main(){
    Tutor tutores[MAX_TUTORES];
    int totalTutores = 0;
    int opcao;

    do{
        limpar_Tela();
        exibir_Menu();
        scanf("%d", &opcao);
        Limpar_Buffer();
        limpar_Tela();

        switch (opcao)
        {
        case 1:
            ListarTutores(tutores, totalTutores);
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
            printf("Encerrando programa.\n");
            break;
        default:
            printf("Opcao invalida.\n");
            Aguardar_Tecla();
        }
    }
    while(opcao != 0);
    return 0;
}