#include <stdio.h>
#include <stdlib.h>

typedef struct {
    float D;
    int Q;
    float *P;
} Cliente;

int DadosCliente(Cliente *cliente) {
    // Ler D (dinheiro) - deve ser >= 0
    scanf("%f", &cliente->D);
    while (cliente->D < 0) {
        scanf("%f", &cliente->D);
    }

    // Ler Q (quantidade de livros) - deve ser >= 0 e <= 100
    scanf("%d", &cliente->Q);
    while (cliente->Q < 0 || cliente->Q > 100) {
        scanf("%d", &cliente->Q);
    }

    cliente->P = (float *)malloc(cliente->Q * sizeof(float));
    if (cliente->P == NULL) {
        printf("Erro de alocação de memória!\n");
        return 0;
    }

    // Ler os preços dos livros - cada um deve ser >= 0
    for (int i = 0; i < cliente->Q; i++) {
        scanf("%f", &cliente->P[i]);
        while (cliente->P[i] < 0) {
            scanf("%f", &cliente->P[i]);
        }
    }
    return 1;
}

void calculoCompra(Cliente cliente) {
    float dinheiro = cliente.D;
    int livros_comprados = 0;

    for (int i = 0; i < cliente.Q; i++) {
        // Verifica se pode comprar o livro atual
        if (dinheiro >= cliente.P[i]) {
            dinheiro -= cliente.P[i];
            livros_comprados++;
        }
    }
    //Imprimir resultado
    printf("%d %.2f\n", livros_comprados, dinheiro);
}

int main() {
    int N;

    //Ler número de clientes (1 <= N <= 100)
    scanf("%d", &N);
    while (N < 1 || N > 100) {
        scanf("%d", &N);
    }

    //Aloca vetor de clientes dinamicamente
    Cliente *clientes = (Cliente *)malloc(N * sizeof(Cliente));
    if (clientes == NULL) {
        printf("Erro de alocação de memória!\n");
        return 1;
    }

    // Ler dados de cada cliente
    for (int i = 0; i < N; i++) {
        if (!DadosCliente(&clientes[i])) {
            // Em caso de erro, liberar memória e sair
            for (int j = 0; j <= i; j++) {
                if (clientes[j].P != NULL) {
                    free(clientes[j].P);
                }
            }
            free(clientes);
            return 1;
        }
    }

    // Calcular e mostrar resultados para cada cliente
    for (int i = 0; i < N; i++) {
        calculoCompra(clientes[i]);
        free(clientes[i].P); // Liberar memória alocada para os preços
    }

    free(clientes); // Liberar vetor de clientes
    return 0;
}