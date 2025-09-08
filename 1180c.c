/* 
    NOME: Henrique Rodrigues Ribeiro
    RA: 176515
   
*/

#include <stdio.h>
#include <stdlib.h>

int main() {
    int n;
    scanf("%d", &n);
    
    // Alocar memória dinamicamente para o vetor
    int *x = (int*)malloc(n * sizeof(int));
    
    if (x == NULL) {
        printf("Erro de alocacao de memoria!\n");
        return 1;
    }
    
    // Ler os valores usando ponteiros
    int *ptr = x;
    for (int i = 0; i < n; i++) {
        scanf("%d", ptr);
        ptr++;
    }
    
    // Encontrar o menor valor e sua posição usando ponteiros
    int menor = *x;
    int posicao = 0;
    
    ptr = x;
    for (int i = 0; i < n; i++) {
        if (*ptr < menor) {
            menor = *ptr;
            posicao = i;
        }
        ptr++;
    }
    
    printf("Menor valor: %d\n", menor);
    printf("Posicao: %d\n", posicao);
    
    // Liberar memória alocada
    free(x);
    
    return 0;
}