

#include <stdio.h>
#include "tad-lista-ciclica-nord.h"

void imprime_menu (void);
char elem_inserir (void);
int posicao_entrar (char *);
void imprime_lista (Lista);

int main (void)
{
  fprintf(stdout,"\nclient para Lista_NaoOrdenada_Caracteres_Ciclica\n");

  // operacao para o switch
  unsigned short int op = 0;
  // caso usuario deseje colocar item
  char c;
  // caso queira colocar item em det posicao
  int i;
  Lista lista; 

  do
  {
    imprime_menu();
    scanf("%hu", &op);
    
    switch (op)
    {
      case 0:
        lista = cria_lista();
        break;

      case 1:
        imprime_lista(lista);
        break;

      case 2:
        c = elem_inserir();
        if ( insere_final(&lista, c) )
        {
          fprintf(stdout, "inserido com sucesso\n");
          break;
        }
        else
        {
          fprintf(stdout, "erro ao inserir\n");
          break;
        }

      case 3:
        if ( remove_ini(&lista) )
        {
          fprintf(stdout, "removido com sucesso\n");
          break;
        }
        else
        {
          fprintf(stdout, "falha ao remover");
          break;
        }

      case 4:
        if (apaga_lista(&lista))
          fprintf(stdout, "\napagada com sucesso\ncrie outra lista\n");
        else
          fprintf(stdout, "falha ao apagar\n");
        break;

      case 5:
        c = elem_inserir();
        if ( insere_inicio(&lista, c))
        {
          fprintf(stdout, "inserido com sucesso\n");
          break;
        }
        else
        {
          fprintf(stdout, "falha ao inserir\n");
          break;
        }

      case 6:
        i = posicao_entrar(&c);
        if (insere_pos(&lista,i,c))
        {
          fprintf(stdout, "inserido com sucesso\n");
          break;
        }
        else
        {
          fprintf(stdout, "falha ao inserir\n");
          break;
        }

      case 7:

        break;

      case 8:

        break;

      case 9:
        printf("\n[...] saindo\n");
        break;

      default:
        printf("\nopcao invalida\n");
        break;
    }

  } while (op != 9);
}

void imprime_menu (void)
{
  fprintf(stdout, "\n---------- MENU ----------\n");
  fprintf(stdout, "(0) criar a lista\n");
  fprintf(stdout, "(1) imprimir a lista\n");
  fprintf(stdout, "(2) inserir no final\n");
  fprintf(stdout, "(3) remover do inicio\n");
  fprintf(stdout, "(4) apagar lista\n");
  fprintf(stdout, "(5) inserir no inicio\n");
  fprintf(stdout, "(6) inserir na posicao\n");
  fprintf(stdout, "(7) remover do fim\n");
  fprintf(stdout, "(8) remover as vogais\n");
  fprintf(stdout, "(9) sair do menu\n");
  fprintf(stdout, "sua escolha: ");
}

char elem_inserir (void)
{
  char c_inserir;
  fprintf(stdout, "inserir: ");
  scanf(" %c", &c_inserir);
  return c_inserir;
}

int posicao_entrar (char *c)
{
  int pos_entrar;
  char char_entrar;
  fprintf(stdout, "posicao: ");
  scanf("%d", &pos_entrar);
  fprintf(stdout, "\ncaractere: ");
  scanf(" %c", &char_entrar);
  *c = char_entrar;
  return pos_entrar;
}

void imprime_lista (Lista lst)
{
  if (lista_vazia(lst))
  {
    fprintf(stdout, "\nlista vazia, nada para imprimir\n");
    return;
  }

  int i;
  fprintf(stdout, "\n[ ");
  for(i = 1; ; i++)
  {
    char c;
    if (get_elem_pos(lst, i, &c) == -1)
      break;
    fprintf(stdout, "%c ", c);
  }
  fprintf(stdout, "]\n");
  fprintf(stdout,"\nexiste, %d elems na lista no momento\n", i-1);
}
