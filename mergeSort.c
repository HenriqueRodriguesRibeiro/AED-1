#include <stdio.h>
#include <stdlib.h>
#include <time.h> //clock(), CLOCKS_PER_SEC e clock_t

int const TAM = 400000; //constante para tamanho do vetor

void merge(int arr[], int l, int m, int r) {
    int n1 = m - l + 1;
    int n2 = r - m;

    // Criar arrays temporários
    int *L = (int*)malloc((n1 + 1) * sizeof(int)); // Adiciona espaço para o sentinela
    int *R = (int*)malloc((n2 + 1) * sizeof(int));

    // Copiar dados para os arrays temporários L[] e R[]
    for (int i = 0; i < n1; i++)
        L[i] = arr[l + i];
    for (int j = 0; j < n2; j++)
        R[j] = arr[m + 1 + j];

    // Mesclar os arrays temporários de volta em arr[l..r]
    int i = 0, j = 0, k = l;
    while (i < n1 && j < n2) {
        if (L[i] <= R[j]) {
            arr[k] = L[i];
            i++;
        } else {
            arr[k] = R[j];
            j++;
        }
        k++;
    }

    // Copiar os elementos restantes de L[], se houver
    while (i < n1) {
        arr[k] = L[i];
        i++;
        k++;
    }

    // Copiar os elementos restantes de R[], se houver
    while (j < n2) {
        arr[k] = R[j];
        j++;
        k++;
    }
}

void mergeSort(int arr[], int l, int r) {
    if (l < r) {
        // Encontrar o ponto do meio
        int m = l + (r - l) / 2;

        // Ordenar as duas metades
        mergeSort(arr, l, m);
        mergeSort(arr, m + 1, r);

        // Mesclar as sublistas ordenadas
        merge(arr, l, m, r);
    }
}

int main(){
    clock_t t; //variável para armazenar tempo
    int vetor[TAM];
    
    //semente de aleatoriedade
    srand((unsigned)time(NULL));

    //geração aleatório dos valores do vetor
    for(int a = 0; a < TAM; a++)
        vetor[a] = rand() % TAM;

    //Verificando tempo de execução do bubble sort=> t2
    t = clock(); //armazena tempo
    mergeSort(vetor,0, TAM-1);
    t = clock() - t; //tempo final - tempo 

    //imprime o tempo na tela
    printf("Tempo de execucao: %lf ms\n", ((double)t)/((CLOCKS_PER_SEC/1000))); //conversão para double

    return 0;
}