/* 
    NOME: Henrique Rodrigues Ribeiro
    RA: 176515
    
   
*/

#include <stdio.h>
#include <string.h>

char grid[1024][1025];
int vis[1024][1024];
int N, M;

int dx[4] = {1, -1, 0, 0};
int dy[4] = {0, 0, 1, -1};

void bfs(int x, int y) {
    static int qx[1048576];
    static int qy[1048576];

    int ini = 0, fim = 0;

    qx[fim] = x;
    qy[fim] = y;
    fim++;

    vis[x][y] = 1;

    while (ini < fim) {
        int cx = qx[ini];
        int cy = qy[ini];
        ini++;

        for (int i = 0; i < 4; i++) {
            int nx = cx + dx[i];
            int ny = cy + dy[i];

            if (nx >= 0 && nx < N && ny >= 0 && ny < M) {
                if (!vis[nx][ny] && grid[nx][ny] == '.') {
                    vis[nx][ny] = 1;

                    qx[fim] = nx;
                    qy[fim] = ny;
                    fim++;
                }
            }
        }
    }
}

int main() {
    scanf("%d %d", &N, &M);

    for (int i = 0; i < N; i++) {
        scanf("%s", grid[i]);
    }

    int cliques = 0;

    for (int i = 0; i < N; i++) {
        for (int j = 0; j < M; j++) {
            if (grid[i][j] == '.' && !vis[i][j]) {
                bfs(i, j);
                cliques++;
            }
        }
    }

    printf("%d\n", cliques);

    return 0;
}
