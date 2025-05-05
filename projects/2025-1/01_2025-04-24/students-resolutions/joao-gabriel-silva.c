#include <stdio.h>
#include <stdbool.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

// Definições de constantes
#define MAX_ALUNOS 100
#define MAX_DISCIPLINAS 20
#define MAX_NOME 100
#define MEDIA_APROVACAO 6.0
#define MAX_NOTAS 5

// Estrutura para Disciplina
typedef struct {
    char nome[MAX_NOME];
    int codigo;
} Disciplina;

// Estrutura para Aluno
typedef struct {
    char nome[MAX_NOME];
    int matricula;
    Disciplina disciplinas[MAX_DISCIPLINAS];
    int num_disciplinas;
    float notas[MAX_NOTAS];
    float media;
} Aluno;

// Variáveis globais
Aluno alunos[MAX_ALUNOS];
Disciplina disciplinas[MAX_DISCIPLINAS];
int total_alunos = 0;
int total_disciplinas = 10; // Inicializado com disciplinas pré-cadastradas

// Protótipos de funções
void inicializarSistema();
void limparTela();
void aguardarTecla();
void menuPrincipal();
void menuAlunos();
void menuDisciplinas();

// Funções para Alunos
void cadastrarAluno();
void listarAlunos();
void buscarAluno();
void excluirAluno();
void calcularMediaAluno();

// Funções para Disciplinas
void cadastrarDisciplina();
void listarDisciplinas();
void buscarDisciplina();
void excluirDisciplina();
void matricularAlunoDisciplina();

// Funções auxiliares
int buscarAlunoPorMatricula(int matricula);
int buscarDisciplinaPorCodigo(int codigo);
void toLowerString(char *str);

// Implementação das funções

void inicializarSistema() {
    // Disciplinas pré-cadastradas
    strcpy(disciplinas[0].nome, "Logica de programacao");
    disciplinas[0].codigo = 1001;
    strcpy(disciplinas[1].nome, "Redes e computadores");
    disciplinas[1].codigo = 1002;
    strcpy(disciplinas[2].nome, "Programacao orientada a objetos");
    disciplinas[2].codigo = 1003;
    strcpy(disciplinas[3].nome, "Programacao web");
    disciplinas[3].codigo = 1004;
    strcpy(disciplinas[4].nome, "Programacao de sistemas");
    disciplinas[4].codigo = 1005;
    strcpy(disciplinas[5].nome, "Criacao de sites");
    disciplinas[5].codigo = 1006;
    strcpy(disciplinas[6].nome, "Back-end");
    disciplinas[6].codigo = 1007;
    strcpy(disciplinas[7].nome, "Banco de dados web");
    disciplinas[7].codigo = 1008;
    strcpy(disciplinas[8].nome, "Estrutura de dados");
    disciplinas[8].codigo = 1009;
    strcpy(disciplinas[9].nome, "Ingles tecnico");
    disciplinas[9].codigo = 1010;
}

void limparTela() {
    #ifdef _WIN32
        system("cls");
    #else
        system("clear");
    #endif
}

void aguardarTecla() {
    printf("\nPressione ENTER para continuar...");
    while (getchar() != '\n'); // Limpa o buffer
    getchar(); // Aguarda nova tecla
}

void menuPrincipal() {
    int opcao;
    
    do {
        limparTela();
        printf("\n========== SISTEMA DE GESTAO ACADEMICA ==========\n");
        printf("1. Menu Alunos\n");
        printf("2. Menu Disciplinas\n");
        printf("3. Sair\n");
        printf("Escolha uma opcao: ");
        scanf("%d", &opcao);
        
        switch(opcao) {
            case 1:
                menuAlunos();
                break;
            case 2:
                menuDisciplinas();
                break;
            case 3:
                printf("Saindo do sistema...\n");
                exit(0);
            default:
                printf("Opcao invalida! Tente novamente.\n");
                aguardarTecla();
        }
    } while (opcao != 3);
}

