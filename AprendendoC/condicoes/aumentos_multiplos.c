//Recebe um valor que representa um salário e mostra quanto esse salário vai ter de aumento, em C
//Se menor que 1250, 15%; Se maior 10%

#include <stdio.h>

int main (void) {
    double salario;
    double aumento;

    printf("Olá caro funcionário! \n");
    printf("Para saber quanto você vai receber de aumento, digite seu salário abaixo: \n R$");
    scanf("%lf", &salario);

    printf("Seu salário é R$%.2f \n", salario);

    if (salario > 1250) {
        aumento = salario * 0.1;
        printf("Você receberá um aumento de 10%% \n");
        printf("O que irá acrescentar ao seu salário +R$%.2f \n", aumento);

    } else {
        aumento = salario * 0.15;
        printf("Você receberá um aumento de 15%% \n");
        printf("O que irá acrescentar ao seu salário + R$%.2f \n", aumento);
    }

    printf("Seu salário ficará: R$%.2f \n", salario + aumento);

    return 0;
}