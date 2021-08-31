#include "tad-estatica-nord.h"
#include <stdio.h>

#ifndef STRING_INCLUIDA 
#include <string.h>
#define STRING_INCLUIDA 1
#endif

#ifndef STDLIB_INCLUIDA
#include <stdlib.h>
#define STDLIB_INCLUIDA 1
#endif

void print(lista_p lista) {
    int ok = 1;
    printf("\nStrings:\n");

    for (int i = 1; i <= tamanho(lista); i++) {

        char *string = get_elem_pos(lista, i, &ok);
        if (ok)
            printf("%s", string);
    }

    printf("\n\n");
}

void print_menu(int indice) {
    printf("\n= = = = =MENU = = = = =\n");
    printf("\n= Estamos na lista %i =\n", indice);
    printf("\t[1] Nova String\n");
    printf("\t[2] Remove String\n");
    printf("\t[3] Printa Lista\n");
    printf("\t[4] Esvaziar Lista\n");
    printf("\t[5] Apagar Lista\n");
    printf("\t[6] Remove String todas\n");
    printf("\t[7] Remove Maior\n");
    printf("\t[8] Concatenar a outra lista nessa\n");
    printf("\t[9] Alternar a outra lista\n");
    printf("\t[0] Sair\n");
    printf("ESCOLHA: ");
}

INFO_ARMAZENADA_ARGUMENTO recebe_elemento() {
    INFO_ARMAZENADA_ARGUMENTO receber = (INFO_ARMAZENADA_ARGUMENTO) malloc(MAX_ARMAZENADO * sizeof(INFO_ARMAZENADA));

    printf("Para inserir: ");
    fgets(receber, sizeof(receber), stdin);
    setbuf(stdin, NULL);

    return receber;
}

INFO_ARMAZENADA_ARGUMENTO receber_a_remover() {
    INFO_ARMAZENADA_ARGUMENTO a_remover = (INFO_ARMAZENADA_ARGUMENTO) malloc(MAX_ARMAZENADO * sizeof(INFO_ARMAZENADA));
    printf("Para remover: ");
    fgets(a_remover , sizeof(a_remover), stdin);
    setbuf(stdin, NULL);

    return a_remover;
}

int main (void) {
    int escolha = 1;
    int indice_lista_ativa = 0;

    lista_p listas[2] = {cria_lista(), cria_lista()};

    lista_p *lista_ativa = &listas[indice_lista_ativa]; // endereco para lista ativa, captar o primeiro

    while (escolha) {
        print_menu(indice_lista_ativa);
        scanf("%i", &escolha);
        setbuf(stdin, NULL);

        switch (escolha) {
            case 1:
                if (insere_elem(*lista_ativa, recebe_elemento()))
                    printf("Inserido com sucesso");
                else
                    printf("Removido com sucesso");
                break;

            case 2:
                if (remove_elem(*lista_ativa, receber_a_remover())) {
                    printf("\nRemovido com sucesso!\n\n");
                } else {
                    printf("\nNada Removido\n\n");
                }

                break;

            case 3:
                print(*lista_ativa);
                break;

            case 4:
                if (esvazia_lista(*lista_ativa))
                    printf("Esvaziada com sucesso");
                else
                    printf("Não esvaziada...");
                break;

            case 5:
                if (apaga_lista(lista_ativa)) 
                    printf("\nApagada com Sucesso\n");
                else 
                    printf("\nNao foi possivel apagar\n");
                        
                break;

            case 6:
                if (remove_todas(*lista_ativa, receber_a_remover())) {
                    printf("\nTodos maiores removidos com sucesso!\n\n");
                } else {
                    printf("\nNada Removido\n\n");
                }
                break;

            case 7:
                if (remove_maior(*lista_ativa)) {
                    printf("\nMaior removido com sucesso!\n\n");
                } else {
                    printf("\nNada Removido\n\n");
                }
                break;

            case 8:
                if (concat_listas(*lista_ativa, listas[(indice_lista_ativa+1)%2]))
                    printf("\nConcatenadas com sucesso\n");
                else
                    printf("\nNao foi possivel concatenar TUDO\n");
                break;

            case 9:
                printf("Alternada a lista\n");
                indice_lista_ativa = (indice_lista_ativa + 1) % 2;
                lista_ativa = &listas[indice_lista_ativa];
                break;


            default:
                escolha = 0;
        }
    }

    return 0;
}
