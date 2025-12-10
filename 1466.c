/* 
    NOME: Henrique Rodrigues Ribeiro
    RA: 176515
    
   
*/

#include <stdio.h>
#include <stdlib.h>

typedef struct Node {
    int value;
    struct Node* left;
    struct Node* right;
} Node;

// Função para criar um novo nó
Node* createNode(int value) {
    Node* newNode = (Node*)malloc(sizeof(Node));
    newNode->value = value;
    newNode->left = NULL;
    newNode->right = NULL;
    return newNode;
}

// Função para inserir um valor na BST
Node* insert(Node* root, int value) {
    if (root == NULL) {
        return createNode(value);
    }
    
    if (value < root->value) {
        root->left = insert(root->left, value);
    } else if (value > root->value) {
        root->right = insert(root->right, value);
    }
    
    return root;
}

// Função para percurso por nível (BFS)
void levelOrderTraversal(Node* root, int caseNumber) {
    if (root == NULL) return;
    
    // Array para simular uma fila
    Node* queue[500];
    int front = 0, rear = 0;
    
    printf("Case %d:\n", caseNumber);
    
    // Enfileira a raiz
    queue[rear++] = root;
    
    int first = 1; // Flag para controlar espaços
    
    while (front < rear) {
        Node* current = queue[front++];
        
        // Imprime o valor do nó atual
        if (first) {
            printf("%d", current->value);
            first = 0;
        } else {
            printf(" %d", current->value);
        }
        
        // Enfileira os filhos
        if (current->left != NULL) {
            queue[rear++] = current->left;
        }
        if (current->right != NULL) {
            queue[rear++] = current->right;
        }
    }
    
    printf("\n");
}

// Função para liberar a memória da árvore
void freeTree(Node* root) {
    if (root == NULL) return;
    
    freeTree(root->left);
    freeTree(root->right);
    free(root);
}

int main() {
    int C;
    scanf("%d", &C);
    
    for (int caseNum = 1; caseNum <= C; caseNum++) {
        int N;
        scanf("%d", &N);
        
        Node* root = NULL;
        
        // Ler os N números e construir a BST
        for (int i = 0; i < N; i++) {
            int value;
            scanf("%d", &value);
            root = insert(root, value);
        }
        
        // Fazer o percurso por nível
        levelOrderTraversal(root, caseNum);
        
        // Linha em branco após cada caso (inclusive o último)
        printf("\n");
        
        // Liberar memória da árvore
        freeTree(root);
    }
    
    return 0;
}