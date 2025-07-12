#include <stdio.h>
#include <stdlib.h>

typedef struct no *pme;
struct no {
    int col, val;
    struct no *prox;
};

typedef pme Matriz[100]; // vetor de listas encadeadas

void inicializa(Matriz m, int n) {
    int i;
    for (i = 0; i < n; i++) m[i] = NULL;
}

void insere(Matriz m, int linha, int coluna, int valor) {
    pme novo, p, ant;

    if (valor == 0) return;

    novo = (pme)malloc(sizeof(struct no));
    novo->col = coluna;
    novo->val = valor;
    novo->prox = NULL;

    p = m[linha];
    ant = NULL;

    while (p != NULL && p->col < coluna) {
        ant = p;
        p = p->prox;
    }

    if (p != NULL && p->col == coluna) {
        p->val += valor;
        if (p->val == 0) {
            if (ant == NULL) m[linha] = p->prox;
            else ant->prox = p->prox;
            free(p);
        }
        free(novo); // descartamos o novo nó, pois apenas somamos
    } else {
        novo->prox = p;
        if (ant == NULL) m[linha] = novo;
        else ant->prox = novo;
    }
}

void imprime(Matriz m, int linha, int coluna) {
    int i, j;
    pme p;
    for (i = 0; i < linha; i++) {
        p = m[i];
        for (j = 0; j < coluna; j++) {
            if (p != NULL && p->col == j) {
                printf("%d ", p->val);
                p = p->prox;
            } else {
                printf("0 ");
            }
        }
        printf("\n");
    }
}

void libera(Matriz m, int linha) {
    int i;
    pme p, temp;
    for (i = 0; i < linha; i++) {
        p = m[i];
        while (p != NULL) {
            temp = p;
            p = p->prox;
            free(temp);
        }
    }
}

void soma(Matriz A, Matriz B, Matriz C, int n) {
    int i;
    pme pA, pB;

    for (i = 0; i < n; i++) {
        pA = A[i];
        pB = B[i];

        while (pA != NULL || pB != NULL) {
            if (pA != NULL && pB != NULL) {
                if (pA->col == pB->col) {
                    if (pA->val + pB->val != 0) {
                        insere(C, i, pA->col, pA->val + pB->val);
                    }
                    pA = pA->prox;
                    pB = pB->prox;
                } else if (pA->col < pB->col) {
                    insere(C, i, pA->col, pA->val);
                    pA = pA->prox;
                } else {
                    insere(C, i, pB->col, pB->val);
                    pB = pB->prox;
                }
            } else if (pA != NULL) {
                insere(C, i, pA->col, pA->val);
                pA = pA->prox;
            } else if (pB != NULL) {
                insere(C, i, pB->col, pB->val);
                pB = pB->prox;
            }
        }
    }
}

void subtrai(Matriz A, Matriz B, Matriz C, int n) {
    int i;
    pme pA, pB;

    for (i = 0; i < n; i++) {
        pA = A[i];
        pB = B[i];

        while (pA != NULL || pB != NULL) {
            if (pA != NULL && pB != NULL) {
                if (pA->col == pB->col) {
                    if (pA->val - pB->val != 0) {
                        insere(C, i, pA->col, pA->val - pB->val);
                    }
                    pA = pA->prox;
                    pB = pB->prox;
                } else if (pA->col < pB->col) {
                    insere(C, i, pA->col, pA->val);
                    pA = pA->prox;
                } else {
                    insere(C, i, pB->col, -pB->val);
                    pB = pB->prox;
                }
            } else if (pA != NULL) {
                insere(C, i, pA->col, pA->val);
                pA = pA->prox;
            } else if (pB != NULL) {
                insere(C, i, pB->col, -pB->val);
                pB = pB->prox;
            }
        }
    }
}

void multiplica(Matriz A, Matriz B, Matriz C, int n) {
    int i, j, produto;
    pme pA, pB;

    for (i = 0; i < n; i++) {
        for (pA = A[i]; pA != NULL; pA = pA->prox) {
            for (pB = B[pA->col]; pB != NULL; pB = pB->prox) {
                j = pB->col;
                produto = pA->val * pB->val;
                if (produto != 0) {
                    insere(C, i, j, produto);
                }
            }
        }
    }
}

int main() {
    Matriz A, B, C;
    int op, N, i, j, valor;

    scanf("%d", &op);
    scanf("%d", &N);

    inicializa(A, N);
    inicializa(B, N);
    inicializa(C, N);

    for (i = 0; i < N; i++) {
        for (j = 0; j < N; j++) {
            scanf("%d", &valor);
            if (valor != 0) insere(A, i, j, valor);
        }
    }

    for (i = 0; i < N; i++) {
        for (j = 0; j < N; j++) {
            scanf("%d", &valor);
            if (valor != 0) insere(B, i, j, valor);
        }
    }

    if (op == 1) soma(A, B, C, N);
    else if (op == 2) subtrai(A, B, C, N);
    else if (op == 3) multiplica(A, B, C, N);

    imprime(C, N, N);

    libera(A, N);
    libera(B, N);
    libera(C, N);

    return 0;
}
