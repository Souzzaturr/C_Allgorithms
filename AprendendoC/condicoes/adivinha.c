//O computador "pensa" em um número, e o usuario chuta que número é esse, em C

#include <stdio.h>
#include <stdlib.h>
#include <time.h>

int main (void) {
    srand(time(NULL));
    int numero_computador = (rand() % 5) + 1;
    int numero_usuario;

    printf("(PC) Pensei em um número aqui de 1 a 5, consegue adivinhar qual foi? \n");
    scanf("%d", &numero_usuario);

    if (numero_computador == numero_usuario) {
        printf("(PC) Parabéns, você adivinhou o número que eu estava pensando!! \n");

    } else {
        printf("(PC) Que pena, você errou!! \n");
    }

    printf("(PC) Eu pensei no número %d, e você chutou %d! \n", numero_computador, numero_usuario);

    return 0;
}