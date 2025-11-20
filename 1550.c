/* 
    NOME: Henrique Rodrigues Ribeiro
    RA: 176515
    
   
*/

#include <stdio.h>
#include <string.h>

int reverse(int x) {
    int r = 0;
    while (x > 0) {
        r = r * 10 + (x % 10);
        x /= 10;
    }
    return r;
}

int bfs(int A, int B) {
    int dist[10000];
    int queue[10000];
    int ini = 0, fim = 0;

    for (int i = 0; i < 10000; i++)
        dist[i] = -1;

    dist[A] = 0;
    queue[fim++] = A;

    while (ini < fim) {
        int x = queue[ini++];

        if (x == B)
            return dist[x];

        // operação +1
        int v1 = x + 1;
        if (v1 < 10000 && dist[v1] == -1) {
            dist[v1] = dist[x] + 1;
            queue[fim++] = v1;
        }

        // operação inverter
        int v2 = reverse(x);
        if (v2 < 10000 && dist[v2] == -1) {
            dist[v2] = dist[x] + 1;
            queue[fim++] = v2;
        }
    }
    return -1;
}

int main() {
    int T, A, B;
    scanf("%d", &T);
    while (T--) {
        scanf("%d %d", &A, &B);
        printf("%d\n", bfs(A, B));
    }
    return 0;
}
