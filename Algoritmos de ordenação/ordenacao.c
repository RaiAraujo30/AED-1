#include <stdio.h>
#include <stdlib.h>
#include <string.h>




#define MAX 10


struct lista_sequencial {
    int valores[MAX];
    int tamanho;
};

void merge_sort(struct lista_sequencial *l, int inicio, int fim);

void merge(struct lista_sequencial *l, int inicio, int meio, int fim);

void inicializar (struct lista_sequencial * l){
    l->tamanho = 0;
}



void selection_sort(int lista[], int tamanho){
    for (int i=0; i< tamanho - 1; ++i){
        int minIndex = i;
        for (int j = i + 1; j < tamanho; j++){
            if(lista[j] < lista[minIndex]){
                minIndex = j;
            } 
        }if(minIndex != i){
                int aux = lista[i];
                lista[i] = lista[minIndex];
                lista[minIndex] = aux;
            }
    }
}


void bubble_sort(struct lista_sequencial *l, int tamanho) {
    for (int i = 0; i < tamanho - 1; i++) {
        for (int j = tamanho -1; j > i; j--) {
            if (l->valores[j] < l->valores[j-1]) {
                int aux = l->valores[j];
                l->valores[j] = l->valores[j - 1];
                l->valores[j - 1] = aux;
            }
        }
    }
}


void insertion_sort(int lista[], int tamanho){
    for(int i = 1; i < tamanho; i++){
        int pivo = lista [i];
        int j = i - 1;
        while (j >= 0 && lista[j] > pivo){
            lista[j + 1] = lista[j];
            j--;
        }
        lista[j+1] = pivo;
    }
}




void merge_sort(struct lista_sequencial *l, int inicio, int fim) {
    if (inicio < fim - 1) { // Caso base: intervalo tem pelo menos dois elementos
        int meio = (inicio + fim) / 2;
        merge_sort(l, inicio, meio);
        merge_sort(l, meio, fim);
        merge(l, inicio, meio, fim);
    }
}

void merge(struct lista_sequencial *l, int inicio, int meio, int fim) {
    int *temp;
    int i, j, k;
    int tamanho = fim - inicio;
    temp = (int *)malloc(sizeof(int) * tamanho);

    for (i = inicio, j = meio, k = 0; i < meio && j < fim; k++) {
        if (l->valores[i] <= l->valores[j]) {
            temp[k] = l->valores[i];
            i++;
        } else {
            temp[k] = l->valores[j];
            j++;
        }
    }

    while (i < meio) {
        temp[k] = l->valores[i];
        i++;
        k++;
    }

    while (j < fim) {
        temp[k] = l->valores[j];
        j++;
        k++;
    }

    for (i = inicio, k = 0; k < tamanho; k++, i++) {
        l->valores[i] = temp[k];
    }

    free(temp);
}


void troca(int* a, int* b){
    int temp = *a;
    *a = *b;
    *b = temp;   
}

int partition(struct lista_sequencial *l, int inicio, int fim) {
    int pivo = l->valores[inicio];  // Usar o primeiro elemento como pivo
    int i = inicio + 1;
    int j = fim;

    while (1) {
        while (i <= j && l->valores[i] <= pivo) {
            i++;
        }
        while (l->valores[j] > pivo) {
            j--;
        }
        if (i < j) {
            troca(&(l->valores[i]), &(l->valores[j]));
        } else {
            break;
        }
    }

    troca(&(l->valores[inicio]), &(l->valores[j]));
    return j;
}

void quickSort(struct lista_sequencial *l, int inicio, int fim) {
    if (inicio < fim) {
        int p = partition(l, inicio, fim);
        quickSort(l, inicio, p - 1);
        quickSort(l, p + 1, fim);
    }
}
void trocar(int* a, int* b) {
    int temp = *a;
    *a = *b;
    *b = temp;
}
void maxHeapify(struct lista_sequencial *l, int raiz) {
    int maior = raiz;
    int esquerda = 2 * raiz + 1;
    int direita = 2 * raiz + 2;

    if (esquerda < l->tamanho && l->valores[esquerda] > l->valores[maior])
        maior = esquerda;

    if (direita < l->tamanho && l->valores[direita] > l->valores[maior])
        maior = direita;

    if (maior != raiz) {
        trocar(&(l->valores[raiz]), &(l->valores[maior]));
        maxHeapify(l, maior);
    }
}

void heapSort(struct lista_sequencial *l) {
    for (int i = l->tamanho / 2 - 1; i >= 0; i--)
        maxHeapify(l, i);

    for (int i = l->tamanho - 1; i > 0; i--) {
        trocar(&(l->valores[0]), &(l->valores[i]));
        l->tamanho--;
        maxHeapify(l, 0);
    }
}

int main() {
    int arr[] = {12, 11, 13, 5, 6, 7};
    int tamanho = sizeof(arr) / sizeof(arr[0]);

    printf("Array antes da ordenacao: ");
    for (int i = 0; i < tamanho; i++) {
        printf("%d ", arr[i]);
    }
    printf("\n");


    printf("Array depois da ordenacao: ");
    for (int i = 0; i < tamanho; i++) {
        printf("%d ", arr[i]);
    }
    printf("\n");

    return 0;
}