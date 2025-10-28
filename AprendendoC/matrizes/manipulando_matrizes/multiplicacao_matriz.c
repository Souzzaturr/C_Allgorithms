// Para a operação ser possível, o numero de colunas da primeira matriz deve ser igual ao número de linhas da segunda.
// Em C 
// >:)

#include <stdio.h>
#include <limits.h>

void exibir_matriz (int *matriz, int linhas, int colunas, int maior);

int main () {
    int linhas1 = 3;
    int colunas1 = 3;
    int linhas2 = 3;
    int colunas2 = 3;
    int maior1 = INT_MIN;
    int maior2 = INT_MIN;
    int maior_produto = INT_MIN;

    printf("\n--- Produto Matrizes --- \n\n");

    printf("Deseja criar a matriz 1 com quantas linhas x colunas? (Escreva os dois valores abaixo separados por espaço) \n");
    scanf("%d %d", &linhas1, &colunas1);
    
    printf("Matriz 1 será de tamanho %dx%d. \n", linhas1, colunas1);
    
    printf("Deseja criar a matriz 2 com quantas linhas x colunas? (Escreva os dois valores abaixo separados por espaço) \n");
    scanf("%d %d", &linhas2, &colunas2);

    if (colunas1 == linhas2) {
        
        int matriz1[linhas1][colunas1];
        int matriz2[linhas2][colunas2];
        int matriz_produto[linhas1][colunas2];
        
        printf("Matriz 2 será de tamanho %dx%d. \n", linhas2, colunas2);
        
        printf("Defina os valores da matriz 1: \n");
        
        for (int i = 0; i < linhas1; i++) {
            for (int j = 0; j < colunas1; j++) {
                printf("%dº elemento da %dª linha: \n", j + 1, i + 1);
                scanf("%d", &matriz1[i][j]);
                
                if (matriz1[i][j] > maior1) {
                    maior1 = matriz1[i][j];
                }
            }
        }
        
        printf("Defina os valores da matriz 2: \n");

        for (int i = 0; i < linhas2; i++) {
            for (int j = 0; j < colunas2; j++) {
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

        exibir_matriz(&matriz1[0][0], linhas1, colunas1, maior1);

        printf("\nMatriz 2: \n");

        exibir_matriz(&matriz2[0][0], linhas2, colunas2, maior2);

        printf("\nO produto da matriz 1 pela matriz 2 será uma nova matriz, de tamanho %dx%d. \n", linhas1, colunas2);

        printf("\nMatriz Produto: \n");
        
        for (int i = 0; i < linhas1; i++) {

            for (int j = 0; j < colunas2; j++) {
                int soma = 0;

                for (int k = 0; k < linhas2; k++){
                    soma += matriz1[i][k] * matriz2[k][j];
                    
                    if (soma > maior_produto) {
                        maior_produto = soma;
                    }
                }

                matriz_produto[i][j] = soma;
            }
        }

        exibir_matriz(&matriz_produto[0][0], linhas1, colunas2, maior_produto);

    } else {
        printf("Não é possível realizar a multiplicação entre a matriz 1 e a matriz 2!!\n");
        printf("Motivo: a quantidade de colunas da matriz 1 é diferente da quantidade de linhas da matriz 2. \n");
    }

    return 0;
}

void exibir_matriz (int *matriz, int linhas, int colunas, int maior) {
    int qtd_digitos_maior = 1;
    for (int num = maior; num >= 10; num /= 10) {
        qtd_digitos_maior++;
    }
    for (int i = 0; i < linhas; i++) {
        printf("| ");
        for (int j = 0; j < colunas; j++) {
            int qtd_digitos_num = 1;
            for (int num = matriz[i * colunas + j]; num >= 10; num /= 10) {
                qtd_digitos_num++;
            }
            for (int digitos_a_mais = qtd_digitos_maior - qtd_digitos_num; digitos_a_mais > 0; digitos_a_mais--) {
                printf("0");
            }
            printf("%d%s", matriz[i * colunas + j], j == colunas - 1 ? " |\n" : ", ");
        }
    }
}