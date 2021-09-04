#include "tad-lista-dinamica-ord.h"
#include <stdio.h>
#include <stdlib.h>

void printa_lista(Lista lista);

int main (void) {
    Lista lista = cria_lista();

}

void printa_lista(Lista lista) {
    int pos = 1;
    float printe_isso;

    printf("\n\nLista [");
    while (get_elem_pos(lista, pos, &printe_isso))  {
        printf(" %i ", printe_isso);
        pos++;
    }
    printf("]\n");
}
