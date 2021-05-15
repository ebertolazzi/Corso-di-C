//Libreria di input-output
#include <stdio.h>

//Libreria per includere la funzione exit
#include <stdlib.h>

FILE *apri_file(const char *nome_file, const char *mod_apertura){
    //Puntatore al file
    FILE *file;

    //Apertura del file
    //http://www.cplusplus.com/reference/cstdio/fopen/
    file = fopen(
        nome_file,      //Nome del file
        mod_apertura    // Modalita di apertura 
                        // r read         - lettura
                        // w writing      - scrittura
                        // a append       - aggiungo alla fine del file
                        // r+ read+write  - leggo e scrivo solo se esiste
                        // w+ read+write  - se non esiste viene creato
                        // a+ read+write  - se non esiste viene creato ed aggiungo alla fine del file
    );
    if(file == NULL){
        printf("Errore");
        exit(1);
    }
    
    return file;
}