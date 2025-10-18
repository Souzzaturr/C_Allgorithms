//Recebe sete números inteiros, e separa-os em impares e pares, em C

#include <stdio.h>
#include <string.h>

int main (void) {
    int array_impares[7];
    int array_pares[7];
    int numero;
    
    memset(array_impares, 0, 28);
    memset(array_pares, 0, 28);

    printf("\n--- Separador impar-par ---\n\n");

    for (int i = 0; i < 7; i++) {
        printf("Digite um número inteiro: \n");
        scanf("%d", &numero);

        if (numero % 2 == 0) {
            array_pares[i] = numero;

        } else {
            array_impares[i] = numero;
        }
    }
    printf("Os números pares digitados foram: ");
    
    for (int i = 0; i < 7; i++) {
        if (array_pares[i] != 0) {
            printf("%d, ", array_pares[i]);
        }
    }
    printf("\n");
    printf("Os números impares digitados foram: ");

    for (int i = 0; i < 7; i++) {
        if (array_impares[i] != 0) {
            printf("%d, ", array_impares[i]);
        }
    }
    printf("\n");

    return 0;
}