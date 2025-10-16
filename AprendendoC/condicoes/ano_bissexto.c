//Programa recebe do usuario um ano qualquer e exibe se esse ano é bissexto, em C
//Meu primeiro teste de cores no terminal em C

#include <stdio.h>

int main (void) {
    int ano;

    printf("Sou um programa que posso lhe dizer se um ano é bissexto ou não. \n");
    printf("Duvida? Digite um ano qualquer então! \n");
    scanf("%d", &ano);

    if ((ano % 400 == 0) || (ano % 100 != 0) && (ano % 4 == 0)) {
        printf("\033[32mO ano %d é Bissexto! \033[m \n", ano);

    } else {
        printf("\033[31mO ano %d não é Bissexto! \033[m \n", ano);
    }
    printf("Gostou? \n");

    return 0;
}