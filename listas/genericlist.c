#include <stdio.h>
#include <stdlib.h>
#include "genericlist.h"

#define RET 0
#define TRI 1
#define CIR 2

struct listagen {
    int tipo;
    void *info;
    struct listagen *prox;
};

typedef struct listagen ListaGen;

ListaGen* cria_tri(float b, float h) {
    Triangulo *t;
    ListaGen *list;

    t = (Triangulo*) malloc(sizeof(Triangulo));
    t->b = b;
    t->h = h;

    list = (ListaGen*) malloc(sizeof(ListaGen));
    list->tipo = TRI;
    list->info = t;
    list->prox = NULL;

    return list;
}


ListaGen* cria_ret(float b, float h) {
    Retangulo *r;
    ListaGen *list;

    r = (Retangulo*) malloc(sizeof(Retangulo));
    r->b = b;
    r->h = h;

    list = (ListaGen*) malloc(sizeof(ListaGen));
    list->tipo = RET;
    list->info = r;
    list->prox = NULL;

    return list;
}

ListaGen* cria_cir(float r) {
    Circulo *c;
    ListaGen *list;

    c = (Circulo*) malloc(sizeof(Circulo));
    c->r = r;

    list = (ListaGen*) malloc(sizeof(ListaGen));
    list->tipo = CIR;
    list->info = c;
    list->prox = NULL;

    return list;
}

int vazia(ListaGen *list) {
    return list == NULL;
}

void imprime_lista(ListaGen *list) {
    if (vazia(list)) return;

    printf("tipo: %d\n", list->tipo);
    imprime_lista(list->prox);
}

int main(int argc, char *argv[]) {

    ListaGen *list;

    list = cria_ret(50, 20);

}
