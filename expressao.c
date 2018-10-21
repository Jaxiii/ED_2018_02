#include "expressao.h"
#include "calculadora.h"

void expressao(){
    char entrada[30];
    int tamanho, i;
    printf("%s", "\nModo expressao!\n");
    printf("%s", "\nEntrada -> ");

    scanf("%s", entrada);
    tamanho = strlen(entrada);
    t_pilha* pilha = cria_pilha();

    for (i = 0; i <= tamanho; i++){
        if (entrada[i] == '('){
            push(pilha, (float)entrada[i]);
        }
        if (entrada [i] == ')') {
            if (pilha->topo == NULL){
                printf("%s", "\nExpressao invalida! Retornando ao menu...\n");
                break;
            } else {
                pop(pilha);
            }
        }
    }
    if (pilha->topo != NULL) {
        printf("%s", "\nExpressao invalida! Retornando ao menu...\n");
    } else {
        printf("%s", "\nExpressao valida! Iniciando transformacao\n");
        libera_pilha(pilha);
        t_pilha* pilha = cria_pilha();
        transforma(entrada);
    }
}

char* transforma(char *entrada){
    char saida[30] = {};
    char tmp = '0';
    int j = 0;
    int tamanho = strlen(entrada);
    t_pilha* pilha = cria_pilha();
    printf("%s", "\nResultado da transformacao: ");
    for (int i = 0; i <= tamanho; i++) {
        if (isdigit(entrada[i]) != 0){
            printf("%c", entrada[i]);
            saida[j] = entrada[i];
            j++;
        }
        if (isalpha(entrada[i]) != 0){
            printf("%c", entrada[i]);
            saida[j] = entrada[i];
            j++;
        }
        if (entrada[i] == '+' || entrada[i] == '-' || 
        entrada[i] == '*' || entrada[i] == '/' ) {

            if (pilha->topo != NULL && (pilha->topo->dado == (float)'/' ||
                pilha->topo->dado == (float)'*')){
                    if(entrada[i] == '*' || entrada[i] == '/');
                    tmp =(char)pop(pilha);
                    printf("%c", tmp);
                    saida[j] = tmp;
                    j++;
                    push(pilha, (float)entrada[i]);
            } else {
                push(pilha, (float)entrada[i]);
            }
        }
        if (entrada[i] == '('){
            push(pilha, (float)entrada[i]);
        }
        if (entrada[i] == ')'){
            float verifica = 0.0;
            do {
                verifica = pop(pilha);
                if (verifica != (float)'('){
                    printf("%c", (char)verifica);
                    saida[j] = (char)verifica;
                    j++;
                }
            }while (verifica != (float)'(');
        }

    }
    while (pilha->topo != NULL) {
        tmp = (char)pop(pilha);
        printf("%c", tmp);
        saida[j] = tmp;
        j++;
    }
    libera_pilha(pilha);
    char* retorno = saida;
    return retorno;
}