/* 
    NOME: Henrique Rodrigues Ribeiro
    RA: 176515
    Turma: IA
   
*/

#include <stdio.h>

int main (){

int valor, resultado;
scanf("%d", &valor);


printf("%d\n", valor);
resultado = valor/100;
printf("%d valor(s) de R$ 100,00\n", resultado);
valor = valor % 100;

resultado = valor/50;
printf("%d valor(s) de R$ 50,00\n", resultado);
valor = valor % 50;

resultado = valor/20;
printf("%d valor(s) de R$ 20,00\n", resultado);
valor = valor % 20;

resultado = valor/10;
printf("%d valor(s) de R$ 10,00\n", resultado);
valor = valor % 10;

resultado = valor/5;
printf("%d valor(s) de R$ 5,00\n", resultado);
valor = valor % 5;

resultado = valor/2;
printf("%d valor(s) de R$ 2,00\n", resultado);
valor = valor % 2;

resultado = valor/1;
printf("%d valor(s) de R$ 1,00\n", resultado);

}