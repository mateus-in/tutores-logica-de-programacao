#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

#define MAX_PERGUNTAS 50
#define MAX_TEXTO 100
#define MAX_ALTERNATIVAS 4
#define MAX_JOGADORES 10

// Definição das estruturas
typedef struct {
    int id;
    char texto[MAX_TEXTO];
    char alternativas[MAX_ALTERNATIVAS][MAX_TEXTO];
    int alternativa_correta; // 0 a 3
    char tema[30];
    int ativo; // 0 = inativo, 1 = ativo
} Pergunta;

typedef struct {
    char nome[50];
    int pontuacao;
} Jogador;

// Funções utilitárias
void limparTela() {
    #ifdef _WIN32
        system("cls");
    #else
        system("clear");
    #endif
}

void aguardarTecla() {
    printf("\nPressione qualquer tecla para voltar ao menu...");
    getchar();
}

void limparBuffer() {
    int c;
    while ((c = getchar()) != '\n' && c != EOF);
}

// Função implementada pelo professor
void exibirMenu() {
    printf("*****Sistema de Quiz*****\n\n");
    printf("1 - Cadastrar pergunta\n");
    printf("2 - Listar perguntas\n");
    printf("3 - Jogar quiz\n");
    printf("4 - Mostrar pontuação\n");
    printf("5 - Classificar jogadores\n");
    printf("6 - Buscar perguntas por tema\n");
    printf("7 - Apagar pergunta\n");
    printf("0 - Sair\n\n");
    printf("Escolha uma opção: ");
}

// Declaração das funções a serem implementadas pelos grupos
void cadastrarPergunta(Pergunta *perguntas, int *totalPerguntas);
void listarPerguntas(Pergunta *perguntas);
void jogarQuiz(Pergunta *perguntas, Jogador *jogadores, int *totalJogadores);
void mostrarPontuacao(Jogador *jogadores, int totalJogadores);
void classificarJogadores(Jogador *jogadores, int totalJogadores);
void buscarPerguntasPorTema(Pergunta *perguntas, char *tema);
void apagarPergunta(Pergunta *perguntas, int *totalPerguntas);

int main() {
    // Declaração dos arrays e variáveis de controle
    Pergunta perguntas[MAX_PERGUNTAS];
    Jogador jogadores[MAX_JOGADORES];
    int totalPerguntas = 0;
    int totalJogadores = 0;
    int opcao;
    char tema[30];

    // Inicializar todas as perguntas como inativas
    for (int i = 0; i < MAX_PERGUNTAS; i++) {
        perguntas[i].ativo = 0;
    }
    
    // Loop principal do programa
    do {
        limparTela();
        exibirMenu();
        scanf("%d", &opcao);
        limparBuffer();
        
        limparTela();
        
        switch (opcao) {
            case 1:
                cadastrarPergunta(perguntas, &totalPerguntas);
                break;
            case 2:
                listarPerguntas(perguntas);
                break;
            case 3:
                jogarQuiz(perguntas, jogadores, &totalJogadores);
                break;
            case 4:
                mostrarPontuacao(jogadores, totalJogadores);
                break;
            case 5:
                classificarJogadores(jogadores, totalJogadores);
                break;
            case 6:
                printf("*****Buscar Perguntas por Tema*****\n\n");
                printf("Digite o tema: ");
                fgets(tema, 30, stdin);
                // Remover o \n do final da string
                size_t len = strlen(tema);
                if (len > 0 && tema[len-1] == '\n') {
                    tema[len-1] = '\0';
                }
                buscarPerguntasPorTema(perguntas, tema);
                break;
            case 7:
                apagarPergunta(perguntas, &totalPerguntas);
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

// As implementações das funções serão feitas pelos grupos

/* 
 * void cadastrarPergunta(Pergunta *perguntas, int *totalPerguntas)
 * Função que permite cadastrar uma nova pergunta no sistema
 * Grupo 1
 */

/*
 * void listarPerguntas(Pergunta *perguntas)
 * Função que lista todas as perguntas cadastradas no sistema
 * Grupo 2
 */

/*
 * void jogarQuiz(Pergunta *perguntas, Jogador *jogadores, int *totalJogadores)
 * Função principal do jogo que apresenta as perguntas ao jogador e registra as respostas
 * Grupo 3
 */

/*
 * void mostrarPontuacao(Jogador *jogadores, int totalJogadores)
 * Função que exibe a pontuação atual de todos os jogadores
 * Grupo 4
 */

/*
 * void classificarJogadores(Jogador *jogadores, int totalJogadores)
 * Função que ordena e exibe os jogadores por ordem de pontuação (maior para menor)
 * Grupo 5
 */

/*
 * void buscarPerguntasPorTema(Pergunta *perguntas, char *tema)
 * Função que busca e exibe todas as perguntas de um determinado tema
 * Grupo 6
 */

/*
 * void apagarPergunta(Pergunta *perguntas, int *totalPerguntas)
 * Função que permite excluir uma pergunta cadastrada
 * Grupo 7
 */ 