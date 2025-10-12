//Exibe a tabuada de um número inserido pelo usuario, em C

#include <stdio.h>

int main (void) {
    int numero;

    printf("Digite abaixo um número inteiro qualquer.\n");
    scanf("%d", &numero);

    printf("Número escolhido: %d\n\n", numero);

    printf("----Tabuada do %d----\n", numero);

    printf("%d X 1 = %d\n", numero, numero * 1);
    printf("%d X 2 = %d\n", numero, numero * 2);
    printf("%d X 3 = %d\n", numero, numero * 3);
    printf("%d X 4 = %d\n", numero, numero * 4);
    printf("%d X 5 = %d\n", numero, numero * 5);
    printf("%d X 6 = %d\n", numero, numero * 6);
    printf("%d X 7 = %d\n", numero, numero * 7);
    printf("%d X 8 = %d\n", numero, numero * 8);
    printf("%d X 9 = %d\n", numero, numero * 9);
    printf("%d X 10 = %d\n", numero, numero * 10);
    printf("----Fim----\n");

    return 0;
}