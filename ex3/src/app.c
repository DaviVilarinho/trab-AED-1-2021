#include "tad-lista-dinamica-nord.h"
#include <stdio.h>
#include <stdlib.h>

void printa_menu (void);
void printa_lista (Lista lista);

int main (void)
{
  int lista_ativa = 0;
  Lista listas[2] = {cria_lista(), cria_lista()};
  int op = 0;
  int status = 1;
  TIPO_DE_DADO f = 0.0; // para insercao
  TIPO_DE_DADO menor;
  int pos; // para remocao

  do
  {
    printa_menu();
    printf("escolha: ");
    scanf("%i", &op);
    switch (op)
    {
    case 1:
      printa_lista(listas[lista_ativa]);
      break;
    case 2:
      if (apaga_lista(&listas[lista_ativa]))
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
      scanf("%f", &f);
      if (insere_elem(&listas[lista_ativa], f))
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
      menor = remove_menor(&listas[lista_ativa], &status);
      if (status)
      {
        printf("\nremovido menor (%f) com sucesso\n", menor);
        break;
      }
      else
      {
        printf("\nfalha ao remover menor\n");
        break;
      }
    case 5:
      printf("\nposicao pra remover: ");
      scanf("%i", &pos);
      if (remove_elem_pos(&listas[lista_ativa], pos))
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
      printf("\nelemento a remover: ");
      scanf("%f", &f);
      if (remove_elem(&listas[lista_ativa], f))
      {
        printf("\nremovido (%f) com sucesso\n", f);
        break;
      }
      else
      {
        printf("\nfalha ao remover\n");
        break;
      }

    case 7:
      if (iguais(listas[0], listas[1]))
        printf("\nSao iguais\n");
      else
        printf("\nNAO sao iguais\n");

      break;

    case 9:
      lista_ativa = (lista_ativa + 1) % 2;
      printf("\nTrocamos a referência\n");
      break;

    case 10:
      printf("\n[...] saindo\n");
      break;

    default:
      printf("\nopcao invalida\n");
      break;
    }
  } while (op != 10);
}

void printa_menu (void)
{
  printf("\n---------- MENU ----------\n");
  printf("(1) imprimir a lista\n");
  printf("(2) apagar a lista\n");
  printf("(3) inserir no ini\n");
  printf("(4) remover menor\n");
  printf("(5) remover elemento da posicao\n");
  printf("(6) remover elemento\n");
  printf("(7) Iguais\n");
  printf("(8) Intercalar\n");
  printf("(9) Trocar lista ativa para lista alternativa (usada em iguais e intercalar)\n");
  printf("(10) sair do menu\n");
}

void printa_lista (Lista lst)
{
  int pos = 1;
  float printe_isso;

  printf("\n[ ");
  while (get_elem_pos(lst, pos, &printe_isso))
  {
    printf(" %f ", printe_isso);
    pos++;
  }
  printf("]\n"); 
}
