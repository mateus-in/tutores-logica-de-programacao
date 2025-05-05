#include <stdio.h>
#include <string.h>

#define MAX_TUTORES 100
#define MAX_PETS 3 // Cada tutor pode ter até 3 pets
#define TAM_STR 50

typedef struct {
    char nome[TAM_STR];
    char especie[TAM_STR];
    int idade;
} Pet;

typedef struct {
    char nome[TAM_STR];
    char telefone[TAM_STR];
    Pet pets[MAX_PETS];
    int qtdPets;
    int ativo; // flag para exclusão lógica
} Tutor;

Tutor tutores[MAX_TUTORES];
int totalTutores = 0;

// Funções
void cadastrarTutor();
void listarTutores();
void editarTutor();
void excluirTutor();
void menu();

int main() {
    menu();
    return 0;
}

void menu() {
    int opcao;

    do {
        printf("\n=== Sistema de Cadastro de Tutores e Pets ===\n");
        printf("1. Cadastrar tutor\n");
        printf("2. Listar tutores\n");
        printf("3. Editar tutor\n");
        printf("4. Excluir tutor\n");
        printf("0. Sair\n");
        printf("Escolha uma opção: ");
        scanf("%d", &opcao);
        getchar(); // limpar buffer

        switch(opcao) {
            case 1: cadastrarTutor(); break;
            case 2: listarTutores(); break;
            case 3: editarTutor(); break;
            case 4: excluirTutor(); break;
            case 0: printf("Encerrando...\n"); break;
            default: printf("Opção inválida.\n");
        }
    } while (opcao != 0);
}

void cadastrarTutor() {
    if (totalTutores >= MAX_TUTORES) {
        printf("Limite de tutores atingido.\n");
        return;
    }

    Tutor t;
    printf("\nNome do tutor: ");
    fgets(t.nome, TAM_STR, stdin);
    t.nome[strcspn(t.nome, "\n")] = 0;

    printf("Telefone: ");
    fgets(t.telefone, TAM_STR, stdin);
    t.telefone[strcspn(t.telefone, "\n")] = 0;

    printf("Quantos pets (até %d): ", MAX_PETS);
    scanf("%d", &t.qtdPets);
    getchar();

    if (t.qtdPets > MAX_PETS) t.qtdPets = MAX_PETS;

    for (int i = 0; i < t.qtdPets; i++) {
        printf("\nPet #%d:\n", i+1);
        printf("Nome: ");
        fgets(t.pets[i].nome, TAM_STR, stdin);
        t.pets[i].nome[strcspn(t.pets[i].nome, "\n")] = 0;

        printf("Espécie: ");
        fgets(t.pets[i].especie, TAM_STR, stdin);
        t.pets[i].especie[strcspn(t.pets[i].especie, "\n")] = 0;

        printf("Idade: ");
        scanf("%d", &t.pets[i].idade);
        getchar();
    }

    t.ativo = 1;
    tutores[totalTutores++] = t;

    printf("\nCadastro realizado com sucesso!\n");
}

void listarTutores() {
    printf("\n=== Lista de Tutores ===\n");

    for (int i = 0; i < totalTutores; i++) {
        if (tutores[i].ativo) {
            printf("\nTutor #%d\n", i);
            printf("Nome: %s\n", tutores[i].nome);
            printf("Telefone: %s\n", tutores[i].telefone);
            printf("Pets:\n");

            for (int j = 0; j < tutores[i].qtdPets; j++) {
                printf("  - %s (%s), %d anos\n",
                       tutores[i].pets[j].nome,
                       tutores[i].pets[j].especie,
                       tutores[i].pets[j].idade);
            }
        }
    }
}

void editarTutor() {
    int id;
    listarTutores();
    printf("\nDigite o número do tutor para editar: ");
    scanf("%d", &id);
    getchar();

    if (id < 0 || id >= totalTutores || !tutores[id].ativo) {
        printf("Tutor inválido.\n");
        return;
    }

    printf("Novo nome do tutor (atual: %s): ", tutores[id].nome);
    fgets(tutores[id].nome, TAM_STR, stdin);
    tutores[id].nome[strcspn(tutores[id].nome, "\n")] = 0;

    printf("Novo telefone (atual: %s): ", tutores[id].telefone);
    fgets(tutores[id].telefone, TAM_STR, stdin);
    tutores[id].telefone[strcspn(tutores[id].telefone, "\n")] = 0;

    printf("Deseja editar os pets? (1 = sim, 0 = não): ");
    int editarPets;
    scanf("%d", &editarPets);
    getchar();

    if (editarPets) {
        printf("Quantos pets agora (até %d): ", MAX_PETS);
        scanf("%d", &tutores[id].qtdPets);
        getchar();

        if (tutores[id].qtdPets > MAX_PETS) tutores[id].qtdPets = MAX_PETS;

        for (int i = 0; i < tutores[id].qtdPets; i++) {
            printf("Pet #%d:\n", i+1);
            printf("Nome: ");
            fgets(tutores[id].pets[i].nome, TAM_STR, stdin);
            tutores[id].pets[i].nome[strcspn(tutores[id].pets[i].nome, "\n")] = 0;

            printf("Espécie: ");
            fgets(tutores[id].pets[i].especie, TAM_STR, stdin);
            tutores[id].pets[i].especie[strcspn(tutores[id].pets[i].especie, "\n")] = 0;

            printf("Idade: ");
            scanf("%d", &tutores[id].pets[i].idade);
            getchar();
        }
    }

    printf("Dados atualizados com sucesso.\n");
}

void excluirTutor() {
    int id;
    listarTutores();
    printf("\nDigite o número do tutor para excluir: ");
    scanf("%d", &id);
    getchar();

    if (id < 0 || id >= totalTutores || !tutores[id].ativo) {
        printf("Tutor inválido.\n");
        return;
    }

    tutores[id].ativo = 0;
    printf("Tutor excluído com sucesso.\n");
}