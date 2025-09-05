//Implementação de Pilhas
struct aluno{
    int matricula;
    char nome[30];
    float n1, n2, n3;
};
typedef struct elemento* Pilha;

struct elemento{
    struct aluno dados;
    struct elemento *prox;
};
typedef struct elemento Elem;

Pilha *pi;

//Criação de pilhas
pi = cria_pilha();//No programa Principal

Pilha* cria_pilha(){
    Pilha* pi = (Pilha*) malloc(sizeof(Pilha));
    if(pi != NULL)
        *pi = NULL;
    return pi;    
}

//Liberação da lista
libera_pilha (pi);//No programa Principal

void libera_pilha(Pilha* pi){
    if(pi != NULL){
        Elem* no;
        while((*pi) != NULL){
            no = *pi;
            *pi = (*pi)->prox;
            free(no);
        }
        free(pi);
    }
}

//Tamanho da pilha
int x = tam_pilha(pi);//No programa Principal

int tam_pilha(Pilha* pi){
    if(pi == NULL) return 0;
    int cont = 0;
    Elem* no = *pi;
    while(no != NULL){
        cont++;
        no = no->prox;
    }
    return cont;
}

//Pilha cheia
int x = Pilha_cheia(pi);//No programa Principal
if(Pilha_cheia(pi))

int Pilha_cheia(Pilha* pi){
    return 0;
}

//Pilha cheia
int x = Pilha_vazia(pi);

int Pilha_vazia(Pilha* pi){
    if(pi == NULL) return 1;
    if((*pi) == NULL) return1;
    return 0;
}

//Inserção em Pilha
int x = insere_pilha(pi, dados_aluno);//No programa Principal

int insere_pilha(Pilha* pi, struct aluno *al){
    if(pi == NULL) return 0;
    Elem* no = (Elem*) malloc(sizeof(Elem));
    if(no == NULL) return 0;
    no->dados = al;
    no->prox = (*pi);
    *pi = no;
    return 1;
}

//Remoção Pilha
int x = remove_pilha(pi);

int remove_pilha(Pilha* pi){
    if(pi == NULL) return 0;
    if((*pi) == NULL) return 0;
    Elem *no = *pi;
    *pi = no->prox;
    free(no);
    return 1;
}

//Consulta PIlha
int x = consulta_topo_pilha(pi, &dados_aluno);

int consulta_topo_pilha(Pilha* pi, struct aluno *al){
    if(pi == NULL) return 0;
    if((*pi) == NULL) return 0;
    *al = (*pi)->dados;
    return 1;
}