void menuAlunos() {
    int opcao;
    
    do {
        limparTela();
        printf("\n========== MENU ALUNOS ==========\n");
        printf("1. Cadastrar Aluno\n");
        printf("2. Listar Alunos\n");
        printf("3. Buscar Aluno\n");
        printf("4. Excluir Aluno\n");
        printf("5. Calcular Media\n");
        printf("6. Matricular em Disciplina\n");
        printf("7. Voltar ao Menu Principal\n");
        printf("Escolha uma opcao: ");
        scanf("%d", &opcao);
        
        switch(opcao) {
            case 1:
                cadastrarAluno();
                break;
            case 2:
                listarAlunos();
                break;
            case 3:
                buscarAluno();
                break;
            case 4:
                excluirAluno();
                break;
            case 5:
                calcularMediaAluno();
                break;
            case 6:
                matricularAlunoDisciplina();
                break;
            case 7:
                return;
            default:
                printf("Opcao invalida! Tente novamente.\n");
                aguardarTecla();
        }
    } while (opcao != 7);
}

void menuDisciplinas() {
    int opcao;
    
    do {
        limparTela();
        printf("\n========== MENU DISCIPLINAS ==========\n");
        printf("1. Cadastrar Disciplina\n");
        printf("2. Listar Disciplinas\n");
        printf("3. Buscar Disciplina\n");
        printf("4. Excluir Disciplina\n");
        printf("5. Voltar ao Menu Principal\n");
        printf("Escolha uma opcao: ");
        scanf("%d", &opcao);
        
        switch(opcao) {
            case 1:
                cadastrarDisciplina();
                break;
            case 2:
                listarDisciplinas();
                break;
            case 3:
                buscarDisciplina();
                break;
            case 4:
                excluirDisciplina();
                break;
            case 5:
                return;
            default:
                printf("Opcao invalida! Tente novamente.\n");
                aguardarTecla();
        }
    } while (opcao != 5);
}

void cadastrarAluno() {
    limparTela();
    if (total_alunos >= MAX_ALUNOS) {
        printf("Limite de alunos atingido!\n");
        aguardarTecla();
        return;
    }
    
    printf("\n=== CADASTRO DE ALUNO ===\n");
    
    printf("Nome: ");
    scanf(" %[^\n]", alunos[total_alunos].nome);
    
    // Verifica se a matrícula já existe
    int matricula;
    bool matricula_existe;
    do {
        matricula_existe = false;
        printf("Matricula: ");
        scanf("%d", &matricula);
        
        for (int i = 0; i < total_alunos; i++) {
            if (alunos[i].matricula == matricula) {
                printf("Matricula ja existente! Digite outra.\n");
                matricula_existe = true;
                break;
            }
        }
    } while (matricula_existe);
    
    alunos[total_alunos].matricula = matricula;
    alunos[total_alunos].num_disciplinas = 0;
    
    // Inicializa notas
    for (int i = 0; i < MAX_NOTAS; i++) {
        alunos[total_alunos].notas[i] = 0.0;
    }
    alunos[total_alunos].media = 0.0;
    
    total_alunos++;
    printf("\nAluno cadastrado com sucesso!\n");
    aguardarTecla();
}

void listarAlunos() {
    limparTela();
    printf("\n=== LISTA DE ALUNOS ===\n");
    
    if (total_alunos == 0) {
        printf("Nenhum aluno cadastrado.\n");
    } else {
        for (int i = 0; i < total_alunos; i++) {
            printf("\nAluno %d:\n", i+1);
            printf("Nome: %s\n", alunos[i].nome);
            printf("Matricula: %d\n", alunos[i].matricula);
            printf("Disciplinas matriculadas: %d\n", alunos[i].num_disciplinas);
            
            if (alunos[i].num_disciplinas > 0) {
                printf("Disciplinas:\n");
                for (int j = 0; j < alunos[i].num_disciplinas; j++) {
                    printf("- %s (Codigo: %d)\n", 
                           alunos[i].disciplinas[j].nome, 
                           alunos[i].disciplinas[j].codigo);
                }
            }
            
            printf("Media: %.2f\n", alunos[i].media);
            printf("----------------------------\n");
        }
    }
    aguardarTecla();
}

