#include <stdio.h>
#include <stdlib.h>

struct No;

void adiciona_no (struct No **raiz, int valor);
void exibe_arvore_ordem (struct No *raiz);
void esvazia_arvore (struct No **raiz);

int main () {
    struct No *arvore = NULL;
    int resposta;
    int num;
    int loop = 1;

    while (loop) {
        printf("\n--- Arvore Binária ---\n\n");
        printf("Escolha uma das opções abaixo:\n");
        printf("[ 1 ] Exibir Valores\n");
        printf("[ 2 ] Adicionar Valor\n");
        printf("[ 3 ] Sair\n\n");
        printf("Sua resposta: ");
        scanf("%d", &resposta);

        switch (resposta) {
            case 1 :
            if (arvore == NULL) {
                    printf("Arvore vazia...\n");
                    printf("Você deve adicionar pelo menos 1 valor à avore!!\n");
                    printf("Digite um valor: ");
                    scanf("%d", &num);
                    
                    adiciona_no(&arvore, num);
                    
                    printf("Valor adicionado com sucesso à arvore!!\n");
                }
                
                printf("Exibindo valores da arvore abaixo:\n");
                
                exibe_arvore_ordem(arvore);
                break;

            case 2:
                printf("Digite um valor qualquer: ");
                scanf("%d", &num);

                adiciona_no(&arvore, num);
                
                printf("Número adicionado com sucesso à arvore!!\n");
                break;
        
            case 3:
                printf("Saindo...\n");
                loop = 0;
                break;

            default:
                printf("Não entendi o que você quiz dizer...\n");
                printf("Poderia digitar uma das 3 opções? [ 1 ] [ 2 ] [ 3 ]\n");
                scanf("%d", &resposta);
        }
    }

    esvazia_arvore(&arvore);

    return 0;
}

struct No {
    int dado;
    struct No *esq;
    struct No *dir;
};


void adiciona_no (struct No **raiz, int novo_valor) {
    struct No *nova_folha = malloc(sizeof(struct No));
    nova_folha -> dado = novo_valor;
    nova_folha -> esq = NULL;
    nova_folha -> dir = NULL;

    if (*raiz != NULL) {
        struct No *ptr = *raiz;
        struct No *ptr_aux = *raiz;
        
        while (ptr_aux != NULL) {
            ptr = ptr_aux;
            
            if (novo_valor > ptr_aux -> dado) {
                ptr_aux = ptr_aux -> dir;
                
            } else if (novo_valor < ptr_aux -> dado) {
                ptr_aux = ptr_aux -> esq;
                
            } else break;
        }

        if (novo_valor > ptr -> dado) {
            ptr -> dir = nova_folha;

        } else if (novo_valor < ptr -> dado) {
            ptr -> esq = nova_folha;

        } else {
            free(nova_folha);
        }

    } else {
        *raiz = nova_folha;
    }
        
    return;
}

void exibe_arvore_ordem (struct No *raiz) {
    if (raiz == NULL) return;

    exibe_arvore_ordem(raiz -> esq);

    printf("%d ", raiz -> dado);

    exibe_arvore_ordem(raiz -> dir);

    return;
}

void esvazia_arvore (struct No **raiz) {
    if (*raiz == NULL) return;

    esvazia_arvore(&((*raiz) -> dir));
    esvazia_arvore(&((*raiz) -> esq));

    free(*raiz);
}