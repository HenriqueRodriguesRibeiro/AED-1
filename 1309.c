/* 
    NOME: Henrique Rodrigues Ribeiro
    RA: 176515
    Turma: IA
   
*/

#include <stdio.h>
#include <string.h>
#include <ctype.h>

void inverte(char *);

void main ()
{

	char qtdStr[100], num_vir[100];
	short i, j, contador;
	unsigned short moeda;
	unsigned numeroInt;

	while (scanf("%u %hu", &numeroInt, &moeda) != EOF)
	{

		// Passa um número inteiro para uma string;
		// Fazer isso, descarta quaisquer 0's no começo do número;
		sprintf(qtdStr, "%u", numeroInt);

		contador = 0;
		i = strlen(qtdStr) - 1;

		// Se for só uma string com o caracter '0'
		// Simplesmente imprima o resultado;
		if (strcmp(qtdStr, "0") == 0)
			printf("$0.%02hu\n", moeda);
		else
		{

			j = 0;
			while (i >= 0)
			{

				// A cada 3 numeros, imprima uma vírgula;
				if (contador % 3 == 0 && contador != 0)
					num_vir[j++] = ',';

				// Enquanto isso, passe o que tem na string qtdStr
				// para a string num_vir;
				num_vir[j++] = qtdStr[i--];

				contador++;
			}

			// Coloca o caractere de final de string;
			num_vir[j] = '\0';
			// Inverte a string de saída
			// Isso é necessário porque a string é preenchida de trás para frente;
			inverte(num_vir);

			printf("$%s.%02hu\n", num_vir, moeda);

			// Reseta o conteúdo das strings para a próxima iteração;
			memset(qtdStr, 0, sizeof(qtdStr));
			memset(num_vir, 0, sizeof(num_vir));

		}

	}

}

void inverte(char *numero)
{

	unsigned short i;
	short inicio, fim, meio;
	char aux;

	inicio = 0;
	fim = strlen(numero) - 1;
	meio = (strlen(numero) / 2) - 1;
	while (inicio <= meio)
	{

	    aux = numero[inicio];
	    numero[inicio] = numero[fim];
	    numero[fim] = aux;

	    inicio++;
	    fim--;

  	}

}