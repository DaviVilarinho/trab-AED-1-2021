#ifndef HEADER_INCL
#define HEADER_INCL

struct no;
typedef struct no *Lista;

Lista cria_lista (void);
int lista_vazia (Lista lst);
int insere_elem (Lista *lst, char elem);
int remove_elem (Lista *lst, char elem);
int apaga_lista (Lista *lst);
char *get_elem_pos (Lista *lst, char elem_procurado, int *sucesso);

#endif
