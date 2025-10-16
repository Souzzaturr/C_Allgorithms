//Programa de aprovar emprestimo, em C

#include <stdio.h>

int main (void) {
    double valor;
    double salario;
    double mensalidade;
    int anos;

    printf("--- Arturo_Bank --- \n\n");
    printf("Deseja solicitar o empréstimo de quantos reais? \n R$");
    scanf("%lf", &valor);

    printf("Para termos mais informações sobre você, digite seu salário: \n R$");
    scanf("%lf", &salario);

    printf("Deseja pagar em quantos anos? \n");
    scanf("%d", &anos);

    mensalidade = valor / (anos * 12);

    if (mensalidade <= salario * 0.3) {
        printf("Emprestimo aprovado com sucesso! \n");
        printf("Valor das mensalidades: R$%.2f \n", mensalidade);

    } else {
        printf("Emprestimo negado! \n");
        printf("Motivo: Valor das mensalidades não pode execer 30%% do salário. \n");
        printf("Valor das mensalidades: R$%.2f \n", mensalidade);
        printf("Salário: R$%.2f \n", salario);
    }

    return 0;
}