/*
  Título: Sequência de Fibonacci
  Descrição: Programa que exibe os N primeiros termos da sequência de Fibonacci
  Entrada: Quantidade de termos a serem exibidos (N)
  Saída: N primeiros termos da sequência de Fibonacci
  Exemplo:
    Entrada:
      Quantos termos da Fibonacci deseja exibir? 8
    Saída:
      0 1 1 2 3 5 8 13
    Entrada:
      Quantos termos da Fibonacci deseja exibir? 1
    Saída:
      0
    Entrada:
      Quantos termos da Fibonacci deseja exibir? 0
    Saída:
      Valor invalido.
*/

#include <stdio.h>

int main()
{
  int n;                          // Quantidade de termos a exibir
  int i;                          // Contador do laço
  long long anterior = 0;         // Termo anterior da sequência
  long long atual = 1;           // Termo atual da sequência
  long long proximo;             // Próximo termo da sequência

  // Leitura da quantidade de termos
  printf("Quantos termos da Fibonacci deseja exibir? ");
  scanf("%d", &n);

  // Validação da entrada
  if (n <= 0)
  {
    printf("Valor invalido.\n");
    return 0;
  }

  // Exibe o primeiro termo
  printf("%lld ", anterior);

  // Se n > 1, exibe o segundo termo
  if (n > 1)
  {
    printf("%lld ", atual);
  }

  // Exibe do terceiro termo em diante
  for (i = 3; i <= n; i++)
  {
    proximo = anterior + atual;    // Calcula o próximo termo
    printf("%lld ", proximo);      // Exibe o termo calculado

    // Atualiza os termos para a próxima iteração
    anterior = atual;
    atual = proximo;
  }
  printf("\n");

  return 0;
}