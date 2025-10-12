//Calcula o preço do aluguel de um carro, em C

#include <stdio.h>

int main (void) {
    int km_rodados;
    int dias;
    double aluguel;

    printf("---- SISTEMA ARTURO'S CARS ----\n\n");
    printf("Por quantos dias deseja alugar um de nosso carros?\n");
    scanf("%d", &dias);

    printf("Pretende andar quantos kms?\n");
    scanf("%d", &km_rodados);

    aluguel = km_rodados * 0.15 + dias * 60;

    printf("Para ficar %d dias com nossos carros, e andar %d kms, você precisará pagar o aluguel!\n", dias, km_rodados);
    printf("O aluguel fica: R$%.2f! \n", aluguel);

    return 0;
}