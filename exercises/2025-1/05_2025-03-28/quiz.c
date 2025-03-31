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

/* 
 * void cadastrarPergunta(Pergunta *perguntas, int *totalPerguntas)
 * Função que permite cadastrar uma nova pergunta no sistema
 * Grupo 1
 */
void cadastrarPergunta(Pergunta *perguntas, int *totalPerguntas) {
    printf("*****Cadastrar Pergunta*****\n\n");
    
    if (*totalPerguntas >= MAX_PERGUNTAS) {
        printf("Erro: Número máximo de perguntas atingido.\n");
        aguardarTecla();
        return;
    }
    
    int novoId = 1;
    // Encontrar o próximo ID disponível
    for (int i = 0; i < MAX_PERGUNTAS; i++) {
        if (perguntas[i].ativo && perguntas[i].id >= novoId) {
            novoId = perguntas[i].id + 1;
        }
    }
    
    // Encontrar posição livre no array
    int posicao = -1;
    for (int i = 0; i < MAX_PERGUNTAS; i++) {
        if (!perguntas[i].ativo) {
            posicao = i;
            break;
        }
    }
    
    if (posicao == -1) {
        printf("Erro: Não há espaço disponível.\n");
        aguardarTecla();
        return;
    }
    
    Pergunta novaPergunta;
    novaPergunta.id = novoId;
    novaPergunta.ativo = 1;
    
    printf("Digite o texto da pergunta: ");
    fgets(novaPergunta.texto, MAX_TEXTO, stdin);
    novaPergunta.texto[strcspn(novaPergunta.texto, "\n")] = '\0'; // Remove quebra de linha
    
    printf("Digite o tema da pergunta: ");
    fgets(novaPergunta.tema, 30, stdin);
    novaPergunta.tema[strcspn(novaPergunta.tema, "\n")] = '\0'; // Remove quebra de linha
    
    printf("\nDigite as 4 alternativas:\n");
    for (int i = 0; i < MAX_ALTERNATIVAS; i++) {
        printf("Alternativa %d: ", i + 1);
        fgets(novaPergunta.alternativas[i], MAX_TEXTO, stdin);
        novaPergunta.alternativas[i][strcspn(novaPergunta.alternativas[i], "\n")] = '\0';
    }
    
    do {
        printf("\nQual é a alternativa correta (1-4)? ");
        scanf("%d", &novaPergunta.alternativa_correta);
        limparBuffer();
        
        novaPergunta.alternativa_correta--; // Ajustar para o índice 0-3
        
    } while (novaPergunta.alternativa_correta < 0 || novaPergunta.alternativa_correta >= MAX_ALTERNATIVAS);
    
    perguntas[posicao] = novaPergunta;
    (*totalPerguntas)++;
    
    printf("\nPergunta cadastrada com sucesso!\n");
    aguardarTecla();
}

/*
 * void listarPerguntas(Pergunta *perguntas)
 * Função que lista todas as perguntas cadastradas no sistema
 * Grupo 2
 */
void listarPerguntas(Pergunta *perguntas) {
    printf("*****Listar Perguntas*****\n\n");
    
    int encontrouPerguntas = 0;
    
    for (int i = 0; i < MAX_PERGUNTAS; i++) {
        if (perguntas[i].ativo) {
            encontrouPerguntas = 1;
            printf("ID: %d\n", perguntas[i].id);
            printf("Tema: %s\n", perguntas[i].tema);
            printf("Pergunta: %s\n", perguntas[i].texto);
            printf("Alternativas:\n");
            
            for (int j = 0; j < MAX_ALTERNATIVAS; j++) {
                printf("%d) %s\n", j + 1, perguntas[i].alternativas[j]);
            }
            
            printf("Resposta correta: %d\n", perguntas[i].alternativa_correta + 1);
            printf("----------------------------------------\n");
        }
    }
    
    if (!encontrouPerguntas) {
        printf("Não há perguntas cadastradas.\n");
    }
    
    aguardarTecla();
}

/*
 * void jogarQuiz(Pergunta *perguntas, Jogador *jogadores, int *totalJogadores)
 * Função principal do jogo que apresenta as perguntas ao jogador e registra as respostas
 * Grupo 3
 */
