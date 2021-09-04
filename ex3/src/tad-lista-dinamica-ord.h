struct no;
typedef struct no * Lista;

Lista cria_lista();
int lista_vazia(Lista lst);
int insere_elem_ord(Lista *lst, float elem);
int remove_elem_ord(Lista *lst, float elem);
int remove_elem_pos(Lista *lst, int position);
int get_elem_pos(Lista lst, int pos, float *retorno_implicito);
int get_maior(Lista lst, float *retorno_implicito);
int get_menor(Lista lst, float *retorno_implicito);
int inverte(Lista *lst);
int apaga_lista(Lista *lst);
