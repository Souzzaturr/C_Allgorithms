#include <stdio.h>
#include <stdlib.h>

struct No {
    int dado;
    struct No *prox;
};

void empilhar (struct No **pilha_destino, struct No *no);
int desempilhar (struct No **pilha);
int topo (struct No *pilha);
void exibir_pilha (struct No *pilha);
int tamanho_pilha (struct No *pilha);
void esvaziar_pilha (struct No **pilha);

int main () {
    int opcao, elemento, tamanho;
    int loop = 1;
    struct No *pilha = NULL;

    while (loop) {
        printf("\n--- Exercício de Pilha --- \n\n");
        printf("[ 1 ] EMPILHAR\n");
        printf("[ 2 ] DESEMPILHAR\n");
        printf("[ 3 ] EXIBIR ELEMENTO DO TOPO\n");
        printf("[ 4 ] EXIBIR A PILHA\n");
        printf("[ 5 ] TAMANHO DA PILHA\n");
        printf("[ 6 ] ESVAZIAR A PILHA\n");
        printf("[ 0 ] SAIR\n\n");
        
        printf("Escolha uma das opções acima:\n");
        scanf("%d", &opcao);

        switch (opcao) {
            case 1:
                printf("Digite um novo valor a ser empilhado na pilha:\n");
                scanf("%d", &elemento);

                struct No *ptr = malloc(sizeof(struct No));
                ptr -> dado = elemento;

                if (pilha == NULL) {
                    pilha = ptr;

                } else {
                    empilhar(&pilha, ptr);
                }

                printf("Elemento adicionado com sucesso!!\n");
                break;

            case 2:
                if (tamanho_pilha(pilha)) {
                    elemento = desempilhar(&pilha);

                    printf("Elemento %d desempilhado com sucesso!!\n", elemento);

                } else {
                    printf("Pilha já está vazia...\n");
                }

                break;
            
            case 3:
                if (tamanho_pilha(pilha)) {
                    elemento = topo(pilha);
                    
                    printf("TOPO -> %d\n", elemento);

                } else {
                    printf("Pilha vazia, nenhum elemento no topo...\n");
                }

                break;
            
            case 4:
                printf("Exibindo a pilha...\n");

                exibir_pilha(pilha);
                break;
            
            case 5:
                tamanho = tamanho_pilha(pilha);

                printf("A pilha tem tamanho de %d elementos!!\n", tamanho);
                break;

            case 6:
                esvaziar_pilha(&pilha);

                printf("Pilha esvaziada com sucesso!!\n");
                break;
            
            case 0:
                loop = 0;
                printf("Finalizando programa...\n");
                break;

            default:
                printf("Não entendi o que você quiz dizer, digite uma opção novamente!!\n");
                break;

        }
    }

    esvaziar_pilha(&pilha);

    return 0;
}

void empilhar (struct No **pilha_destino, struct No *no) {
    no -> prox = *pilha_destino;
    *pilha_destino = no;
}

int desempilhar (struct No **pilha) {
    if ((*pilha) == NULL) {
        return 0;
    } else {
        struct No *ptr = *pilha;
        int elemento = (*pilha) -> dado;
        *pilha = (*pilha) -> prox;
        free(ptr);
        return elemento;
    }
}

int topo (struct No *pilha) {
    if (pilha == NULL) {
        return 0;
    } else {
        return pilha -> dado;
    }
}

void exibir_pilha (struct No *pilha) {
    if (pilha == NULL) {
        printf("Pilha vazia...\n");
    } else {
        printf("TOPO ->");
        while (pilha) {
            printf(" %d%s", pilha -> dado, pilha -> prox == NULL ? "\n" : " ->");
            pilha = pilha -> prox;
        }
    }
}

int tamanho_pilha (struct No *pilha) {
    int tamanho = 0;
    while (pilha) {
        pilha = pilha -> prox;
        tamanho++;
    }
    return tamanho;
}

void esvaziar_pilha (struct No **pilha) {
    struct No *ptr;
    while (*pilha) {
        ptr = *pilha;
        *pilha = (*pilha) -> prox;
        ptr -> prox = NULL;
        free(ptr);
    }
}