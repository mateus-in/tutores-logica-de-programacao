/*
  Título: Troca de Valores com Ponteiros
  Descrição: Programa que demonstra o uso de ponteiros para trocar os valores de duas variáveis
  Entrada: Nenhuma (valores definidos no código)
  Saída: Valores das variáveis antes e depois da troca
  Exemplo:
    Entrada:
      x = 5
      y = 10
    Saída:
      Antes: x = 5, y = 10
      Depois: x = 10, y = 5
*/

#include <stdio.h>

/**
 * Troca os valores de duas variáveis usando ponteiros
 * @param a Ponteiro para a primeira variável
 * @param b Ponteiro para a segunda variável
 */
void trocar(int *a, int *b)
{
  int temp = *a;  // Armazena o valor apontado por a
  *a = *b;        // Atribui o valor apontado por b ao endereço de a
  *b = temp;      // Atribui o valor temporário ao endereço de b
}

int main()
{
  int x = 5, y = 10;  // Variáveis iniciais

  printf("Antes: x = %d, y = %d\n", x, y);
  trocar(&x, &y);     // Chama a função passando os endereços
  printf("Depois: x = %d, y = %d\n", x, y);

  return 0;
}
