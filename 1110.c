/* NOME: Henrique Rodrigues Ribeiro
   RA: 176515
   Turma: IA
   
*/

#include <stdio.h>
#include <stdlib.h>



typedef struct dequeNo {
    int valor;
    struct dequeNo *anterior, *proximo;
} DequeNo;

typedef struct deque {
    int TAM;
    DequeNo *frente, *tras;
} Deque;

void push_front(Deque *p, int valor) {
    p->TAM += 1;
    DequeNo *novaFrente = (DequeNo *) malloc(sizeof(DequeNo));

    novaFrente->valor = valor;
    novaFrente->proximo = p->frente;
    if(p->frente != NULL)
        p->frente->anterior = novaFrente;
    p->frente = novaFrente;
    if(p->tras == NULL)
        p->tras = p->frente;    
}

void push_back(Deque *p, int valor) {
    p->TAM += 1;
    DequeNo *novoTras = (DequeNo *)malloc(sizeof(DequeNo));

    novoTras->valor = valor;
    novoTras->anterior = p->tras;
    if(p->tras != NULL)
        p->tras->proximo = novoTras;
    p->tras = novoTras;
    if(p->frente == NULL)
        p->frente = p->tras;    
}

void pop_front(Deque *p) {
    if(p->TAM > 0) {
        p->TAM -= 1;
        DequeNo *velhaFrente = p->frente;
        p->frente = p->frente->proximo;
        free(velhaFrente);
    }
}

void pop_back(Deque *p) {
    if(p->TAM > 0) {
        p->TAM -= 1;
        DequeNo *velhoTras = p->tras;
        p->tras = p->tras->anterior;
        free(velhoTras);
    }
}

int front(Deque *p) {
    return p->frente->valor;
}

int back(Deque *p) {
    return p->tras->valor;
}

int size(Deque *p) {
    return p->TAM;
}

int vazio(Deque *p) {
    return p->TAM == 0;
}

void inicia(Deque *p) {
    p->TAM = 0;
    p->frente = NULL;
    p->tras = NULL;
}

void destroi(Deque *p) {
    while (!vazio(p)) {
        pop_front(p);
    }
}

int main() {
    int N, primeiro;
    Deque baralho;

    while(scanf("%d", &N)) {
        if(!N)
            break;
        inicia(&baralho);

        for (int i = 1; i <= N; i++) {
            push_back(&baralho, i);
        }

        primeiro = 1;
        printf("Discarded cards: ");
        while(size(&baralho) > 1) {
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