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

ListaGen* insere_no(ListaGen* list, ListaGen* novo) {
    novo->prox = list;
    return novo;
}

int vazia(ListaGen *list) {
    return list == NULL;
}

void imprime_lista(ListaGen *list) {
    if (vazia(list)) return;

    printf("tipo: %d\n", list->tipo);
    imprime_lista(list->prox);
}

float area(ListaGen* l) {
    float a;

    switch (l->tipo) {
        case RET:
            Retangulo *r = (Retangulo*) l->info;
            a = r->b * r->h;
            break;

        case TRI:
            Triangulo *t = (Triangulo*) l->info;
            a = t->b * t->h;
            break;
        case CIR:
            Circulo *cir = (Circulo*) l->info;
            a = 3.14 * (cir->r * cir->r);
            break;
    }
    return a;
}

int main(int argc, char *argv[]) {

    ListaGen *list;
    list = NULL;

    list = insere_no(list, cria_cir(20));
    //list = insere_no(list, cria_tri(20, 10));
    //list = insere_no(list, cria_ret(50, 20));

    imprime_lista(list);

    printf("area do circulo: %2.f\n", area(list));

    free(list);
}
