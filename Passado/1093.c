/* 
    NOME: Henrique Rodrigues Ribeiro
    RA: 176515
    Turma: IA
   
*/

#include <stdio.h>
#include <math.h>

double solve(int, int, int);

int main(int argc, char **argv)
{

    double prob;
    int vital1, vital2, ataque, d, temp;

    while (scanf("%d %d %d %d", &vital1, &vital2, &ataque, &d), vital1 && vital2 && ataque && d)
    {

        temp = vital1;
        vital1 = 0;
        while (temp > 0)
            temp -= d, ++vital1;

        temp = vital2;
        vital2 = 0;
        while (temp > 0)
            temp -= d, ++vital2;

        prob = solve(vital1, vital2, ataque);
        printf("%.1f\n", prob * 100);
    }

    return 0;
}

double solve(int n1, int n2, int ataque)
{

    if (ataque == 3)
        return (double)n1 / (double)(n1 + n2);
    else
    {

        double p;
        p = 1.0 - (6 - ataque) / 6.0;
        p = (1 - p) / p;
        return (1.0 - pow(p, n1)) / (1.0 - pow(p, n1 + n2));
    }
}