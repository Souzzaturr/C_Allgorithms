//Recebe 10 números e retorna umas informações, em C

#include <stdio.h>

int main (void) {
    int vetor_numeros[10];
    int vetor_numeros2[10];
    int maior;
    int qtd_num;
    int tem_cinco = 0;

    printf("\n --- Extraindo dados de uma lista de números ---\n\n");

    for (int i = 0; i < 10; i++) {
        printf("Digite um número qualquer: \n");
        scanf("%d", &vetor_numeros[i]);
    }

    for (int i = 0; i < 10; i++) {
        tem_cinco = tem_cinco || vetor_numeros[i] == 5;
        maior = -1;

        for (int j = 0; j < 10; j++) {
            if (vetor_numeros[j] > maior) {
                maior = vetor_numeros[j];
            }
        }

        for (int j = 0; j < 10; j++) {
            if (vetor_numeros[j] == maior) {
                vetor_numeros[j] = -1;
                break;
            }
        }

        vetor_numeros2[i] = maior;
        qtd_num++;
    }

    printf("A) Foram digitados %d números. \n", qtd_num);
    printf("B) O valor 5 %s foi um dos valores digitados. \n", tem_cinco ? "" : "não");
    printf("C) Os valores digitados, em ordem decrescente, são: ");
    
    for (int i = 0; i < 10; i++) {
        printf("%d, ", vetor_numeros2[i]);
    }

    printf("\n");

    return 0;
}