#include <stdio.h>
#include <stdlib.h>

struct lista {
    int info;
    struct lista* prox;
};

typedef struct lista Lista;


// funcão de inicialização: retorna uma lista vazia
Lista* inicializa(void) {
    return NULL;
}

// inserção no início: retorna a lista atualizada
Lista* insere(Lista *list, int i) {
    Lista *novo = (Lista*) malloc(sizeof(Lista));

    novo->info = i;
    novo->prox = list;

    return novo;
}

void imprime(Lista *list) {
    Lista *p;
    for (p = list; p != NULL; p = p->prox) {
        printf("info = %d\n", p->info);
    }
}

int vazia(Lista *list) {
    return list == NULL;
}

Lista* busca(Lista *list, int num) {
    Lista *p;

    for (p = list; p != NULL; p->prox) {
        if (p->info == num) {
            return p;
        }
    }

    return NULL;
}

Lista* retira(Lista *list, int num) {
    Lista *ant = NULL;
    Lista *p = list;

    while (p != NULL && p->info != num) {
        ant = p;
        p = p->prox;
    }

    // verifica se achou o elemento
    if (p == NULL) {
        return list; // nao achou o elemento
    }

    // retira o elemento
    if (ant == NULL) {
        list = p->prox;
    } else {
        ant->prox = p->prox;
    }

    free(p);
    return list;
}

void libera(Lista *list) {
    Lista *p = list;
    while (p != NULL) {
        Lista *t = p->prox;
        free(p);
        p = t;
    }
}

// imprime elementos de forma recursiva!!
void imprime_rec(Lista *list) {

    if (vazia(list)) return;

    printf("info: %d\n", list->info);
    imprime_rec(list->prox);
}

// retira elemento recursivamente
Lista* retira_rec(Lista *list, int num) {

    if (vazia(list)) return list;

    if (list->info == num) {
         Lista* t = list;
         list = list->prox;
         free(t);

    } else {
        list->prox = retira_rec(list->prox, num);
    }

    return list;
}

void libera_rec(Lista *list) {

    if (!vazia(list)) {
        libera_rec(list->prox);
        free(list);
    }
}

int main(int argc, char *argv[]) {
    Lista *list;
    list = inicializa();
    list = insere(list, 23);
    list = insere(list, 45);
    list = insere(list, 65);
    list = insere(list, 90);
    list = insere(list, 43);
    list = insere(list, 53);
    list = insere(list, 421);
    list = insere(list, 931);

    //imprime(list);
    printf("\n");

    retira(list, 23);

    //imprime(list);
    printf("\n");

    retira(list, 421);

    //imprime(list);
    printf("\n");


    imprime_rec(list);
    printf("\n");


    retira_rec(list, 931);
    imprime(list);

    libera(list);

    return 0;
}
