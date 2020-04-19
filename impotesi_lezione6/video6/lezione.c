//Libreria di input-output
#include <stdio.h>

//Libreria funzioni sui polinomi
#include "lib_polinomi.h"

#define NPOLY 10

int scegli_indice(char *string){
    int d;
    printf("%s",string);
    scanf(" %d", &d);
    return d;
}

void ciclo_principale(){
    //Caratte di input
    char c;
    //Fine programma
    int fine = 0;
    // polinomi considerati
    int ind1, ind2, ind3;
    // vettore di polinomi
    struct polinomio poly_vett[NPOLY];
    do{
        printf("Scegli comando:\n");
        printf("n - crea nu nuovo polinomio\n");
        printf("c - carica un polinomio\n");
        printf("s - salva polinomio corrente\n");
        printf("v - valuta polinomio corrente\n");
        printf("m - mostra a schermo un polinomio\n");
        printf("p - somma due polinomi\n");
        printf("x - moltiplica due polinomi\n");

        scanf(" %c", &c);

        switch (c)
        {
            case 'n':
                ind1 = scegli_indice("Scegli l'idice per il nuovo polinomio:");
                nuovo_polinomio(&poly_vett[ind1]);
                break;

            case 'c':
                ind1= scegli_indice("Scegli l'idice di dove caricare il polinomio:");
                carica_polinomio(&poly_vett[ind1]);
                break;

            case 's':
                ind1 = scegli_indice("Scegli l'idice del polinomio da salvare:");
                salva_polinomio(&poly_vett[ind1]);
                break;

            case 'v':
                ind1 = scegli_indice("Scegli l'idice del polinomio da valutare:"); 
                valuta_polinomio(&poly_vett[ind1]);
                break;

            case 'm':
                ind1 = scegli_indice("Scegli l'idice del polinomio da mostrare:");
                mostra_polinomio(&poly_vett[ind1]);
                break;

            case 'p':
                ind1 = scegli_indice("Somma due polinomi, scegli il primo indice:");
                mostra_polinomio(&poly_vett[ind1]);
                ind2 = scegli_indice("Scegli il secondo indice:");
                mostra_polinomio(&poly_vett[ind2]);
                ind3 = scegli_indice("Scegli l'indice di dove mettere il risultato:");
                somma(&poly_vett[ind1], &poly_vett[ind2], &poly_vett[ind3]);
                break;

            case 'x':
                ind1 = scegli_indice("Moltiplica due polinomi, scegli il primo indice:");
                mostra_polinomio(&poly_vett[ind1]);
                ind2 = scegli_indice("Scegli il secondo indice:");
                mostra_polinomio(&poly_vett[ind2]);
                ind3 = scegli_indice("Scegli l'indice di dove mettere il risultato:");
                moltiplica(&poly_vett[ind1], &poly_vett[ind2], &poly_vett[ind3]);
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