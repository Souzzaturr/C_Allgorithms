//Recebe o nome completo de uma pessoa e retorna o primeiro e o ultimo nome dessa pessoa, em C

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int main (void) {
    char nome[51];
    char primeiro_nome[51];
    char ultimo_nome[51];
    int tamanho_palavra = 0;
    int primeiro_nome_coletado = 0;

    printf("\n--- Primeiro e Último Nome de uma Pessoa ---\n\n");

    printf("Qual o seu nome completo? \n");
    fgets(nome, sizeof(nome), stdin);
    nome[strcspn(nome, "\n")] = '\0';

    for (int i = 0; i <= strlen(nome); i++) {
        if (nome[i] == ' ' || i == strlen(nome)) {
            for (int j = tamanho_palavra; j > 0; j--) {
                if (! primeiro_nome_coletado) {
                    primeiro_nome[tamanho_palavra - j] = nome[i - j];

                    if (j == 1) {
                        primeiro_nome[tamanho_palavra] = '\0';
                        strncpy(ultimo_nome, primeiro_nome, sizeof(primeiro_nome) - 1);
                        primeiro_nome_coletado = 1;
                        tamanho_palavra = 0;
                    }

                } else {
                    ultimo_nome[tamanho_palavra - j] = nome[i - j];

                    if (j == 1) {
                        ultimo_nome[tamanho_palavra] = '\0';
                        tamanho_palavra = 0;
                    }
                }
            }

        } else {
            tamanho_palavra++;
        }
    }

    printf("Bem, %s: \n", primeiro_nome);
    printf("Seu primeiro nome é \"%s\" \n", primeiro_nome);
    printf("Seu último nome é \"%s\" \n", ultimo_nome);
    printf("E seu nome completo é \"%s\" \n", nome);

    return 0;
}