void buscarAluno() {
    limparTela();
    printf("\n=== BUSCAR ALUNO ===\n");
    
    if (total_alunos == 0) {
        printf("Nenhum aluno cadastrado.\n");
        aguardarTecla();
        return;
    }
    
    int opcao;
    printf("1. Buscar por matricula\n");
    printf("2. Buscar por nome\n");
    printf("Escolha uma opcao: ");
    scanf("%d", &opcao);
    
    if (opcao == 1) {
        int matricula;
        printf("Digite a matricula: ");
        scanf("%d", &matricula);
        
        int index = buscarAlunoPorMatricula(matricula);
        if (index != -1) {
            printf("\nAluno encontrado:\n");
            printf("Nome: %s\n", alunos[index].nome);
            printf("Matricula: %d\n", alunos[index].matricula);
            printf("Disciplinas matriculadas: %d\n", alunos[index].num_disciplinas);
            
            if (alunos[index].num_disciplinas > 0) {
                printf("Disciplinas:\n");
                for (int j = 0; j < alunos[index].num_disciplinas; j++) {
                    printf("- %s (Codigo: %d)\n", 
                           alunos[index].disciplinas[j].nome, 
                           alunos[index].disciplinas[j].codigo);
                }
            }
            
            printf("Media: %.2f\n", alunos[index].media);
        } else {
            printf("Aluno nao encontrado.\n");
        }
    } else if (opcao == 2) {
        char nome[MAX_NOME];
        printf("Digite o nome: ");
        scanf(" %[^\n]", nome);
        
        bool encontrado = false;
        for (int i = 0; i < total_alunos; i++) {
            char nomeAluno[MAX_NOME];
            strcpy(nomeAluno, alunos[i].nome);
            toLowerString(nomeAluno);
            toLowerString(nome);
            
            if (strstr(nomeAluno, nome) != NULL) {
                printf("\nAluno encontrado:\n");
                printf("Nome: %s\n", alunos[i].nome);
                printf("Matricula: %d\n", alunos[i].matricula);
                printf("Disciplinas matriculadas: %d\n", alunos[i].num_disciplinas);
                
                if (alunos[i].num_disciplinas > 0) {
                    printf("Disciplinas:\n");
                    for (int j = 0; j < alunos[i].num_disciplinas; j++) {
                        printf("- %s (Codigo: %d)\n", 
                               alunos[i].disciplinas[j].nome, 
                               alunos[i].disciplinas[j].codigo);
                    }
                }
                
                printf("Media: %.2f\n", alunos[i].media);
                printf("----------------------------\n");
                encontrado = true;
            }
        }
        
        if (!encontrado) {
            printf("Nenhum aluno encontrado com esse nome.\n");
        }
    } else {
        printf("Opcao invalida!\n");
    }
    
    aguardarTecla();
}

void excluirAluno() {
    limparTela();
    printf("\n=== EXCLUIR ALUNO ===\n");
    
    if (total_alunos == 0) {
        printf("Nenhum aluno cadastrado.\n");
        aguardarTecla();
        return;
    }
    
    int matricula;
    printf("Digite a matricula do aluno a ser excluido: ");
    scanf("%d", &matricula);
    
    int index = buscarAlunoPorMatricula(matricula);
    if (index != -1) {
        // Move todos os alunos após o índice uma posição para trás
        for (int i = index; i < total_alunos - 1; i++) {
            alunos[i] = alunos[i + 1];
        }
        total_alunos--;
        printf("Aluno excluido com sucesso.\n");
    } else {
        printf("Aluno nao encontrado.\n");
    }
    
    aguardarTecla();
}

void calcularMediaAluno() {
    limparTela();
    printf("\n=== CALCULAR MEDIA ===\n");
    
    if (total_alunos == 0) {
        printf("Nenhum aluno cadastrado.\n");
        aguardarTecla();
        return;
    }
    
    int matricula;
    printf("Digite a matricula do aluno: ");
    scanf("%d", &matricula);
    
    int index = buscarAlunoPorMatricula(matricula);
    if (index != -1) {
        printf("\nAluno: %s\n", alunos[index].nome);
        printf("Matricula: %d\n", alunos[index].matricula);
        
        float soma = 0.0;
        printf("Notas:\n");
        for (int i = 0; i < MAX_NOTAS; i++) {
            printf("Nota %d: %.2f\n", i+1, alunos[index].notas[i]);
            soma += alunos[index].notas[i];
        }
        
        alunos[index].media = soma / MAX_NOTAS;
        printf("Media calculada: %.2f\n", alunos[index].media);
        
        if (alunos[index].media >= MEDIA_APROVACAO) {
            printf("Situacao: Aprovado\n");
        } else {
            printf("Situacao: Reprovado\n");
        }
    } else {
        printf("Aluno nao encontrado.\n");
    }
    
    aguardarTecla();
}

