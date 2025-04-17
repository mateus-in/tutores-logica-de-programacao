# Maratona de Programação - Lógica de Programação em C (7 Desafios)

Bem-vindos à nossa Maratona de Programação! O objetivo hoje é praticar os conceitos de C que aprendemos em aula. Teremos 7 desafios com diferentes níveis de dificuldade. Concentrem-se, leiam atentamente os enunciados e testem seus códigos com os exemplos fornecidos e outros casos que imaginarem. Boa sorte e divirtam-se codando!

---

## Questões Fáceis (4)

### 1. Soma de Pares
*   **Tópicos:** I/O Básico, Laço de Repetição (`for` ou `while`), Estrutura de Decisão (`if`).
*   **Enunciado:** Escreva um programa que leia um número inteiro `N`, seguido por `N` números inteiros. O programa deve calcular e imprimir a soma apenas dos números pares dentre os `N` números lidos.
*   **Entrada:**
    *   A primeira linha contém um inteiro `N` (1 <= N <= 100).
    *   As `N` linhas seguintes contêm um inteiro cada.
*   **Saída:**
    *   Um único inteiro representando a soma dos números pares.
*   **Exemplo:**
    *   Entrada:
        ```
        5
        10
        3
        8
        5
        2
        ```
    *   Saída:
        ```
        20
        ```

### 2. Classificador de Caractere
*   **Tópicos:** I/O Básico, Estrutura de Decisão (`if-else if-else`).
*   **Enunciado:** Escreva um programa que leia um único caractere e identifique se ele é uma letra maiúscula, uma letra minúscula, um dígito numérico ou outro tipo de símbolo.
*   **Entrada:**
    *   Uma única linha contendo um caractere.
*   **Saída:**
    *   Imprimir "MAIUSCULA", "MINUSCULA", "DIGITO" ou "OUTRO".
*   **Exemplo 1:**
    *   Entrada: `A`
    *   Saída: `MAIUSCULA`
*   **Exemplo 2:**
    *   Entrada: `7`
    *   Saída: `DIGITO`
*   **Exemplo 3:**
    *   Entrada: `*`
    *   Saída: `OUTRO`

### 3. Contagem em Vetor
*   **Tópicos:** I/O Básico, Vetor (Array), Laço de Repetição.
*   **Enunciado:** Escreva um programa que leia 5 números inteiros para um vetor. Em seguida, leia mais um número inteiro `X`. O programa deve contar e imprimir quantas vezes o número `X` aparece no vetor.
*   **Entrada:**
    *   Cinco linhas, cada uma contendo um inteiro para o vetor.
    *   Uma sexta linha contendo o inteiro `X`.
*   **Saída:**
    *   Um único inteiro indicando a frequência de `X` no vetor.
*   **Exemplo:**
    *   Entrada:
        ```
        2
        5
        2
        8
        2
        2
        ```
    *   Saída:
        ```
        3
        ```

### 4. Tamanho da String (Manual)
*   **Tópicos:** I/O Básico (Strings), String como Vetor de Caracteres, Laço de Repetição.
*   **Enunciado:** Escreva um programa que leia uma string (com no máximo 50 caracteres). Calcule e imprima o tamanho dessa string *sem usar a função `strlen`* da biblioteca `<string.h>`. Lembre-se que strings em C terminam com o caractere nulo `\0`.
*   **Entrada:**
    *   Uma linha contendo a string.
*   **Saída:**
    *   Um inteiro representando o tamanho da string.
*   **Exemplo:**
    *   Entrada: `Ola Mundo`
    *   Saída: `9`

---

## Questões Intermediárias (2)

### 5. Inversão de Vetor com Função
*   **Tópicos:** Vetor, Laço de Repetição, Função, Ponteiros (passagem de vetor para função).
*   **Enunciado:** Escreva uma função chamada `void inverteVetor(int vet[], int tamanho)` que recebe um vetor de inteiros e seu tamanho, e inverte a ordem dos elementos *dentro do próprio vetor* (in-place). No programa principal (`main`), leia um inteiro `N`, leia `N` inteiros para um vetor, chame a função `inverteVetor` e, por fim, imprima o vetor invertido, com os elementos separados por espaço.
*   **Entrada:**
    *   A primeira linha contém o inteiro `N` (1 <= N <= 100).
    *   A segunda linha contém `N` inteiros separados por espaço.
*   **Saída:**
    *   Os `N` inteiros do vetor invertido, separados por espaço.
*   **Exemplo:**
    *   Entrada:
        ```
        6
        10 20 30 40 50 60
        ```
    *   Saída:
        ```
        60 50 40 30 20 10
        ```

### 6. Matriz Transposta
*   **Tópicos:** Matriz (Array Bidimensional), Laços Aninhados, I/O.
*   **Enunciado:** Escreva um programa que leia as dimensões `M` e `N` de uma matriz (1 <= M, N <= 50). Em seguida, leia os `M * N` elementos inteiros da matriz. O programa deve calcular e imprimir a matriz transposta (N x M). Na matriz transposta, as linhas da original viram colunas e as colunas viram linhas.
*   **Entrada:**
    *   A primeira linha contém dois inteiros `M` e `N`.
    *   As `M` linhas seguintes contêm `N` inteiros cada, representando a matriz.
*   **Saída:**
    *   Imprimir as `N` linhas da matriz transposta, com `M` inteiros em cada linha, separados por espaço.
*   **Exemplo:**
    *   Entrada:
        ```
        2 3
        1 2 3
        4 5 6
        ```
    *   Saída:
        ```
        1 4
        2 5
        3 6
        ```

---

## Questão Difícil (1)

### 7. Contador de Palavras
*   **Tópicos:** String (manipulação), Laço de Repetição, Lógica de Estado, Ponteiros (opcional, para percorrer a string).
*   **Enunciado:** Escreva um programa que leia uma linha de texto (uma frase com no máximo 200 caracteres). O programa deve contar quantas palavras existem na frase. Considere que as palavras são separadas por um ou mais espaços. Palavras podem conter letras, números e outros símbolos, mas espaços definem a separação. A frase pode começar ou terminar com espaços, e pode haver múltiplos espaços entre as palavras.
*   **Entrada:**
    *   Uma linha de texto.
*   **Saída:**
    *   Um inteiro representando o número de palavras.
*   **Exemplo 1:**
    *   Entrada: `  Ola   mundo    cruel   `
    *   Saída: `3`
*   **Exemplo 2:**
    *   Entrada: `Maratona de Programacao em C`
    *   Saída: `5`
*   **Exemplo 3:**
    *   Entrada: `UmaUnicaPalavra`
    *   Saída: `1`
*   **Exemplo 4:**
    *   Entrada: `   ` (Apenas espaços)
    *   Saída: `0`
*   **Dica:** Percorra a string caractere por caractere. Mantenha uma variável de "estado" para saber se você está atualmente *dentro* de uma palavra ou *fora* (em um espaço). Conte uma nova palavra apenas quando você transitar do estado "fora" para o estado "dentro" (ou seja, quando encontrar um caractere que não é espaço logo após ter encontrado um espaço ou no início da string).