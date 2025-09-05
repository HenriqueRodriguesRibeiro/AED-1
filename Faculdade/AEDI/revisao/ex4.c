#include <stdio.h>
#define MAX_LINHA 10

typedef struct no *pme;
struct no{
    int col,val;
    pme prox;
}
typedef pme matriz[MAX_LINHA];

void inicializa(matriz m, int l){
    int i;
    for(i = 0; i <l; i++)
        m[i]= NULL;
}

void inserir(matriz m, int l, int c, int v){
    pme novo, p;
    novo = (pme)malloc(sizeof(struct no));
    novo->col = c;
    novo->val = v;
    novo->prox = NULL;
    if(m[l] == NULL) 
        m[l] = novo;
    else{
        p = m[l];
        while(p != NULL) p = p->prox;
        p->prox = novo;
      }
}

void libera(matriz m, int l){
    int i, j;
    pme p, q;
    for(i = 0; i < l; i++){
        for(p = m[i]; p != NULL;){
            q = p;
            p = p->prox;
            free(q);
        }
        m[i] = NULL;
    }
}

void imprimir(matriz m, int t){
    int i, j;
    pme p;
    for(i=0; i<t; i++){
        p= m[i];
        for(j=0; j<t; j++){
            if(p != NULL && p->col == j){
                printf("%d ", p->val);
                p = p->prox;
            } else 
                printf("0 ");
        }
        printf("\n");
    }
}

int condensaMatriz(matriz m, int condensada[][3]){
    int i, tam = 0;
    pme p;
    for(i = 0; i < MAX_LINHA; i++){
        p = m[i];
        while(p != NULL){
            condensada[tam][0] = i; // Linha
            condensada[tam][1] = p->col; // Coluna
            condensada[tam][2] = p->val; // Valor
            tam++;
            p = p->prox;
        }
    }
    return tam; // Retorna o tamanho da matriz condensada
}