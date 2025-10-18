//Praticando manipulação de strings, em C

#include <stdio.h>
#include <string.h>

int main (void) {
    char nome[51];

    printf("Digite seu nome completo: \n");
    fgets(nome, sizeof(nome), stdin);

    nome[strcspn(nome, "\n")] = '\0';

    printf("Seu nome é: %s!! \n", nome);

    for (int i = 0; i < strlen(nome); i++) {
        if (nome[i] == 'a' || nome[i] == 'A') {
            nome[i] = '@';
        }
    }

    printf("Saca só o que eu fiz com o seu nome: %s \n", nome);

    printf("O seu nome tem %ld letras!! \n", strlen(nome));

    return 0;
}