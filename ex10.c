#include <stdio.h>

#define TAM 3

void inicializarTabuleiro(char tabuleiro[TAM][TAM]) {
    for (int i = 0; i < TAM; i++) {
        for (int j = 0; j < TAM; j++) {
            tabuleiro[i][j] = ' ';
        }
    }
}

void exibirTabuleiro(char tabuleiro[TAM][TAM]) {
    printf("\n");
    for (int i = 0; i < TAM; i++) {
        printf(" %c | %c | %c \n", tabuleiro[i][0], tabuleiro[i][1], tabuleiro[i][2]);
        if (i < TAM - 1) {
            printf("---+---+---\n");
        }
    }
    printf("\n");
}

int posicaoValida(int linha, int coluna) {
    return (linha >= 0 && linha < TAM && coluna >= 0 && coluna < TAM);
}

int posicaoOcupada(char tabuleiro[TAM][TAM], int linha, int coluna) {
    return tabuleiro[linha][coluna] != ' ';
}

void realizarJogada(char tabuleiro[TAM][TAM], char jogador) {
    int linha, coluna;

    while (1) {
        printf("Jogador %c, digite a linha e a coluna (0 a 2): ", jogador);
        scanf("%d %d", &linha, &coluna);

        if (!posicaoValida(linha, coluna)) {
            printf("Posicao invalida! Tente novamente.\n");
            continue;
        }

        if (posicaoOcupada(tabuleiro, linha, coluna)) {
            printf("Posicao ja ocupada! Tente novamente.\n");
            continue;
        }

        tabuleiro[linha][coluna] = jogador;
        break;
    }
}

int verificarVencedor(char tabuleiro[TAM][TAM], char jogador) {
    /* Verifica linhas e colunas */
    for (int i = 0; i < TAM; i++) {
        if (tabuleiro[i][0] == jogador && tabuleiro[i][1] == jogador && tabuleiro[i][2] == jogador) {
            return 1;
        }
        if (tabuleiro[0][i] == jogador && tabuleiro[1][i] == jogador && tabuleiro[2][i] == jogador) {
            return 1;
        }
    }

    /* Verifica diagonais */
    if (tabuleiro[0][0] == jogador && tabuleiro[1][1] == jogador && tabuleiro[2][2] == jogador) {
        return 1;
    }
    if (tabuleiro[0][2] == jogador && tabuleiro[1][1] == jogador && tabuleiro[2][0] == jogador) {
        return 1;
    }

    return 0;
}

int tabuleiroCheio(char tabuleiro[TAM][TAM]) {
    for (int i = 0; i < TAM; i++) {
        for (int j = 0; j < TAM; j++) {
            if (tabuleiro[i][j] == ' ') {
                return 0;
            }
        }
    }
    return 1;
}

int main(void) {
    char tabuleiro[TAM][TAM];
    char jogadorAtual = 'X';
    int vencedor = 0;
    int empate = 0;

    inicializarTabuleiro(tabuleiro);

    printf("=== JOGO DA VELHA ===\n");
    exibirTabuleiro(tabuleiro);

    while (!vencedor && !empate) {
        realizarJogada(tabuleiro, jogadorAtual);
        exibirTabuleiro(tabuleiro);

        vencedor = verificarVencedor(tabuleiro, jogadorAtual);

        if (vencedor) {
            printf("O jogador %c venceu!\n", jogadorAtual);
            break;
        }

        if (tabuleiroCheio(tabuleiro)) {
            empate = 1;
            printf("O jogo empatou!\n");
            break;
        }

        jogadorAtual = (jogadorAtual == 'X') ? 'O' : 'X';
    }

    return 0;
}