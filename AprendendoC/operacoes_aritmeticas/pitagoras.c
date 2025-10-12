//Programa recebe medida de 2 catetos e retorna a medida da hipotenusa, em C
//Fórmula: h² = c1² + c2²

#include <stdio.h>
#include <math.h>

int main (void) {
    int cateto1;
    int cateto2;
    double hipotenusa;

    printf("--- Pitágoras ---\n\n");
    printf("Digite a medida do cateto 1: \n");
    scanf("%d", &cateto1);

    printf("Digite a medida do cateto 2: \n");
    scanf("%d", &cateto2);

    hipotenusa = pow(pow(cateto1, 2) + pow(cateto2, 2), 1.0/2.0);

    printf("Calculando a hipotenusa de um triângulo retângulo de catetos medindo %d e %d, temos: \n", cateto1, cateto2);
    printf("Hipotenusa = %.2f \n", hipotenusa);

    return 0;
}