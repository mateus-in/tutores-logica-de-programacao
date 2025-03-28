# Exercício: Gerenciamento de Alunos

## Enunciado
Crie um programa que implemente um sistema simples de gerenciamento de alunos com as seguintes funcionalidades:

1. Listar os alunos cadastrados
2. Cadastrar um novo aluno
3. Atualizar um aluno cadastrado
4. Excluir um aluno cadastrado
5. Sair

### Requisitos
- O programa deve armazenar até 10 alunos
- Cada aluno deve ter:
  - Matrícula (número inteiro)
  - Nome (string com até 50 caracteres)
- A tela deve ser limpa a cada interação
- Após cada operação, o programa deve aguardar uma tecla ser pressionada para continuar
- O programa deve continuar executando até que a opção de sair seja escolhida

### Exemplo de uso
```
*****CRUD Alunos*****

1 - Listar os alunos cadastrados
2 - Cadastrar um novo aluno
3 - Atualizar um aluno cadastrado
4 - Excluir um aluno cadastrado
0 - Sair

Escolha uma opção: 2

*****Cadastrar aluno*****

Matrícula: 12345
Nome: João Silva

Aluno cadastrado com sucesso!
Pressione qualquer tecla para voltar ao menu...
```

### Dicas
- Use structs para representar os alunos
- Implemente funções separadas para cada operação
- Use `system("clear")` para limpar a tela (ou `system("cls")` no Windows)
- Use `getchar()` para pausar o programa e aguardar uma tecla
- Lembre-se de limpar o buffer de entrada após usar `scanf`
- Para excluir um aluno, você pode mover todos os alunos subsequentes uma posição para trás no array 