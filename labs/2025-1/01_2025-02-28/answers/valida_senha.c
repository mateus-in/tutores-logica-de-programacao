/*
  Título: Validação de Senha Numérica
  Descrição: Programa que implementa um sistema simples de validação de senha,
             permitindo múltiplas tentativas até que a senha correta seja digitada
  Entrada: Números inteiros representando tentativas de senha
  Saída: Mensagens indicando se a senha está correta ou incorreta
  Exemplo:
    Entrada:
      Digite a senha: 1111
      Senha incorreta. Tente novamente.
      Digite a senha: 1234
    Saída:
      Acesso liberado.
*/

#include <stdio.h>

int main()
{
  int senha;                    // Senha digitada pelo usuário
  const int SENHA_CORRETA = 1234;  // Senha correta do sistema

  // Solicita a senha até que seja correta
  do
  {
    printf("Digite a senha: ");
    scanf("%d", &senha);

    if (senha != SENHA_CORRETA)
    {
      printf("Senha incorreta. Tente novamente.\n");
    }
  } while (senha != SENHA_CORRETA);

  // Mensagem de acesso liberado
  printf("Acesso liberado.\n");

  return 0;
}