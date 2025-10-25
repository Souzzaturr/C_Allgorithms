// Uma pilha simples, com ponteiros... Em C

#include <stdio.h>
#include <stdlib.h>

struct No {
    int valor;
    struct No *prox;
};

void adiciona (struct No *no, struct No *novono);
void limpar (struct No *no);

int main () {
    int primeiro_num = 1;
    int num = 0;
    struct No *First_Stack_in_C = malloc(sizeof(struct No));
    First_Stack_in_C -> prox = NULL;

    printf("\n--- Primeira Lista Encadeada em C --- \n\n");

    while (1) {
        printf("Digite um valor qualquer positivo diferente de zero: \n");
        scanf("%d", &num);

        if (num > 0) {
            if (primeiro_num) {
                First_Stack_in_C -> valor = num;
                primeiro_num = 0;

            } else {
                struct No *ptr = malloc(sizeof(struct No));
                ptr -> valor = num;
                ptr -> prox = NULL;
                adiciona(First_Stack_in_C, ptr);
            }

        } else {
            break;
        }
    }

    struct No *ptr2 = First_Stack_in_C;

    printf("Os valores digitados foram: \n");

    while (ptr2 != NULL) {
        printf("%d%s", ptr2 -> valor, ptr2 -> prox == NULL ? "\n" : ", ");
        ptr2 = ptr2 -> prox;
    }

    limpar(First_Stack_in_C);
    First_Stack_in_C = NULL;

    return 0;
}

void adiciona (struct No *no, struct No *novono)  {
    while (no -> prox != NULL) {
        no = no -> prox;
    }
    no -> prox = novono;
    return;
}

void limpar (struct No *no) {
    struct No *ptr = no;
    while (ptr != NULL) {
        ptr = ptr -> prox;
        free(no);
        no = ptr;
    }
    return;
}