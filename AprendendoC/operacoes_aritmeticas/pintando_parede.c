//Calcula area de uma parede, e quantidade de tinta necessária para pintar (1L => 2m²), em C

#include <stdio.h>

int main (void) {
    double altura;
    double largura;
    double area;
    double litros_tinta;

    printf("Qual a altura da parede que deseja pintar?\n");
    scanf("%lf", &altura);

    printf("Qual a largura da parede que deseja pintar?\n");
    scanf("%lf", &largura);

    area = largura * altura;
    litros_tinta = area / 2.0;

    printf("Você irá pintar uma área de %.1fm x %.1fm, que dá aproximadamente %.1fm².\n", altura, largura, area);
    printf("Para isso, irá precisar de %.1fL de tinta (1L -> 2m²).\n", litros_tinta);

    return 0;
}