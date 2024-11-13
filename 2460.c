#include <stdio.h>
#include <string.h>

struct cel{
    int conteudo;
    struct cel *prox;
};

typedef struct cel celula;


void insere(int x, celula *p){
    celula *nova;
    nova = malloc(sizeof(celula));
    nova->conteudo = x;
    nova->prox = p->prox;
    p->prox = nova;
}

void imprimir (celula *ult){
    celula *p;
    for(p = ult->prox; p!=NULL; p = p->prox){
        if(p->prox ==NULL)
            printf("%d\n", p->conteudo);
        else
            printf("%d ", p->conteudo);
    }
}

void busca_remove (int y, celula *ult){
    celula *p, *q;
    p = ult;
    q = ult->prox;
    while (q != NULL && q->conteudo != y){
        p = q;
        q = q->prox;
    }
    if (q != NULL){
        p->prox = q->prox;
        free(q);
    }
}

int main(){
    celula *cabeca = malloc(sizeof(celula));
	cabeca->prox = NULL;

	int n;
	scanf(("%d",&n));

	int lista;
	celula *next = cabeca;
	for(int i = 0; i < n; ++i){
		scanf("%d", &lista);
		insere(lista, next);
		next = next->prox;
	}

	int m;
	scanf("%d",&m);

	int remove;
	for(int i = 0; i < m; ++i){
		scanf("%d",&remove);
		busca_remove(remove, cabeca);
	}

	imprimir(cabeca);
	return 0;
}