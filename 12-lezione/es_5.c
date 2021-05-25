// Fare una funzione che elimina dal vettore tutti gli elementi pari o dispari
// modificando size di conseguenza.
// Pari se la somma degli elementi è pari e dispari se la somma è dispari 
#include "lib_stampa.h"
#include <stdio.h>


void elimina_elementi(int array[], int* size){
    int sum = 0;
    for(int i = 0; i < *size; i++){
        sum += array[i];
    }
    for(int i=0; i < *size;i++){
        if((sum % 2 == 0 && array[i] % 2 == 0) || (sum % 2 == 1 && array[i] % 2 == 1)){
            for(int j=i; j < *size; j++){
                array[j] = array[j+1];
            }
            (*size)--;
            i--;
        } 
    }
}

int main(){
    int t1[] = {1,2,2,3,3,4,4,4,5};
    int size = 9;
    elimina_elementi(t1, &size);
    stampa(t1, size);
    int t2[] = {2,2,3,3,4,4,4,5};
    size = 8;
    elimina_elementi(t2, &size);
    stampa(t2, size);
}