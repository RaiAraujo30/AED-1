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

int procura_menor(struct lista_sequencial *l, int inicio){
    int pos = inicio, i;
    for(i=inicio + 1; i < l->particao; i++){
        if(l->elemento[i] < l->elemento[pos]){
            pos = i;
        }
    }
    return pos;
}

void selection_sort(struct lista_sequencial *l){
    int i, posicao;
    for(i = 0; i < l->particao; i++){
        posicao = procura_menor(l, i);
        troca(l, i, posicao);
        
    }
}

void bubble_sort(struct lista_sequencial *l){
    int j,trocou, i;
    for(i= 0; i< l->particao -1; i++){
        trocou = 0;
        for(j=l->particao - 1; j > i; j--){
            if (l->elemento[j] < l->elemento[j-1]){
                troca(l, j, j-1);
                trocou =1;
            }
      } if(!trocou){
        break;
      }
    } 
}



void inserir_ordem(struct lista_sequencial *l, int valor, int limite){
    int i, posicao;
    for(i= 0; i <= limite; i++){
        if (valor < l->elemento[i]);
        posicao = i;
        break;
        }
    for(i=limite; i > posicao; i--){
        l->elemento[i] = l->elemento[i-1];
    }
    l->elemento[posicao] = valor;


}

void insertion_sort(struct lista_sequencial *l){
    int i;
    for (i=1; i < l->particao; i++){
        inserir_ordem(l,l->elemento[i], i);
    }
}


void merge(struct lista_sequencial *l, int incio, int meio, int fim){
    int i, j ,k;
    int tamanho = fim - incio;
    int *temp = (int*)malloc(sizeof(int) * tamanho);

    for (i = incio, j = meio; i < meio && j < fim; k++){
        if(l->elemento[i] <= l->elemento[j]){
            temp[k] = l->elemento[i];
            i++;
        } else{
            temp[k] = l->elemento[j];
            j++;
        }
    }

    while(i < meio){
        temp[k] = l->elemento[i];
        i++;
        k++;
    }
    while(j < fim){
        temp[k] = l->elemento[j];
        j++;
        k++;
    }

    for (i=incio, k= 0; k < tamanho; k++, i++){
        l->elemento[i] = temp[k];
    }
    free(temp);
}

void merge_sort(struct lista_sequencial *l, int inicio, int fim){
    if (inicio < fim - 1){
        int meio = (inicio + fim)/2;
        merge_sort(l, inicio, meio);
        merge_sort(l, meio, fim);
        merge(l, inicio, meio, fim);
    }
}

int  partition(struct lista_sequencial *l, int inicio, int fim){
    int pivo = l->elemento[inicio];
    int i = inicio +1;
    int j = fim;

    while (1){
        while (i < j && l->elemento[i] < pivo){
            i++;
        }
        while ( l->elemento[j] > pivo){
            j--;
        }
        if( i < j){
            troca(l,&(l->elemento[i]), &(l->elemento[j]));
        }else {
            break;;
        }
    }
    troca(l,&(l->elemento[inicio]), &(l->elemento[j]));
    return j;
}

void quick_sort(struct lista_sequencial *l, int inicio, int fim){
    if (inicio < fim){
        int p = partition(l, inicio, fim);
        quick_sort(l, inicio, p-1);
        quick_sort(l, p+1, fim);
    }
}

void heapfy(struct lista_sequencial *l, int raiz){
    int maior = raiz;
    int esquerda = 2 * raiz + 1;
    int direita = 2*raiz + 2;

    if (esquerda < l->particao && l->elemento[esquerda] > l->elemento[maior]){
        maior = esquerda;
    }
    if (direita < l->particao && l->elemento[direita] > l->elemento[maior]){
        maior = direita;
    }

    if (maior != raiz){
        troca(l, &(l->elemento[raiz]), &(l->elemento[maior]));
        heapfy(l, maior);
    }
}

void heap_sort(struct lista_sequencial *l){
    
    int i;
    for(i = l->particao / 2 - 1; i >=0; i--){
        heapfy(l, i);
    }
    for (i = l->particao - 1; i > 0; i--){
        troca(l, &(l->elemento[0]), &(l->elemento[i]));
        l->particao--;
        heapfy(l, 0);
    }
}