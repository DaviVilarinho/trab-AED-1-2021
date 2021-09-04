#include "tad-lista-dinamica-ord.h"
#include <stdio.h>
#include <stdlib.h>

void printa_menu (void);
void printa_lista (Lista lista);

int main (void)
{
  Lista lista = cria_lista();
  int op;
  float f = 0.0; // para insercao
  int pos; // para remocao

  do
  {
    switch (op)
    {
    case 1:
      printa_lista(lista);
      break;
    case 2:
      if (apaga_lista(lista))
      {
        printf("\napagada com sucesso\n");
        break;
      }
      else
      {
        printf("\nfalha ao apagar\n");
        break;
      }
    case 3:
      printf("\nelemento: ");
      scanf("%f", f);
      if (insere_elem(lista, f))
      {
        printf("\ninserido com sucesso\n");
        break;
      }
      else
      {
        printf("\nfalha ao inserir\n");
        break;
      }
    case 4:
      if (remove_elem(lista))
      {
        printf("\nremovido com sucesso\n");
        break;
      }
      else
      {
        printf("\nfalha ao remover\n");
        break;
      }
    case 5:
      printf("\nposicao pra remover: ");
      scanf("%i", pos);
      if (remove_elem_pos(lista, pos))
      {
        printf("\nremovido com sucesso\n");
        break;
      }
      else
      {
        printf("\nfalha ao remover\n");
        break;
      }
    case 6:
      printf("\n[...] saindo\n");
      break;
    default:
      printf("\nopcao invalida\n");
      break;
    }
  } while (op != 6);
}

void printa_menu (void)
{
  printf("\n---------- MENU ----------\n");
  printf("(1) imprimir a lista\n");
  printf("(2) apagar a lista\n");
  printf("(3) inserir elemento\n");
  printf("(4) remover 1o elemento\n");
  printf("(5) remover elemento da posicao\n");
  printf("(6) sair do menu\n");
}

void printa_lista (Lista lista)
{
  int pos = 1;
  float printe_isso;

  printf("\n\n[ ");
  while (get_elem_pos(lista, pos, &printe_isso))
  {
    printf(" %i ", printe_isso);
    pos++;
  }
  printf("]\n");
}
