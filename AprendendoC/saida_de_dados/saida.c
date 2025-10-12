//Exercitando saída de dados com C

#include <stdio.h>
#include <stdlib.h>

int main(void) {
    printf("Olá, me chamo %s, e tenho %d anos.\n", "Fulano", 18);

    printf("O número de Pi é: %.2f \n", 3.14159265);

    printf("Eu posso usar \\\" para exibir \" (aspas) em uma string que também está definida com aspas.\n");

    printf("Exemplo: \"Fulano\", \"Linguagem C\", \"etc...\"\n");

    printf("O nome da minha máquina é:\n");

    system("uname -n");

    return 0;
}