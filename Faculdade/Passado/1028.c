/* 
    NOME: Henrique Rodrigues Ribeiro
    RA: 176515
    Turma: IA
   
*/

#include <stdio.h>

void main(){
    int ricardo, vicente;
    int resultado = 0;
    int casos;

    scanf("%d", &casos);
    while (casos--)
    {
        scanf("%d %d", &ricardo, &vicente);
        while (vicente != 0)
        {
            resultado = ricardo % vicente;
            ricardo = vicente;
            vicente = resultado;
        }
        printf("%d\n", ricardo);
    }
    
}