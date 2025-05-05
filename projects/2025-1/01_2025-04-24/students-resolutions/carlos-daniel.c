//já coloquei tudo explicado em caso de você quiser me perguntar 
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_PETS 3
#define MAX_TUTORES 10

// Struct representando um pet
typedef struct {
    char nome[50];
} Pet;

// Struct representando um tutor e seus pets
typedef struct {
    char cpf[20];
    char nome[50];
    Pet pets[MAX_PETS];
    int numPets;
} Tutor;

// Vetor global de tutores
Tutor tutores[MAX_TUTORES];
int totalTutores = 0;

// Limpa a tela do terminal
void limparTela() {
#ifdef _WIN32
    system("cls");
#else
    system("clear");
#endif
}

// Pausa o programa até o usuário apertar Enter
void aguardarTecla() {
    printf("\nPressione Enter para voltar ao menu...");
    getchar();
}

// Limpa o buffer de entrada (usado após scanf)
void limparBuffer() {
    int c;
    while ((c = getchar()) != '\n' && c != EOF);
}

// Exibe o menu principal
void exibirMenu() {
    printf("*****Gestão de Pets*****\n\n");
    printf("1 - Listar os tutores cadastrados\n");
    printf("2 - Cadastrar um novo tutor\n");
    printf("3 - Atualizar um tutor cadastrado\n");
    printf("4 - Excluir um tutor cadastrado\n");
    printf("5 - Listar os pets cadastrados\n");
    printf("6 - Cadastrar um novo pet\n");
    printf("7 - Atualizar um pet cadastrado\n");
    printf("8 - Excluir um pet cadastrado\n");
    printf("0 - Sair\n\n");
    printf("Escolha uma opção: ");
}

// Procura um tutor pelo CPF e retorna o índice ou -1 se não encontrar
int buscarTutorPorCPF(char *cpf) {
    for (int i = 0; i < totalTutores; i++) {
        if (strcmp(tutores[i].cpf, cpf) == 0) {
            return i;
        }
    }
    return -1;
}

// Lista todos os tutores cadastrados
void listarTutores() {
    if (totalTutores == 0) {
        printf("Nenhum tutor cadastrado.\n");
    } else {
        for (int i = 0; i < totalTutores; i++) {
            printf("CPF: %s - Nome: %s\n", tutores[i].cpf, tutores[i].nome);
        }
    }
    aguardarTecla();
}

// Cadastra um novo tutor no sistema
void cadastrarTutor() {
    if (totalTutores >= MAX_TUTORES) {
        printf("Limite de tutores atingido.\n");
        aguardarTecla();
        return;
    }

    char cpf[20];
    printf("Digite o CPF do tutor: ");
    fgets(cpf, sizeof(cpf), stdin);
    cpf[strcspn(cpf, "\n")] = 0;

    if (buscarTutorPorCPF(cpf) != -1) {
        printf("Tutor já cadastrado com este CPF.\n");
        aguardarTecla();
        return;
    }

    strcpy(tutores[totalTutores].cpf, cpf);

    printf("Digite o nome do tutor: ");
    fgets(tutores[totalTutores].nome, sizeof(tutores[totalTutores].nome), stdin);
    tutores[totalTutores].nome[strcspn(tutores[totalTutores].nome, "\n")] = 0;

    tutores[totalTutores].numPets = 0;
    totalTutores++;

    printf("Tutor cadastrado com sucesso!\n");
    aguardarTecla();
}

// Atualiza o nome de um tutor existente
void atualizarTutor() {
    char cpf[20];
    printf("Digite o CPF do tutor: ");
    fgets(cpf, sizeof(cpf), stdin);
    cpf[strcspn(cpf, "\n")] = 0;

    int idx = buscarTutorPorCPF(cpf);
    if (idx == -1) {
        printf("Tutor não encontrado.\n");
    } else {
        printf("Digite o novo nome do tutor: ");
        fgets(tutores[idx].nome, sizeof(tutores[idx].nome), stdin);
        tutores[idx].nome[strcspn(tutores[idx].nome, "\n")] = 0;
        printf("Tutor atualizado com sucesso!\n");
    }
    aguardarTecla();
}

// Exclui um tutor e seus pets
void excluirTutor() {
    char cpf[20];
    printf("Digite o CPF do tutor a ser excluído: ");
    fgets(cpf, sizeof(cpf), stdin);
    cpf[strcspn(cpf, "\n")] = 0;

    int idx = buscarTutorPorCPF(cpf);
    if (idx == -1) {
        printf("Tutor não encontrado.\n");
    } else {
        for (int i = idx; i < totalTutores - 1; i++) {
            tutores[i] = tutores[i + 1];
        }
        totalTutores--;
        printf("Tutor excluído com sucesso.\n");
    }
    aguardarTecla();
}

