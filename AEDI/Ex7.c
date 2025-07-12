#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// Estrutura para um nó da árvore binária
typedef struct ArvoreNo {
    char dado;
    struct ArvoreNo* esq;
    struct ArvoreNo* dir;
} ArvoreNo;

// Função para criar um novo nó
ArvoreNo* criarNovoNo(char valorCaractere) {
    ArvoreNo* novoNoArvore = (ArvoreNo*)malloc(sizeof(ArvoreNo));
    novoNoArvore->dado = valorCaractere;
    novoNoArvore->esq = NULL;
    novoNoArvore->dir = NULL;
    return novoNoArvore;
}

// Função para encontrar o índice de um dado em uma string
int procurarPosicao(char* texto, char alvo, int comeco, int termino) {
    for (int contador = comeco; contador <= termino; contador++) {
        if (texto[contador] == alvo) {
            return contador;
        }
    }
    return -1;
}

// Função recursiva para construir a árvore
ArvoreNo* montarArvore(char* preOrdem, char* emOrdem, int inicioIntervalo, int fim, int* indicePre) {
    if (inicioIntervalo > fim) {
        return NULL;
    }

    ArvoreNo* noAtual = criarNovoNo(preOrdem[*indicePre]);
    (*indicePre)++;

    if (inicioIntervalo == fim) {
        return noAtual;
    }

    int posEmOrdem = procurarPosicao(emOrdem, noAtual->dado, inicioIntervalo, fim);

    noAtual->esq = montarArvore(preOrdem, emOrdem, inicioIntervalo, posEmOrdem - 1, indicePre);
    noAtual->dir = montarArvore(preOrdem, emOrdem, posEmOrdem + 1, fim, indicePre);

    return noAtual;
}

// Função para realizar o percurso pós-ordem e imprimir o resultado
void imprimirPosOrdem(ArvoreNo* noRaiz) {
    if (noRaiz == NULL) {
        return;
    }

    imprimirPosOrdem(noRaiz->esq);
    imprimirPosOrdem(noRaiz->dir);
    printf("%c", noRaiz->dado);
}

// Função principal
int main() {
    int qtdNos;
    char seqPreOrdem[82], seqEmOrdem[82];

    // Lê a entrada
    scanf("%d %s %s", &qtdNos, seqPreOrdem, seqEmOrdem);

    int contadorPreOrdem = 0;
    ArvoreNo* raizArvore = montarArvore(seqPreOrdem, seqEmOrdem, 0, qtdNos - 1, &contadorPreOrdem);

    // Imprime o percurso pós-ordem
    imprimirPosOrdem(raizArvore);
    printf("\n");

    return 0;
}