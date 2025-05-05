#include <stdio.h>
#include <string.h>

#define MAX_TUTORES 100
#define MAX_PETS 10
#define MAX_NOME 50
#define CPF_LENGTH 12

// Estruturas
typedef struct {
    char nome[MAX_NOME];
} Pet;

typedef struct {
    char cpf[CPF_LENGTH];
    char nome[MAX_NOME];
    Pet pets[MAX_PETS];
    int total_pets;
} Tutor;

// Variáveis globais
Tutor tutores[MAX_TUTORES];
int total_tutores = 0;

// Funções
void cadastrar_tutor();
void editar_tutor();
void listar_tutores();
void excluir_tutor();
void cadastrar_pet();
void editar_pet();
void listar_pets();
void excluir_pet();
int localizar_tutor(char cpf[]);

int main() {
    int opcao;
    do {
        printf("\nMenu Principal:\n");
        printf("1. Tutores\n");
        printf("2. Animais de Estimação\n");
        printf("0. Sair\n");
        printf("Escolha uma opção: ");
        scanf("%d", &opcao);

        switch (opcao) {
            case 1:
                printf("\nMenu Tutores:\n");
                printf("1. Cadastrar Tutor\n");
                printf("2. Editar Tutor\n");
                printf("3. Listar Tutores\n");
                printf("4. Excluir Tutor\n");
                printf("Escolha uma opção: ");
                scanf("%d", &opcao);
                switch (opcao) {
                    case 1: cadastrar_tutor(); break;
                    case 2: editar_tutor(); break;
                    case 3: listar_tutores(); break;
                    case 4: excluir_tutor(); break;
                    default: printf("Opção inválida.\n");
                }
                break;
            case 2:
                printf("\nMenu Animais de Estimação:\n");
                printf("1. Cadastrar Pet\n");
                printf("2. Editar Pet\n");
                printf("3. Listar Pets\n");
                printf("4. Excluir Pet\n");
                printf("Escolha uma opção: ");
                scanf("%d", &opcao);
                switch (opcao) {
                    case 1: cadastrar_pet(); break;
                    case 2: editar_pet(); break;
                    case 3: listar_pets(); break;
                    case 4: excluir_pet(); break;
                    default: printf("Opção inválida.\n");
                }
                break;
            case 0: printf("Saindo...\n"); break;
            default: printf("Opção inválida.\n");
        }
    } while (opcao != 0);
    return 0;
}

void cadastrar_tutor() {
    if (total_tutores >= MAX_TUTORES) {
        printf("Limite de tutores alcançado.\n");
        return;
    }
    Tutor novo_tutor;
    printf("Digite o CPF do tutor: ");
    scanf("%s", novo_tutor.cpf);
    printf("Digite o nome do tutor: ");
    scanf(" %[^\n]", novo_tutor.nome);
    novo_tutor.total_pets = 0;
    tutores[total_tutores++] = novo_tutor;
    printf("Tutor cadastrado com sucesso!\n");
}

void editar_tutor() {
    char cpf[CPF_LENGTH];
    printf("Digite o CPF do tutor a ser editado: ");
    scanf("%s", cpf);
    int index = localizar_tutor(cpf);
    if (index == -1) {
        printf("Tutor não encontrado.\n");
        return;
    }
    printf("Novo nome do tutor: ");
    scanf(" %[^\n]", tutores[index].nome);
    printf("Tutor editado com sucesso!\n");
}

void listar_tutores() {
    printf("Lista de Tutores:\n");
    for (int i = 0; i < total_tutores; i++) {
        printf("CPF: %s, Nome: %s\n", tutores[i].cpf, tutores[i].nome);
    }
}

void excluir_tutor() {
    char cpf[CPF_LENGTH];
    printf("Digite o CPF do tutor a ser excluído: ");
    scanf("%s", cpf);
    int index = localizar_tutor(cpf);
    if (index == -1) {
        printf("Tutor não encontrado.\n");
        return;
    }
    for (int i = index; i < total_tutores - 1; i++) {
        tutores[i] = tutores[i + 1];
    }
    total_tutores--;
    printf("Tutor excluído com sucesso!\n");
}

void cadastrar_pet() {
    char cpf[CPF_LENGTH];
    printf("Digite o CPF do tutor: ");
    scanf("%s", cpf);
    int index = localizar_tutor(cpf);
    if (index == -1) {
        printf("Tutor não encontrado.\n");
        return;
    }
    if (tutores[index].total_pets >= MAX_PETS) {
        printf("Limite de pets alcançado para este tutor.\n");
        return;
    }
    Pet novo_pet;
    printf("Digite o nome do animal de estimação: ");
    scanf(" %[^\n]", novo_pet.nome);
    tutores[index].pets[tutores[index].total_pets++] = novo_pet;
    printf("Pet cadastrado com sucesso!\n");
}

void editar_pet() {
    char cpf[CPF_LENGTH], nome_pet[MAX_NOME];
    printf("Digite o CPF do tutor: ");
    scanf("%s", cpf);
    int index_tutor = localizar_tutor(cpf);
    if (index_tutor == -1) {
        printf("Tutor não encontrado.\n");
        return;
    }
    printf("Digite o nome do animal de estimação: ");
    scanf(" %[^\n]", nome_pet);
    for (int i = 0; i < tutores[index_tutor].total_pets; i++) {
        if (strcmp(tutores[index_tutor].pets[i].nome, nome_pet) == 0) {
            printf("Novo nome do pet: ");
            scanf(" %[^\n]", tutores[index_tutor].pets[i].nome);
            printf("Pet editado com sucesso!\n");
            return;
        }
    }
    printf("Pet não encontrado.\n");
}

void listar_pets() {
    char cpf[CPF_LENGTH];
    printf("Digite o CPF do tutor: ");
    scanf("%s", cpf);
    int index = localizar_tutor(cpf);
    if (index == -1) {
        printf("Tutor não encontrado.\n");
        return;
    }
    printf("Lista de Pets:\n");
    for (int i = 0; i < tutores[index].total_pets; i++) {
        printf("Nome do Pet: %s, Tutor: %s (CPF: %s)\n", tutores[index].pets[i].nome, tutores[index].nome, tutores[index].cpf);
    }
}

void excluir_pet() {
    char cpf[CPF_LENGTH], nome_pet[MAX_NOME];
    printf("Digite o CPF do tutor: ");
    scanf("%s", cpf);
    int index_tutor = localizar_tutor(cpf);
    if (index_tutor == -1) {
        printf("Tutor não encontrado.\n");
        return;
    }
    printf("Digite o nome do animal de estimação: ");
    scanf(" %[^\n]", nome_pet);
    for (int i = 0; i < tutores[index_tutor].total_pets; i++) {
        if (strcmp(tutores[index_tutor].pets[i].nome, nome_pet) == 0) {
            for (int j = i; j < tutores[index_tutor].total_pets - 1; j++) {
                tutores[index_tutor].pets[j] = tutores[index_tutor].pets[j + 1];
            }
            tutores[index_tutor].total_pets--;
            printf("Pet excluído com sucesso!\n");
            return;
        }
    }
    printf("Pet não encontrado.\n");
}

int localizar_tutor(char cpf[]) {
    for (int i = 0; i < total_tutores; i++) {
        if (strcmp(tutores[i].cpf, cpf) == 0) {
            return i;
        }
    }
    return -1;
}
