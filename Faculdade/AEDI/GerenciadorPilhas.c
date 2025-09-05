#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define TAM_NOME 50
#define TAM_LINHA 120

typedef struct Elemento {
    int valor;
    struct Elemento *proximo;
} Elemento;

typedef struct Pilha {
    char nome[TAM_NOME];
    Elemento *topo;
    struct Pilha *proxima;
} Pilha;

Pilha *listaPilhas = NULL;

void erro(const char *mensagem) {
    printf("%s\n", mensagem);
    // Liberar tudo antes de sair
    Pilha *p = listaPilhas;
    while (p != NULL) {
        Elemento *e = p->topo;
        while (e != NULL) {
            Elemento *temp = e;
            e = e->proximo;
            free(temp);
        }
        Pilha *tempP = p;
        p = p->proxima;
        free(tempP);
    }
    exit(0);
}

Pilha *buscarPilha(const char *nome) {
    Pilha *atual = listaPilhas;
    while (atual != NULL) {
        if (strcmp(atual->nome, nome) == 0)
            return atual;
        atual = atual->proxima;
    }
    return NULL;
}

void inicializarPilha(const char *nome) {
    Pilha *nova = malloc(sizeof(Pilha));
    strcpy(nova->nome, nome);
    nova->topo = NULL;
    nova->proxima = listaPilhas;
    listaPilhas = nova;
}

void empilhar(const char *nome, int valor) {
    Pilha *p = buscarPilha(nome);
    if (p == NULL) {
        char msg[100];
        snprintf(msg, sizeof(msg), "Pilha %s nao encontrada!", nome);
        erro(msg);
    }

    Elemento *novo = malloc(sizeof(Elemento));
    novo->valor = valor;
    novo->proximo = p->topo;
    p->topo = novo;
}

void desempilhar(const char *nome) {
    Pilha *p = buscarPilha(nome);
    if (p == NULL) {
        char msg[100];
        snprintf(msg, sizeof(msg), "Pilha %s nao encontrada!", nome);
        erro(msg);
    }
    if (p->topo == NULL) {
        char msg[100];
        snprintf(msg, sizeof(msg), "Pilha %s vazia!", nome);
        erro(msg);
    }

    Elemento *remover = p->topo;
    p->topo = p->topo->proximo;
    free(remover);
}

void topoPilha(const char *nome) {
    Pilha *p = buscarPilha(nome);
    if (p == NULL) {
        char msg[100];
        snprintf(msg, sizeof(msg), "Pilha %s nao encontrada!", nome);
        erro(msg);
    }
    if (p->topo == NULL) {
        char msg[100];
        snprintf(msg, sizeof(msg), "Pilha %s vazia!", nome);
        erro(msg);
    }
    printf("%d\n", p->topo->valor);
}

void print(const char *nome) {
    Pilha *p = buscarPilha(nome);
    if (p == NULL) {
        char msg[100];
        snprintf(msg, sizeof(msg), "Pilha %s nao encontrada!", nome);
        erro(msg);
    }

    printf("[");
    Elemento *e = p->topo;
    while (e != NULL) {
        printf("%d", e->valor);
        if (e->proximo != NULL)
            printf(", ");
        e = e->proximo;
    }
    printf("]\n");
}

void SplitPilha(const char *nome, const char *novoNome, int k) {
    Pilha *origem = buscarPilha(nome);
    if (origem == NULL) {
        char msg[100];
        snprintf(msg, sizeof(msg), "Pilha %s nao encontrada!", nome);
        erro(msg);
    }

    Elemento *temporario = NULL;
    for (int i = 0; i < k && origem->topo != NULL; i++) {
        Elemento *remover = origem->topo;
        origem->topo = remover->proximo;
        remover->proximo = temporario;
        temporario = remover;
    }

    Pilha *nova = malloc(sizeof(Pilha));
    strcpy(nova->nome, novoNome);
    nova->topo = NULL;
    nova->proxima = listaPilhas;
    listaPilhas = nova;

    while (temporario != NULL) {
        Elemento *prox = temporario->proximo;
        temporario->proximo = nova->topo;
        nova->topo = temporario;
        temporario = prox;
    }
}

