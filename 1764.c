/* 
    NOME: Henrique Rodrigues Ribeiro
    RA: 176515
    
   
*/

#include <stdio.h>
#include <stdlib.h>

typedef struct {
    int x, y, z;
} Edge;

int parent[40001];
int ranku[40001];

int find(int x) {
    while (x != parent[x]) {
        parent[x] = parent[parent[x]];
        x = parent[x];
    }
    return x;
}

void unite(int a, int b) {
    a = find(a);
    b = find(b);

    if (a != b) {
        if (ranku[a] < ranku[b])
            parent[a] = b;
        else if (ranku[b] < ranku[a])
            parent[b] = a;
        else {
            parent[b] = a;
            ranku[a]++;
        }
    }
}

int cmp(const void *a, const void *b) {
    return ((Edge*)a)->z - ((Edge*)b)->z;
}

int main() {
    int M, N;

    while (1) {
        scanf("%d %d", &M, &N);
        if (M == 0 && N == 0) break;

        for (int i = 0; i < M; i++) {
            parent[i] = i;
            ranku[i] = 0;
        }

        Edge *edges = (Edge*)malloc(N * sizeof(Edge));

        for (int i = 0; i < N; i++) {
            scanf("%d %d %d", &edges[i].x, &edges[i].y, &edges[i].z);
        }

        qsort(edges, N, sizeof(Edge), cmp);

        long long total = 0;
        int used = 0;

        for (int i = 0; i < N && used < M - 1; i++) {
            if (find(edges[i].x) != find(edges[i].y)) {
                unite(edges[i].x, edges[i].y);
                total += edges[i].z;
                used++;
            }
        }

        printf("%lld\n", total);

        free(edges);
    }

    return 0;
}
