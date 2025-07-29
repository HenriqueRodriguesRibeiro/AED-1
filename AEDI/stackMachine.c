#include <stdio.h>
#include <stdlib.h>
#include <string.h>
 
#define MAX_CMD 20
 
typedef struct pilha {
    int valor;
    struct pilha *prox;
} Pilha;
 
Pilha* inicializar() {
    return NULL;
}
 
Pilha* empilhar(Pilha *p, int valor) {
    Pilha *novo = (Pilha*) malloc(sizeof(Pilha));
    novo->valor = valor;
    novo->prox = p;
    return novo;
}
 
Pilha* desempilhar(Pilha *p, int *valor) {
    if (!p) {
        printf("Erro: Pilha vazia!\n");
        return NULL;
    }
    Pilha *temp = p;
    *valor = p->valor;
    p = p->prox;
    free(temp);
    return p;
}
 
Pilha* adicionar(Pilha *p, int *erro) {
    int a, b;
    if (!p || !p->prox) {
        printf("Erro: Elementos insuficiente para operacao!\n");
        *erro = 1;
        return p;
    }
    p = desempilhar(p, &a);
    p = desempilhar(p, &b);
    return empilhar(p, b + a);
}
 
Pilha* subtrair(Pilha *p, int *erro) {
    int a, b;
    if (!p || !p->prox) {
        printf("Erro: Elementos insuficiente para operacao!\n");
        *erro = 1;
        return p;
    }
    p = desempilhar(p, &a);
    p = desempilhar(p, &b);
    return empilhar(p, b - a);
}
 
Pilha* multiplicar(Pilha *p, int *erro) {
    int a, b;
    if (!p || !p->prox) {
        printf("Erro: Elementos insuficiente para operacao!\n");
        *erro = 1;
        return p;
    }
    p = desempilhar(p, &a);
    p = desempilhar(p, &b);
    return empilhar(p, b * a);
}
 
Pilha* dividir(Pilha *p, int *erro) {
    int a, b;
    if (!p || !p->prox) {
        printf("Erro: Elementos insuficiente para operacao!\n");
        *erro = 1;
        return p;
    }
    p = desempilhar(p, &a);
    p = desempilhar(p, &b);
    if (a == 0) {
        printf("Erro: Divisao por zero!\n");
        *erro = 1;
        return p;
    }
    return empilhar(p, b / a);
}
 
Pilha* duplicar(Pilha *p, int *erro) {
    int valor;
    if (!p) {
        printf("Erro: Pilha vazia para DUP!\n");
        *erro = 1;
        return p;
    }
    p = desempilhar(p, &valor);
    p = empilhar(p, valor);
    return empilhar(p, valor);
}
 
Pilha* trocar(Pilha *p, int *erro) {
    int a, b;
    if (!p || !p->prox) {
        printf("Erro: Pilha insuficiente para SWAP!\n");
        *erro = 1;
        return p;
    }
    p = desempilhar(p, &a);
    p = desempilhar(p, &b);
    p = empilhar(p, a);
    return empilhar(p, b);
}
 
Pilha* rolar(Pilha *p, int n, int *erro) {
    if (n <= 0) {
        printf("Erro: Posicao invalida!\n");
        *erro = 1;
        return p;
    }
 
    Pilha *temp = NULL;
    int valor, i;
 
    for (i = 1; i <= n; i++) {
        if (!p) {
            printf("Erro: Posicao invalida!\n");
            *erro = 1;
            return p;
        }
        if (i == n) {
            p = desempilhar(p, &valor);
        } else {
            int v;
            p = desempilhar(p, &v);
            temp = empilhar(temp, v);
        }
    }
 
    while (temp) {
        temp = desempilhar(temp, &i);
        p = empilhar(p, i);
    }
 
    return empilhar(p, valor);
}
 
void limpar(Pilha *p) {
    int temp;
    while (p) {
        p = desempilhar(p, &temp);
    }
}
 
Pilha* imprimir(Pilha *p) {
    Pilha *temp = NULL;
    int valor;
    
    while (p) {
        p = desempilhar(p, &valor);
        printf("%d ", valor);
        temp = empilhar(temp, valor);
    }
    printf("\n");
    
    while (temp) {
        temp = desempilhar(temp, &valor);
        p = empilhar(p, valor);
    }
    
    return p;
}
 
int main() {
    int N, erro = 0, imprimiu = 0;
    char linha[MAX_CMD];
    Pilha *pilha = inicializar();
 
    do {
        scanf("%d", &N);
    } while (N < 1 || N > 100);
    getchar();
 
    for (int i = 0; i < N && !erro; i++) {
        fgets(linha, sizeof(linha), stdin);
        linha[strcspn(linha, "\n")] = '\0';
 
        char comando[10];
        int valor;
 
        if (sscanf(linha, "%s %d", comando, &valor) == 2) {
            if (strcmp(comando, "PUSH") == 0) {
                pilha = empilhar(pilha, valor);
            } else if (strcmp(comando, "ROLL") == 0) {
                pilha = rolar(pilha, valor, &erro);
            }
        } else {
            if (strcmp(linha, "POP") == 0) {
                int temp;
                pilha = desempilhar(pilha, &temp);
            } else if (strcmp(linha, "ADD") == 0) {
                pilha = adicionar(pilha, &erro);
            } else if (strcmp(linha, "SUB") == 0) {
                pilha = subtrair(pilha, &erro);
            } else if (strcmp(linha, "MUL") == 0) {
                pilha = multiplicar(pilha, &erro);
            } else if (strcmp(linha, "DIV") == 0) {
                pilha = dividir(pilha, &erro);
            } else if (strcmp(linha, "DUP") == 0) {
                pilha = duplicar(pilha, &erro);
            } else if (strcmp(linha, "SWAP") == 0) {
                pilha = trocar(pilha, &erro);
            } else if (strcmp(linha, "CLEAR") == 0) {
                limpar(pilha);
                pilha = inicializar();
            } else if (strcmp(linha, "PRINT") == 0) {
                pilha = imprimir(pilha);
                imprimiu = 1;
            }
        }
        
        if (erro) {
            limpar(pilha);
            return 0;
        }
    }
 
    if (!imprimiu) {
        pilha = imprimir(pilha);
    }
 
    limpar(pilha);
    return 0;
}