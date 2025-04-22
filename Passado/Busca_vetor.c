//Busca Linear
int buscaLinear(int *V, int N, int elem){
    for(int i = 0; i < N; i++){
        if(elem == V[i])
            return i;
    }
    return -1;
}

//Busca ordenada
int buscaORdenada(int *v, int N, int elem){
    for(int i = 0; i < N; i++){
        if(elem == V[i])
            return i;
        else
            if(elem < V[i])
                return -1;
    }
    return -1;            
}