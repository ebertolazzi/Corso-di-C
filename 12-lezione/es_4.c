// Trova il numero mediano di un vettore di interi senza segno
// nel caso il vettore abbia un numero pari ritorna più piccolo
// Ritorna -1 se il vettore è vuoto
// ES: 1,7,1,7,7,2,4,4,3,2 -> 3
// ES: 1,1,2,3,4,5,7,7,7 -> 4
#include <stdlib.h>
#include <stdio.h>

int mediano(unsigned int array[], int size)
{
    if(size == 0){
        return -1;
    }
    int count = size/2;
    int max;
    int *vett = calloc(size,sizeof(int));
    for (int d = 0; d <= count; ++d){
        max = -1;
        int ind = 0;
        for(int i = 0; i < size; i++){
            if(max <= (int)array[i] && vett[i] == 0){
                max = array[i];
                ind = i;
            }
        }
        vett[ind] = 1;
    }
    free(vett);
    return max;
}


int main(){ 
    // 1,1,2,2,3,4,4,7,7,7
    int a[] = {1,7,1,7,7,2,4,4,3,2};
     // 1,1,2,3,4,5,7,7,7
    int b[] = {1,7,1,7,7,2,4,5,3};
    printf("%d\n",mediano(a,10));
    printf("%d\n",mediano(b,9));
}