// TAD - lista estática/sequencial não-ordenada de strings

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

// op trivial, aloca memoria para estrutura de lista
lista_p cria_lista() {
    lista_p nova_lista = (lista_p) malloc(sizeof(struct lista_estatica));

    if (nova_lista != NULL) {
        nova_lista->tamanho = 0;
    }

    return nova_lista;
}

// esvazia porem mantendo a memoria alocada
int esvazia_lista(lista_p lista) {
    lista->tamanho = 0;

    return 1;
}

// apaga a lista da memoria, desalocando-a
int apaga_lista(lista_p *lista) {
    esvazia_lista(*lista);
    free(*lista);
    *lista = NULL;

    return 1;
}

// checa se lista vazia
int lista_vazia(lista_p lista) {
    if (lista->tamanho == 0)
        return 1;
    else
        return 0;
}

// checa se lista cheia
int lista_cheia(lista_p lista) {
    if (lista->tamanho == MAX)
        return 1;
    else
        return 0;
}

// retorna o tamanho da lista
int tamanho(lista_p lista) {
    return lista->tamanho;
}

// insere o elemento
int insere_elem(lista_p lista, INFO_ARMAZENADA_ARGUMENTO inserir) {
    if (!lista_cheia(lista)) {
        strcpy(lista->vetor[tamanho(lista)], inserir);
        lista->tamanho = lista->tamanho + 1;
        return 1;
    } else {
        return 0;
    }
}

// encapsulada porque pode quebrar a estrutura
void shift_esquerda(lista_p lista, int pos) {
    int tam = tamanho(lista);
    if (pos > 0 && pos <= tam) {
        // assignar no atual o proximo ate o proximo ser o ultimo
        for (int i = pos-1; i < MAX-1; i++) {
            strcpy(lista->vetor[i], lista->vetor[i+1]);
        }
        lista->tamanho = lista->tamanho - 1;
    }
}

// remove o elemento passado como parametro
int remove_elem(lista_p lista, INFO_ARMAZENADA_ARGUMENTO remover) {
    if (!lista_vazia(lista)) {
        for (int i = 0; i < MAX; i++) {
            // encontrar string que seja igual a que quer remover
            if (strcmp(remover, lista->vetor[i]) == 0) {

                shift_esquerda(lista, i+1); // i+1 porque fiz em relacao a primeiro, segundo..., nao leitura de array
                return 1;
            }
        }
        return 0;
    } else {
        return 0;
    }
}

// retorna a string pedida
INFO_ARMAZENADA_ARGUMENTO get_elem_pos(lista_p lista, int pos, int *ok) {
    if (pos > tamanho(lista) || pos < 1) {
        // pegar posicoes invalidas nao pode
        *ok = 0;
        return NULL;

    } else {
        *ok = 1;
        return lista->vetor[pos-1];
    }
}

// remove todas strings
int remove_todas(lista_p lista, INFO_ARMAZENADA_ARGUMENTO remover) {
    if (!lista_vazia(lista)) {
        int i = 0;
        int removidos = 0;
        while (i < lista->tamanho) {
            if (strcmp(lista->vetor[i], remover) == 0) {
                shift_esquerda(lista, i+1);
                removidos++;
            } else {
                i++;
            }
        }

        return removidos;
    } else {
        return 0; 
    }
}

// remove a maior string da lista
int remove_maior(lista_p lista) {
    if (!lista_vazia(lista)) {
        int indice_maior = 0; 
        for (int i = 1; i < tamanho(lista); i++) {
            if (strlen(lista->vetor[i]) > strlen(lista->vetor[indice_maior])) 
                indice_maior = i;
        }

        shift_esquerda(lista, indice_maior+1);

        return 1;
    } else {
        return 0; // nao ha o que remover sem maior
    }
}

// concatena duas listas
int concat_listas(lista_p lista1, lista_p lista2) {
    int inseriu = 0;
    for (int i = 0; i < lista2->tamanho; i++) {
        if (insere_elem(lista1, lista2->vetor[i]))
            inseriu++;
    }

    if (inseriu == lista2->tamanho)
        return 1;
    else
        return 0;
}
