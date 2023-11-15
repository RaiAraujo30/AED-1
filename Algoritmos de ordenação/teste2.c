#include <stdio.h>
#define MAX 100

struct lista_sequencial {
    int elemento[MAX];
    int particao;
};


void troca (struct lista_sequencial *l, int pos1, int pos2){
    int temp = l->elemento[pos1];
    l->elemento[pos1] = l->elemento[pos2];
    l->elemento[pos2] = temp;
}

void selection_sort(struct lista_sequencial *l){
    int i, posicao ;
    for (i =0 ; i< l->particao; i++){
        posicao = procura_menor(l,i);
        troca(l, i, posicao);
    }
}