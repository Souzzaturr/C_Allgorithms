//Praticando comando While, em C

#include <stdio.h>

int main (void) {
    int numero = 1;
    int soma = 0;

    while (numero != 0) {
        printf("Digite um número (0 para finalizar o programa): \n");
        scanf("%d", &numero);

        soma += numero;

        printf("Número digitado: %d \n", numero);
    }

    printf("A soma de todos os números digitados acima é %d \n", soma);
    printf("Programa finalizado... \n");

    return 0;
}