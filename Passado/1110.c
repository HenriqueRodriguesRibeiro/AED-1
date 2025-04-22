/* NOME: Henrique Rodrigues Ribeiro
   RA: 176515
   Turma: IA
   
*/

#include <stdio.h>
#include <stdlib.h>

/*Usando deques, uma estrutura de dados que permite operações de inserção e remoção nas duas pontas, 
podemos ir simulando o processo até que o deque tenha apenas um elemento, que no caso é o elemento 
que precisa ser retornado como o elemento que sobrou.*/

struct dequeNo{
    int valor;
    struct dequeNo *anterior, *proximo;
};

struct deque{
    int TAM;
    struct dequeNo *frente, *tras;
};

void push_front(struct deque *p, int valor){
    p->TAM += 1;
    struct dequeNo *novaFrente = (struct dequeNo *) malloc(sizeof(struct dequeNo));

    novaFrente->valor = valor;
    novaFrente->proximo = p->frente;
    if(p->frente != NULL)
        p->frente->anterior = novaFrente;
    p->frente = novaFrente;
    if(p->tras == NULL)
        p->tras = p->frente;    
}

void push_back(struct deque *p, int valor){
    p->TAM += 1;
    struct dequeNo *novoTras = (struct dequeNo *)malloc(sizeof(struct dequeNo));

    novoTras->valor = valor;
    novoTras->anterior = p->tras;
    if(p->tras != NULL)
        p->tras->proximo = novoTras;
    p->tras = novoTras;
    if(p->frente == NULL)
        p->frente = p->tras;    
}

void pop_front(struct deque *p){
    if(p->TAM > 0){
        p->TAM -= 1;
        struct dequeNo *velhaFrente = p->frente;
        p->frente = p->frente->proximo;
        free(velhaFrente);
    }
}

void pop_back(struct deque *p){
    if(p->TAM > 0){
        p->TAM -= 1;
        struct dequeNo *velhoTras = p->tras;
        p->tras = p->tras->anterior;
        free(velhoTras);
    }
}

int front(struct deque *p){
    return p->frente->valor;
}

int back(struct deque *p){
    return p->tras->valor;
}

int size(struct deque *p){
    return p->TAM;
}

int vazio(struct deque *p){
    return p->TAM == 0;
}

void inicia(struct deque *p){
    p->TAM = 0;
    p->frente = NULL;
    p->tras = NULL;
}

void destroi(struct deque *p){
    while (!vazio(p)){
        pop_front(p);
    }
}

int main(){
    int N, primeiro;
    struct deque baralho;

    while(scanf("%d", &N)){
        if(!N)
            break;
        inicia(&baralho);

        for (int i = 1; i <= N; i++){
            push_back(&baralho, i);
        }

        primeiro = 1;
        printf("Discarded cards: ");
        while(size(&baralho) > 1){
            if(!primeiro)
                printf(", ");
            else
                primeiro = 0;
            printf("%d", front(&baralho));

            pop_front(&baralho);
            push_back(&baralho, front(&baralho));
            pop_front(&baralho);        
        }

        printf("\nRemaining card: %d\n", front(&baralho));

        destroi(&baralho);    
    }
    return 0;
}