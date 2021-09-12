#define TIPO_DE_DADO float

struct no;

typedef struct no *Lista;

Lista cria_lista();
int lista_vazia(Lista lst);
int apaga_lista(Lista *lst);
int insere_elem(Lista *lst, TIPO_DE_DADO elem);
int get_elem_pos(Lista lst, int pos, TIPO_DE_DADO *retorno_implicito);
int remove_elem_pos(Lista *lista, int pos);
int remove_elem(Lista *lista, TIPO_DE_DADO dado);
int iguais(Lista lst1, Lista lst2);
Lista intercalar(Lista lst1, Lista ls2);
TIPO_DE_DADO remove_menor(Lista *lst, int *status);
