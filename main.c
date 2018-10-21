#include "calculadora.h"
#include "expressao.h"
#include "pilha.h"
#include <stdlib.h>
#include <stdio.h>

int main(void){
    int input;

    do
    {
        printf("\nMenu:\n");
        printf("\n1 - Modo Expressao\n");
        printf("2 - Modo Calculadora\n");
        printf("0 - Sair\n");
        printf("\n-> ");
        scanf("%i", &input);

        switch (input)
        {
            case 1:
                expressao();
                break;
            case 2:
                calculadora();
                break;
            case 0:
                printf("%s", "Finalizando...\n");
                break;
            default:
                clr_screen();
                printf("%s", "Opcao invalida! Tente novamente\n");
                break;
        }
    } while (input != 0);
}