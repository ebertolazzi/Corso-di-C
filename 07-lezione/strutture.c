#include <stdio.h>
#include <string.h>

// Creo una struttura di tipo persona
// Non c'è allocazione di memoria
struct persona {
    int eta;
    char iniziale;
    char nome[20];
    char cognome[20];
    double altezza;
    double peso;
};

// Alloco un elemento di tipo struttura con due campi double
struct {
    double a;
    double b;
} unica;

// Creo una variabile di tipo persona
struct persona giorgo;

// Creo una stuttura di tipo animale e allocazione di due
// di quel tipo
struct animale {
    char nome[20];
    int eta;
} cane, gatto;

// Creo una variabile di tipo animale
struct animale topo;

// Creo un vettore di strutture a pesona, la classe
struct persona classe[10];

int main(){
    topo.eta = 4;
    //Nota sui vettore di char o stringhe
    // char a[20];
    // a = "stringa";   // error
    // Dopo che è stato allocato non può essere più assegnato in questo modo.
    // ma bisogna utilizzare la funzione strcpy
    // strcpy( a, "stringa" );
    // https://www.cplusplus.com/reference/cstring/strcpy/
    // Così è errore
    // topo.nome = "Topolino";
    strcpy(topo.nome, "Topolino");

    // Inizializzazione veloce di una struttura durante la creazione
    struct animale canarino = {"Michel",1};

    // Inizializzo il primo elemento del vettore di pensone in classe
    classe[0].eta = 5;
    strcpy(classe[0].nome, "Giovanni");

    // Creo un puntatore a persona e lo assegno con il terzo elemento della classe
    struct persona *el = &classe[2];
    
    // Quando uso un puntatore per accedere ad un campo della struttura
    // Devo utilizzare l'operatore ->.
    strcpy(el->nome, "Giovanni");
    el->eta = 22;
    el->peso = 65;
    el->altezza = 1.53;
    strcpy(el->cognome, "Muscolo");
    el->iniziale = 'G';
    // Modifico l'eta
    el->eta++; // oppure el->eta = el->eta + 1;
}