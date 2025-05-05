#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <locale.h>

#define MAX_PETS 3
#define MAX_TUTORES 10

int conferirCPF(char *cpf)
{
    if (strlen(cpf) != 11)
    {
        printf("CPF deve ter 11 d�gitos.\n");
        return 0;
    }
    for (int i = 0; i < 11; i++)
    {
        if (cpf[i] < '0' || cpf[i] > '9')
        {
            printf("CPF deve conter apenas d�gitos.\n");
            return 0;
        }
    }
    return 1;
}

int conferirNOME(char *nome)
{
    if (strlen(nome) == 0)
    {
        printf("Nome inv�lido!\n");
        return 0;
    }
    return 1;
}

typedef struct
{
    int ID;
    char nome[50];
} Pet;

typedef struct
{
    char CPF[20];
    char nome[50];
    Pet pets[MAX_PETS];
    int numPets;
} Tutor;

void limparTela()
{
#ifdef _WIN32
    system("cls");
#else
    system("clear");
#endif
}

void aguardarTecla()
{
    printf("\nPressione qualquer tecla para voltar ao menu...");
    getchar();
}

void limparBuffer()
{
    int c;
    while ((c = getchar()) != '\n' && c != EOF)
        ;
}

void exibirMenu()
{
    printf("===========Gestao de Pets===========\n\n");
    printf("1 - Listar os tutores cadastrados\n");
    printf("2 - Cadastrar um novo tutor\n");
    printf("3 - Atualizar um tutor cadastrado\n");
    printf("4 - Excluir um tutor cadastrado\n");
    printf("5 - Listar os pets cadastrados\n");
    printf("6 - Cadastrar um novo pet\n");
    printf("7 - Atualizar um pet cadastrado\n");
    printf("8 - Excluir um pet cadastrado\n");
    printf("0 - Sair\n\n");
    printf("Escolha uma opcao: ");
}


void listarTutores(Tutor *tutores, int totalTutores)
{
    printf("===========Tutores Cadastrados===========\n\n");
    if (totalTutores == 0)
    {
        printf("Nenhum tutor cadastrado!\n");
    }
    else
    {
        printf("lista de tutores:\n\n");
        for (int i = 0; i < totalTutores; i++)
        {
            printf("Tutor %d:\n", i + 1);
            printf("Nome: %s\n", tutores[i].nome);
            printf("CPF: %s\n", tutores[i].CPF);
            printf("Numero de pets: %d\n", tutores[i].numPets);
            for (int j = 0; j < tutores[i].numPets; j++)
            {
                printf("Pet %d: %s\n", j + 1, tutores[i].pets[j].nome);
            }
            printf("-------------------------\n");
        }
    }
    aguardarTecla();
}


void cadastrarTutor(Tutor *tutores, int *totalTutores)
{

    printf("===========Cadastro de Tutor===========\n\n");
    if (*totalTutores >= MAX_TUTORES)
    {
        printf("Numero maximo de tutores atingido!\n");
        aguardarTecla();
        return;
    }
    Tutor novoTutor;
    printf("Digite o CPF do tutor: ");
    scanf("%s", novoTutor.CPF);
    limparBuffer();

    if (!conferirCPF(novoTutor.CPF))
    {
        printf("CPF invalido!\n");
        aguardarTecla();
        return;
    }
    for (int j = 0; j < *totalTutores; j++)
    {
        if (strcmp(tutores[j].CPF, novoTutor.CPF) == 0)
        {
            printf("Ja existe um tutor cadastrado com este CPF!\n");
            aguardarTecla();
            return;
        }
    }
    printf("Digite o nome do tutor: ");
    fgets(novoTutor.nome, sizeof(novoTutor.nome), stdin);
    novoTutor.nome[strcspn(novoTutor.nome, "\n")] = 0; 
    novoTutor.numPets = 0;

    if (!conferirNOME(novoTutor.nome))
    {
        printf("Nome invalido!\n");
        aguardarTecla();
        return;
    }
    for (int i = 0; i < *totalTutores; i++)
    {
        if (strcmp(tutores[i].nome, novoTutor.nome) == 0)
        {
            printf("Ja existe um tutor cadastrado com esse nome!\n");
            aguardarTecla();
            return;
        }
    }

    tutores[*totalTutores] = novoTutor;
    (*totalTutores)++;
    printf("Tutor cadastrado com sucesso!\n");
    printf("Nome: %s\n", novoTutor.nome);
    printf("CPF: %s\n", novoTutor.CPF);

    printf("-------------------------\n");
    aguardarTecla();
}


