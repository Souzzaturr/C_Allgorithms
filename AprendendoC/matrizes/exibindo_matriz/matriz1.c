//Recebe uma sequência de números, armazena-os em uma matriz, e exibe a matriz, em C

#include <stdio.h>

int main (void) {
    int matriz[3][3];

    printf("\n--- Matriz ---\n\n");

    for (int i = 0; i < 3; i++) {
        for (int j = 0; j < 3; j++) {
            printf("Digite um número: \n");
            scanf("%d", &matriz[i][j]);
        }
    }

    printf("a lista de números digitados pode formar uma matriz, observe: \n");

    for (int i = 0; i < 3; i++) {
        printf("|");

        for (int j = 0; j < 3; j++) {
            printf(" %d |", matriz[i][j]);
        }

        printf("\n");
    }

    printf("Acima está a matriz formada com todos os valores digitados!! \n");

    return 0;
}