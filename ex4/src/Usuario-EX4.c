#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include "AED-EX4.h"

int main ()
{
    Lista lista, lista2, lista_int, lista_rev;
    int opcao, opcao2, pos, pos2, pos3, pos4, pos5, var, var2, var3, ins, ins2, rem, tam, tam2, cont;

    while (1)
    {
        printf("\nSelecione uma opção:\n");
        printf("\n[1] Criar Lista");
        printf("\n[2] Imprimir Lista");
        printf("\n[3] Apagar Lista");
        printf("\n[4] Esvaziar Lista");
        printf("\n[5] Inserir um elemento na Lista");
        printf("\n[6] Remover um elemento da Lista");
        printf("\n[7] Remover o elemento da posição desejada");
        printf("\n[8] Tamanho da lista");
        printf("\n[9] Intercalar duas listas");
        printf("\n[10] Inverter a lista");
        printf("\n[11] Sair do programa");
        printf("\nDigite a opção desejada: ");

        scanf("%d", &opcao);

        switch (opcao)
        {
            case 1:

                lista = cria_lista ();
                printf ("\nLista criada com sucesso.\n");
                sleep (1);
                break;

            case 2:

                printf("\nLista: ");

                pos = 0;

                while(get_elem_pos (&lista, pos, &var))
                {
                    printf("%d ", var);
                    pos++;
                }

                printf("\n");
                sleep (1);
                break;

            case 3:

                apaga_lista (&lista);
                printf("\nLista apagada com sucesso.\n");
                sleep (1);
                break;

            case 4:
                
                esvazia_lista (&lista);
                printf("\nLista esvaziada com sucesso.\n");
                sleep (1);
                break;

            case 5:

                printf("\nDigite o elemento: ");
                scanf("%d", &ins);
                insere_ord(&lista, ins);
                printf("\nElemento inserido com sucesso.\n");
                sleep (1);
                break;
            
            case 6:
                
                printf("\nDigite o elemento: ");
                scanf("%d", &rem);
                remove_ord (&lista, rem);
                printf("\nElemento removido com sucesso.\n");
                sleep (1);
                break;

            case 7:

                printf("\nDigite a posição da qual remover o elemento: ");
                scanf("%d", &pos3);
                rem_elem_pos (&lista, pos3);
                printf("\nElemento removido com sucesso.\n");
                sleep (1);
                break;

            case 8:

                tam = tamanho(&lista);
                printf("\nTamanho: %d\n", tam);
                sleep (1);
                break;

            case 9:

                lista2 = cria_lista();
                lista_int = cria_lista();

                printf("\nQuantos elementos terá a lista com a qual quer intercalar?\n");
                scanf("%d", &opcao2);
                printf("\nAgora digite os elementos, um a um.\n");

                for (int i = 0; i < opcao2; i++)
                {
                    printf("\nDigite o elemento: ");
                    scanf("%d", &ins2);
                    insere_ord(&lista2, ins2);
                }

                intercalar(&lista, &lista2, &lista_int);
                printf("\nLista intercalada: ");

                pos5 = 0;
                while(get_elem_pos (&lista_int, pos5, &var3))
                {
                    printf("%d ", var3);
                    pos5++;
                }

                printf("\n");
                sleep (1);
                break;

            case 10:

                printf("\nLista Invertida: ");
                tam2 = tamanho (&lista);
                cont = tam2 - 1;

                for (int i = 0; i < tam2; i++)
                {
                    get_elem_pos(&lista, cont, &var2);
                    printf("%d ", var2);
                    cont--;
                }

                printf("\n");
                sleep (1);
                break;

            case 11:

                return 0;

            default:

                printf("\nOpção inválida, tente novamenta.\n");

                sleep (1);
                break;
        }
    }

    return 0;
}
