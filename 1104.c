/* 
    NOME: Henrique Rodrigues Ribeiro
    RA: 176515
    Turma: IA
   
*/

#include <stdio.h>
#include <string.h>

#define true 1
#define false 0
#define MAXSIZE 100101

typedef struct Cartas{

	_Bool alice;
	_Bool beatriz;

} Cartas;

Cartas cards[MAXSIZE];

void main ()
{
	unsigned i, tmp;
	unsigned alice, beatriz;

	while (scanf("%u %u", &alice, &beatriz), alice)
	{
		memset(cards, false, sizeof(cards));

		for (i = 0; i < alice; ++i){
			scanf("%u", &tmp), cards[tmp].alice = true;
        }
		for (i = 0; i < beatriz; ++i){
			scanf("%u", &tmp), cards[tmp].beatriz = true;
        }    
		alice = beatriz = 0;

		for (i = 0; i < MAXSIZE; ++i)
		{
			if (cards[i].alice && !cards[i].beatriz){
				++alice;
            }    
			if (!cards[i].alice && cards[i].beatriz){
				++beatriz;
            }    
		}
		printf("%d\n", beatriz > alice ? alice : beatriz);
	}

}