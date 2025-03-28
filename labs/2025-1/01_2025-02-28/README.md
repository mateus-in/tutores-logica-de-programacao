# Laboratório 01 - 28/02/2025

Este laboratório contém exercícios básicos de programação em C, focando em estruturas de controle e entrada/saída.

## Exercícios

### 1. Verificação de Número Par ou Ímpar
Peça ao usuário um número inteiro e use if-else para verificar se ele é par ou ímpar, exibindo a mensagem correspondente.

### 2. Soma de Números até Limite
Peça ao usuário que digite vários números inteiros (um por vez), e some-os enquanto o total acumulado for menor que 100. Use a estrutura while para controlar o loop. Quando a soma ultrapassar ou atingir 100, encerre e exiba o valor total acumulado.

### 3. Validação de Senha
Implemente um sistema que peça ao usuário uma senha numérica (inteira). Enquanto a senha estiver incorreta, o programa deve pedir novamente. Use do-while para garantir que ao menos uma leitura será feita. Quando a senha estiver correta (ex: 1234), exiba "Acesso liberado".

### 4. Classificação Indicativa de Filmes
Crie um pequeno menu com classificações indicativas de um filme:
- 1 - Livre
- 2 - 10 anos
- 3 - 12 anos
- 4 - 14 anos
- 5 - 16 anos
- 6 - 18 anos
Use switch para exibir uma mensagem com a classificação selecionada. Se a opção não for nenhuma dessas, exibir "Opção invalida".

### 5. Números Ímpares
Use a estrutura for para exibir todos os números ímpares de 1 até 99 na tela, cada um em uma linha.

### 6. Saudação com Nome e Idade
Use scanf para ler um nome (sem espaço) e uma idade, depois exiba na tela a mensagem:
"Olá, <nome>! Você tem <idade> anos."

## Como Usar

1. Compile cada arquivo .c usando o GCC:
   ```bash
   gcc nome_do_arquivo.c -o nome_do_executavel
   ```

2. Execute o programa gerado:
   ```bash
   ./nome_do_executavel
   ```

## Soluções

As soluções dos exercícios estão disponíveis no diretório `answers/`. 