void jogarQuiz(Pergunta *perguntas, Jogador *jogadores, int *totalJogadores) {
    printf("*****Jogar Quiz*****\n\n");
    
    // Verificar se há perguntas cadastradas
    int perguntasAtivas = 0;
    for (int i = 0; i < MAX_PERGUNTAS; i++) {
        if (perguntas[i].ativo) {
            perguntasAtivas++;
        }
    }
    
    if (perguntasAtivas == 0) {
        printf("Não há perguntas cadastradas para jogar.\n");
        aguardarTecla();
        return;
    }
    
    // Verificar se há espaço para novo jogador
    if (*totalJogadores >= MAX_JOGADORES) {
        printf("Número máximo de jogadores atingido.\n");
        aguardarTecla();
        return;
    }
    
    // Cadastrar novo jogador
    Jogador novoJogador;
    printf("Digite seu nome: ");
    fgets(novoJogador.nome, 50, stdin);
    novoJogador.nome[strcspn(novoJogador.nome, "\n")] = '\0';
    novoJogador.pontuacao = 0;
    
    // Iniciar o jogo
    printf("\nBem-vindo(a) %s! Vamos começar o quiz.\n", novoJogador.nome);
    printf("Responda às perguntas escolhendo o número da alternativa correta.\n\n");
    aguardarTecla();
    
    // Percorrer e apresentar cada pergunta ativa
    for (int i = 0; i < MAX_PERGUNTAS; i++) {
        if (perguntas[i].ativo) {
            limparTela();
            printf("Pergunta: %s\n\n", perguntas[i].texto);
            
            for (int j = 0; j < MAX_ALTERNATIVAS; j++) {
                printf("%d) %s\n", j + 1, perguntas[i].alternativas[j]);
            }
            
            int resposta;
            printf("\nSua resposta (1-4): ");
            scanf("%d", &resposta);
            limparBuffer();
            
            resposta--; // Ajustar para índice 0-3
            
            if (resposta == perguntas[i].alternativa_correta) {
                printf("\nResposta CORRETA! +1 ponto\n");
                novoJogador.pontuacao++;
            } else {
                printf("\nResposta INCORRETA!\n");
                printf("A resposta correta era: %d) %s\n", 
                       perguntas[i].alternativa_correta + 1, 
                       perguntas[i].alternativas[perguntas[i].alternativa_correta]);
            }
            
            aguardarTecla();
        }
    }
    
    // Mostrar resultado final
    limparTela();
    printf("*****Resultado Final*****\n\n");
    printf("Jogador: %s\n", novoJogador.nome);
    printf("Pontuação: %d\n", novoJogador.pontuacao);
    
    // Adicionar jogador à lista
    jogadores[*totalJogadores] = novoJogador;
    (*totalJogadores)++;
    
    printf("\nJogo concluído! Sua pontuação foi registrada.\n");
    aguardarTecla();
}

/*
 * void mostrarPontuacao(Jogador *jogadores, int totalJogadores)
 * Função que exibe a pontuação atual de todos os jogadores
 * Grupo 4
 */
void mostrarPontuacao(Jogador *jogadores, int totalJogadores) {
    printf("*****Pontuações Atuais*****\n\n");
    
    if (totalJogadores == 0) {
        printf("Não há jogadores registrados.\n");
    } else {
        printf("%-30s | %s\n", "Nome", "Pontuação");
        printf("-------------------------------------\n");
        
        for (int i = 0; i < totalJogadores; i++) {
            printf("%-30s | %d\n", jogadores[i].nome, jogadores[i].pontuacao);
        }
    }
    
    aguardarTecla();
}

/*
 * void classificarJogadores(Jogador *jogadores, int totalJogadores)
 * Função que ordena e exibe os jogadores por ordem de pontuação (maior para menor)
 * Grupo 5
 */
void classificarJogadores(Jogador *jogadores, int totalJogadores) {
    printf("*****Classificação de Jogadores*****\n\n");
    
    if (totalJogadores == 0) {
        printf("Não há jogadores registrados.\n");
        aguardarTecla();
        return;
    }
    
    // Criar uma cópia dos jogadores para ordenar
    Jogador jogadoresOrdenados[MAX_JOGADORES];
    for (int i = 0; i < totalJogadores; i++) {
        jogadoresOrdenados[i] = jogadores[i];
    }
    
    // Ordenar por pontuação (algoritmo de seleção - selection sort)
    for (int i = 0; i < totalJogadores - 1; i++) {
        int indiceMaximo = i;
        
        for (int j = i + 1; j < totalJogadores; j++) {
            if (jogadoresOrdenados[j].pontuacao > jogadoresOrdenados[indiceMaximo].pontuacao) {
                indiceMaximo = j;
            }
        }
        
        if (indiceMaximo != i) {
            Jogador temp = jogadoresOrdenados[i];
            jogadoresOrdenados[i] = jogadoresOrdenados[indiceMaximo];
            jogadoresOrdenados[indiceMaximo] = temp;
        }
    }
    
    // Exibir classificação
    printf("Classificação:\n");
    printf("%-5s | %-30s | %s\n", "Pos.", "Nome", "Pontuação");
    printf("------------------------------------------\n");
    
    for (int i = 0; i < totalJogadores; i++) {
        printf("%-5d | %-30s | %d\n", i + 1, jogadoresOrdenados[i].nome, jogadoresOrdenados[i].pontuacao);
    }
    
    aguardarTecla();
}

