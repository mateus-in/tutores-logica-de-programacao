#include <stdio.h>
#include <string.h>

#define MAX_TUTORES 100 //define um limite máximo de 100 tutores
#define MAX_PETS 10 //cada tutor pode ter até dez pets

typedef struct {
    char nome[50];
} Pet; //define a estrutura de um pet, que tem apenas um nome

typedef struct {
    char cpf[15]; // id do tutor
    char nome[50]; // nome do tutor
    Pet pets[MAX_PETS]; //array com os pets dele (máximo definido).
    int qtdPets; //contador de quantos pets ele têm
} Tutor;

Tutor tutores[MAX_TUTORES]; //vetor que guarda os tutores cadastrados
int qtdTutores = 0; // mostra quantos tutores estão cadastrados no momento

// Funções de utilidade: localizar o tutor por cpf
//recebe um cpf e retorna o índice do tutor com esse cpf
// se não encontrar, ele retorna -1
int encontrarTutorPorCPF(const char *cpf) {
    for (int i = 0; i < qtdTutores; i++) {
        if (strcmp(tutores[i].cpf, cpf) == 0)
            return i;
    }
    return -1;
}

// Funções para tutores
void cadastrarTutor() { //pede cpf e nome e vê se ele já está cadastrado (se não estiver adiciona no vetor)
    if (qtdTutores >= MAX_TUTORES) {
        printf("Limite de tutores atingido.\n");
        return;
    }

    Tutor novo;
    printf("Digite o CPF do tutor: ");
    scanf(" %14s", novo.cpf);
    if (encontrarTutorPorCPF(novo.cpf) != -1) {
        printf("Tutor com esse CPF já cadastrado.\n");
        return;
    }

    printf("Digite o nome do tutor: ");
    scanf(" %[^\n]", novo.nome);
    novo.qtdPets = 0;

    tutores[qtdTutores++] = novo;
    printf("Tutor cadastrado com sucesso!\n");
}

void editarTutor() { //solicitá cpf. se encontrar deixa editar o nome
    char cpf[15];
    printf("Digite o CPF do tutor a editar: ");
    scanf(" %14s", cpf);

    int idx = encontrarTutorPorCPF(cpf);
    if (idx == -1) {
        printf("Tutor não encontrado.\n");
        return;
    }

    printf("Digite o novo nome: ");
    scanf(" %[^\n]", tutores[idx].nome);
    printf("Nome atualizado.\n");
}

void listarTutores() { //mostra os tutores cadastrados
    for (int i = 0; i < qtdTutores; i++) {
        printf("CPF: %s - Nome: %s\n", tutores[i].cpf, tutores[i].nome);
    }
}

void excluirTutor() { //solicitá o cpf (se encontrar exclui o tutor e o pet)
    char cpf[15];
    printf("Digite o CPF do tutor a excluir: ");
    scanf(" %14s", cpf);

    int idx = encontrarTutorPorCPF(cpf);
    if (idx == -1) {
        printf("Tutor não encontrado.\n");
        return;
    }

    for (int i = idx; i < qtdTutores - 1; i++) {
        tutores[i] = tutores[i + 1];
    }
    qtdTutores--;
    printf("Tutor e seus pets excluídos.\n");
}

// Funções para pets
void cadastrarPet() { //pede o cpf de novo e se for encontrado cadastra um pet novo
    char cpf[15];
    printf("Digite o CPF do tutor: ");
    scanf(" %14s", cpf);

    int idx = encontrarTutorPorCPF(cpf);
    if (idx == -1) {
        printf("Tutor não encontrado.\n");
        return;
    }

    if (tutores[idx].qtdPets >= MAX_PETS) {
        printf("Limite de pets atingido para este tutor.\n");
        return;
    }

    printf("Digite o nome do pet: ");
    scanf(" %[^\n]", tutores[idx].pets[tutores[idx].qtdPets].nome);
    tutores[idx].qtdPets++;
    printf("Pet cadastrado.\n");
}

void editarPet() { //com o cpf, o nome do tutor e do pet permite alterar o nome
    char cpf[15], nome[50];
    printf("Digite o CPF do tutor: ");
    scanf(" %14s", cpf);
    int idx = encontrarTutorPorCPF(cpf);
    if (idx == -1) {
        printf("Tutor não encontrado.\n");
        return;
    }

    printf("Digite o nome do pet: ");
    scanf(" %[^\n]", nome);
    for (int i = 0; i < tutores[idx].qtdPets; i++) {
        if (strcmp(tutores[idx].pets[i].nome, nome) == 0) {
            printf("Digite o novo nome: ");
            scanf(" %[^\n]", tutores[idx].pets[i].nome);
            printf("Nome do pet atualizado.\n");
            return;
        }
    }
    printf("Pet não encontrado.\n");
}

void listarPets() { //lista os pets com nome, cpf e nome do tutor
    for (int i = 0; i < qtdTutores; i++) {
        for (int j = 0; j < tutores[i].qtdPets; j++) {
            printf("Pet: %s - Tutor: %s - CPF: %s\n", tutores[i].pets[j].nome, tutores[i].nome, tutores[i].cpf);
        }
    }
}

void excluirPet() { //se conseguir achar o cpf e o nome do pet o pet é excluído
    char cpf[15], nome[50];
    printf("Digite o CPF do tutor: ");
    scanf(" %14s", cpf);
    int idx = encontrarTutorPorCPF(cpf);
    if (idx == -1) {
        printf("Tutor não encontrado.\n");
        return;
    }

    printf("Digite o nome do pet: ");
    scanf(" %[^\n]", nome);

    for (int i = 0; i < tutores[idx].qtdPets; i++) {
        if (strcmp(tutores[idx].pets[i].nome, nome) == 0) {
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

void menu() { //um loop que mostra o menu e chama a opção escolhida
    int opcao;
    do {
        printf("\n--- Menu Principal ---\n");
        printf("1. Cadastrar tutor\n2. Editar tutor\n3. Listar tutores\n4. Excluir tutor\n");
        printf("5. Cadastrar pet\n6. Editar pet\n7. Listar pets\n8. Excluir pet\n9. Sair\n");
        printf("Escolha uma opção: ");
        scanf("%d", &opcao);

        switch (opcao) {
        case 1:
            cadastrarTutor();
            break;
        case 2:
            editarTutor();
            break;
        case 3:
            listarTutores();
            break;
        case 4:
            excluirTutor();
            break;
        case 5:
            cadastrarPet();
            break;
        case 6:
            editarPet();
            break;
        case 7:
            listarPets();
            break;
        case 8:
            excluirPet();
            break;
        case 9:
            printf("Encerrando...\n");
            break;
        default:
            printf("Opção inválida.\n");
        }
    } while (opcao != 9); // só para com a opção nove sendo a escolhida
}

int main() { //função principal chamada menu
    menu();
    return 0;
}
    