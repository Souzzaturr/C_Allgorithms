//Upgrade de matriz1.c, agora extraindo dados da matriz, em C

#include <stdio.h>

int main (void) {
    int matriz[3][3];
    int soma_pares = 0;
    int soma_terceira_coluna = 0;
    int maior_segunda_linha = -1 * __INT_MAX__;

    printf("\n--- Matriz 2.0 --- \n\n");

    for (int i = 0; i < 3; i++) {
        for (int j = 0; j < 3; j++) {
            printf("Digite um número inteiro qualquer: \n");
            scanf("%d", &matriz[i][j]);
        }
    }

    printf("Os valores digitados podem formar uma matriz 3x3, observe: \n");

    for (int i = 0; i < 3; i++) {
        printf("|");

        for (int j = 0; j < 3; j++) {
            printf(" %d |", matriz[i][j]);
        }

        printf("\n");
    }

    printf("Acima, está a matriz com os valores digitados!! \n");

    for (int i = 0; i < 3; i++) {
        for (int j = 0; j < 3; j++) {
            if (matriz[i][j] % 2 == 0) {
                soma_pares += matriz[i][j];
            }
        }
    }

    for (int i = 0; i < 3; i++) {
        soma_terceira_coluna += matriz[i][2];

        if (matriz[1][i] > maior_segunda_linha) {
            maior_segunda_linha = matriz[1][i];
        }
    }

    printf("A) A soma de todos os valores pares digitados é: %d \n", soma_pares);
    printf("B) A soma dos valores da terceira coluna é: %d \n", soma_terceira_coluna);
    printf("C) O maior valor da segunda linha é: %d \n", maior_segunda_linha);

    return 0;
}
