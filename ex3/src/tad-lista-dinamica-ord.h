struct no;
typedef struct no *Lista;

Lista cria_lista();
int lista_vazia(Lista lst);
int apaga_lista(Lista *lst);
int insere_elem(Lista *lst, float elem);
int remove_elem(Lista *lst);
int get_elem_pos(Lista lst, int pos, float *retorno_implicito);
int remove_elem_pos(Lista *lst, int pos);
