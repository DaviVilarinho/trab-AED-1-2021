#include "tad-lista-dinamica-ord.h"
#include <stdlib.h>

struct no
{
    float info;
    Lista prox;
};

Lista cria_lista()
{
    return NULL;
}

int lista_vazia(Lista lst)
{
    return (lst == NULL);
}

// encapsulada (nao acessivel aos clients)
Lista cria_no(float info) 
{
    Lista novo_no;
    novo_no = (Lista) malloc(sizeof(struct no));

    if (novo_no != NULL)
        novo_no->info = info;

    return novo_no;
}


int insere_elem(Lista *lst, float elem)
{
    // aloca e setta
    Lista N = cria_no(elem);
    N->info = elem;

    if (lista_vazia(*lst))
    {
        *lst = N;
        N->prox = NULL;
    }

    N->prox = *lst;
    *lst = N;
    
    return 1; 
}

// TODO colocar pra remover do primeiro
// int remove_elem(Lista *lista)
// {
//     if (lista_vazia(*lista))
//         return 0;

//     Lista cursor = *lista;
//     Lista retardatario = NULL;

//     return 0;
// }

// int remove_elem_pos(Lista *lista, int position)
// {
//     if (lista_vazia(*lista)) return 0; // lista vazia nao tem elemento

//     Lista cursor = *lista;
//     Lista retardatario = NULL;

//     // encontrar o elemento a ser removido & seu antecessor
//     while (cursor != NULL && position > 1)
//     {
//         retardatario = cursor;
//         cursor = cursor->prox;
//         position--;
//     }

//     if (position == 1 && cursor != NULL)
//     {
//         remove_no(lista, &retardatario, &cursor);
//         return 1;
//     }
//     return 0;
// }

int get_elem_pos(Lista lst, int pos, float *retorno_implicito)
{
    if (lista_vazia(lst))
        return 0; // lista vazia nao tem elementos

    Lista cursor = lst;
    while (pos > 1 && cursor != NULL)
    {
        cursor = cursor->prox;
        pos--;
    }

    if (pos == 1 && cursor != NULL)
    {
        *retorno_implicito = cursor->info;
        return 1; 
    }
    else
        return 0;
}

// TODO implementar
// int get_menor(Lista lista, float *retorno_implicito);

// TODO deixar mais simples
// int apaga_lista(Lista *lista)
// {
//     if (lista_vazia(*lista))
//         return 0;
//     else
//     {
       
//     }
// }
