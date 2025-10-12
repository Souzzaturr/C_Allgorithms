//Retorna a raiz quadrada de um número

#include <stdio.h>
#include <math.h>

int main(void) {
    int num;
    double raiz;

    printf("Digite algum número abaixo:\n");
    scanf("%d", &num);

    raiz = pow(num, 1.0/2.0);

    printf("A raiz de %d é %.2f\n", num, raiz);

    return 0;
}