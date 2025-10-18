//Recebe um nome, e desse nome retorna um conjunto de dados, em C

#include <stdio.h>
#include <string.h>

int main (void) {
    char nome[51];
    int tamanho_sem_espacos = 0;
    int tamanho_primeiro_nome = 0;


    printf("\n--- Analisador de Textos ---\n\n");

    printf("Digite seu nome abaixo: \n");
    fgets(nome, sizeof(nome), stdin);

    nome[strcspn(nome, "\n")] = '\0';

    printf("Seu nome é: %s!!\n", nome);

    printf("Com todas as letras maiúsculas, fica: ");

    for (int i = 0; i < strlen(nome); i++) {
        printf("%c", nome[i] >= 97 && nome[i] <= 122 ? nome[i] - 32 : nome[i]);
    }

    printf("\n");

    printf("Com todas as letras minúsculas, fica: ");

    for (int i = 0; i < strlen(nome); i++) {
        printf("%c", nome[i] >= 65 && nome[i] <= 90 ? nome[i] + 32 : nome[i]);
    }

    printf("\n");

    for (int i = 0; i < strlen(nome); i++) {
        if (nome[i] != ' ') {
            tamanho_sem_espacos++;
        }
    }

    printf("Seu nome tem %d letras!! \n", tamanho_sem_espacos);

    for (int i = 0; i < strlen(nome); i++) {
        if (nome[i] != ' ') {
            tamanho_primeiro_nome++;

        } else {
            break;
        }
    }

    printf("O seu primeiro nome tem %d letras!! \n", tamanho_primeiro_nome);

    return 0;
}