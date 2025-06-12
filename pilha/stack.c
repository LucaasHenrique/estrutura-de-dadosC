#include <stdio.h>
#include <stdlib.h>

typedef struct No No;
typedef struct Pilha Pilha;

struct No {
    int valor;
    struct No *prox;
};

struct Pilha {
    No *topo;
    int tamanho; 
};

void iniciar_pilha(Pilha *pilha) {
    
    pilha->topo = NULL;
    pilha->tamanho = 0;

}

Pilha *push(Pilha *pilha, int valor) {
    
    No *novo = (No*) malloc(sizeof(No));
    novo->valor = valor;
    novo->prox = pilha->topo;

    pilha->topo = novo;
    pilha->tamanho += 1;

    return pilha;
}

void pecorre_pilha(Pilha *pilha) { 
    No *aux = pilha->topo;

    while (aux != NULL) {
        printf("%d\n", aux->valor);
        aux = aux->prox;
    }
}

Pilha *pop(Pilha *pilha) {
    No *antigoTopo = pilha->topo;
    pilha->topo = pilha->topo->prox;
    free(antigoTopo);

    return pilha;
}

int main(int argc, char *argv[]){
    
    Pilha *pilha = (Pilha*) malloc(sizeof(Pilha));
    iniciar_pilha(pilha);
    pilha = push(pilha, 5);
    pilha = push(pilha, 3);
    pilha = push(pilha, 10); 

    pecorre_pilha(pilha);
    
    pop(pilha);
    printf("\n");

    pecorre_pilha(pilha);

    pop(pilha);
    printf("\n");
    
    pecorre_pilha(pilha);

    return 0;
}

