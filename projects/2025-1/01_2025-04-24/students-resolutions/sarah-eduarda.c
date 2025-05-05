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
    int qtdPets;
} Tutor;

Tutor tutores[MAX_TUTORES];
int qtdTutores = 0;

// Funções auxiliares
int encontrarTutor(char cpf[]) {
    for (int i = 0; i < qtdTutores; i++) {
        if (strcmp(tutores[i].cpf, cpf) == 0)
            return i;
    }
    return -1;
}

int encontrarPet(Tutor *tutor, char nomePet[]) {
    for (int i = 0; i < tutor->qtdPets; i++) {
        if (strcmp(tutor->pets[i].nome, nomePet) == 0)
            return i;
    }
    return -1;
}

// Tutores
void cadastrarTutor() {
    if (qtdTutores >= MAX_TUTORES) {
        printf("Limite de tutores atingido.\n");
        return;
    }
    Tutor t;
    printf("CPF: ");
    scanf("%s", t.cpf);
    if (encontrarTutor(t.cpf) != -1) {
        printf("Tutor já cadastrado.\n");
        return;
    }
    printf("Nome: ");
    scanf(" %[^\n]", t.nome);
    t.qtdPets = 0;
    tutores[qtdTutores++] = t;
    printf("Tutor cadastrado com sucesso!\n");
}

void editarTutor() {
    char cpf[15];
    printf("Digite o CPF do tutor a editar: ");
    scanf("%s", cpf);
    int pos = encontrarTutor(cpf);
    if (pos == -1) {
        printf("Tutor não encontrado.\n");
        return;
    }
    printf("Novo nome: ");
    scanf(" %[^\n]", tutores[pos].nome);
    printf("Tutor atualizado.\n");
}

void listarTutores() {
    for (int i = 0; i < qtdTutores; i++) {
        printf("CPF: %s | Nome: %s\n", tutores[i].cpf, tutores[i].nome);
    }
}

void excluirTutor() {
    char cpf[15];
    printf("Digite o CPF do tutor a excluir: ");
    scanf("%s", cpf);
    int pos = encontrarTutor(cpf);
    if (pos == -1) {
        printf("Tutor não encontrado.\n");
        return;
    }
    for (int i = pos; i < qtdTutores - 1; i++) {
        tutores[i] = tutores[i + 1];
    }
    qtdTutores--;
    printf("Tutor excluído.\n");
}

// Pets
void cadastrarPet() {
    char cpf[15];
    printf("CPF do tutor: ");
    scanf("%s", cpf);
    int pos = encontrarTutor(cpf);
    if (pos == -1) {
        printf("Tutor não encontrado.\n");
        return;
    }
    if (tutores[pos].qtdPets >= MAX_PETS) {
        printf("Limite de pets atingido.\n");
        return;
    }
    printf("Nome do pet: ");
    scanf(" %[^\n]", tutores[pos].pets[tutores[pos].qtdPets].nome);
    tutores[pos].qtdPets++;
    printf("Pet cadastrado com sucesso!\n");
}

void editarPet() {
    char cpf[15], nome[50];
    printf("CPF do tutor: ");
    scanf("%s", cpf);
    int pos = encontrarTutor(cpf);
    if (pos == -1) {
        printf("Tutor não encontrado.\n");
        return;
    }
    printf("Nome do pet: ");
    scanf(" %[^\n]", nome);
    int petIndex = encontrarPet(&tutores[pos], nome);
    if (petIndex == -1) {
        printf("Pet não encontrado.\n");
        return;
    }
    printf("Novo nome: ");
    scanf(" %[^\n]", tutores[pos].pets[petIndex].nome);
    printf("Pet atualizado.\n");
}

void listarPets() {
    for (int i = 0; i < qtdTutores; i++) {
        for (int j = 0; j < tutores[i].qtdPets; j++) {
            printf("Pet: %s | Tutor: %s | CPF: %s\n", tutores[i].pets[j].nome, tutores[i].nome, tutores[i].cpf);
        }
    }
}

void excluirPet() {
    char cpf[15], nome[50];
    printf("CPF do tutor: ");
    scanf("%s", cpf);
    int pos = encontrarTutor(cpf);
    if (pos == -1) {
        printf("Tutor não encontrado.\n");
        return;
    }
    printf("Nome do pet a excluir: ");
    scanf(" %[^\n]", nome);
    int petIndex = encontrarPet(&tutores[pos], nome);
    if (petIndex == -1) {
        printf("Pet não encontrado.\n");
        return;
    }
    for (int i = petIndex; i < tutores[pos].qtdPets - 1; i++) {
        tutores[pos].pets[i] = tutores[pos].pets[i + 1];
    }
    tutores[pos].qtdPets--;
    printf("Pet excluído.\n");
}

// Menu
void menu() {
    int opc;
    do {
        printf("\n--- MENU ---\n");
        printf("1. Cadastrar Tutor\n");
        printf("2. Editar Tutor\n");
        printf("3. Listar Tutores\n");
        printf("4. Excluir Tutor\n");
        printf("5. Cadastrar Pet\n");
        printf("6. Editar Pet\n");
        printf("7. Listar Pets\n");
        printf("8. Excluir Pet\n");
        printf("0. Sair\n");
        printf("Escolha: ");
        scanf("%d", &opc);

        switch (opc) {
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
    } while (opc != 0);
}

int main() {
    menu();
    return 0;
}