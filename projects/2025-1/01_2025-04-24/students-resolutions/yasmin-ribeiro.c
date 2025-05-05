
#include <stdio.h>
#include <string.h>
#define MAX_TUTORES 10
#define MAX_PETS 10
#define MAX_NOME 50
#define MAX_CPF 11

typedef struct{
    char nome[MAX_NOME];
    char cpf[MAX_CPF];
} Tutor;

typedef struct {
    char nome[MAX_NOME];
    char cpf_tutor[MAX_CPF];
} Pet;

Tutor tutores[MAX_TUTORES];
Pet pets[MAX_PETS];
int num_tutores = 0;
int num_pets = 0;

void cadastrar_tutor();
void editar_tutor();
void listar_tutores();
void excluir_tutor();
void cadastrar_pet();
void editar_pet();
void listar_pets();
void excluir_pet();

int main () {
    int opcao;
    do {
        printf("Menu:\n");
        printf("1. Cadastrar tutor\n");
        printf("2. Editar tutor\n");
        printf("3. Listar tutores\n");
        printf("4. Excluir tutor\n");
        printf("5. Cadastrar pet\n");
        printf("6. Editar pet\n");
        printf("7. Listar pets\n");
        printf("8. Excluir pet\n");
        printf("9. Sair\n");
        printf("Opção:");
        scanf("%d", &opcao);
        getchar(); // Consumir o caractere de nova linha

        switch (opcao) {
            case 1:
                cadastrar_tutor();
                break;
            case 2:
                editar_tutor();
                break;
            case 3:
                listar_tutores();
                break;
            case 4:
                excluir_tutor();
                break;
            case 5:
                cadastrar_pet();
                break;
            case 6:
                editar_pet();
                break;
            case 7:
                listar_pets();
                break;
            case 8:
                excluir_pet();
                break;
            case 9:
                printf("Saindo\n");
                break;
            default:
                printf("Opção inválida!\n");
        }
    } while (opcao != 9);

    return 0;
}

// Implementação das funções
void cadastrar_tutor() {
    if (num_tutores < MAX_TUTORES) {
        printf("Digite o nome do tutor: ");
        fgets(tutores[num_tutores].nome, MAX_NOME, stdin);
        tutores[num_tutores].nome[strcspn(tutores[num_tutores].nome, "\n")] = 0;
        printf("Digite o CPF do tutor: ");
        fgets(tutores[num_tutores].cpf, MAX_CPF, stdin);
        tutores[num_tutores].cpf[strcspn(tutores[num_tutores].cpf, "\n")] = 0;
        num_tutores++;
        printf("Tutor cadastrado com sucesso!\n");
    } else {
        printf("Limite de tutores atingido!\n");
    }
}

void editar_tutor() {
    char cpf[MAX_CPF];
    printf("Digite o CPF do tutor: ");
    fgets(cpf, MAX_CPF, stdin);
    cpf[strcspn(cpf, "\n")] = 0;
    for (int i = 0; i < num_tutores; i++) {
        if (strcmp(tutores[i].cpf, cpf) == 0) {
            printf("Digite o novo nome do tutor: ");
            fgets(tutores[i].nome, MAX_NOME, stdin);
            tutores[i].nome[strcspn(tutores[i].nome, "\n")] = 0;
            printf("Tutor editado com sucesso!\n");
            return;
        }
    }
    printf("Tutor não encontrado!\n");
}

void listar_tutores() {
    for (int i = 0; i < num_tutores; i++) {
        printf("Nome: %s, CPF: %s\n", tutores[i].nome, tutores[i].cpf);
    }
}

void excluir_tutor() {
    char cpf[MAX_CPF];
    printf("Digite o CPF do tutor: ");
    fgets(cpf, MAX_CPF, stdin);
    cpf[strcspn(cpf, "\n")] = 0;
    for (int i = 0; i < num_tutores; i++) {
        if (strcmp(tutores[i].cpf, cpf) == 0) {
            for (int j = i; j < num_tutores - 1; j++) {
                tutores[j] = tutores[j + 1];
            }
            num_tutores--;
            printf("Tutor excluído com sucesso!\n");
            return;
        }
    }
    printf("Tutor não encontrado!\n");
}

void cadastrar_pet() {
    if (num_pets < MAX_PETS) {
        printf("Digite o nome do pet: ");
        fgets(pets[num_pets].nome, MAX_NOME, stdin);
        pets[num_pets].nome[strcspn(pets[num_pets].nome, "\n")] = 0;
        printf("Digite o CPF do tutor: ");
        fgets(pets[num_pets].cpf_tutor, MAX_CPF, stdin);
        pets[num_pets].cpf_tutor[strcspn(pets[num_pets].cpf_tutor, "\n")] = 0;
        num_pets++;
        printf("Pet cadastrado com sucesso!\n");
    } else {
        printf("Limite de pets atingido!\n");
    }
}

void editar_pet() {
    char nome[MAX_NOME];
    char cpf[MAX_CPF];
    printf("Digite o nome do pet:");
    fgets(nome, MAX_NOME, stdin);
    nome[strcspn(nome, "\n")] = 0;
    printf("Digite o CPF do tutor:");
    fgets(cpf, MAX_CPF, stdin);
    cpf[strcspn(cpf, "\n")] = 0;
    for (int i = 0; i < num_pets; i++) {
        if (strcmp(pets[i].nome, nome) == 0 && strcmp(pets[i].cpf_tutor, cpf) == 0) {
            printf("Digite o novo nome do pet: ");
            fgets(pets[i].nome, MAX_NOME, stdin);
            pets[i].nome[strcspn(pets[i].nome, "\n")] = 0;
            printf("Pet editado com sucesso!\n");
            return;
        }
    }
    printf("Pet não encontrado!\n");
}
void listar_pets() {
    for (int i = 0; i < num_pets; i++) {
        printf("Nome do pet: %s, CPF do tutor: %s\n", pets[i].nome, pets[i].cpf_tutor);
    }
}
void excluir_pet() {
    char nome[MAX_NOME];
    char cpf[MAX_CPF];
    printf("Digite o nome do pet:");
    fgets(nome, MAX_NOME, stdin);
    nome[strcspn(nome, "\n")] = 0;
    printf("Digite o CPF do tutor: ");
    fgets(cpf, MAX_CPF, stdin);
    cpf[strcspn(cpf, "\n")] = 0;
    for (int i = 0; i < num_pets; i++) {
        if (strcmp(pets[i].nome, nome) == 0 && strcmp(pets[i].cpf_tutor, cpf) == 0) {
            for (int j = i; j < num_pets - 1; j++) {
                pets[j] = pets[j + 1];
            }
            num_pets--;
            printf("Pet excluído com sucesso!\n");
            return;
        }
    }
    printf("Pet não encontrado!\n");
}