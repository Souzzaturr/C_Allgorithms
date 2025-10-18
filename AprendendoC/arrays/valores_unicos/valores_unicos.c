//Recebe vários números e guarda-os em um vetor, em C
//Os números não podem ser guardados repetidamente

#include <stdio.h>
#include <string.h>

int main (void) {
    int vetor_numeros[10];
    int vetor_numeros_nao_repetidos[10];
    int se_repete = 0;

    memset(vetor_numeros, 0, 40);
    memset(vetor_numeros_nao_repetidos, 0, 40);

    for (int i = 0; i < 10; i++) {
        printf("Digite um número inteiro qualquer. \n");
        scanf("%d", &vetor_numeros[i]);
    }

    for (int i = 0; i < 10; i++) {
        for (int j = 0; j < 10; j++) {
            if (vetor_numeros[i] == vetor_numeros_nao_repetidos[j]) {
                se_repete = 1;

                break;
            }
        }

        if (! se_repete) {
            for (int j = 0; j < 10; j++) {
                if (vetor_numeros_nao_repetidos[j] == 0) {
                    vetor_numeros_nao_repetidos[j] = vetor_numeros[i];

                    break;
                }
            }
        }
        se_repete = 0;
    }

    printf("Todos os diferentes valores digitados foram: ");

    for (int i = 0; i < 10; i++) {
        if (vetor_numeros_nao_repetidos[i] != 0) {
            printf("%d, ", vetor_numeros_nao_repetidos[i]);
        }
    }
    printf("\n");

    return 0;
}