/*
  Título: Busca de Palavra em Frase
  Descrição: Programa que verifica se uma palavra está contida em uma frase
  Entrada: 
    - Uma frase (string com espaços)
    - Uma palavra para buscar
  Saída: Mensagem indicando se a palavra foi encontrada ou não na frase
  Exemplo:
    Entrada:
      Digite uma frase: O rato roeu a roupa do rei de Roma
      Digite a palavra a buscar: roupa
    Saída:
      A palavra "roupa" está na frase.
*/

#include <stdio.h>
#include <string.h>

int main()
{
  char frase[200];   // Array para armazenar a frase (até 199 caracteres + \0)
  char palavra[50];  // Array para armazenar a palavra (até 49 caracteres + \0)

  printf("Digite uma frase: ");
  fgets(frase, sizeof(frase), stdin);

  printf("Digite a palavra a buscar: ");
  scanf("%s", palavra);

  // Verifica se a palavra está na frase usando strstr()
  if (strstr(frase, palavra) != NULL)
    printf("A palavra \"%s\" está na frase.\n", palavra);
  else
    printf("A palavra \"%s\" NÃO está na frase.\n", palavra);

  return 0;
}
