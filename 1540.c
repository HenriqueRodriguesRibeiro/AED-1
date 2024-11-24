#include <stdio.h>
#include <math.h>

double pa(double, double, unsigned short);

double pa(double a1, double an, unsigned short posicao)
{
	// Simples caso de PA;
	return ((an - a1) / posicao); 

}

void main(){
    unsigned short testes;
    unsigned short ano1, anoFim;
    double Ci, Cf, resultado, fracao;
    int inteiro;
    scanf("%hu", &testes);

    while(testes--){
        scanf("%hu %lf %hu %lf", &ano1, &Ci, &anoFim, &Cf);

        resultado = pa(Ci, Cf, (anoFim - ano1));

        inteiro = resultado;

        fracao = trunc((resultado - inteiro)*100);
        printf("%d,%02.f\n", inteiro, fracao);
    }
}

