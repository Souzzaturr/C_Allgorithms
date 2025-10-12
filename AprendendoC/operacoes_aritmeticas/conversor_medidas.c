//Converte um valor de metro para as demais unidades de medidas, em C

#include <stdio.h>

int main (void) {
    double metros;
    double km;
    double hm;
    double dam;
    double dm;
    double cm;
    double mm;

    printf("Digite alguma medida (em metros M) abaixo.\n");
    scanf("%lf", &metros);

    km = metros / 1000.0;
    hm = metros / 100.0;
    dam = metros / 10.0;
    dm = metros * 10;
    cm = metros * 100;
    mm = metros * 1000;

    printf("A medida escolhida foi: %.2fm\n", metros);
    printf("Em quilômetros, fica: %.3fkm\n", km);
    printf("Em hectômetros, fica: %.2fhm\n", hm);
    printf("Em decâmetros, fica: %.2fdam\n", dam);
    printf("Em decímetros, fica: %.2fdm\n", dm);
    printf("Em centímetros, fica: %.2fcm\n", cm);
    printf("Em milimetros, fica: %.2fmm\n", mm);

    return 0;
}