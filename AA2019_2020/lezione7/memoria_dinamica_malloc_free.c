
#include <stdio.h>

// Qui sono contenute anche le funzioni per la memoria dinamica
#include <stdlib.h>

// Includo le assert
#include <assert.h>

// Schemi schiari sul funzionamento delle funzioni di allocazione
// ttps://www.geeksforgeeks.org/dynamic-memory-allocation-in-c-using-malloc-calloc-free-and-realloc/

struct poly { 
    unsigned int size;
    int *vett;
};


int main(){
    // Creazione di un elemento
    // Creazione di un puntatore ad intero
    int *p_int = malloc(sizeof(int));
    if(p_int == NULL){
        printf("Allocazione di memoria fillita!\n");
        exit(1);
    }
    
    // Scrivo dentro la mia variabile dinamica
    (*p_int) = 5;

    // Stampa della varibile
    printf("%d\n",(*p_int));

    //Pulizia della memoria
    free(p_int);

    //Recuperare da utente la dimensione
    long unsigned int size;
    printf("Dimensione del vettore è:");
    assert(scanf("%lu",&size)==1);

    // Creazione di un vettore dinamico
    int *p_vett = malloc(size * sizeof(int));
    if(p_vett == NULL){
        printf("Allocazione di memoria fillita!\n");
        exit(1);
    }

    // Primo elemento di un vettore
    // p_vett o &p_vett[0] sono equiavalenti
    // Recupero valore elementi
    for(unsigned int i = 0; i < size; i++){
        //assert(scanf(" %d", &p_vett[i])==1);
        // Notazione dei puntatori
        assert(scanf(" %d", (&p_vett[0] + i))==1);
    }

    // Stampa dei elementi
    for(unsigned int i = 0; i < size; i++){
        printf("%d ", p_vett[i]);
    }

    // Pulizia della memoria del vettore
    free(p_vett);
    
    // Creazione di un vettore di strutture dinamico
    // Informazioni su come mai la dimensione non è la somma
    // https://www.geeksforgeeks.org/is-sizeof-for-a-struct-equal-to-the-sum-of-sizeof-of-each-member/
    // Il motivo è il pudding 
    printf("\nDimensione di int*: %lu\n",sizeof( int *));
    printf("Dimensione di unsigned int: %lu\n",sizeof(unsigned int ));
    printf("Dimensione della struct: %lu\n",sizeof(struct poly));

    struct poly *s_vett = malloc(size * sizeof(struct poly));
    if(s_vett == NULL){
        printf("Allocazione di memoria fillita!\n");
        exit(1);
    }

    // Recupero le dimensioni dei vettori all'interno della struttura
    printf("Inserisci la dimensione dei %lu vettori\n",size);
    for(unsigned int i = 0; i < size; i++){
        printf("Dimensione vettore %u: ",i);
        assert(scanf(" %u", &(s_vett[i].size))==1);
        s_vett[i].vett =  malloc(s_vett[i].size * sizeof(int));
    }    

    //Stampa delle dimensioni
    for(unsigned int i = 0; i < size; i++){
        printf("%u ", s_vett[i].size);
    }

    // Pulizia dei vettori inteni
    for(unsigned int i = 0; i < size; i++){
        free(s_vett[i].vett);
    } 
    // Pulizia della memoria del vettore
    free(s_vett);
}

// Utilizzo della calloc è uguale alla malloc soltanto che la calloc mette zero nella memoria