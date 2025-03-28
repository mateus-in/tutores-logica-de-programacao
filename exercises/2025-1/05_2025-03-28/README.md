# Exercício: Sistema de Quiz em Grupo

## Enunciado
Neste exercício, vocês devem implementar um sistema de quiz (perguntas e respostas) em C, trabalhando em grupos. Cada grupo ficará responsável por implementar uma função específica do sistema.

## Data: 28/03/2025

## Funcionalidades
1. Cadastrar perguntas e respostas
2. Listar todas as perguntas cadastradas
3. Jogar quiz (responder às perguntas)
4. Mostrar pontuação atual
5. Classificar jogadores pelo placar
6. Buscar perguntas por tema
7. Apagar uma pergunta
8. Sair

## Estrutura do programa
O programa deve utilizar as seguintes estruturas de dados:

```c
#define MAX_PERGUNTAS 50
#define MAX_TEXTO 100
#define MAX_ALTERNATIVAS 4
#define MAX_JOGADORES 10

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
```

## Organização das equipes
A turma deve se organizar em 8 grupos. Cada grupo será responsável por implementar uma função específica:

1. **Grupo 1:** `void cadastrarPergunta(Pergunta *perguntas, int *totalPerguntas)`
   - Função que permite cadastrar uma nova pergunta no sistema

2. **Grupo 2:** `void listarPerguntas(Pergunta *perguntas)`
   - Função que lista todas as perguntas cadastradas no sistema

3. **Grupo 3:** `void jogarQuiz(Pergunta *perguntas, Jogador *jogadores, int *totalJogadores)`
   - Função principal do jogo que apresenta as perguntas ao jogador e registra as respostas

4. **Grupo 4:** `void mostrarPontuacao(Jogador *jogadores, int totalJogadores)`
   - Função que exibe a pontuação atual de todos os jogadores

5. **Grupo 5:** `void classificarJogadores(Jogador *jogadores, int totalJogadores)`
   - Função que ordena e exibe os jogadores por ordem de pontuação (maior para menor)

6. **Grupo 6:** `void buscarPerguntasPorTema(Pergunta *perguntas, char *tema)`
   - Função que busca e exibe todas as perguntas de um determinado tema

7. **Grupo 7:** `void apagarPergunta(Pergunta *perguntas, int *totalPerguntas)`
   - Função que permite excluir uma pergunta cadastrada

8. **Professor:** `void exibirMenu()`
   - Função que exibe o menu de opções (já implementada)

## Diretrizes
- Cada grupo deve implementar APENAS a função designada
- A comunicação entre os grupos é essencial para garantir a compatibilidade das funções
- Todas as funções devem ser documentadas com comentários explicativos
- A interface com o usuário deve seguir o padrão estabelecido no código base
- Implemente validações adequadas para cada função

## Dicas
- Use a função `limparTela()` antes de iniciar a interação com o usuário
- Use a função `aguardarTecla()` ao finalizar a interação
- Valide todas as entradas do usuário
- Para a função de jogo, apresente as perguntas uma por vez e registre as respostas
- Ao classificar jogadores, use o algoritmo de ordenação de sua preferência
- Ao cadastrar perguntas, verifique se há espaço disponível
- Para buscar perguntas por tema, faça uma comparação case-insensitive 