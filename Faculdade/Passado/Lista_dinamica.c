//implementação de uma lista encadeada dinamica
struct aluno
{
    int matricula;
    char nome[30];
    float n1,n2,n3;
};
typedef struct elemento* Lista;

struct elemento
{
    struct aluno dados;
    struct elemento *prox;
};

typedef struct elemento Elem;

Lista *li;

//Criação da lista
Lista* cria_lista();//No programa Principal

Lista* cria_lista(){
    Lista* li = (Lista*) malloc(sizeof(Lista));
    if(li != NULL)
        *li = NULL;
    return li;
}

li = cria_lista();

//Libera Lista
void libera_lista(Lista* li);//No programa Principal

void libera_lista(Lista* li){
    if(li != NULL){
        Elem* no;
        while ((*li) != NULL)
        {
            no = *li;
            *li = (*li)->prox;
            free(no);
        }
        free(li);
    }    
}

libera_lista(li);

//Tamanho da Lista
int tamanho_lista(Lista* li);

int tamanho_lista(Lista* li){
    if(li == NULL) return 0;
    int cont = 0;
    Elem* no = *li;
    while (no != NULL)
    {
        cont++;
        no = no->prox
    }
    return cont;
}

int x = tamanho_lista(li);//No programa Principal

//Verificação de Lista cheia
int lista_cheia(Lista* li);

int lista_cheia(Lista* li){
    return 0;
}

int x = lista_cheia(li);//No programa Principal

//Verificação Lista Vazia
int lista_vazia(Lista* li);

int lista_vazia(Lista* li){
    if(li == NULL)
        return 1;
    if((*li) == NULL)
        return 1;
    return 0;        
}

int x = lista_vazia(Lista* li);//No programa Principal

//Inserção em Lista encadeada (inicio)
int x = insere_lista_inicio(li, dados_aluno);

int insere_lista_inicio(Lista* li, struct aluno al);

int insere_lista_inicio(Lista* li, struct aluno al){
    if(li == NULL) return 0;
    Elem* no = (Elem*) malloc(sizeof(Elem));
    if(no == NULL) return 0;
    no->dados = al;
    no->prox = (*li);
    *li = no;
    return 1;
}

//Inserção em Lista encadeada (final)
int x = insere_lista_final(li, dados_aluno);//No programa Principal

int insere_lista_final(Lista* li, struct aluno al);

int insere_lista_final(Lista* li, struct aluno al){
    if(li == NULL) return 0;
    Elem *no = (Elem*) malloc(sizeof(Elem));
    if(no == NULL) return 0;
    no->dados = al;
    no->prox = NULL;
    if((*li) == NULL)
        *li = no;
    else{
        Elem *aux = *li;
        while(aux->prox != NULL){
            aux = aux->prox;
        }
        aux->prox = no;
    }    
    return 1;
}

//Inserção em Lista encadeada (Ordenada)
int x = insere_lista_ordenada(li, dados_aluno);//No programa Principal

int insere_lista_ordenada(Lista* li, struct aluno al);

int insere_lista_ordenada(Lista* li, struct aluno al){
    if(li == NULL) return 0;
    Elem *no = (Elem*) malloc(sizeof(Elem));
    if(no == NULL) return 0;
    no->dados = al;
    if(lista_vazia(li)){
        no->prox = (*li);
        *li = no;
        return 1;
    }else{
        Elem *ant, *atual = *li;
        while(atual != NULL && atual->dados.matricula < al.matricula){
            ant = atual;
            atual = atual->prox;
        }
        if(atual == *li){
            no->prox = (*li);
            *li = no;
        }else{
            no->prox = ant->prox;
            ant->prox = no;
        }
        return 1;
    }
}



//Remoção em lista encadeada Dinaminca (inicio)
int x = remove_lista_inicio(li);//No programa Principal

int remove_lista_inicio(Lista *li);

int remove_lista_inicio(Lista *li){
    if(li == NULL) return 0;
    if((*li) == NULL) return 0;

    Elem *no = *li;
    *li = no->prox;
    free(no);
    return 1;
}

//Remoção em lista encadeada dinamica (final)
int x = remove_lista_final(li);//No programa Principal

int remove_lista_final(Lista *li);

int remove_lista_final(Lista *li){
    if(li == NULL 0) return 0;
    if((*li) == NULL) return 0;
    Elem *ant, *no = *li;
    while(no->prox != NULL){
        ant = no;
        no = no->prox;
    }
    if(no == (*li))
        *li = no->prox;
    else
        ant->prox = no->prox;
    free(no);
    return 1;        

}

//Remoção em lista encadeada dinamica (qualquer)
int x = remove_lista(li, matricula_aluno);//No programa Principal

int remove_lista(Lista* li, int mat);

int remove_lista(Lista* li, int mat){
    if(li == NULL) return 0;
    Elem *ant, *no = *li;
    while(no != NULL && no->dados.matricula != mat){
        ant = no;
        no = no->prox
    }
    if(no == NULL) return 0;
    if(no == *li)
        *li = no->prox;
    else
        ant->prox = no->prox;
    free(no);
    return 1;        
}

//Consulta em lista encadeada
int x = consulta_lista_pos(li, posicao, &dados_aluno);//No programa Principal

int consulta_lista_pos(Lista* li, int pos, struct aluno *al);

int consulta_lista_pos(Lista* li, int pos, struct aluno *al){
    if(li == NULL || pos <= 0) return 0;
    Elem *no = *li;
    int i = 1;
    while(no != NULL && i < pos){
        no = no->prox;
        i++;
    }
    if(no == NULL) return 0;
    else{
        *al = no->dados;
        return 1;
    }
}