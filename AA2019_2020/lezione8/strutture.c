// Libreria input output
#include <stdio.h>

// Includo le mie librerie per i polinomi
#include "lib/lib_poly.h"

// Includo le mie librerie per i vettori
#include "lib/lib_vett.h"

struct polinomio poly;

int main(){
    // Inizializzare la struttura globale poly
    poly.size = 5;
    poly.vett[0] = 5;
    poly.vett[1] = 1;
    poly.vett[2] = 3;
    poly.vett[3] = 3;
    poly.vett[4] = 2;

    // Stampare il vettore della struttura
    stampa_vettore(poly.vett, poly.size);

    //Creo un vettore di strutture
    struct polinomio pp[5];
    //Accesso ad un vettore di strutture
    pp[0].size = 2;
    pp[0].vett[0] = 0;
    pp[0].vett[1] = 1;
    // Stampare il primo elemento del nostro vettore di strutture
    stampa_vettore(pp[0].vett, pp[0].size);

    struct polinomio pp2[] = { // Si riferisce al vettore di strutture
        {                      // Si riferisce all'elemento della struttura
            {1,2,3,4,5},       // Questo è il contenuto di pp2[0].vett
            5                  // Questo è il contenuto di pp2[0].vsize
        },{
            {5,5,5},           // Questo è il contenuto di pp2[1].vvett
            3                  // Questo è il contenuto di pp2[1].vsize
        }                    
    };
    // Stampare il primo elemento del nostro vettore di strutture pp2
    stampa_vettore(pp2[0].vett, pp2[0].size);    
    // Stampare il secondo elemento del nostro vettore di strutture pp2
    stampa_vettore(pp2[1].vett, pp2[1].size);

    // Definizione di un puntatore a struttura
    struct polinomio *p_pointer;
    
    // Grave errore!!!
    //(*p_pointer).size = 5;

    // Assegno al mio puntatore il secondo elemento del vettore di strutture pp2[1]
    p_pointer = &pp2[1];
    // Stampa di pp2;
    stampa_vettore((*p_pointer).vett, (*p_pointer).size);
    // Modifico il contenuto di pp2[1]
    (*p_pointer).vett[1] = 2;
    stampa_vettore((*p_pointer).vett, (*p_pointer).size);

    // Notazione veloce per accedere ad un campo di una struttura
    p_pointer->vett[1] = 3;
    stampa_vettore(p_pointer->vett, p_pointer->size);

    // Vettore di puntatori a strutture
    struct polinomio *pp_pointer[3];
    // Essegno al secondo elemento del vettore di puntatori la mia struttura pp2[0]
    pp_pointer[1] = &pp2[0];
    //Accesso all'elemento del vettore di puntatori
    pp_pointer[1]->vett[0] = 5;
    stampa_vettore(pp_pointer[1]->vett, pp_pointer[1]->size);

    // Modifica del campo size e relativi elementi
    pp_pointer[1]->size = 8;
    pp_pointer[1]->vett[5] = 5;
    pp_pointer[1]->vett[6] = 5;
    pp_pointer[1]->vett[7] = 5;
    stampa_vettore(pp_pointer[1]->vett, pp_pointer[1]->size);

    //Utilizzo delle funzioni sui polinomi con un puntatore
    stampa_vettore_polinomio(pp_pointer[1]); 
    //Utilizzo delle funzioni sui polinomi con un elemento
    stampa_vettore_polinomio(&pp2[0]); 

    //  Chiamate inserisci elemento nel polinomio per valore con l'indirizzo oppure con il puntatore
    inserisci_elemento_polinomio(&pp2[0]);
    inserisci_elemento_polinomio(pp_pointer[1]);
    // Stampa del polinomio
    stampa_vettore_polinomio(pp_pointer[1]); 
}
