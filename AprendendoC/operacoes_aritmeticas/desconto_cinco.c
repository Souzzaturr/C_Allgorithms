//Recebe o preço de um produto e calcula como ficara esse preço com 5% de desconto, em C

#include <stdio.h>

int main (void) {
    double preco;
    double preco_desconto;

    printf("Digite abaixo o preço de um produto que deseja: \nR$");
    scanf("%lf", &preco);

    printf("O produto custa R$%.2f \n", preco);

    preco_desconto = preco * 0.95;

    printf("Com desconto de 5%%, custará: R$%.2f\n", preco_desconto);
    printf("Recomendação: espere até uma blackfriday!\n");

    return 0;
}