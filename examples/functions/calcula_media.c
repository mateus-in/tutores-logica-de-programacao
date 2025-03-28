/*
  Título: Cálculo de Média
  Descrição: Programa que demonstra o uso de uma função para calcular a média de três notas
  Entrada: Nenhuma (valores definidos no código)
  Saída: Média aritmética das três notas
  Exemplo:
    Entrada:
      n1 = 8.0
      n2 = 7.5
      n3 = 9.5
    Saída:
      Média do aluno: 8.33
*/

#include <stdio.h>

/**
 * Calcula a média aritmética de três notas
 * @param n1 Primeira nota
 * @param n2 Segunda nota
 * @param n3 Terceira nota
 * @return Média aritmética das três notas
 */
float calcularMedia(float n1, float n2, float n3)
{
  return (n1 + n2 + n3) / 3;
}

int main()
{
  float media = calcularMedia(8.0, 7.5, 9.5);
  printf("Média do aluno: %.2f\n", media);

  return 0;
}