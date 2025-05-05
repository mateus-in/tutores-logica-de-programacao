#include <stdio.h>
#include <string.h>

#define MAX_TUTORES 100
#define MAX_PETS 5
#define TAM_CPF 15
#define TAM_NOME 100

typedef struct {
    char nome[TAM_NOME];
} Pet;

typedef struct {
    char cpf[TAM_CPF];
    char nome[TAM_NOME];
    Pet pets[MAX_PETS];
    int qtdPets;
} Tutor;

Tutor tutores[MAX_TUTORES];
int qtdTutores = 0;

// Funções auxiliares
int encontrarTutorPorCPF(char cpf[]) {
    for (int i = 0; i < qtdTutores; i++) {
        if (strcmp(tutores[i].cpf, cpf) == 0)
            return i;
    }
    return -1;
}

int encontrarPetPorNome(Tutor *tutor, char nome[]) {
    for (int i = 0; i < tutor->qtdPets; i++) {
        if (strcmp(tutor->pets[i].nome, nome) == 0)
            return i;
    }
    return -1;
}

// Funcionalidades de tutores
void cadastrarTutor() {
    if (qtdTutores >= MAX_TUTORES) {
        printf("Limite de tutores atingido!\n");
        return;
    }

    Tutor novo;
    printf("CPF do tutor: ");
    scanf(" %[^\n]", novo.cpf);

    if (encontrarTutorPorCPF(novo.cpf) != -1) {
        printf("CPF já cadastrado!\n");
        return;
    }

    printf("Nome do tutor: ");
    scanf(" %[^\n]", novo.nome);

    novo.qtdPets = 0;
    tutores[qtdTutores++] = novo;

    printf("Tutor cadastrado com sucesso!\n");
}

void editarTutor() {
    char cpf[TAM_CPF];
    printf("CPF do tutor a editar: ");
    scanf(" %[^\n]", cpf);

    int pos = encontrarTutorPorCPF(cpf);
    if (pos == -1) {
        printf("Tutor não encontrado!\n");
        return;
    }

    printf("Novo nome do tutor: ");
    scanf(" %[^\n]", tutores[pos].nome);

    printf("Tutor atualizado com sucesso!\n");
}

void listarTutores() {
    if (qtdTutores == 0) {
        printf("Nenhum tutor cadastrado.\n");
        return;
    }

    for (int i = 0; i < qtdTutores; i++) {
        printf("CPF: %s | Nome: %s\n", tutores[i].cpf, tutores[i].nome);
    }
}

void excluirTutor() {
    char cpf[TAM_CPF];
    printf("CPF do tutor a excluir: ");
    scanf(" %[^\n]", cpf);

    int pos = encontrarTutorPorCPF(cpf);
    if (pos == -1) {
        printf("Tutor não encontrado!\n");
        return;
    }

    for (int i = pos; i < qtdTutores - 1; i++) {
        tutores[i] = tutores[i + 1];
    }

    qtdTutores--;
    printf("Tutor e seus pets excluídos com sucesso!\n");
}

// Funcionalidades de pets
void cadastrarPet() {
    char cpf[TAM_CPF];
    printf("CPF do tutor do pet: ");
    scanf(" %[^\n]", cpf);

    int pos = encontrarTutorPorCPF(cpf);
    if (pos == -1) {
        printf("Tutor não encontrado!\n");
        return;
    }

    if (tutores[pos].qtdPets >= MAX_PETS) {
        printf("Limite de pets atingido para este tutor.\n");
        return;
    }

    printf("Nome do pet: ");
    scanf(" %[^\n]", tutores[pos].pets[tutores[pos].qtdPets].nome);
    tutores[pos].qtdPets++;

    printf("Pet cadastrado com sucesso!\n");
}

void editarPet() {
    char cpf[TAM_CPF], nome[TAM_NOME];
    printf("CPF do tutor: ");
    scanf(" %[^\n]", cpf);

    int posTutor = encontrarTutorPorCPF(cpf);
    if (posTutor == -1) {
        printf("Tutor não encontrado!\n");
        return;
    }

    printf("Nome do pet a editar: ");
    scanf(" %[^\n]", nome);

    int posPet = encontrarPetPorNome(&tutores[posTutor], nome);
    if (posPet == -1) {
        printf("Pet não encontrado!\n");
        return;
    }

    printf("Novo nome do pet: ");
    scanf(" %[^\n]", tutores[posTutor].pets[posPet].nome);

    printf("Pet atualizado com sucesso!\n");
}

void listarPets() {
    for (int i = 0; i < qtdTutores; i++) {
        for (int j = 0; j < tutores[i].qtdPets; j++) {
            printf("Pet: %s | Tutor: %s | CPF: %s\n",
                   tutores[i].pets[j].nome,
                   tutores[i].nome,
                   tutores[i].cpf);
        }
    }
}

void excluirPet() {
    char cpf[TAM_CPF], nome[TAM_NOME];
    printf("CPF do tutor: ");
    scanf(" %[^\n]", cpf);

    int posTutor = encontrarTutorPorCPF(cpf);
    if (posTutor == -1) {
        printf("Tutor não encontrado!\n");
        return;
    }

    printf("Nome do pet a excluir: ");
    scanf(" %[^\n]", nome);

    int posPet = encontrarPetPorNome(&tutores[posTutor], nome);
    if (posPet == -1) {
        printf("Pet não encontrado!\n");
        return;
    }

    for (int i = posPet; i < tutores[posTutor].qtdPets - 1; i++) {
        tutores[posTutor].pets[i] = tutores[posTutor].pets[i + 1];
    }

    tutores[posTutor].qtdPets--;

    printf("Pet excluído com sucesso!\n");
}

// Menu principal
void menu() {
    int opcao;
    do {
        printf("\n===== Menu Principal =====\n");
        printf("1. Cadastrar tutor\n");
        printf("2. Editar tutor\n");
        printf("3. Listar tutores\n");
        printf("4. Excluir tutor\n");
        printf("5. Cadastrar pet\n");
        printf("6. Editar pet\n");
        printf("7. Listar pets\n");
        printf("8. Excluir pet\n");
        printf("0. Sair\n");
        printf("Escolha uma opção: ");
        scanf("%d", &opcao);

        switch (opcao) {
            case 1: cadastrarTutor(); break;
            case 2: editarTutor(); break;
            case 3: listarTutores(); break;
            case 4: excluirTutor(); break;
            case 5: cadastrarPet(); break;
            case 6: editarPet(); break;
            case 7: listarPets(); break;
            case 8: excluirPet(); break;
            case 0: printf("Encerrando o programa...\n"); break;
            default: printf("Opção inválida!\n");
        }
    } while (opcao != 0);
}

int main() {
    menu();
    return 0;
}
