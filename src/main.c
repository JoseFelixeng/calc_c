#include <stdio.h>
#include "menu.h"
#include "funcoes.h"
#include "historico.h"

int main(){
    int opcao;
    int a, b;
    float c, d;
    double A;
    float resultado;
    char descricao[100];

    do {
        menuPrincipal();
        scanf("%d", &opcao);

        switch(opcao){
            case 1:
                printf("====================\n");
                printf("Operação SOMA\n");
                printf("====================\n");
                printf("Digite dois numeros: ");
                scanf("%d %d", &a, &b);
                resultado = soma(&a, &b);
                printf("Resultado: %.0f\n", resultado);
                snprintf(descricao, sizeof(descricao), "%d + %d", a, b);
                salvarHistorico(descricao, resultado);
                break;

            case 2:
                printf("====================\n");
                printf("Operação SUBTRAÇÃO\n");
                printf("====================\n");
                printf("Digite dois numeros: ");
                scanf("%d %d", &a, &b);
                resultado = sub(&a, &b);
                printf("Resultado: %.0f\n", resultado);
                snprintf(descricao, sizeof(descricao), "%d - %d", a, b);
                salvarHistorico(descricao, resultado);
                break;

            case 3:
                printf("====================\n");
                printf("Operação MULTIPLICAÇÃO\n");
                printf("====================\n");
                printf("Digite dois numeros: ");
                scanf("%d %d", &a, &b);
                resultado = mult(&a, &b);
                printf("Resultado: %.0f\n", resultado);
                snprintf(descricao, sizeof(descricao), "%d * %d", a, b);
                salvarHistorico(descricao, resultado);
                break;

            case 4:
                printf("====================\n");
                printf("Operação DIVISÃO\n");
                printf("====================\n");
                printf("Digite dois numeros: ");
                scanf("%f %f", &c, &d);
                resultado = divisao(&c, &d);
                printf("Resultado: %.5f\n", resultado);
                snprintf(descricao, sizeof(descricao), "%.2f / %.2f", c, d);
                salvarHistorico(descricao, resultado);
                break;

            case 5:
                printf("====================\n");
                printf("Operação POTENCIAÇÃO\n");
                printf("====================\n");
                printf("Digite base e expoente: ");
                scanf("%d %d", &a, &b);
                resultado = pot(&a, &b);
                printf("Resultado: %.0f\n", resultado);
                snprintf(descricao, sizeof(descricao), "%d ^ %d", a, b);
                salvarHistorico(descricao, resultado);
                break;

            case 6:
                printf("====================\n");
                printf("Operação RADICIAÇÃO\n");
                printf("====================\n");
                printf("Digite o numero para ser feita a raiz: ");
                scanf("%lf", &A);
                resultado = raiz(&A);
                printf("A raiz quadrada aproximada do numero é: %.5f\n", resultado);
                snprintf(descricao, sizeof(descricao), "raiz(%.2f)", A);
                salvarHistorico(descricao, resultado);
                break;

            case 7:
                printf("====================\n");
                printf("Operação PORCENTAGEM\n");
                printf("====================\n");
                printf("Digite um numero e a porcentagem: ");
                scanf("%f %f", &c, &d);
                resultado = perc(&c, &d);
                printf("Resultado: %.5f\n", resultado);
                snprintf(descricao, sizeof(descricao), "%.2f%% de %.2f", d, c);
                salvarHistorico(descricao, resultado);
                break;

            case 8:
                printf("====================\n");
                printf("Operação Resto\n");
                printf("====================\n");
                printf("Digite dois numeros: ");
                scanf("%d %d", &a, &b);
                resultado = resto(&a, &b);
                printf("Resultado: %.0f\n", resultado);
                snprintf(descricao, sizeof(descricao), "%d %% %d", a, b);
                salvarHistorico(descricao, resultado);
                break;

            case 9:
                exibirHistorico();
                break;

            case 0:
                printf("Programa encerrado.\n");
                break;

            default:
                printf("Opção inválida!\n");
        }
    } while(opcao != 0);

    return 0;
}