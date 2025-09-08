/* 
    NOME: Henrique Rodrigues Ribeiro
    RA: 176515
   
*/

#include <stdio.h>

int main() {
    int n;
    scanf("%d", &n);
    
    int menor, posicao, valor;
    
    // Ler o primeiro valor
    scanf("%d", &valor);
    menor = valor;
    posicao = 0;
    
    // Ler os valores restantes e encontrar o menor
    for (int i = 1; i < n; i++) {
        scanf("%d", &valor);
        
        if (valor < menor) {
            menor = valor;
            posicao = i;
        }
    }
    
    printf("Menor valor: %d\n", menor);
    printf("Posicao: %d\n", posicao);
    
    return 0;
}