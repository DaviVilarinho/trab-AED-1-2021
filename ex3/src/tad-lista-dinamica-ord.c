#include "tad-lista-dinamica-ord.h"
#include <stdlib.h>

struct no {
    float info;
    Lista prox;
};

Lista cria_lista() {
    return NULL;
}

int lista_vazia(Lista lista) {
    if (lista == NULL) return 1;
    else               return 0;
}

// encapsulada cria_no
Lista cria_no(float info) {
    Lista novo_no;
    novo_no = (Lista) malloc(sizeof(struct no));

    if (novo_no != NULL)
        novo_no->info = info;

    return novo_no;
}

void coloca_entre(Lista *o_colocado, Lista *antecessor, Lista *atual) {
    (*o_colocado)->prox = *atual;
    (*antecessor)->prox = (*o_colocado);
}

int insere_elem_ord(Lista *lista, float elem) {
    Lista inserindo = cria_no(elem);

    if (inserindo != NULL) {
        if (lista_vazia(*lista)) {
            *lista = inserindo;             // lista vazia só apontar para o novo nó alocado
            return 1;
        } else if ((*lista)->info >= elem) {
            inserindo->prox = *lista;       
            *lista = inserindo;             // inserindo no início

            return 1;
        }
        // casos não cobertos: no miolo

        Lista retardatario = *lista;
        Lista cursor = (*lista)->prox;

        // se estiver no miolo
        while (cursor != NULL) {
            if (cursor->info >= elem) {
                coloca_entre(&inserindo, &retardatario, &cursor);
                return 1;
            }

            retardatario = cursor;
            cursor = cursor->prox;
        }

        // se passou tudo, o cursor é nulo, basta inserir no proximo do retardatario
        retardatario->prox = inserindo;
        return 1;
         
    } else {
        return 0; // falha na alocacao de memória
    }
}

void remove_no(Lista *lista, Lista *retardatario, Lista *cursor) {
    if ((*retardatario) != NULL)
        (*retardatario)->prox = (*cursor)->prox; // excluir, se houver, antecessor

    if (*cursor == *lista)  // se for a cabeça, tem que reatribui-la
        *lista = (*cursor)->prox;            

    free(*cursor);
    *cursor = NULL;
}

int remove_elem_ord(Lista *lista, float elem) {
    if (lista_vazia(*lista)) return 0; // lista vazia

    Lista cursor = *lista;
    Lista retardatario = NULL;

    // percorre até encontrar
    while (cursor != NULL) {
        if (cursor->info == elem) {
            remove_no(lista, &retardatario, &cursor);
            return 1;
        }
        retardatario = cursor;
        cursor = cursor->prox;
    }

    return 0; // nao encontrado

}

int remove_elem_pos(Lista *lista, int position) {
    if (lista_vazia(*lista)) return 0; // lista vazia nao tem elemento

    Lista cursor = *lista;
    Lista retardatario = NULL;

    // encontrar o elemento a ser removido & seu antecessor
    while (cursor != NULL && position > 1) {
        retardatario = cursor;
        cursor = cursor->prox;
        position--;
    }

    if (position == 1 && cursor != NULL) {
        remove_no(lista, &retardatario, &cursor);

        return 1;
    }

    return 0;
}

float get_elem_pos(Lista lista, int pos, float *retorno_implicito) {
    if (lista_vazia(lista)) {return 0;} // lista vazia nao tem elementos

    Lista cursor = lista;
    while (pos > 1 && cursor != NULL) {
        cursor = cursor->prox;
        pos--;
    }

    if (pos == 1 && cursor != NULL) {
        *retorno_implicito = cursor->info;
        return 1; 
    } else {
        return 0;
    }
}

int get_maior(Lista lista, float *retorno_implicito);
int get_menor(Lista lista, float *retorno_implicito);

int inverte(Lista *lista);

int apaga_lista(Lista *lista) {
    if (lista_vazia(*lista)) return 0;
    else {
        Lista resto = (*lista)->prox;
        free(*lista); *lista = NULL; // esvaziar atual
        return 1 + esvazia_lista(&resto); // e o resto
    }
}


