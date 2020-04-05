
//Libreria di input-output
#include <stdio.h>

//Libreria per includere la funzione exit
#include <stdlib.h>

FILE *apri_file(char *name, char *mod){
    //Puntatore al file
    FILE *file;
    //Apro di nuovo il file
    file = fopen(
        name, // File da aprire
        mod           // Modalita di apertura 
                      // r read         - lettura
                      // w writing      - scrittura
                      // a append       - aggiungo alla fine del file
                      // r+ read+write  - leggo e scrivo solo se esiste
                      // w+ read+write  - se non esiste viene creato
                      // a+ read+write  - se non esiste viene creato ed aggiungo alla fine del file
    );
    //Controllo se l'apertura del file è andata a buon fine
    if(file == NULL) {
        printf("Errore!");   
        exit(1);
    }

    return file;
}

int main(){
    //Puntatore al file
    FILE *file;

    //Apro il file
    file = apri_file("myFile.txt", "w");

    char line[80]="\0";
    do{

        //Scrivo su file
        fprintf(file,"%s",line);

        //Stampo in console 
        printf(">");

        //Scrivo su file
        //scanf(" %80s",line);      //Questa funziona si ferma allo spazio
        fgets(line, 80, stdin);     //Questa funzione legge fino a 80 caratteri

    }while(line[0] != '.');         //Se leggo un punto mi fermo

    //Chiudo il file
    fclose(file);

    //Apro il file
    file = apri_file("myFile.txt", "r");

    //Controllo se l'apertura del file è andata a buon fine
    if(file == NULL) {
        printf("Errore!");   
        return 1;
    }

    char *r ;
    do{
        r = fgets(line, 80, file);
        //r = fscanf(file, "%s", line);

        //Stampo in console 
        printf("%s",line);
    }while(r != NULL);

    //Chiudo il file
    fclose(file);

    //Apro il file
    file = apri_file("myFile.txt", "a");
    do{

        //Scrivo su file
        fprintf(file,"%s",line);

        //Stampo in console 
        printf(">");

        //Scrivo su file
        //scanf(" %80s",line);      //Questa funziona si ferma allo spazio
        fgets(line, 80, stdin);     //Questa funzione legge fino a 80 caratteri

    }while(line[0] != '.');         //Se leggo un punto mi fermo
}