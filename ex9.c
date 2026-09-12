#include <stdio.h>

#define MAX_ALUNOS 50

void lerNotas(float notas[], int n) {
    for (int i = 0; i < n; i++) {
        printf("Nota do aluno %d: ", i + 1);
        scanf("%f", &notas[i]);
    }
}

float calcularMedia(float notas[], int n) {
    float soma = 0.0f;
    for (int i = 0; i < n; i++) {
        soma += notas[i];
    }
    return soma / n;
}

float encontrarMaiorNota(float notas[], int n) {
    float maior = notas[0];
    for (int i = 1; i < n; i++) {
        if (notas[i] > maior) {
            maior = notas[i];
        }
    }
    return maior;
}

float encontrarMenorNota(float notas[], int n) {
    float menor = notas[0];
    for (int i = 1; i < n; i++) {
        if (notas[i] < menor) {
            menor = notas[i];
        }
    }
    return menor;
}

void imprimirRelatorio(float notas[], int n, float media, float maior, float menor) {
    printf("\n===== RELATORIO DA TURMA =====\n");
    printf("Notas: ");
    for (int i = 0; i < n; i++) {
        printf("%.2f ", notas[i]);
    }
    printf("\n");
    printf("Media da turma: %.2f\n", media);
    printf("Maior nota: %.2f\n", maior);
    printf("Menor nota: %.2f\n", menor);
}

int main(void) {
    float notas[MAX_ALUNOS];
    int n;

    printf("Quantos alunos deseja cadastrar? ");
    scanf("%d", &n);

    if (n <= 0 || n > MAX_ALUNOS) {
        printf("Quantidade invalida de alunos.\n");
        return 1;
    }

    lerNotas(notas, n);

    float media = calcularMedia(notas, n);
    float maior = encontrarMaiorNota(notas, n);
    float menor = encontrarMenorNota(notas, n);

    imprimirRelatorio(notas, n, media, maior, menor);

    return 0;
}