#include <stdio.h>
#include <string.h>
#include <ctype.h>

int main(void) {
    char nome[200];

    printf("Digite o nome completo: ");
    fgets(nome, sizeof(nome), stdin);

    /* Remove o '\n' deixado pelo fgets, se existir */
    size_t len = strlen(nome);
    if (len > 0 && nome[len - 1] == '\n') {
        nome[len - 1] = '\0';
    }

    int vogais = 0, consoantes = 0, espacos = 0;
    len = strlen(nome);

    for (size_t i = 0; i < len; i++) {
        char c = tolower((unsigned char)nome[i]);

        if (c == ' ') {
            espacos++;
        } else if (isalpha((unsigned char)c)) {
            if (c == 'a' || c == 'e' || c == 'i' || c == 'o' || c == 'u') {
                vogais++;
            } else {
                consoantes++;
            }
        }
    }

    printf("\nNome digitado: %s\n", nome);
    printf("Quantidade de caracteres: %zu\n", len);
    printf("Quantidade de vogais: %d\n", vogais);
    printf("Quantidade de consoantes: %d\n", consoantes);
    printf("Quantidade de espacos em branco: %d\n", espacos);

    return 0;
}