/* NOME: Henrique Rodrigues Ribeiro
   RA: 176515
   Turma: IA
   
   Exercício 1020
    Idade em Dias
   Leia um valor inteiro correspondente à idade de uma pessoa em dias e informe-a em anos, meses e dias 
*/

#include <stdio.h>

int main() {

int idade,anos,meses,dias;

//entrada
scanf("%d",&idade);

//processamento
anos = idade/365;
meses = (idade%365)/30;
dias = (idade%365)%30;

//saida
printf("%d anos\n%d meses\n%d dias\n",anos,meses,dias);
return 0;
}