#include <stdio.h>
#include "Lista.h"

void imprime_Lista(Lista);

int main()
{
    int op,op1,FLAG = 0; // FLAG contabiliza a qtde de reinicializações da lista
    Lista L, L1, L2;

    do{
        do{
            //Obtem opção do usuário
            printf("===========================================\n");
            printf("[1]  Criar uma Lista\n");
            printf("[2]  Esvaziar a Lista\n");
            printf("[3]  Libera a Lista\n");
            printf("[4]  Inserir um elemento na Lista\n");
            printf("[5]  Remover um elemento na Lista\n");
            printf("[6]  Imprimir a Lista\n");
            printf("[7]  Remover todos os elementos negativos da Lista\n");
            printf("[8]  Remover todos os elementos pares da Lista\n");
            printf("[9]  Imprimir o tamanho da Lista\n");
            printf("[10] Intercala duas Listas\n");
            printf("[11] Sair do sistema\n");
            printf("\nDigite a opçao desejada: ");

            scanf("%d",&op);
            setbuf(stdin, NULL);
            if(op < 1 || op > 11 )
                printf("\n***Opçao digitada nao eh valida! ***\nAs opçoes disponiveis sao:\n");
        }while(op < 1 || op > 11 );

        if(op == 11)
            break;
        else if(op != 1 && FLAG == 0) {
            printf("\nAntes de qualquer operaçao, a lista precisa ser criada.\n\n");
            continue;
        }

        switch (op) {

        case 1:  {
            if(FLAG){ //Verifica se a lista ja existe
                libera_lista(&L);
                libera_lista(&L1);
                libera_lista(&L2);
                if(L != NULL) {
                    printf("\nJa existe uma instancia de lista e houve falha ao tentar libera-la.\n\n");
                    break;
                }
            }

             L = cria_lista();
             L1 = cria_lista();
             L2 = cria_lista();
             if(L == NULL) {
                printf("\nFalha na alocaçao...\n\n");
                return -1;
             }

             if(FLAG)
                printf("\nA lista foi reinicializada pela %d vez com sucesso!\n\n",FLAG);
             else
                printf("\nA lista foi criada com sucesso!\n\n");

            FLAG++;

            break;

        }
        case 2: {
            printf("\nQual lista voce quer esvaziar 1 ou 2: ");
            scanf("%d",&op1);

            if(op1 != 1 && op1 != 2){
                printf("\nOpcao invalida!\n\n");
                break;
            }

            if(op1 == 1)
                esvazia_lista(L);
            else
                esvazia_lista(L1);

            printf("\nA lista foi esvaziada com sucesso!\n\n");
            break;
        }
        case 3: {
            printf("\nQual lista voce quer liberar 1 ou 2: ");
            scanf("%d",&op1);

            if(op1 != 1 && op1 != 2){
                printf("\nOpcao invalida!\n\n");
                break;
            }

            if(op1 == 1)
                libera_lista(&L);
            else
                libera_lista(&L1);
            if (L == NULL) {
                printf("\nNao foi possivel liberar a lista.\n\n");
            }
            printf("\nA lista foi liberada com sucesso!\n\n");
            FLAG = 0;
            break;

        }
        case 4: {
            int N;
            printf("\nQual lista voce quer inserir um elemento 1 ou 2: ");
            scanf("%d",&op1);

            if(op1 != 1 && op1 != 2){
                printf("\nOpcao invalida!\n\n");
                break;
            }

            printf("\nDigite o elemento (nro inteiro)a ser inserido na lista: ");
            scanf("%d",&N);
            if(op1 == 1){
            if(insere_ord(L,N) == 0)
                printf("\nA lista ja esta cheia! Nao foi possivel incluir o elemento %d.\n\n",N);
            else
                printf("\nO elemento %d foi incluido com sucesso!\n\n", N);
            }
            else{
              if(insere_ord(L1,N) == 0)
                printf("\nA lista ja esta cheia! Nao foi possivel incluir o elemento %d.\n\n",N);
            else
                printf("\nO elemento %d foi incluido com sucesso!\n\n", N);
            }

            break;
        }
        case 5: {
            int N;
             printf("\nQual lista voce quer remover um elemento 1 ou 2: ");
            scanf("%d",&op1);

            if(op1 != 1 && op1 != 2){
                printf("\nOpcao invalida!\n\n");
                break;
            }

            printf("\nDigite o elemento a ser removido da lista: ");
            scanf("%d",&N);
            if(op1 == 1)
            if(remove_ord(L,N) == 0) {
                if(lista_vazia(L) == 1)
                    printf("\nA lista esta vazia!\n\n");
                else
                    printf("\nNao existe o elemento %d na lista;\n\n",N) ;
            }
            else
                printf("\nO elemento %d foi removido com sucesso!\n\n",N);
            else{
                 if(remove_ord(L1,N) == 0) {
                if(lista_vazia(L1) == 1)
                    printf("\nA lista esta vazia!\n\n");
                else
                    printf("\nNao existe o elemento %d na lista;\n\n",N) ;
            }
            else
                printf("\nO elemento %d foi removido com sucesso!\n\n",N);
            }

            break;
        }
        case 6: {
            imprime_Lista(L);
            imprime_Lista(L1);
            break;
        }
        case 7: {
            remove_negativos(L);
            remove_negativos(L1);
            break;

        }
        case 8: {
            remove_pares(L);
            remove_pares(L1);
            break;
        }
        case 9: {
            printf("A lista possui %d elementos\n",tamanho_lista(L));
            printf("A lista possui %d elementos\n",tamanho_lista(L1));
            break;
        }
        case 10: {
         intercala_lista(L,L1,&L2);
         imprime_Lista(L2);
         break;

        }
      }

    }while (op != 11);

    printf("\nAdeus\n");
    return 0;
}

void imprime_Lista(Lista L) {
    if(lista_vazia(L) == 1) {
        printf("\n***LISTA VAZIA***\n\n");
        return;
    }

    printf("\nLista: {");
    int i;
    for(i = 1; ;i++){
        int N;
        if(get_elem_pos(L,i,&N) == 0) {
            break;
        }
        printf(" %d ", N);
    }
    printf("}\n\nExistem %d elementos na lista.\n\n", i-1);
}



