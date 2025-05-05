#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <ctype.h>

//definindo as variaveis fixas
#define MAX_TUTORES 10
#define MAX_PETS 3
#define TAM_NOME_T 50
#define TAM_CPF 12
#define TAM_NOME_P 20

//aqui cadastro os pets
typedef struct {
    char nome_pet[TAM_NOME_P];
    int ativo;
} Pet;

//cadastrando o tutor e adicionado os petes 
typedef struct {
    char nome_Tutor[TAM_NOME_T + 1];
    char cpf[TAM_CPF];
    Pet pets[MAX_PETS];
    int qtd_pets;
    int ativo;
} Tutor;

//
void limparTela() {
    #ifdef _WIN32
        system("cls");
    #else 
        system("clear");
    #endif    
}
//apos definir uma funçao aguarda enter de confirmacao
void aguardarTela() {
    printf("\nPressione Enter para continuar...");
    getchar();
}
//usei do programa do mateus mas nao entendi a sintace
void limparBuffer() {
    int c;
    while ((c = getchar()) != '\n' && c != EOF);
}

void linha() {
    printf("========================================\n");
}

//aqui mostramos o menu para o usuario
void exibirMenu() {
    linha();
    printf("         SISTEMA DE TUTORES E PETS       \n");
    linha();
    printf("1. Cadastrar tutor\n");
    printf("2. Editar tutor\n");
    printf("3. Listar tutores\n");
    printf("4. Excluir tutor\n");
    printf("5. Cadastrar pet\n");
    printf("6. Editar pet\n");
    printf("7. Listar pets\n");
    printf("8. Excluir pet\n");
    printf("0. Sair\n");
    linha();
    printf("Escolha uma opção: ");
}

//aqui nao permitimos 2 usuarios com mesmo cpf
int cpfExiste(Tutor *tutores, const char *cpf) {
    for (int i = 0; i < MAX_TUTORES; i++) {
        if (tutores[i].ativo && strcmp(tutores[i].cpf, cpf) == 0) {
            return 1;  
        }  
    }
    return 0;
}

//permite acessar o tutor cadastrado
int buscarTutorPorCPF(Tutor *tutores, int quant_tutores, const char *cpf) {
    for (int i = 0; i < quant_tutores; i++) {
        if (tutores[i].ativo && strcmp(tutores[i].cpf, cpf) == 0) {
            return i;
        }
    }
    return -1;
}

//cadastrando 1° tutor
void adicionarTutor(Tutor *tutores, int *quant_tutores) {
    limparTela();
    linha();
    printf("           CADASTRO DE TUTOR            \n");
    linha();
    //se atingir o maximo de tutores cadastrados
    if (*quant_tutores >= MAX_TUTORES) {
        printf("Máximo de tutores atingido!\n");
        aguardarTela();
        return;
    }
    // adicionando mais tutores
    Tutor novoTutor;

    printf("Nome do tutor: ");
    fgets(novoTutor.nome_Tutor, TAM_NOME_T, stdin);
    novoTutor.nome_Tutor[strcspn(novoTutor.nome_Tutor, "\n")] = '\0';

    printf("CPF do tutor: ");
    fgets(novoTutor.cpf, TAM_CPF, stdin);
    novoTutor.cpf[strcspn(novoTutor.cpf, "\n")] = '\0';
    // ao adicionar novo tutor nao permite mesmo cpf
    if (cpfExiste(tutores, novoTutor.cpf)) {
        printf("\n! CPF já cadastrado!\n");
        aguardarTela();
        return;
    }
    //adicionando pet para tutores ativos
    novoTutor.qtd_pets = 0;
    novoTutor.ativo = 1;
    tutores[*quant_tutores] = novoTutor;
    (*quant_tutores)++;
    //ao cadastrar da um retorno ao usuario
    printf("\n Tutor cadastrado com sucesso!\n");
    aguardarTela();
}

