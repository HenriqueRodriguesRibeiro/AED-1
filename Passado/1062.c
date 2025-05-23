/* 
    NOME: Henrique Rodrigues Ribeiro
    RA: 176515
    Turma: IA
   
*/

#include <stdlib.h>
#include <stdio.h>

struct pilhaNo{
    int testes;
    struct pilhaNo* abaixo;
};

struct pilha{
    int tam;
    struct pilhaNo* topo;
};

void push(struct pilha* p, int testes){
    p->tam += 1;
    struct pilhaNo* novoTopo = (struct pilhaNo*) malloc(sizeof(struct pilhaNo));

    novoTopo->testes = testes;
    novoTopo->abaixo = p->topo;
    p->topo = novoTopo;
}

void pop(struct pilha* p){
    if(p->tam > 0){
        p->tam -= 1;
        struct pilhaNo* velhoTopo = p->topo;
        p->topo = p->topo->abaixo;
        free(velhoTopo);
    }
}

int top(struct pilha* p){
    return p->topo->testes;
}

int size(struct pilha* p){
    return p->tam;
}

int empty(struct pilha* p){
    return p->tam == 0;
}

void inicializa(struct pilha* p){
    p->tam = 0;
    p->topo = NULL;
}

void destroi(struct pilha* p){
    while(!empty(p)){
        pop(p);
    }
}

int main(){
    int N, x;
    struct pilha A, estacao, B;

    while(scanf("%d", &N) != EOF){
        if(!N)  break;

        while(scanf("%d", &x)){
            if(!x){
                printf("\n");
                break;
            }

            inicializa(&A);
            inicializa(&estacao);
            inicializa(&B);

            push(&A, x);
            push(&B, 1);

            for(int i = 2; i <= N; ++i){
                scanf("%d", &x);
                push(&A, x);
                push(&B, i);
            }

            while(!empty(&A) || !empty(&estacao) || !empty(&B)){
                if(!empty(&A) && !empty(&B) && top(&A) == top(&B)){
                    pop(&A);
                    pop(&B);
                }else if(!empty(&estacao) && !empty(&B) && top(&estacao) == top(&B)){
                    pop(&estacao);
                    pop(&B);
                }else if(!empty(&A)){
                    push(&estacao, top(&A));
                    pop(&A);
                }else{
                    break;
                }
            }

            if(empty(&A) && empty(&estacao) && empty(&B)){
                printf("Yes\n");
            }else{
                printf("No\n");
            }

            destroi(&A);
            destroi(&estacao);
            destroi(&B);
        }
    }
    return 0;
}