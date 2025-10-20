// Solicita a quantidade de linhas e colunas para criação das matrizes, lê os valores para cada célula
// das matrizes e exibe a primeira matriz, a segunda matriz, e a soma delas. Em C

#include <stdio.h>
#include <limits.h>

int main () {
    int linhas = 3;
    int colunas = 3;
    int maior1 = INT_MIN;
    int maior2 = INT_MIN;
    int qtd_digitos_maior1 = 1;
    int qtd_digitos_maior2 = 1;
    int qtd_digitos_maior_geral;

    printf("\n--- Soma Matrizes --- \n\n");

    printf("Deseja criar 2 matrizes com quantas linhas x colunas? (Escreva os dois valores abaixo separados por espaço) \n");
    scanf("%d %d", &linhas, &colunas);

    printf("Você escolheu uma soma entre matrizes %dx%d. \n", linhas, colunas);

    int matriz1[linhas][colunas];
    int matriz2[linhas][colunas];

    printf("Defina os valores da matriz 1: \n");

    for (int i = 0; i < linhas; i++) {
        for (int j = 0; j < colunas; j++) {
            printf("%dº elemento da %dª linha: \n", j + 1, i + 1);
            scanf("%d", &matriz1[i][j]);

            if (matriz1[i][j] > maior1) {
                maior1 = matriz1[i][j];
            }
        }
    }

    printf("Defina os valores da matriz 2: \n");

    for (int i = 0; i < linhas; i++) {
        for (int j = 0; j < colunas; j++) {
            printf("%dº elemento da %dª linha: \n", j + 1, i + 1);
            scanf("%d", &matriz2[i][j]);

            if (matriz2[i][j] > maior2) {
                maior2 = matriz2[i][j];
            }
        }
    }

    printf("Valores definidos com sucesso!!\n");
    printf("Segue o resultado final das matrizes: \n\n");

    printf("Matriz 1: \n");

    while (maior1 >= 10) {
        maior1 = maior1 / 10;
        qtd_digitos_maior1++;
    }

    for (int i = 0; i < linhas; i++) {
        printf("| ");

        for (int j = 0; j < colunas; j++) {
            int qtd_digitos_num = 1;

            for (int num = matriz1[i][j]; num >= 10; num /= 10) {
                qtd_digitos_num++;
            }

            for (int acrescenta_digitos = qtd_digitos_maior1 - qtd_digitos_num; acrescenta_digitos > 0; acrescenta_digitos--) {
                printf("0");
            }

            printf("%d%s", matriz1[i][j], j == colunas - 1 ? " |\n" : ", ");
        }
    }

    printf("\nMatriz 2: \n");

    while (maior2 >= 10) {
        maior2 = maior2 / 10;
        qtd_digitos_maior2++;
    }

    for (int i = 0; i < linhas; i++) {
        printf("| ");

        for (int j = 0; j < colunas; j++) {
            int qtd_digitos_num = 1;

            for (int num = matriz2[i][j]; num >= 10; num /= 10) {
                qtd_digitos_num++;
            }

            for (int acrescenta_digitos = qtd_digitos_maior2 - qtd_digitos_num; acrescenta_digitos > 0; acrescenta_digitos--) {
                printf("0");
            }

            printf("%d%s", matriz2[i][j], j == colunas - 1 ? " |\n" : ", ");
        }
    }

    printf("\nA soma de matriz 1 com matriz 2 dá a matriz soma abaixo: \n");

    qtd_digitos_maior_geral = qtd_digitos_maior1 > qtd_digitos_maior2 ? qtd_digitos_maior1 : qtd_digitos_maior2;

    for (int i = 0; i < linhas; i++) {
        printf("| ");

        for (int j = 0; j < colunas; j++) {
            int qtd_digitos_num = 1;
            int soma_celula = matriz1[i][j] + matriz2[i][j];

            for (int num = soma_celula; num >= 10; num /= 10) {
                qtd_digitos_num++;
            }

            for (int acrescenta_digitos = qtd_digitos_maior_geral - qtd_digitos_num; acrescenta_digitos > 0; acrescenta_digitos--) {
                printf("0");
            }

            printf("%d%s", soma_celula, j == colunas - 1 ? " |\n" : ", ");
        }
    }

    return 0;
}