#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_PETS 3
#define MAX_TUTORES 10

// Estrutura para representar um pet
typedef struct {
    int id;
    char nome[50];
} Pet;

// Estrutura para representar um tutor
typedef struct {
    int id;
    char cpf[15];
    char nome_completo[50];
    Pet pets[MAX_PETS];
    int totalAnimais; // Número de pets cadastrados
} Tutor;

// Função para limpar a tela do terminal
void limparTela() {
#ifdef _WIN32
    system("cls");
#else
    system("clear");
#endif
}

// Função para aguardar o usuário pressionar uma tecla
void aguardarTecla() {
    printf("\nPressione qualquer tecla para voltar ao menu...");
    getchar();
}

// Função para limpar o buffer do teclado
void limparBuffer() {
    int ch;
    while ((ch = getchar()) != '\n' && ch != EOF);
}

// Função para exibir o menu principal
void exibirMenu() {
    printf("*****Gestão de Pets*****\n\n");
    printf("1 - Listar tutores cadastrados\n");
    printf("2 - Cadastrar novo tutor\n");
    printf("3 - Atualizar tutor existente\n");
    printf("4 - Excluir tutor\n");
    printf("5 - Listar pets cadastrados\n");
    printf("6 - Cadastrar novo pet\n");
    printf("7 - Atualizar pet\n");
    printf("8 - Excluir pet\n");
    printf("0 - Sair\n\n");
    printf("Escolha uma opção: ");
}

// Função para listar os tutores cadastrados
void listarTutores(Tutor tutores[], int totalTutores) {
    if (totalTutores == 0) {
        printf("Nenhum tutor cadastrado.\n");
    } else {
        for (int i = 0; i < totalTutores; i++) {
            printf("ID: %d\nCPF: %s\nNome: %s\nTotal de Pets: %d\n-----------\n",
                   tutores[i].id, tutores[i].cpf, tutores[i].nome_completo, tutores[i].totalAnimais);
        }
    }
    aguardarTecla();
}

// Função para cadastrar um novo tutor
void cadastrarTutor(Tutor tutores[], int *totalTutores) {
    if (*totalTutores >= MAX_TUTORES) {
        printf("Limite de tutores atingido.\n");
        aguardarTecla();
        return;
    }

    Tutor novoTutor;
    novoTutor.id = *totalTutores + 1;

    printf("Informe o CPF do tutor: ");
    fgets(novoTutor.cpf, sizeof(novoTutor.cpf), stdin);
    novoTutor.cpf[strcspn(novoTutor.cpf, "\n")] = '\0'; // Remove o '\n' da string

    // Verifica se o CPF já está cadastrado
    for (int i = 0; i < *totalTutores; i++) {
        if (strcmp(tutores[i].cpf, novoTutor.cpf) == 0) {
            printf("Esse CPF já está cadastrado.\n");
            aguardarTecla();
            return;
        }
    }

    printf("Digite o nome completo do tutor: ");
    fgets(novoTutor.nome_completo, sizeof(novoTutor.nome_completo), stdin);
    novoTutor.nome_completo[strcspn(novoTutor.nome_completo, "\n")] = '\0'; // Remove o '\n'

    novoTutor.totalAnimais = 0; // Inicia com 0 pets
    tutores[*totalTutores] = novoTutor;
    (*totalTutores)++;

    printf("Tutor cadastrado com sucesso!\n");
    aguardarTecla();
}

// Função para atualizar os dados de um tutor
void atualizarTutor(Tutor tutores[], int totalTutores) {
    if (totalTutores == 0) {
        printf("Nenhum tutor cadastrado.\n");
        aguardarTecla();
        return;
    }

    char cpfBusca[15];
    printf("Informe o CPF do tutor a ser atualizado: ");
    fgets(cpfBusca, sizeof(cpfBusca), stdin);
    cpfBusca[strcspn(cpfBusca, "\n")] = '\0'; // Remove o '\n'

    for (int i = 0; i < totalTutores; i++) {
        if (strcmp(tutores[i].cpf, cpfBusca) == 0) {
            printf("Novo nome: ");
            fgets(tutores[i].nome_completo, sizeof(tutores[i].nome_completo), stdin);
            tutores[i].nome_completo[strcspn(tutores[i].nome_completo, "\n")] = '\0'; // Remove o '\n'

            printf("Novo CPF: ");
            fgets(tutores[i].cpf, sizeof(tutores[i].cpf), stdin);
            tutores[i].cpf[strcspn(tutores[i].cpf, "\n")] = '\0'; // Remove o '\n'

            printf("Atualização realizada com sucesso!\n");
            aguardarTecla();
            return;
        }
    }

    printf("Tutor não encontrado.\n");
    aguardarTecla();
}

// Função para excluir um tutor
void excluirTutor(Tutor tutores[], int *totalTutores) {
    if (*totalTutores == 0) {
        printf("Nenhum tutor cadastrado.\n");
        aguardarTecla();
        return;
    }

    char cpfExcluir[15];
    printf("Informe o CPF do tutor a ser excluído: ");
    fgets(cpfExcluir, sizeof(cpfExcluir), stdin);
    cpfExcluir[strcspn(cpfExcluir, "\n")] = '\0'; // Remove o '\n'

    for (int i = 0; i < *totalTutores; i++) {
        if (strcmp(tutores[i].cpf, cpfExcluir) == 0) {
            for (int j = i; j < *totalTutores - 1; j++) {
                tutores[j] = tutores[j + 1]; // Desloca os elementos
            }
            (*totalTutores)--;
            printf("Tutor excluído com sucesso!\n");
            aguardarTecla();
            return;
        }
    }

    printf("Tutor não encontrado.\n");
    aguardarTecla();
}

