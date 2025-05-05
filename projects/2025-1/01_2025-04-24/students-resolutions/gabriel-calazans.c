#include <stdio.h>
#include <string.h>

#define MAX_TUTORES 100
#define MAX_PETS 5
#define MAX_NOME 50
#define MAX_CPF 15
#define MAX_CONSULTAS 10
#define MAX_DATA 11
#define MAX_DESCRICAO 100

typedef struct {
    char data[MAX_DATA];          // Data da consulta
    char descricao[MAX_DESCRICAO]; // Descrição da consulta
} Consulta;

typedef struct {
    char nome[MAX_NOME];
    Consulta historico[MAX_CONSULTAS];
    int qtdConsultas;             // Quantidade de consultas registradas
} Pet;

typedef struct {
    char cpf[MAX_CPF];
    char nome[MAX_NOME];
    Pet pets[MAX_PETS];
    int qtdPets;
} Tutor;

Tutor tutores[MAX_TUTORES];
int qtdTutores = 0;

// Funções auxiliares
int encontrarTutorPorCPF(char cpf[]) {
    for (int i = 0; i < qtdTutores; i++) {
        if (strcmp(tutores[i].cpf, cpf) == 0) {
            return i;
        }
    }
    return -1;
}

int encontrarPetPorNome(Tutor *tutor, char nome[]) {
    for (int i = 0; i < tutor->qtdPets; i++) {
        if (strcmp(tutor->pets[i].nome, nome) == 0) {
            return i;
        }
    }
    return -1;
}

// 🧍 Funções de tutor
void cadastrarTutor() {
    if (qtdTutores >= MAX_TUTORES) {
        printf("Limite de tutores atingido!\n");
        return;
    }

    Tutor t;
    printf("Digite o CPF do tutor: ");
    scanf(" %[^\n]", t.cpf);

    if (encontrarTutorPorCPF(t.cpf) != -1) {
        printf("CPF já cadastrado.\n");
        return;
    }

    printf("Digite o nome do tutor: ");
    scanf(" %[^\n]", t.nome);

    t.qtdPets = 0;
    tutores[qtdTutores++] = t;
    printf("Tutor cadastrado com sucesso!\n");
}

void editarTutor() {
    char cpf[MAX_CPF];
    printf("Digite o CPF do tutor para editar: ");
    scanf(" %[^\n]", cpf);

    int idx = encontrarTutorPorCPF(cpf);
    if (idx == -1) {
        printf("Tutor não encontrado.\n");
        return;
    }

    printf("Digite o novo nome do tutor: ");
    scanf(" %[^\n]", tutores[idx].nome);
    printf("Tutor atualizado com sucesso!\n");
}

void listarTutores() {
    printf("Tutores cadastrados:\n");
    for (int i = 0; i < qtdTutores; i++) {
        printf("CPF: %s | Nome: %s\n", tutores[i].cpf, tutores[i].nome);
    }
}

void excluirTutor() {
    char cpf[MAX_CPF];
    printf("Digite o CPF do tutor para excluir: ");
    scanf(" %[^\n]", cpf);

    int idx = encontrarTutorPorCPF(cpf);
    if (idx == -1) {
        printf("Tutor não encontrado.\n");
        return;
    }

    for (int i = idx; i < qtdTutores - 1; i++) {
        tutores[i] = tutores[i + 1];
    }
    qtdTutores--;
    printf("Tutor e seus pets foram excluídos.\n");
}

// 🐶 Funções de pet
void cadastrarPet() {
    char cpf[MAX_CPF];
    printf("Digite o CPF do tutor: ");
    scanf(" %[^\n]", cpf);

    int idx = encontrarTutorPorCPF(cpf);
    if (idx == -1) {
        printf("Tutor não encontrado.\n");
        return;
    }

    if (tutores[idx].qtdPets >= MAX_PETS) {
        printf("Este tutor já tem o número máximo de pets.\n");
        return;
    }

    Pet p;
    printf("Digite o nome do pet: ");
    scanf(" %[^\n]", p.nome);
    p.qtdConsultas = 0;  // Inicializa o contador de consultas

    tutores[idx].pets[tutores[idx].qtdPets++] = p;
    printf("Pet cadastrado com sucesso!\n");
}

