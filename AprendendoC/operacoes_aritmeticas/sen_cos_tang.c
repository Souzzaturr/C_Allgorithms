//Recebe um angulo e retorna o seno, cosseno, e tangente desse angulo, em C

#include <stdio.h>
#include <math.h>

int main (void) {
    const double PI = 3.141592653589793;
    double grau;
    double rad;

    printf("--- SEN COS TAN ---\n\n");
    printf("Digite abaixo um ângulo que você deseja saber seu seno, cosseno e tangente.\n");
    scanf("%lf", &grau);

    rad = grau * PI / 180;

    printf("Angulo escolhido: %.2f° \n", grau);
    printf("O seno de %.2f° é: %.2f° \n", grau, sin(rad));
    printf("O cosseno de %.2f° é: %.2f° \n", grau, cos(rad));
    printf("A tangente de %.2f° é: %.2f° \n", grau, tan(rad));

    return 0;
}