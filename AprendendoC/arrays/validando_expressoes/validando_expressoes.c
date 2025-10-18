//Recebe uma string que vai representar uma operação matemática e vai exibir se o uso dos parênteses está correto ou não, em C

#include <stdio.h>
#include <string.h>

int main (void) {
    char expressao[51];
    int parenteses;

    printf("\n --- Expression Analisys --- \n\n");

    printf("Digite abaixo uma expressão matemática qualquer. \n");
    fgets(expressao, sizeof(expressao), stdin);

    expressao[strcspn(expressao, "\n")] = '\0';

    for (int i = 0; i < 50; i++) {
        if (expressao[i] == '(') {
            parenteses++;

        } else if (expressao[i] == ')') {
            parenteses--;
        }

        if (parenteses < 0) {
            break;
        }
    }

    printf("A sintaxe da expressão está %s!! \n", parenteses == 0 ? "CORRETA" : "ERRADA");

    return 0;
}