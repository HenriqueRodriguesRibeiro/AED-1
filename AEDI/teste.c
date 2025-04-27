#include <stdio.h>
#include <stdlib.h>

typedef struct {
    float D;
    int Q;
    float *P;
} Cliente;

void lerDadosCliente(Cliente *cliente) {
    // Ler dinheiro do cliente (D) - deve ser >= 0
    do {
        scanf("%f", &cliente->D);
        if (cliente->D < 0) {
            // Se valor inválido, continuar pedindo
            continue;
        }
        break;
    } while (1);

    // Ler quantidade de livros (Q) - deve ser >=0 e <=100
    do {
        scanf("%d", &cliente->Q);
        if (cliente->Q < 0 || cliente->Q > 100) {
            // Se valor inválido, continuar pedindo
            continue;
        }
        break;
    } while (1);

    // Alocar memória para os preços dos livros
    cliente->P = (float *)malloc(cliente->Q * sizeof(float));
    if (cliente->P == NULL) {
        printf("Erro de alocação de memória!\n");
        exit(1);
    }

    // Ler preços dos livros - cada um deve ser >=0
    for (int i = 0; i < cliente->Q; i++) {
        do {
            scanf("%f", &cliente->P[i]);
            if (cliente->P[i] < 0) {
                // Se valor inválido, continuar pedindo
                continue;
            }
            break;
        } while (1);
    }
}

void calcularCompra(Cliente *cliente) {
    float dinheiro = cliente->D;
    int livros_comprados = 0;

    // Tentar comprar livros na ordem de preferência
    for (int i = 0; i < cliente->Q; i++) {
        if (dinheiro >= cliente->P[i]) {
            dinheiro -= cliente->P[i];
            livros_comprados++;
        } else {
            break; // Não tem dinheiro para mais livros
        }
    }

    // Imprimir resultado conforme formato especificado
    printf("%d %.2f\n", livros_comprados, dinheiro);
}

int main() {
    int N;

    // Ler número de clientes (1 <= N <= 100)
    do {
        scanf("%d", &N);
        if (N < 1 || N > 100) {
            continue; // Valor inválido, pedir novamente
        }
        break;
    } while (1);

    // Alocar vetor de clientes dinamicamente
    Cliente *clientes = (Cliente *)malloc(N * sizeof(Cliente));
    if (clientes == NULL) {
        printf("Erro de alocação de memória!\n");
        return 1;
    }

    // Ler dados de cada cliente
    for (int i = 0; i < N; i++) {
        lerDadosCliente(&clientes[i]);
    }

    // Calcular e mostrar resultados para cada cliente
    for (int i = 0; i < N; i++) {
        calcularCompra(&clientes[i]);
        free(clientes[i].P); // Liberar memória alocada para os preços
    }

    free(clientes); // Liberar vetor de clientes
    return 0;
}