void cadastrarDisciplina() {
    limparTela();
    if (total_disciplinas >= MAX_DISCIPLINAS) {
        printf("Limite de disciplinas atingido!\n");
        aguardarTecla();
        return;
    }
    
    printf("\n=== CADASTRO DE DISCIPLINA ===\n");
    
    printf("Nome: ");
    scanf(" %[^\n]", disciplinas[total_disciplinas].nome);
    
    // Verifica se o código já existe
    int codigo;
    bool codigo_existe;
    do {
        codigo_existe = false;
        printf("Codigo: ");
        scanf("%d", &codigo);
        
        for (int i = 0; i < total_disciplinas; i++) {
            if (disciplinas[i].codigo == codigo) {
                printf("Codigo ja existente! Digite outro.\n");
                codigo_existe = true;
                break;
            }
        }
    } while (codigo_existe);
    
    disciplinas[total_disciplinas].codigo = codigo;
    total_disciplinas++;
    printf("\nDisciplina cadastrada com sucesso!\n");
    aguardarTecla();
}

void listarDisciplinas() {
    limparTela();
    printf("\n=== LISTA DE DISCIPLINAS ===\n");
    
    if (total_disciplinas == 0) {
        printf("Nenhuma disciplina cadastrada.\n");
    } else {
        for (int i = 0; i < total_disciplinas; i++) {
            printf("\nDisciplina %d:\n", i+1);
            printf("Nome: %s\n", disciplinas[i].nome);
            printf("Codigo: %d\n", disciplinas[i].codigo);
            printf("----------------------------\n");
        }
    }
    aguardarTecla();
}

void buscarDisciplina() {
    limparTela();
    printf("\n=== BUSCAR DISCIPLINA ===\n");
    
    if (total_disciplinas == 0) {
        printf("Nenhuma disciplina cadastrada.\n");
        aguardarTecla();
        return;
    }
    
    int opcao;
    printf("1. Buscar por codigo\n");
    printf("2. Buscar por nome\n");
    printf("Escolha uma opcao: ");
    scanf("%d", &opcao);
    
    if (opcao == 1) {
        int codigo;
        printf("Digite o codigo: ");
        scanf("%d", &codigo);
        
        int index = buscarDisciplinaPorCodigo(codigo);
        if (index != -1) {
            printf("\nDisciplina encontrada:\n");
            printf("Nome: %s\n", disciplinas[index].nome);
            printf("Codigo: %d\n", disciplinas[index].codigo);
        } else {
            printf("Disciplina nao encontrada.\n");
        }
    } else if (opcao == 2) {
        char nome[MAX_NOME];
        printf("Digite o nome: ");
        scanf(" %[^\n]", nome);
        
        bool encontrada = false;
        for (int i = 0; i < total_disciplinas; i++) {
            char nomeDisciplina[MAX_NOME];
            strcpy(nomeDisciplina, disciplinas[i].nome);
            toLowerString(nomeDisciplina);
            toLowerString(nome);
            
            if (strstr(nomeDisciplina, nome) != NULL) {
                printf("\nDisciplina encontrada:\n");
                printf("Nome: %s\n", disciplinas[i].nome);
                printf("Codigo: %d\n", disciplinas[i].codigo);
                printf("----------------------------\n");
                encontrada = true;
            }
        }
        
        if (!encontrada) {
            printf("Nenhuma disciplina encontrada com esse nome.\n");
        }
    } else {
        printf("Opcao invalida!\n");
    }
    
    aguardarTecla();
}