// Lista todos os pets cadastrados junto com os dados do tutor
void listarPets() {
    int encontrou = 0;
    for (int i = 0; i < totalTutores; i++) {
        for (int j = 0; j < tutores[i].numPets; j++) {
            printf("Pet: %s - Tutor: %s - CPF: %s\n",
                   tutores[i].pets[j].nome,
                   tutores[i].nome,
                   tutores[i].cpf);
            encontrou = 1;
        }
    }
    if (!encontrou) {
        printf("Nenhum pet cadastrado.\n");
    }
    aguardarTecla();
}

// Cadastra um novo pet para um tutor
void cadastrarPet() {
    char cpf[20];
    printf("Digite o CPF do tutor do pet: ");
    fgets(cpf, sizeof(cpf), stdin);
    cpf[strcspn(cpf, "\n")] = 0;

    int idx = buscarTutorPorCPF(cpf);
    if (idx == -1) {
        printf("Tutor não encontrado.\n");
        aguardarTecla();
        return;
    }

    if (tutores[idx].numPets >= MAX_PETS) {
        printf("Limite de pets para este tutor atingido.\n");
        aguardarTecla();
        return;
    }

    printf("Digite o nome do pet: ");
    fgets(tutores[idx].pets[tutores[idx].numPets].nome, sizeof(tutores[idx].pets[0].nome), stdin);
    tutores[idx].pets[tutores[idx].numPets].nome[strcspn(tutores[idx].pets[tutores[idx].numPets].nome, "\n")] = 0;

    tutores[idx].numPets++;
    printf("Pet cadastrado com sucesso!\n");
    aguardarTecla();
}

// Atualiza o nome de um pet existente
void atualizarPet() {
    char cpf[20], nome[50];
    printf("Digite o CPF do tutor do pet: ");
    fgets(cpf, sizeof(cpf), stdin);
    cpf[strcspn(cpf, "\n")] = 0;

    int idx = buscarTutorPorCPF(cpf);
    if (idx == -1) {
        printf("Tutor não encontrado.\n");
        aguardarTecla();
        return;
    }

    printf("Digite o nome do pet: ");
    fgets(nome, sizeof(nome), stdin);
    nome[strcspn(nome, "\n")] = 0;

    for (int i = 0; i < tutores[idx].numPets; i++) {
        if (strcmp(tutores[idx].pets[i].nome, nome) == 0) {
            printf("Digite o novo nome do pet: ");
            fgets(tutores[idx].pets[i].nome, sizeof(tutores[idx].pets[i].nome), stdin);
            tutores[idx].pets[i].nome[strcspn(tutores[idx].pets[i].nome, "\n")] = 0;
            printf("Pet atualizado com sucesso!\n");
            aguardarTecla();
            return;
        }
    }

    printf("Pet não encontrado.\n");
    aguardarTecla();
}

// Exclui um pet de um tutor
void excluirPet() {
    char cpf[20], nome[50];
    printf("Digite o CPF do tutor do pet: ");
    fgets(cpf, sizeof(cpf), stdin);
    cpf[strcspn(cpf, "\n")] = 0;

    int idx = buscarTutorPorCPF(cpf);
    if (idx == -1) {
        printf("Tutor não encontrado.\n");
        aguardarTecla();
        return;
    }

    printf("Digite o nome do pet a ser excluído: ");
    fgets(nome, sizeof(nome), stdin);
    nome[strcspn(nome, "\n")] = 0;

    for (int i = 0; i < tutores[idx].numPets; i++) {
        if (strcmp(tutores[idx].pets[i].nome, nome) == 0) {
            for (int j = i; j < tutores[idx].numPets - 1; j++) {
                tutores[idx].pets[j] = tutores[idx].pets[j + 1];
            }
            tutores[idx].numPets--;
            printf("Pet excluído com sucesso!\n");
            aguardarTecla();
            return;
        }
    }

    printf("Pet não encontrado.\n");
    aguardarTecla();
}

// Função principal com o menu interativo
int main() {
    int opcao;

    do {
        limparTela();
        exibirMenu();
        scanf("%d", &opcao);
        limparBuffer();
        limparTela();

        switch (opcao) {
            case 1: listarTutores(); break;
            case 2: cadastrarTutor(); break;
            case 3: atualizarTutor(); break;
            case 4: excluirTutor(); break;
            case 5: listarPets(); break;
            case 6: cadastrarPet(); break;
            case 7: atualizarPet(); break;
            case 8: excluirPet(); break;
            case 0: printf("Encerrando o programa...\n"); break;
            default: printf("Opção inválida!\n"); aguardarTecla();
        }
    } while (opcao != 0);

    return 0;
}