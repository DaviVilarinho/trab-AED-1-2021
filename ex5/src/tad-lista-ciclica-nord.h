struct no;
typedef struct no *Lista;

Lista cria_lista (void);
int lista_vazia (Lista lst);
int insere_final (Lista *lst, char elem);
int remove_ini (Lista *lst);
int apaga_lista (Lista *lst);
int get_elem_pos (Lista lst, int elem_procurado, char *sucesso);

int insere_inicio (Lista *, char);
int insere_pos (Lista *lst, int pos, char c);
