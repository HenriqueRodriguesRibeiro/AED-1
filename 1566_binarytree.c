/* 
    NOME: Henrique Rodrigues Ribeiro
    RA: 176515
   
*/

#include <stdio.h>
#include <stdlib.h>

typedef struct Node {
    int key;
    struct Node *left, *right;
} Node;

Node* insert(Node *root, int key) {
    if (root == NULL) {
        root = (Node*) malloc(sizeof(Node));
        root->key = key;
        root->left = NULL;
        root->right = NULL;
        return root;
    }

    if (key < root->key) {
        root->left = insert(root->left, key);
    } else {
        root->right = insert(root->right, key);
    }

    return root;
}

void inorder(Node *root) {
    if (root == NULL)
        return;

    inorder(root->left);
    printf("%d ", root->key);
    inorder(root->right);
}

void freeTree(Node *root) {
    if (root == NULL)
        return;
    freeTree(root->left);
    freeTree(root->right);
    free(root);
}

int main() {
    int NC;
    scanf("%d", &NC);

    while (NC--) {
        int N;
        scanf("%d", &N);

        Node *root = NULL;

        for (int i = 0; i < N; i++) {
            int h;
            scanf("%d", &h);
            root = insert(root, h);
        }

        inorder(root);
        printf("\n");

        freeTree(root);
    }

    return 0;
}
