//Recebe o nome de uma cidade e retorna se o nome dessa cidade começa com santo, em C

#include <stdio.h>
#include <string.h>

int main (void) {
    char cidade[51];
    int tem_santo;

    printf("\n--- Verificando as Primeiras Letras de um Texto --- \n\n");

    printf("Digite o nome da cidade que você mora!! \n");
    fgets(cidade, sizeof(cidade), stdin);

    cidade[strcspn(cidade, "\n")] = '\0';

    if (strlen(cidade) >= 5) {
        tem_santo = ((cidade[0] == 'S' || cidade[0] == 's') && (cidade[1] == 'A' || cidade[1] == 'a') && (cidade[2] == 'N' || cidade[2] == 'n') && (cidade[3] == 'T' || cidade[3] == 't') && (cidade[4] == 'O' || cidade[4] == 'o'));
    }

    printf("O nome da cidade \"%s\" %stem Santo no primeiro nome!! \n", cidade, tem_santo ? "" : "não ");

    return 0;
}