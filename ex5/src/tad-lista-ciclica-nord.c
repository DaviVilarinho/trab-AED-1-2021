// TAD - lista dinâmica/encadeada cíclica de chars

#include "tad-lista-ciclica-nord.h"
#include <stdlib.h>
#include <ctype.h> // para comparar vogal

struct no {
  char info;
  struct no *prox;
};

// op trivial
Lista cria_lista (void)
{
  return NULL;
}

// check de lista vazia
int lista_vazia (Lista lst)
{
  if (lst == NULL) return 1;
  else return 0;
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
    (*lst) = NULL;
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
    free(*lst); // erro! tinha que ter apontado pro null
  }

  return 1;
}

// captura elem da pos passada (inverso doq o prof faz)
int get_elem_pos (Lista lst, int pos, char *c)
{
  if (lista_vazia(lst) || pos < 1)
    return -1;

  Lista aux = lst;

  // CASO lista com 1 elemento
  if ( &(lst)->prox == &lst )
  {
    *c = lst->info;
    return 1;
  }

  while (pos > 1)
  {
    aux = aux->prox;
    if (aux == lst) return -1;

    pos--;
  }

  *c = aux->info; // retorno implicito do elem procurado
  return 1;
}

// insere no inicio da lista
int insere_inicio (Lista *lst, char elem)
{
  // aloca e preenche
  Lista N = (Lista) malloc( sizeof(struct no) );
  if (N == NULL) { return 0; }
  N->info = elem;

  // CASO lista esteja vazia, ele da em si mesmo
  if (lista_vazia(*lst))
  {
    *lst = N;
    N->prox = *lst;
    return 1;
  }

  N->prox = (*lst);
  Lista antiga_cabeca = *lst;
  (*lst)  = N; // N é a nova cabeca

  // encontra o ultimo e associe na nova cabeça
  Lista aux = N->prox;
  while (aux->prox != antiga_cabeca) { // a cabeca aponta pra antiga cabeca
    aux = aux->prox;
  }
  aux->prox = *lst; // associar o final ao novo inicio

  return 1;
}

// insere na posicao passada como argumento
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

  if (pos == 1) // inserir em 1 eh facil
  {
    insere_inicio(&(*lst), elem);
    return 1;
  }
  
  int contador = 2; // para inserirmos corretamente
  Lista aux = (*lst)->prox;
  Lista aux2 = *lst;

  if (aux == *lst && pos == 1) // lista com 1 elemento
  {
    insere_final( &(*lst), elem );
  }
  else if (aux == *lst && pos != 1)
  {
    return 0; // 1 elemento podemos apenas inserir na pos 1
  }

  while ( (contador < pos) && (aux != *lst) )
  {
    // avancamos
    aux = aux->prox;
    aux2 = aux2->prox;
    contador++;
  }

  if (contador != pos) // voltamos pro inicio e nao eh a pos desejada
  {
    return 0;
  } 

  // passou do while e do if estamos na posicao
  N->prox = aux;
  aux2->prox = N;
  return 1;
}

// remove do fim
int remove_fim(Lista *lst) 
{
  // CASO lista vazia OU nula
  if (lista_vazia(*lst) || *lst == NULL)
  {
    return 0;
  }

  // CASO lista com 1 elemento
  if ( (*lst)->prox == *lst )
  {
    remove_ini(&(*lst)); // sem diferencas
    return 1;
  }

  // CASO lista populada
  Lista aux = (*lst)->prox; // segundo elemento 
  Lista retardatario = (*lst); // elemento anterior

  // rodar o ciclo até que a gnt encontre o que aponta pra head
  while (aux->prox != *lst) 
  {
    aux = aux->prox;
    retardatario = retardatario->prox;
  }

  // desalocar e definir nova referencia do anterior a antiga head
  free(aux); aux = NULL;
  retardatario->prox = *lst; // retardatario fecha o ciclo

  return 1;
}

// encapsulada
int eh_vogal (char c)
{
  char ch = tolower(c);
  if ( ch == 'a' || ch == 'e' || ch == 'i' || ch == 'o' || ch == 'u' )
    return 1;
  else
    return 0;
}

// remove todas as vogais da lista atual
int remove_vogais (Lista *lst)
{
  if (lista_vazia(*lst))
  {
    return 0;
  }

  // CASO lista com 1 elemento
  if ( (*lst)->prox == *lst && eh_vogal((*lst)->info) )
  {
    remove_ini(lst);
    return 1;
  }

  // CASO primeira eh vogal

  // trailing vogais
  Lista aux =  (*lst)->prox;
  while (aux->prox != *lst)
  {
    if (eh_vogal(aux->info))
      aux = aux->prox;
    else
      break;
  }
  Lista anterior = aux;
  *lst = aux;
  aux = aux->prox;

  // vogais no meio
  while (aux->prox != *lst)
  {
    if (eh_vogal(aux->info))
    {
     aux = aux->prox;
     
     // checando vogais continuas
      while (aux != *lst)
      {
       // se aux vogal vamos pro proximo noh
       if (eh_vogal(aux->info))
         aux = aux->prox;
       // caso achemos uma consoante
       else
         break;
      }

      // CASO vogais no fim
      if (aux == *lst)
      {
        anterior->prox = *lst;
        break;
      }
      else
      {
        anterior->prox = aux;
      }
    }

    // preparar pra proxima iteracao
    anterior = anterior->prox;
    aux = aux->prox;
  }

  return 1;
}
