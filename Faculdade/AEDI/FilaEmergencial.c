#include <stdio.h>
#include <stdlib.h>
#include <string.h>
 
#define MAX 51
 
typedef struct no {
    int id;
    char mensagem[MAX];
    struct no* prox;
} TNo;
 
typedef struct {
    TNo* ini;
    TNo* fim;
} TFila;
 
void inicializa(TFila* f) {
    f->ini = NULL;
    f->fim = NULL;
}
 
void copiaMensagem(char* destino, char* origem) {
    int i;
    for (i = 0; i < MAX - 1 && origem[i] != '\0'; i++) {
        destino[i] = origem[i];
    }
    destino[i] = '\0';
}
 
void enqueue(TFila* f, int id, char* mensagem) {
    TNo* novo = (TNo*)malloc(sizeof(TNo));
    novo->id = id;
    copiaMensagem(novo->mensagem, mensagem);
    novo->prox = NULL;
 
    if (f->fim == NULL) {
        f->ini = f->fim = novo;
    } else {
        f->fim->prox = novo;
        f->fim = novo;
    }
}
 
void dequeue(TFila* f) {
    if (f->ini == NULL) {
        printf("Fila vazia!");
        exit(0);
    }
 
    TNo* temp = f->ini;
    f->ini = f->ini->prox;
    if (f->ini == NULL)
        f->fim = NULL;
 
    free(temp);
}
 
void imprime(TFila* f) {
    if (f->ini == NULL) {
        printf("\n");
        return;
    }
 
    TNo* atual = f->ini;
    while (atual != NULL) {
        printf("ID: %d - %s\n", atual->id, atual->mensagem);
        atual = atual->prox;
    }
}
 
void clear(TFila* f) {
    while (f->ini != NULL) {
        TNo* temp = f->ini;
        f->ini = f->ini->prox;
        free(temp);
    }
    f->fim = NULL;
}
 
int main() {
    int N;
    char linha[110];
 
    TFila fila;
    inicializa(&fila);
 
    do {
        scanf("%d", &N);
    } while (N < 1 || N > 100);
 
    fgets(linha, sizeof(linha), stdin);
 
    for (int i = 0; i < N; i++) {
        fgets(linha, sizeof(linha), stdin);
 
        if (strncmp(linha, "ENQUEUE", 7) == 0) {
            int id;
            char msg[MAX];
            sscanf(linha, "ENQUEUE %d %[^\n]", &id, msg);
            enqueue(&fila, id, msg);
        } else if (strncmp(linha, "DEQUEUE", 7) == 0) {
            dequeue(&fila);
        } else if (strncmp(linha, "PRINT", 5) == 0) {
            imprime(&fila);
        } else if (strncmp(linha, "CLEAR", 5) == 0) {
            clear(&fila);
        }
    }
 
    clear(&fila);
    return 0;
}