//Lista Duplamente Encadeada... EM C >:)
#include <stdio.h>
#include <stdlib.h>

struct No {
    int dado;
    struct No *prox;
    struct No *prev;
};

struct Lista {
    int tamanho;
    struct No *primeiro;
    struct No *ultimo;
};

void inserir (struct Lista *ptr, struct No *novono, int posicao);
int remover (struct Lista *ptr, int posicao);
void exibir_lista (struct Lista *ptr, int ordem);
void esvaziar (struct Lista *ptr);

int main () {
    int resposta, num, posicao, ordem;
    int loop = 1;
    struct Lista lista;

    while (loop) {
        printf("\n--- Lista Duplamente Encadeada ---\n\n");
        printf("Escolha uma das opções abaixo:\n");
        printf("[ 1 ] Inserir um número na lista\n");
        printf("[ 2 ] Remover um número da lista\n");
        printf("[ 3 ] Exibir toda a lista\n");
        printf("[ 4 ] Esvaziar toda a lista\n");
        printf("[ 5 ] Sair\n\n");
        
        scanf("%d", &resposta);

        switch (resposta) {
            case 1:
                printf("Digite um número para ser adicionado à lista:\n");
                scanf("%d", &num);

                struct No *ptr = malloc(sizeof(struct No));
                ptr -> dado = num;
                ptr -> prox = NULL;
                ptr -> prev = NULL;
                
                if (lista.tamanho == 0) {
                    posicao = 0;

                } else {
                    printf("Digite a posição em que esse número vai ser adicionado na lista:\n");
                    scanf("%d", &posicao);

                    while (posicao < 0) {
                        printf("Digite um numero positivo para sabermos em qual posição deseja adicionar esse número!!\n");
                        scanf("%d", &posicao);
                    }
                }

                inserir(&lista, ptr, posicao);
                
                printf("Número adicionado à lista com sucesso!!\n");
                break;
            
            case 2:
                if (lista.tamanho > 0) {
                    if (lista.tamanho == 1) {
                        posicao = 0;

                    } else {
                        printf("Deseja remover um elemento de qual posição da lista?\n");
                        scanf("%d", &posicao);

                        while (posicao >= lista.tamanho || posicao < 0) {
                            printf("Digite uma posição na lista que contenha um elemento!!\n");
                            scanf("%d", &posicao);
                        }
                    }

                    num = remover(&lista, posicao);
                    printf("\nNúmero %d removido com sucesso da posição %d!!\n", num, posicao);

                } else {
                    printf("Lista está vazia...\n");
                }
                
                break;
            
            case 3:
                if (lista.tamanho > 0) {
                    printf("Deseja que a lista seja exibida normalmente ou de trás pra frente?\n");
                    printf("[ 1 ] para ordem normal\n");
                    printf("[ 0 ] para ser exibida de trás pra frente\n");
                    scanf("%d", &ordem);
                    
                    while (ordem != 0 && ordem != 1) {
                        printf("Digite apenas 1 ou 0!! [1] para ordem normal, [0] para de trás pra frente.\n");
                        scanf("%d", &ordem);
                    }

                    exibir_lista(&lista, ordem);

                    // Exibir lista na ordem normal ou inversa? >:)

                } else {
                    printf("Lista está vazia...\n");
                }

                break;

            case 4:
                if (lista.tamanho > 0) {
                    esvaziar(&lista);
                    printf("Lista esvaziada com sucesso!!\n");

                } else {
                    printf("Lista já está vazia...\n");
                }

                break;
            
            case 5:
                loop = 0;
                break;
            
            default:
                printf("Opção incorreta, escolha uma das opções, de 1 a 5.\n");
                break;
        }
    }

    esvaziar(&lista);

    printf("Finalizando programa...\n");

    return 0;
}

void inserir (struct Lista *ptr, struct No *novono, int posicao) {
    if (ptr -> tamanho == 0) {
        ptr -> primeiro = novono;
        ptr -> ultimo = novono;

    } else if (posicao >= ptr -> tamanho) {
        ptr -> ultimo -> prox = novono;
        novono -> prev = ptr -> ultimo;
        ptr -> ultimo = novono;

    } else if (posicao == 0) {
        novono -> prox = ptr -> primeiro;
        ptr -> primeiro -> prev = novono;
        ptr -> primeiro = novono;

    } else {
        struct No *ptr1 = ptr -> primeiro;

        for (int i = 0; i < posicao - 1; i++) {
            ptr1 = ptr1 -> prox;
        }

        novono -> prox = ptr1 -> prox;
        novono -> prev = ptr1;
        novono -> prox -> prev = novono;
        ptr1 -> prox = novono;
    }

    ptr -> tamanho++;
}

int remover (struct Lista *ptr, int posicao) {
    int num;
    struct No *ptr1;
    if (posicao == 0) {
        ptr1 = ptr -> primeiro;
        ptr -> primeiro = ptr1 -> prox;
        num = ptr1 -> dado;
        ptr1 -> prox -> prev = NULL;
        ptr1 -> prox = NULL;
        free(ptr1);

    } else if (posicao == ptr -> tamanho - 1) {
        ptr1 = ptr -> ultimo;
        ptr -> ultimo = ptr1 -> prev;
        num = ptr1 -> dado;
        ptr1 -> prev -> prox = NULL;
        ptr1 -> prev = NULL;
        free(ptr1);

    } else {
        ptr1 = ptr -> primeiro;

        for (int i = 0; i < posicao; i++) {
            ptr1 = ptr1 -> prox;
        }

        num = ptr1 -> dado;
        ptr1 -> prev -> prox = ptr1 -> prox;
        ptr1 -> prox -> prev = ptr1 -> prev;
        ptr1 -> prox = NULL;
        ptr1 -> prev = NULL;
        free(ptr1);
    }

    ptr -> tamanho--;

    return num;
}

void exibir_lista (struct Lista *ptr, int ordem) {
    struct No *ptr1 = ordem ? ptr -> primeiro : ptr -> ultimo;

    printf("\nLista Duplamente Encadeada %s==>", ordem ? "" : "Invertida ");

    for (int i = 0; i < ptr -> tamanho; i++) {
        printf(" %d %s", ptr1 -> dado, i < ptr -> tamanho - 1 ? "==" : "\n");
        ptr1 = ordem ? ptr1 -> prox : ptr1 -> prev;
    }
}

void esvaziar (struct Lista *ptr) {
    struct No *ptr1, *ptr2;
    ptr1 = ptr -> primeiro;
    
    for (int i = 0; i < ptr -> tamanho; i++) {
        ptr2 = ptr1;
        ptr1 = ptr1 -> prox;
        free(ptr2);
    }
    
    ptr -> primeiro = NULL;
    ptr -> ultimo = NULL;
    ptr -> tamanho = 0;
}