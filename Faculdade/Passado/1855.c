/* 
    NOME: Henrique Rodrigues Ribeiro
    RA: 176515
    Turma: IA
   
*/

#include <stdio.h>

int main(){
	int x, y, i, j;
	int l_atual = 0, c_atual = 0;
	char resp, seta;
	
	scanf("%d", &x);
	scanf("%d", &y);
	char mapa[y][x];
	
	for(i=0; i<y; i++){
		for(j=0; j<x; j++){
			scanf(" %c", &mapa[i][j]);
		}
	}
	
	if(mapa[0][0] == '>'){
		seta = '>';
		mapa[0][0] = 'x';
		c_atual++;
		while(1){
			if(l_atual>=y || l_atual<0 || c_atual>=x || c_atual<0){
				resp = '!';
				break;
			}
			else if(mapa[l_atual][c_atual] == '*'){
				resp = '*';
				break;
			}
			else if(mapa[l_atual][c_atual] == 'x'){
				resp = '!';
				break;
			}
			else if(mapa[l_atual][c_atual] == 'v'){
				seta = 'v';
				mapa[l_atual][c_atual] = 'x';
				l_atual++;
			}
			else if(mapa[l_atual][c_atual] == '^'){
				seta = '^';
				mapa[l_atual][c_atual] = 'x';
				l_atual--;
			}
			else if(mapa[l_atual][c_atual] == '>'){
				seta = '>';
				mapa[l_atual][c_atual] = 'x';
				c_atual++;
			}
			else if(mapa[l_atual][c_atual] == '<'){
				seta = '<';
				mapa[l_atual][c_atual] = 'x';
				c_atual--;
			}
			else if(mapa[l_atual][c_atual] == '.'){
				if(seta == 'v'){
					l_atual++;
				}
				else if(seta == '^'){
					l_atual--;
				}
				else if(seta == '>'){
					c_atual++;
				}
				else if(seta == '<'){
					c_atual--;
				}
			}
		}
		printf("%c\n", resp);
	}
	
	else if(mapa[0][0] == 'v'){
		seta = 'v';
		mapa[0][0] = 'x';
		l_atual++;
		while(1){
			if(l_atual>=y || l_atual<0 || c_atual>=x || c_atual<0){
				resp = '!';
				break;
			}
			else if(mapa[l_atual][c_atual] == '*'){
				resp = '*';
				break;
			}
			else if(mapa[l_atual][c_atual] == 'x'){
				resp = '!';
				break;
			}
			else if(mapa[l_atual][c_atual] == 'v'){
				seta = 'v';
				mapa[l_atual][c_atual] = 'x';
				l_atual++;
			}
			else if(mapa[l_atual][c_atual] == '^'){
				seta = '^';
				mapa[l_atual][c_atual] = 'x';
				l_atual--;
			}
			else if(mapa[l_atual][c_atual] == '>'){
				seta = '>';
				mapa[l_atual][c_atual] = 'x';
				c_atual++;
			}
			else if(mapa[l_atual][c_atual] == '<'){
				seta = '<';
				mapa[l_atual][c_atual] = 'x';
				c_atual--;
			}
			else if(mapa[l_atual][c_atual] == '.'){
				if(seta == 'v'){
					l_atual++;
				}
				else if(seta == '^'){
					l_atual--;
				}
				else if(seta == '>'){
					c_atual++;
				}
				else if(seta == '<'){
					c_atual--;
				}
			}
		}
		printf("%c\n", resp);
	}
	
	else if(mapa[0][0] == '*'){
		printf("*\n");
	}
	
	else{
		printf("!\n");
	}
}