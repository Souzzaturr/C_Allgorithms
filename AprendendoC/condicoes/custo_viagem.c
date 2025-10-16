//Programa recebe a distancia a ser percorrida em uma viagem e calcula o preço da passagem, em C

#include <stdio.h>

int main (void) {
    int distancia;
    double preco;

    printf("--- BusTur.Net --- \n\n");
    printf("Pretende andar quantos km? \n");
    scanf("%d", &distancia);

    printf("Calculando passagem... \n");

    if (distancia <= 200) {
        preco = distancia * 0.5;
        printf("A passagem para a viagem de %dkm irá custar R$%.2f \n", distancia, preco);

    } else {
        preco = distancia * 0.45;
        printf("A passagem para a viagem de %dkm irá custar R$%.2f \n", distancia, preco);
        printf("Já com desconto de 10%% \n");
    }
    printf("Boa viagem!! \n");

    return 0;
}