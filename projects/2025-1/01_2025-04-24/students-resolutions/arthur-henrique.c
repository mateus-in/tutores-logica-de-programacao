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

int buscarTutorPorCPF(char *cpf) {
    for (int i = 0; i < qtdTutores; i++) {
        if (strcmp(tutores[i].cpf, cpf) == 0)
            return i;
    }
    return -1;
}

void registrarTutor() {
    if (qtdTutores >= MAX_TUTORES) {
        printf("Limite de tutores atingido!\n");
        return;
    }

    Tutor novoTutor;
    printf("CPF do tutor: ");
    scanf(" %14s", novoTutor.cpf);

    if (buscarTutorPorCPF(novoTutor.cpf) != -1) {
        printf("Este CPF já está cadastrado.\n");
        return;
    }

    printf("Nome do tutor: ");
    scanf(" %[^\n]", novoTutor.nome);

    novoTutor.qtdPets = 0;
    tutores[qtdTutores++] = novoTutor;

    printf("Tutor cadastrado com sucesso!\n");
}

void editarTutor() {
    char cpf[15];
    printf("CPF do tutor: ");
    scanf(" %14s", cpf);

    int pos = buscarTutorPorCPF(cpf);
    if (pos == -1) {
        printf("Tutor não encontrado.\n");
        return;
    }

    printf("Novo nome do tutor: ");
    scanf(" %[^\n]", tutores[pos].nome);

    printf("Nome atualizado com sucesso!\n");
}

void listarTutores() {
    printf("\n--- Lista de Tutores ---\n");
    for (int i = 0; i < qtdTutores; i++) {
        printf("CPF: %s | Nome: %s\n", tutores[i].cpf, tutores[i].nome);
    }
}

void excluirTutor() {
    char cpf[15];
    printf("CPF do tutor: ");
    scanf(" %14s", cpf);

    int pos = buscarTutorPorCPF(cpf);
    if (pos == -1) {
        printf("Tutor não encontrado.\n");
        return;
    }

    for (int i = pos; i < qtdTutores - 1; i++) {
        tutores[i] = tutores[i + 1];
    }
    qtdTutores--;

    printf("Tutor removido com sucesso!\n");
}

void adicionarPet() {
    char cpf[15];
    printf("CPF do tutor: ");
    scanf(" %14s", cpf);

    int pos = buscarTutorPorCPF(cpf);
    if (pos == -1) {
        printf("Tutor não encontrado.\n");
        return;
    }

    if (tutores[pos].qtdPets >= MAX_PETS) {
        printf("Limite de pets atingido para esse tutor.\n");
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
    scanf(" %14s", cpf);

    int pos = buscarTutorPorCPF(cpf);
    if (pos == -1) {
        printf("Tutor não encontrado.\n");
        return;
    }

    printf("Nome do pet: ");
    scanf(" %[^\n]", nome);

    for (int i = 0; i < tutores[pos].qtdPets; i++) {
        if (strcmp(tutores[pos].pets[i].nome, nome) == 0) {
            printf("Novo nome do pet: ");
            scanf(" %[^\n]", tutores[pos].pets[i].nome);
            printf("Nome do pet atualizado!\n");
            return;
        }
    }
    printf("Pet não encontrado.\n");
}

void listarPets() {
    printf("\n--- Lista de Pets ---\n");
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
    char cpf[15], nome[50];
    printf("CPF do tutor: ");
    scanf(" %14s", cpf);

    int pos = buscarTutorPorCPF(cpf);
    if (pos == -1) {
        printf("Tutor não encontrado.\n");
        return;
    }

    printf("Nome do pet: ");
    scanf(" %[^\n]", nome);

    for (int i = 0; i < tutores[pos].qtdPets; i++) {
        if (strcmp(tutores[pos].pets[i].nome, nome) == 0) {
            for (int j = i; j < tutores[pos].qtdPets - 1; j++) {
                tutores[pos].pets[j] = tutores[pos].pets[j + 1];
            }
            tutores[pos].qtdPets--;
            printf("Pet removido com sucesso!\n");
            return;
        }
    }
    printf("Pet não encontrado.\n");
}

void menu() {
    int opcao;
    do {
        printf("\n--- Menu Principal ---\n");
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
            case 1: registrarTutor(); break;
            case 2: editarTutor(); break;
            case 3: listarTutores(); break;
            case 4: excluirTutor(); break;
            case 5: adicionarPet(); break;
            case 6: editarPet(); break;
            case 7: listarPets(); break;
            case 8: excluirPet(); break;
            case 0: printf("Encerrando o programa...\n"); break;
            default: printf("Opção inválida. Tente de novo.\n");
        }
    } while (opcao != 0);
}

int main() {
    menu();
    return 0;
}