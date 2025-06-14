#include <stdio.h>

void insertion_sort(int *vet) {
    for (int i = 0; i < 5; i++) {
        int eleito = vet[i];
        int j = i - 1;

        while (j >= 0 && vet[j] > eleito) {
            vet[j+1] = vet[j];
            j -= 1;
        }

        vet[j+1] = eleito;
    }

}

int main(int argc, char *argv[]) {
    
    int x[5];
    int num;
        
    for (int i = 0; i < 5; i++) {
        printf("digite um numero: ");     
        scanf("%d", &num);    
        x[i] = num;
    }
    
    insertion_sort(x);

    for (int i = 0; i < 5; i++) {
        printf("%d ", x[i]);
    }

    printf("\n");

    return 0;
}
