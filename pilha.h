#include <stdlib.h>
#include <stdio.h>

/*!
    Estrutura do elemento a ser empilhado/desempilhado
*/
typedef struct elemento{
    float dado;   /*!< Armazena um dado do tipo inteiro no elemento*/
    struct elemento* anterior; /*!< Elemento anterior.*/     
} t_elemento;

typedef struct pilha{
    t_elemento* topo; /*!< Armazena o endereço do topo da pilha*/
} t_pilha;

    //! A normal member taking two arguments and returning an integer value.
    /*!
      \param a an integer argument.
      \param s a constant character pointer.
      \return The test results
      \sa QTstyle_Test(), ~QTstyle_Test(), testMeToo() and publicVar()
    */

t_elemento* cria_elemento(float dado);
t_pilha* cria_pilha (); /*! Aloca memoria para a pilha*/
int libera_elemento(); /*! Libera a memoria alocada para elementos*/
int libera_pilha(); /*! Libera a memoria alocada para a lista*/
int push(t_pilha* pilha, float dado); /*! Adiciona um novo elemento no topo da pilha*/
float pop(t_pilha* pilha); /*! Retira e retorna o elemento no topo da pilha*/
float peek(); /*! Retorna o elemento no topo da pilha*/
void imprime_pilha(t_pilha* pilha); /*! Imprimie toda a pilha*/
void error();