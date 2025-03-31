# Tutores Lógica de Programação

Repositório para os materiais do curso de tutoria em lógica de programação.

## Configurando Depuração de Programas C no VS Code

Para depurar programas C no VS Code, siga estas etapas:

### 1. Instalar Extensões Necessárias

- Instale a extensão **C/C++** da Microsoft

### 2. Configurar Arquivos de Depuração

Dois arquivos são necessários para a depuração:

1. **launch.json** - Define como o depurador é inicializado
2. **tasks.json** - Define como o programa é compilado

#### launch.json
```json
{
  "version": "0.2.0",
  "configurations": [
    {
      "name": "Debug C Program",
      "type": "cppdbg",
      "request": "launch",
      "program": "${fileDirname}/${fileBasenameNoExtension}",
      "args": [],
      "stopAtEntry": false,
      "cwd": "${fileDirname}",
      "environment": [],
      "externalConsole": true,
      "MIMode": "lldb",
      "preLaunchTask": "C/C++: gcc build active file"
    }
  ]
}
```

#### tasks.json
```json
{
  "version": "2.0.0",
  "tasks": [
    {
      "label": "C/C++: gcc build active file",
      "type": "shell",
      "command": "/usr/bin/gcc",
      "args": [
        "-g",
        "${file}",
        "-o",
        "${fileDirname}/${fileBasenameNoExtension}"
      ],
      "options": {
        "cwd": "${fileDirname}"
      },
      "problemMatcher": [
        "$gcc"
      ],
      "group": {
        "kind": "build",
        "isDefault": true
      },
      "detail": "Task generated for debugging."
    }
  ]
}
```

### 3. Como Usar o Depurador

1. Abra seu arquivo C no VS Code
2. Defina pontos de interrupção clicando na margem esquerda ao lado dos números de linha
3. Pressione F5 ou selecione "Run > Start Debugging" no menu
4. Um terminal externo será aberto para entrada interativa (importante para programas que usam scanf)

### 4. Recursos de Depuração Disponíveis

- Inspeção de variáveis
- Execução passo a passo (F10 para próxima linha, F11 para entrar em funções)
- Visualização de expressões
- Navegação na pilha de chamadas

### 5. Resolução de Problemas Comuns

- **Erro "Unable to perform this action because the process is running"**: Este erro ocorre quando o programa espera entrada interativa no console integrado do VS Code. Para resolver, certifique-se de que `"externalConsole": true` está definido no launch.json.

- **Programa não pausa nos pontos de interrupção**: Verifique se está compilando com a flag `-g` (incluída na configuração do tasks.json). 