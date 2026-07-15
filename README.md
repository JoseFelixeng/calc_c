# Calculadora em C

Calculadora de linha de comando com histórico de operações salvo em arquivo e
testes automatizados.

## Estrutura do projeto

```
calculadora/
├── main.c        # Programa principal (menu interativo)
├── menu.h/.c     # Exibição do menu
├── funcoes.h/.c  # Operações matemáticas (soma, sub, mult, divisao, pot, perc, raiz, resto)
├── historico.h/.c# Salvamento e exibição do histórico de operações
├── testes.c      # Bateria de testes automatizados
└── README.md
```

## Funcionalidades

- Soma, subtração, multiplicação, divisão, potenciação, raiz quadrada
  (método babilônico), porcentagem e resto da divisão.
- Cada operação realizada é registrada automaticamente em `historico.txt`,
  com data, hora, operação e resultado.
- Opção **9** do menu exibe o histórico salvo até o momento.
- `testes.c` roda uma bateria de casos de teste (incluindo casos de borda,
  como divisão por zero) e grava o resultado em `testes.txt`.

## Como compilar

Requer `gcc` e a biblioteca matemática (`-lm`, usada por `raiz`).

**Programa principal:**
```bash
gcc -Wall -o calculadora main.c menu.c funcoes.c historico.c -lm
```

**Testes automatizados:**
```bash
gcc -Wall -o testes testes.c funcoes.c -lm
```

## Como usar

**Rodar a calculadora:**
```bash
./calculadora
```
Escolha uma opção do menu (0 a 9) e siga as instruções na tela. Cada
resultado é impresso no terminal e também salvo em `historico.txt`
(criado automaticamente na primeira operação).

**Rodar os testes:**
```bash
./testes
```
O resumo aparece no terminal e o detalhamento completo (esperado vs.
obtido, PASSOU/FALHOU) é salvo em `testes.txt`.

## Arquivos gerados em tempo de execução

- `historico.txt` — histórico de operações da calculadora (cresce a cada
  uso; não é apagado entre execuções).
- `testes.txt` — relatório da última execução dos testes (sobrescrito a
  cada execução).

## Observações de implementação

- A função `div` da linguagem C original foi renomeada para `divisao`
  para evitar conflito com a função `div()` da `stdlib.h`.
- `divisao`, `perc` e `resto` protegem contra divisão por zero, imprimindo
  um aviso e retornando `0` nesse caso.
- `raiz` usa o método babilônico (Newton-Raphson) com precisão de
  `0.00001` e trata número negativo retornando `-1` com aviso.
