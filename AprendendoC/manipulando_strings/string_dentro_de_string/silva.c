//Recebe o nome de uma pessoa e retorna se essa pessoa tem "Silva" no nome, em C

#include <stdio.h>
#include <string.h>

int main (void) {
    char nome[51];
    int tem_silva = 0;

    printf("\n--- Procurando uma String Dentro de Outra --- \n\n");

    printf("Olá, qual o seu nome?? \n");
    fgets(nome, sizeof(nome), stdin);

    nome[strcspn(nome, "\n")] = '\0';

    if (strlen(nome) >= 5) {
        for (int i = 0; i < strlen(nome) - 4; i++) {
            if ((nome[i] == 'S' || nome[i] == 's') && (nome[i + 1] == 'I' || nome[i + 1] == 'i') && (nome[i + 2] == 'L' || nome[i + 2] == 'l') && (nome[i + 3] == 'V' || nome[i + 3] == 'v') && (nome[i + 4] == 'A' || nome[i + 4] == 'a')) {
                tem_silva = 1;
                break;
            }
        }
    }

    printf("O seu nome, \"%s\" %stem \"Silva\"!! \n", nome, tem_silva ? "" : "não ");

    return 0;
}