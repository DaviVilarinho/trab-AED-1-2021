#include "tad-lista-ciclica-nord.h"
#include <stdlib.h>

struct no {
  char info;
  struct no *prox;
};

Lista cria_lista (void)
{
  return NULL;
}

int lista_vazia (Lista lst)
{
  return (lst == NULL);
}

// precisa do ponteiro pois modifica Head`s de outros locais
int insere_final (Lista *lst, char elem)
{
  // aloca e preenche
  Lista N = (Lista) malloc( sizeof(struct no) );
  if (N == NULL) { return 0; }
  N->info = elem;
  N->prox = *lst;

  // CASO lista esteja vazia
  if (lista_vazia(*lst))
  {
    *lst = N; // lista aponta pro novo no ( `novo final` )
    N->prox = *lst; // novo no aponta pra ele msm 
  }
  // CASO lista populada
  else
  {
    Lista aux = *lst; // aux aponta pra head
    while (aux->prox != *lst)
    {
      aux = aux->prox;
    }
    aux->prox = N;
  }
  return 1;
}

// novamente recebemos via * pois precisamos mudar end do Head
int remove_ini (Lista *lst) {
  // CASO lista vazia OU nula
  if (lista_vazia(*lst) || *lst == NULL)
  {
    return 0;
  }

  // CASO lista populada com 1 elemento
  if ( (*lst)->prox == (*lst) )
  {
    apaga_lista(lst);
    return 1;
  }
  // CASO contrario, lista populada

  // helpers de movimentacao
  Lista aux = *lst;
  Lista aux2 =  aux->prox;

  // trocando o no inicial
  aux->info = aux2->info;
  aux->prox = aux2->prox;

  // liberando o no solto pra evitar memory leak
  free(aux2);
  aux2 = NULL;

  return 1;
}

// dinamica nao tem diferenca entre apaga-esvazia
int apaga_lista (Lista *lst)
{
  // caso nao haja lista no end passado
  if (*lst == NULL)
    return 0;

  // CASO lista vazia OU apenas 1 elemento
  if ( (lista_vazia(*lst) == 1) || ( *lst == (*lst)->prox ) )
  {
    free(*lst);
    return 1;
  }
  // CASO lista com 1+ elems
  else
  {
    Lista aux = (*lst)->prox; // aux aponta pro primeiro no
    Lista aux2 = NULL; 
    while ( (*lst)->prox != *lst ) // vem limpando ate voltar pro inicial
    {
      aux2 = aux->prox; // aux2 aponta pro segundo no
      (*lst)->prox = aux2; // a lista `esquece` o primeiro no
      free(aux); // primeiro no eh liberado
      aux = aux2; // aux aponta pro `novo primeiro` no
    }
    free(*lst);
  }

  return 1;
}

// captura elem da pos passada (inverso doq o prof faz)
int get_elem_pos (Lista lst, int pos, char *c)
{
  if (lista_vazia(lst) || pos <= 0)
    return -1;

  int contador = 1;
  Lista aux = lst;

  while (aux->prox != lst && contador < pos)
  {
    aux = aux->prox;
    contador++;
  }

  if (contador != pos)
    return -1; // posicao nao existe na lista
  
  *c = aux->info; // retorno implicito do elem procurado
  return 1;
}

// TODO:  insere_pos, remove_fim, remove_vogais

int insere_inicio (Lista *lst, char elem)
{
  // aloca e preenche
  Lista N = (Lista) malloc( sizeof(struct no) );
  if (N == NULL) { return 0; }
  N->info = elem;

  // CASO lista esteja vazia
  if (lista_vazia(*lst))
  {
    *lst = N;
    N->prox = (*lst)->prox;
    return 1;
  }

  N->prox = (*lst)->prox;
  (*lst)->prox = N; // N eh o `novo tail` 

  return 1;
}

int insere_pos (Lista *lst, int pos, char elem)
{
  // aloca e preenche
  Lista N = (Lista) malloc( sizeof(struct no) );
  if (N == NULL) { return 0; }
  N->info = elem;

  if (lista_vazia(*lst) && pos != 1)
  {
    return 0; // vazia so pode na primeira posicao
  }
  
  Lista aux = *lst; // aux aponta pro primeiro no
  int contador = 1;

  while (contador != (pos-1) && aux->prox != *lst)
  {
    aux = aux->prox;
    contador++;
  }

  if (contador != pos) // voltamos pro inicio e nao eh a pos desejada
  {
    return 0;
  } 

  // passou do while e do if estamos na pos desejada
  N->prox = aux->prox;
  aux->prox = N;
  return 1;
}
