#include <stdio.h>
#include "funcoes.h"

void soma(int *a, int *b){
    printf("Operação Soma");
    int &R;
    R = a + b; 
    return R
}

void sub(int *a, int *b){
    printf("Operação Subtração");
    int &R;
    R = a - b; 
    return R
}

void mult(int *a, int *b){
    printf("Operação Multiplicação");
    int &R;
    R = a * b; 
    return R
}


void div(int *a, int *b){
    printf("Operação Subtração")
    int &R;
    R = a/b; 

    if R < 0:
        printf("Divisão por Zero encontrada!");
        break
   
    return R
}