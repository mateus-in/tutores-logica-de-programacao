/*
  Título: Média de Notas
  Descrição: Programa que calcula a média de notas fornecidas até que seja digitada uma nota negativa
  Entrada: Notas (valores reais não negativos)
  Saída: Quantidade de notas válidas e média, ou mensagem indicando que não houve notas válidas
  Exemplo:
    Entrada:
      Digite notas (valor negativo para encerrar):
      7.5
      8.0
      6.5
      9.0
      -1
    Saída:
      Foram lidas 4 notas validas.
      Media das notas: 7.75
    Entrada:
      Digite notas (valor negativo para encerrar):
      -1
    Saída:
      Nenhuma nota valida foi digitada.
*/

#include <stdio.h>

int main()
{
  float nota;         // Nota digitada pelo usuário
  float soma = 0.0f;  // Soma das notas válidas
  int contador = 0;   // Contador de notas válidas

  // Inicia a leitura das notas
  printf("Digite notas (valor negativo para encerrar):\n");
  scanf("%f", &nota);

  // Continua lendo enquanto a nota não for negativa
  while (nota >= 0.0f)
  {
    soma += nota;       // Adiciona a nota à soma
    contador++;         // Incrementa o contador de notas
    scanf("%f", &nota); // Lê a próxima nota
  }

  // Verifica se houve notas válidas e exibe o resultado
  if (contador > 0)
  {
    printf("Foram lidas %d notas validas.\n", contador);
    printf("Media das notas: %.2f\n", soma / contador);
  }
  else
  {
    printf("Nenhuma nota valida foi digitada.\n");
  }

  return 0;
}