void atualizarTutor(Tutor *tutores, int totalTutores)
{
    printf("===========Atualizacao de Tutor===========\n\n");

    char CPFbuscar[20];
    printf("Digite o CPF do tutor a ser atualizado: ");
    scanf("%s", CPFbuscar);
    limparBuffer();

    int encontrado = 0;
    for (int i = 0; i < totalTutores; i++)
    {
        if (strcmp(tutores[i].CPF, CPFbuscar) == 0)
        {
            encontrado = 1;

            char novoNome[50];
            printf("Digite o novo nome do tutor: ");
            fgets(novoNome, sizeof(novoNome), stdin);
            novoNome[strcspn(novoNome, "\n")] = 0; 

            
            for (int j = 0; j < totalTutores; j++)
            {
                if (j != i && strcmp(tutores[j].nome, novoNome) == 0)
                {
                    printf("Nao e possivel atualizar: ja existe um tutor com esse nome.\n");
                    aguardarTecla();
                    return;
                }
            }

            strcpy(tutores[i].nome, novoNome);
            printf("Tutor atualizado com sucesso!\n");
            aguardarTecla();
            return;
        }
    }

    if (!encontrado)
    {
        printf("Tutor nao encontrado!\n");
    }
}


void excluirTutor(Tutor *tutores, int *totalTutores)
{
    printf("===========Exclusao de Tutor===========\n\n");
    char CPFbuscar[20];
    printf("Digite o CPF do tutor a ser excluido: ");
    scanf("%s", CPFbuscar);
    limparBuffer();

    int encontrado = 0;
    for (int i = 0; i < *totalTutores; i++)
    {
        if (strcmp(tutores[i].CPF, CPFbuscar) == 0)
        {
            {
                for (int j = i; j < *totalTutores - 1; j++)
                {
                    tutores[j] = tutores[j + 1];
                }
                (*totalTutores)--;
                encontrado = 1;
                printf("Tutor excluido com sucesso!\n");
            }
        }
        if (!encontrado)
        {
            printf("Tutor nao encontrado!\n");
        }

    }
    aguardarTecla();
}


void listarPets(Tutor *tutores, int totalTutores)
{
    printf("===========Pets Cadastrados===========\n\n");

    int encontrouPets = 0;

    for (int i = 0; i < totalTutores; i++)
    {
        if (tutores[i].numPets > 0)
        {
            for (int j = 0; j < tutores[i].numPets; j++)
            {
                printf("Pet: %s\n", tutores[i].pets[j].nome);
                printf("ID do pet: %d\n", tutores[i].pets[j].ID);
                printf("Tutor: %s\n", tutores[i].nome);
                printf("CPF do tutor: %s\n", tutores[i].CPF);
                printf("-------------------------\n");

                encontrouPets = 1;
            }
        }
    }

    if (!encontrouPets)
    {
        printf("Nenhum pet cadastrado!\n");
    }

    aguardarTecla();
}


