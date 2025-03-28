/*
  Título: Contagem de Vogais
  Descrição: Programa que lê uma frase e conta quantas vogais (a, e, i, o, u) ela possui
  Entrada: Uma frase (string com espaços)
  Saída: O número total de vogais na frase
  Exemplo:
    Entrada:
      Digite uma frase: Logica de Programacao
    Saída:
      Número de vogais: 8
*/

#include <stdio.h>
#include <string.h>
#include <ctype.h>

int main()
{
  char frase[200];
  int contador = 0;

  printf("Digite uma frase: ");
  fgets(frase, sizeof(frase), stdin); // Permite ler frases com espaços

  for (int i = 0; frase[i] != '\0'; i++)
  {
    char c = tolower(frase[i]); // Converte para minúsculo
    if (c == 'a' || c == 'e' || c == 'i' || c == 'o' || c == 'u')
    {
      contador++;
    }
  }

  printf("Número de vogais: %d\n", contador);

  return 0;
}
