// TAD - lista estática/sequencial ordenada (decrescente) de ints

#include <stdlib.h>
#include "Lista.h"

struct lista {
    int no[MAX];
    int Fim; // "aponta" pro primeiro livre
};

// operacao mais basica - apenas aloca a estrutura Lista
Lista cria_lista() {
    Lista lst = (Lista) malloc (sizeof(struct lista));
    if(lst != NULL)
        lst->Fim = 0;
    return lst;
}

// checa se a lista eh vazia
int lista_vazia(Lista lst) {
    if(lst == NULL) return -1;
    return (lst->Fim == 0);
}

// checa se atingimos o maximo de nos
int lista_cheia(Lista lst){
    if(lst == NULL) return -1;
    return(lst->Fim == MAX);
}

// insere na posicao correta, obedecendo uma ordem decrescente
int insere_ord(Lista lst, int elem) {
    if(lst == NULL || lista_cheia(lst) == 1)
        return 0;

    if(lista_vazia(lst) == 1 || elem <= lst->no[lst->Fim-1]) { // vazia ou insercao no ultimo (sem deslocamento)
        lst->no[lst->Fim] = elem;
    }
    else { // insercao no meio
        int i;
        // deslocamento a direita (for-loop decresce) para abrir espaco para o novo elemento
        for(i = lst->Fim; (i > 0 && lst->no[i-1] < elem); i--)
            lst->no[i] = lst->no[i-1];

        lst->no[i] = elem; // inclui o novo elemento na lista
    }
    lst->Fim++;  // avanca o Fim
    return 1;    // sucesso
}

// insere no fim da lista
int insere_fim(Lista lst, int elem) {
     if(lst == NULL || lista_cheia(lst) == 1)
        return 0;

    // vazia (insercao simples) ou ultimo (sem deslocamento)
    if(lista_vazia(lst) == 1 || elem <= lst->no[lst->Fim-1]) {
        lst->no[lst->Fim] = elem;
    }
    else {
        lst->no[lst->Fim] = elem;
    }

    lst->Fim++;  // avanca o Fim para ambos casos
    return 1;    // SUCESSO
}

// remove o elemento passado como argumento da lista
int remove_ord(Lista lst, int elem) {
    if(lst == NULL || lista_vazia(lst) == 1 || elem > lst->no[0] || elem < lst->no[lst->Fim-1]) // sem lista, vazia, maior que 1o ou menor que ultimo
        return 0; // FALHA

    int i, Aux = 0;

    // percorrimento ate achar o elemento
    while(Aux < lst->Fim && lst->no[Aux] > elem)
        Aux++;

    if(Aux == lst->Fim || lst->no[Aux] < elem) // final da lista (elem nao existe)
        return 0; // FALHA

    // deslocamento a esquerda do sucessor ate o final da lista
    for(i = Aux+1;i < lst->Fim; i++)
        lst->no[i-1] = lst->no[i]; // for-loop crescente, desloca esqerda

    lst->Fim--; // decremento do Fim
    return 1;  // sucesso

}

// desaloca a memoria alocada para a estrutura da lista
void libera_lista(Lista *lst){
    free(*lst);
    *lst = NULL;
}

// esvazia a lista, porem mantem a memoria alocada
int esvazia_lista(Lista lst) {
    if(lst == NULL)
        return 0;

    lst->Fim = 0;
    return 1;
}

// remove os numeros negativos presentes na lista
int remove_negativos(Lista lst) {
    if(lst == NULL || lista_vazia(lst) == 1)
        return 0;// FALHA

    int i, FLAG, Aux = 0;

    FLAG = 0;

    // percorrimento ate achar o elem ou final da lista
    while(Aux < lst->Fim){

        if(lst->no[Aux] < 0){
            // deslocamento a esq do sucessor ate o final da lista
            for(i = Aux + 1; i < lst->Fim; i++)
                lst->no[i - 1] = lst->no[i];

            lst->Fim--; // decremento do tempo Fim
            FLAG++;
        }else{
            Aux++;
        }
    }

    if(FLAG == 0)
        return 0; // FALHA - sem nros negativos na lista
    else
        return 1; // SUCESSO

}

// remove os elementos pares presentes na lista
int remove_pares(Lista lst){
if(lst == NULL || lista_vazia(lst) == 1)
        return 0; // FALHA

    int i, FLAG, Aux = 0;

    FLAG = 0;

    // percorrimento ate achar o elem ou final da lista
    while(Aux < lst->Fim){

        if(lst->no[Aux]%2 == 0){
            // deslocamento a esq do sucessor ate o final da lista
            for(i = Aux + 1; i < lst->Fim; i++)
                lst->no[i - 1] = lst->no[i];
            lst->Fim--; // decremento do tempo Fim
            FLAG++;
        }else{
            Aux++;
        }
    }

    if(FLAG == 0)
        return 0; // FALHA
    else
        return 1; // SUCESSO

}

// retorna o tamanho da lista
int tamanho_lista(Lista lst){
    return lst->Fim;
}

// intercala duas listas, mantendo a ordenacao decrescente
void intercala_listaORD(Lista lst, Lista lst1, Lista *lst2){
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
        esvazia_lista(*lst2);

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

// intercala duas listas sem respeitar a ordenacao
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
        esvazia_lista(*lst2);

        while(Aux < tam){

            if(pos < lst->Fim && pos1 < lst1->Fim){

                insere_fim((*lst2), lst->no[pos]);
                pos++;

                insere_fim((*lst2), lst1->no[pos1]);
                pos1++;

                Aux += 2;

            }else if(pos == lst->Fim){

                insere_fim((*lst2), lst1->no[pos1]);
                pos1++;
                Aux++;

            }else if(pos1 == lst1->Fim){

                insere_fim((*lst2), lst->no[pos]);
                pos++;
                Aux++;

            }
        }
    }
}

// retorna implicitamente o elemento da posicao passada como parametro
int get_elem_pos(Lista lst, int pos, int *elem) {
    if(lst == NULL || lista_vazia(lst)|| pos <= 0 || pos > lst->Fim) // sem lista, vazia ou posicao invalida
        return 0; // FALHA

    *elem = lst->no[pos-1]; // subtraido de um pq vetor inicia em 0
    return 1;
}
