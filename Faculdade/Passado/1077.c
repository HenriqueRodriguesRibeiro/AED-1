/* NOME: Henrique Rodrigues Ribeiro
   RA: 176515
   Turma: IA
   
*/

#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <ctype.h>

struct pilhaNew{
    char valor;
    struct pilhaNew* fundo;    
};

struct pilha{
    int TAM;
    struct pilhaNew* topo;
};

void push(struct pilha* p, char valor){
    p->TAM += 1;
    struct pilhaNew* NewTopo = (struct pilhaNew*) malloc(sizeof(struct pilhaNew));

    NewTopo->valor = valor;
    NewTopo->fundo = p->topo;
    p->topo = NewTopo;
}

void pop(struct pilha* p){
    if(p->topo > 0){
        p->TAM -= 1;
        struct pilhaNew* antigo = p->topo;
        p->topo = p->topo->fundo;
        free(antigo);
    }
}

char top(struct pilha* p){
    return p->topo->valor;
}

char size(struct pilha* p){
    return p->TAM;
}

char vazio(struct pilha* p){
    return p->TAM == 0;
}

char inicia(struct pilha* p){
    p->TAM = 0;
    p->topo = NULL;
}

void destroi(struct pilha* p){
    while (!vazio(p)){
        pop(p);
    }
}

int precedencia(char operador){
    switch(operador){
        case '+':
        case '-':   return 1;
        case '*':
        case '/':   return 2;
    }
}

int main(){
    int N, tamanho;
    struct pilha p;
    char expressao[301];

    scanf("%d\n", &N);

    for(int k = 0; k < N; k++){
        scanf("%s\n", &expressao);
        
        inicia(&p);

        tamanho = strlen(expressao);
        for(int i = 0; i < tamanho; i++){
            if(isalpha(expressao[i]) || isdigit(expressao[i])){
                printf("%c", expressao[i]);
            }else if(expressao[i] == '(' || expressao[i] == '^'){
                push(&p, expressao[i]);
            }else if(expressao[i] == ')'){
                while(!vazio(&p) && top(&p) != '('){
                    printf("%c", top(&p));
                    pop(&p);
                }

                if(!vazio(&p)){
                    pop(&p);
                }
            }   else{
                    while(!vazio(&p) && top(&p) != '(' && precedencia(expressao[i]) <= precedencia(top(&p))){
                        printf("%c", top(&p));
                        pop(&p);
                    }

                push(&p, expressao[i]); 
            }
        }

        while (!vazio(&p)){
            printf("%c", top(&p));
            pop(&p);
        }
        printf("\n");
    }

    return 0;
}