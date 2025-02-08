/* 
    NOME: Henrique Rodrigues Ribeiro
    RA: 176515
    Turma: IA
   
*/

#include <string.h>
#include <stdio.h>
#include <ctype.h>

int main(){
    char S[101];
    int n, erro, letras_Mai, letras_Min, numeral;

    while(gets(S) != NULL){
        n = strlen(S);

        if(n < 6 || n > 32){
            printf("Senha invalida.\n");
            continue;
        }

        erro = 0, letras_Mai = 0, letras_Min = 0, numeral = 0;

        for(int i = 0; i < n; ++i){
            if(isalpha(S[i])){
                if(S[i] == tolower(S[i]))   letras_Min = 1;
                else                        letras_Mai = 1;
            }else if(isdigit(S[i]))         numeral = 1;
            else{
                erro = 1;
                break;
            }
        }

        if(erro || !(letras_Mai && letras_Min && numeral)){
            printf("Senha invalida.\n");
        }else{
            printf("Senha valida.\n");
        }
    }

    return 0;
}