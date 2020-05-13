
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

UnionMat somma_matrice(const UnionMat* a, const UnionMat* b){
    UnionMat c;
    if(a->tipo == ELEMENTO || b->tipo == ELEMENTO){
        // Caso in cui ho almeno un elemento
        const UnionMat *elemento = a->tipo == ELEMENTO ? a : b;
        const UnionMat *altro = elemento == a ? b : a;
        switch (altro->tipo){
            case ELEMENTO:
                c.tipo = ELEMENTO;
                c.data.val = a->data.val + b->data.val;
                break;

            case VETTORE_COLONNA:
            case VETTORE_RIGA:
                if(altro->tipo == VETTORE_COLONNA){
                    c.tipo = VETTORE_COLONNA;
                }else{
                    c.tipo = VETTORE_RIGA;
                }
                c.data.vet.val = malloc(altro->data.vet.size * sizeof(double));
                for (int i = 0; i < altro->data.vet.size ; i++){
                    c.data.vet.val[i] = elemento->data.val + altro->data.vet.val[i];         
                }
                break;

            case MATRICE:
                c.tipo = MATRICE;
                c.data.mat.size_x = altro->data.mat.size_x;
                c.data.mat.size_y = altro->data.mat.size_y;
                c.data.mat.val = (double**)malloc(altro->data.mat.size_y * sizeof(double));
                for (int i = 0; i < altro->data.mat.size_y ; i++){
                    c.data.mat.val[i] = malloc(altro->data.mat.size_x * sizeof(double));
                    for (int j = 0; j < c.data.mat.size_x ; j++){
                        c.data.mat.val[i][j] = elemento->data.val + altro->data.mat.val[i][j];            
                    }       
                }
                break;
        }
    }else{
        // Caso in cui sono entrambi o vettori o matrici
        switch (a->tipo){
            case VETTORE_COLONNA:
            case VETTORE_RIGA:
                if( a->data.vet.size == b->data.vet.size && a->tipo == b->tipo){
                    if(a->tipo == VETTORE_COLONNA){
                        c.tipo = VETTORE_COLONNA;
                    }else{
                        c.tipo = VETTORE_RIGA;
                    }
                    c.data.vet.val = malloc(a->data.vet.size * sizeof(double));
                    for (int i = 0; i < a->data.vet.size ; i++){
                        c.data.vet.val[i] = a->data.vet.val[i] + b->data.vet.val[i];         
                    }
                }else{
                    printf("Dimensione non coerente\n");
                    exit(EXIT_FAILURE);
                }
                break;

            case MATRICE:
                if(a->data.mat.size_x == b->data.mat.size_x && a->data.mat.size_y == b->data.mat.size_y && a->tipo == b->tipo){
                    c.tipo = MATRICE;
                    c.data.mat.size_x = a->data.mat.size_x;
                    c.data.mat.size_y = a->data.mat.size_y;
                    c.data.mat.val = (double**)malloc(a->data.mat.size_y * sizeof(double));
                    for (int i = 0; i < c.data.mat.size_y ; i++){
                        c.data.mat.val[i] = malloc(a->data.mat.size_x * sizeof(double));
                        for (int j = 0; j < c.data.mat.size_x ; j++){
                            c.data.mat.val[i][j] = a->data.mat.val[i][j] + b->data.mat.val[i][j];            
                        }       
                    }
                }else{
                    printf("Dimensione non coerente\n");
                    exit(EXIT_FAILURE);
                }
                break;
        }
    }
    return c;
}