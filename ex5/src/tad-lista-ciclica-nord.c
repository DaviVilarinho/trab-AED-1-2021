#include "tad-lista-ciclica-nord.h"
#include <stdlib.h>

struct node {
  char info;
  struct node *next;
};

Lista cria_lista (void)
{
  return NULL;
}

int lista_vazia (Lista lst)
{
  return (lst == NULL);
}

// insercao no inicio
int insere_elem (Lista *lst, char elem)
{
  Lista Node = (Lista) malloc(sizeof(struct node));

  if (Node == NULL)
    return 0; // falha ao alocar

  // insercao mais imples, sempre no inicio
  Node->info = elem;
  Node->next = *lst;
  *lst = Node;

  return 1;
}

// remocao especifica
int remove_elem (Lista *lst, char elem)
{
  // lista_vazia testa a Head
  if (lista_vazia(*lst) == 1)
    return 0; // falha ao alocar

  Lista aux = *lst; // Ponteiro auxiliar para o primeiro nó

  // primeiro da lista eh o procurado
  if (aux->info == elem)
  {
    *lst = aux->next; // Head aponta pro segundo (prox) nó
    free(aux);
    return 1;
  }

  // percorrimento até achar o elem ou final de lista
  while (aux->next != NULL && aux->next->info != elem)
    aux = aux->next;

  if (aux->next == NULL)
    return 0; // acabou a lista, `elem` nao esta nela

  // para `elem` != primeiro nó
  Lista aux2 = aux->next; // Aponta nó a ser removido
  aux->next = aux2->next; // Retira nó da lista
  free(aux2); // Libera memória alocada
  
  return 1;
}

int apaga_lista (Lista *lst)
{
  if (lst == NULL)
    return 1; // sucesso pois lista nao existe ou ja apagada

  // caso mais simples, sem elems na lista
  if (lista_vazia(*lst) == 1)
  {
    free(lst);
    return 1; // sucesso
  }

  // caso contrario, libera cada no ate chegar ao fim da lista
  Lista aux = *lst; // apontando para Head
  while(aux->next != NULL)
  {
    aux->next = *lst;
    *lst = (*lst)->next;
    free(aux);
    aux->next = NULL; // prevenindo segfault
  }

  return 1; // sucesso
}

int esvazia_lista (Lista *lst)
{
  if (lista_vazia(*lst) == 1)
    return 1; // nada a ser feito

  // lista com 1 elemento
  if ((*lst)->next = NULL)
  {
    lst = NULL;
    return 1;
  }

  // lista populada
  while ((*lst)->next != NULL)
  {
    Lista aux = *lst;
    (*lst)->next = (*lst)->next->next;
    aux = NULL;
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
  while (aux->next != NULL && (aux->info != elem_procurado))
    aux->next = aux->next->next; // avancar enquanto nao achamos

  if (aux->next == NULL && (aux->info != elem_procurado))
  {
    *(sucesso) = 0;
    return sucesso; // falha, elem nao esta na lista
  }

  *(sucesso) = 1;
  return sucesso; // ao sair do loop e passar no if, temos sucesso
}


