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
    
    if (mod_x < 0) mod_x += M;
    if (mod_y < 0) mod_y += M;
    
    if (mod_x != mod_y) return mod_x - mod_y;
    
    int x_odd = abs(x) % 2;
    int y_odd = abs(y) % 2;
    
    if (x_odd != y_odd) {
        if (x_odd == 1) return -1;
        else return 1;
    }
    
    if (x_odd == 1) return y - x;
    if (x_odd == 0) return x - y;
    
    return 0;
}

int partition(int arr[], int low, int high) {
    int pivot = arr[high];
    int i = low - 1;
    
    for (int j = low; j < high; j++) {
        if (compare(arr[j], pivot) <= 0) {
            i++;
            int temp = arr[i];
            arr[i] = arr[j];
            arr[j] = temp;
        }
    }
    
    int temp = arr[i + 1];
    arr[i + 1] = arr[high];
    arr[high] = temp;
    
    return i + 1;
}

void quick_sort(int arr[], int low, int high) {
    if (low < high) {
        int pi = partition(arr, low, high);
        quick_sort(arr, low, pi - 1);
        quick_sort(arr, pi + 1, high);
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
        
        quick_sort(nums, 0, N - 1);
        
        for (int i = 0; i < N; i++) {
            printf("%d\n", nums[i]);
        }
        
        free(nums);
    }
    
    return 0;
}