//Praticando laço for, em C

#include <stdio.h>

int main (void) {
    int qtd_numeros;
    int numero;
    int soma = 0;

    printf("Quantos números você quer somar? \n");
    scanf("%d", &qtd_numeros);

    for (int i = 1; i <= qtd_numeros; i++) {
        printf("Digite o %dº número: \n", i);
        scanf("%d", &numero);

        soma += numero;

        printf("%dº número digitado: %d \n", i, numero);
    }

    printf("A soma de todos os %d números digitados é: %d \n", qtd_numeros, soma);

    return 0;
}