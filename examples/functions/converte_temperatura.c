/*
  Título: Conversão de Temperatura
  Descrição: Programa que demonstra o uso de funções para converter temperaturas entre Celsius e Fahrenheit
  Entrada: Nenhuma (valores definidos no código)
  Saída: Temperaturas convertidas em ambas as escalas
  Exemplo:
    Entrada:
      celsius = 25°C
      fahrenheit = 77°F
    Saída:
      25.00°C = 77.00°F
      77.00°F em Celsius é: 25.00°C
*/

#include <stdio.h>

/**
 * Converte temperatura de Celsius para Fahrenheit
 * @param c Temperatura em Celsius
 * @return Temperatura convertida para Fahrenheit
 */
float celsiusParaFahrenheit(float c)
{
  return (c * 9 / 5) + 32;
}

/**
 * Converte temperatura de Fahrenheit para Celsius
 * @param f Temperatura em Fahrenheit
 * @return Temperatura convertida para Celsius
 */
float fahrenheitParaCelsius(float f)
{
  return (f - 32) * 5 / 9;
}

int main()
{
  float celsius = 25;     // Temperatura em Celsius
  float fahrenheit = 77;  // Temperatura em Fahrenheit

  // Exibe as conversões
  printf("%.2f°C = %.2f°F\n", celsius, celsiusParaFahrenheit(celsius));
  printf("%.2f°F em Celsius é: %.2f°C\n", fahrenheit, fahrenheitParaCelsius(fahrenheit));

  return 0;
}