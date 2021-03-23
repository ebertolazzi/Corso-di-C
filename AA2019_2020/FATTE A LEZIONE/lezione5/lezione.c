//Libreria di input-output
#include <stdio.h>

//Libreria funzioni sui polinomi
#include "lib_polinomi.h"


void ciclo_principale(int vett[], int *size){
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
                nuovo_polinomio(vett, size);
                break;

            case 'c':
                carica_polinomio(vett, size);
                break;

            case 's':
                salva_polinomio(vett, size);
                break;

            case 'v':
                valuta_polinomio(vett, size);
                break;

            case 'm':
                mostra_polinomio(vett, size);
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
    // Dimensione del polinomio
    int size = 0;
    // Vettore del polinomio
    int vett[SIZE];
    // Ciclo principale
    ciclo_principale(vett, &size);
}