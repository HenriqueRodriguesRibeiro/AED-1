/* 
    NOME: Henrique Rodrigues Ribeiro
    RA: 176515
    Turma: IA
   
*/

#include <stdio.h>

int main(){
    char pulo;
    int N, T, acertos, tentativas[50];
    scanf("%d", &N);

    for(int k = 0; k < N; ++k){
        scanf("%d", &T);

        for(int i = 0; i < T; ++i){
            scanf("%d", &tentativas[i]);
        }
        scanf("\n", &pulo);
        acertos = 0;

        for(int i = 0; i < T; ++i){
            scanf("%c", &pulo);

            if((pulo == 'S' && tentativas[i] < 3) || (pulo == 'J' && tentativas[i] > 2)){
                ++acertos;
            }
        }
        printf("%d\n", acertos);
    }
    return 0;
}