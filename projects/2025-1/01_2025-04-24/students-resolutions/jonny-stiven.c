#include <stdio.h>
#include <string.h>

// Constantes para limites
#define MAX_TUTORES 100
#define MAX_PETS 5
#define MAX_NOME 50
#define MAX_CPF 15

// Estrutura de dados para Pet
typedef struct {
    char nome[MAX_NOME];
} Pet;

// Estrutura de dados para Tutor, que contém uma lista de pets
typedef struct {
    char cpf[MAX_CPF];
    char nome[MAX_NOME];
    Pet pets[MAX_PETS];
    int qtdPets;
} Tutor;

// Vetor de tutores e contador
Tutor tutores[MAX_TUTORES];
int qtdTutores = 0;

// -----------------------------
// Função auxiliar para encontrar um tutor pelo CPF
int encontrarTutorPorCPF(char cpf[]) {
    for (int i = 0; i < qtdTutores; i++) {
        if (strcmp(tutores[i].cpf, cpf) == 0)
            return i;
    }
    return -1; // Retorna -1 se não encontrar
}

// -----------------------------
// Cadastra um novo tutor
void cadastrarTutor() {
    if (qtdTutores >= MAX_TUTORES) {
        printf("Limite de tutores atingido.\n");
        return;
    }

    Tutor novo;
    printf("CPF: ");
    scanf(" %s", novo.cpf);

    if (encontrarTutorPorCPF(novo.cpf) != -1) {
        printf("Tutor com esse CPF já existe.\n");
        return;
    }

    printf("Nome: ");
    scanf(" %[^\n]", novo.nome); // Lê nome com espaços
    novo.qtdPets = 0;

    tutores[qtdTutores++] = novo;
    printf("Tutor cadastrado com sucesso!\n");
}

// Edita o nome de um tutor pelo CPF
void editarTutor() {
    char cpf[MAX_CPF];
    printf("CPF do tutor: ");
    scanf(" %s", cpf);

    int idx = encontrarTutorPorCPF(cpf);
    if (idx == -1) {
        printf("Tutor não encontrado.\n");
        return;
    }

    printf("Novo nome: ");
    scanf(" %[^\n]", tutores[idx].nome);
    printf("Nome atualizado com sucesso.\n");
}

// Lista todos os tutores cadastrados
void listarTutores() {
    if (qtdTutores == 0) {
        printf("Nenhum tutor cadastrado.\n");
        return;
    }

    for (int i = 0; i < qtdTutores; i++) {
        printf("CPF: %s | Nome: %s\n", tutores[i].cpf, tutores[i].nome);
    }
}

// Exclui um tutor e seus pets pelo CPF
void excluirTutor() {
    char cpf[MAX_CPF];
    printf("CPF do tutor: ");
    scanf(" %s", cpf);

    int idx = encontrarTutorPorCPF(cpf);
    if (idx == -1) {
        printf("Tutor não encontrado.\n");
        return;
    }

    // Desloca os tutores para preencher o espaço
    for (int i = idx; i < qtdTutores - 1; i++) {
        tutores[i] = tutores[i + 1];
    }

    qtdTutores--;
    printf("Tutor e seus pets foram excluídos.\n");
}

// -----------------------------
// Cadastra um pet associado a um tutor
void cadastrarPet() {
    char cpf[MAX_CPF];
    printf("CPF do tutor: ");
    scanf(" %s", cpf);

    int idx = encontrarTutorPorCPF(cpf);
    if (idx == -1) {
        printf("Tutor não encontrado.\n");
        return;
    }

    if (tutores[idx].qtdPets >= MAX_PETS) {
        printf("Número máximo de pets atingido.\n");
        return;
    }

    printf("Nome do pet: ");
    scanf(" %[^\n]", tutores[idx].pets[tutores[idx].qtdPets].nome);
    tutores[idx].qtdPets++;

    printf("Pet cadastrado com sucesso.\n");
}

// Edita o nome de um pet pelo CPF do tutor e nome do pet
void editarPet() {
    char cpf[MAX_CPF], nomePet[MAX_NOME];
    printf("CPF do tutor: ");
    scanf(" %s", cpf);
    int idx = encontrarTutorPorCPF(cpf);
    if (idx == -1) {
        printf("Tutor não encontrado.\n");
        return;
    }

    printf("Nome do pet: ");
    scanf(" %[^\n]", nomePet);

    for (int i = 0; i < tutores[idx].qtdPets; i++) {
        if (strcmp(tutores[idx].pets[i].nome, nomePet) == 0) {
            printf("Novo nome do pet: ");
            scanf(" %[^\n]", tutores[idx].pets[i].nome);
            printf("Nome do pet atualizado.\n");
            return;
        }
    }
    printf("Pet não encontrado.\n");
}

// Lista todos os pets com dados do tutor
void listarPets() {
    int encontrou = 0;
    for (int i = 0; i < qtdTutores; i++) {
        for (int j = 0; j < tutores[i].qtdPets; j++) {
            printf("Pet: %s | Tutor: %s | CPF: %s\n", 
                tutores[i].pets[j].nome, tutores[i].nome, tutores[i].cpf);
            encontrou = 1;
        }
    }

    if (!encontrou)
        printf("Nenhum pet cadastrado.\n");
}

// Exclui um pet pelo nome e CPF do tutor
void excluirPet() {
    char cpf[MAX_CPF], nomePet[MAX_NOME];
    printf("CPF do tutor: ");
    scanf(" %s", cpf);
    int idx = encontrarTutorPorCPF(cpf);
    if (idx == -1) {
        printf("Tutor não encontrado.\n");
        return;
    }

    printf("Nome do pet: ");
    scanf(" %[^\n]", nomePet);

    for (int i = 0; i < tutores[idx].qtdPets; i++) {
        if (strcmp(tutores[idx].pets[i].nome, nomePet) == 0) {
            // Remove o pet deslocando os demais
            for (int j = i; j < tutores[idx].qtdPets - 1; j++) {
                tutores[idx].pets[j] = tutores[idx].pets[j + 1];
            }
            tutores[idx].qtdPets--;
            printf("Pet excluído.\n");
            return;
        }
    }
    printf("Pet não encontrado.\n");
}

// -----------------------------
// Menu principal para interagir com o usuário
void menu() {
    int opcao;
    do {
        printf("\n===== Menu Principal =====\n");
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

// Função principal
int main() {
    menu();
    return 0;
}
