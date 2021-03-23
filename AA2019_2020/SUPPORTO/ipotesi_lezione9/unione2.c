// Libreria di input-output
#include <stdio.h>

struct example{
    int type;
    union {      // Parola chiave per creare un unione
                 // Qui sono presenti i campi all'interno della nostra unione
        float f; // type = 0
        int i;   // type = 1   
        char c;  // type = 2
    } value; // Creo una variabile di tipo unione di nome uni
};


void stampa(struct example e) {
    switch (e.type) {
    case 0:
        printf("float: %f\n",e.value.f);
        break;
    case 1:
        printf("integer: %d\n",e.value.i);
        break;
    case 2:
        printf("char: %c\n",e.value.c);
        break;
    default:
        printf("Tipo non riconosciuto\n");
        break;
    }
}

int main(){
    // Allocazione della struttura example
    struct example p;

    // Inizializzazione della struttura p con un float
    p.value.f = 2.4;
    p.type = 0;
    stampa(p);

    // Inizializzazione della struttura p con un float
    p.value.c = 'c';
    p.type = 2;
    stampa(p);   

    // Allocazione di un vettore di struttura contenenti unioni
    struct example ex[5];
    ex[1].value.f = 2.7;
    ex[1].type = 0;
    stampa(ex[1]);
}

