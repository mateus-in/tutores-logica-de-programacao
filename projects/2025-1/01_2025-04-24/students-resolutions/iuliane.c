#include <stdio.h>
#include <string.h>

// Definição de constantes para o número máximo de tutores e pets
#define MAX_TUTORES 10
#define MAX_PETS 3

// Estrutura que define um Pet
typedef struct {
    char nomePet[50];        // Nome do pet
    char nomeTutor[50];      // Nome do tutor associado ao pet
    char cpfTutor[15];       // CPF do tutor associado ao pet
} Pet;

// Estrutura que define um Tutor
typedef struct {
    char nome[50];           // Nome do tutor
    char cpf[15];            // CPF do tutor
    Pet pets[MAX_PETS];      // Vetor para armazenar até 3 pets por tutor
    int numPets;            // Quantidade de pets cadastrados para o tutor
} Tutor;

// Função para cadastrar um novo tutor
void cadastrarTutor(Tutor tutores[], int *numTutores) {
    // Verifica se o número máximo de tutores já foi alcançado
    if (*numTutores >= MAX_TUTORES) {
        printf("Limite de tutores alcançado!\n");
        return;
    }

    // Solicita os dados do tutor
    printf("\nCadastrar Tutor\n");
    printf("Digite o CPF do tutor: ");
    scanf("%s", tutores[*numTutores].cpf);
    printf("Digite o nome do tutor: ");
    scanf(" %[^\n]", tutores[*numTutores].nome);

    // Inicializa o número de pets do tutor como 0
    tutores[*numTutores].numPets = 0;

    // Incrementa o número de tutores cadastrados
    (*numTutores)++;
}

// Função para editar o nome de um tutor
void editarTutor(Tutor tutores[], int numTutores) {
    char cpf[15];
    printf("\nEditar Tutor\n");
    printf("Digite o CPF do tutor a ser editado: ");
    scanf("%s", cpf);

    // Busca o tutor pelo CPF e permite editar o nome
    for (int i = 0; i < numTutores; i++) {
        if (strcmp(tutores[i].cpf, cpf) == 0) {
            printf("Digite o novo nome do tutor: ");
            scanf(" %[^\n]", tutores[i].nome);
            return;
        }
    }

    // Caso o CPF não seja encontrado
    printf("Tutor não encontrado!\n");
}

// Função para listar todos os tutores cadastrados
void listarTutores(Tutor tutores[], int numTutores) {
    printf("\nTutores cadastrados:\n");
    // Exibe o CPF e o nome de todos os tutores
    for (int i = 0; i < numTutores; i++) {
        printf("CPF: %s, Nome: %s\n", tutores[i].cpf, tutores[i].nome);
    }
}

// Função para excluir um tutor
void excluirTutor(Tutor tutores[], int *numTutores) {
    char cpf[15];
    printf("\nExcluir Tutor\n");
    printf("Digite o CPF do tutor a ser excluído: ");
    scanf("%s", cpf);

    // Busca o tutor pelo CPF
    for (int i = 0; i < *numTutores; i++) {
        if (strcmp(tutores[i].cpf, cpf) == 0) {
            // Remove todos os pets do tutor
            tutores[i].numPets = 0;

            // Desloca os outros tutores para preencher o espaço
            for (int j = i; j < *numTutores - 1; j++) {
                tutores[j] = tutores[j + 1];
            }
            (*numTutores)--;  // Decrementa o número de tutores
            printf("Tutor excluído com sucesso!\n");
            return;
        }
    }

    // Caso o CPF não seja encontrado
    printf("Tutor não encontrado!\n");
}

