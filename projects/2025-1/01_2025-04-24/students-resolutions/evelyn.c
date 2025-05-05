#include <stdio.h>
#include <string.h>

#define MAX_TUTORES 100
#define MAX_PETS 5
#define MAX_NOME 50
#define MAX_CPF 15

typedef struct {
    char nome[MAX_NOME];
} Pet;

typedef struct {
    char cpf[MAX_CPF];
    char nome[MAX_NOME];
    Pet pets[MAX_PETS];
    int qtd_pets;
} Tutor;

Tutor tutores[MAX_TUTORES];
int qtd_tutores = 0;

// Funções auxiliares
int buscarTutorPorCPF(char cpf[]) {
    for (int i = 0; i < qtd_tutores; i++) {
        if (strcmp(tutores[i].cpf, cpf) == 0) {
            return i;
        }
    }
    return -1;
}

int buscarPetPorNome(Tutor *tutor, char nome[]) {
    for (int i = 0; i < tutor->qtd_pets; i++) {
        if (strcmp(tutor->pets[i].nome, nome) == 0) {
            return i;
        }
    }
    return -1;
}

// Funções do menu
void cadastrarTutor() {
    if (qtd_tutores >= MAX_TUTORES) {
        printf("Limite de tutores atingido.\n");
        return;
    }
    Tutor novo;
    printf("CPF: ");
    scanf(" %[^\n]", novo.cpf);
    if (buscarTutorPorCPF(novo.cpf) != -1) {
        printf("Tutor já cadastrado.\n");
        return;
    }
    printf("Nome: ");
    scanf(" %[^\n]", novo.nome);
    novo.qtd_pets = 0;
    tutores[qtd_tutores++] = novo;
    printf("Tutor cadastrado com sucesso.\n");
}

void editarTutor() {
    char cpf[MAX_CPF];
    printf("CPF do tutor: ");
    scanf(" %[^\n]", cpf);
    int idx = buscarTutorPorCPF(cpf);
    if (idx == -1) {
        printf("Tutor não encontrado.\n");
        return;
    }
    printf("Novo nome: ");
    scanf(" %[^\n]", tutores[idx].nome);
    printf("Tutor atualizado.\n");
}

void listarTutores() {
    if (qtd_tutores == 0) {
        printf("Nenhum tutor cadastrado.\n");
        return;
    }
    for (int i = 0; i < qtd_tutores; i++) {
        printf("CPF: %s | Nome: %s\n", tutores[i].cpf, tutores[i].nome);
    }
}

void excluirTutor() {
    char cpf[MAX_CPF];
    printf("CPF do tutor: ");
    scanf(" %[^\n]", cpf);
    int idx = buscarTutorPorCPF(cpf);
    if (idx == -1) {
        printf("Tutor não encontrado.\n");
        return;
    }
    for (int i = idx; i < qtd_tutores - 1; i++) {
        tutores[i] = tutores[i + 1];
    }
    qtd_tutores--;
    printf("Tutor excluído.\n");
}

void cadastrarPet() {
    char cpf[MAX_CPF];
    printf("CPF do tutor: ");
    scanf(" %[^\n]", cpf);
    int idx = buscarTutorPorCPF(cpf);
    if (idx == -1) {
        printf("Tutor não encontrado.\n");
        return;
    }
    if (tutores[idx].qtd_pets >= MAX_PETS) {
        printf("Limite de pets atingido para este tutor.\n");
        return;
    }
    printf("Nome do pet: ");
    scanf(" %[^\n]", tutores[idx].pets[tutores[idx].qtd_pets].nome);
    tutores[idx].qtd_pets++;
    printf("Pet cadastrado com sucesso.\n");
}

void editarPet() {
    char cpf[MAX_CPF], nome_pet[MAX_NOME];
    printf("CPF do tutor: ");
    scanf(" %[^\n]", cpf);
    int idx = buscarTutorPorCPF(cpf);
    if (idx == -1) {
        printf("Tutor não encontrado.\n");
        return;
    }
    printf("Nome do pet: ");
    scanf(" %[^\n]", nome_pet);
    int pet_idx = buscarPetPorNome(&tutores[idx], nome_pet);
    if (pet_idx == -1) {
        printf("Pet não encontrado.\n");
        return;
    }
    printf("Novo nome do pet: ");
    scanf(" %[^\n]", tutores[idx].pets[pet_idx].nome);
    printf("Pet atualizado.\n");
}

void listarPets() {
    for (int i = 0; i < qtd_tutores; i++) {
        for (int j = 0; j < tutores[i].qtd_pets; j++) {
            printf("Pet: %s | Tutor: %s | CPF: %s\n",
                   tutores[i].pets[j].nome,
                   tutores[i].nome,
                   tutores[i].cpf);
        }
    }
}

void excluirPet() {
    char cpf[MAX_CPF], nome_pet[MAX_NOME];
    printf("CPF do tutor: ");
    scanf(" %[^\n]", cpf);
    int idx = buscarTutorPorCPF(cpf);
    if (idx == -1) {
        printf("Tutor não encontrado.\n");
        return;
    }
    printf("Nome do pet: ");
    scanf(" %[^\n]", nome_pet);
    int pet_idx = buscarPetPorNome(&tutores[idx], nome_pet);
    if (pet_idx == -1) {
        printf("Pet não encontrado.\n");
        return;
    }
    for (int i = pet_idx; i < tutores[idx].qtd_pets - 1; i++) {
        tutores[idx].pets[i] = tutores[idx].pets[i + 1];
    }
    tutores[idx].qtd_pets--;
    printf("Pet excluído.\n");
}

// Menu principal
void menu() {
    int opcao;
    do {
        printf("\nMenu Principal\n");
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
            case 0: printf("Saindo...\n"); break;
            default: printf("Opção inválida.\n");
        }
    } while (opcao != 0);
}

int main() {
    menu();
    return 0;
}