void excluirDisciplina() {
    limparTela();
    printf("\n=== EXCLUIR DISCIPLINA ===\n");
    
    if (total_disciplinas == 0) {
        printf("Nenhuma disciplina cadastrada.\n");
        aguardarTecla();
        return;
    }
    
    int codigo;
    printf("Digite o codigo da disciplina a ser excluida: ");
    scanf("%d", &codigo);
    
    int index = buscarDisciplinaPorCodigo(codigo);
    if (index != -1) {
        // Verifica se a disciplina está matriculada por algum aluno
        bool em_uso = false;
        for (int i = 0; i < total_alunos; i++) {
            for (int j = 0; j < alunos[i].num_disciplinas; j++) {
                if (alunos[i].disciplinas[j].codigo == codigo) {
                    em_uso = true;
                    break;
                }
            }
            if (em_uso) break;
        }
        
        if (em_uso) {
            printf("Esta disciplina esta sendo utilizada por alunos e nao pode ser excluida.\n");
        } else {
            // Move todas as disciplinas após o índice uma posição para trás
            for (int i = index; i < total_disciplinas - 1; i++) {
                disciplinas[i] = disciplinas[i + 1];
            }
            total_disciplinas--;
            printf("Disciplina excluida com sucesso.\n");
        }
    } else {
        printf("Disciplina nao encontrada.\n");
    }
    
    aguardarTecla();
}

void matricularAlunoDisciplina() {
    limparTela();
    printf("\n=== MATRICULAR ALUNO EM DISCIPLINA ===\n");
    
    if (total_alunos == 0) {
        printf("Nenhum aluno cadastrado.\n");
        aguardarTecla();
        return;
    }
    
    if (total_disciplinas == 0) {
        printf("Nenhuma disciplina cadastrada.\n");
        aguardarTecla();
        return;
    }
    
    int matricula;
    printf("Digite a matricula do aluno: ");
    scanf("%d", &matricula);
    
    int aluno_index = buscarAlunoPorMatricula(matricula);
    if (aluno_index == -1) {
        printf("Aluno nao encontrado.\n");
        aguardarTecla();
        return;
    }
    
    if (alunos[aluno_index].num_disciplinas >= MAX_DISCIPLINAS) {
        printf("Este aluno ja esta matriculado no maximo de disciplinas permitidas.\n");
        aguardarTecla();
        return;
    }
    
    printf("\nDisciplinas disponiveis:\n");
    for (int i = 0; i < total_disciplinas; i++) {
        printf("%d. %s (Codigo: %d)\n", i+1, disciplinas[i].nome, disciplinas[i].codigo);
    }
    
    int codigo;
    printf("\nDigite o codigo da disciplina: ");
    scanf("%d", &codigo);
    
    int disciplina_index = buscarDisciplinaPorCodigo(codigo);
    if (disciplina_index == -1) {
        printf("Disciplina nao encontrada.\n");
        aguardarTecla();
        return;
    }
    
    // Verifica se o aluno já está matriculado nesta disciplina
    for (int i = 0; i < alunos[aluno_index].num_disciplinas; i++) {
        if (alunos[aluno_index].disciplinas[i].codigo == codigo) {
            printf("Este aluno ja esta matriculado nesta disciplina.\n");
            aguardarTecla();
            return;
        }
    }
    
    // Matricula o aluno na disciplina
    alunos[aluno_index].disciplinas[alunos[aluno_index].num_disciplinas] = disciplinas[disciplina_index];
    alunos[aluno_index].num_disciplinas++;
    
    printf("\nMatricula realizada com sucesso!\n");
    printf("Aluno: %s\n", alunos[aluno_index].nome);
    printf("Disciplina: %s\n", disciplinas[disciplina_index].nome);
    
    aguardarTecla();
}

// Funções auxiliares
int buscarAlunoPorMatricula(int matricula) {
    for (int i = 0; i < total_alunos; i++) {
        if (alunos[i].matricula == matricula) {
            return i;
        }
    }
    return -1;
}

int buscarDisciplinaPorCodigo(int codigo) {
    for (int i = 0; i < total_disciplinas; i++) {
        if (disciplinas[i].codigo == codigo) {
            return i;
        }
    }
    return -1;
}

void toLowerString(char *str) {
    for (int i = 0; str[i]; i++) {
        str[i] = tolower(str[i]);
    }
}

int main() {
    inicializarSistema();
    menuPrincipal();
    return 0;
}