void registrarConsultaPet() {
    char cpf[MAX_CPF], nomePet[MAX_NOME];
    printf("Digite o CPF do tutor: ");
    scanf(" %[^\n]", cpf);

    int idx = encontrarTutorPorCPF(cpf);
    if (idx == -1) {
        printf("Tutor não encontrado.\n");
        return;
    }

    printf("Digite o nome do pet: ");
    scanf(" %[^\n]", nomePet);
    int petIdx = encontrarPetPorNome(&tutores[idx], nomePet);
    if (petIdx == -1) {
        printf("Pet não encontrado.\n");
        return;
    }

    if (tutores[idx].pets[petIdx].qtdConsultas >= MAX_CONSULTAS) {
        printf("Limite de consultas atingido para este pet.\n");
        return;
    }

    Consulta c;
    printf("Digite a data da consulta (DD/MM/AAAA): ");
    scanf(" %[^\n]", c.data);
    printf("Digite a descrição da consulta: ");
    scanf(" %[^\n]", c.descricao);

    tutores[idx].pets[petIdx].historico[tutores[idx].pets[petIdx].qtdConsultas++] = c;
    printf("Consulta registrada com sucesso!\n");
}

void listarHistoricoConsultas() {
    char cpf[MAX_CPF], nomePet[MAX_NOME];
    printf("Digite o CPF do tutor: ");
    scanf(" %[^\n]", cpf);

    int idx = encontrarTutorPorCPF(cpf);
    if (idx == -1) {
        printf("Tutor não encontrado.\n");
        return;
    }

    printf("Digite o nome do pet: ");
    scanf(" %[^\n]", nomePet);
    int petIdx = encontrarPetPorNome(&tutores[idx], nomePet);
    if (petIdx == -1) {
        printf("Pet não encontrado.\n");
        return;
    }

    printf("Histórico de consultas para o pet %s:\n", nomePet);
    for (int i = 0; i < tutores[idx].pets[petIdx].qtdConsultas; i++) {
        printf("Consulta %d:\n", i + 1);
        printf("Data: %s\n", tutores[idx].pets[petIdx].historico[i].data);
        printf("Descrição: %s\n\n", tutores[idx].pets[petIdx].historico[i].descricao);
    }
}

void editarPet() {
    char cpf[MAX_CPF], nome[MAX_NOME];
    printf("Digite o CPF do tutor: ");
    scanf(" %[^\n]", cpf);
    int idx = encontrarTutorPorCPF(cpf);
    if (idx == -1) {
        printf("Tutor não encontrado.\n");
        return;
    }

    printf("Digite o nome do pet: ");
    scanf(" %[^\n]", nome);
    int petIdx = encontrarPetPorNome(&tutores[idx], nome);
    if (petIdx == -1) {
        printf("Pet não encontrado.\n");
        return;
    }

    printf("Digite o novo nome do pet: ");
    scanf(" %[^\n]", tutores[idx].pets[petIdx].nome);
    printf("Pet atualizado com sucesso!\n");
}

void listarPets() {
    printf("Lista de pets:\n");
    for (int i = 0; i < qtdTutores; i++) {
        for (int j = 0; j < tutores[i].qtdPets; j++) {
            printf("Pet: %s | Tutor: %s | CPF: %s\n", 
                tutores[i].pets[j].nome, tutores[i].nome, tutores[i].cpf);
        }
    }
}

void excluirPet() {
    char cpf[MAX_CPF], nome[MAX_NOME];
    printf("Digite o CPF do tutor: ");
    scanf(" %[^\n]", cpf);
    int idx = encontrarTutorPorCPF(cpf);
    if (idx == -1) {
        printf("Tutor não encontrado.\n");
        return;
    }

    printf("Digite o nome do pet: ");
    scanf(" %[^\n]", nome);
    int petIdx = encontrarPetPorNome(&tutores[idx], nome);
    if (petIdx == -1) {
        printf("Pet não encontrado.\n");
        return;
    }

    for (int i = petIdx; i < tutores[idx].qtdPets - 1; i++) {
        tutores[idx].pets[i] = tutores[idx].pets[i + 1];
    }
    tutores[idx].qtdPets--;
    printf("Pet excluído com sucesso!\n");
}

// 📋 Menu principal
void menu() {
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
        printf("9. Registrar Consulta para Pet\n");
        printf("10. Listar Histórico de Consultas\n");
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
            case 9: registrarConsultaPet(); break;
            case 10: listarHistoricoConsultas(); break;
            case 0: printf("Saindo...\n"); break;
            default: printf("Opção inválida.\n");
        }
    } while(opcao != 0);
}

int main() {
    menu();
    return 0;
}