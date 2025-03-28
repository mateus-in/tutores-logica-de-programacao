/*
  Título: Cadastro de Funcionário com Endereço
  Descrição: Programa que demonstra o uso de estruturas aninhadas para cadastrar um funcionário e seu endereço
  Entrada: 
    - Nome do funcionário (string)
    - Rua (string)
    - Número (int)
    - Cidade (string)
  Saída: Dados completos do funcionário e seu endereço
  Exemplo:
    Entrada:
      Nome do funcionário: João Silva
      Rua: Rua das Flores
      Número: 123
      Cidade: São Paulo
    Saída:
      Funcionário: João Silva
      Endereço: Rua das Flores, nº 123, São Paulo
*/

#include <stdio.h>
#include <string.h>

struct Endereco
{
  char rua[50];     // Nome da rua (até 49 caracteres + \0)
  int numero;       // Número do endereço
  char cidade[50];  // Nome da cidade (até 49 caracteres + \0)
};

struct Funcionario
{
  char nome[50];           // Nome do funcionário (até 49 caracteres + \0)
  struct Endereco endereco; // Endereço do funcionário (estrutura aninhada)
};

int main()
{
  struct Funcionario func;

  // Cadastro dos dados do funcionário
  printf("Nome do funcionário: ");
  fgets(func.nome, sizeof(func.nome), stdin);
  func.nome[strcspn(func.nome, "\n")] = '\0';

  printf("Rua: ");
  fgets(func.endereco.rua, sizeof(func.endereco.rua), stdin);
  func.endereco.rua[strcspn(func.endereco.rua, "\n")] = '\0';

  printf("Número: ");
  scanf("%d", &func.endereco.numero);
  getchar();  // Limpa o buffer do teclado

  printf("Cidade: ");
  fgets(func.endereco.cidade, sizeof(func.endereco.cidade), stdin);
  func.endereco.cidade[strcspn(func.endereco.cidade, "\n")] = '\0';

  // Exibição dos dados cadastrados
  printf("\nFuncionário: %s\n", func.nome);
  printf("Endereço: %s, nº %d, %s\n",
         func.endereco.rua, func.endereco.numero, func.endereco.cidade);

  return 0;
}
