#include <stdio.h>
#include "menu.h"

int main(){
    int opcao; 
    int a, b; 

    do {
        menuPrincipal();
        scan("%d", &opcao); 
        
        /*Criando o Menu*/
        switch(opcao){
            case 1:
                printf("Digite dois numeros: ");
                scanf("%d %d", &a, &b);
                printf("Resultado: %d\n", soma(&a,&b));

            case 2:
                printf("Digite dois numeros: ");
                scanf("%d %d", &a, &b);
                printf("Resultado: %d\n", sub(&a,&b));

            case 3:
                printf("Digite dois numeros: ");
                scanf("%d %d", &a, &b);
                printf("Resultado: %d\n", mult(&a,&b));

            case 4:
                printf("Digite dois numeros: ");
                scanf("%d %d", &a, &b);
                printf("Resultado: %d\n", div(&a,&b));
                
            case 5:
                printf("Digite dois numeros: ");
                scanf("%d %d", &a, &b);
                printf("Resultado: %d\n", pot(&a,&b));

            case 0:
                printf("Programa encerrado.\n");
                break;

            default:
                printf("Opção inválida!\n");
        }while(op !=0);
    }
    return 0;
}