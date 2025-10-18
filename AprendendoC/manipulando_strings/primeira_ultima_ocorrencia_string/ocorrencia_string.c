//Recebe uma string, um caractere, e retorna as posições desse caractere na string, em C

#include <stdio.h>
#include <string.h>

int main (void) {
    char frase[50];
    char caractere;
    int qtd_aparicoes_caractere = 0;
    int primeira_ocorrencia;
    int ultima_ocorrencia = -1;

    printf("\n--- Primeira e Última Ocorrência de uma String --- \n\n");

    printf("Digite uma frase qualquer!! \n");
    fgets(frase, sizeof(frase), stdin);
    frase[strcspn(frase, "\n")] = '\0';

    printf("Deseja saber informações sobre qual caractere, em relação à frase escrita acima? \n");
    scanf("%c", &caractere);

    printf("O caractere escolhido foi: \"%c\". \n", caractere);

    for (int i = 0; i < strlen(frase); i++) {
        if (frase[i] == caractere || (frase[i] == caractere + 32 && caractere >= 65 && caractere <= 90) || (frase[i] == caractere - 32 && caractere >= 97 && caractere <= 122)) {
            qtd_aparicoes_caractere++;
            
            if (ultima_ocorrencia == -1) {
                primeira_ocorrencia = i;
            }

            ultima_ocorrencia = i;
        }
    }

    printf("O caractere \"%c\" aparece %d vezes na frase digitada. \n", caractere, qtd_aparicoes_caractere);
    printf("O caractere \"%c\" aparece pela primeira vez na posição %dº. \n", caractere, primeira_ocorrencia);
    printf("O caractere \"%c\" aparece pela ultima vez na posição %dº. \n", caractere, ultima_ocorrencia);

    return 0;
}