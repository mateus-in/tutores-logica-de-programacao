#include <stdio.h>
#include <string.h>

#define MAX_TUTORES 100
#define MAX_PETS 5

typedef struct {
    char nome[50];
} Pet;

typedef struct {
    char cpf[15];
    char nome[50];
    Pet pets[MAX_PETS];
    int numPets;
} Tutor;

Tutor tutores[MAX_TUTORES];
int numTutores = 0;

// Funções auxiliares
int encontrarTutorPorCPF(char *cpf) {
    for (int i = 0; i < numTutores; i++) {
        if (strcmp(tutores[i].cpf, cpf) == 0) {
            return i;
        }
    }
    return -1;
}

// Tutores
void cadastrarTutor() {
    if (numTutores >= MAX_TUTORES) {
        printf("Limite de tutores atingido.\n");
        return;
    }

    printf("CPF: ");
    scanf(" %14s", tutores[numTutores].cpf);
    printf("Nome: ");
    scanf(" %[^\n]", tutores[numTutores].nome);

    tutores[numTutores].numPets = 0;
    numTutores++;
    printf("Tutor cadastrado com sucesso!\n");
}

void editarTutor() {
    char cpf[15];
    printf("Digite o CPF do tutor a ser editado: ");
    scanf(" %14s", cpf);

    int idx = encontrarTutorPorCPF(cpf);
    if (idx == -1) {
        printf("Tutor não encontrado.\n");
        return;
    }

    printf("Novo nome: ");
    scanf(" %[^\n]", tutores[idx].nome);
    printf("Tutor editado com sucesso!\n");
}

void listarTutores() {
    printf("\n--- Lista de Tutores ---\n");
    for (int i = 0; i < numTutores; i++) {
        printf("CPF: %s | Nome: %s\n", tutores[i].cpf, tutores[i].nome);
    }
}

void excluirTutor() {
    char cpf[15];
    printf("Digite o CPF do tutor a ser excluído: ");
    scanf(" %14s", cpf);

    int idx = encontrarTutorPorCPF(cpf);
    if (idx == -1) {
        printf("Tutor não encontrado.\n");
        return;
    }

    for (int i = idx; i < numTutores - 1; i++) {
        tutores[i] = tutores[i + 1];
    }
    numTutores--;
    printf("Tutor excluído com sucesso.\n");
}

// Pets
void cadastrarPet() {
    char cpf[15];
    printf("CPF do tutor: ");
    scanf(" %14s", cpf);

    int idx = encontrarTutorPorCPF(cpf);
    if (idx == -1) {
        printf("Tutor não encontrado.\n");
        return;
    }

    if (tutores[idx].numPets >= MAX_PETS) {
        printf("Limite de pets atingido para este tutor.\n");
        return;
    }

    printf("Nome do pet: ");
    scanf(" %[^\n]", tutores[idx].pets[tutores[idx].numPets].nome);
    tutores[idx].numPets++;
    printf("Pet cadastrado com sucesso!\n");
}

void editarPet() {
    char cpf[15], nome[50];
    printf("CPF do tutor: ");
    scanf(" %14s", cpf);
    printf("Nome do pet: ");
    scanf(" %[^\n]", nome);

    int idx = encontrarTutorPorCPF(cpf);
    if (idx == -1) {
        printf("Tutor não encontrado.\n");
        return;
    }

    for (int i = 0; i < tutores[idx].numPets; i++) {
        if (strcmp(tutores[idx].pets[i].nome, nome) == 0) {
            printf("Novo nome do pet: ");
            scanf(" %[^\n]", tutores[idx].pets[i].nome);
            printf("Pet editado com sucesso!\n");
            return;
        }
    }

    printf("Pet não encontrado.\n");
}

void listarPets() {
    printf("\n--- Lista de Pets ---\n");
    for (int i = 0; i < numTutores; i++) {
        for (int j = 0; j < tutores[i].numPets; j++) {
            printf("Pet: %s | Tutor: %s | CPF: %s\n",
                   tutores[i].pets[j].nome, tutores[i].nome, tutores[i].cpf);
        }
    }
}

void excluirPet() {
    char cpf[15], nome[50];
    printf("CPF do tutor: ");
    scanf(" %14s", cpf);
    printf("Nome do pet: ");
    scanf(" %[^\n]", nome);

    int idx = encontrarTutorPorCPF(cpf);
    if (idx == -1) {
        printf("Tutor não encontrado.\n");
        return;
    }

    for (int i = 0; i < tutores[idx].numPets; i++) {
        if (strcmp(tutores[idx].pets[i].nome, nome) == 0) {
            for (int j = i; j < tutores[idx].numPets - 1; j++) {
                tutores[idx].pets[j] = tutores[idx].pets[j + 1];
            }
            tutores[idx].numPets--;
            printf("Pet excluído com sucesso!\n");
            return;
        }
    }

    printf("Pet não encontrado.\n");
}

// Menu principal
void menu() {
    int opcao;
    do {
        printf("\n--- MENU PRINCIPAL ---\n");
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

        switch(opcao) {
            case 1: cadastrarTutor(); break;
            case 2: editarTutor(); break;
            case 3: listarTutores(); break;
            case 4: excluirTutor(); break;
            case 5: cadastrarPet(); break;
            case 6: editarPet(); break;
            case 7: listarPets(); break;
            case 8: excluirPet(); break;
            case 0: printf("Saindo...\n"); break;
            default: printf("Opção inválida.\n");
        }

    } while (opcao != 0);
}

int main() {
    menu();
    return 0;
}