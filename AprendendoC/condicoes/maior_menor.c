//Programa recebe 3 número e exibe qual é o maior e qual é o menor, em C

#include <stdio.h>

int main (void) {
    int num1;
    int num2;
    int num3;
    int maior;
    int menor;

    printf("Se você me der 3 valores, eu direi qual é o maior e qual é o menor! \n");
    printf("Digite o primeiro valor: \n");
    scanf("%d", &num1);

    printf("Digite o segundo valor: \n");
    scanf("%d", &num2);

    printf("Digite o terceiro valor: \n");
    scanf("%d", &num3);

    printf("Os valores lidos foram: %d, %d, %d \n", num1, num2 ,num3);

    maior = num1;
    menor = num1;

    if (num2 > maior) {
        maior = num2;

    }
    if (num3 > maior) {
        maior = num3;
    }

    if (num2 < menor) {
        menor = num2;

    }
    if (num3 < menor) {
        menor = num3;
    }

    printf("O maior número lido foi: \033[33m%d\033[m \n", maior);
    printf("O menor número lido foi: \033[33m%d\033[m \n", menor);

    return 0;
}