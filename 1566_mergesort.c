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

void merge(int arr[], int left, int mid, int right) {
    int n1 = mid - left + 1;
    int n2 = right - mid;
    
    int *L = (int*)malloc(n1 * sizeof(int));
    int *R = (int*)malloc(n2 * sizeof(int));
    
    for (int i = 0; i < n1; i++)
        L[i] = arr[left + i];
    for (int j = 0; j < n2; j++)
        R[j] = arr[mid + 1 + j];
    
    int i = 0, j = 0, k = left;
    while (i < n1 && j < n2) {
        if (compare(L[i], R[j]) <= 0) {
            arr[k] = L[i];
            i++;
        } else {
            arr[k] = R[j];
            j++;
        }
        k++;
    }
    
    while (i < n1) {
        arr[k] = L[i];
        i++;
        k++;
    }
    
    while (j < n2) {
        arr[k] = R[j];
        j++;
        k++;
    }
    
    free(L);
    free(R);
}

void merge_sort(int arr[], int left, int right) {
    if (left < right) {
        int mid = left + (right - left) / 2;
        merge_sort(arr, left, mid);
        merge_sort(arr, mid + 1, right);
        merge(arr, left, mid, right);
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
        
        merge_sort(nums, 0, N - 1);
        
        for (int i = 0; i < N; i++) {
            printf("%d\n", nums[i]);
        }
        
        free(nums);
    }
    
    return 0;
}