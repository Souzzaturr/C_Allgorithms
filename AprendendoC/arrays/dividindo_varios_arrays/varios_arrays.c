//Recebe varios valores e retorna a lista de números digitados +2 listas com valores impares e pares, em C

#include <stdio.h>
#include <string.h>

int main (void) {
    int vetor_numeros[10];
    int vetor_numeros_ordenados[10];
    int vetor_pares[10];
    int vetor_impares[10];
    int menor;

    memset(vetor_numeros_ordenados, -1, sizeof(vetor_numeros_ordenados));
    memset(vetor_pares, -1, sizeof(vetor_pares));
    memset(vetor_impares, -1, sizeof(vetor_impares));

    printf("\n--- Dividindo Valores em Vários Arrays ---\n\n");

    for (int i = 0; i < 10; i++) {
        printf("Digite um valor: \n");
        scanf("%d", &vetor_numeros[i]);
    }

    for (int i = 0; i < 10; i++) {
        menor = __INT_MAX__;

        for (int j = 0; j < 10; j++) {
            if (vetor_numeros[j] != -1 && vetor_numeros[j] < menor) {
                menor = vetor_numeros[j];
            }
        }

        for (int j = 0; j < 10; j++) {
            if (vetor_numeros[j] == menor) {
                vetor_numeros[j] = -1;
            }
        }

        if (menor != __INT_MAX__) {
            
            if (menor % 2 == 0) {
                vetor_pares[i] = menor;
                
            } else {
                vetor_impares[i] = menor;
            }
            
            vetor_numeros_ordenados[i] = menor;
        }
    }

    printf("Os diferentes números digitados, em ordem crescente, são: \n");

    for (int i = 0; i < 10; i++) {
        if (vetor_numeros_ordenados [i] != -1) {
            printf("%d, ", vetor_numeros_ordenados[i]);
        }
    }
    printf("\n");

    printf("Dos valores digitados, os valores pares são: \n");

    for (int i = 0; i < 10; i++) {
        if (vetor_pares[i] != -1) {
            printf("%d, ", vetor_pares[i]);
        }
    }
    printf("\n");

    printf("Dos valores digitados, os valores impares são: \n");

    for (int i = 0; i < 10; i++) {
        if (vetor_impares[i] != -1) {
            printf("%d, ", vetor_impares[i]);
        }
    }
    printf("\n");

    return 0;
}