void cadastrarPet(Tutor *tutores, int totalTutores)
{
    printf("===========Cadastro de Pet===========\n\n");
    char nomeTutor[50];
    printf("Digite o nome do tutor do pet: ");
    fgets(nomeTutor, sizeof(nomeTutor), stdin);
    nomeTutor[strcspn(nomeTutor, "\n")] = 0; 

    for (int i = 0; i < totalTutores; i++)
    {
        if (strcmp(tutores[i].nome, nomeTutor) == 0)
        {
            if (tutores[i].numPets >= MAX_PETS)
            {
                printf("Numero maximo de pets atingido para esse tutor!\n");
                aguardarTecla();
                return;
            }
            else
            {
                Pet novoPet;
                printf("Digite o nome do pet: ");
                fgets(novoPet.nome, sizeof(novoPet.nome), stdin);
                novoPet.nome[strcspn(novoPet.nome, "\n")] = 0; 

                novoPet.ID = tutores[i].numPets + 1; 
                tutores[i].pets[tutores[i].numPets] = novoPet;
                tutores[i].numPets++;

                printf("Pet cadastrado com sucesso!\n");
                printf("Nome do pet: %s\n", novoPet.nome);
                printf("ID do pet: %d\n", novoPet.ID);
                printf("-------------------------\n");
                aguardarTecla();
                return;
            }
        }
    }
    
    printf("Tutor nao encontrado!\n");
    printf("Verifique se o nome do tutor foi digitado corretamente.\n");
    printf("Caso o nome esteja correto, cadastre o tutor antes de cadastrar o pet.\n");
    aguardarTecla();
}


void atualizarPet(Tutor *tutores, int totalTutores)
{
    printf("===========Atualizacao de Pet===========n\n");

    char nomePet[50];
    int encontrado = 0;

    printf("Digite o nome do pet que deseja atualizar: ");
    fgets(nomePet, sizeof(nomePet), stdin);
    nomePet[strcspn(nomePet, "\n")] = '\0'; 

    for (int i = 0; i < totalTutores; i++)
    {
        for (int j = 0; j < tutores[i].numPets; j++)
        {
            if (strcmp(tutores[i].pets[j].nome, nomePet) == 0)
            {
                printf("Pet encontrado!\n");
                printf("Nome atual: %s\n", tutores[i].pets[j].nome);

                printf("Digite o novo nome do pet: ");
                fgets(tutores[i].pets[j].nome, sizeof(tutores[i].pets[j].nome), stdin);
                tutores[i].pets[j].nome[strcspn(tutores[i].pets[j].nome, "\n")] = '\0'; 

                printf("Pet atualizado com sucesso.\n");
                encontrado = 1;
                break;
            }
        }
        if (encontrado)
            break;
    }

    if (!encontrado)
    {
        printf("Pet nao encontrado.\n");
    }

    aguardarTecla();
}


void excluirPet(Tutor *tutores, int totalTutores)
{
    printf("===========Exclusao de Pet===========*\n\n");
    char nomePet[50];
    int encontrado = 0;

    printf("Digite o nome do pet que deseja excluir: ");
    fgets(nomePet, sizeof(nomePet), stdin);
    nomePet[strcspn(nomePet, "\n")] = '\0'; 

    for (int i = 0; i < totalTutores; i++)
    {
        for (int j = 0; j < tutores[i].numPets; j++)
        {
            if (strcmp(tutores[i].pets[j].nome, nomePet) == 0)
            {
                encontrado = 1;

                
                for (int k = j; k < tutores[i].numPets - 1; k++)
                {
                    tutores[i].pets[k] = tutores[i].pets[k + 1];
                }

                tutores[i].numPets--;

                printf("Pet \"%s\" excluido com sucesso.\n", nomePet);
                break;
            }
        }
        if (encontrado)
            break;
    }

    if (!encontrado)
    {
        printf("Pet \"%s\" nao encontrado.\n", nomePet);
    }

    aguardarTecla();
}

int main()
{
  
    Tutor tutores[MAX_TUTORES];
    int totalTutores = 0;
    int opcao;
    setlocale(LC_ALL, "Portuguese_Brasil "); 

    do
    {
        limparTela();
        exibirMenu();
        scanf("%d", &opcao);
        limparBuffer();

        limparTela();

        switch (opcao)
        {
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
            printf("Opcao invalida!\n");
            aguardarTecla();
        }
    } while (opcao != 0);

    return 0;
}