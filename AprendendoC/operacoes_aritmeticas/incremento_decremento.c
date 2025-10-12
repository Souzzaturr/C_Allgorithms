//Praticando operadores de incremento e decremeto em C

#include <stdio.h>

int main(void) {
    int num;

    printf("Digite um número:\n");
    scanf("%d", &num);

    printf("O número que você escolheu é %d\n", num++);
    printf("Seu sucessor é %d\n", num--);
    printf("Seu antecessor é %d\n", --num);

    return 0;
}