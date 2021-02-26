
#include <stdio.h>
#include <stdlib.h>

// Definizione delle dimensioni
#define SIZEX 4
#define SIZEY 5

// Link struttura dati
// https://publications.gbdirect.co.uk/c_book/chapter5/arrays.html 

int main(){
    // Allochiamo una matrice 4x5
    int matrice[SIZEX][SIZEY];
    // Accesso di un array multidimensionale
    for(int i = 0; i < SIZEX; i++){
        for(int j = 0; j < SIZEY; j++){
            matrice[i][j] = j+i*SIZEY;
        }
    }
    // Stampa del contenuto
    // Accesso a due indici
    for(int i = 0; i < SIZEX; i++){
        for(int j = 0; j < SIZEY; j++){
            // Notazione vettore/matrice
            printf("%d\t", matrice[i][j]);
            // Aritmetica dei puntatori su i e j
            //printf("%d\t", *(*(matrice+i))+j);
            // Aritmetica dei puntatori su i
            //printf("%d\t", (*(matrice+i))[j]);
            // Aritmetica dei puntatori su j
            //printf("%d\t", *(matrice[i]+j));
        }
        printf("\n");
    }
    printf("\n");
    // Accesso a un indice
    for(int j = 0; j < SIZEX*SIZEY; j++){
        // Aritmetica dei puntatori su j
        //printf("%d\t", *(*matrice)+j);
        // Novatione vettore
        printf("%d\t", (*matrice)[j]);
    }
    printf("\n");
    printf("\n");

    // Allocazione dei singoli vettori
    int r1[SIZEY], r2[SIZEY], r3[SIZEY], r4[SIZEY];
    // Creazione di un vettore di puntatori
    int *m[SIZEX] = {r1,r2,r3,r4};
    // Accesso di un array multidimensionale
    for(int i = 0; i < SIZEX; i++){
        for(int j = 0; j < SIZEY; j++){
            m[i][j] = j+i*SIZEY;
        }
    }
    // Accesso a due indici
    for(int i = 0; i < SIZEX; i++){
        for(int j = 0; j < SIZEY; j++){
            // Notazione vettore/matrice
            printf("%d\t", m[i][j]);
        }
        printf("\n");
    }
    printf("\n");   
    // SBAGLIATO!!!
    // Accesso a un indice
    // for(int j = 0; j < SIZEX*SIZEY; j++){
    //     // Aritmetica dei puntatori su j
    //     //printf("%d\t", *(*matrice)+j);
    //     // Novatione vettore
    //     printf("%d\t", (*m)[j]);
    // }

    // Allocazione dei singoli vettori
    int *rr1 = malloc(sizeof(int)*SIZEY);
    int rr2[SIZEY], rr3[SIZEY], rr4[SIZEY];
    // Creazione di un vettore di puntatori
    int *mm[SIZEX] = {rr1,rr2,rr3,rr4};
    // Accesso di un array multidimensionale
    for(int i = 0; i < SIZEX; i++){
        for(int j = 0; j < SIZEY; j++){
            mm[i][j] = j+i*SIZEY;
        }
    }
    // Accesso a due indici
    for(int i = 0; i < SIZEX; i++){
        for(int j = 0; j < SIZEY; j++){
            // Notazione vettore/matrice
            printf("%d\t", mm[i][j]);
        }
        printf("\n");
    }
    printf("\n"); 

    // Allocazione di un array multidimensionale dinamico
    int *mdyn = malloc(sizeof(int)*SIZEY*SIZEX);
    // Accesso di un array multidimensionale
    for(int i = 0; i < SIZEX; i++){
        for(int j = 0; j < SIZEY; j++){
            mdyn[j+i*SIZEY] = j+i*SIZEY;
        }
    }
    for(int i = 0; i < SIZEX; i++){
        for(int j = 0; j < SIZEY; j++){
            // Notazione vettore/matrice
            printf("%d\t", mdyn[j+i*SIZEY]);
        }
        printf("\n");
    }
    printf("\n"); 
}