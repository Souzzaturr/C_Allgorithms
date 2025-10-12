//Calcula a média arimética de duas notas de um aluno em C

#include <stdio.h>
#include <math.h>

int main (void) {
    double nota1;
    double nota2;
    double media;

    printf("Qual a primeira nota do aluno?\n");
    scanf("%lf", &nota1);

    printf("Qual a segunda nota do aluno?\n");
    scanf("%lf", &nota2);

    media = (nota1 + nota2) / 2.0;

    printf("A média aritmética entre as notas %.2f e %.2f é %.2f!!\n", nota1, nota2, media);

    return 0;
}