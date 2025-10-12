//Recebe o salario de um funcionário qualquer e exibe seu salário com aumento de 15%, em C

#include <stdio.h>

int main (void) {
    double salario;
    double salario_aumento;

    printf("Olá funcionário, digite abaixo seu salário para saber como ficará após o reajuste! \nR$");
    scanf("%lf", &salario);

    salario_aumento = salario * 1.15;

    printf("Seu salário é: R$%.2f\n", salario);
    printf("Seu salário após o reajuste de 15%% ficará: R$%.2f\n", salario_aumento);
    printf("Bom fim de semana!!\n");

    return 0;
}