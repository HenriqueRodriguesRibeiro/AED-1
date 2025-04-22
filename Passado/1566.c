/* 
    NOME: Henrique Rodrigues Ribeiro
    RA: 176515
    Turma: IA
   
*/

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define true 1
#define false 0
#define MAXSIZE 235

void main ()
{
	_Bool flag;
	unsigned quantidadeA;
	unsigned i, qtsCasos, tmp;
	int alturas[MAXSIZE] = { 0 };

	scanf("%u", &qtsCasos);

	while (qtsCasos--)
	{

		scanf("%u", &quantidadeA);

		for (i = 0; i < quantidadeA; ++i)
		{

			scanf("%u", &tmp);
			alturas[tmp]++;

		}

		flag = false;
		for (i = 20; i <= 230; ++i)
		{

			if (alturas[i] > 1)
			{

				while (alturas[i]--)
				{

					if (!flag)
						printf("%u", i), flag = true;
					else
						printf(" %u", i);

				}

			}
			else if (alturas[i] == 1)
				if (!flag)
					printf("%u", i), flag = true;
				else
					printf(" %u", i);

		}

		printf("\n");
		memset(alturas, 0, sizeof(alturas));

	}


}