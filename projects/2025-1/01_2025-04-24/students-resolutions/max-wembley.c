#include <stdio.h>
#include <string.h>

#define MAX_PETS 5
#define MAX_TUTORES 100

typedef struct {
    char nome[50];
} Pet;

typedef struct {
    char cpf[15];
    char nome[50];
    Pet pets[MAX_PETS];
    int qtdPets;
} Tutor;

Tutor tutores[MAX_TUTORES];
int qtdTutores = 0;

int encontrarTutorPorCPF(char cpf[]) {
    for (int i = 0; i < qtdTutores; i++) {
        if (strcmp(tutores[i].cpf, cpf) == 0) {
            return i;
        }
    }
    return -1;
}

void cadastrarTutor() {
    if (qtdTutores >= MAX_TUTORES) {
        printf("Limite de tutores atingido.\n");
        return;
    }

    printf("CPF do tutor: ");
    fgets(tutores[qtdTutores].cpf, sizeof(tutores[qtdTutores].cpf), stdin);
    strtok(tutores[qtdTutores].cpf, "\n");

    printf("Nome do tutor: ");
    fgets(tutores[qtdTutores].nome, sizeof(tutores[qtdTutores].nome), stdin);
    strtok(tutores[qtdTutores].nome, "\n");

    tutores[qtdTutores].qtdPets = 0;
    printf("Tutor cadastrado com sucesso!\n");
    qtdTutores++;
}

void editarTutor() {
    char cpf[15];
    printf("Digite o CPF do tutor: ");
    fgets(cpf, sizeof(cpf), stdin);
    strtok(cpf, "\n");

    int index = encontrarTutorPorCPF(cpf);
    if (index != -1) {
        printf("Novo nome do tutor: ");
        fgets(tutores[index].nome, sizeof(tutores[index].nome), stdin);
        strtok(tutores[index].nome, "\n");
        printf("Tutor atualizado com sucesso!\n");
    } else {
        printf("Tutor não encontrado.\n");
    }
}

void listarTutores() {
    if (qtdTutores == 0) {
        printf("Nenhum tutor cadastrado.\n");
        return;
    }
    printf("\n--- Lista de Tutores ---\n");
    for (int i = 0; i < qtdTutores; i++) {
        printf("CPF: %s | Nome: %s\n", tutores[i].cpf, tutores[i].nome);
    }
}

void excluirTutor() {
    char cpf[15];
    printf("Digite o CPF do tutor a ser excluído: ");
    fgets(cpf, sizeof(cpf), stdin);
    strtok(cpf, "\n");

    int index = encontrarTutorPorCPF(cpf);
    if (index != -1) {
        for (int i = index; i < qtdTutores - 1; i++) {
            tutores[i] = tutores[i + 1];
        }
        qtdTutores--;
        printf("Tutor excluído com sucesso!\n");
    } else {
        printf("Tutor não encontrado.\n");
    }
}

void cadastrarPet() {
    char cpf[15];
    printf("CPF do tutor: ");
    fgets(cpf, sizeof(cpf), stdin);
    strtok(cpf, "\n");

    int index = encontrarTutorPorCPF(cpf);
    if (index != -1) {
        if (tutores[index].qtdPets >= MAX_PETS) {
            printf("Limite de pets atingido para este tutor.\n");
            return;
        }

        printf("Nome do pet: ");
        fgets(tutores[index].pets[tutores[index].qtdPets].nome, 50, stdin);
        strtok(tutores[index].pets[tutores[index].qtdPets].nome, "\n");

        tutores[index].qtdPets++;
        printf("Pet cadastrado com sucesso!\n");
    } else {
        printf("Tutor não encontrado.\n");
    }
}

void editarPet() {
    char cpf[15], nomePet[50];
    printf("CPF do tutor: ");
    fgets(cpf, sizeof(cpf), stdin);
    strtok(cpf, "\n");

    int index = encontrarTutorPorCPF(cpf);
    if (index != -1) {
        printf("Nome do pet: ");
        fgets(nomePet, sizeof(nomePet), stdin);
        strtok(nomePet, "\n");

        for (int i = 0; i < tutores[index].qtdPets; i++) {
            if (strcmp(tutores[index].pets[i].nome, nomePet) == 0) {
                printf("Novo nome do pet: ");
                fgets(tutores[index].pets[i].nome, 50, stdin);
                strtok(tutores[index].pets[i].nome, "\n");
                printf("Pet atualizado com sucesso!\n");
                return;
            }
        }
        printf("Pet não encontrado.\n");
    } else {
        printf("Tutor não encontrado.\n");
    }
}

void listarPets() {
    printf("\n--- Lista de Pets ---\n");
    int encontrados = 0;
    for (int i = 0; i < qtdTutores; i++) {
        for (int j = 0; j < tutores[i].qtdPets; j++) {
            printf("Pet: %s | Tutor: %s | CPF: %s\n",
                   tutores[i].pets[j].nome,
                   tutores[i].nome,
                   tutores[i].cpf);
            encontrados++;
        }
    }
    if (encontrados == 0) {
        printf("Nenhum pet cadastrado.\n");
    }
}

void excluirPet() {
    char cpf[15], nomePet[50];
    printf("CPF do tutor: ");
    fgets(cpf, sizeof(cpf), stdin);
    strtok(cpf, "\n");

    int index = encontrarTutorPorCPF(cpf);
    if (index != -1) {
        printf("Nome do pet: ");
        fgets(nomePet, sizeof(nomePet), stdin);
        strtok(nomePet, "\n");

        for (int i = 0; i < tutores[index].qtdPets; i++) {
            if (strcmp(tutores[index].pets[i].nome, nomePet) == 0) {
                for (int j = i; j < tutores[index].qtdPets - 1; j++) {
                    tutores[index].pets[j] = tutores[index].pets[j + 1];
                }
                tutores[index].qtdPets--;
                printf("Pet excluído com sucesso!\n");
                return;
            }
        }
        printf("Pet não encontrado.\n");
    } else {
        printf("Tutor não encontrado.\n");
    }
}

void menuPrincipal() {
    int opcao;
    do {
        printf("\n===== MENU PRINCIPAL =====\n");
        printf("1. Cadastrar Tutor\n");
        printf("2. Editar Tutor\n");
        printf("3. Listar Tutores\n");
        printf("4. Excluir Tutor\n");
        printf("5. Cadastrar Pet\n");
        printf("6. Editar Pet\n");
        printf("7. Listar Pets\n");
        printf("8. Excluir Pet\n");
        printf("0. Sair\n");
        printf("Escolha uma opção: ");
        scanf("%d", &opcao);
        getchar();

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
            default: printf("Opção inválida!\n");
        }
    } while(opcao != 0);
}

int main() {
    menuPrincipal();
    return 0;
}