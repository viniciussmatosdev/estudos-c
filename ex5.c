#include <stdio.h>

#define TAM 5

int main(void) {
    int matriz[TAM][TAM];
    int maior, linhaMaior = 0, colunaMaior = 0;

    printf("Digite os %d elementos da matriz %dx%d:\n", TAM * TAM, TAM, TAM);
    for (int i = 0; i < TAM; i++) {
        for (int j = 0; j < TAM; j++) {
            printf("Elemento [%d][%d]: ", i, j);
            scanf("%d", &matriz[i][j]);
        }
    }

    maior = matriz[0][0];

    for (int i = 0; i < TAM; i++) {
        for (int j = 0; j < TAM; j++) {
            if (matriz[i][j] > maior) {
                maior = matriz[i][j];
                linhaMaior = i;
                colunaMaior = j;
            }
        }
    }

    printf("\nMatriz digitada:\n");
    for (int i = 0; i < TAM; i++) {
        for (int j = 0; j < TAM; j++) {
            printf("%5d", matriz[i][j]);
        }
        printf("\n");
    }

    printf("\nMaior elemento: %d\n", maior);
    printf("Linha:  %d\n", linhaMaior);
    printf("Coluna: %d\n", colunaMaior);

    return 0;
}