#include <stdio.h>

struct Ponto {
    int x;
    int y;
};

int main () {
    int eixo_x;
    int eixo_y;

    printf("Digite as coordenadas x e y abaixo de um ponto qualquer. \n");
    scanf("%d %d", &eixo_x, &eixo_y);

    struct Ponto posicao = {eixo_x, eixo_y};

    printf("Eixo X escolhido: %d \n", posicao.x);
    printf("Eixo Y escolhido: %d \n", posicao.y);

    printf("Vamos alterar o eixo X, qual posição para X você quer? \n");
    scanf("%d", &posicao.x);

    printf("Nova coordenada X: %d \n", posicao.x);
    printf("O struct Ponto, contendo 2 elementos do tipo int, ocupa %ld bytes na memória. \n", sizeof(posicao));

    return 0;
}