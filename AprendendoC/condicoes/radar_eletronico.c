//Radar eletrônico (Limite de velocidade: 80km/h), em C

#include <stdio.h>

int main (void) {
    int velocidade;

    printf("Digite a velocidade do carro (em km/s): \n");
    scanf("%d", &velocidade);

    printf("Velocidade registrada com sucesso (%dkm/h) \n", velocidade);

    if (velocidade <= 80) {
        printf("Velocidade dentro do limite. (80km/h) \n");
        printf("Carro liberado! \n");

    } else {
        printf("Velocidade acima do limite (80km/h) \n");
        printf("Carro será multado. \n");
        printf("Calculando valor da multa... \n");
        printf("Será cobrado multa no valor de R$%d \n", (velocidade - 80) * 7);
    }

    return 0;
}