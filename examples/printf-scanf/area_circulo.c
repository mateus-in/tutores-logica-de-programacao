/*
  Título: Cálculo de Área e Circunferência do Círculo
  Descrição: Programa que calcula a área e circunferência de um círculo a partir do raio
  Entrada: Um número real (float) representando o raio do círculo
  Saída: 
    - A área do círculo (π * raio²)
    - A circunferência do círculo (2 * π * raio)
  Exemplo:
    Entrada:
      Digite o valor do raio: 5.0
    Saída:
      Area do circulo: 78.54
      Circunferencia do circulo: 31.42
*/

#include <stdio.h>

int main()
{
  float raio, area, circunferencia;
  const float PI = 3.14159f; // ou use #include <math.h> e M_PI

  printf("Digite o valor do raio: ");
  scanf("%f", &raio);

  area = PI * (raio * raio);
  circunferencia = 2 * PI * raio;

  printf("Area do circulo: %.2f\n", area);
  printf("Circunferencia do circulo: %.2f\n", circunferencia);

  return 0;
}