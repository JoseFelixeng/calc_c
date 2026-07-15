#include <stdio.h>
#include <math.h>
#include "funcoes.h"

static int totalTestes = 0;
static int testesPassaram = 0;
static FILE *arquivoTeste;

void verificar(const char *nomeTeste, double esperado, double obtido, double tolerancia){
    totalTestes++;
    int passou = fabs(esperado - obtido) <= tolerancia;
    if (passou) testesPassaram++;

    fprintf(arquivoTeste, "[%s] %-22s | Esperado: %10.5f | Obtido: %10.5f\n",
            passou ? "PASSOU" : "FALHOU", nomeTeste, esperado, obtido);
    printf("[%s] %s\n", passou ? "PASSOU" : "FALHOU", nomeTeste);
}

int main(void){
    int a, b;
    float fa, fb;
    double da;

    arquivoTeste = fopen("testes.txt", "w");
    if (arquivoTeste == NULL){
        printf("Erro ao criar arquivo de testes!\n");
        return 1;
    }

    fprintf(arquivoTeste, "===== RESULTADOS DOS TESTES AUTOMATIZADOS =====\n\n");

    // ---- soma ----
    a = 5; b = 3;
    verificar("soma(5,3)", 8, soma(&a, &b), 0.0001);
    a = -2; b = 7;
    verificar("soma(-2,7)", 5, soma(&a, &b), 0.0001);

    // ---- sub ----
    a = 10; b = 4;
    verificar("sub(10,4)", 6, sub(&a, &b), 0.0001);
    a = 3; b = 9;
    verificar("sub(3,9)", -6, sub(&a, &b), 0.0001);

    // ---- mult ----
    a = 6; b = 7;
    verificar("mult(6,7)", 42, mult(&a, &b), 0.0001);
    a = -3; b = 4;
    verificar("mult(-3,4)", -12, mult(&a, &b), 0.0001);

    // ---- divisao ----
    fa = 10; fb = 4;
    verificar("divisao(10,4)", 2.5, divisao(&fa, &fb), 0.0001);
    fa = 5; fb = 0;
    verificar("divisao(5,0) [zero]", 0, divisao(&fa, &fb), 0.0001);

    // ---- pot ----
    a = 2; b = 10;
    verificar("pot(2,10)", 1024, pot(&a, &b), 0.0001);
    a = 5; b = 0;
    verificar("pot(5,0)", 1, pot(&a, &b), 0.0001);

    // ---- perc ----
    fa = 200; fb = 15;
    verificar("perc(200,15%)", 30, perc(&fa, &fb), 0.0001);
    fa = 50; fb = 50;
    verificar("perc(50,50%)", 25, perc(&fa, &fb), 0.0001);

    // ---- raiz ----
    da = 16;
    verificar("raiz(16)", 4, raiz(&da), 0.001);
    da = 2;
    verificar("raiz(2)", 1.41421, raiz(&da), 0.001);
    da = 0;
    verificar("raiz(0)", 0, raiz(&da), 0.001);

    // ---- resto ----
    a = 10; b = 3;
    verificar("resto(10,3)", 1, resto(&a, &b), 0.0001);
    a = 20; b = 5;
    verificar("resto(20,5)", 0, resto(&a, &b), 0.0001);

    fprintf(arquivoTeste, "\n===== RESUMO =====\n");
    fprintf(arquivoTeste, "%d de %d testes passaram.\n", testesPassaram, totalTestes);
    fclose(arquivoTeste);

    printf("\n%d de %d testes passaram. Veja testes.txt para detalhes.\n", testesPassaram, totalTestes);

    return (testesPassaram == totalTestes) ? 0 : 1;
}