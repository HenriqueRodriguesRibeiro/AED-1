#include <stdio.h>
#include <stdlib.h>
#include <string.h>
 
#define MAX_CMD 20
 
typedef struct pilha {
    int valor;
    struct pilha *seg;
} pilha;
 
typedef pilha *ppilha;
 
ppilha inicializa() {
    return NULL;
}
 
ppilha push(ppilha p, int n) {
    ppilha novo = (ppilha) malloc(sizeof(pilha));
    novo->valor = n;
    novo->seg = p;
    return novo;
}
 
ppilha pop(ppilha p, int *v) {
    if (!p) {
        printf("Erro: Pilha vazia!\n");
        return NULL;
    }
    ppilha temp = p;
    *v = p->valor;
    p = p->seg;
    free(temp);
    return p;
}
 
ppilha ADD(ppilha p, int *erro) {
    int a, b;
    if (!p || !p->seg) {
        printf("Erro: Elementos insuficiente para operacao!\n");
        *erro = 1;
        return p;
    }
    p = pop(p, &a);
    p = pop(p, &b);
    return push(p, a + b);
}
 
ppilha SUB(ppilha p, int *erro) {
    int a, b;
    if (!p || !p->seg) {
        printf("Erro: Elementos insuficiente para operacao!\n");
        *erro = 1;
        return p;
    }
    p = pop(p, &a);
    p = pop(p, &b);
    return push(p, b - a);
}
 
ppilha MUL(ppilha p, int *erro) {
    int a, b;
    if (!p || !p->seg) {
        printf("Erro: Elementos insuficiente para operacao!\n");
        *erro = 1;
        return p;
    }
    p = pop(p, &a);
    p = pop(p, &b);
    return push(p, b * a);
}
 
ppilha DIV(ppilha p, int *erro) {
    int a, b;
    if (!p || !p->seg) {
        printf("Erro: Elementos insuficiente para operacao!\n");
        *erro = 1;
        return p;
    }
    p = pop(p, &a);
    p = pop(p, &b);
    if (a == 0) {
        printf("Erro: Divisao por zero!\n");
        *erro = 1;
        return p;
    }
    
    return push(p, b / a);
}
 
ppilha DUP(ppilha p, int *erro) {
    int a;
    if (!p) {
        printf("Erro: Pilha vazia para DUP!\n");
        *erro = 1;
        return p;
    }
    p = pop(p, &a);
    p = push(p, a);
    return push(p, a);
}
 
ppilha SWAP(ppilha p, int *erro) {
    int a, b;
    if (!p || !p->seg) {
        printf("Erro: Pilha insuficiente para SWAP!\n");
        *erro = 1;
        return p;
    }
    p = pop(p, &a);
    p = pop(p, &b);
    p = push(p, a);
    return push(p, b);
}
 
ppilha ROLL(ppilha p, int n, int *erro) {
    if (n <= 0) {
        printf("Erro: Posicao invalida!\n");
        *erro = 1;
        return p;
    }
 
    ppilha aux = NULL;
    int val, i;
 
    for (i = 1; i <= n; i++) {
        if (!p) {
            printf("Erro: Posicao invalida!\n");
            *erro = 1;
            return p;
        }
        if (i == n) {
            p = pop(p, &val);
        } else {
            int temp;
            p = pop(p, &temp);
            aux = push(aux, temp);
        }
    }
 
    while (aux) {
        aux = pop(aux, &i);
        p = push(p, i);
    }
 
    p = push(p, val);
 
    return p;
}
 
ppilha CLEAR(ppilha p) {
    int v;
    while (p) p = pop(p, &v);
    return NULL;
}
 
ppilha PRINT(ppilha p) {
    int v;
    ppilha aux = NULL;
    
    while (p) {
        p = pop(p, &v);
        printf("%d ", v);
        aux = push(aux, v);
    }
    printf("\n");
 
    while (aux) {
        aux = pop(aux, &v);
        p = push(p, v);
    }
 
    return p;
}
 
int main() {
    int N, erro = 0, print = 0;
    char linha[MAX_CMD];
    ppilha head = inicializa();
 
    do{
    scanf("%d", &N);
    }while(N < 1 || N > 100);
 
    getchar();
 
    for (int i = 0; i < N && !erro; i++) {
        fgets(linha, sizeof(linha), stdin);
        linha[strcspn(linha, "\n")] = 0;
 
        char cmd[10];
        int val;
 
        if (sscanf(linha, "%s %d", cmd, &val) == 2) {
            if (strcmp(cmd, "PUSH") == 0) {
                head = push(head, val);
            } else if (strcmp(cmd, "ROLL") == 0) {
                head = ROLL(head, val, &erro);
            }
        } else {
            if (strcmp(linha, "POP") == 0) {
                int tmp;
                head = pop(head, &tmp);   
            } if (strcmp(linha, "ADD") == 0) {
                head = ADD(head, &erro);
            } else if (strcmp(linha, "SUB") == 0) {
                head = SUB(head, &erro);
            } else if (strcmp(linha, "MUL") == 0) {
                head = MUL(head, &erro);
            } else if (strcmp(linha, "DIV") == 0) {
                head = DIV(head, &erro);
            } else if (strcmp(linha, "DUP") == 0) {
                head = DUP(head, &erro);
            } else if (strcmp(linha, "SWAP") == 0) {
                head = SWAP(head, &erro);
            } else if (strcmp(linha, "CLEAR") == 0) {
                head = CLEAR(head);
            } else if (strcmp(linha, "PRINT") == 0) {
                head = PRINT(head);
                print = 1;
            }
        }
        if (erro) {
            head = CLEAR(head);
            return 0;
        }
    }
 
    if(print == 0) {
        
        head = PRINT(head);
    }
 
    head = CLEAR(head);
 
    return 0;
}