void listarTutores(Tutor *tutores, int quant_tutores) {
    limparTela();
    linha();
    printf("           LISTA DE TUTORES             \n");
    linha();
//abrindo contador de rutores cadastrados
    int encontrou = 0;
    for (int i = 0; i < quant_tutores; i++) {
        if (tutores[i].ativo) {
            printf("Tutor %d\n", i + 1);
            printf("Nome: %s\n", tutores[i].nome_Tutor);
            printf("CPF: %s\n", tutores[i].cpf);
            linha();
            encontrou = 1;
        }
    }
    if (!encontrou) {
        printf("Nenhum tutor cadastrado.\n");
    }
    aguardarTela();
}

void editarTutor(Tutor *tutores, int quant_tutores) {
    limparTela();
    linha();
    printf("            EDITAR TUTOR                \n");
    linha();

    char cpf[TAM_CPF];
    printf("Digite o CPF do tutor: ");
    fgets(cpf, TAM_CPF, stdin);
    cpf[strcspn(cpf, "\n")] = '\0';

    for (int i = 0; i < quant_tutores; i++) {
        if (tutores[i].ativo && strcmp(tutores[i].cpf, cpf) == 0) {
            printf("Novo nome: ");
            fgets(tutores[i].nome_Tutor, TAM_NOME_T, stdin);
            tutores[i].nome_Tutor[strcspn(tutores[i].nome_Tutor, "\n")] = '\0';
            printf("\nNome atualizado com sucesso!\n");
            aguardarTela();
            return;
        }
    }

    printf("\n! Tutor não encontrado.\n");
    aguardarTela();
}

void excluirTutor(Tutor *tutores, int *quant_tutores) {
    limparTela();
    linha();
    printf("           EXCLUIR TUTOR                \n");
    linha();

    char cpf[TAM_CPF];
    printf("Digite o CPF do tutor: ");
    fgets(cpf, TAM_CPF, stdin);
    cpf[strcspn(cpf, "\n")] = '\0';

    for (int i = 0; i < *quant_tutores; i++) {
        if (tutores[i].ativo && strcmp(tutores[i].cpf, cpf) == 0) {
            tutores[i].ativo = 0;
            printf("\nTutor excluído com sucesso.\n");
            aguardarTela();
            return;
        }
    }

    printf("\n! Tutor não encontrado.\n");
    aguardarTela();
}

void cadastrarPet(Tutor *tutores, int quant_tutores) {
    limparTela();
    linha();
    printf("           CADASTRAR PET                \n");
    linha();

    char cpf[TAM_CPF];
    printf("CPF do tutor: ");
    fgets(cpf, TAM_CPF, stdin);
    cpf[strcspn(cpf, "\n")] = '\0';

    int idx = buscarTutorPorCPF(tutores, quant_tutores, cpf);
    if (idx == -1) {
        printf("\n! Tutor não encontrado.\n");
        aguardarTela();
        return;
    }

    if (tutores[idx].qtd_pets >= MAX_PETS) {
        printf("\n! Limite de pets atingido para este tutor.\n");
        aguardarTela();
        return;
    }

    Pet novoPet;
    printf("Nome do pet: ");
    fgets(novoPet.nome_pet, TAM_NOME_P, stdin);
    novoPet.nome_pet[strcspn(novoPet.nome_pet, "\n")] = '\0';
    novoPet.ativo = 1;

    tutores[idx].pets[tutores[idx].qtd_pets++] = novoPet;
    printf("\n Pet cadastrado com sucesso!\n");
    aguardarTela();
}

void listarPets(Tutor *tutores, int quant_tutores) {
    limparTela();
    linha();
    printf("              LISTAR PETS               \n");
    linha();

    char cpf[TAM_CPF];
    printf("CPF do tutor: ");
    fgets(cpf, TAM_CPF, stdin);
    cpf[strcspn(cpf, "\n")] = '\0';

    int idx = buscarTutorPorCPF(tutores, quant_tutores, cpf);
    if (idx == -1) {
        printf("\nTutor não encontrado.\n");
        aguardarTela();
        return;
    }

    linha();
    printf("Tutor: %s\n", tutores[idx].nome_Tutor);
    printf("Pets:\n");

    int encontrou = 0;
    for (int i = 0; i < tutores[idx].qtd_pets; i++) {
        if (tutores[idx].pets[i].ativo) {
            printf("- %s\n", tutores[idx].pets[i].nome_pet);
            encontrou = 1;
        }
    }

    if (!encontrou) {
        printf("Nenhum pet cadastrado para este tutor.\n");
    }

    aguardarTela();
}

