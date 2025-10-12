//Converte de real para dólar (2025), em C

#include <stdio.h>

int main (void) {
    double real;
    double dolar;

    printf("Quanto você tem na carteira ai? \nR$");
    scanf("%lf", &real);

    printf("Você tem R$%.2f Reais!\n", real);

    dolar = real / 5.53;

    printf("Convertendo para Dólar, ficaria $%.2f!\n", dolar);
    printf("Bom passeio!!\n");

    return 0;
}