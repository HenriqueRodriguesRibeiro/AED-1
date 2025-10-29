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

void heapify(int arr[], int n, int i) {
    int largest = i;
    int left = 2 * i + 1;
    int right = 2 * i + 2;
    
    if (left < n && compare(arr[left], arr[largest]) > 0)
        largest = left;
    
    if (right < n && compare(arr[right], arr[largest]) > 0)
        largest = right;
    
    if (largest != i) {
        int temp = arr[i];
        arr[i] = arr[largest];
        arr[largest] = temp;
        heapify(arr, n, largest);
    }
}

void heap_sort(int arr[], int n) {
    // Build max heap
    for (int i = n / 2 - 1; i >= 0; i--)
        heapify(arr, n, i);
    
    // Extract elements from heap
    for (int i = n - 1; i > 0; i--) {
        int temp = arr[0];
        arr[0] = arr[i];
        arr[i] = temp;
        heapify(arr, i, 0);
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
        
        heap_sort(nums, N);
        
        for (int i = 0; i < N; i++) {
            printf("%d\n", nums[i]);
        }
        
        free(nums);
    }
    
    return 0;
}