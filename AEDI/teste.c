#include <stdio.h>
#include <stdlib.h>
#include <string.h>
 
#define MAX_NAME 50
#define MAX_CMD 100
 
typedef struct stack_node {
    int valor;
    struct stack_node *prox;
} StackNode;
 
typedef struct {
    char nome[MAX_NAME];
    StackNode *topo;
} Pilha;
 
typedef struct pilha_node {
    Pilha pilha;
    struct pilha_node *prox;
} PilhaNode;
 
void initPilha(Pilha *p, const char *nome) {
    strncpy(p->nome, nome, MAX_NAME);
    p->topo = NULL;
}
 
StackNode* criarStackNode(int valor) {
    StackNode *novo = (StackNode*)malloc(sizeof(StackNode));
    novo->valor = valor;
    novo->prox = NULL;
    return novo;
}
 
PilhaNode* adicionarPilha(PilhaNode *head, const char *nome) {
    PilhaNode *novo = (PilhaNode*)malloc(sizeof(PilhaNode));
    initPilha(&novo->pilha, nome);
    novo->prox = head;
    return novo;
}
 
PilhaNode* encontrarPilha(PilhaNode *head, const char *nome) {
    PilhaNode *atual = head;
    while (atual != NULL) {
        if (strcmp(atual->pilha.nome, nome) == 0) {
            return atual;
        }
        atual = atual->prox;
    }
    return NULL;
}
 
void push(Pilha *p, int valor) {
    StackNode *novo = criarStackNode(valor);
    novo->prox = p->topo;
    p->topo = novo;
}
 
int pop(Pilha *p, int *erro) {
    if (p->topo == NULL) {
        *erro = 1;
        return 0;
    }
    
    StackNode *temp = p->topo;
    int valor = temp->valor;
    p->topo = p->topo->prox;
    free(temp);
    *erro = 0;
    return valor;
}
 
int top(Pilha *p, int *erro) {
    if (p->topo == NULL) {
        *erro = 1;
        return 0;
    }
    *erro = 0;
    return p->topo->valor;
}
 
void printPilha(Pilha *p) {
    if (p->topo == NULL) {
        printf("[]\n");
        return;
    }
    
    printf("[");
    StackNode *atual = p->topo;
    int primeiro = 1;
    
    while (atual != NULL) {
        if (!primeiro) {
            printf(", ");
        }
        printf("%d", atual->valor);
        atual = atual->prox;
        primeiro = 0;
    }
    printf("]\n");
}
 
void showPilhas(PilhaNode *head) {
    if (head == NULL) {
        printf("\n");
        return;
    }
    
    PilhaNode *atual = head;
    while (atual != NULL) {
        printf("%s: ", atual->pilha.nome);
        if (atual->pilha.topo == NULL) {
            printf("[]\n");
        } else {
            printf("[");
            StackNode *node = atual->pilha.topo;
            int primeiro = 1;
            while (node != NULL) {
                if (!primeiro) {
                    printf(", ");
                }
                printf("%d", node->valor);
                node = node->prox;
                primeiro = 0;
            }
            printf("]\n");
        }
        atual = atual->prox;
    }
}
 
PilhaNode* mergePilhas(PilhaNode *head, const char *nomeA, const char *nomeB, int *erro) {
    PilhaNode *nodeA = encontrarPilha(head, nomeA);
    PilhaNode *nodeB = encontrarPilha(head, nomeB);
    
    if (nodeA == NULL || nodeB == NULL || nodeA == nodeB) {
        *erro = 1;
        return head;
    }
    
    // Inverter a pilha B para manter a ordem correta
    StackNode *invertida = NULL;
    StackNode *atual = nodeB->pilha.topo;
    while (atual != NULL) {
        StackNode *novo = criarStackNode(atual->valor);
        novo->prox = invertida;
        invertida = novo;
        atual = atual->prox;
    }
    
    // Adicionar os elementos invertidos no topo da pilha A
    atual = invertida;
    while (atual != NULL) {
        push(&nodeA->pilha, atual->valor);
        StackNode *temp = atual;
        atual = atual->prox;
        free(temp);
    }
    
    // Remover a pilha B da lista
    PilhaNode *prev = NULL;
    PilhaNode *curr = head;
    while (curr != NULL) {
        if (curr == nodeB) {
            if (prev == NULL) {
                head = curr->prox;
            } else {
                prev->prox = curr->prox;
            }
            free(curr);
            break;
        }
        prev = curr;
        curr = curr->prox;
    }
    
    *erro = 0;
    return head;
}
 
PilhaNode* splitPilha(PilhaNode *head, const char *nome, const char *novoNome, int k, int *erro) {
    *erro = 0;
 
    PilhaNode *origNode = encontrarPilha(head, nome);
    if (origNode == NULL) {
        *erro = 1;
        return head;
    }
 
    // Se k for inválido (menor ou igual a 0), retornamos erro imediatamente
    if (k <= 0) {
        *erro = 1;
        return head;
    }
 
    // Contamos até k elementos ou até o fim da pilha
    StackNode *tempTop = NULL;
    int count = 0;
 
    while (count < k && origNode->pilha.topo != NULL) {
        int dummy;
        int valor = pop(&origNode->pilha, &dummy);
        StackNode *novo = criarStackNode(valor);
        novo->prox = tempTop;
        tempTop = novo;
        count++;
    }
 
    // Se não retirou nenhum elemento (pilha vazia ou k > 0 mas nada para retirar), erro
    if (count == 0) {
        *erro = 1;
        return head;
    }
 
    // Criar nova pilha com os elementos extraídos
    head = adicionarPilha(head, novoNome);
    PilhaNode *novaNode = encontrarPilha(head, novoNome);
 
    while (tempTop != NULL) {
        StackNode *temp = tempTop;
        push(&novaNode->pilha, tempTop->valor);
        tempTop = tempTop->prox;
        free(temp);
    }
 
    return head;
}
 
