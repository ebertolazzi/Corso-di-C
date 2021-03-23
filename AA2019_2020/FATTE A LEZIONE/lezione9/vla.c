
#include <stdio.h>

// Link VLA
// https://www.drdobbs.com/the-new-cwhy-variable-length-arrays/184401444

int* fun(int dim){
    int i, j;
    /* Allocazione di un variable lenght array */
    float arr[dim][dim];

    /* Inizializzazione */
    for(i = 0; i < dim; i++){
        for(j = 0; j < dim; j++){
            arr[i][j] = j+i*dim;
        }
    }

    /* Mia stampa */
    for(i = 0; i < dim; i++){
        for(j = 0; j < dim; j++){
            /* Notazione vettore/matrice */
            printf("%f\t", arr[i][j]);
        }
        printf("\n");
    }

    return NULL;
    // Variabile che voglio ritornare
    // ERRORE CHE NON VA FATTO
    // int ret[dim];
    // for(j = 0; j < dim; j++){
    //     ret[j] = arr[0][j];
    // }

    // return ret;
}

int main(){

    int a;
    // Recupero dimensione della matrice
    scanf(" %d",&a);
    // Chimata a funzione
    int *r = fun(a);
    // ERRORE CHE NON VA FATTO
    //printf("%d",r[0]);

    return 0;
}
