/* 
    NOME: Henrique Rodrigues Ribeiro
    RA: 176515
   
*/


#include <stdio.h>
#include <string.h>

int main(){
    char expressao[1001];
    int N, tam, diamante, metade;

    scanf("%d", &N);
    for(int j = 0; j < N; j++){
        scanf("%s\n", &expressao);

        diamante = 0;
        metade = 0;
        tam = strlen(expressao);

        for(int i = 0; i < tam; i++){
            if(expressao[i] == '<'){
                metade++;
            }else if(expressao[i] == '>' && metade > 0){
                metade--;
                diamante++;
            }
        }
        printf("%d\n", diamante);
    }
    return 0; 
}