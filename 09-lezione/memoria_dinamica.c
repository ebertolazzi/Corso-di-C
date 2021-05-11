
#include <stdlib.h>
#include <stdio.h>

void stampa_vettore(double *v,int dim){
    int i=0;
    for(;i<dim-1; i++){
        printf("%f,",v[i]);
    }
    printf("%f\n",v[i]);
}

int main(){
    // Allocazione dinamica della memoria funzione malloc
    int *a = malloc(
        sizeof(int) /* Numero di byte da allocare */ 
    );
    // Stampo prima di inizializzare contenuto è random
    printf("numero a: %d\n", (*a));
    (*a) = 4;
    printf("numero a: %d\n", (*a));
    
    // Deallocazione della memoria
    free(a);

    // Allocazione dinamica con azzeramento memoria
    a = calloc(
        1 /* Numero di elementi da allocare */,
        sizeof(int) /* Dimensione di ogni elemento */
    );
    printf("numero a: %d\n", (*a));
    (*a) = 4;
    printf("numero a: %d\n", (*a));

    // Deallocazione della memoria
    free(a);   

    // Allocazione di un vettore da 10
    double *vett = malloc(sizeof(double)*10);
    vett[2] = 5;
    stampa_vettore(vett,10);
    // Deallocazione della memoria del vettore
    free(vett);
    // ERRORE chiamare la stampa dopo la free
    // stampa_vettore(vett,10);

    // Allocazione di un vettore da 10 inizializzando la memoria
    vett = calloc(10, sizeof(double));
    vett[2] = 12;
    stampa_vettore(vett,10);

    //Modifica di un vettore già in memoria
    double *vett_new;
    vett_new = realloc (vett, sizeof(double)*15);
    if(vett_new != NULL){
        // Il vecchio puntatore non è più valido
        vett = vett_new;
        // Ora si vett che vett_new puntano alla stessa zona di memoria
    }else{
        // Se la realloc vallisce il vecchio puntatore è ancora valido
    }
    stampa_vettore(vett,15);
    // ERRORE sono andato a leggere in una locazione sbagliata
    //stampa_vettore(vett,100000000);

    // Deallocazione della memoria del vettore
    free(vett_new);
    // Ora anche vett non è più valido
    // ERRORE la memoria puntata da vett è già stata deallocata
    //free(vett);

    // Esempio per mostrare Segmentation fault (core dumped)
    // vett = calloc(10, sizeof(double)*1000000);
    // double *v = vett;
    // free(vett);
    // stampa_vettore(v,1000000);
}