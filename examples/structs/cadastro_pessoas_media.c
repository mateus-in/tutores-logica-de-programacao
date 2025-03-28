/*
  Título: Cadastro de Pessoas com Médias
  Descrição: Programa que cadastra 5 pessoas e calcula a média de idade e peso
  Entrada: 
    - Nome (string)
    - Idade (int)
    - Peso (float)
  Saída: Média de idade e peso das pessoas cadastradas
  Exemplo:
    Entrada:
      Nome: João
      Idade: 25
      Peso: 75.5
      Nome: Maria
      Idade: 30
      Peso: 65.0
      Nome: Pedro
      Idade: 28
      Peso: 80.0
      Nome: Ana
      Idade: 22
      Peso: 60.0
      Nome: Carlos
      Idade: 35
      Peso: 85.0
    Saída:
      Média de idade: 28.00
      Média de peso: 73.10 kg
*/

#include <stdio.h>
#include <string.h>

struct Pessoa
{
  char nome[50];    // Nome da pessoa (até 49 caracteres + \0)
  int idade;        // Idade em anos
  float peso;       // Peso em quilogramas
};

int main()
{
  struct Pessoa pessoas[5];  // Vetor de 5 pessoas
  int soma_idade = 0;        // Soma das idades
  float soma_peso = 0.0;     // Soma dos pesos
  int i;

  // Cadastro das pessoas
  for (i = 0; i < 5; i++)
  {
    printf("Nome: ");
    fgets(pessoas[i].nome, sizeof(pessoas[i].nome), stdin);
    pessoas[i].nome[strcspn(pessoas[i].nome, "\n")] = '\0';

    printf("Idade: ");
    scanf("%d", &pessoas[i].idade);
    soma_idade += pessoas[i].idade;

    printf("Peso: ");
    scanf("%f", &pessoas[i].peso);
    soma_peso += pessoas[i].peso;

    getchar();  // Limpa o buffer do teclado
  }

  // Cálculo e exibição das médias
  printf("Média de idade: %.2f\n", soma_idade / 5.0);
  printf("Média de peso: %.2f kg\n", soma_peso / 5.0);

  return 0;
}