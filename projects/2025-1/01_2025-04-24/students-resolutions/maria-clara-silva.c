#include <stdio.h>
#include <string.h>

#define MAX_TUTORES 10
#define MAX_PETS 20

typedef struct {
    int ativo;
    char nome[50];
    char cpf[15]; // CPF como string
} Tutor;

typedef struct {
    int ativo;
    char nome[50];
    char cpfTutor[15]; // CPF do tutor associado
} Pet;

Tutor tutores[MAX_TUTORES];
Pet pets[MAX_PETS];
int totalTutores = 0;
int totalPets = 0;

// Funções auxiliares
int buscarTutorPorCPF(char cpf[]) {
    for (int i = 0; i < totalTutores; i++) {
        if (tutores[i].ativo && strcmp(tutores[i].cpf, cpf) == 0) {
            return i;
        }
    }
    return -1;
}

int buscarPetPorNomeECpfTutor(char nome[], char cpfTutor[]) {
    for (int i = 0; i < totalPets; i++) {
        if (pets[i].ativo && strcmp(pets[i].nome, nome) == 0 && strcmp(pets[i].cpfTutor, cpfTutor) == 0) {
            return i;
        }
    }
    return -1;
}

// Funções de Tutor
void cadastrarTutor() {
    if (totalTutores >= MAX_TUTORES) {
        printf("Limite de tutores atingido!\n");
        return;
    }

    Tutor t;
    t.ativo = 1;

    printf("Nome do tutor: ");
    fgets(t.nome, sizeof(t.nome), stdin);
    t.nome[strcspn(t.nome, "\n")] = '\0';

    printf("CPF do tutor (somente números): ");
    fgets(t.cpf, sizeof(t.cpf), stdin);
    t.cpf[strcspn(t.cpf, "\n")] = '\0';

    tutores[totalTutores++] = t;
    printf("Tutor cadastrado com sucesso!\n");
}

void listarTutores() {
    printf("\n--- Lista de Tutores ---\n");
    for (int i = 0; i < totalTutores; i++) {
        if (tutores[i].ativo) {
            printf("Nome: %s | CPF: %s\n", tutores[i].nome, tutores[i].cpf);
        }
    }
}

void editarTutor() {
    char cpf[15];
    printf("Digite o CPF do tutor para editar: ");
    fgets(cpf, sizeof(cpf), stdin);
    cpf[strcspn(cpf, "\n")] = '\0';

    int pos = buscarTutorPorCPF(cpf);
    if (pos == -1) {
        printf("Tutor não encontrado!\n");
        return;
    }

    printf("Novo nome do tutor: ");
    fgets(tutores[pos].nome, sizeof(tutores[pos].nome), stdin);
    tutores[pos].nome[strcspn(tutores[pos].nome, "\n")] = '\0';

    printf("Tutor atualizado com sucesso!\n");
}

void excluirTutor() {
    char cpf[15];
    printf("Digite o CPF do tutor para excluir: ");
    fgets(cpf, sizeof(cpf), stdin);
    cpf[strcspn(cpf, "\n")] = '\0';

    int pos = buscarTutorPorCPF(cpf);
    if (pos == -1) {
        printf("Tutor não encontrado!\n");
        return;
    }

    tutores[pos].ativo = 0;

    // Excluir também os pets deste tutor
    for (int i = 0; i < totalPets; i++) {
        if (strcmp(pets[i].cpfTutor, cpf) == 0) {
            pets[i].ativo = 0;
        }
    }

    printf("Tutor e seus pets excluídos com sucesso!\n");
}

