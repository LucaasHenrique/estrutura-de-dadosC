#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct no No;
No *inicializarLista();
No *adicionarNo(int);
void *adicionarFimNo(No *lista);

/*void removerNo(No *lista) {
    No *aux = lista;
    lista = (No*) aux->prox;
    lista->ant = NULL;
    free(aux);
}*/

struct no {
    int id; 
    No *ant;
    No *prox;
};

No* criarNo(int id) {
    No *lista = (No*)malloc(sizeof(No));
    lista->id = id;
    lista->ant = NULL;
    lista->prox = NULL;
    
    return lista;
}

No *incializarLista() {
    No *aux = NULL;
    aux = criarNo(1);
    
    return aux;
}

void *adicionarFimNo(No *lista) {
    lista->prox = criarNo(lista->id+1);
    lista->prox->ant = lista;
}

No *adicionarInicioNo(No* lista) {

    
}

int main() {
    No *lista;
    lista = incializarLista();
    adicionarFimNo(lista);
    adicionarFimNo(lista);
    
    printf("%p\n", lista);
    printf("valor id: %d\n", lista->id);
    
    for (No *p = lista; p!=NULL; p=p->prox) {
        printf("%d\n", p->id);
    }
}
