#include <stdio.h>
#include <math.h>
#include "funcoes.h"

int soma(int *a, int *b){
    int R;
    R = *a + *b;
    return R;
}

int sub(int *a, int *b){
    int R;
    R = *a - *b;
    return R;
}

int mult(int *a, int *b){
    int R;
    R = *a * *b;
    return R;
}

float divisao(float *a, float *b){
    float R;

    if (*b == 0){
        printf("Divisão por Zero encontrada!\n");
        return 0;
    }

    R = *a / *b;
    return R;
}

int pot(int *a, int *b){
    int R = 1;
    for (int i = 0; i < *b; i++){
        R *= *a;
    }
    return R;
}

float perc(float *a, float *b){
    float R;
    R = (*a * *b) / 100;
    return R;
}

double raiz(double *a){
    double precisao = 0.00001; // Margem de erro para parar o loop
    double x = *a;
    double b;

    if (x < 0){
        printf("Não é possível calcular raiz de número negativo!\n");
        return -1;
    }
    if (x == 0){
        return 0;
    }

    b = x / 2.0; // Chute inicial

    // Método babilônico para aproximações sucessivas
    while (fabs(b * b - x) > precisao) {
        b = (b + x / b) / 2.0;
    }

    return b;
}

float resto(int *a, int *b){
    float RF;

    if (*b == 0){
        printf("Divisão por Zero encontrada!\n");
        return 0;
    }

    RF = *a - ((*a / *b) * *b);
    return RF;
}