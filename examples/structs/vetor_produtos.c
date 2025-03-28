/*
  Título: Vetor de Produtos
  Descrição: Programa que demonstra o uso de um vetor de estruturas para cadastrar e exibir produtos
  Entrada: 
    - Nome do produto (string)
    - Preço (float)
    - Quantidade em estoque (int)
  Saída: Lista de produtos cadastrados com seus respectivos dados
  Exemplo:
    Entrada:
      Nome do produto: Notebook
      Preço: 3500.00
      Quantidade em estoque: 10
      Nome do produto: Mouse
      Preço: 50.00
      Quantidade em estoque: 20
      Nome do produto: Teclado
      Preço: 100.00
      Quantidade em estoque: 15
    Saída:
      Produtos cadastrados:
      Produto: Notebook | Preço: R$ 3500.00 | Estoque: 10
      Produto: Mouse | Preço: R$ 50.00 | Estoque: 20
      Produto: Teclado | Preço: R$ 100.00 | Estoque: 15
*/

#include <stdio.h>
#include <string.h>

struct Produto
{
  char nome[50];    // Nome do produto (até 49 caracteres + \0)
  float preco;      // Preço do produto
  int quantidade;   // Quantidade em estoque
};

int main()
{
  struct Produto produtos[3];  // Vetor de 3 produtos
  int i;

  // Cadastro dos produtos
  for (i = 0; i < 3; i++)
  {
    printf("Nome do produto: ");
    fgets(produtos[i].nome, sizeof(produtos[i].nome), stdin);
    produtos[i].nome[strcspn(produtos[i].nome, "\n")] = '\0';

    printf("Preço: ");
    scanf("%f", &produtos[i].preco);

    printf("Quantidade em estoque: ");
    scanf("%d", &produtos[i].quantidade);

    getchar();  // Limpa o buffer do teclado
  }

  // Exibição dos produtos cadastrados
  printf("\nProdutos cadastrados:\n");
  for (i = 0; i < 3; i++)
  {
    printf("Produto: %s | Preço: R$ %.2f | Estoque: %d\n", 
           produtos[i].nome, produtos[i].preco, produtos[i].quantidade);
  }

  return 0;
}