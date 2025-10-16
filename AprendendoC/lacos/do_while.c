//Praticando comando do-while, em C

#include <stdio.h>

int main (void) {
    int numero;
    int soma = 0;

    do {
        printf("Digite um número qualquer (0 para finalizar o programa): \n");
        scanf("%d", &numero);

        printf("Número digitado: %d \n", numero);

        soma += numero;

    } while (numero != 0);

    printf("A soma de todos os números digitados é: %d \n", soma);
    printf("Programa finalizado...\n");

    return 0;
}