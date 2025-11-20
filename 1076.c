/* 
    NOME: Henrique Rodrigues Ribeiro
    RA: 176515
   
   
*/
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define true 1  // Define "true" como 1
#define false 0 // Define "false" como 0
#define MAXSIZE 110 // Define o tamanho máximo do labirinto

int lido[MAXSIZE]; // Array para marcar vértices visitados
char adj[MAXSIZE][MAXSIZE]; // Matriz de adjacência para representar o labirinto

int x, ans; // x = número de vértices, ans = contador de arestas visitadas

// Protótipo da função DFS
void dfs(int);

int main(int argc, char **argv) {
    int n, y;
    int q, u, v, i;

    // Lê o número de casos de teste
    scanf("%d", &n);

    // Loop para cada caso de teste
    while (n--) {
        // Lê o vértice inicial (q), número de vértices (x) e número de arestas (y)
        scanf("%d", &q);
        scanf("%d %d", &x, &y);

        // Inicializa os arrays de visita e adjacência
        memset(lido, 0, sizeof(lido)); // Marca todos os vértices como não visitados
        memset(adj, 0, sizeof(adj)); // Inicializa a matriz de adjacência com 0

        // Lê as arestas e preenche a matriz de adjacência
        for (i = 0; i < y; ++i) {
            scanf("%d %d", &u, &v);
            adj[u][v] = adj[v][u] = true; // Marca a aresta entre u e v como existente
        }

        // Inicializa o contador de arestas visitadas
        ans = 0;

        // Executa a DFS a partir do vértice inicial q
        dfs(q);

        // Imprime o resultado: o dobro do número de arestas visitadas
        printf("%d\n", ans << 1); // ans << 1 é equivalente a ans * 2
    }

    return 0;
}


void dfs(int u) {
    int i;
    lido[u] = true; // Marca o vértice u como visitado

    // Percorre todos os vértices adjacentes a u
    for (i = 0; i < x; ++i) {
        if (adj[u][i]) { // Se há uma aresta entre u e i
            if (!lido[i]) { // Se o vértice i ainda não foi visitado
                dfs(i); // Visita o vértice i recursivamente
                ans++; // Incrementa o contador de arestas visitadas
            }
        }
    }
}