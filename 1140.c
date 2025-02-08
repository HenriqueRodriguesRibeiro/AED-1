/* 
    NOME: Henrique Rodrigues Ribeiro
    RA: 176515
    Turma: IA
   
*/

#include <stdio.h>
#include <stdbool.h>
#include <string.h>
#include <ctype.h>

typedef struct{

	char palavra[21];

} string;

bool isTautograma(string *, unsigned short tam);

void main ()
{

	unsigned short i;

	while (true)
	{

		char frase[2000] = { 0 }, *temp;
		string palavras[100];

		scanf(" %[^\n]", frase);

		if (strcmp(frase, "*") == 0)
			break;

		i = 0;
		temp = strtok(frase, " ");
		strcpy(palavras[i++].palavra, temp);

		do
		{

			temp = strtok('\0', " ");

			if (temp)
				strcpy(palavras[i++].palavra, temp);

		} while (temp);

		// Resultado final;
		if (isTautograma(palavras, i))
			printf("Y\n");
		else
			printf("N\n");

	}

}

bool isTautograma(string *palavras, unsigned short tam)
{

	unsigned short i;

	for (i = 1; i < tam; i++)
		if (tolower(palavras[i].palavra[0]) != tolower(palavras[i - 1].palavra[0]))
			return false;

	return true;

}