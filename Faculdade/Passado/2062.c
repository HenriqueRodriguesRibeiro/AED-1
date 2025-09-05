/* 
    NOME: Henrique Rodrigues Ribeiro
    RA: 176515
    Turma: IA
   
*/

#include <string.h>
#include <stdio.h>

int main(){
    int N;
    char frase[21];
    scanf("%d\n", &N);

    for(int i = 0; i < N; ++i){
        scanf("%s", &frase);

        if(i)   printf(" ");

        if(strlen(frase) == 3){
            if(frase[0] == 'O' && frase[1] == 'B')
                printf("OBI");
            else if(frase[0] == 'U' && frase[1] == 'R')
                printf("URI");
            else
                printf("%s", frase);
        }else{
            printf("%s", frase);
        }
    }
    printf("\n");
    return 0;
}