#ifndef LISTA_H_INCLUDED
#define LISTA_H_INCLUDED

#define MAX 20

typedef struct lista * Lista;

Lista cria_lista();
int lista_vazia(Lista);
int lista_cheia(Lista);
int insere_ord(Lista, int);
int remove_ord(Lista, int);
void libera_lista(Lista*);
int esvazia_lista(Lista);
int remove_negativos(Lista);
int remove_pares(Lista);
int tamanho_lista(Lista);
void intercala_lista(Lista, Lista, Lista*);
int get_elem_pos(Lista, int, int *);

#endif //LISTA_H_INCLUDED
