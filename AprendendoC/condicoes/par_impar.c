//Programa recebe do usuario um número inteiro qualquer e exibe se é par ou impar, em C

#include <stdio.h>

int main (void) {
    int numero;

    printf("Escolha um número qualquer e digite-o abaixo: \n");
    scanf("%d", &numero);

    if (numero % 2 == 0) {
        printf("O número %d é PAR. \n", numero);

    } else {
        printf("O número %d é ÍMPAR. \n", numero);
    }

    return 0;
}