void show() {
    Pilha *p = listaPilhas;
    while (p != NULL) {
        printf("%s: [", p->nome);
        Elemento *e = p->topo;
        while (e != NULL) {
            printf("%d", e->valor);
            if (e->proximo != NULL)
                printf(", ");
            e = e->proximo;
        }
        printf("]\n");
        p = p->proxima;
    }
}

void MergePilhas(const char *nomeA, const char *nomeB) {
    Pilha *a = buscarPilha(nomeA);
    Pilha *b = buscarPilha(nomeB);
    if (a == NULL || b == NULL) {
        erro("Erro: pilhas nao encontradas!");
    }

    if (a == b) return;

    if (b->topo == NULL) {
        Pilha **pp = &listaPilhas;
        while (*pp != NULL) {
            if (*pp == b) {
                *pp = b->proxima;
                free(b);
                return;
            }
            pp = &(*pp)->proxima;
        }
    }

    Elemento *ultimoB = b->topo;
    while (ultimoB->proximo != NULL)
        ultimoB = ultimoB->proximo;

    ultimoB->proximo = a->topo;
    a->topo = b->topo;

    Pilha **pp = &listaPilhas;
    while (*pp != NULL) {
        if (*pp == b) {
            *pp = b->proxima;
            free(b);
            break;
        }
        pp = &(*pp)->proxima;
    }
}



int main() {
    int n;
    char linha[TAM_LINHA];

    if (scanf("%d\n", &n) != 1 || n < 1 || n > 100)
        erro("Numero de operacoes invalido!");

    for (int i = 0; i < n; i++) {
        fgets(linha, TAM_LINHA, stdin);
        linha[strcspn(linha, "\n")] = 0;

        if (strstr(linha, ":INIT")) {
            char nome[TAM_NOME];
            sscanf(linha, "%[^:]:INIT", nome);
            inicializarPilha(nome);
        } else if (strstr(linha, ":PUSH")) {
            char nome[TAM_NOME];
            int valor;
            sscanf(linha, "%[^:]:PUSH %d", nome, &valor);
            empilhar(nome, valor);
        } else if (strstr(linha, ":POP")) {
            char nome[TAM_NOME];
            sscanf(linha, "%[^:]:POP", nome);
            desempilhar(nome);
        } else if (strstr(linha, ":TOP")) {
            char nome[TAM_NOME];
            sscanf(linha, "%[^:]:TOP", nome);
            topoPilha(nome);
        } else if (strstr(linha, ":PRINT")) {
            char nome[TAM_NOME];
            sscanf(linha, "%[^:]:PRINT", nome);
            print(nome);
        } else if (strncmp(linha, "MERGE", 5) == 0) {
            char a[TAM_NOME], b[TAM_NOME];
            sscanf(linha, "MERGE %s %s", a, b);
            MergePilhas(a, b);
        } else if (strncmp(linha, "SPLIT", 5) == 0) {
            char nome[TAM_NOME], novo[TAM_NOME];
            int k;
            sscanf(linha, "SPLIT %s %s %d", nome, novo, &k);
            SplitPilha(nome, novo, k);
        } else if (strcmp(linha, "SHOW") == 0) {
            show();
        } else {
            erro("Comando invalido!");
        }
    }

    // Libera memoria ao final
    Pilha *p = listaPilhas;
    while (p != NULL) {
        Elemento *e = p->topo;
        while (e != NULL) {
            Elemento *temp = e;
            e = e->proximo;
            free(temp);
        }
        Pilha *tempP = p;
        p = p->proxima;
        free(tempP);
    }

    return 0;
}
