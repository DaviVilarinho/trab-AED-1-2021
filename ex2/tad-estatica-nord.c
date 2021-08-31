#include "tad-estatica-nord.h"
#ifndef STDLIB_INCLUIDA
#define STDLIB_INCLUIDA 1
#include <stdlib.h>
#endif
#ifndef STRING_INCLUIDA
#define STRING_INCLUIDA 1
#include <string.h>
#endif

struct lista_estatica {
    int tamanho;
    INFO_ARMAZENADA vetor[MAX][MAX_ARMAZENADO];
};

lista_p cria_lista() {
    lista_p nova_lista = (lista_p) malloc(sizeof(struct lista_estatica));

    if (nova_lista != NULL) {
        nova_lista->tamanho = 0;
    }

    return nova_lista;
}

int esvazia_lista(lista_p lista) {
    lista->tamanho = 0;

    return 1;
}

int apaga_lista(lista_p *lista) {
    free(*lista);
    *lista = NULL;

    return 1;
}

int lista_vazia(lista_p lista) {
    if (lista->tamanho == 0)
        return 1;
    else
        return 0;
}

int lista_cheia(lista_p lista) {
    if (lista->tamanho == MAX)
        return 1;
    else
        return 0;
}

int tamanho(lista_p lista) {
    return lista->tamanho;
}

int insere_elem(lista_p lista, INFO_ARMAZENADA_ARGUMENTO inserir) {
    if (!lista_cheia(lista)) {
        strcpy(lista->vetor[tamanho(lista)], inserir);
        (lista->tamanho)++;
        return 1;
    } else {
        return 0;
    }
}

// encapsulada porque pode quebrar a estrutura
void shift_esquerda(lista_p lista, int pos) {
    int tam = tamanho(lista);
    if (pos > 0 && pos <= tam) {
        for (int i = pos-1; i < MAX-1; i++) {
            strcpy(lista->vetor[i], lista->vetor[i+1]);
        }
        (lista->tamanho)--;
    }
}

int remove_elem(lista_p lista, INFO_ARMAZENADA_ARGUMENTO remover);
INFO_ARMAZENADA_ARGUMENTO get_elem_pos(lista_p, int pos, int *ok);
int remove_todas(lista_p lista, INFO_ARMAZENADA_ARGUMENTO remover);
int remove_maior(lista_p lista);

