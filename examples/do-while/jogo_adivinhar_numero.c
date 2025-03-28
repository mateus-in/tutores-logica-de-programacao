/*
  Título: Jogo de Adivinhação
  Descrição: Programa que implementa um jogo simples de adivinhação,
             onde o usuário deve descobrir um número secreto
  Entrada: Números inteiros representando palpites
  Saída: Mensagens indicando se o palpite está correto ou incorreto
  Exemplo:
    Entrada:
      Adivinhe o numero secreto: 10
      Tente novamente...
      Adivinhe o numero secreto: 20
      Tente novamente...
      Adivinhe o numero secreto: 15
    Saída:
      Voce acertou!
*/

#include <stdio.h>

int main()
{
  const int NUMERO_SECRETO = 15;  // Número que o usuário deve adivinhar
  int palpite;                    // Palpite do usuário

  // Jogo de adivinhação que continua até que o usuário acerte
  do
  {
    printf("Adivinhe o numero secreto: ");
    scanf("%d", &palpite);

    if (palpite != NUMERO_SECRETO)
    {
      printf("Tente novamente...\n");
    }
  } while (palpite != NUMERO_SECRETO);

  // Mensagem de sucesso quando o usuário acerta
  printf("Voce acertou!\n");

  return 0;
}