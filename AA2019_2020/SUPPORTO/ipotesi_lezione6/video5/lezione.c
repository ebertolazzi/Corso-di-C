//Libreria di input-output
#include <stdio.h>

//Libreria funzioni sui polinomi
#include "lib_polinomi.h"


void ciclo_principale(){
    //Caratte di input
    char c;
    //Fine programma
    int fine = 0;
    do{
        printf("Scegli comando:\n");
        printf("n - crea nu nuovo polinomio\n");
        printf("c - carica un polinomio\n");
        printf("s - salva polinomio corrente\n");
        printf("v - valuta polinomio corrente\n");
        printf("m - mostra a schermo il polinomio corrente\n");
        printf("q - per terminare\n");

        scanf(" %c", &c);

        switch (c)
        {
            case 'n':
                nuovo_polinomio(&poly_vett[0]);
                break;

            case 'c':
                carica_polinomio(&poly_vett[0]);
                break;

            case 's':
                salva_polinomio(&poly_vett[0]);
                break;

            case 'v':
                valuta_polinomio(&poly_vett[0]);
                break;

            case 'm':
                mostra_polinomio(&poly_vett[0]);
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