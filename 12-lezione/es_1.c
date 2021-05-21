#include "lib_stampa.h"
#include <stdlib.h>

// Scrivi una funzione che conta le ricorrenze di ogni numero all'interno del vettore di ingresso
// e riempie un vettore posizionando le ricorrenze nella posizione del numero corrispondente
// La funzione ritorni un vettore allocato dinamicamente con le ricorrenze
// Es {1,2,3,3,4,4,1,4} -> {2,1,2,2,3,3,2,3}
int *count(int array[], int size)
{
    if (size == 0)
    {
        return NULL;
    }
    int *res = malloc(sizeof(int) * size);
    for (int i = 0; i < size; i++)
    {
        res[i] = 0;
    }
    for (int i = 0; i < size; i++)
    {
        for (int j = 0; j < size; j++)
        {
            if (array[i] == array[j])
            {
                res[i] += 1;
            }
        }
    }
    return res;
}


int main(){
    int t1[] = {1,2,2,3,3,4,4,4,5};
    int *r = count(t1, 9);
    stampa(r, 9);
}