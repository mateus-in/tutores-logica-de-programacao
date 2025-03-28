/*
  Título: Cálculo de Média de Notas
  Descrição: Programa que lê 6 notas de um aluno, armazena-as em um vetor e calcula a média
  Entrada: 6 notas (números reais)
  Saída: A média aritmética das notas
  Exemplo:
    Entrada:
      Digite a nota 1: 7.5
      Digite a nota 2: 8.0
      Digite a nota 3: 6.5
      Digite a nota 4: 9.0
      Digite a nota 5: 7.0
      Digite a nota 6: 8.5
    Saída:
      Média do aluno: 7.75
*/

#include <stdio.h>

int main()
{
  float notas[6], soma = 0, media;

  // Entrada de dados
  for (int i = 0; i < 6; i++)
  {
    printf("Digite a nota %d: ", i + 1);
    scanf("%f", &notas[i]);
  }

  // Processamento: cálculo da média
  for (int i = 0; i < 6; i++)
  {
    soma += notas[i];
  }
  media = soma / 6;

  // Saída
  printf("Média do aluno: %.2f\n", media);

  return 0;
}