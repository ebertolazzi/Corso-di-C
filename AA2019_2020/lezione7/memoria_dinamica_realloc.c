
#include <stdio.h>

// Qui sono contenute anche le funzioni per la memoria dinamica
#include <stdlib.h>

// Includo le assert
#include <assert.h>

// Schemi schiari sul funzionamento delle funzioni di allocazione
// https://www.geeksforgeeks.org/dynamic-memory-allocation-in-c-using-malloc-calloc-free-and-realloc/

int main(){
    // Creazione di un elemento
    // Creazione di un puntatore ad intero
    int *p_vett = malloc(sizeof(int));
    if(p_vett == NULL){
        printf("Allocazione di memoria fillita!\n");
        exit(1);
    }
    
    unsigned int size = 0;
    char s[5];
    do{
        printf("Elemento: ");
        assert(scanf(" %s", s)==1);

        if(s[0] == 'f'){
            break;
        }

        p_vett[size++] = atoi(s);
        
        // Funzione Realloc
        p_vett = realloc(p_vett, (size + 1) * sizeof(int));
    }while(1);

    // Stampa dei elementi
    for(unsigned int i = 0; i < size; i++){
        printf("%d ", p_vett[i]);
    }
    printf("\n");

    // Pulizia della memoria del vettore
    free(p_vett);
    
}