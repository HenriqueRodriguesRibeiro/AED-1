/* 
    NOME: Henrique Rodrigues Ribeiro
    RA: 176515
    
   
*/

#include <stdio.h>
#include <stdlib.h>

#define MAXN 1000   /* limite seguro para matriz */

int adj[MAXN+1][MAXN+1];  /* matriz de adjacência */
int indeg[MAXN+1];        /* grau de entrada */
int queue[MAXN+5];        /* fila para BFS */

int main() {
    int T;
    if (scanf("%d", &T) != 1)
        return 0;

    while (T--) {
        int N, M;
        int i, j, A, B;

        scanf("%d %d", &N, &M);

        /* zera matriz e graus */
        for (i = 1; i <= N; i++) {
            indeg[i] = 0;
            for (j = 1; j <= N; j++) {
                adj[i][j] = 0;
            }
        }

        /* leitura das dependências */
        for (i = 0; i < M; i++) {
            scanf("%d %d", &A, &B);
            /* A depende de B → B → A */
            if (adj[B][A] == 0) {
                adj[B][A] = 1;
                indeg[A] = indeg[A] + 1;
            }
        }

        /* BFS Kahn */
        int head = 0;
        int tail = 0;

        for (i = 1; i <= N; i++) {
            if (indeg[i] == 0) {
                queue[tail] = i;
                tail = tail + 1;
            }
        }

        int processed = 0;

        while (head < tail) {
            int u = queue[head];
            head = head + 1;
            processed = processed + 1;

            for (j = 1; j <= N; j++) {
                if (adj[u][j] == 1) {
                    indeg[j] = indeg[j] - 1;
                    if (indeg[j] == 0) {
                        queue[tail] = j;
                        tail = tail + 1;
                    }
                }
            }
        }

        if (processed == N)
            printf("NAO\n");  /* acíclico */
        else
            printf("SIM\n");  /* tem ciclo */
    }

    return 0;
}
