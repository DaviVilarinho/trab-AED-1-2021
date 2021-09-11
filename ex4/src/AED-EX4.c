#include <stdio.h>
#include <stdlib.h>
#include "AED-EX4.h"

//Cria uma lista
Lista cria_lista ()
{
    Lista cabecalho; //Aloca nó cabeçalho
    cabecalho = (Lista) malloc(sizeof(struct no));

    if (cabecalho != NULL) //Só se alocação não falhar
    {
        cabecalho -> prox = NULL;
        cabecalho -> info = 0; //Guarda quantidade
    }

    return cabecalho; //Se alocação falhar, retorna NULL
}

//Pega o tamanho da lista
int tamanho (Lista *lst)
{
    return (*lst) -> info;
}

//Apaga a lista, INCLUSIVE o nó cabeçalho
int apaga_lista (Lista *lst)
{
    esvazia_lista (lst); //Esvazia a lista
    free (*lst); //Dá free no nó cabeçalho

    return 1;
}

//Esvazia a lista, mas MANTÉM o nó cabeçalho
int esvazia_lista (Lista *lst)
{
    if (lst == NULL) //Se já tiver vazia, retorna 1
        return 1;
    
    Lista aux = (*lst) -> prox; //Aux aponta para o nó depois do cabeçalho
    Lista aux2;
  
    while (aux != NULL) //Loop que limpa do 1º nó (tirando o cabeçalho) até o último
    {
        aux2 = aux -> prox;
        free(aux);
        aux = aux2;
    }
    
    (*lst) -> info = 0; //Seta qtde de nós pra 0
    return 1;
}

//Pega o elemento na posição desejada
int get_elem_pos (Lista *lst, int pos, int *var)
{
    /* Se a posição for maior que a quantia de nós OU se posição desejada for menor que 0
    OU se a quantia de nós na lista for 0, a função retorna 0*/
    if ((*lst) -> info < pos || pos < 0 || (*lst) -> info == 0)
        return 0;

    Lista aux = (*lst) -> prox; //Aux aponta para o nó depois do cabeçalho

    while (aux != NULL && pos--) //Seta o aux até a posição desejada
        aux = aux -> prox;

    if (aux == NULL)
        return 0;

    *var = aux -> info;

    return 1;
}

//Remove o elemento na posição desejada
int rem_elem_pos (Lista *lst, int pos)
{
    if ((*lst) -> info < pos || pos < 0 || (*lst) -> info == 0)
        return 0;

    Lista aux = *lst; //Aux aponta para o nó depois do cabeçalho

    while (aux != NULL && pos--) //Seta o aux até a posição desejada
        aux = aux -> prox;

    if (aux == NULL)
        return 0;

    int elem = aux -> info;
    remove_ord (lst, elem); //Remove o elemento dessa posição

    return 1;
}

//Insere um elemento na lista de forma ordenada
int insere_ord (Lista *lst, int elem)
{
    Lista N = (Lista) malloc(sizeof(struct no));

    if (N == NULL)
        return 0; //Falha, não alocado

    N -> info = elem; //Insere o valor do elem

    //Percorrimento da lista
    Lista aux = *lst; //Aux aponta para o nó cabeçalho

    while (aux -> prox != NULL && aux -> prox -> info < elem)
        aux = aux -> prox; //Avança

    //Insere o novo elemento na lista
    N -> prox = aux -> prox;
    aux -> prox = N;
    (*lst) -> info++; //Incrementa qtde de nós na lista

    return 1;
}

//Remove um nó
int remove_ord (Lista *lst, int elem)
{
    if (lst == NULL)
        return 0; //Falhou

    Lista aux = *lst; //Ponteiro auxiliar para o 1º nó

    //Percorrimento até fim da lista, achar elem ou nó maior
    while (aux -> prox != NULL && aux -> prox -> info < elem)
        aux = aux -> prox;

    if (aux -> prox == NULL || aux -> prox -> info > elem)
        return 0; //Falhou

    //Remove elemento =/= 1º nó da lista
    Lista aux2 = aux -> prox; //Aponta nó a ser removido
    aux -> prox = aux2 -> prox; //Retira nó da lista
    free (aux2); //Libera memória alocada
    (*lst) -> info--; //Decrementa qtde de nós na lista

    return 1;
}

//Intercala duas listas (lst1 e lst2) e forma o resultado lst3
int intercalar (Lista *lst1, Lista *lst2, Lista *lst3)
{
    //Se alguma das duas listas estiver vazia, retorna 0
    if (((*lst1) -> info == 0 || (*lst1) -> prox == NULL) || ((*lst2) -> info == 0 || (*lst2) -> prox == NULL))
        return 0;

    int tam1, tam2, var1, var2, cont1, cont2;
    tam1 = tamanho (lst1);
    cont1 = tam1 - 1;
    tam2 = tamanho (lst2);
    cont2 = tam2 - 1;

    for (int i = 0; i < tam1; i++) //Loop pega os valores da lista 1 e ja insere ordenado na intercalada
    {
        get_elem_pos(lst1, cont1, &var1);
        insere_ord(lst3, var1);
        cont1--;
    }

    for (int j = 0; j < tam2; j++) //Mesma coisa mas agr com a lista 2
    {
        get_elem_pos(lst2, cont2, &var2);
        insere_ord(lst3, var2);
        cont2--;
    }
  
    return 1;
}
