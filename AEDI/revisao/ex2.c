#include <stdio.h>
#include <stdlib.h>
#define MAX_LINHA 100

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

int somar(matriz m1, matriz m2, int t){
    int i, val, col, soma;
    pme p, q, r, novo;
    matriz m3;
    for( i = 0; i<t; i++){
        m3[i] = NULL;
        p = m1[i], q = m2[i];
        while(p != NULL || q != NULL){
            if(p == NULL ||(q != NULL && q->col < p->col)){
                val = q->val;
                col = q->col;   
                q = q->prox;
            }else
            if(q == NULL || (p != NULL && p->col < q->col)){
                val = p->val;
                col = p->col;
                p = p->prox;
            }else{
                val= p->val + q->val;
                p = p->prox;
                q = q->prox;
            }
            if(val != 0){
                novo= (pme)malloc(sizeof(struct no));
                novo->val = val;
                novo->col = col;
                if(m3[i] == NULL){
                    m3[i] = novo;
                    r = novo;
                }
                else{
                    r->prox = novo;
                    r = novo;
                }
            }
        }    
    }
    imprimir(m3, t);
    libera(m3, t);
}

int identidade(matriz m, int t) {
    int i, j;
    pme p;

    for (i = 0; i < t; i++) {
        p = m[i]; // Ponteiro para o primeiro nó da linha i

        for (j = 0; j < t; j++) {
            if (i == j) { // Diagonal principal
                if (p == NULL || p->col != j || p->val != 1) {
                    return 0; // Falha: não tem 1 na diagonal
                }
                p = p->prox; // Avança para o próximo nó da linha
            } else { // Fora da diagonal
                // Percorre a lista até encontrar a coluna j ou terminar
                while (p != NULL && p->col < j) {
                    p = p->prox;
                }
                // Se encontrou um nó na coluna j, deve ser zero (mas como é esparsa, não pode existir!)
                if (p != NULL && p->col == j) {
                    return 0; // Falha: elemento não-zero fora da diagonal
                }
            }
        }
    }
    return 1; // Passou em todas as verificações
}

void vetorMatriz(matriz m, int nl, int nc, int vet_esp[][2], int nev, int result[]){
    int i, j, col, val, iVet, vv;
    pme p;
    
    for(i = 0; i < nl; i++){
        result[i] = 0; // Inicializa o vetor de resultados
    }

    for(i= 0; i < nl; i++){
        p = m[i];
        while(p != NULL){
            col = p->col;
            val = p->val;
            vv = 0; // Inicializa o valor do vetor de resultados para a linha i

            for(j = 0; j < nev && vet_esp[j][0] <= col; j++){
                if(vet_esp[j][0] == col){
                    vv = vet_esp[j][1];
                }
            }

            result[i] += val * vv; // Acumula o produto 
            p = p->prox; // Avança para o próximo nó
        }
    }
}

void multiplicaMatrizes(matriz A, matriz B, int n) {
    matriz C;
    inicializa(C, n);
    for (int i = 0; i < n; i++) {
        pme elem_A = A[i];
        while (elem_A) {
            int k = elem_A->col;
            int val_A = elem_A->val;
            pme elem_B = B[k];
            while (elem_B) {
                int j = elem_B->col;
                int val_B = elem_B->val;
                // Busca se C[i][j] já existe
                pme elem_C = C[i], ant = NULL;
                while (elem_C && elem_C->col < j) {
                    ant = elem_C;
                    elem_C = elem_C->prox;
                }
                if (elem_C && elem_C->col == j) {
                    elem_C->val += val_A * val_B;
                } else {
                    pme novo = (pme)malloc(sizeof(struct no));
                    novo->col = j;
                    novo->val = val_A * val_B;
                    novo->prox = elem_C;
                    if (!ant) C[i] = novo;
                    else ant->prox = novo;
                }
                elem_B = elem_B->prox;
            }
            elem_A = elem_A->prox;
        }
    }
    imprimir(C, n);
    libera(C, n);
}

