/* 
    NOME: Henrique Rodrigues Ribeiro
    RA: 176515
   
*/

#include <stdio.h>
#include <string.h>

#define MAX 1010

int main() {
    char expr[MAX];
    int pilha[MAX];
    int top, i, n, erro;

    while (fgets(expr, MAX, stdin) != NULL) {
        top = 0;     // pilha começa vazia
        erro = 0;     // 0 = ok, 1 = erro
        n = strlen(expr);

        for (i = 0; i < n; i++) {
            if (expr[i] == '(') {
                pilha[top] = '(';
                top++;
            }
            else if (expr[i] == ')') {
                if (top == 0) {
                    erro = 1; // tentativa de fechar sem abrir
                } else {
                    top--;   // desempilha
                }
            }
        }

        if (erro == 0 && top == 0) {
            printf("correct\n");
        } else {
            printf("incorrect\n");
        }
    }

    return 0;
}
