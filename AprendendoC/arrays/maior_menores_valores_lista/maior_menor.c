//Ler 5 valores e retorna na tela o maior e o menor valor dos 5, e suas respectivas posições, em C

#include <stdio.h>

int main (void) {
    int vetor_numeros[5];
    int maior, posicao_maior;
    int menor, posicao_menor;

    printf("\n--- maior menor ---\n\n");

    for (int i = 0; i < 5; i++) {
        printf("Digite um número: \n");
        scanf("%d", &vetor_numeros[i]);

        if (i == 0) {
            maior = vetor_numeros[i];
            posicao_maior = i;
            menor = vetor_numeros[i];
            posicao_menor = i;

        } else if (vetor_numeros[i] > maior) {
            maior = vetor_numeros[i];
            posicao_maior = i;

        } else if (vetor_numeros[i] < menor) {
            menor = vetor_numeros[i];
            posicao_menor = i;
        }
    }
    printf("O maior número digitado foi: %d \n", maior);
    printf("O número %d foi o %dº número a ser digitado. \n", maior, posicao_maior + 1);
    printf("O menor número digitado foi: %d \n", menor);
    printf("O número %d foi o %dº número a ser digitado. \n", menor, posicao_menor + 1);

    return 0;
}