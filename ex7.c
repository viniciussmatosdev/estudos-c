#include <stdio.h>
#include <string.h>

#define TAM 100

int main(void) {
    char nome1[TAM], nome2[TAM];

    printf("Digite o primeiro nome: ");
    fgets(nome1, sizeof(nome1), stdin);

    printf("Digite o segundo nome: ");
    fgets(nome2, sizeof(nome2), stdin);

    /* Remove o '\n' de cada string, se existir */
    size_t len1 = strlen(nome1);
    if (len1 > 0 && nome1[len1 - 1] == '\n') nome1[len1 - 1] = '\0';

    size_t len2 = strlen(nome2);
    if (len2 > 0 && nome2[len2 - 1] == '\n') nome2[len2 - 1] = '\0';

    size_t maiorTam = (len1 > len2) ? len1 : len2;

    int resultado = strncmp(nome1, nome2, maiorTam);

    if (resultado == 0) {
        printf("\nOs nomes sao iguais.\n");
    } else if (resultado < 0) {
        printf("\nOs nomes sao diferentes.\n");
        printf("\"%s\" e alfabeticamente maior que \"%s\".\n", nome2, nome1);
    } else {
        printf("\nOs nomes sao diferentes.\n");
        printf("\"%s\" e alfabeticamente maior que \"%s\".\n", nome1, nome2);
    }

    return 0;
}