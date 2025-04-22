/* 
    NOME: Henrique Rodrigues Ribeiro
    RA: 176515
    Turma: IA
   
*/

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdbool.h>

#define INF 100000 // Define um valor "infinito" para distâncias iniciais
#define MAXSIZE 101010 // Define o tamanho máximo do grafo

int vis[MAXSIZE]; // Array para marcar vértices visitados
int dist[MAXSIZE]; // Array para armazenar as distâncias mínimas

// Estrutura para representar um nó na lista de adjacência
typedef struct _node {
    int u, w; // u = vértice destino, w = peso da aresta
    struct _node *next; // Ponteiro para o próximo nó
} node_t;

// Estrutura para representar o grafo
typedef struct _g {
    node_t *adj; // Lista de adjacência (array de nós)
} g_t;

// Protótipos das funções
g_t *make_graph(int); // Função para criar o grafo
node_t *make_node(int, int); // Função para criar um nó
void dijkstra(g_t *, int, int); // Função para executar o algoritmo de Dijkstra
void push_back(g_t *, int, int, int); // Função para adicionar uma aresta ao grafo

int main(int argc, char **argv) {
    int i;
    int n, m, c, k, a, b, w;

    // Loop principal: lê a entrada até que n, m, c e k sejam todos zero
    while (scanf("%d %d %d %d", &n, &m, &c, &k), (c && n && m && k)) {
        // Cria o grafo com n+1 vértices
        g_t *graph = make_graph(n + 1);

        // Lê as m arestas
        for (i = 0; i < m; ++i) {
            scanf("%d %d %d", &a, &b, &w);

            // Adiciona arestas ao grafo com base nas condições:
            // 1. Se ambos os vértices estão fora do conjunto de cidades (a >= c e b >= c)
            // 2. Se ambos estão dentro do conjunto de cidades e são consecutivos (a < c e b < c e |a - b| == 1)
            if (a >= c && b >= c || ((a < c) && (b < c) && (abs(a - b) == 1)))
                push_back(graph, a, b, w), push_back(graph, b, a, w);

            // Se a aresta vai de fora do conjunto de cidades para dentro
            if (a >= c && b < c)
                push_back(graph, b, a, w);

            // Se a aresta vai de dentro do conjunto de cidades para fora
            if (b >= c && a < c)
                push_back(graph, a, b, w);
        }

        // Executa o algoritmo de Dijkstra a partir do vértice k
        dijkstra(graph, k, n);

        // Imprime a distância mínima até a cidade c-1
        printf("%d\n", dist[c - 1]);
    }

    return 0;
}

// Implementação do algoritmo de Dijkstra
void dijkstra(g_t *g, int s, int __size) {
    node_t *k;
    int i, j, v;

    // Inicializa as distâncias como infinito
    for (i = 0; i < __size; ++i)
        dist[i] = INF;

    // Marca todos os vértices como não visitados
    memset(vis, false, sizeof(vis));

    // A distância do vértice inicial (s) para ele mesmo é 0
    dist[s] = 0;

    // Loop principal do Dijkstra
    for (i = 0; i < __size; ++i) {
        v = -1;

        // Encontra o vértice não visitado com a menor distância
        for (j = 0; j < __size; ++j)
            if (!vis[j] && (v == -1 || dist[j] < dist[v]))
                v = j;

        // Se não há mais vértices para visitar, sai do loop
        if (dist[v] == INF)
            break;

        // Marca o vértice como visitado
        vis[v] = true;

        // Atualiza as distâncias dos vértices adjacentes
        for (k = g->adj[v].next; k != NULL; k = k->next) {
            int to = k->u; // Vértice destino
            int len = k->w; // Peso da aresta

            // Se a distância atual for maior que a nova distância, atualiza
            if (dist[v] + len < dist[to])
                dist[to] = dist[v] + len;
        }
    }
}

// Função para criar o grafo
g_t *make_graph(int __size) {
    int i;
    g_t *g = (g_t *)malloc(sizeof(g_t)); // Aloca memória para o grafo
    g->adj = (node_t *)malloc(sizeof(node_t) * (__size + 1)); // Aloca memória para a lista de adjacência

    // Inicializa a lista de adjacência
    for (i = 0; i < __size; ++i)
        g->adj[i].next = NULL;

    return g;
}

// Função para criar um nó
node_t *make_node(int u, int w) {
    node_t *new_node = (node_t *)malloc(sizeof(node_t)); // Aloca memória para o nó

    new_node->u = u; // Define o vértice destino
    new_node->w = w; // Define o peso da aresta
    new_node->next = NULL; // Inicializa o próximo nó como NULL

    return new_node;
}

// Função para adicionar uma aresta ao grafo
void push_back(g_t *g, int u, int v, int w) {
    node_t *new_node = make_node(u, w); // Cria um novo nó
    new_node->next = g->adj[v].next; // Insere o novo nó na lista de adjacência
    g->adj[v].next = new_node;
}