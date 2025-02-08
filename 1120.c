/* 
    NOME: Henrique Rodrigues Ribeiro
    RA: 176515
    Turma: IA
   
*/

#include <stdio.h>
#include <stdbool.h>
#include <string.h>

void validaDefeito(char *, char);
void validaZeros(char *, char *);

void main ()
{

    unsigned short i, j;
    char numero[300], num_erro;
    char numeroSemZero[300];

    while (true)
    {

        scanf(" %c %s", &num_erro, numero);

        if (num_erro == '0' && (strcmp(numero, "0") == 0))
            break;

        // Função substitui todas as ocorrências do número defeituoso na string
        // Por um caractere não numérico;
        validaDefeito(numero, num_erro);

        // Função retira todos os zeros nas posições não significativas da string
        // ou seja, qualquer zero do lado esquerdo da string;
        validaZeros(numero, numeroSemZero);

        // Se a string de retorno tiver tamanho 0, quer dizer que tudo foi tirado e nada sobrou
        // Por isso, imprime o valor 0;
        if (!strlen(numeroSemZero))
            printf("0\n");
        else
            printf("%s\n", numeroSemZero);

        memset(numero, 0, sizeof(numero));
        memset(numeroSemZero, 0, sizeof(numeroSemZero));

    }

}

// Função retira todas as ocorrências do digito defeituoso;
void validaDefeito(char *numero, char num_erro)
{

    unsigned short i;

    i = 0;
    while (numero[i])
    {

        if (numero[i] == num_erro)
            numero[i] = 'A';
        i++;

    }

}

// Função retira todos os zeros e caracteres não numéricos da string;
void validaZeros(char *numero, char *numeroSemZero)
{

    unsigned short i, j;
    char aux[300] = { 0 };

    i = j = 0;
    while (numero[i])
    {

        // Enquanto houver caracteres na string 'numero'
        // Passe tudo que estiver na posição 'i' e não for o caracter 'A'
        // Para a string temporária;
        if (numero[i] != 'A')
            aux[j++] = numero[i];

        i++;
    }

    // Se 'j' for 0, quer dizer que não tinha nada para passar à string temporária;
    // Salvo o caracter zero na posição 'j' para forçar a entrada no próximo laço;
    if (j == 0)
        aux[j] = '0';

    i = j = 0;
    // Enquanto o caracter na posição 'i' for o 0, só avance pela string;
    while (aux[i] == '0')
        i++;

    // Se saiu do laço anterior, foi porque encontrou um caracter diferente do 0;
    // Passe o que sobrou, enquanto houver caracteres na string temporária
    // para a string de saída;
    while (aux[i])
        numeroSemZero[j++] = aux[i++];

    // Salva um caracter nulo ao final da string;
    numeroSemZero[j] = '\0';

}