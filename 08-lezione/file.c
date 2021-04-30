
#include <stdio.h>

int main(){
    // Puntatore a file
    FILE *file;
    // "w"  - scrittura (crea il file)
    // "r"  - lettura
    // "a"  - aggiungo contenuto al file
    // "r+" - leggo e scrivo solo se esiste il file
    // "w+" - leggo e scrivo (si crea il file)
    // "a+" - leggo e aggiungo contenuto al file (si crea il file)
    file = fopen("data","a");
    fprintf(file,"%d\n",12);
    fclose(file);

    char mystring[100];
    file = fopen("data","r");
    if (file == NULL) perror ("Error opening file");
    else {
    while ( fgets (mystring , 100 , file) != NULL )
        printf("%s",mystring);
    }
    fclose (file);
}