// Funções de Pet
void cadastrarPet() {
    if (totalPets >= MAX_PETS) {
        printf("Limite de pets atingido!\n");
        return;
    }

    char cpfTutor[15];
    printf("Digite o CPF do tutor do pet: ");
    fgets(cpfTutor, sizeof(cpfTutor), stdin);
    cpfTutor[strcspn(cpfTutor, "\n")] = '\0';

    int posTutor = buscarTutorPorCPF(cpfTutor);
    if (posTutor == -1) {
        printf("Tutor não encontrado! Cadastre o tutor primeiro.\n");
        return;
    }

    Pet p;
    p.ativo = 1;
    strcpy(p.cpfTutor, cpfTutor);

    printf("Nome do pet: ");
    fgets(p.nome, sizeof(p.nome), stdin);
    p.nome[strcspn(p.nome, "\n")] = '\0';

    pets[totalPets++] = p;
    printf("Pet cadastrado com sucesso!\n");
}

void listarPets() {
    printf("\n--- Lista de Pets ---\n");
    for (int i = 0; i < totalPets; i++) {
        if (pets[i].ativo) {
            printf("Nome do Pet: %s | CPF do Tutor: %s\n", pets[i].nome, pets[i].cpfTutor);

            // Mostrar nome do tutor
            int posTutor = buscarTutorPorCPF(pets[i].cpfTutor);
            if (posTutor != -1) {
                printf("Nome do Tutor: %s\n", tutores[posTutor].nome);
            }
            printf("\n");
        }
    }
}

void editarPet() {
    char nome[50], cpfTutor[15];
    printf("Digite o nome do pet para editar: ");
    fgets(nome, sizeof(nome), stdin);
    nome[strcspn(nome, "\n")] = '\0';

    printf("Digite o CPF do tutor do pet: ");
    fgets(cpfTutor, sizeof(cpfTutor), stdin);
    cpfTutor[strcspn(cpfTutor, "\n")] = '\0';

    int pos = buscarPetPorNomeECpfTutor(nome, cpfTutor);
    if (pos == -1) {
        printf("Pet não encontrado!\n");
        return;
    }

    printf("Novo nome do pet: ");
    fgets(pets[pos].nome, sizeof(pets[pos].nome), stdin);
    pets[pos].nome[strcspn(pets[pos].nome, "\n")] = '\0';

    printf("Pet atualizado com sucesso!\n");
}

void excluirPet() {
    char nome[50], cpfTutor[15];
    printf("Digite o nome do pet para excluir: ");
    fgets(nome, sizeof(nome), stdin);
    nome[strcspn(nome, "\n")] = '\0';

    printf("Digite o CPF do tutor do pet: ");
    fgets(cpfTutor, sizeof(cpfTutor), stdin);
    cpfTutor[strcspn(cpfTutor, "\n")] = '\0';

    int pos = buscarPetPorNomeECpfTutor(nome, cpfTutor);
    if (pos == -1) {
        printf("Pet não encontrado!\n");
        return;
    }

    pets[pos].ativo = 0;
    printf("Pet excluído com sucesso!\n");
}

// Menu principal
void menu() {
    int opcao;
    do {
        printf("\n--- Menu ---\n");
        printf("1 - Cadastrar Tutor\n");
        printf("2 - Listar Tutores\n");
        printf("3 - Editar Tutor\n");
        printf("4 - Excluir Tutor\n");
        printf("5 - Cadastrar Pet\n");
        printf("6 - Listar Pets\n");
        printf("7 - Editar Pet\n");
        printf("8 - Excluir Pet\n");
        printf("0 - Sair\n");
        printf("Escolha uma opção: ");
        scanf("%d", &opcao);
        getchar(); // Limpar buffer

        switch (opcao) {
            case 1: cadastrarTutor(); break;
            case 2: listarTutores(); break;
            case 3: editarTutor(); break;
            case 4: excluirTutor(); break;
            case 5: cadastrarPet(); break;
            case 6: listarPets(); break;
            case 7: editarPet(); break;
            case 8: excluirPet(); break;
            case 0: printf("Saindo...\n"); break;
            default: printf("Opção inválida!\n");
        }
    } while (opcao != 0);
}

// Programa principal
int main() {
    menu();
    return 0;
}