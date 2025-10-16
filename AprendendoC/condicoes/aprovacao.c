//Recebe 2 notas de um aluno, calcula média e exibe se ele foi aprovado ou não (média mínima sendo 7.0), em C

#include <stdio.h>

int main (void) {
    double nota1;
    double nota2;
    double media;

    printf("Qual a primeira nota do aluno? \n");
    scanf("%lf", &nota1);

    printf("Qual a segunda nota do aluno? \n");
    scanf("%lf", &nota2);

    media = (nota1 + nota2) / 2.0;

    printf("Média do aluno: %.1f \n", media);

    if (media >= 7) {
        printf("Aluno aprovado por média!! \n");
        printf("Boas férias!!\n");

    } else if (media >= 5) {
        printf("Aluno fará exame final!! \n");
        printf("Comparecer para exame final: sábado, às 8:00 da manhã! \n");
        printf("Não se atrase!! \n");

    } else {
        printf("Aluno reprovado por média!! \n");

    }

    return 0;
}