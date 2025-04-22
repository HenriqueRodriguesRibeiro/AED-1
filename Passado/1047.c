/* 
    NOME: Henrique Rodrigues Ribeiro
    RA: 176515
    Turma: IA
   
*/ 

#include <stdio.h>

int main(){
    int hora_ini, hora_fim, min_ini, min_fim;
    int dura_hora, duracao, dura_min;

    scanf("%d %d %d %d", &hora_ini, &min_ini, &hora_fim, &min_fim);

    if(hora_fim == hora_ini && min_fim == min_ini){
        printf("O JOGO DUROU 24 HORA(S) E 0 MINUTO(S)\n");
    } else{
        duracao = (hora_fim*60 + min_fim) -(hora_ini*60 + min_ini);

        if (duracao < 0){
            duracao += 24 * 60;
        }
        
        dura_hora = duracao/60;
        dura_min = duracao%60;

        printf("O JOGO DUROU %d HORA(S) E %d MINUTO(S)\n", dura_hora, dura_min);
    }
    return 0;
}