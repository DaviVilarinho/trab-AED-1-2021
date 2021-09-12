struct no 
{
    int info;
    struct no * prox;
};

typedef struct no * Lista;

Lista cria_lista();
int tamanho (Lista *);
int lista_vazia(Lista);
int apaga_lista (Lista *);
int esvazia_lista (Lista *);
int insere_ord(Lista *, int);
int remove_ord (Lista *, int);
int get_elem_pos (Lista *, int, int *);
int rem_elem_pos (Lista *, int);
int intercalar (Lista *, Lista *, Lista *);
int inverte(Lista *);
