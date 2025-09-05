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

    // Cria o nó atual com o próximo dado do percurso pré-ordem
    ArvoreNo* noAtual = criarNovoNo(preOrdem[*indicePre]);
    (*indicePre)++;

    // Se o nó não tem filhos, retorna ele mesmo
    if (inicioIntervalo == fim) {
        return noAtual;
    }

    // Encontra o índice deste nó no percurso em-ordem
    int emOrdem = procurarPosicao(emOrdem, noAtual->dado, inicioIntervalo, fim);

    // Constrói as subárvores esquerda e direita
    noAtual->esq = montarArvore(preOrdem, emOrdem, inicioIntervalo, emOrdem - 1, indicePre);
    noAtual->dir = montarArvore(preOrdem, emOrdem, emOrdem + 1, fim, indicePre);

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