#include <stdio.h>

int maior(int a, int b) {
    return (a > b) ? a : b;
}

int menor(int a, int b) {
    return (a < b) ? a : b;
}

float media(float a, float b) {
    return (a + b) / 2.0f;
}

int fatorial(int n) {
    if (n < 0) {
        return -1; /* fatorial nao definido para negativos */
    }
    int resultado = 1;
    for (int i = 2; i <= n; i++) {
        resultado *= i;
    }
    return resultado;
}

int main(void) {
    int a, b, n;

    printf("Digite dois numeros inteiros: ");
    scanf("%d %d", &a, &b);

    printf("Maior: %d\n", maior(a, b));
    printf("Menor: %d\n", menor(a, b));
    printf("Media: %.2f\n", media((float)a, (float)b));

    printf("\nDigite um numero para calcular o fatorial: ");
    scanf("%d", &n);

    int fat = fatorial(n);
    if (fat == -1) {
        printf("Fatorial nao definido para numeros negativos.\n");
    } else {
        printf("Fatorial de %d: %d\n", n, fat);
    }

    return 0;
}