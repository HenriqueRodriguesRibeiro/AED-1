/* 
    NOME: Henrique Rodrigues Ribeiro
    RA: 176515
    
   
*/

#include <stdio.h>
#include <stdlib.h>

typedef struct {
    int *data;
    int size;
    int cap;
} Vec;

void vec_init(Vec *v) {
    v->data = NULL;
    v->size = 0;
    v->cap = 0;
}

void vec_push(Vec *v, int x) {
    if (v->size == v->cap) {
        int newcap;
        if (v->cap == 0)
            newcap = 4;
        else
            newcap = v->cap * 2;

        v->data = realloc(v->data, newcap * sizeof(int));
        v->cap = newcap;
    }
    v->data[v->size++] = x;
}

void vec_free(Vec *v) {
    if (v->data != NULL)
        free(v->data);
    v->data = NULL;
    v->size = 0;
    v->cap = 0;
}

int dfs(int u, Vec *adj, int *state) {
    int i, v;
    state[u] = 1; // 1 = em processamento
    for (i = 0; i < adj[u].size; i++) {
        v = adj[u].data[i];
        if (state[v] == 1) {
            return 1; // ciclo encontrado
        }
        if (state[v] == 0) {
            if (dfs(v, adj, state))
                return 1;
        }
    }
    state[u] = 2; // 2 = finalizado
    return 0;
}

int main() {
    int T;
    if (scanf("%d", &T) != 1)
        return 0;

    while (T--) {
        int N, M;
        int i, A, B;
        scanf("%d %d", &N, &M);

        Vec *adj = malloc((N + 1) * sizeof(Vec));
        for (i = 1; i <= N; i++) {
            vec_init(&adj[i]);
        }

        for (i = 0; i < M; i++) {
            scanf("%d %d", &A, &B);
            // A depende de B => B -> A
            vec_push(&adj[B], A);
        }

        int *state = calloc(N + 1, sizeof(int));
        int hasCycle = 0;

        for (i = 1; i <= N; i++) {
            if (state[i] == 0) {
                if (dfs(i, adj, state)) {
                    hasCycle = 1;
                    break;
                }
            }
        }

        if (hasCycle == 1)
            printf("SIM\n");
        else
            printf("NAO\n");

        for (i = 1; i <= N; i++) {
            vec_free(&adj[i]);
        }
        free(adj);
        free(state);
    }

    return 0;
}