/*
 * void buscarPerguntasPorTema(Pergunta *perguntas, char *tema)
 * Função que busca e exibe todas as perguntas de um determinado tema
 * Grupo 6
 */
void buscarPerguntasPorTema(Pergunta *perguntas, char *tema) {
    printf("*****Perguntas do Tema: %s*****\n\n", tema);
    
    // Converter o tema de busca para minúsculas
    char temaBusca[30];
    strcpy(temaBusca, tema);
    for (int i = 0; temaBusca[i]; i++) {
        temaBusca[i] = tolower(temaBusca[i]);
    }
    
    int encontrou = 0;
    
    for (int i = 0; i < MAX_PERGUNTAS; i++) {
        if (perguntas[i].ativo) {
            // Converter o tema da pergunta para minúsculas para comparação
            char temaAtual[30];
            strcpy(temaAtual, perguntas[i].tema);
            for (int j = 0; temaAtual[j]; j++) {
                temaAtual[j] = tolower(temaAtual[j]);
            }
            
            // Verificar se o tema da busca está contido no tema da pergunta
            if (strstr(temaAtual, temaBusca) != NULL) {
                encontrou = 1;
                
                printf("ID: %d\n", perguntas[i].id);
                printf("Tema: %s\n", perguntas[i].tema);
                printf("Pergunta: %s\n", perguntas[i].texto);
                printf("Alternativas:\n");
                
                for (int j = 0; j < MAX_ALTERNATIVAS; j++) {
                    printf("%d) %s\n", j + 1, perguntas[i].alternativas[j]);
                }
                
                printf("Resposta correta: %d\n", perguntas[i].alternativa_correta + 1);
                printf("----------------------------------------\n");
            }
        }
    }
    
    if (!encontrou) {
        printf("Nenhuma pergunta encontrada com o tema '%s'.\n", tema);
    }
    
    aguardarTecla();
}

/*
 * void apagarPergunta(Pergunta *perguntas, int *totalPerguntas)
 * Função que permite excluir uma pergunta cadastrada
 * Grupo 7
 */
void apagarPergunta(Pergunta *perguntas, int *totalPerguntas) {
    printf("*****Apagar Pergunta*****\n\n");
    
    if (*totalPerguntas == 0) {
        printf("Não há perguntas cadastradas para excluir.\n");
        aguardarTecla();
        return;
    }
    
    // Listar as perguntas disponíveis
    printf("Perguntas cadastradas:\n");
    printf("%-5s | %-30s | %s\n", "ID", "Tema", "Pergunta");
    printf("---------------------------------------------------------------------\n");
    
    for (int i = 0; i < MAX_PERGUNTAS; i++) {
        if (perguntas[i].ativo) {
            printf("%-5d | %-30s | %.30s%s\n", 
                   perguntas[i].id, 
                   perguntas[i].tema, 
                   perguntas[i].texto,
                   strlen(perguntas[i].texto) > 30 ? "..." : "");
        }
    }
    
    // Solicitar o ID da pergunta a ser excluída
    int idExcluir;
    printf("\nDigite o ID da pergunta que deseja excluir: ");
    scanf("%d", &idExcluir);
    limparBuffer();
    
    // Procurar a pergunta com o ID informado
    int encontrou = 0;
    
    for (int i = 0; i < MAX_PERGUNTAS; i++) {
        if (perguntas[i].ativo && perguntas[i].id == idExcluir) {
            encontrou = 1;
            
            // Confirmar exclusão
            char confirmacao;
            printf("\nPergunta: %s\n", perguntas[i].texto);
            printf("Tem certeza que deseja excluir esta pergunta? (S/N): ");
            scanf("%c", &confirmacao);
            limparBuffer();
            
            if (toupper(confirmacao) == 'S') {
                // Marcar como inativa
                perguntas[i].ativo = 0;
                (*totalPerguntas)--;
                printf("\nPergunta excluída com sucesso!\n");
            } else {
                printf("\nOperação cancelada pelo usuário.\n");
            }
            
            break;
        }
    }
    
    if (!encontrou) {
        printf("\nERRO: Pergunta com ID %d não encontrada.\n", idExcluir);
    }
    
    aguardarTecla();
} 