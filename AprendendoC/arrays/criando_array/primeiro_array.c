//Praticando uso de arrays, em C

#include <stdio.h>

int main (void) {
    int vetor_numeros[5];
    int tamanho_vetor;

    for (int i = 0; i < 5; i++) {
        printf("Digite um número inteiro qualquer: \n");
        scanf("%d", &vetor_numeros[i]);
    }

    printf("Os números digitados foram: ");

    for (int i = 0; i < 5; i++) {
        printf("%d, ", vetor_numeros[i]);
    }

    tamanho_vetor = sizeof(vetor_numeros) / 4;
    
    printf("\n");
    printf("A quantidade de números digitados é: %d \n", tamanho_vetor);
    printf("O ultimo número digitado foi: %d \n", vetor_numeros[tamanho_vetor - 1]);

    return 0;
}