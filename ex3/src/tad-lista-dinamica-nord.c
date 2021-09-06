#include "tad-lista-dinamica-nord.h"
#include <stdlib.h>

struct no
{
    TIPO_DE_DADO info;
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
Lista cria_no(TIPO_DE_DADO info) 
{
    Lista novo_no;
    novo_no = (Lista) malloc(sizeof(struct no));

    if (novo_no != NULL)
        novo_no->info = info;

    return novo_no;
}


int insere_elem(Lista *lst, TIPO_DE_DADO elem)
{
    // aloca e setta
    Lista N = cria_no(elem);

    if (N == NULL) return 0; // nao foi possivel criar elemento 

    N->prox = *lst;
    *lst = N;
    
    return 1; 
}

void remove_no(Lista *lista, Lista *retardatario, Lista *cursor) {
    if ((*retardatario) != NULL)
        (*retardatario)->prox = (*cursor)->prox; // excluir, se houver, antecessor

    if (*cursor == *lista)  // se for a cabeça, tem que reatribui-la
        *lista = (*cursor)->prox;            

    free(*cursor);
    *cursor = NULL;
}

int remove_elem_pos(Lista *lista, int position)
{
    if (lista_vazia(*lista)) return 0; // lista vazia nao tem elemento

    Lista cursor = *lista;
    Lista retardatario = NULL;

    // encontrar o elemento a ser removido & seu antecessor
    while (cursor != NULL && position > 1)
    {
        retardatario = cursor;
        cursor = cursor->prox;
        position--;
    }

    if (position == 1 && cursor != NULL)
    {
        remove_no(lista, &retardatario, &cursor);

        return 1;
    }
    return 0;
}

int remove_elem(Lista *lista, TIPO_DE_DADO dado) {
    if (lista_vazia(*lista)) return 0; // lista vazia nao tem elemento

    Lista cursor = *lista;
    Lista retardatario = NULL;

    // encontrar o elemento a ser removido & seu antecessor
    while (cursor != NULL)
    {
        if (cursor->info == dado)
        {
            remove_no(lista, &retardatario, &cursor);
            return 1;
        }

        retardatario = cursor;
        cursor = cursor->prox;
    }

    return 0;
}

int get_elem_pos(Lista lst, int pos, TIPO_DE_DADO *retorno_implicito)
{
    if (lista_vazia(lst))
        return 0; // lista vazia nao tem elementos

    Lista cursor = lst;
    while (pos > 1)
    {
        if (cursor == NULL)
            return 0;

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

TIPO_DE_DADO remove_menor(Lista *lst, int *status) {
    if (lista_vazia(*lst)) {*status = 0; return 0;} // lista vazia nao retorna nada mesmo

    Lista cursor = (*lst)->prox;
    Lista menor  = *lst;
    Lista retardatario_menor = menor;
    Lista retardatario = *lst;

    while (cursor != NULL) {
        if (cursor->info <= menor->info) {
            retardatario_menor = retardatario; // o queprecisamos mudar a ref
            menor = cursor;

        }

        retardatario = cursor;
        cursor = cursor->prox;
    }


    TIPO_DE_DADO menor_dado = menor->info;

    retardatario_menor->prox = menor->prox; // mudar, no pior dos casos é ele mesmo, que vai ser removido

    if (menor == *lst)
        *lst = menor->prox; // caso seja a cabeça da lista, atualizá-la antes

    free(menor); menor = NULL;
    *status = 1;
    return menor_dado;
}

int apaga_lista(Lista *lst)
{
    if (lista_vazia(*lst))
        return 0;
    else
    {
        Lista cursor = *lst;
        while (*lst != NULL) 
        {
            cursor = *lst;
            *lst = (*lst)->prox; // nova cabeça é o próximo
            
            free(cursor); cursor = NULL; // libera o atual nodo
        }
        return 1;
    }
}

int iguais(Lista lst1, Lista lst2) {
    if (lst1 == NULL || lst2 == NULL) { // se algum estiver vazio
        if (lst1 == lst2)               // se ambas estiverem eh vdd
            return 1;
        else
            return 0;                   // se nao, nao eh
    } else {                            // nao tem vazios
        if (lst1->info == lst2->info)
            return iguais(lst1->prox, lst2->prox); // eh igual se os demais forem iguais
        else
            return 0;                              // do contrário nao é
    }
}

void insere_e_avance(Lista *lst, Lista inserir) {
    inserir->prox = NULL;

    if (*lst == NULL)
        *lst = inserir;
    else {
        (*lst)->prox = inserir;
        (*lst) = (*lst)->prox;
    }
}

Lista intercalar(Lista lst1, Lista lst2) {
    Lista nova_lista = cria_lista();
//    Lista nova_lista_cursor = nova_lista;

    Lista cursor[2] = {lst1, lst2};

    while (cursor[0] != NULL || cursor[1] != NULL) 
    {
        for (int i = 0; i < 2; i++) 
        {
            if (cursor[i] != NULL) 
            {
                //insere_e_avance(&nova_lista_cursor, cria_no(cursor[i]->info));
                insere_elem(&nova_lista, cursor[i]->info);
                cursor[i] = cursor[i]->prox;
            }
        }
    }

    return nova_lista;
}

