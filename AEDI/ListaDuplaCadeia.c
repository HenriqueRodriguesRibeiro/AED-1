#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_DESC 51

typedef struct Node {
    int codigo;
    char descricao[MAX_DESC];
    struct Node* next;
    struct Node* prev;
} Node;

// Funções da lista
Node* createNode(int codigo, char* descricao) {
    Node* newNode = (Node*)malloc(sizeof(Node));
    if (newNode == NULL) return NULL;
    
    newNode->codigo = codigo;
    strncpy(newNode->descricao, descricao, MAX_DESC);
    newNode->descricao[MAX_DESC - 1] = '\0';
    newNode->next = newNode;
    newNode->prev = newNode;
    return newNode;
}

void insertEnd(Node** head, int codigo, char* descricao) {
    Node* newNode = createNode(codigo, descricao);
    if (*head == NULL) {
        *head = newNode;
        return;
    }
    
    Node* last = (*head)->prev;
    newNode->next = *head;
    (*head)->prev = newNode;
    newNode->prev = last;
    last->next = newNode;
}

int removeNode(Node** head, int codigo) {
    if (*head == NULL) return 0;

    Node* current = *head;
    do {
        if (current->codigo == codigo) {
            if (current->next == current) {
                free(current);
                *head = NULL;
            } else {
                current->prev->next = current->next;
                current->next->prev = current->prev;
                if (current == *head) {
                    *head = current->next;
                }
                free(current);
            }
            return 1;
        }
        current = current->next;
    } while (current != *head);
    
    return 0;
}

Node* searchNode(Node* head, int codigo) {
    if (head == NULL) return NULL;

    Node* current = head;
    do {
        if (current->codigo == codigo) {
            return current;
        }
        current = current->next;
    } while (current != head);
    
    return NULL;
}

void printForward(Node* head) {
    if (head == NULL) {
        printf("Lista vazia!\n");
        return;
    }

    Node* current = head;
    do {
        printf("Codigo: %d - %s\n", current->codigo, current->descricao);
        current = current->next;
    } while (current != head);
}

void printReverse(Node* head) {
    if (head == NULL) {
        printf("Lista vazia!\n");
        return;
    }

    Node* current = head->prev;
    Node* start = current;
    
    do {
        printf("Codigo: %d - %s\n", current->codigo, current->descricao);
        current = current->prev;
    } while (current != start);
}

void freeList(Node** head) {
    if (*head == NULL) return;

    Node* current = (*head)->next;
    Node* nextNode;

    while (current != *head) {
        nextNode = current->next;
        free(current);
        current = nextNode;
    }

    free(*head);
    *head = NULL;
}

int main() {
    int N, codigo;
    char linha[100], comando[20], descricao[MAX_DESC];
    int comandos_lidos = 0;
    Node* head = NULL;

    if (scanf("%d", &N) != 1 || N < 1 || N > 100) {
        printf("N nao e valido!\n");
        return 0;
    }
    getchar();

    while (fgets(linha, sizeof(linha), stdin)) {
        comandos_lidos++;
        if (comandos_lidos > N) {
            printf("Numero de comandos superior a N!\n");
            break;
        }

        linha[strcspn(linha, "\n")] = 0;

        if (strncmp(linha, "ADD", 3) == 0) {
            if (sscanf(linha + 4, "%d %[^\n]", &codigo, descricao) == 2) {
                if (searchNode(head, codigo) != NULL) {
                    printf("Codigo ja existente!\n");
                } else {
                    insertEnd(&head, codigo, descricao);
                }
            }
        } 
        else if (strncmp(linha, "REMOVE", 6) == 0) {
            if (sscanf(linha + 7, "%d", &codigo) == 1) {
                if (!removeNode(&head, codigo)) {
                    printf("Codigo nao encontrado!\n");
                }
            }
        } 
        else if (strcmp(linha, "PRINT_FORWARD") == 0) {
            printForward(head);
        } 
        else if (strcmp(linha, "PRINT_REVERSE") == 0) {
            printReverse(head);
        } 
        else if (strncmp(linha, "SEARCH", 6) == 0) {
            if (sscanf(linha + 7, "%d", &codigo) == 1) {
                Node* found = searchNode(head, codigo);
                if (found != NULL) {
                    printf("Codigo: %d - %s\n", found->codigo, found->descricao);
                } else {
                    printf("Codigo nao encontrado!\n");
                }
            }
        }
    }

    if (comandos_lidos < N) {
        printf("N superior ao numero de comandos!\n");
    }

    freeList(&head);
    return 0;
}