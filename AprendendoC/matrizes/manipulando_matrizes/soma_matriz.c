// Solicita a quantidade de linhas e colunas para criação das matrizes, lê os valores para cada célula
// das matrizes e exibe a primeira matriz, a segunda matriz, e a soma delas. Em C

#include <stdio.h>
#include <limits.h>

void exibir_matriz (int *matriz, int n_linhas, int n_colunas, int maior_num);

int main () {
    int linhas = 3;
    int colunas = 3;
    int maior1 = INT_MIN;
    int maior2 = INT_MIN;
    int maior_geral = INT_MIN;

    printf("\n--- Soma Matrizes --- \n\n");

    printf("Deseja criar 2 matrizes com quantas linhas x colunas? (Escreva os dois valores abaixo separados por espaço) \n");
    scanf("%d %d", &linhas, &colunas);

    printf("Você escolheu uma soma entre matrizes %dx%d. \n", linhas, colunas);

    int matriz1[linhas][colunas];
    int matriz2[linhas][colunas];
    int matriz_soma[linhas][colunas];

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

    exibir_matriz(&matriz1[0][0], linhas, colunas, maior1);

    printf("\nMatriz 2: \n");

    exibir_matriz(&matriz2[0][0], linhas, colunas, maior2);

    printf("\nA soma de matriz 1 com matriz 2 dá a matriz soma abaixo: \n");

    for (int i = 0; i < linhas; i++) {
        for (int j = 0; j < colunas; j++) {
            matriz_soma[i][j] = matriz1[i][j] + matriz2[i][j];

            if (matriz_soma[i][j] > maior_geral) {
                maior_geral = matriz_soma[i][j];
            }
        }
    }

    exibir_matriz(&matriz_soma[0][0], linhas, colunas, maior_geral);

    return 0;
}

void exibir_matriz (int *matriz, int n_linhas, int n_colunas, int maior_num) {
    int qtd_digitos_max = 1;
    while (maior_num >= 10) {
        maior_num /= 10;
        qtd_digitos_max++;
    }
    for (int i = 0; i < n_linhas; i++) {
        printf("| ");
        for (int j = 0; j < n_colunas; j++) {
            int qtd_digitos_num = 1;
            for (int num = matriz[i * n_colunas + j]; num >= 10; num /= 10) {
                qtd_digitos_num++;
            }
            for (int digitos_a_mais = qtd_digitos_max - qtd_digitos_num; digitos_a_mais > 0; digitos_a_mais--) {
                printf("0");
            }
            printf("%d%s", matriz[i * n_colunas + j], j == n_colunas - 1 ? " |\n" : ", ");
        }
    }
}