#include <stdio.h>
#include <stdlib.h>

struct Ponto {
    int x;
    int y;
};

int main (int argc, char *argv[]) {
    //int x;
    //x = 10;

    struct Ponto *ponteiro;
    printf("Endereço armazenado em ponteiro na declaração: %p \n", ponteiro);
    ponteiro = malloc(sizeof(struct Ponto));
    printf("Endereço armazenado em ponteiro após receber endereço de memória fresquinha: %p \n", ponteiro);

    ponteiro -> x = 10;
    ponteiro -> y = 20;

    printf("Ponteiro -> X: %d \n", ponteiro -> x);
    printf("Ponteiro -> Y: %d \n", ponteiro -> y);

    struct Ponto posicao;
    posicao.x = 5;
    posicao.y = 8;

    struct Ponto *ptr;
    ptr = &posicao;

    printf("X: %d \n", ptr -> x);
    printf("Y: %d \n", ptr -> y);

    //int *ponteiro;
    //ponteiro = &x;

    //printf("%d \n", *ponteiro);
    //*ponteiro = 5;
    //printf("%d \n", x);

    return 0;
}