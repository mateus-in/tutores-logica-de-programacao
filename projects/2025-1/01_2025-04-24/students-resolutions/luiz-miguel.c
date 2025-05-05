
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_PETS 3
#define MAX_TUTORES 10

typedef struct {
    int id;
    char nome[50];
} Pet;

typedef struct {
    int id;
    char nome[50];
    Pet pets[MAX_PETS];
    int numPets;
} Tutor;

void limparTela() {
    #ifdef _WIN32
        system("cls");
    #else
        system("clear");
    #endif
}

void aguardarTecla() {
    printf("\nPressione ENTER para voltar ao menu...");
    getchar();
}

void limparBuffer() {
    int c;
    while ((c = getchar()) != '\n' && c != EOF);
}

void exibirMenu() {
    printf("***** Gestão de Pets *****\n\n");
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

void listarTutores(Tutor tutores[], int totalTutores) {
    if (totalTutores == 0) {
        printf("Nenhum tutor cadastrado ainda.\n");
    } else {
        for (int i = 0; i < totalTutores; i++) {
            printf("Tutor #%d\n", i + 1);
            printf("ID: %d\n", tutores[i].id);
            printf("Nome: %s\n", tutores[i].nome);
            printf("Pets:\n");

            if (tutores[i].numPets == 0) {
                printf("  Nenhum pet cadastrado.\n");
            } else {
                for (int j = 0; j < tutores[i].numPets; j++) {
                    printf("  - %s (ID: %d)\n", tutores[i].pets[j].nome, tutores[i].pets[j].id);
                }
            }
            printf("--------------------------\n");
        }
    }
    aguardarTecla();
}

void cadastrarTutor(Tutor tutores[], int *totalTutores) {
    if (*totalTutores >= MAX_TUTORES) {
        printf("Limite de tutores atingido!\n");
        aguardarTecla();
        return;
    }

    char nome[50];
    printf("Digite o nome do novo tutor: ");
    fgets(nome, sizeof(nome), stdin);
    nome[strcspn(nome, "\n")] = 0;

    for (int i = 0; i < *totalTutores; i++) {
        if (strcmp(tutores[i].nome, nome) == 0) {
            printf("Tutor já cadastrado!\n");
            aguardarTecla();
            return;
        }
    }

    tutores[*totalTutores].id = *totalTutores + 1;
    strcpy(tutores[*totalTutores].nome, nome);
    tutores[*totalTutores].numPets = 0;
    (*totalTutores)++;

    printf("Tutor cadastrado com sucesso!\n");
    aguardarTecla();
}

void atualizarTutor(Tutor tutores[], int totalTutores) {
    char nome[50];
    printf("Digite o nome do tutor a ser atualizado: ");
    fgets(nome, sizeof(nome), stdin);
    nome[strcspn(nome, "\n")] = 0;

    for (int i = 0; i < totalTutores; i++) {
        if (strcmp(tutores[i].nome, nome) == 0) {
            printf("Digite o novo nome: ");
            fgets(tutores[i].nome, sizeof(tutores[i].nome), stdin);
            tutores[i].nome[strcspn(tutores[i].nome, "\n")] = 0;
            printf("Atualizado com sucesso!\n");
            aguardarTecla();
            return;
        }
    }

    printf("Tutor não encontrado!\n");
    aguardarTecla();
}

void excluirTutor(Tutor tutores[], int *totalTutores) {
    char nome[50];
    printf("Digite o nome do tutor a ser excluído: ");
    fgets(nome, sizeof(nome), stdin);
    nome[strcspn(nome, "\n")] = 0;

    for (int i = 0; i < *totalTutores; i++) {
        if (strcmp(tutores[i].nome, nome) == 0) {
            for (int j = i; j < *totalTutores - 1; j++) {
                tutores[j] = tutores[j + 1];
            }
            (*totalTutores)--;
            printf("Tutor excluído com sucesso!\n");
            aguardarTecla();
            return;
        }
    }

    printf("Tutor não encontrado!\n");
    aguardarTecla();
}

void listarPets(Tutor tutores[], int totalTutores) {
    int encontrou = 0;
    for (int i = 0; i < totalTutores; i++) {
        for (int j = 0; j < tutores[i].numPets; j++) {
            printf("Pet: %s (ID: %d), Tutor: %s\n", tutores[i].pets[j].nome, tutores[i].pets[j].id, tutores[i].nome);
            encontrou = 1;
        }
    }

    if (!encontrou) {
        printf("Nenhum pet cadastrado ainda.\n");
    }

    aguardarTecla();
}

void cadastrarPet(Tutor tutores[], int totalTutores) {
    char nomeTutor[50], nomePet[50];
    printf("Digite o nome do tutor: ");
    fgets(nomeTutor, sizeof(nomeTutor), stdin);
    nomeTutor[strcspn(nomeTutor, "\n")] = 0;

    for (int i = 0; i < totalTutores; i++) {
        if (strcmp(tutores[i].nome, nomeTutor) == 0) {
            if (tutores[i].numPets >= MAX_PETS) {
                printf("Esse tutor já possui o número máximo de pets.\n");
                aguardarTecla();
                return;
            }

            printf("Digite o nome do pet: ");
            fgets(nomePet, sizeof(nomePet), stdin);
            nomePet[strcspn(nomePet, "\n")] = 0;

            for (int j = 0; j < tutores[i].numPets; j++) {
                if (strcmp(tutores[i].pets[j].nome, nomePet) == 0) {
                    printf("Pet já cadastrado!\n");
                    aguardarTecla();
                    return;
                }
            }

            Pet novoPet;
            novoPet.id = tutores[i].numPets + 1;
            strcpy(novoPet.nome, nomePet);
            tutores[i].pets[tutores[i].numPets++] = novoPet;

            printf("Pet cadastrado com sucesso!\n");
            aguardarTecla();
            return;
        }
    }

    printf("Tutor não encontrado!\n");
    aguardarTecla();
}

void atualizarPet(Tutor tutores[], int totalTutores) {
    char nomePet[50];
    printf("Digite o nome do pet a ser atualizado: ");
    fgets(nomePet, sizeof(nomePet), stdin);
    nomePet[strcspn(nomePet, "\n")] = 0;

    for (int i = 0; i < totalTutores; i++) {
        for (int j = 0; j < tutores[i].numPets; j++) {
            if (strcmp(tutores[i].pets[j].nome, nomePet) == 0) {
                printf("Digite o novo nome para o pet: ");
                fgets(tutores[i].pets[j].nome, sizeof(tutores[i].pets[j].nome), stdin);
                tutores[i].pets[j].nome[strcspn(tutores[i].pets[j].nome, "\n")] = 0;
                printf("Pet atualizado com sucesso!\n");
                aguardarTecla();
                return;
            }
        }
    }

    printf("Pet não encontrado!\n");
    aguardarTecla();
}

void excluirPet(Tutor tutores[], int totalTutores) {
    char nomePet[50];
    printf("Digite o nome do pet a ser excluído: ");
    fgets(nomePet, sizeof(nomePet), stdin);
    nomePet[strcspn(nomePet, "\n")] = 0;

    for (int i = 0; i < totalTutores; i++) {
        for (int j = 0; j < tutores[i].numPets; j++) {
            if (strcmp(tutores[i].pets[j].nome, nomePet) == 0) {
                for (int k = j; k < tutores[i].numPets - 1; k++) {
                    tutores[i].pets[k] = tutores[i].pets[k + 1];
                }
                tutores[i].numPets--;
                printf("Pet excluído com sucesso!\n");
                aguardarTecla();
                return;
            }
        }
    }

    printf("Pet não encontrado!\n");
    aguardarTecla();
}

int main() {
    Tutor tutores[MAX_TUTORES];
    int totalTutores = 0;
    int opcao;

    do {
        limparTela();
        exibirMenu();
        scanf("%d", &opcao);
        limparBuffer();

        limparTela();

        switch (opcao) {
            case 1:
                listarTutores(tutores, totalTutores);
                break;
            case 2:
                cadastrarTutor(tutores, &totalTutores);
                break;
            case 3:
                atualizarTutor(tutores, totalTutores);
                break;
            case 4:
                excluirTutor(tutores, &totalTutores);
                break;
            case 5:
                listarPets(tutores, totalTutores);
                break;
            case 6:
                cadastrarPet(tutores, totalTutores);
                break;
            case 7:
                atualizarPet(tutores, totalTutores);
                break;
            case 8:
                excluirPet(tutores, totalTutores);
                break;
            case 0:
                printf("Encerrando o programa...\n");
                break;
            default:
                printf("Opção inválida!\n");
                aguardarTecla();
        }
    } while (opcao != 0);

    return 0;
}
