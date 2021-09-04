struct no;
typedef struct no *Lista;

Lista cria_lista();
int lista_vazia(Lista lst);
int apaga_lista(Lista *lst);
int insere_elem(Lista *lst, float elem);
int remove_elem(Lista *lst);
int remove_elem_pos(Lista *lst, int pos);
float get_elem_pos(Lista lst, int pos, float *retorno_implicito);
int get_menor(Lista lst, float *retorno_implicito);
