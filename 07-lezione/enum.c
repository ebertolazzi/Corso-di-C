#include <stdio.h>

enum tag{
    A, B, C = 12, D
};

// Un modo carino di utilizzare gli enumereti è per definire dei tipi
enum tipo{
    VELOCE, LENTO
};
// Se creo un vettore di stringhe nello stesso ordine dell'enumerato
// Posso utilizzando il valore dell'enumerato recuperare la stringa corrispondente.
char *tipo_str[] = {"Veloce","Lento"}; 
struct macchina{
    enum tipo t;
};


int main(){
    struct macchina mia = {LENTO};
    // In questo modo vado a leggere dentro il vettore di stringhe nella posizione LENTO che corrisponde
    // Alla stringa lento
    printf("Tipo della mia macchina: %s\n", tipo_str[mia.t]);
}

