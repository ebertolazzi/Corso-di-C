
#include "lib_unionmat.h"
#include <stdio.h>

int main(){
    UnionMat m1, m2, m3, m4;
    nuova_matrice(&m1);
    stampa_matrice(&m1);
    nuova_matrice(&m2);
    stampa_matrice(&m2);
    //m3 = somma_matrice(&m1,&m2);
    //stampa_matrice(&m3);
    m4 = moltiplica_matrice(&m1,&m2);
    stampa_matrice(&m4);
    //determinatne(m1);
}