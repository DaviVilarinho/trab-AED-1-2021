#include <stdlib.h>
#include "Lista.h"

struct lista {
    int no[MAX];
    int Fim;

};

Lista cria_lista() {

    Lista lst = (Lista) malloc (sizeof(struct lista));
    if(lst != NULL)
        lst->Fim = 0;
    return lst;
}

int lista_vazia(Lista lst) {
    if(lst == NULL) return -1;
    return (lst->Fim == 0);
}

int lista_cheia(Lista lst){
    if(lst == NULL) return -1;
    return(lst->Fim == MAX);
}

int insere_ord(Lista lst, int elem) {
     if(lst == NULL || lista_cheia(lst) == 1)
        return 0;

    if(lista_vazia(lst) == 1 || elem <= lst->no[lst->Fim-1]) {
        lst->no[lst->Fim] = elem;
    }
    else {
        int i;
        //Deslocamento a direita para abrir espaço para o novo elemento
        for(i = lst->Fim; (i > 0 && lst->no[i-1] < elem); i--)
            lst->no[i] = lst->no[i-1];

        lst->no[i] = elem; //Inclui o novo elemento na lista
    }
    lst->Fim++;  //Avança o Fim
    return 1;    //Sucesso
}

int remove_ord(Lista lst, int elem) {
    if(lst == NULL || lista_vazia(lst) == 1 || elem < lst->no[0] || elem > lst->no[lst->Fim-1])
        return 0;// FALHA

    int i, Aux = 0;

    //Percorrimento até achar o elem ou final da lista
    while(Aux < lst->Fim && lst->no[Aux] < elem)
        Aux++;

    if(Aux == lst->Fim || lst->no[Aux] > elem) //Final da lista(elem nao existe)
        return 0; //Falha

    //Deslocamento a esq do sucessor até o final da lista
    for(i = Aux+1;i < lst->Fim; i++)
        lst->no[i-1] = lst->no[i];

    lst->Fim--; //Decremento do tempo Fim
    return 1;  //Sucesso

}

void libera_lista(Lista *lst){
    free(*lst);
    *lst = NULL;
}

int esvazia_lista(Lista lst) {
    if(lst == NULL)
        return 0;

    lst->Fim = 0;
    return 1;
}

int remove_negativos(Lista lst) {
if(lst == NULL || lista_vazia(lst) == 1)
        return 0;// FALHA

    int i, FLAG, Aux = 0;

    FLAG = 0;

    //Percorrimento até achar o elem ou final da lista
    while(Aux < lst->Fim){

        if(lst->no[Aux] < 0){
            //Deslocamento a esq do sucessor até o final da lista
            for(i = Aux + 1; i < lst->Fim; i++)
                lst->no[i - 1] = lst->no[i];

            lst->Fim--; //Decremento do tempo Fim
            FLAG++;
        }else{
            Aux++;
        }
    }

    if(FLAG == 0)
        return 0; //Falha
    else
        return 1; //Sucesso

}
int remove_pares(Lista lst){
if(lst == NULL || lista_vazia(lst) == 1)
        return 0;// FALHA

    int i, FLAG, Aux = 0;

    FLAG = 0;

    //Percorrimento até achar o elem ou final da lista
    while(Aux < lst->Fim){

        if(lst->no[Aux]%2 == 0){
            //Deslocamento a esq do sucessor até o final da lista
            for(i = Aux + 1; i < lst->Fim; i++)
                lst->no[i - 1] = lst->no[i];

            lst->Fim--; //Decremento do tempo Fim
            FLAG++;
        }else{
            Aux++;
        }
    }

    if(FLAG == 0)
        return 0; //Falha
    else
        return 1; //Sucesso

}

int tamanho_lista(Lista lst){

return lst->Fim;

}

void intercala_lista(Lista lst, Lista lst1, Lista *lst2){

    if((lst == NULL || lista_vazia(lst) == 1) &&
       (lst1 == NULL || lista_vazia(lst1) == 1)){
        return; // FALHA
    }

    int Aux, pos, pos1;

    if(lista_vazia(lst) == 1 && lista_vazia(lst1) != 1){
        (*lst2) = lst1;
    }else if(lista_vazia(lst) != 1 && lista_vazia(lst1) == 1){
        (*lst2) = lst;
    }else{

        int tam;

        if((lst->Fim + lst1->Fim) > MAX)
            tam = MAX;
        else
            tam = (lst->Fim + lst1->Fim);

        Aux = 0; pos = 0; pos1 = 0;

        while(Aux < tam){

            if(pos < lst->Fim && pos1 < lst1->Fim){

                if(lst->no[pos] > lst1->no[pos1]){

                    insere_ord((*lst2), lst->no[pos]);
                    pos++;

                }else{

                    insere_ord((*lst2), lst1->no[pos1]);
                    pos1++;

                }

            }else if(pos == lst->Fim){

                insere_ord((*lst2), lst1->no[pos1]);
                pos1++;

            }else{

                insere_ord((*lst2), lst->no[pos]);
                pos++;

            }

            Aux++;

        }

    }

}

int get_elem_pos(Lista lst, int pos, int *elem) {
    if(lst == NULL || lista_vazia(lst)|| pos <= 0 || pos > lst->Fim)
        return 0;

    *elem = lst->no[pos-1];
    return 1;

}
