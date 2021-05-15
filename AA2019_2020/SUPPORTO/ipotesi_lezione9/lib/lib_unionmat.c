#include <stdio.h>
#include <stdlib.h>
#include "lib_unionmat.h"

void stampa_matrice(const UnionMat* mat){
    if(mat->tipo == ELEMENTO){
        printf("Elemento vale: %lf",mat->data.val);
    }else{
        printf("La matrice è composta da:\n");
        for(int i = 0 ; i < mat->data.mat.size_x ; i++){
            printf("[");
            int j = 0 ;
            for(; j < mat->data.mat.size_y - 1; j++){
                printf("\t%lf,",mat->data.mat.val[i][j]);
            }
            printf("\t%lf]\n", mat->data.mat.val[i][j]);
        }        
    }
}

void nuovo_matrice(UnionMat* mat){
    int size_x, size_y;
    
    printf("Inserisci dimensione in X:");
    scanf(" %d",&size_x);

    printf("Inserisci dimensione in Y:");
    scanf(" %d",&size_y);

    if(size_x == (size_y == 1)){
        mat->tipo = ELEMENTO;
        printf("Inserisci il valore:");
        scanf(" %lf",&mat->data.val);
    }else{
        mat->tipo = MATRICE;
        mat->data.mat.size_x = size_x;
        mat->data.mat.size_y = size_y;
        mat->data.mat.val = (double **)malloc(size_x*sizeof(double*));
        for(int i = 0; i < size_x; i++){
            mat->data.mat.val[i] = (double *)malloc(size_y*sizeof(double*));
            for(int j = 0; j < size_y; j++){
                printf("Inserisci il valore elemento [%d,%d]:",i,j);
                scanf(" %lf",&mat->data.mat.val[i][j]);
            }
        } 
    }
}
