//Retorna o dobro, o tiplo, e a raiz quadrada de um número

#include <stdio.h>
#include <math.h>

int main (void) {
    int numero;
    int dobro;
    int triplo;
    double raiz;

    printf("Digite um número qualquer:\n");
    scanf("%d", &numero);

    dobro = numero * 2;
    triplo = numero * 3;
    raiz = pow(numero, 1.0/2.0);

    printf("O número escolhido foi: %d\n", numero);
    printf("O dobro de %d é %d\n", numero, dobro);
    printf("O triplo de %d é %d\n", numero, triplo);
    printf("A raiz quadrada de %d é %.2f\n", numero, raiz);

    return 0;
}