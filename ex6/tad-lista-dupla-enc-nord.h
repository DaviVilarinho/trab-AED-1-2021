#ifndef INFO_ARMAZENADA 
#define INFO_ARMAZENADA double
#endif
#ifndef ELEMENTO_NAO_ENCONTRADO
#define ELEMENTO_NAO_ENCONTRADO -1
#endif

struct no;
typedef struct no* no_p;

no_p cria_lista();
int remove_nord(no_p *lista, INFO_ARMAZENADA remove);
int insere(no_p *lista, INFO_ARMAZENADA inserir);
int lista_vazia(no_p lista);
int esvazia_lista(no_p *lista);
int apaga_lista(no_p *lista);
INFO_ARMAZENADA get_elem_pos(no_p lista, int pos, int *flag);
int remove_todos(no_p *lista, INFO_ARMAZENADA remover_ocorrencias);
int remove_maior(no_p *lista);
int inverte(no_p *lista);
int insere_pos(no_p *lista, int pos, INFO_ARMAZENADA inserir);