void liberarMemoria(PilhaNode *head) {
    PilhaNode *atual = head;
    while (atual != NULL) {
        PilhaNode *temp = atual;
        atual = atual->prox;
        
        while (temp->pilha.topo != NULL) {
            int dummy;
            pop(&temp->pilha, &dummy);
        }
        free(temp);
    }
}
 
int main() {
    int N;
    char linha[MAX_CMD];
    PilhaNode *head = NULL;
 
    do {
        scanf("%d", &N);
    } while (N < 1 || N > 100);
 
    fgets(linha, sizeof(linha), stdin);
 
 
    for (int i = 0; i < N; i++) {
        if (fgets(linha, sizeof(linha), stdin) == NULL) {
            printf("Erro ao ler comando.\n");
            liberarMemoria(head);
            return 1;
        }
        linha[strcspn(linha, "\n")] = '\0';
 
        char *token = strtok(linha, ":");
        if (token == NULL) continue;
 
        char nome[MAX_NAME];
        strncpy(nome, token, MAX_NAME);
 
        token = strtok(NULL, ":");
        if (token != NULL) {
            if (strcmp(token, "INIT") == 0) {
                if (encontrarPilha(head, nome) != NULL) {
                    printf("Erro: Pilha %s já existe.\n", nome);
                    liberarMemoria(head);
                    return 1;
                }
                head = adicionarPilha(head, nome);
            } else if (strncmp(token, "PUSH", 4) == 0) {
                PilhaNode *node = encontrarPilha(head, nome);
                if (node == NULL) {
                    printf("Pilha %s nao encontrada!\n", nome);
                    liberarMemoria(head);
                    return 1;
                }
                int valor = atoi(token + 5);
                push(&node->pilha, valor);
            } else if (strcmp(token, "POP") == 0) {
                PilhaNode *node = encontrarPilha(head, nome);
                if (node == NULL) {
                    printf("Pilha %s nao encontrada!\n", nome);
                    liberarMemoria(head);
                    return 1;
                }
                int erro;
                pop(&node->pilha, &erro);
                if (erro) {
                    printf("Pilha %s vazia!\n", nome);
                    liberarMemoria(head);
                    return 1;
                }
                if (node->pilha.topo == NULL) {
                    PilhaNode *prev = NULL, *curr = head;
                    while (curr != NULL) {
                        if (curr == node) {
                            if (prev == NULL) head = curr->prox;
                            else prev->prox = curr->prox;
                            free(curr);
                            break;
                        }
                        prev = curr;
                        curr = curr->prox;
                    }
                }
            } else if (strcmp(token, "TOP") == 0) {
                PilhaNode *node = encontrarPilha(head, nome);
                if (node == NULL) {
                    printf("Pilha %s nao encontrada!\n", nome);
                    liberarMemoria(head);
                    return 1;
                }
                int erro;
                int valor = top(&node->pilha, &erro);
                if (erro) {
                    printf("Pilha %s vazia!\n", nome);
                    liberarMemoria(head);
                    return 1;
                }
                printf("%d\n", valor);
            } else if (strcmp(token, "PRINT") == 0) {
                PilhaNode *node = encontrarPilha(head, nome);
                if (node == NULL) {
                    printf("Pilha %s nao encontrada!\n", nome);
                    liberarMemoria(head);
                    return 1;
                }
                printPilha(&node->pilha);
            }
        } else {
            if (strcmp(nome, "SHOW") == 0) {
                showPilhas(head);
            } else if (strncmp(nome, "MERGE", 5) == 0) {
                char nomeA[MAX_NAME], nomeB[MAX_NAME];
                if (sscanf(linha, "MERGE %s %s", nomeA, nomeB) != 2) {
                    printf("Erro: pilhas nao encontradas!\n");
                    liberarMemoria(head);
                    return 1;
                }
                int erro;
                head = mergePilhas(head, nomeA, nomeB, &erro);
                if (erro) {
                    printf("Erro: pilhas nao encontradas!\n");
                    liberarMemoria(head);
                    return 1;
                }
            } else if (strncmp(nome, "SPLIT", 5) == 0) {
                char nomeOrig[MAX_NAME], novoNome[MAX_NAME];
                int k;
                if (sscanf(linha, "SPLIT %s %s %d", nomeOrig, novoNome, &k) != 3) {
                    liberarMemoria(head);
                    return 1;
                }
                int erro;
                head = splitPilha(head, nomeOrig, novoNome, k, &erro);
                if (erro) {
                    printf("Pilha %s vazia!\n", nomeOrig);
                    liberarMemoria(head);
                    return 1;
                }
            }
        }
    }
 
    liberarMemoria(head);
    return 0;
}