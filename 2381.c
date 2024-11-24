/* NOME: Henrique Rodrigues Ribeiro
   RA: 176515
   Turma: IA
   
*/

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// Essa função é um comparador utilizado pela função qsort.
//Ela recebe dois ponteiros para void como parâmetros, que na prática serão ponteiros para as strings que estão sendo comparadas.
int comparacao(const void* a, const void* b){
    return strcmp((char*)a, (char*)b);
}

int main(void){
    int posi, N;
    char alunos[200][50];

    scanf("%d %d\n", &N, &posi);

    for(int i = 0; i < N; i++){
        scanf("%s", &alunos[i]);
    }

    qsort(alunos, N, sizeof(char)*50, comparacao);
    printf("%s\n", &alunos[posi - 1]);

    return 0;
}

/*
 posi : Armazena a posição do nome a ser impresso
 N : Armazena o Numero de nomes
 alunos: uma matriz de caracteres bidimensional para armazenar os nomes
 */