// Função para cadastrar um novo pet para um tutor
void cadastrarPet(Tutor tutores[], int numTutores) {
    char cpf[15];
    printf("\nCadastrar Pet\n");
    printf("Digite o CPF do tutor: ");
    scanf("%s", cpf);

    // Busca o tutor pelo CPF
    for (int i = 0; i < numTutores; i++) {
        if (strcmp(tutores[i].cpf, cpf) == 0) {
            // Verifica se o tutor já tem o número máximo de pets
            if (tutores[i].numPets >= MAX_PETS) {
                printf("Este tutor já tem o máximo de pets!\n");
                return;
            }

            // Solicita os dados do pet
            printf("Digite o nome do pet: ");
            scanf(" %[^\n]", tutores[i].pets[tutores[i].numPets].nomePet);
            strcpy(tutores[i].pets[tutores[i].numPets].nomeTutor, tutores[i].nome);
            strcpy(tutores[i].pets[tutores[i].numPets].cpfTutor, tutores[i].cpf);

            // Incrementa o número de pets do tutor
            tutores[i].numPets++;
            printf("Pet cadastrado com sucesso!\n");
            return;
        }
    }

    // Caso o CPF do tutor não seja encontrado
    printf("Tutor não encontrado!\n");
}

// Função para listar todos os pets de um tutor
void listarPets(Tutor tutores[], int numTutores) {
    char cpf[15];
    printf("\nListar Pets\n");
    printf("Digite o CPF do tutor: ");
    scanf("%s", cpf);

    // Busca o tutor pelo CPF
    for (int i = 0; i < numTutores; i++) {
        if (strcmp(tutores[i].cpf, cpf) == 0) {
            printf("Pets do tutor %s (CPF: %s):\n", tutores[i].nome, tutores[i].cpf);
            // Exibe o nome de todos os pets do tutor
            for (int j = 0; j < tutores[i].numPets; j++) {
                printf("Nome do Pet: %s\n", tutores[i].pets[j].nomePet);
            }
            return;
        }
    }

    // Caso o CPF do tutor não seja encontrado
    printf("Tutor não encontrado!\n");
}

// Função para excluir um pet de um tutor
void excluirPet(Tutor tutores[], int numTutores) {
    char cpf[15], nomePet[50];
    printf("\nExcluir Pet\n");
    printf("Digite o CPF do tutor: ");
    scanf("%s", cpf);
    printf("Digite o nome do pet a ser excluído: ");
    scanf(" %[^\n]", nomePet);

    // Busca o tutor pelo CPF
    for (int i = 0; i < numTutores; i++) {
        if (strcmp(tutores[i].cpf, cpf) == 0) {
            // Busca o pet pelo nome
            for (int j = 0; j < tutores[i].numPets; j++) {
                if (strcmp(tutores[i].pets[j].nomePet, nomePet) == 0) {
                    // Desloca os outros pets para preencher o espaço
                    for (int k = j; k < tutores[i].numPets - 1; k++) {
                        tutores[i].pets[k] = tutores[i].pets[k + 1];
                    }
                    tutores[i].numPets--;  // Decrementa o número de pets
                    printf("Pet excluído com sucesso!\n");
                    return;
                }
            }
            printf("Pet não encontrado!\n");
            return;
        }
    }

    // Caso o CPF do tutor não seja encontrado
    printf("Tutor não encontrado!\n");
}

// Função principal do programa
int main() {
    Tutor tutores[MAX_TUTORES];  // Array para armazenar os tutores
    int numTutores = 0;          // Contador de tutores cadastrados
    int opcao;                    // Variável para armazenar a escolha do menu

    do {
        // Exibe o menu de opções
        printf("\nMenu Principal:\n");
        printf("1. Cadastrar Tutor\n");
        printf("2. Editar Tutor\n");
        printf("3. Listar Tutores Cadastrados\n");
        printf("4. Excluir Tutor\n");
        printf("5. Cadastrar Pet\n");
        printf("6. Listar Pets\n");
        printf("7. Excluir Pet\n");
        printf("8. Sair\n");
        printf("Escolha uma opção: ");
        scanf("%d", &opcao);

        // Chama a função correspondente com base na opção escolhida
        switch (opcao) {
            case 1: cadastrarTutor(tutores, &numTutores); break;
            case 2: editarTutor(tutores, numTutores); break;
            case 3: listarTutores(tutores, numTutores); break;
            case 4: excluirTutor(tutores, &numTutores); break;
            case 5: cadastrarPet(tutores, numTutores); break;
            case 6: listarPets(tutores, numTutores); break;
            case 7: excluirPet(tutores, numTutores); break;
            case 8: printf("Saindo...\n"); break;
            default: printf("Opção inválida! Tente novamente.\n"); break;
        }
    } while (opcao != 8);  // O loop continua até o usuário escolher sair

    return 0;
}