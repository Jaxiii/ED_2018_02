#include "pilha.h"

t_elemento* cria_elemento(float dado){
    t_elemento* novo_elemento = malloc(sizeof(t_elemento));
    novo_elemento->dado = dado;
    novo_elemento->anterior = NULL;
    return novo_elemento;
}
t_pilha* cria_pilha () {
    t_pilha* nova_pilha = malloc(sizeof(t_pilha));
    nova_pilha->topo = NULL;
    return nova_pilha;
}

int libera_elemento(t_elemento* elemento){
    if(elemento != NULL){
        free(elemento);
        return 1;
    } else {
        return 0;
    }
}

int libera_pilha(t_pilha* pilha){
    if(pilha != NULL){
        while (pilha->topo != NULL){
            t_elemento* aux = pilha->topo;
            pilha->topo = aux->anterior;
            libera_elemento(aux);
        }
        free(pilha);
        return 1;
    }
        else {
            return 0;
        }
}
int push(t_pilha* pilha, float dado){
    if (pilha != NULL) {
        t_elemento* novo_elemento = cria_elemento(dado);
        novo_elemento->anterior = pilha->topo;
        pilha->topo = novo_elemento;
        return 1;
    }
    else {
        return 0;
    }
}

float pop(t_pilha* pilha){
    if ( pilha->topo != NULL) {
        t_elemento* elemento = pilha->topo;
        pilha->topo = elemento->anterior;
        float elem = elemento->dado;
        free(elemento);
        return elem;

    }
    else {
        error();
        return 0.0;
    }
}

t_elemento* peek(t_pilha* pilha) {
        return pilha->topo;
}

void error(){
    printf("%s","ERROR\n");
}

void imprime_pilha(t_pilha* pilha){
    t_elemento* atual = pilha->topo;
    while(atual != NULL){
        printf("Pilha -> %.2f\n",atual->dado);
        atual = atual->anterior;
    }
}
