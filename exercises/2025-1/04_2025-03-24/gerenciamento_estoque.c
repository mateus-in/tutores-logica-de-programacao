#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

#define MAX_PRODUTOS 50
#define MAX_NOME 50
#define ESTOQUE_BAIXO 5

// Definição da struct Produto
typedef struct
{
  char nome[MAX_NOME + 1];
  float preco;
  int quantidade;
  int ativo; // 0 = inativo, 1 = ativo
} Produto;

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
  printf("*****Gerenciamento de Estoque*****\n\n");
  printf("1 - Adicionar Produto\n");
  printf("2 - Listar Produtos\n");
  printf("3 - Atualizar Estoque\n");
  printf("4 - Buscar Produto\n");
  printf("5 - Produtos com Estoque Baixo\n");
  printf("0 - Sair\n\n");
  printf("Escolha uma opção: ");
}

void strToLower(char *str)
{
  for (int i = 0; str[i]; i++)
  {
    str[i] = tolower(str[i]);
  }
}

int produtoExiste(Produto *produtos, const char *nome)
{
  for (int i = 0; i < MAX_PRODUTOS; i++)
  {
    if (produtos[i].ativo && strcmp(produtos[i].nome, nome) == 0)
    {
      return 1;
    }
  }
  return 0;
}

void adicionarProduto(Produto *produtos, int *totalProdutos)
{
  printf("*****Adicionar Produto*****\n\n");

  if (*totalProdutos >= MAX_PRODUTOS)
  {
    printf("Erro: Número máximo de produtos atingido!\n");
    aguardarTecla();
    return;
  }

  Produto novoProduto;

  printf("Nome do produto: ");
  fgets(novoProduto.nome, MAX_NOME, stdin);

  // Remover o \n do final da string
  size_t len = strlen(novoProduto.nome);
  if (len > 0 && novoProduto.nome[len - 1] == '\n')
  {
    novoProduto.nome[len - 1] = '\0';
  }

  // Validar se o nome não está vazio
  if (strlen(novoProduto.nome) == 0)
  {
    printf("Erro: O nome do produto não pode estar vazio!\n");
    aguardarTecla();
    return;
  }

  // Verificar se o produto já existe
  if (produtoExiste(produtos, novoProduto.nome))
  {
    printf("Erro: Já existe um produto com este nome!\n");
    aguardarTecla();
    return;
  }

  printf("Preço: ");
  scanf("%f", &novoProduto.preco);
  limparBuffer();

  // Validar preço
  if (novoProduto.preco <= 0)
  {
    printf("Erro: O preço deve ser positivo!\n");
    aguardarTecla();
    return;
  }

  printf("Quantidade: ");
  scanf("%d", &novoProduto.quantidade);
  limparBuffer();

  // Validar quantidade
  if (novoProduto.quantidade < 0)
  {
    printf("Erro: A quantidade não pode ser negativa!\n");
    aguardarTecla();
    return;
  }

  if (novoProduto.quantidade > 999)
  {
    printf("Erro: A quantidade máxima é 999 unidades!\n");
    aguardarTecla();
    return;
  }

  novoProduto.ativo = 1;

  // Encontrar posição disponível
  for (int i = 0; i < MAX_PRODUTOS; i++)
  {
    if (!produtos[i].ativo)
    {
      produtos[i] = novoProduto;
      (*totalProdutos)++;
      break;
    }
  }

  printf("\nProduto adicionado com sucesso!\n");
  aguardarTecla();
}

void listarProdutos(Produto *produtos)
{
  printf("*****Lista de Produtos*****\n\n");

  int encontrados = 0;

  for (int i = 0, count = 1; i < MAX_PRODUTOS; i++)
  {
    if (produtos[i].ativo)
    {
      printf("----------------------------------------\n");
      printf("%d. %s\n", count++, produtos[i].nome);
      printf("   Preço: R$ %.2f\n", produtos[i].preco);
      printf("   Quantidade: %d\n", produtos[i].quantidade);
      printf("----------------------------------------\n");
      encontrados++;
    }
  }

  if (encontrados == 0)
  {
    printf("Nenhum produto cadastrado.\n");
  }

  aguardarTecla();
}