void editarPet(Tutor *tutores, int quant_tutores) {
    listarPets(tutores, quant_tutores);

    char cpf[TAM_CPF], nome_pet[TAM_NOME_P];
    printf("\nCPF do tutor: ");
    fgets(cpf, TAM_CPF, stdin);
    cpf[strcspn(cpf, "\n")] = '\0';

    int idx = buscarTutorPorCPF(tutores, quant_tutores, cpf);
    if (idx == -1) {
        printf("\nTutor não encontrado.\n");
        aguardarTela();
        return;
    }

    printf("Nome do pet a editar: ");
    fgets(nome_pet, TAM_NOME_P, stdin);
    nome_pet[strcspn(nome_pet, "\n")] = '\0';

    for (int i = 0; i < tutores[idx].qtd_pets; i++) {
        if (tutores[idx].pets[i].ativo && strcmp(tutores[idx].pets[i].nome_pet, nome_pet) == 0) {
            printf("Novo nome do pet: ");
            fgets(tutores[idx].pets[i].nome_pet, TAM_NOME_P, stdin);
            tutores[idx].pets[i].nome_pet[strcspn(tutores[idx].pets[i].nome_pet, "\n")] = '\0';
            printf("\n Pet atualizado com sucesso!\n");
            aguardarTela();
            return;
        }
    }

    printf("\nPet não encontrado.\n");
    aguardarTela();
}

void excluirPet(Tutor *tutores, int quant_tutores) {
    listarPets(tutores, quant_tutores);

    char cpf[TAM_CPF], nome_pet[TAM_NOME_P];
    printf("\nCPF do tutor: ");
    fgets(cpf, TAM_CPF, stdin);
    cpf[strcspn(cpf, "\n")] = '\0';

    int idx = buscarTutorPorCPF(tutores, quant_tutores, cpf);
    if (idx == -1) {
        printf("\n Tutor não encontrado.\n");
        aguardarTela();
        return;
    }

    printf("Nome do pet a excluir: ");
    fgets(nome_pet, TAM_NOME_P, stdin);
    nome_pet[strcspn(nome_pet, "\n")] = '\0';

    for (int i = 0; i < tutores[idx].qtd_pets; i++) {
        if (tutores[idx].pets[i].ativo && strcmp(tutores[idx].pets[i].nome_pet, nome_pet) == 0) {
            tutores[idx].pets[i].ativo = 0;
            printf("\n Pet excluído com sucesso.\n");
            aguardarTela();
            return;
        }
    }

    printf("\n Pet não encontrado.\n");
    aguardarTela();
}

int main() {
    Tutor tutores[MAX_TUTORES] = {0};
    int quant_tutores = 0;
    int opcao;

    do {
        limparTela();
        exibirMenu();
        scanf("%d", &opcao);
        limparBuffer();

        switch(opcao) 
        {
            case 1:
                 adicionarTutor(tutores, &quant_tutores);
                      break;
            case 2:
                 editarTutor(tutores, quant_tutores);
                  break;
            case 3: 
                listarTutores(tutores, quant_tutores);
                 break;
            case 4: 
                excluirTutor(tutores, &quant_tutores);
                 break;
            case 5: 
                cadastrarPet(tutores, quant_tutores);
                 break;
            case 6:
                 editarPet(tutores, quant_tutores);
                  break;
            case 7:
                 listarPets(tutores, quant_tutores);
              break;
            case 8: 
                excluirPet(tutores, quant_tutores);
                 break;
            case 0: 
                printf("\nSaindo do sistema...\n");
                 break;
            default:
             printf("\n[!] Opção inválida!\n");
              aguardarTela();
               break;
        }
    } while(opcao != 0);

    return 0;
}