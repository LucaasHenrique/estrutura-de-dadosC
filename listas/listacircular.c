#include <stdio.h>
#include <stdlib.h>

struct lista {
    int num;
    struct lista *prox;
};

typedef struct lista Lista;

Lista *criar(int num) {
    Lista *l = (Lista*) malloc(sizeof(Lista));
    l->num = num;

    return l;
}

Lista *insere(Lista *list, int num) {
    Lista *novo = criar(num);
    Lista *aux;


    if (list == NULL) {
        novo->prox = novo;
    } else {
        aux = list;

        do {
            aux = aux->prox;
        } while (aux->prox != list);

        aux->prox = novo;
        novo->prox = list;
    }

    return novo;
}

int vazia(Lista* list) {
    return list == NULL;
}

void imprime(Lista *list) {

    if (vazia(list)) return;

    printf("num: %d\n", list->num);

    imprime(list->prox);
}

int main(int argc, char *argv[]) {

    Lista *list;
    list = NULL;

    list = insere(list, 5);
    list = insere(list, 2);

    imprime(list);
    return 0;
}
