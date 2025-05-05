#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <locale.h>

#define MAX_PETS 3
#define MAX_TUTORES 10
#define TAM_NOME 50

typedef struct {
    int id;
    char nome[TAM_NOME];
    int ativo;
} Pet;

typedef struct {
    int id;
    char nome[TAM_NOME];
    Pet pets[MAX_PETS];
    int ativo;
    int quantidadePets;
} Tutor;

void limparTela() {
#ifdef _WIN32
    system("cls");
#else
    system("clear");
#endif
}

void limparBuffer() {
    int c;
    while ((c = getchar()) != '\n' && c != EOF);
}

void aguardarTecla() {
    printf("\nPressione ENTER para continuar...");
    getchar();
}

void menu() {
    printf("\nVETERINÁRIA PRONTO VET\n");
    printf("------- MENU ---------\n");
    printf("[1] Cadastrar Tutor\n");
    printf("[2] Listar Tutores\n");
    printf("[3] Atualizar Tutor\n");
    printf("[4] Excluir Tutor\n");
    printf("[5] Cadastrar Pet\n");
    printf("[6] Listar Pets\n");
    printf("[7] Atualizar Pet\n");
    printf("[8] Excluir Pet\n");
    printf("[0] Sair\n");
    printf("----------------------\n");
    printf("Opção: ");
}

void cadastrarTutor(Tutor *tutores, int *contador) {
    if (*contador >= MAX_TUTORES) {
        printf("Limite máximo de tutores atingido!\n");
        aguardarTecla();
        return;
    }

    Tutor novo;
    novo.ativo = 1;
    novo.quantidadePets = 0;

    printf("ID do Tutor: ");
    scanf("%d", &novo.id);
    limparBuffer();

    for (int i = 0; i < MAX_TUTORES; i++) {
        if (tutores[i].ativo && tutores[i].id == novo.id) {
            printf("Este ID já está em uso.\n");
            aguardarTecla();
            return;
        }
    }

    printf("Nome do Tutor: ");
    fgets(novo.nome, TAM_NOME, stdin);
    novo.nome[strcspn(novo.nome, "\n")] = '\0';

    for (int i = 0; i < MAX_TUTORES; i++) {
        if (!tutores[i].ativo) {
            tutores[i] = novo;
            (*contador)++;
            printf("Tutor cadastrado com sucesso!\n");
            aguardarTecla();
            return;
        }
    }
}

void listarTutores(Tutor *tutores) {
    int encontrados = 0;
    printf("\n----- Lista de Tutores -----\n");
    for (int i = 0; i < MAX_TUTORES; i++) {
        if (tutores[i].ativo) {
            printf("ID: %d\nNome: %s\nPets: %d\n", tutores[i].id, tutores[i].nome, tutores[i].quantidadePets);
            for (int j = 0; j < tutores[i].quantidadePets; j++) {
                if (tutores[i].pets[j].ativo)
                    printf("  - Pet %d: %s\n", tutores[i].pets[j].id, tutores[i].pets[j].nome);
            }
            printf("----------------------\n");
            encontrados++;
        }
    }

    if (encontrados == 0)
        printf("Nenhum tutor encontrado.\n");

    aguardarTecla();
}

void atualizarTutor(Tutor *tutores) {
    int id, encontrado = 0;
    printf("Digite o ID do tutor que deseja atualizar: ");
    scanf("%d", &id);
    limparBuffer();

    for (int i = 0; i < MAX_TUTORES; i++) {
        if (tutores[i].ativo && tutores[i].id == id) {
            printf("Nome atual: %s\n", tutores[i].nome);
            printf("Novo nome: ");
            fgets(tutores[i].nome, TAM_NOME, stdin);
            tutores[i].nome[strcspn(tutores[i].nome, "\n")] = '\0';
            printf("Tutor atualizado com sucesso!\n");
            encontrado = 1;
            break;
        }
    }

    if (!encontrado)
        printf("Tutor não encontrado.\n");

    aguardarTecla();
}

void excluirTutor(Tutor *tutores, int *contador) {
    int id, encontrado = 0;
    printf("Digite o ID do tutor que deseja excluir: ");
    scanf("%d", &id);
    limparBuffer();

    for (int i = 0; i < MAX_TUTORES; i++) {
        if (tutores[i].ativo && tutores[i].id == id) {
            tutores[i].ativo = 0;
            (*contador)--;
            printf("Tutor excluído com sucesso!\n");
            encontrado = 1;
            break;
        }
    }

    if (!encontrado)
        printf("Tutor não encontrado.\n");

    aguardarTecla();
}

