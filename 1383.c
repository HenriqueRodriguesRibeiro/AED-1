/* NOME: Henrique Rodrigues Ribeiro
   RA: 176515
   Turma: IA
   
    Exercício 1383
        Sudoku
*/

#include <stdio.h>

int sudoku[9][9];

//Verificação das colunas
int sameColumn(int x){
    int num[10];

    for(int i = 0; i < 10; i++){
        num[i] = 0;
    }

    for(int i = 0; i < 9; i++){
        if(num[sudoku[x][i]]) 
           return 0;
            num[sudoku[x][i]] += 1;
    }

    return 1;
}

//verificação das Linhas
int sameRow(int y){
    int num[10];

     for(int i = 0; i < 10; ++i){
        num[i] = 0;
    }

    for(int i = 0; i < 9; i++){
        if(num[sudoku[i][y]]) 
           return 0;
            num[sudoku[i][y]] += 1;
    }

    return 1;
}    

//Verificação dos quadrados 3x3
int sameSquare(int x){
    int num[10];
    int linha = 3*(x/3), coluna = 3*(x%3);

    for(int i = 0; i < 10; ++i){
        num[i] = 0;
    }

    for(int i = 0; i < 3; i++){
        for(int j = 0; j < 3; j++){
           if(num[sudoku[linha + i][coluna + j]]) 
              return 0;
            num[sudoku[linha + i][coluna + j]] += 1;
        }    
    }

    return 1;
}

int main(){
    int n;
    char* resposta;

    scanf("%d", &n);

    for(int k = 1; k <= n; ++k){
        for(int i = 0; i < 9; ++i){
            for(int j = 0; j < 9; ++j){
                scanf("%d", &sudoku[i][j]);
            }
        }

        printf("Instancia %d\n", k);

        resposta = "Sim";
       
        for(int i = 0; i < 9; ++i){
            if(!sameRow(i) || !sameColumn(i) || !sameSquare(i)){
                resposta = "Nao";
                break;
            }
        }

        printf("%s\n\n", resposta);
    }

    return 0;
}
