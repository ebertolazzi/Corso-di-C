
#include <stdlib.h>
#include <stdio.h>

#include "lib_unionmat.h"

void stampa_matrice(const UnionMat* mat){
    // Variable di ciclo
    int i = 0;
    // Gestione dei vari tipi
    switch (mat->tipo)
    {
        case ELEMENTO:
            printf("Elemento vale: %lf\n", mat->data.val);
            break;

        case VETTORE_COLONNA:
            printf("Il vettore colonna è composto da:\n");
            for(i = 0; i < mat->data.vet.size; i++){
                printf("[%lf]\n", mat->data.vet.val[i]);
            }
            break;

        case VETTORE_RIGA:
            printf("Il vettore riga è composto da:\n");
            printf("[");
            for(i = 0; i < mat->data.vet.size - 1 ; i++){
                printf("\t%lf,", mat->data.vet.val[i]);
            }
            printf("%lf]\n", mat->data.vet.val[i]);
            break;

    case MATRICE:
            printf("la matrice è composto da:\n");
            for(int j = 0; j < mat->data.mat.size_y; j++){
                printf("[");
                for(i = 0; i < mat->data.mat.size_x - 1 ; i++){
                    printf("\t%lf,", mat->data.mat.val[j][i]);
                }
                printf("%lf]\n", mat->data.mat.val[j][i]);
            }

            break;            
    default:
        break;
    }
}

void nuova_matrice(UnionMat* mat){
    // Dimensione lette
    int size_x, // numero colonne
        size_y; // numero righe
    // Chiedo all'utente la dimensione
    printf("Inserisci dimensione in X:");
    scanf(" %d",&size_x);
    // Chiedo all'utente la dimensione
    printf("Inserisci dimensione in Y:");
    scanf(" %d",&size_y);

    if(size_x == (size_y == 1)){
        // Gestione singolo elemento
        mat->tipo = ELEMENTO;
        printf("Inserisci il valore:");
        scanf(" %lf", &mat->data.val);
        return;
    }
    if(size_x == 1 || size_y == 1){
        // Gestione dei vettori
        if(size_x == 1){
            mat->tipo = VETTORE_COLONNA;
            mat->data.vet.size = size_y;
        }else{
            mat->tipo = VETTORE_RIGA;
            mat->data.vet.size = size_x;
        }
        mat->data.vet.val = malloc(mat->data.vet.size * sizeof(double));
        for (int i = 0; i < mat->data.vet.size ; i++){
            printf("Inserisci il valore elemento [%d]:",i);
            scanf(" %lf", &mat->data.vet.val[i]);            
        }
    }else{
        // Gestione delle matrici
        mat->tipo = MATRICE;
        mat->data.mat.size_x = size_x;
        mat->data.mat.size_y = size_y;
        mat->data.mat.val = (double**)malloc(size_y * sizeof(double));
        for (int i = 0; i < mat->data.mat.size_y ; i++){
            mat->data.mat.val[i] = malloc(size_x * sizeof(double));
            for (int j = 0; j < mat->data.mat.size_x ; j++){
                printf("Inserisci il valore elemento [%d,%d]:",i,j);
                scanf(" %lf", &mat->data.mat.val[i][j]);            
            }       
        }
    }

}