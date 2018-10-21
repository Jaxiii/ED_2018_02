#ifndef CALCULADORA_H_INCLUDED
#define CALCULADORA_H_INCLUDED

#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>
#include <string.h>
#include "pilha.h"

void calculadora();
void clr_screen();
float converteCharFloat(char *digito);
char operacao(t_pilha *pilha, char *operando);

#endif 