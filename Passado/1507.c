/* 
    NOME: Henrique Rodrigues Ribeiro
    RA: 176515
    Turma: IA
   
*/

#include <stdio.h>
#include <stdbool.h>
#include <string.h>

bool isSubString(char *string1, char *string2);

void main ()
{

	unsigned short i, j;
	char string[100060];
	char subString[1100];
	unsigned short q_casos, q_strings;

	scanf("%hu", &q_casos);
	scanf("%s", string);

	for (i = 0; i < q_casos; ++i)
	{

		scanf("%hu", &q_strings);

		for (j = 0; j < q_strings; ++j)
		{

			scanf("%s", subString);

			if (isSubString(subString, string))
				printf("Yes\n");
			else
				printf("No\n");

		}

		scanf("%s", string);

	}

}

bool isSubString(char *string1, char *string2)
{

	unsigned short i, j;
	unsigned short tamanho1, tamanho2;

	tamanho1 = strlen(string1);
	tamanho2 = strlen(string2);

	for (i = 0, j = 0; i < tamanho2 && j < tamanho1; i++)
		if (string1[j] == string2[i])
			j++;

	// Se todos os caracteres do padrão existirem na string principal
	// Então o padrão é uma substring;
	if (j == tamanho1)
		return true;
	else
		return false;

}