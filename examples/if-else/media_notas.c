/*
  Título: Média e Situação do Aluno
  Descrição: Programa que calcula a média de duas notas e determina a situação do aluno
  Entrada: Duas notas (valores reais)
  Saída: Média e situação do aluno (Aprovado, Recuperação ou Reprovado)
  Exemplo:
    Entrada:
      Digite a primeira nota: 8.5
      Digite a segunda nota: 7.5
    Saída:
      Média: 8.00
      Aprovado
    Entrada:
      Digite a primeira nota: 6.0
      Digite a segunda nota: 5.0
    Saída:
      Média: 5.50
      Recuperacao
    Entrada:
      Digite a primeira nota: 4.0
      Digite a segunda nota: 3.0
    Saída:
      Média: 3.50
      Reprovado
*/

#include <stdio.h>

int main()
{
  float nota1, nota2;  // Variáveis para as notas
  float media;         // Variável para a média

  // Leitura das notas
  printf("Digite a primeira nota: ");
  scanf("%f", &nota1);
  printf("Digite a segunda nota: ");
  scanf("%f", &nota2);

  // Cálculo da média
  media = (nota1 + nota2) / 2;
  printf("Média: %.2f\n", media);

  // Verificação da situação do aluno
  if (media >= 7.0)
  {
    printf("Aprovado\n");
  }
  else if (media >= 5.0)
  {
    printf("Recuperacao\n");
  }
  else
  {
    printf("Reprovado\n");
  }

  return 0;
}