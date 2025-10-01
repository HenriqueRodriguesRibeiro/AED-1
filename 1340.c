/* 
    NOME: Henrique Rodrigues Ribeiro
    RA: 176515
   
*/

#include <stdio.h>
#include <stdlib.h>

#define MAX 1000

// Estrutura simples para Fila
typedef struct {
    int data[MAX];
    int front, rear;
} Queue;

void initQueue(Queue *q) {
    q->front = 0;
    q->rear = 0;
}
void pushQueue(Queue *q, int x) {
    q->data[q->rear++] = x;
}
int popQueue(Queue *q) {
    int val = q->data[q->front];
    q->front++;
    return val;
}
int emptyQueue(Queue *q) {
    return q->front == q->rear;
}

// Estrutura simples para Pilha
typedef struct {
    int data[MAX];
    int top;
} Stack;

void initStack(Stack *s) {
    s->top = 0;
}
void pushStack(Stack *s, int x) {
    s->data[s->top++] = x;
}
int popStack(Stack *s) {
    s->top--;
    return s->data[s->top];
}
int emptyStack(Stack *s) {
    return s->top == 0;
}

// Estrutura simples para Fila de Prioridade (máx-heap simplificado)
typedef struct {
    int data[MAX];
    int size;
} PriorityQueue;

void initPQ(PriorityQueue *pq) {
    pq->size = 0;
}
void pushPQ(PriorityQueue *pq, int x) {
    pq->data[pq->size++] = x;
}
int popPQ(PriorityQueue *pq) {
    int i, idx = 0;
    int max = pq->data[0];
    for(i = 1; i < pq->size; i++) {
        if(pq->data[i] > max) {
            max = pq->data[i];
            idx = i;
        }
    }
    for(i = idx; i < pq->size - 1; i++) {
        pq->data[i] = pq->data[i+1];
    }
    pq->size--;
    return max;
}
int emptyPQ(PriorityQueue *pq) {
    return pq->size == 0;
}

int main() {
    int n, op, x;
    while(scanf("%d", &n) != EOF) {
        Stack s; Queue q; PriorityQueue pq;
        int isStack = 1, isQueue = 1, isPQ = 1;
        
        initStack(&s);
        initQueue(&q);
        initPQ(&pq);
        
        while(n--) {
            scanf("%d", &op);
            if(op == 1) {
                scanf("%d", &x);
                pushStack(&s, x);
                pushQueue(&q, x);
                pushPQ(&pq, x);
            } else {
                scanf("%d", &x);
                if(emptyStack(&s) || popStack(&s) != x) {
                    isStack = 0;
                }
                if(emptyQueue(&q) || popQueue(&q) != x) {
                    isQueue = 0;
                }
                if(emptyPQ(&pq) || popPQ(&pq) != x) {
                    isPQ = 0;
                }
            }
        }
        
        if(isStack + isQueue + isPQ > 1) {
            printf("not sure\n");
        } else {
            if(isStack == 1) {
                printf("stack\n");
            } else {
                if(isQueue == 1) {
                    printf("queue\n");
                } else {
                    if(isPQ == 1) {
                        printf("priority queue\n");
                    } else {
                        printf("impossible\n");
                    }
                }
            }
        }
    }
    return 0;
}
