# Caixa Eletrônico em C

Sistema de caixa eletrônico de terminal, feito em C puro, com persistência do saldo em disco. Projeto pessoal para consolidar os estudos da linguagem.

## O que o sistema faz

- Ver saldo
- Realizar depósito
- Realizar saque
- Sair (salvando o saldo em `saldo.txt`)

Ao iniciar, o programa carrega o último saldo salvo. Se o arquivo não existir, começa com saldo zerado.

## Conceitos de C aplicados

- **Structs**: a conta é modelada com `Contabancaria` (titular e saldo)
- **Ponteiros e passagem por referência**: as funções recebem `Contabancaria *conta` e alteram o saldo direto na memória, usando `->`
- **Manipulação de arquivos**: `fopen`, `fprintf`, `fscanf` e `fclose` com `FILE *` para salvar e carregar o saldo
- **Validações**: valor de depósito ou saque inválido (zero ou negativo), saldo insuficiente, falha ao abrir arquivo e opção inválida no menu
- **Controle de fluxo**: menu interativo com `while` e `switch-case`

## Como compilar e executar

Precisa do `gcc` instalado.

```bash
gcc system.c -o caixa
./caixa
```

No Windows (PowerShell ou CMD):

```bash
gcc system.c -o caixa.exe
caixa.exe
```

## Estrutura

```
.
├── system.c     # código-fonte
├── saldo.txt    # gerado ao sair do programa
└── README.md
```

## Melhorias futuras

- Validar a leitura do `scanf` para evitar loop infinito quando o usuário digita letras
- Permitir mais de uma conta
- Pedir o nome do titular na inicialização
- Registrar histórico de transações
