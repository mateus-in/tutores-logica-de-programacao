# 📘 Projeto de Lógica de Programação  
**Cadastro de Tutores e Pets**

**Professor:** Mateus Lopes Castro  
**Entrega:** até **24/04** no e-mail **mateuslopescastro@outlook.com**  
**Formato do arquivo:** `.c`
**Nome do arquivo:** `NomeDoAluno.c`

---

## 🎯 Objetivo

Implementar um sistema em linguagem C para cadastrar, editar, listar e excluir **tutores** e seus respectivos **pets**. Este projeto reforça os conceitos de **structs**, **funções**, **vetores**, **controle de fluxo** e **organização modular** do código.

---

## 📋 Requisitos do Sistema

### Entidades

- **Tutor**
  - CPF (string)
  - Nome (string)
  - Lista de pets (máx. definido no código base)

- **Pet**
  - Nome (string)
  - Associado a um tutor

---

## 📑 Funcionalidades obrigatórias

Cada funcionalidade deverá ser acessada por meio de um **menu principal**. As opções são:

### 🧍 Tutores

1. **Cadastrar tutor**  
   - Inserir CPF e nome do tutor.

2. **Editar tutor**  
   - Localizar por CPF e permitir editar o nome.

3. **Listar tutores cadastrados**  
   - Exibir CPF e nome de todos os tutores.

4. **Excluir tutor**  
   - Localizar por CPF e remover o tutor e seus pets.

### 🐶 Pets

5. **Cadastrar pet**  
   - Inserir nome do pet e CPF do tutor ao qual ele pertence.

6. **Editar pet**  
   - Localizar pet e tutor por CPF e nome, e editar o nome do pet.

7. **Listar pets (mostrar dados do tutor)**  
   - Exibir nome do pet + nome e CPF do tutor.

8. **Excluir pet**  
   - Localizar pet por nome e CPF do tutor e removê-lo.

---

## 💡 Orientações

- A estrutura base do código será fornecida pelo professor.  
- O projeto deve ser entregue apenas em **formato `.c`**.  
- Comentários no código são bem-vindos e valorizados.  
- Organize o código em funções separadas por funcionalidade.  
- O sistema **não precisa salvar os dados em arquivos**, apenas em memória (usando vetores).

---

## 📬 Entrega

- Enviar o arquivo `.c` com a resolução até **24/04** para o e-mail:  
  **mateuslopescastro@outlook.com**

---

## 🛠️ Dicas Técnicas

- Utilize o arquivo `code.c` para iniciar o desenvolvimento.
