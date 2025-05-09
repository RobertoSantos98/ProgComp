
# ProgComp

## Descrição

Este repositório contém o código-fonte para um sistema de gerenciamento de alunos e autenticação de usuário. Ele permite que um administrador se autentique no sistema, adicione, remova e liste alunos.

## Funcionalidades

- **Autenticação de usuário:** O administrador faz login com um nome de usuário e senha.
- **Gerenciamento de alunos:** O administrador pode adicionar, remover, listar e procurar alunos.
- **Interface de comando:** O sistema é interativo e baseado em linha de comando.

## Estrutura do Projeto

- `admin`: Contém as credenciais de login.
- `alunos`: Armazena dados dos alunos, como nome e notas.
- Funções para realizar operações de gerenciamento de alunos (adicionar, remover, listar, etc.).

## Como Usar

1. Clone o repositório:
   ```bash
   git clone https://github.com/RobertoSantos98/ProgComp.git
   ```
2. Compile o código:
   ```bash
   gcc main.c -o sistema
   ```
3. Execute o sistema:
   ```bash
   ./sistema
   ```

## Contribuindo

Se você deseja contribuir para este projeto, sinta-se à vontade para abrir um pull request. Qualquer contribuição é bem-vinda!

## Licença

Este projeto é de código aberto e distribuído sob a licença MIT.
