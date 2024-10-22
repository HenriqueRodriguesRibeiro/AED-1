/* NOME: Henrique Rodrigues Ribeiro
   RA: 176515
   Turma: IA
   
   Exercício 1002
    Área do círculo
    A fórmula para calcular a área de uma circunferência é: area = π . raio2. Considerando para este problema que π = 3.14159:

    - Efetue o cálculo da área, elevando o valor de raio ao quadrado e multiplicando por π.
*/

#include <stdio.h>
#include <math.h>
#define PI 3.14159 

int main() {
    //Declaração de variaevis
    double raio, area;

    //Entrada de dados
    scanf("%lf", &raio);

    //Cálculo pedido
    area = PI * pow(raio,2);

    //Saida de dados
    printf("A=%.4lf\n",area);
    return 0;
}