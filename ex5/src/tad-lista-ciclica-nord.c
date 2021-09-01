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
int remove_ini (Lista *lst)
{
  // CASO lista vazia
  if (lista_vazia(*lst))
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

// TODO : modificar os retornos
char *get_elem_pos (Lista *lst, char elem_procurado, int *sucesso)
{
  // caso + simples encontramos de imediato
  if ((*lst)->info == elem_procurado)
  {
    *(sucesso) = 1; // sucesso
    return sucesso;
  }

  // resto dos casos percorremos toda a lista
  Lista aux = *lst;
  while (aux->prox != NULL && (aux->info != elem_procurado))
    aux->prox = aux->prox->prox; // avancar enquanto nao achamos

  if (aux->prox == NULL && (aux->info != elem_procurado))
  {
    *(sucesso) = 0;
    return sucesso; // falha, elem nao esta na lista
  }

  *(sucesso) = 1;
  return sucesso; // ao sair do loop e passar no if, temos sucesso
}

// TODO: insere_inicio, insere_pos, remove_fim, remove_vogais
