#include <stdio.h>
#include <time.h>
#include "historico.h"

#define ARQUIVO_HISTORICO "/data/historico.txt"

void salvarHistorico(const char *operacao, double resultado){
    FILE *arquivo = fopen(ARQUIVO_HISTORICO, "a");
    if (arquivo == NULL){
        printf("Erro ao abrir o arquivo de histórico!\n");
        return;
    }

    time_t agora = time(NULL);
    struct tm *tempo = localtime(&agora);
    char dataHora[32];
    strftime(dataHora, sizeof(dataHora), "%d/%m/%Y %H:%M:%S", tempo);

    fprintf(arquivo, "[%s] %s = %.5f\n", dataHora, operacao, resultado);

    fclose(arquivo);
}

void exibirHistorico(void){
    FILE *arquivo = fopen(ARQUIVO_HISTORICO, "r");
    if (arquivo == NULL){
        printf("\nAinda não há histórico registrado.\n");
        return;
    }

    char linha[256];
    printf("\n===== HISTÓRICO DE OPERAÇÕES =====\n");
    while (fgets(linha, sizeof(linha), arquivo) != NULL){
        printf("%s", linha);
    }
    printf("===================================\n");

    fclose(arquivo);
}