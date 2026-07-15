#ifndef HISTORICO_H
#define HISTORICO_H

// Salva uma linha no arquivo historico.txt com data/hora, operação e resultado
void salvarHistorico(const char *operacao, double resultado);

// Imprime na tela o conteúdo do historico.txt
void exibirHistorico(void);

#endif