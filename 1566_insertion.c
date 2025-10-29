/* 
    NOME: Henrique Rodrigues Ribeiro
    RA: 176515
   
*/

#include <stdio.h>
#include <stdlib.h>

int M;

int compare(int x, int y) {
    int mod_x = x % M;
    int mod_y = y % M;
    
    // Ajustar módulo para ser não-negativo
    if (mod_x < 0) mod_x += M;
    if (mod_y < 0) mod_y += M;
    
    // 1. Comparar por módulo
    if (mod_x != mod_y) {
        return mod_x - mod_y;
    }
    
    // 2. Mesmo módulo - verificar par/ímpar
    int x_odd = abs(x) % 2;
    int y_odd = abs(y) % 2;
    
    // Se um é ímpar e outro é par
    if (x_odd != y_odd) {
        // Ímpar vem antes do par
        if (x_odd == 1) return -1;  // x é ímpar, vem antes
        else return 1;              // x é par, vem depois
    }
    
    // 3. Ambos ímpares - maior vem primeiro
    if (x_odd == 1) {
        return y - x;  // maior vem primeiro
    }
    
    // 4. Ambos pares - menor vem primeiro
    if (x_odd == 0) {
        return x - y;  // menor vem primeiro
    }
    
    return 0;
}

void insertion_sort(int arr[], int n) {
    for (int i = 1; i < n; i++) {
        int key = arr[i];
        int j = i - 1;
        
        while (j >= 0 && compare(arr[j], key) > 0) {
            arr[j + 1] = arr[j];
            j--;
        }
        arr[j + 1] = key;
    }
}

int main() {
    int N;
    
    while (1) {
        scanf("%d %d", &N, &M);
        if (N == 0 && M == 0) {
            printf("0 0\n");
            break;
        }
        
        printf("%d %d\n", N, M);
        
        int *nums = (int*)malloc(N * sizeof(int));
        for (int i = 0; i < N; i++) {
            scanf("%d", &nums[i]);
        }
        
        insertion_sort(nums, N);
        
        for (int i = 0; i < N; i++) {
            printf("%d\n", nums[i]);
        }
        
        free(nums);
    }
    
    return 0;
}