# Exercício: Gerenciamento de Estoque

## Enunciado
Crie um programa que implemente um sistema simples de gerenciamento de estoque com as seguintes funcionalidades:

1. Adicionar Produto
2. Listar Produtos
3. Atualizar Estoque
4. Buscar Produto
5. Produtos com Estoque Baixo
0. Sair

### Requisitos
- O programa deve armazenar até 50 produtos
- Cada produto deve ter:
  - Nome (string com até 50 caracteres)
  - Preço (valor positivo)
  - Quantidade (valor não negativo, máximo 999 unidades)
- A tela deve ser limpa a cada interação
- Após cada operação, o programa deve aguardar uma tecla ser pressionada para continuar
- O programa deve continuar executando até que a opção de sair seja escolhida
- Não permitir produtos com nomes duplicados
- Implementar busca parcial case-insensitive
- Alertar produtos com estoque abaixo de 5 unidades

### Exemplo de uso
```
*****Gerenciamento de Estoque*****

1 - Adicionar Produto
2 - Listar Produtos
3 - Atualizar Estoque
4 - Buscar Produto
5 - Produtos com Estoque Baixo
0 - Sair

Escolha uma opção: 1

*****Adicionar Produto*****

Nome do produto: Notebook Dell
Preço: 3500.00
Quantidade: 10

Produto adicionado com sucesso!
Pressione qualquer tecla para voltar ao menu...
```

### Dicas
- Use structs para representar os produtos
- Implemente funções separadas para cada operação
- Use `system("clear")` para limpar a tela (ou `system("cls")` no Windows)
- Use `getchar()` para pausar o programa e aguardar uma tecla
- Lembre-se de limpar o buffer de entrada após usar `scanf`
- Para a busca de produtos, converta as strings para minúsculas para fazer comparação sem distinguir maiúsculas e minúsculas

## Descrição
Este exercício implementa um sistema simples de gerenciamento de estoque em C. O sistema permite realizar operações básicas de CRUD (Create, Read, Update, Delete) em um estoque de produtos, além de funcionalidades específicas para controle de estoque.

## Objetivos
- Praticar o uso de estruturas (structs)
- Implementar operações com arrays
- Desenvolver um sistema de menu interativo
- Trabalhar com manipulação de strings
- Implementar validações de entrada
- Praticar a organização de código em funções

## Estrutura de Dados
```c
struct Produto {
    char nome[50];
    float preco;
    int quantidade;
};
```

## Validações Necessárias
1. Nome do produto:
   - Não pode estar vazio
   - Máximo de 50 caracteres
   - Não pode ser duplicado

2. Preço:
   - Deve ser positivo
   - Máximo de 2 casas decimais

3. Quantidade:
   - Deve ser não negativa
   - Máximo de 999 unidades

## Exemplos de Uso

### Adicionando um Produto
```
=== Gerenciamento de Estoque ===
[1] Adicionar Produto
[2] Listar Produtos
[3] Atualizar Estoque
[4] Buscar Produto
[5] Produtos com Estoque Baixo
[6] Sair
Opção: 1

Nome do produto: Notebook Dell
Preço: 3500.00
Quantidade: 10

Produto adicionado com sucesso!
```

### Listando Produtos
```
=== Gerenciamento de Estoque ===
[1] Adicionar Produto
[2] Listar Produtos
[3] Atualizar Estoque
[4] Buscar Produto
[5] Produtos com Estoque Baixo
[6] Sair
Opção: 2

Produtos Cadastrados:
----------------------------------------
1. Notebook Dell
   Preço: R$ 3500.00
   Quantidade: 10
----------------------------------------
2. Mouse Wireless
   Preço: R$ 89.90
   Quantidade: 15
----------------------------------------
```
