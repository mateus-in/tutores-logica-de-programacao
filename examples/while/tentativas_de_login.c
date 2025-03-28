/*
  Título: Simulador de Login
  Descrição: Programa que simula um sistema de login com senha numérica
  Entrada: Tentativas de senha (números inteiros)
  Saída: Mensagens de erro ou acesso concedido
  Exemplo:
    Entrada:
      Digite a senha numerica: 1234
      Senha incorreta. Tente novamente: 5678
      Senha incorreta. Tente novamente: 2025
    Saída:
      Acesso concedido.
    Entrada:
      Digite a senha numerica: 2025
    Saída:
      Acesso concedido.
*/

#include <stdio.h>

int main()
{
  int senha;                      // Senha digitada pelo usuário
  const int SENHA_CORRETA = 2025; // Senha válida para acesso

  // Primeira tentativa de login
  printf("Digite a senha numerica: ");
  scanf("%d", &senha);

  // Continua pedindo a senha enquanto estiver incorreta
  while (senha != SENHA_CORRETA)
  {
    printf("Senha incorreta. Tente novamente: ");
    scanf("%d", &senha);
  }

  // Senha correta, concede acesso
  printf("Acesso concedido.\n");

  return 0;
}