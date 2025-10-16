//Praticando desvio de fluxos com o comando if, em C

#include <stdio.h>
#include <stdbool.h>

int main (void) {
    int numero;

    printf("Digite um número qualquer abaixo: \n");
    scanf("%d", &numero);

    if (numero) {
        printf("O fluxo normal desse código foi desviado\n");
        printf("Usando Condições!!\n");
        printf("%d \n", numero > 3);
    }

    printf("Gostou?\n");

    return 0;
}