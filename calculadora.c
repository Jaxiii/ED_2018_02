#include "calculadora.h"

void calculadora(){
    char entrada[9];
    t_pilha* pilha = cria_pilha();
    printf("%s", "\nPilha vazia inicializada!\n");
    printf("%s", "'q' para sair!\n");
    
    do {
        printf("%s", "\nEntrada-> ");
        scanf("%s", entrada);

        if ( isdigit(entrada[0]) != 0 ||
        (entrada[0] == '-' && isdigit(entrada[1]) != 0 )){
            push(pilha, converteCharFloat(entrada));
            imprime_pilha(pilha);
        } 
        else if (entrada[0] != 'q') {
            operacao(pilha, entrada);
        }
    } while (entrada[0] != 'q');

    libera_pilha(pilha);
}

int converteCharInt (char* num){
	int digito = 0;
	int tamanho = strlen(num);
	for(int i=0; i < tamanho; i++){
		digito = digito * 10 + (num[i]-'0');
	}
    return digito;
}

float converteCharFloat(char* digito){
  float total = 0;
  float sinal = 1;
  int decimal;
  if (digito[0] == '-'){
    digito++;
    sinal = -1;
  }
  for (decimal = 0; *digito; digito++){
    if (*digito == '.'){
      decimal = 1; 
      continue;
    }
    int d = *digito - '0';
    if (d >= 0 && d <= 9){
      if (decimal) sinal /= 10.0f;
      total = total * 10.0f + (float)d;
      total = total*sinal;
    }
  }
  return total;
}

char operacao(t_pilha *pilha, char *operando){
    if (*operando == '+' || *operando == '-' || *operando == '*' || 
        *operando == '/' || *operando == 'c') {

        if (operando[0] == '+'){
            if (operando[1] != '!') {
                t_elemento* atual = pilha->topo;
                if (atual->anterior != NULL){
                    float a = pop(pilha);
                    float b = pop(pilha);
                    push(pilha, ( a + b ));
                    imprime_pilha(pilha);
                    return ('+');
                }
                else {
                    printf("%s", "Operandos insuficientes!");
                    return ('0');
                }
            } else {
                while (pilha->topo->anterior != NULL) {
                    float a = pop(pilha);
                    float b = pop(pilha);
                    push(pilha, ( a + b ));
                }
                imprime_pilha(pilha);
                return ('!');
            }

        }
        if (operando[0] == '-'){
            if (operando[1] != '!') {
                t_elemento* atual = pilha->topo;
                if (atual->anterior != NULL){
                    float a = pop(pilha);
                    float b = pop(pilha);
                    push(pilha, ( a - b ));
                    imprime_pilha(pilha);
                    return ('-');
                }
                else {
                    printf("%s", "Operandos insuficientes!");
                    return ('0');
                }
            } else {
                while (pilha->topo->anterior != NULL) {
                    float a = pop(pilha);
                    float b = pop(pilha);
                    push(pilha, ( a - b ));
                }
                imprime_pilha(pilha);
                return ('!');
            }

        }    
        if (operando[0] == '*'){
            if (operando[1] != '!') {
                t_elemento* atual = pilha->topo;
                if (atual->anterior != NULL){
                    float a = pop(pilha);
                    float b = pop(pilha);
                    push(pilha, ( a * b ));
                    imprime_pilha(pilha);
                    return ('*');
                }
                else {
                    printf("%s", "Operandos insuficientes!");
                    return ('0');
                }
            } else {
                while (pilha->topo->anterior != NULL) {
                    float a = pop(pilha);
                    float b = pop(pilha);
                    push(pilha, ( a * b ));
                }
                imprime_pilha(pilha);
                return ('!');
            }

        }
        if (operando[0] == '/'){
            if (operando[1] != '!') {
                t_elemento* atual = pilha->topo;
                if (atual->anterior != NULL){
                    float a = pop(pilha);
                    float b = pop(pilha);
                    push(pilha, ( a / b ));
                    imprime_pilha(pilha);
                    return ('/');
                }
                else {
                    printf("%s", "Operandos insuficientes!");
                    return ('0');
                }
            } else {
                while (pilha->topo->anterior != NULL) {
                    float a = pop(pilha);
                    float b = pop(pilha);
                    push(pilha, ( a / b ));
                }
                imprime_pilha(pilha);
                return ('!');
            }

        }
        if (*operando == 'c'){
            float N = pop(pilha);
            float K = pop(pilha);

            for ((int)N; N > 0; N--) {
                push(pilha, K);
            }
            imprime_pilha(pilha);
            return ('c');
        }
    } else {
        printf("%s", "Operacao invalida!");
        return 0.0;
    }
}

void clr_screen(){
    int i = 0;
    while (i < 25){
        printf("%s","\n");
        i++;
    }
}