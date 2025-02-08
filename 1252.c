/* 
    NOME: Henrique Rodrigues Ribeiro
    RA: 176515
    Turma: IA
   
*/

#include <stdio.h>
#include <stdlib.h>

int n, m;
int comparar(int *, int *);

void main(){
    int vetor[10100];
    int i;
    
    while (scanf("%d %d", &n, &m), n)
    {
        for(i = 0; i < n; i++)
            scanf("%d", &vetor[i]);

        qsort(vetor, n, sizeof(int), comparar);
        printf("%d %d\n", n, m);
        for(i = 0; i < n; i++)
            printf("%d\n", vetor[i]);    
    }
    printf("%d %d\n", n, m);
}

int comparar(int *a, int *b){
    if(*a % m == *b % m){
        if((*a & 1) && !(*b & 1)) return -1;
        else if(!(*a & 1) && !(*b & 1)) return 1;
        else if((*a & 1) && (*b & 1)){
            if (*a > *b)
                return -1;
            else 
                return 1;
        }
        else if(!(*a & 1) && !(*b & 1)){
            if (*a > *b)
                return 1;
            else 
                return -1;
        }
    }
    else if (*a % m > *b % m)
		return 1;
	else
		return -1;
}