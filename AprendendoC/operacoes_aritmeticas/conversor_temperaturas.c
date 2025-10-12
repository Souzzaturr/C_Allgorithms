//Recebe uma temperatura em Celcius (C°) e retorna em firenheint (F°), em C

#include <stdio.h>

int main (void) {
    double temperatura_c;
    double temperatura_f;

    printf("Está fazendo quantos graus (C°) ai onde você mora?\n");
    scanf("%lf", &temperatura_c);

    temperatura_f = temperatura_c * 9 / 5 + 32;

    printf("Em Fahreinheit, %.1fC° fica %.1fF°!\n", temperatura_c, temperatura_f);
    printf("Agora, sabendo dessa informação, você pode comparar quao quente ou frio é um lugar em outro país!\n");

    return 0;
}