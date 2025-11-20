/* 
    NOME: Henrique Rodrigues Ribeiro
    RA: 176515
   
*/

#include <stdio.h>

typedef struct node {
   int v;
   struct node *dir, *esq;
} node;

node *new(int n) {
   node *nv = (node *) malloc(sizeof(node));
   nv->v = n;
   nv->esq = nv->dir = 0;
   return nv;
}

void pre(node *r) {
   if (r) {
      printf(" %d", r->v);
      pre(r->esq);
      pre(r->dir);
   }
}

void in(node *r) {
   if (r) {
      in(r->esq);
      printf(" %d", r->v);
      in(r->dir);
   }
}
void post(node *r) {
   if (r) {
      post(r->esq);
      post(r->dir);
      printf(" %d", r->v);
   }
}

void inserir(int n, node *r) {
   if (n < r->v)
      if (r->esq != NULL) inserir(n, r->esq);
      else r->esq = new(n);
   else
      if (r->dir != NULL) inserir(n, r->dir);
      else r->dir = new(n);
}

int main(void) {
   int c, n, i, j, v;
   scanf("%d", &c);
   for (i = 1; i <= c; ++i) {
      scanf("%d", &n);
      scanf("%d", &v);
      node *r = new(v);
      for (j = 0; j < n-1; ++j) {
         scanf("%d", &v);
         inserir(v, r);
      }
      printf("Case %d:", i);
      printf("\nPre.:"); pre(r);
      printf("\nIn..:"); in(r);
      printf("\nPost:"); post(r);
      printf("\n\n");
   }

   return 0;
}