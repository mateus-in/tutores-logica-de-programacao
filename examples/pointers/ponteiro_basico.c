/*
  Título: Ponteiro Básico
  Descrição: Programa que demonstra o uso básico de ponteiros para acessar o endereço e valor de uma variável
  Entrada: Um número inteiro
  Saída: Endereço de memória e valor do número
  Exemplo:
    Entrada:
      Digite um número inteiro: 42
    Saída:
      Endereço: 0x7fff5fbff8ac
      Valor: 42
*/

#include <stdio.h>

int main()
{
  int num;  // Variável para armazenar o número

  printf("Digite um número inteiro: ");
  scanf("%d", &num);

  int *p = &num;  // Ponteiro que aponta para o endereço de num

  // Exibe o endereço de memória e o valor apontado
  printf("Endereço: %p\n", p);
  printf("Valor: %d\n", *p);

  return 0;
}