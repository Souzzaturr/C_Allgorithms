//Programa recebe a medida de 3 retas e exibe se essas 3 retas podem formar um triângulo, em C

#include <stdio.h>

int main (void) {
    int reta1;
    int reta2;
    int reta3;

    printf("Sabia que nem toda combinação de 3 retas podem formar um triângulo? \n");
    printf("Se liga: \n");
    printf("Digite a medida de uma primeira reta qualquer: \n");
    scanf("%d", &reta1);

    printf("Digite a medida de uma segunda reta qualquer: \n");
    scanf("%d", &reta2);

    printf("Digite a medida de uma terceira reta qualquer: \n");
    scanf("%d", &reta3);

    if ((reta1 + reta2 > reta3) && (reta1 + reta3 > reta2) && (reta2 + reta3 > reta1)) {
        printf("\033[32m As retas %d, %d, %d podem formar um triângulo!! \n \033[m", reta1, reta2, reta3);

    } else {
        printf("\033[31m As retas %d, %d, %d não podem formar um triângulo!! \n \033[m", reta1, reta2, reta3);

    }

    return 0;
}