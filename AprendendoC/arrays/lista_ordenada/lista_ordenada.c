//Recebe 10 valores, e os organiza em ordem crescente, em C

#include <stdio.h>
#include <string.h>
#include <ctype.h>

int main (void) {
    int vetor_numeros[10];
    int vetor_numeros2[10];
    int numero;
    int menor;

    memset(vetor_numeros2, -1, sizeof(vetor_numeros2));

    printf("\n--- Reorganizator ---\n\n");

    for (int i = 0; i < 10; i++) {
        printf("Digite um número inteiro qualquer: \n");
        scanf("%d", &numero);

        vetor_numeros[i] = numero;
    }

    for (int i = 0; i < 10; i++) {
        menor = __INT_MAX__;

        for (int j = 0; j < 10; j++) {
            if (vetor_numeros[j] != -1 && vetor_numeros[j] < menor) {
                menor = vetor_numeros[j];
            }
        }

        for (int j = 0; j < 10; j++) {
            if (vetor_numeros[j] <= menor) {
                vetor_numeros[j] = -1;
            }
        }

        for (int j = 0; j < 10; j++) {
            if (vetor_numeros2[j] == -1) {
                vetor_numeros2[j] = menor;

                break;
            }
        }
    }

    printf("Os números digitados acima, em ordem crescente, são: ");

    for (int i = 0; i < 10; i++) {
        if (vetor_numeros2[i] != -1) {
            printf("%d, ", vetor_numeros2[i]);
        }
    }
    printf("\n");

    return 0;
}