/* 
    NOME: Henrique Rodrigues Ribeiro
    RA: 176515
    
   
*/


#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdbool.h>

#define SIZE 8

typedef struct {
    int x, y, dist;
} Node;

// Movimentos possíveis do cavalo (8 direções)
int moves[8][2] = {
    {2, 1}, {2, -1}, {-2, 1}, {-2, -1},
    {1, 2}, {1, -2}, {-1, 2}, {-1, -2}
};

// Converte coordenadas de xadrez para índices da matriz
void chessToIndex(char* pos, int* x, int* y) {
    *x = pos[0] - 'a';  // Coluna: 'a' a 'h' -> 0 a 7
    *y = pos[1] - '1';  // Linha: '1' a '8' -> 0 a 7
}

// Verifica se a posição está dentro do tabuleiro
bool isValid(int x, int y) {
    return x >= 0 && x < SIZE && y >= 0 && y < SIZE;
}

// BFS para encontrar o menor número de movimentos
int bfs(int startX, int startY, int targetX, int targetY) {
    if (startX == targetX && startY == targetY) {
        return 0;
    }
    
    bool visited[SIZE][SIZE] = {false};
    Node queue[SIZE * SIZE];
    int front = 0, rear = 0;
    
    // Inicializa com a posição inicial
    queue[rear].x = startX;
    queue[rear].y = startY;
    queue[rear].dist = 0;
    rear++;
    visited[startX][startY] = true;
    
    while (front < rear) {
        Node current = queue[front];
        front++;
        
        // Tenta todos os movimentos possíveis
        for (int i = 0; i < 8; i++) {
            int newX = current.x + moves[i][0];
            int newY = current.y + moves[i][1];
            
            if (isValid(newX, newY) && !visited[newX][newY]) {
                // Se encontrou o destino
                if (newX == targetX && newY == targetY) {
                    return current.dist + 1;
                }
                
                // Adiciona à fila
                visited[newX][newY] = true;
                queue[rear].x = newX;
                queue[rear].y = newY;
                queue[rear].dist = current.dist + 1;
                rear++;
            }
        }
    }
    
    return -1;  // Não deveria acontecer em um tabuleiro 8x8
}

int main() {
    char start[3], target[3];
    
    while (scanf("%s %s", start, target) == 2) {
        int startX, startY, targetX, targetY;
        
        // Converte coordenadas
        chessToIndex(start, &startX, &startY);
        chessToIndex(target, &targetX, &targetY);
        
        // Calcula o número mínimo de movimentos
        int moves = bfs(startX, startY, targetX, targetY);
        
        // Imprime o resultado
        printf("To get from %s to %s takes %d knight moves.\n", 
               start, target, moves);
    }
    
    return 0;
}