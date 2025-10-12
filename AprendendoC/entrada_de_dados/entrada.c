//Aprendendo entrada de dados pelo teclado

#include <stdio.h>

int main(void) {
    int idade = 0;
    float peso = 0;

    printf("Digite abaixo sua idade:\n");
    scanf("%d", &idade);

    printf("Digite abaixo seu peso:\n");
    scanf("%f", &peso);

    printf("Sua idade é: %d anos\n", idade);
    printf("Seu peso é: %.1fkg\n", peso);

    return 0;
}