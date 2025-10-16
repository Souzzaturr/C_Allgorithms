//Recebe um número de 1 a 7 e diz qual dia da semana corresponde a esse número, em C
//Levando em conta a seguinte ordem: Dom, Seg, Ter, Quar, Quin, Sex, Sab

#include <stdio.h>

int main (void) {
    int dia;

    printf("Digite abaixo um número de 1 a 7: \n");
    scanf("%d", &dia);

    switch (dia) {
        case 1:
            printf("Dia %d corresponde a Domingo. \n", dia);
            break;
        case 2:
            printf("Dia %d corresponde a Segunda-Feira. \n", dia);
            break;
        case 3:
            printf("Dia %d corresponde a Terça-Feira. \n", dia);
            break;
        case 4:
            printf("Dia %d corresponde a Quarta-Feira. \n", dia);
            break;
        case 5:
            printf("Dia %d corresponde a Quinta-Feira. \n", dia);
            break;
        case 6:
            printf("Dia %d corresponde a Sexta-Feira. \n", dia);
            break;
        case 7:
            printf("Dia %d corresponde a Sábado. \n", dia);
            break;
        default:
            printf("Não há um dia na semana que corresponda ao número %d. \n", dia);
    }

    return 0;
}