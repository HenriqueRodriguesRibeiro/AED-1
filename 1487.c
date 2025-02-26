/* 
    NOME: Henrique Rodrigues Ribeiro
    RA: 176515
    Turma: IA
   
*/

#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

typedef struct brinquedo{

	unsigned short tempo;
	unsigned short qtsPontos;
	double razaoPontoTempo;

} brinquedo;

int compara(brinquedo *a, brinquedo *b);

void main ()
{
	unsigned short i;
	unsigned short instancia;
	unsigned short total_atra;
	unsigned short tempo_lim, aux;
	unsigned short pontoTotal, tempoTotal;

	instancia = 0;
	while (true)
	{

		scanf("%hu %hu", &total_atra, &tempo_lim);

		if (total_atra == 0)
			break;

		brinquedo brinquedos[total_atra];

		for (i = 0; i < total_atra; ++i)
		{

			scanf("%hu %hu", &brinquedos[i].tempo, &brinquedos[i].qtsPontos);
			brinquedos[i].razaoPontoTempo = (brinquedos[i].qtsPontos / (double)brinquedos[i].tempo);

		}

		// Ordeno a struct de brinquedos descrescentemente pela razão dos pontos pelo tempo
		// De cada brinquedo; vou utilizar uma abordagem gulosa;
		// Quanto mais pontos eu conseguir com a quantidade de tempo disponível, melhor.
		qsort(brinquedos, total_atra, sizeof(brinquedo), compara);

		i = 0;
		pontoTotal = tempoTotal = 0;

		while (i < total_atra)
		{

			aux = tempoTotal + brinquedos[i].tempo;

			// Perceba que o mesmo brinquedo pode ser utilizado seguidamente
			// Apenas quando o limite de tempo disponível é ultrapassado
			// É que eu verifico outro brinquedo (i++);
			if (aux <= tempo_lim)
			{

				pontoTotal += brinquedos[i].qtsPontos;
				// Essa linha na verdade é um incremento de tempoTotal disfarçado;
				// Na linha 58 aux recebe tempoTotal + brinquedos[i].tempo;
				// E na linha 71 tempoTotal recebe aux; é a mesma coisa que fazer
				// tempoTotal += tempoTotal + brinquedos[i].tempo;
				tempoTotal = aux;

			}
			else
				i++;
		}

		printf("Instancia %hu\n%hu\n\n", ++instancia, pontoTotal);

	}

}

int compara(brinquedo *a, brinquedo *b)
{

	if (a->razaoPontoTempo == b->razaoPontoTempo)
		return 0;
	else if (a->razaoPontoTempo > b->razaoPontoTempo)
		return -1;
	else
		return 1;

}