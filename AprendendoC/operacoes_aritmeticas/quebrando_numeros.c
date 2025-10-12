//Este programa recebe um número real qualquer e o separa em parte inteira e parte decimal, em C

#include <stdio.h>

int main (void) {
    double numero;
    int inteira;
    double decimal;

    printf("Digite um número real qualquer abaixo!\n");
    scanf("%lf", &numero);

    inteira = numero / 1;
    decimal = numero - inteira;

    printf("O número escolhido foi: %f \n", numero);
    printf("Sua parte inteira é: %d \n", inteira);
    printf("Sua parte decimal é: %f \n", decimal);

    return 0;
}