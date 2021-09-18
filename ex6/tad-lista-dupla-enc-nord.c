// TAD - lista dinâmica/encadeada duplamente-encadeada e não-ordenada de doubles

#ifndef STDLIB_INCLUIDA
#define STDLIB_INCLUIDA 1
#include <stdlib.h>
#endif
#include "tad-lista-dupla-enc-nord.h"

struct no {
    no_p ant;
    INFO_ARMAZENADA info;
    no_p prox;
};

// retornar null e criar de acordo
no_p cria_lista() {
    return NULL;
}

// encapsulada - aloca um novo elemento
no_p novo_elemento(INFO_ARMAZENADA info) {
    no_p criando = (no_p) malloc(sizeof(struct no));

    if (criando != NULL) {
        criando->ant  = NULL;
        criando->prox = NULL;
        criando->info = info;
    }

    return criando;
}

// check de lista vazia
int lista_vazia(no_p lista) {
    if (lista == NULL)
        return 1;
    else
        return 0;
}

// insercao mais simples - no inicio
int insere(no_p *lista, INFO_ARMAZENADA inserir) {
    no_p inserindo = novo_elemento(inserir);
    if (inserindo == NULL) return 0; // evitar erro de memoria
    
    if (lista_vazia(*lista)) { // adicione referencia se vazia
        *lista = inserindo;
        return 1;
    } else { // do contrario insira adiante
        inserindo->prox = (*lista)->prox;
        inserindo->ant  = *lista;
        (*lista)->prox  = inserindo;
        return 1;
    }
}

// remocao do elemento passado como parametro
int remove_nord(no_p *lista, INFO_ARMAZENADA remove) {
    if (lista_vazia(*lista)) return 0;

    no_p cursor = *lista;
    while (cursor != NULL) {
        if (cursor->info == remove) {
            // CASO cursor a remover eh a cabeca da lista 
            if (cursor == *lista) {
                free(cursor);
                cursor = NULL;
                return 1;
            }

            // CASO cursor a remover eh depois da cabeca
            if (cursor->ant)
                cursor->ant->prox = cursor->prox;
            if (cursor->prox)
                cursor->prox->ant = cursor->ant;

            free(cursor); cursor = NULL;
            return 1;
        } else {
            cursor = cursor->prox;
        }
    }

    return 0;
}

// retorna o elemento que esta na posicao passada como parametro
INFO_ARMAZENADA get_elem_pos(no_p lista, int pos, int *flag) {
    if (pos < 1) { // posicao invalida
        *flag = 0;     
        return ELEMENTO_NAO_ENCONTRADO;

    } else if (lista_vazia(lista)) { // nao ha elementos
        *flag = 0;
        return ELEMENTO_NAO_ENCONTRADO;

    } else { // pode haver ou n
        no_p cursor = lista;
        while (cursor != NULL && pos > 1) { // percorrer ate o elemento ou nulo
            cursor = cursor->prox;
            pos--;
        }
        
        if (pos == 1 && cursor != NULL) {
            *flag = 1;
            return cursor->info;

        } else { // nao encontrou nos ciclos
            *flag = 0;
            return ELEMENTO_NAO_ENCONTRADO;
        }
    }
}

// tira a lista da memoria
int esvazia_lista(no_p *lista) {
    if (lista_vazia(*lista)) { // lista vazia nao ha nada pra fazer
        return 1;

    } else {
        no_p prox;
        while ((*lista) != NULL) {
            prox = (*lista)->prox;
            free(*lista); 
            *lista = prox;
        } 
        return 1;
    }
}

// impl dinamica nao ha diferenca entre apaga e esvazia
int apaga_lista(no_p *lista) {
    return esvazia_lista(lista);
}

// encapsulada por danos possiveis
int remove_no(no_p *no) {
    if (lista_vazia(*no)) return 0; // vazio nao ha o que remover

    if ((*no)->ant != NULL) // se tiver anterior
        (*no)->ant->prox = (*no)->prox;
    
    if ((*no)->prox != NULL) // se tiver proximo
        (*no)->prox->ant = (*no)->ant;

    free(*no); 
    *no = NULL;

    return 1;
}

// remove todas ocorrencias de elemento da lista passada
int remove_todos(no_p *lista, INFO_ARMAZENADA remover_ocorrencias) {
    int cont = 0;

    no_p cursor = *lista;

    while (cursor != NULL) {
        if (cursor->info == remover_ocorrencias) {

            no_p aux = cursor; // cria no auxiliar porque ha de ser liberado
            cursor = cursor->prox;

            if (aux != *lista) { // caso geral
                remove_no(&aux);

            } else { // caso cabeca da lista
                *lista = aux->prox;
                if (!lista_vazia(*lista)) {
                    (*lista)->ant = NULL;
                }
                free(aux); aux = NULL;
            }

            cont++;

        } else {
            cursor = cursor->prox;
        }
    }
    return cont;
}

// remove o maior elemento da lista
int remove_maior(no_p *lista) {
    if (lista_vazia(*lista)) return 0; // nao ha como verificar em listas vazias

    no_p maior = *lista;
    no_p cursor = *lista;

    while (cursor != NULL) {
        if (cursor->info > maior->info) {
            maior = cursor;
        }
        cursor = cursor->prox;
    }

    return remove_todos(lista, maior->info);
}

// insere o elemento passado na posicao desejada
int insere_pos(no_p *lista, int pos, INFO_ARMAZENADA info) {
    if (pos < 1 || lista_vazia(*lista)) return 0; // lista vazia ou posicao invalida nao insere

    no_p cursor = *lista;

    while (cursor != NULL && pos > 1) {
        cursor = cursor->prox;
        pos--;
    }
    
    if (pos != 1) return 0; // acima do tamanho

    // achamos a posicao exata e eh cursor
    no_p inserindo = novo_elemento(info);
    
    if (cursor->ant != NULL) 
        cursor->ant->prox = inserindo;
    else if (cursor == *lista)
        *lista = inserindo;
    
    inserindo->prox = cursor;
    inserindo->ant  = cursor->ant;
    cursor->ant = inserindo;

    return 1;
}

// inverte a lista passada como parametro
int inverte(no_p *lista) {
    if (lista_vazia(*lista)) return 0; // lista vazia nao faz nada

    no_p prox;
    no_p temp_ult = NULL;
    no_p cursor = *lista;
    
    while (cursor != NULL) {
        prox = cursor->prox;

        cursor->prox = temp_ult;
        cursor->ant = prox;

        temp_ult = cursor;
        cursor = prox;
    }

    *lista = temp_ult;

    return 1;
}
