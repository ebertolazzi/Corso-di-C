// Classico utilizzo del preprocessore per la definizione delle macro
#define MACRO 0

// Con il preprocessore è possibile definire semplici funzioni
#define AREACERCHIO(r)  r*r*3.14 

// Potete utilizzare lo slash per definire funzioni su più linee
// Funzione di preprocessore più complessa
#define SWAP(tipo,x,y)  \
{                       \
tipo t;                 \
t = (x);                \
(x) = (y);              \
(y) = t;                \
}                       \

// Utilizzo del ## per concatenare due variabile
// ## viene eliminato dal preprocessore
#define UNISCI(x,y) x##y

// Potete rimuovere una definizione di una macro
//#undef MACRO

// Potete utilizzare delle condizioni
// ifdef controlla se una variabile è definita
#ifdef LINE
// Se MACRO è definita allora definisco MACRO2
#define MACRO2 5
// Condizione di else del preprocessore
#else
// Chiusura if del preporcessore
#endif

// Condizione su una variabile intera
// Se la variabile è diversa da zero l'operazione è eseguita
#if MACRO
#define MACRO2 6.6
// Esiste anche la condizione di else
#else
#define MACRO2 7.2
// Chiusura della parentesi dell'if
#endif

// La direttiva include del preprocessore copia il contenuto del file .h all'interno del file
//#include "static_extern.h"

int main(){
    // Esempio utilizzo macro
    double r = MACRO2;
    // Definizioni di funzioni
    double area = AREACERCHIO(r);
    // Funzioni su multi riga
    int a = 5;
    int b = 6;
    SWAP(int,a,b);
    // Utilizzo del ##
    int UNISCI(a,1);
    a1 = 5;
}

// Compilando con il parametro -E avete il file dopo il passaggio del preprocessore
//gcc -E preprocessore.c
// Generazione del codice del preprocessore su file
// gcc -E preprocessore.c -o preprocessore.out.c
// gcc preprocessore.out.c

// Potete definire delle variabili di preprocessore quando compilate un sorgente
// Definisco una macro che si chiama NOMEVARIABILE
//gcc -DNAMEVARIABILE ....
// Definisco il valore di una macro quando compilo il sorgente
//gcc -DMACRO=VALORE

