
#include <stdio.h>

// Includo la funzione exit
#include <stdlib.h>

// Libreria che gestisce i segnali
// https://publications.gbdirect.co.uk/c_book/chapter9/signal_handling.html
#include <signal.h>

void terminate( int sing ){
    printf("Terminato da tastiera\n");
    // Lancio di un segnale utilizzando la funzione raise
    raise(SIGFPE);
    exit(sing);
}

void divisione( int sing ){
    printf("Divisione per zero\n");
    exit(sing);
}

int main(){
    // Con la funzione signal assegno ad un segnale una funzione
    // Quando il segnale SIGFPE (divisione per zero) viene lanciato la funzione divisione viene chiamata
    signal(SIGFPE, divisione);
    // Quando il segnale SIGINT (interruzione da tastiera) viene lanciato la funzione terminate viene chiamata
    signal(SIGINT, terminate);
    // Ciclo infinito che termina utilizzando il Control-C
    while (1);
    // Esempio di divisione per zero
    //int r = 0; 
    //printf("%d", 6 / r);
}
