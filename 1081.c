/* 
    NOME: Henrique Rodrigues Ribeiro
    RA: 176515
    
   
*/

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_VERTICES 21
#define MAX_EDGES 21

typedef struct {
    int adj[MAX_VERTICES][MAX_VERTICES];
    int visited[MAX_VERTICES];
    int V, E;
} Graph;

void initGraph(Graph *g, int V) {
    g->V = V;
    g->E = 0;
    for (int i = 0; i < V; i++) {
        g->visited[i] = 0;
        for (int j = 0; j < V; j++) {
            g->adj[i][j] = 0;
        }
    }
}

void addEdge(Graph *g, int u, int v) {
    g->adj[u][v] = 1;
}

void DFS_visit(Graph *g, int v, int depth, int *first_in_component) {
    // Para cada vizinho em ordem crescente
    for (int w = 0; w < g->V; w++) {
        if (g->adj[v][w]) {
            // Imprimir recuo
            for (int i = 0; i < depth; i++) {
                printf("  ");
            }
            
            printf("%d-%d", v, w);
            
            if (!g->visited[w]) {
                printf(" pathR(G,%d)\n", w);
                g->visited[w] = 1;
                DFS_visit(g, w, depth + 1, first_in_component);
            } else {
                printf("\n");
            }
        }
    }
}

int hasEdges(Graph *g, int v) {
    // Verifica se o vértice tem alguma aresta (saída)
    for (int i = 0; i < g->V; i++) {
        if (g->adj[v][i]) {
            return 1;
        }
    }
    return 0;
}

void DFS(Graph *g) {
    int new_component = 1;
    
    for (int v = 0; v < g->V; v++) {
        if (!g->visited[v] && hasEdges(g, v)) {
            // Se não é o primeiro componente, pular linha
            if (!new_component) {
                printf("\n");
            }
            
            // Marcar primeiro vértice do componente como visitado
            g->visited[v] = 1;
            
            // Fazer DFS a partir deste vértice
            DFS_visit(g, v, 1, &new_component);
            
            new_component = 0;
        }
    }
}

int main() {
    int R, caso = 1;
    scanf("%d", &R);
    
    while (R--) {
        int V, E;
        scanf("%d %d", &V, &E);
        
        Graph g;
        initGraph(&g, V);
        
        for (int i = 0; i < E; i++) {
            int u, v;
            scanf("%d %d", &u, &v);
            addEdge(&g, u, v);
        }
        
        // Ordenar listas de adjacência para visitar em ordem crescente
        // (Já estamos fazendo isso no loop de w=0 até V-1)
        
        printf("Caso %d:\n", caso++);
        DFS(&g);
        
        // Linha em branco após cada caso
        printf("\n");
    }
    
    return 0;
}