// Função para listar os pets cadastrados
void listarPets(Tutor tutores[], int totalTutores) {
    int encontrou = 0;
    for (int i = 0; i < totalTutores; i++) {
        if (tutores[i].totalAnimais > 0) {
            printf("Pets do Tutor: %s (CPF: %s)\n", tutores[i].nome_completo, tutores[i].cpf);
            for (int j = 0; j < tutores[i].totalAnimais; j++) {
                printf("  Pet: %s (ID: %d)\n", tutores[i].pets[j].nome, tutores[i].pets[j].id);
            }
            printf("-----------\n");
            encontrou = 1;
        }
    }

    if (!encontrou) {
        printf("Nenhum pet cadastrado.\n");
    }

    aguardarTecla();
}

// Função para cadastrar um novo pet para um tutor
void cadastrarPet(Tutor tutores[], int totalTutores) {
    char cpfBusca[15];
    printf("Informe o CPF do tutor: ");
    fgets(cpfBusca, sizeof(cpfBusca), stdin);
    cpfBusca[strcspn(cpfBusca, "\n")] = '\0'; // Remove o '\n'

    for (int i = 0; i < totalTutores; i++) {
        if (strcmp(tutores[i].cpf, cpfBusca) == 0) {
            if (tutores[i].totalAnimais >= MAX_PETS) {
                printf("Este tutor já tem o número máximo de pets.\n");
                aguardarTecla();
                return;
            }

            Pet novoPet;
            novoPet.id = tutores[i].totalAnimais + 1;

            printf("Informe o nome do pet: ");
            fgets(novoPet.nome, sizeof(novoPet.nome), stdin);
            novoPet.nome[strcspn(novoPet.nome, "\n")] = '\0'; // Remove o '\n'

            tutores[i].pets[tutores[i].totalAnimais] = novoPet;
            tutores[i].totalAnimais++;

            printf("Pet cadastrado com sucesso!\n");
            aguardarTecla();
            return;
        }
    }

    printf("Tutor não encontrado.\n");
    aguardarTecla();
}

// Função para atualizar dados de um pet
void atualizarPet(Tutor tutores[], int totalTutores) {
    char cpfBusca[15], nomePet[50];
    printf("Informe o CPF do tutor do pet: ");
    fgets(cpfBusca, sizeof(cpfBusca), stdin);
    cpfBusca[strcspn(cpfBusca, "\n")] = '\0'; // Remove o '\n'

    for (int i = 0; i < totalTutores; i++) {
        if (strcmp(tutores[i].cpf, cpfBusca) == 0) {
            printf("Informe o nome do pet a ser atualizado: ");
            fgets(nomePet, sizeof(nomePet), stdin);
            nomePet[strcspn(nomePet, "\n")] = '\0'; // Remove o '\n'

            for (int j = 0; j < tutores[i].totalAnimais; j++) {
                if (strcmp(tutores[i].pets[j].nome, nomePet) == 0) {
                    printf("Novo nome para o pet: ");
                    fgets(tutores[i].pets[j].nome, sizeof(tutores[i].pets[j].nome), stdin);
                    tutores[i].pets[j].nome[strcspn(tutores[i].pets[j].nome, "\n")] = '\0'; // Remove o '\n'

                    printf("Pet atualizado com sucesso!\n");
                    aguardarTecla();
                    return;
                }
            }
            printf("Pet não encontrado.\n");
            aguardarTecla();
            return;
        }
    }

    printf("Tutor não encontrado.\n");
    aguardarTecla();
}

// Função para excluir um pet de um tutor
void excluirPet(Tutor tutores[], int totalTutores) {
    char cpfBusca[15], nomeExcluir[50];
    printf("Informe o CPF do tutor do pet: ");
    fgets(cpfBusca, sizeof(cpfBusca), stdin);
    cpfBusca[strcspn(cpfBusca, "\n")] = '\0'; // Remove o '\n'

    for (int i = 0; i < totalTutores; i++) {
        if (strcmp(tutores[i].cpf, cpfBusca) == 0) {
            printf("Informe o nome do pet a ser excluído: ");
            fgets(nomeExcluir, sizeof(nomeExcluir), stdin);
            nomeExcluir[strcspn(nomeExcluir, "\n")] = '\0'; // Remove o '\n'

            for (int j = 0; j < tutores[i].totalAnimais; j++) {
                if (strcmp(tutores[i].pets[j].nome, nomeExcluir) == 0) {
                    // Desloca os pets após a exclusão
                    for (int k = j; k < tutores[i].totalAnimais - 1; k++) {
                        tutores[i].pets[k] = tutores[i].pets[k + 1];
                    }
                    tutores[i].totalAnimais--;
                    printf("Pet excluído com sucesso!\n");
                    aguardarTecla();
                    return;
                }
            }

            printf("Pet não encontrado.\n");
            aguardarTecla();
            return;
        }
    }

    printf("Tutor não encontrado.\n");
    aguardarTecla();
}

// Função principal para controle do programa
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