#ifndef INFO_ARMAZENADA 
#define MAX_ARMAZENADO 15
#define INFO_ARMAZENADA char
#define INFO_ARMAZENADA_ARGUMENTO char*
#endif
#define MAX 10

struct lista_estatica;

typedef struct lista_estatica * lista_p;

lista_p cria_lista();
int esvazia_lista(lista_p lista); 
int apaga_lista(lista_p *lista);
int lista_vazia(lista_p lista);
int lista_cheia(lista_p lista);
int tamanho(lista_p lista);
int insere_elem(lista_p lista, INFO_ARMAZENADA_ARGUMENTO inserir);
int remove_elem(lista_p lista, INFO_ARMAZENADA_ARGUMENTO remover);
INFO_ARMAZENADA_ARGUMENTO get_elem_pos(lista_p, int pos, int *ok);
int remove_todas(lista_p lista, INFO_ARMAZENADA_ARGUMENTO remover);
int remove_maior(lista_p lista);
