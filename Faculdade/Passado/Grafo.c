//Implementação
typedef struct grafo Grafo;

struct grafo{
    int eh_ponderado;
    int nro_vertices;
    int grau_max;
    int** arestas;
    float** pesos;
    int* grau;
};

Grafo *gr;


//Criação
int main(){
    Grafo cria_Grafo(int nro_vertices, int grau_max, int eh_ponderado);

    Grafo *gr;
    gr = cria_Grafo(10, 7, 0);
}

//Busca em profundidade
void buscaProfundidade(Grafo *gr, int ini, int *visitado, int cont){
    int i;
    visitado[ini] = cont;
    for(i = 0; i<gr->grau[ini]; i++){
        if(!visitado[gr->arestas[ini][i]])
        buscaProfundidade(gr, gr->arestas[ini][i], visitado, cont+1);
    }
}

void buscaProfundidade_Grafo(Grafo *gr, int ini, int *visitado){
    int i, cont = 1;
    for(i = 0; i<gr->nro_vertices; i++)
        visitado[i] = 0;
    buscaProfundidade(gr, ini, visitado, cont);    
}