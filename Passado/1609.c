/* 
    NOME: Henrique Rodrigues Ribeiro
    RA: 176515
    Turma: IA
   
*/

#include <string.h>
#include <stdlib.h>
#include <stdio.h>

int comp(const void* a, const void* b){
    return *(int*)a - *(int*)b;
}

int main(){
    int T, N, resp;
    int carneiros[10000];
    scanf("%d", &T);

    for(int i = 0; i < T; i++){
        scanf("%d", &N);
        resp = 1;
        memset(carneiros, 0, sizeof(carneiros));

        for(int j = 0; j < N; j++){
            scanf("%d", &carneiros[j]);
        }
        qsort(carneiros, N, sizeof(int), comp);

        for(int j = 1; j < N; j++){
            if(carneiros[j - 1] != carneiros[j]){
                resp++;
            }
        }

        printf("%d\n", resp);
    }
    return 0;
}