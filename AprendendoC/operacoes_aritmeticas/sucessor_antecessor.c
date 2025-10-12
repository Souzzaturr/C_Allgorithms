//Este programa exibe o antecessor e o sucessor de um número.

#include <stdio.h>

int main(void) {
    int num;
    int antecessor;
    int sucessor;

    printf("Digite um número qualquer abaixo!\n");
    scanf("%d", &num);

    antecessor = num - 1;
    sucessor = num + 1;

    printf("O antecessor de %d é %d\n", num, antecessor);
    printf("O sucessor de %d é %d\n", num, sucessor);
    printf("Na reta numérica, se representaria assim: ..., %d, %d, %d, ...\n", antecessor, num, sucessor);

    return 0;
}