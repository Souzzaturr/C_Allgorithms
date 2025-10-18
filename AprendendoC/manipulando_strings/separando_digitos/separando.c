//Recebe um número entre 0 - 9999 e mostra as dezenas, centenas, milhares, etc... Em C

#include <stdio.h>
#include <string.h>

int main (void) {
    char num[5];
    int unidades = 0;
    int dezenas = 0;
    int centenas = 0;
    int milhares = 0;

    printf("\n--- Separando Dígitos de um Número ---\n\n");

    printf("Digite um número inteiro qualquer que esteja no intervalo de 0 a 9999. \n");
    printf("Incluindo o 0 e o 9999!! \n");
    fgets(num, sizeof(num), stdin);

    num[strcspn(num, "\n")] = '\0';

    printf("O número digitado tem %ld dígitos!! \n", strlen(num));

    switch (strlen(num)) {
        case 1:
            unidades = num[0];
            break;
        case 2:
            unidades = num[1];
            dezenas = num[0];
            break;
        case 3:
            unidades = num[2];
            dezenas = num[1];
            centenas = num[0];
            break;
        case 4:
            unidades = num[3];
            dezenas = num[2];
            centenas = num[1];
            milhares = num[0];
            break;
    }

    printf("O número digitado tem: \n");
    printf("%c Unidades. \n", unidades ? unidades : '0');
    printf("%c Dezenas. \n", dezenas ? dezenas : '0');
    printf("%c Centenas. \n", centenas ? centenas : '0');
    printf("%c Milhares. \n", milhares ? milhares : '0');

    return 0;
}