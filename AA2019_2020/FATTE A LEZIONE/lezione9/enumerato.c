
// Approcio utilizzando le define
// #define Lunedi 0
// #define Martedi 1
// ...

// int main(){
//     int giorno = Martedi;
// }

#include <stdio.h>

// Link ai Tipi Enumerato
// https://publications.gbdirect.co.uk/c_book/chapter6/enums.html

enum // Parola chiave per definire un enumerato
giorno { // Nome dell'enumerato
    Lunedi,     // Valori ammissibili
    Martedi,
    Mercoledi,
    Giovedi,
    Venerdi,
    Sabato,
    Domenica
};

// Definizione del tipo Giorno
typedef enum giorno Giorno;

// Array di stringhe
char *str_giorno[] = {
    "Lunedì",     
    "Martedì",
    "Mercoledì",
    "Giovedì",
    "Venerdì",
    "Sabato",
    "Domenica"
};

int main(){
    // Allocazione di una variabile giorno
    Giorno g = Domenica;
    if ( g == Lunedi ){
        return 0;
    }
    printf("Oggi è %s", str_giorno[g]);
}