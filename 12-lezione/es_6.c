#include <stdio.h>

//Data la struttura

struct param{
    double min;
    double max;
    double total;
    double media;
    double varianza;
};

// Fare una funzione che prende la struttura per puntatore e un vettore 
// e inizializza la struttura con il valore mininimo, valore massimo,
// la somma degli elementi, la media e la varianza.

void init(const double array[], const int size, struct param *par){
    par->min = array[0];
    par->max = array[0];
    double somma2 = 0;
    for(int i = 0; i< size;i++){
        if(par->min > array[i]){
            par->min = array[i];
        }
        if(par->max < array[i]){
            par->max = array[i];
        }
        par->total += array[i];
        par->media += array[i]/size;
        somma2 += array[i]*array[i];
    }
    par->varianza = (somma2 - ((par->total)*(par->total))/((double)size))/(size-1);
}


int main(){ 
    struct param par;
    double a[] = {1,7,1,7,7,2,4,4,3,2};
    init(a, 10, &par);
    printf("%f\n",par.media);
    printf("%f\n",par.total);
    printf("%f\n",par.varianza);
}