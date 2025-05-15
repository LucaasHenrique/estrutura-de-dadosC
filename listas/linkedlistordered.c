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

Lista* cria(int num) {
    Lista *p = (Lista*) malloc(sizeof(Lista));

    p->info = num;
    return p;
}

// inserção no início: retorna a lista atualizada
Lista* insere(Lista *list, int num) {
    Lista *novo = cria(num);
    Lista *ant = NULL;
    Lista *p = list;

    while (p != NULL && p->info < num) {
        ant = p;
        p = p->prox;
    }

    if (ant == NULL) {
        novo->prox = list;
        list = novo;
    } else {
        novo->prox = ant->prox;
        ant->prox = novo;
    }

    return list;
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

    imprime(list);
    printf("\n");

    libera(list);
    return 0;
}
