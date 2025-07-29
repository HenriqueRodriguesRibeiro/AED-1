#include <stdio.h>

typedef struct lista {
    struct lista *prox;
    int dest; //id do nó destino
} Lista;

typedef struct {
    Lista **vet;
    int nodes; //numero de nos no grafo
}GrafoL;

void menorAresta(GrafoL *g) {
    if (g == NULL || g->vet == NULL || g->nodes <= 0) {
        return;
    }

    int menor_peso, origem = -1, destino = -1;
    int encontrou_aresta = 0;  // Flag inteira substituindo bool

    for (int i = 0; i < g->nodes; i++) {
        Lista *atual = g->vet[i];
        while (atual != NULL) {
            if (!encontrou_aresta || atual->peso < menor_peso) {
                menor_peso = atual->peso;
                origem = i;
                destino = atual->dest;
                encontrou_aresta = 1;
            }
            atual = atual->prox;
        }
    }

    if (!encontrou_aresta) {
        printf("O grafo não possui arestas.\n");
    } else {
        printf("Aresta de menor peso: %d - %d (peso: %d)\n", origem, destino, menor_peso);
    }
}