void cadastrarPet(Tutor *tutores) {
    int idTutor;
    printf("ID do tutor para cadastrar o pet: ");
    scanf("%d", &idTutor);
    limparBuffer();

    for (int i = 0; i < MAX_TUTORES; i++) {
        if (tutores[i].ativo && tutores[i].id == idTutor) {
            if (tutores[i].quantidadePets >= MAX_PETS) {
                printf("Este tutor já possui o número máximo de pets!\n");
                aguardarTecla();
                return;
            }

            Pet novo;
            novo.ativo = 1;

            printf("ID do Pet: ");
            scanf("%d", &novo.id);
            limparBuffer();

            for (int j = 0; j < tutores[i].quantidadePets; j++) {
                if (tutores[i].pets[j].ativo && tutores[i].pets[j].id == novo.id) {
                    printf("ID de pet já existe para esse tutor!\n");
                    aguardarTecla();
                    return;
                }
            }

            printf("Nome do Pet: ");
            fgets(novo.nome, TAM_NOME, stdin);
            novo.nome[strcspn(novo.nome, "\n")] = '\0';

            tutores[i].pets[tutores[i].quantidadePets++] = novo;
            printf("Pet cadastrado com sucesso!\n");
            aguardarTecla();
            return;
        }
    }

    printf("Tutor não encontrado.\n");
    aguardarTecla();
}

void listarPets(Tutor *tutores) {
    int total = 0;
    printf("------ Lista de Pets ------\n");
    for (int i = 0; i < MAX_TUTORES; i++) {
        if (tutores[i].ativo) {
            for (int j = 0; j < tutores[i].quantidadePets; j++) {
                if (tutores[i].pets[j].ativo) {
                    printf("Tutor: %s | Pet ID: %d | Nome: %s\n", tutores[i].nome, tutores[i].pets[j].id, tutores[i].pets[j].nome);
                    total++;
                }
            }
        }
    }
    if (total == 0)
        printf("Nenhum pet encontrado.\n");
    aguardarTecla();
}

void atualizarPet(Tutor *tutores) {
    int idTutor, idPet, encontrado = 0;
    printf("ID do tutor do pet: ");
    scanf("%d", &idTutor);
    limparBuffer();

    for (int i = 0; i < MAX_TUTORES; i++) {
        if (tutores[i].ativo && tutores[i].id == idTutor) {
            printf("ID do pet: ");
            scanf("%d", &idPet);
            limparBuffer();

            for (int j = 0; j < tutores[i].quantidadePets; j++) {
                if (tutores[i].pets[j].ativo && tutores[i].pets[j].id == idPet) {
                    printf("Nome atual: %s\n", tutores[i].pets[j].nome);
                    printf("Novo nome: ");
                    fgets(tutores[i].pets[j].nome, TAM_NOME, stdin);
                    tutores[i].pets[j].nome[strcspn(tutores[i].pets[j].nome, "\n")] = '\0';
                    printf("Pet atualizado com sucesso!\n");
                    encontrado = 1;
                    break;
                }
            }
        }
    }

    if (!encontrado)
        printf("Pet não encontrado.\n");
    aguardarTecla();
}

void excluirPet(Tutor *tutores) {
    int idTutor, idPet;
    printf("ID do tutor do pet: ");
    scanf("%d", &idTutor);
    limparBuffer();

    for (int i = 0; i < MAX_TUTORES; i++) {
        if (tutores[i].ativo && tutores[i].id == idTutor) {
            printf("ID do pet: ");
            scanf("%d", &idPet);
            limparBuffer();

            for (int j = 0; j < tutores[i].quantidadePets; j++) {
                if (tutores[i].pets[j].ativo && tutores[i].pets[j].id == idPet) {
                    tutores[i].pets[j].ativo = 0;
                    printf("Pet excluído com sucesso!\n");
                    aguardarTecla();
                    return;
                }
            }
        }
    }

    printf("Pet ou tutor não encontrado.\n");
    aguardarTecla();
}

int main() {
    setlocale(LC_ALL, "C"); // Evita problemas com acentuação no terminal

    Tutor tutores[MAX_TUTORES] = {0};
    int contadorTutores = 0;
    int opcao;

    do {
        limparTela();
        menu();
        scanf("%d", &opcao);
        limparBuffer();

        limparTela();

        switch (opcao) {
        case 1:
            cadastrarTutor(tutores, &contadorTutores);
            break;
        case 2:
            listarTutores(tutores);
            break;
        case 3:
            atualizarTutor(tutores);
            break;
        case 4:
            excluirTutor(tutores, &contadorTutores);
            break;
        case 5:
            cadastrarPet(tutores);
            break;
        case 6:
            listarPets(tutores);
            break;
        case 7:
            atualizarPet(tutores);
            break;
        case 8:
            excluirPet(tutores);
            break;
        case 0:
            printf("Encerrando programa...\n");
            break;
        default:
            printf("Opção inválida!\n");
            aguardarTecla();
        }
    } while (opcao != 0);

    return 0;
}