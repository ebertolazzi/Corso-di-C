
// Libreria input output
#include <stdio.h>
// Libreria che contiene exit
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

int main(){

    //SCRITTURA

    //Puntatore al file
    FILE *file;

    char line[80] = "\0";

    //Apertura del file
    file = apri_file("data.txt", "w");

    do{
        //Funzione di scrittura su file che funziona come printf
        fprintf(file, "%s", line);
        //Stampa a console
        printf(">");
        //Leggo da terminale 80 caratteri
        //scanf("%80s",line);
        //http://www.cplusplus.com/reference/cstdio/fgets/
        fgets(line, 80, stdin);
    }while(line[0] != '.');

    //Chiusura del file
    fclose(file);

    //LETTURA

    //Apertura del file
    file = apri_file("data.txt", "r");

    //Carattere fine file
    char *r;
    line[0] = '\0';

    do{
        //Stampo a terminale
        printf("%s",line);
        //Leggo da file
        r = fgets(line, 80, file);
    }while(r != NULL);

    //Chiusura del file
    fclose(file);

    //APPEND

    //Apertura del file
    file = apri_file("data.txt", "a");
    //Azzero la stringa
    line[0] = '\0';

    do{
        //Funzione di scrittura su file che funziona come printf
        fprintf(file, "%s", line);
        //Stampa a console
        printf(">");
        //Leggo da terminale 80 caratteri
        //scanf("%80s",line);
        //http://www.cplusplus.com/reference/cstdio/fgets/
        fgets(line, 80, stdin);
    }while(line[0] != '.');

    //Chiusura del file
    fclose(file);
}