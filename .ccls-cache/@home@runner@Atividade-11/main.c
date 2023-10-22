#include <stdio.h>
#include <stdlib.h>
int buscaBinaria(int vetor[], int tamanho, int valor, int* iteracoes) {
    int esquerda = 0;
    int direita = tamanho - 1;
    while (esquerda <= direita) {
        int meio = esquerda + (direita - esquerda) / 2;
        *iteracoes += 1;
        if (vetor[meio] == valor) {
            return meio;
        }
        if (vetor[meio] < valor) {
            esquerda = meio + 1;
        } else {
            direita = meio - 1;
        }
    }
    return -1;
}
int main() {
    int vetor[] = {1, 3, 5, 7, 9, 11, 13, 15, 17, 19};
    int tamanho = sizeof(vetor) / sizeof(vetor[0]);
    int iteracoes = 0;
    int valor, resultado;
    printf("Digite o valor a ser procurado: ");
    scanf("%d", &valor);
    resultado = buscaBinaria(vetor, tamanho, valor, &iteracoes);
    if (resultado == -1) {
        printf("Valor não encontrado no vetor.\n");
    } else {
        printf("Valor encontrado na posição %d.\n", resultado);
    }
    printf("Número de interações: %d\n", iteracoes);
    return 0;
}