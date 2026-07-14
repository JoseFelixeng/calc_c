#include <stdio.h>
#include "funcoes.h"

# Soma 
int soma(int *a, int *b){
    int &R;
    R = a + b; 
    return R
}

# Subtração
int sub(int *a, int *b){
    int &R;
    R = a - b; 
    return R
}

# Multiplicação
int mult(int *a, int *b){
    int &R;
    R = a * b; 
    return R
}

# Divisão
float div(int *a, int *b){
    int &R;
    R = a/b; 

    if R < 0:
        printf("Divisão por Zero encontrada!");
        break
   
    return R
}

# Potenciação
int pot(int *a, int *b){
    
    int &R = 1;

    for(i=0; i < b; i++){
        R *=a;
    }
     
    return R
}