void atualizarEstoque(Produto *produtos)
{
  printf("*****Atualizar Estoque*****\n\n");

  int encontrados = 0;
  for (int i = 0; i < MAX_PRODUTOS; i++)
  {
    if (produtos[i].ativo)
    {
      encontrados++;
      break;
    }
  }

  if (encontrados == 0)
  {
    printf("Nenhum produto cadastrado.\n");
    aguardarTecla();
    return;
  }

  char nomeProduto[MAX_NOME + 1];
  printf("Nome do produto: ");
  fgets(nomeProduto, MAX_NOME, stdin);

  // Remover o \n do final da string
  size_t len = strlen(nomeProduto);
  if (len > 0 && nomeProduto[len - 1] == '\n')
  {
    nomeProduto[len - 1] = '\0';
  }

  int encontrado = 0;
  int posicao = -1;

  for (int i = 0; i < MAX_PRODUTOS; i++)
  {
    if (produtos[i].ativo && strcmp(produtos[i].nome, nomeProduto) == 0)
    {
      posicao = i;
      encontrado = 1;
      break;
    }
  }

  if (encontrado)
  {
    printf("\nProduto encontrado:\n");
    printf("Nome: %s\n", produtos[posicao].nome);
    printf("Quantidade atual: %d\n\n", produtos[posicao].quantidade);

    int novaQuantidade;
    printf("Nova quantidade: ");
    scanf("%d", &novaQuantidade);
    limparBuffer();

    // Validar nova quantidade
    if (novaQuantidade < 0)
    {
      printf("Erro: A quantidade não pode ser negativa!\n");
      aguardarTecla();
      return;
    }

    if (novaQuantidade > 999)
    {
      printf("Erro: A quantidade máxima é 999 unidades!\n");
      aguardarTecla();
      return;
    }

    char confirmacao;
    printf("\nConfirmar atualização (S/N)? ");
    scanf("%c", &confirmacao);
    limparBuffer();

    if (confirmacao == 'S' || confirmacao == 's')
    {
      produtos[posicao].quantidade = novaQuantidade;
      printf("\nEstoque atualizado com sucesso!\n");
    }
    else
    {
      printf("\nOperação cancelada!\n");
    }
  }
  else
  {
    printf("Erro: Produto não encontrado!\n");
  }

  aguardarTecla();
}

void buscarProduto(Produto *produtos)
{
  printf("*****Buscar Produto*****\n\n");

  int encontrados = 0;
  for (int i = 0; i < MAX_PRODUTOS; i++)
  {
    if (produtos[i].ativo)
    {
      encontrados++;
      break;
    }
  }

  if (encontrados == 0)
  {
    printf("Nenhum produto cadastrado.\n");
    aguardarTecla();
    return;
  }

  char termoBusca[MAX_NOME + 1];
  printf("Digite o termo de busca: ");
  fgets(termoBusca, MAX_NOME, stdin);

  // Remover o \n do final da string
  size_t len = strlen(termoBusca);
  if (len > 0 && termoBusca[len - 1] == '\n')
  {
    termoBusca[len - 1] = '\0';
  }

  // Converter para minúsculas para comparação case-insensitive
  char termoBuscaLower[MAX_NOME + 1];
  strcpy(termoBuscaLower, termoBusca);
  strToLower(termoBuscaLower);

  encontrados = 0;

  printf("\nResultados da busca:\n");

  for (int i = 0; i < MAX_PRODUTOS; i++)
  {
    if (produtos[i].ativo)
    {
      // Criar cópia do nome do produto em minúsculas
      char nomeProdutoLower[MAX_NOME + 1];
      strcpy(nomeProdutoLower, produtos[i].nome);
      strToLower(nomeProdutoLower);

      // Verificar se o termo de busca está contido no nome do produto
      if (strstr(nomeProdutoLower, termoBuscaLower) != NULL)
      {
        printf("----------------------------------------\n");
        printf("Nome: %s\n", produtos[i].nome);
        printf("Preço: R$ %.2f\n", produtos[i].preco);
        printf("Quantidade: %d\n", produtos[i].quantidade);
        printf("----------------------------------------\n");
        encontrados++;
      }
    }
  }

  if (encontrados == 0)
  {
    printf("Nenhum produto encontrado com o termo '%s'.\n", termoBusca);
  }
  else
  {
    printf("\nTotal de produtos encontrados: %d\n", encontrados);
  }

  aguardarTecla();
}

void produtosEstoqueBaixo(Produto *produtos)
{
  printf("*****Produtos com Estoque Baixo*****\n\n");

  int encontrados = 0;

  for (int i = 0; i < MAX_PRODUTOS; i++)
  {
    if (produtos[i].ativo && produtos[i].quantidade < ESTOQUE_BAIXO)
    {
      printf("----------------------------------------\n");
      printf("ALERTA: Estoque Baixo!\n");
      printf("Produto: %s\n", produtos[i].nome);
      printf("Quantidade atual: %d\n", produtos[i].quantidade);
      printf("Recomendação: Repor estoque!\n");
      printf("----------------------------------------\n");
      encontrados++;
    }
  }

  if (encontrados == 0)
  {
    printf("Não há produtos com estoque baixo.\n");
  }
  else
  {
    printf("\nTotal de produtos com estoque baixo: %d\n", encontrados);
  }

  aguardarTecla();
}

int main()
{
  // Variáveis locais
  Produto produtos[MAX_PRODUTOS];
  int totalProdutos = 0;
  int opcao;

  // Inicializar todos os produtos como inativos
  for (int i = 0; i < MAX_PRODUTOS; i++)
  {
    produtos[i].ativo = 0;
  }

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
      adicionarProduto(produtos, &totalProdutos);
      break;
    case 2:
      listarProdutos(produtos);
      break;
    case 3:
      atualizarEstoque(produtos);
      break;
    case 4:
      buscarProduto(produtos);
      break;
    case 5:
      produtosEstoqueBaixo(produtos);
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