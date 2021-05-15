// Libreria di input-output
#include <stdio.h>

// Includo la libreria
#include "lib_vett.h" //!Utilizzo delle virgolette per i file locali

// Dimensione massima dei coefficenti del polinomio
#define SIZE 10 //!Rispiegare come funziona il preprocessore

struct     // Parola chiave per creare strutture
polinomio{ // Nome della struttura, la struttura è un nuovo tipo variabile.
    // Qui all'interno ci sono i campi della struttura
    // Vettore degli elementi del polinomio
    int vett[SIZE];
    // Dimensione del polinomio
    int size;
}poly;     // Creazione di variabile di tipo polinomio

//!Come compilare un file per generare un punto .o 
//!gcc -c file.c
// se però usa una funzione di libreria e faccio
// gcc strutture.c
// /tmp/ccnwzaTI.o: In function `main':
// strutture.c:(.text+0x39): undefined reference to `stampa_vettore'

int main(){
    // inizializzo l'elemento globale
    poly.vett[0] = 5;
    poly.size = 1;
    // Stampo il vettore
    stampa_vettore(poly.vett, poly.size);

    // Creazione elemento di tipo polinomio
    struct polinomio p;
    // Definisco i campi del mio polinomio
    p.vett[0] = 10;
    p.vett[1] = 3;
    p.size = 2;
    // Stampo il vettore
    stampa_vettore(p.vett, p.size);

    //Creo un vettore di strutture
    struct polinomio pp[3];

    //Creazione con inizializzazione di una struttura complessa
    struct polinomio pp2[]={
        {// Primo elemento del vettore di strutture
            {1,2},
            2
        },{// Seconedo elemento
            {4,5,4},
            3
        },{//Terzo elemento è vuoto

        }};
    //Stampa della prima struttura
    stampa_vettore(pp2[0].vett, pp2[0].size);
    //Stampa della seconda struttura
    stampa_vettore(pp2[1].vett, pp2[1].size);
    //Stampa della terza struttura
    stampa_vettore(pp2[2].vett, pp2[2].size);

    pp2[2].size = 4;
    // Questo è un errore
    pp2[2].vett[1] = 1;
    stampa_vettore(pp2[2].vett, pp2[2].size);

    //Creao un puntatore a polinomio
    struct polinomio *p_pointer;

    // Questo è sbagliato il puntatore non sta puntando a nessuna struttura!
    // (*p_pointer).size = 5;
    
    //Assegno a p_pointer il secondo elemento di pp2
    //!Rispiegare concetto puntatore e indirizzo 
    p_pointer = &pp2[1];
    //Stampa della prima struttura: ora posso accedere ai campi vett e size
    stampa_vettore((*p_pointer).vett, (*p_pointer).size);
    //Nuovo simbolo -> mi permette di accedere ad un campo di un puntatore a struttura
    p_pointer->vett[0] = 2; // Modifico il velore del primo elemento
    //Stampa della prima struttura modificata
    stampa_vettore(p_pointer->vett, p_pointer->size);
}

