# Configurando o Visual Studio Code para Programação em C no Windows

## Requisitos

Antes de começar, certifique-se de que sua máquina Windows tem:
- **Visual Studio Code** instalado ([Baixar aqui](https://code.visualstudio.com/))
- **MinGW-w64** instalado corretamente

---

## 1. Instalando o MinGW-w64

### **Baixar a versão correta**
Baixe o MinGW-w64 na versão recomendada:
- **GCC 14.2.0 (with POSIX threads) + LLVM/Clang/LLD/LLDB 19.1.7 + MinGW-w64 12.0.0 UCRT**
- **Plataforma:** Windows **64 bits**
- **Arquivo:** **Win64: Zip archive**
- [Download](https://winlibs.com)

### **Configuração do MinGW**
1. Extraia o arquivo ZIP para `C:\mingw64`
2. Adicione `C:\mingw64\bin` ao **Path do Windows**:
   - Pesquise por "Variáveis de Ambiente"
   - Clique em **Editar as variáveis de ambiente do sistema**
   - Em **Variáveis do sistema**, edite **Path** e adicione `C:\mingw64\bin`
   - Confirme e reinicie o terminal
3. Teste a instalação abrindo o **Prompt de Comando** e digitando:
   ```sh
   gcc --version
   ```
   Se aparecer a versão do GCC, está funcionando!

---

## 2. Instalando e Configurando o VS Code

### 🔹 **Instalar extensões essenciais**
Abra o **VS Code** e instale as seguintes extensões:
1. **C/C++** (Microsoft) → Suporte a C e C++
2. **Code Runner** → Facilita a execução dos programas

---

## 3. Configurando o `tasks.json`
Essa configuração permite compilar e rodar **apenas o arquivo aberto** no momento, sem conflitos com outros arquivos no diretório.

### **Criando a Task para Compilar o Código**
1. Pressione `Ctrl + Shift + P` e pesquise por:
   ```
   Tasks: Configure Task
   ```
2. Escolha **"Create tasks.json file from template"** e selecione **"Others"**
3. Substitua o conteúdo do `tasks.json` por:
   ```json
   {
       "version": "2.0.0",
       "tasks": [
           {
               "label": "Compilar C",
               "type": "shell",
               "command": "gcc",
               "args": [
                   "${file}",
                   "-o",
                   "${fileDirname}/${fileBasenameNoExtension}.exe"
               ],
               "group": {
                   "kind": "build",
                   "isDefault": true
               },
               "problemMatcher": "$gcc"
           }
       ]
   }
   ```
4. **Salve o arquivo (`Ctrl + S`)**

### **Criando a Task para Executar o Código**
Agora, adicione essa nova **task para rodar o executável**:

```json
{
    "label": "Rodar C",
    "type": "shell",
    "command": "${fileDirname}/${fileBasenameNoExtension}.exe",
    "group": {
        "kind": "test",
        "isDefault": true
    },
    "problemMatcher": []
}
```

5. **Salve o arquivo (`Ctrl + S`)**

---

## 4. Como Compilar e Rodar
Agora, para compilar e rodar qualquer arquivo `.c`:
1. **Abra o arquivo** que deseja executar
2. Pressione **`Ctrl + Shift + B`**
3. O programa será compilado e executado automaticamente no terminal do VS Code

🔹 **Cada arquivo `.c` gerará um executável separado**, evitando conflitos entre os programas.
