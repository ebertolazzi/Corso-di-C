//Libreria di input-output
#include <stdio.h>

//Libreria funzioni sui polinomi
#include "lib/lib_poly.h"

// Definizione del numero di polinomi che gestisce il programma
#define NUM_POLY 10

// Vettore di polinomi
struct polinomio vett_poly[NUM_POLY];

int scegli_indice(char *string){
    int d;
    printf("%s",string);
    scanf(" %d",&d);
    return d;
}

void ciclo_principale(){
    // Caratte di input
    char c;
    // Fine programma
    int fine = 0;
    // indici utili per le operazioni sui polinomi
    int ind, inda, indb, indr;
    // Ciclo do while delle operazioni
    do{
        printf("Scegli comando:\n");
        printf("n - crea nu nuovo polinomio\n");
        printf("c - carica un polinomio\n");
        printf("s - salva polinomio corrente\n");
        printf("v - valuta polinomio corrente\n");
        printf("m - mostra a schermo un polinomio\n");
        printf("p - somma due polinomi\n");
        printf("x - moltiplica due polinomi\n");        
        printf("q - per terminare\n");

        scanf(" %c", &c);

        switch (c) {
            case 'n':
                ind = scegli_indice("Scegli l'indice per il nuovo polinomio:");         
                nuovo_polinomio(&vett_poly[ind]);
                break;

            case 'c':
                ind = scegli_indice("Scegli l'indice di dove caricare il polinomio:");
                carica_polinomio(&vett_poly[ind]);
                break;

            case 's':
                ind = scegli_indice("Scegli l'indice del polinomio da salvare:");
                salva_polinomio(&vett_poly[ind]);
                break;

            case 'v':
                ind = scegli_indice("Scegli l'indice del polinomio da valutare:");
                valuta_polinomio(&vett_poly[ind]);
                break;

            case 'm':
                ind = scegli_indice("Scegli l'indice del polinomio da mostrare:");
                mostra_polinomio(&vett_poly[ind]);
                break;

            case 'p':
                inda = scegli_indice("Somma due polinomi, scegli l'indice del primo:");
                mostra_polinomio(&vett_poly[inda]);
                indb = scegli_indice("Scegli l'indice del secondo:");
                mostra_polinomio(&vett_poly[indb]);
                indr = scegli_indice("Scegli l'indice di dove mettere il risultato:");
                somma_polinomi(&vett_poly[inda],&vett_poly[indb],&vett_poly[indr]);
                mostra_polinomio(&vett_poly[indr]);
                break;

            case 'x':
                inda = scegli_indice("Moltiplica due polinomi, scegli l'indice del primo:");
                mostra_polinomio(&vett_poly[inda]);
                indb = scegli_indice("Scegli l'indice del secondo:");
                mostra_polinomio(&vett_poly[indb]);
                indr = scegli_indice("Scegli l'indice di dove mettere il risultato:");
                moltiplica_polinomi(&vett_poly[inda],&vett_poly[indb],&vett_poly[indr]);
                mostra_polinomio(&vett_poly[indr]);
                break;

            case 'q':
                fine = 1;
                break;
                    
            default:
                printf("Comando errato.\n");
                break;
        }
    }while(fine == 0);
}


int main(){
    ciclo_principale();
}