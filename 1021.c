/* 
    NOME: Henrique Rodrigues Ribeiro
    RA: 176515
    Turma: IA
   
*/

#include <stdio.h>
#include <math.h>

int main() {
    double nota;

    unsigned int total, fracao;

    scanf("%lf", &nota);

    total = (int) nota;
    nota -= total;

    fracao = round((nota * 100));

    printf("NOTAS:\n");
    printf("%d nota(s) de R$ 100.00\n", total / 100);

    total -= (total / 100) * 100;

    if (total > 50) {
        printf("1 nota(s) de R$ 50.00\n");
        total -= 50;
    } else {
        printf("0 nota(s) de R$ 50.00\n");
    }

    printf("%d nota(s) de R$ 20.00\n", total / 20);

    total -= (total / 20) * 20;
    printf("%d nota(s) de R$ 10.00\n", total / 10);

    total -= (total / 10) * 10;
    printf("%d nota(s) de R$ 5.00\n", total / 5);

    total -= (total / 5) * 5;
    printf("%d nota(s) de R$ 2.00\n", total / 2);

    printf("MOEDAS:\n");
    total -= (total / 2) * 2;
    printf("%d moeda(s) de R$ 1.00\n", total);

    if (fracao > 50) {
        printf("1 moeda(s) de R$ 0.50\n");
        fracao -= 50;
    } else {
        printf("0 moeda(s) de R$ 0.50\n");
    }

    printf("%d moeda(s) de R$ 0.25\n", fracao / 25);

    fracao -= (fracao / 25) * 25;
    printf("%d moeda(s) de R$ 0.10\n", fracao / 10);

    fracao -= (fracao / 10) * 10;
    printf("%d moeda(s) de R$ 0.05\n", fracao / 5);

    fracao -= (fracao / 5) * 5;
    printf("%d moeda(s) de R$ 0.01\n", fracao);

    return 0;
}