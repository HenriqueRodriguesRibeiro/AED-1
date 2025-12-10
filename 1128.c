/* 
    NOME: Henrique Rodrigues Ribeiro
    RA: 176515
    
   
*/

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX 2001

typedef struct Node {
    int v;
    struct Node* next;
} Node;

Node* adj[MAX];      // Lista de adjacência do grafo original
Node* adjT[MAX];     // Lista de adjacência do grafo transposto
int visited[MAX];
int order[MAX];      // Ordem de finalização da DFS
int orderSize;
int comp[MAX];       // Componente de cada vértice
int compCount;

void addEdge(Node* adjList[], int u, int v) {
    Node* newNode = (Node*)malloc(sizeof(Node));
    newNode->v = v;
    newNode->next = adjList[u];
    adjList[u] = newNode;
}

void dfs1(int u) {
    visited[u] = 1;
    
    Node* curr = adj[u];
    while (curr != NULL) {
        int v = curr->v;
        if (!visited[v]) {
            dfs1(v);
        }
        curr = curr->next;
    }
    
    order[orderSize++] = u;  // Armazena em ordem de finalização
}

void dfs2(int u, int c) {
    visited[u] = 1;
    comp[u] = c;
    
    Node* curr = adjT[u];
    while (curr != NULL) {
        int v = curr->v;
        if (!visited[v]) {
            dfs2(v, c);
        }
        curr = curr->next;
    }
}

int main() {
    int H, M;
    
    while (1) {
        scanf("%d %d", &H, &M);
        if (H == 0 && M == 0) break;
        
        // Inicializar estruturas
        orderSize = 0;
        compCount = 0;
        
        for (int i = 1; i <= H; i++) {
            adj[i] = NULL;
            adjT[i] = NULL;
            visited[i] = 0;
            comp[i] = 0;
        }
        
        // Ler arestas
        for (int i = 0; i < M; i++) {
            int V, W, P;
            scanf("%d %d %d", &V, &W, &P);
            
            if (P == 1) {  // Mão única: V -> W
                addEdge(adj, V, W);
                addEdge(adjT, W, V);
            } else {        // Mão dupla: V <-> W
                addEdge(adj, V, W);
                addEdge(adj, W, V);
                addEdge(adjT, V, W);
                addEdge(adjT, W, V);
            }
        }
        
        // Primeira DFS: ordenar por tempo de finalização
        for (int i = 1; i <= H; i++) {
            if (!visited[i]) {
                dfs1(i);
            }
        }
        
        // Resetar visited
        for (int i = 1; i <= H; i++) {
            visited[i] = 0;
        }
        
        // Segunda DFS: no grafo transposto, na ordem inversa
        for (int i = orderSize - 1; i >= 0; i--) {
            int u = order[i];
            if (!visited[u]) {
                dfs2(u, compCount++);
            }
        }
        
        // Verificar se há apenas 1 componente fortemente conexo
        if (compCount == 1) {
            printf("1\n");
        } else {
            printf("0\n");
        }
        
        // Liberar memória (importante para múltiplos casos de teste)
        for (int i = 1; i <= H; i++) {
            // Liberar lista original
            Node* curr = adj[i];
            while (curr != NULL) {
                Node* temp = curr;
                curr = curr->next;
                free(temp);
            }
            
            // Liberar lista transposta
            curr = adjT[i];
            while (curr != NULL) {
                Node* temp = curr;
                curr = curr->next;
                free(temp);
            }
        }
    }
    
    return 0;
}