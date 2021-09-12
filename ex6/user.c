#include "tad-lista-dupla-enc-nord.h"
#include <stdio.h>

#ifndef STDLIB_INCLUIDA
#include <stdlib.h>
#define STDLIB_INCLUIDA 1
#endif

// funcoes intermediarias
void print(no_p lista);
void print_menu();
INFO_ARMAZENADA recebe_elemento();
INFO_ARMAZENADA receber_a_remover();
int receber_indice();

int main (void) {
    int escolha = 1;
    int indice;
    no_p lista = cria_lista();

    while (escolha) {
        print_menu();
        scanf("%i", &escolha);

        switch (escolha) {
            case 1:
                insere(&lista, recebe_elemento());
                break;

            case 2:
                if (remove_nord(&lista, receber_a_remover())) {
                    printf("\nRemovido com sucesso!\n\n");
                } else {
                    printf("\nNada Removido\n\n");
                }

                break;

            case 3:
                print(lista);
                break;

            case 4:
                esvazia_lista(&lista);
                break;

            case 5:
                if (remove_todos(&lista, receber_a_remover())) {
                    printf("\nTodos removidos com sucesso!\n\n");
                } else {
                    printf("\nNada Removido\n\n");
                }
                break;

            case 6:
                if (remove_maior(&lista)) {
                    printf("\nTodos maiores removidos com sucesso!\n\n");
                } else {
                    printf("\nNada Removido\n\n");
                }
                break;

            case 7:
                if (inverte(&lista)) {
                    printf("\nInvertemos a ordem!\n\n");
                } else {
                    printf("\nNada Ocorreu\n\n");
                }
                break;

            case 8:
                indice = receber_indice();
                insere_pos(&lista, indice, recebe_elemento());
                break;

            default:
                escolha = 0;
        }
    }

    return 0;
}

// imprime a lista
void print(no_p lista) {
    int ok = 1;
    int pos = 1;

    while (ok) {
        INFO_ARMAZENADA printar_agora = get_elem_pos(lista, pos, &ok);
        if (ok)
            printf("%lf ", printar_agora);
        pos++;
    }

    printf("\n");
}

// imprime o menu
void print_menu() {
    printf("\n= = = MENU = = =\n");
    printf("\t[1] Novo Double\n");
    printf("\t[2] Remove Double\n");
    printf("\t[3] Printa Lista\n");
    printf("\t[4] Esvaziar Lista\n");
    printf("\t[5] Remove Double todos\n");
    printf("\t[6] Remove maior(es)\n");
    printf("\t[7] Inverte Lista\n");
    printf("\t[8] Inserir na posicao\n");
    printf("\t[0] Sair\n");
    printf("ESCOLHA: ");
}

// intermediaria - elemento a ser inserido
INFO_ARMAZENADA recebe_elemento() {
    INFO_ARMAZENADA receber = 0;
    printf("Para inserir: ");
    scanf("%lf", &receber);

    return receber;
}

// intermediaria - elemento a ser removido
INFO_ARMAZENADA receber_a_remover() {
    INFO_ARMAZENADA a_remover = 0;
    printf("Para remover: ");
    scanf("%lf", &a_remover);

    return a_remover;
}

// intermediaria - indice a ser inserido
int receber_indice() {
    int a_remover = 0;
    printf("Indice para inserir: ");
    scanf("%i", &a_remover);

    return a_remover;
}
