#include <stdio.h>
#include <stdlib.h>

struct No;

void inserir (struct No **fila, int valor);
int remover (struct No **fila);
int primeiro (struct No *fila);
void exibir_fila (struct No *fila);
int tamanho (struct No *fila);
void esvaziar (struct No **fila);

int main () {
    int opcao, num;
    int loop = 1;
    struct No *fila = NULL;

    while (loop) {
        printf("\n--- Fila encadeada ---\n\n");
        printf("[ 1 ] INSERIR\n");
        printf("[ 2 ] REMOVER\n");
        printf("[ 3 ] EXIBIR PRIMEIRO\n");
        printf("[ 4 ] EXIBIR FILA\n");
        printf("[ 5 ] TAMANHO DA FILA\n");
        printf("[ 6 ] ESVAZIAR A FILA\n");
        printf("[ 0 ] SAIR\n\n");

        printf("Escolha uma das opções acima para continuar:\n");
        scanf("%d", &opcao);

        switch (opcao) {
            case 1:
                printf("Digite um número para adicionarmos à fila:\n");
                scanf("%d", &num);

                inserir(&fila, num);

                printf("Número \"%d\" adicionado com sucesso ao final da fila!!\n\n", num);
                break;
            
            case 2:
                if (tamanho(fila)) {
                    num = remover(&fila);

                    printf("Número \"%d\" foi removido com sucesso do inicio da fila!!\n\n", num);

                } else {
                    printf("Impossível remover, a fila está vazia...\n\n");
                }
                break;
            
            case 3:
                if (tamanho(fila)) {
                    num = primeiro(fila);

                    printf("O primeiro número da fila é o \"%d\"!!\n\n", num);

                } else {
                    printf("Não há numeros na fila, a fila está vazia...\n\n");
                }
                break;

            case 4:
                if (tamanho(fila)) {
                    printf("A Fila:\n");

                    exibir_fila(fila);

                } else {
                    printf("Fila vazia...\n\n");
                }
                break;
            
            case 5:
                num = tamanho(fila);

                printf("A fila tem um tamanho de \"%d\" elementos!!\n\n", num);
                break;
            
            case 6:
                esvaziar(&fila);

                printf("Fila esvaziada com sucesso!!\n\n");
                break;
            
            case 0:
                loop = 0;
                break;
            
            default:
                printf("Não entendi o que você quiz dizer...\n");
        }
    }
    esvaziar(&fila);

    printf("Programa finalizado...\n");

    return 0;
}

struct No {
    int dado;
    struct No *prox;
};

void inserir (struct No **fila, int valor) {
    struct No *novono = malloc(sizeof(struct No));
    novono -> dado = valor;
    novono -> prox = NULL;
    if (*fila == NULL) {
        *fila = novono;
    } else {
        struct No *ptr = *fila;
        while (ptr -> prox != NULL) {
            ptr = ptr -> prox;
        }
        ptr -> prox = novono;
    }
    novono = NULL;
}

int remover (struct No **fila) {
    int num = (*fila) -> dado;
    struct No *ptr = *fila;
    *fila = (*fila) -> prox;
    free(ptr);
    ptr = NULL;
    return num;
}

int primeiro (struct No *fila) {
    return fila -> dado;
}

void exibir_fila (struct No *fila) {
    printf("PRIMEIRO -> ");
    while (fila != NULL) {
        printf("%d%s", fila -> dado, fila -> prox == NULL ? " <- FIM DA FILA\n\n" : " <- ");
        fila = fila -> prox;
    }
}

int tamanho (struct No *fila) {
    int tamanho = 0;
    while (fila != NULL) {
        tamanho++;
        fila = fila -> prox;
    }
    return tamanho;
}

void esvaziar (struct No **fila) {
    while (*fila != NULL) {
        struct No *ptr = *fila;
        *fila = (*fila) -> prox;
        ptr -> prox = NULL;
        free(ptr);
    }
}