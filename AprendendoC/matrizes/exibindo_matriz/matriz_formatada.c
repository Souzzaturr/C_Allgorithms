// Solicita ao usuario o tamanho da matriz e depois recebe o valor de cada célula da matriz

#include <stdio.h>
#include <limits.h>

int main () {
    int linhas = 3;
    int colunas = 3;
    int maior = INT_MIN;
    int qtd_digitos_maior = 1;

    printf("\n--- Exibindo Matriz --- \n\n");

    printf("Deseja uma matriz com quantas linhas x colunas? (Escreva os dois valores abaixo separados por espaço) \n");
    scanf("%d %d", &linhas, &colunas);

    printf("Você escolheu uma matriz %dx%d. \n", linhas, colunas);

    int matriz[linhas][colunas];

    for (int i = 0; i < linhas; i++) {
        for (int j = 0; j < colunas; j++) {
            printf("Defina o %dº elemento da %dª linha: \n", j + 1, i + 1);
            scanf("%d", &matriz[i][j]);

            if (matriz[i][j] > maior) {
                maior = matriz[i][j];
            }
        }
    }

    printf("Valores definidos com sucesso!!\n");
    printf("Segue o resultado final da matriz: \n");

    while (maior >= 10) {
        maior = maior / 10;
        qtd_digitos_maior++;
    }

    for (int i = 0; i < linhas; i++) {
        printf("| ");

        for (int j = 0; j < colunas; j++) {
            int qtd_digitos_num = 1;

            for (int num = matriz[i][j]; num >= 10; num /= 10) {
                qtd_digitos_num++;
            }

            for (int acrescenta_digitos = qtd_digitos_maior - qtd_digitos_num; acrescenta_digitos > 0; acrescenta_digitos--) {
                printf("0");
            }

            printf("%d%s", matriz[i][j], j == colunas - 1 ? " |\n" : ", ");
        }
    }

    return 0;
}