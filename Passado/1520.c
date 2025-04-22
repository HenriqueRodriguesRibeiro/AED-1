/* 
    NOME: Henrique Rodrigues Ribeiro
    RA: 176515
    Turma: IA
   
*/

#include <stdio.h>
#include <stdlib.h>
#define true 1;
#define false 0;

int main(){
    int junta;
    int vet[101];
    int x, y, inicio, fim, item;

    while(item != EOF)
    {
        memset(vet, 0, sizeof(vet));
        for (y = 0; y < item; y++)
        {
            scanf("%d %d", &inicio, &fim);
            for (x = inicio; x <= fim; x++)
                vet[x]++;
        }
        
        junta = 0;
        scanf("%d", &y);
        if(vet[y]){
            for (x = 1; x < y; x++)
                junta += vet[x];
            printf("%d found from %d to %d\n", &y, &junta, (junta + vet[x] - 1));    
        }
        else{
            printf("%d not found\n", &y);
        }
    }
    return 0;
}