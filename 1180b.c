/* 
    NOME: Henrique Rodrigues Ribeiro
    RA: 176515
   
*/

#include <stdio.h>

int main() {
    int n;
    scanf("%d", &n);
    
    int x[n];
    
    // Ler os valores do vetor
    for (int i = 0; i < n; i++) {
        scanf("%d", &x[i]);
    }
    
    // Encontrar o menor valor e sua posição
    int menor = x[0];
    int posicao = 0;
    
    for (int i = 1; i < n; i++) {
        if (x[i] < menor) {
            menor = x[i];
            posicao = i;
        }
    }
    
    printf("Menor valor: %d\n", menor);
    printf("Posicao: %d\n", posicao);
    
    return 0;
}