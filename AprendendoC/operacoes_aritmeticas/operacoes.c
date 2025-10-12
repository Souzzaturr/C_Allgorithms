//Aprendendo sobre operações aritméticas em C

#include <stdio.h>

int main(void) {
    float num1;
    float num2;
    float divisao;

    printf("Digite um número qualquer...\n");
    scanf("%f", &num1);

    printf("Digite mais um número qualquer..\n");
    scanf("%f", &num2);

    divisao = num1 / num2;

    printf("A divisão de %.1f por %.1f é aproximadamente %.2f!!\n", num1, num2, divisao);

    return 0;
}