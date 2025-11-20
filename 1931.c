/* 
    NOME: Henrique Rodrigues Ribeiro
    RA: 176515
    
   
*/

#include <stdio.h>
#include <stdlib.h>
#include <limits.h>

typedef struct {
    int to;
    int w;
} Edge;

typedef struct {
    Edge *edges;
    int size;
    int cap;
} List;

void list_init(List *L) {
    L->size = 0;
    L->cap = 2;
    L->edges = malloc(L->cap * sizeof(Edge));
}

void list_push(List *L, int to, int w) {
    if (L->size == L->cap) {
        L->cap *= 2;
        L->edges = realloc(L->edges, L->cap * sizeof(Edge));
        if (!L->edges) { perror("realloc"); exit(1); }
    }
    L->edges[L->size].to = to;
    L->edges[L->size].w = w;
    L->size++;
}

typedef struct {
    int u;
    int parity; /* 0 = even number of edges so far, 1 = odd */
    int dist;
} Node;

/* min-heap (1-based index) */
typedef struct {
    Node *a;
    int size;
    int cap;
} MinHeap;

void heap_init(MinHeap *h, int cap) {
    h->cap = cap > 4 ? cap : 4;
    h->a = malloc((h->cap + 1) * sizeof(Node));
    h->size = 0;
}

void heap_push(MinHeap *h, Node x) {
    if (h->size + 1 > h->cap) {
        h->cap *= 2;
        h->a = realloc(h->a, (h->cap + 1) * sizeof(Node));
        if (!h->a) { perror("realloc"); exit(1); }
    }
    int i = ++h->size;
    h->a[i] = x;
    while (i > 1) {
        int p = i >> 1;
        if (h->a[p].dist <= h->a[i].dist) break;
        Node tmp = h->a[p]; h->a[p] = h->a[i]; h->a[i] = tmp;
        i = p;
    }
}

Node heap_pop(MinHeap *h) {
    Node ret = h->a[1];
    h->a[1] = h->a[h->size--];
    int i = 1;
    while (1) {
        int l = i<<1, r = l+1, smallest = i;
        if (l <= h->size && h->a[l].dist < h->a[smallest].dist) smallest = l;
        if (r <= h->size && h->a[r].dist < h->a[smallest].dist) smallest = r;
        if (smallest == i) break;
        Node tmp = h->a[i]; h->a[i] = h->a[smallest]; h->a[smallest] = tmp;
        i = smallest;
    }
    return ret;
}

int main() {
    int C, V;
    while (scanf("%d %d", &C, &V) == 2) {
        if (C == 0 && V == 0) break;

        /* adjacency lists 1..C */
        List *adj = malloc((C + 1) * sizeof(List));
        for (int i = 1; i <= C; ++i) list_init(&adj[i]);

        for (int i = 0; i < V; ++i) {
            int a, b, g;
            scanf("%d %d %d", &a, &b, &g);
            list_push(&adj[a], b, g);
            list_push(&adj[b], a, g);
        }

        /* dist[u][p]: minimal cost to reach u with parity p (p = number of edges % 2) */
        int **dist = malloc((C + 1) * sizeof(int*));
        for (int i = 0; i <= C; ++i) {
            dist[i] = malloc(2 * sizeof(int));
            dist[i][0] = dist[i][1] = INT_MAX;
        }

        MinHeap h;
        heap_init(&h, 4);

        dist[1][0] = 0; /* start at city 1, zero edges -> even (0) */
        heap_push(&h, (Node){1, 0, 0});

        while (h.size > 0) {
            Node cur = heap_pop(&h);
            if (cur.dist != dist[cur.u][cur.parity]) continue;

            /* traverse neighbors */
            for (int i = 0; i < adj[cur.u].size; ++i) {
                int v = adj[cur.u].edges[i].to;
                int w = adj[cur.u].edges[i].w;
                /* HERE: parity changes by 1 (we traversed one more edge) */
                int newpar = cur.parity ^ 1; /* always flip */
                int nd = cur.dist + w;
                if (nd < dist[v][newpar]) {
                    dist[v][newpar] = nd;
                    heap_push(&h, (Node){v, newpar, nd});
                }
            }
        }

        if (dist[C][0] == INT_MAX) printf("-1\n");
        else printf("%d\n", dist[C][0]);

        for (int i = 1; i <= C; ++i) free(adj[i].edges);
        free(adj);
        for (int i = 0; i <= C; ++i) free(dist[i]);
        free(dist);
        free(h.a);
    }
    return 0;
}
