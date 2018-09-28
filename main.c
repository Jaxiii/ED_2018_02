#include "pilha.h"
#include <stdio.h>

void main(){
    t_pilha* pilha = cria_pilha();
    printf("%f\n",pop(pilha));  
}