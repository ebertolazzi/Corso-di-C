#include <stdio.h>

void fun1(int (*c)[10]){
    (*c)[0] = 4;
}

//E' equivalente a void fun2(int *c){
void fun2(int c[]){
    c[3] = 4;
    //Equivalente *(c+3) = 4;
}

void fun3(int (*c)[5]){
    (*c)[0] = 4;
}

int main(){
    // Array di 10 elementi
    int ar[10];
    // Puntatore ad intero
    int *p;
    // Asseganzione del l'indirizzo del primo 
    // elemento del vettore di interi al puntatore,
    // Dato che ar[0] è un intero ne prendo l'indirizzo e
    // lo assegno al puntatore
    p = &ar[0];
    // Modifico il contenuto della variabile puntata da p
    // in questo caso è come scrivere ar[0] = 3;
    (*p) = 3;
    
    // Assegno a p il vettore ar (ricordati che vettori e puntatori sono la stessa cosa)
    p = ar;

    // Stampo ar
    for(int i=0; i<10; i++){
        printf("%d,",ar[i]);
        // Arittmetica dei puntatori
        // è equivalente a printf("%d,",*(ar+i));
    }
    printf("\n");

    // Non è corretto in quanto l'indirizzo di ar
    // è l'indirizzo di un vettore di 10 elementi non
    // l'indirizzo di un intero
    //p = &ar;
    
    //Creazione di un puntatore a vettore di 10 elementi
    int (*pp)[10];
    // Corretto assegnamento del puntatore a vettori di interi da 10 elementi
    pp = &ar;
    
    // Corretta chiamata a funzione 
    // La funzione prende l'indirizzo di vettori di interi da 10 elementi
    fun1(&ar);
    for(int i=0; i<10; i++){
        printf("%d,",ar[i]);
    }
    printf("\n");
    // La funzione prende un puntatore ar è un puntatore.
    fun2(ar);
    for(int i=0; i<10; i++){
        printf("%d,",ar[i]);
    }

    // Warning ar è di 10 elementi e c è di 5
    //fun3(&ar);
    printf("\n");

    // Vettore multidimensionale
    int ar2d[5][4];
    for (int i = 0; i<5 ;i++){
        for (int j = 0; j<4 ; j++){
            ar2d[i][j] = j+i*4+1;
        }
    }
    for (int i = 0; i<5 ;i++){
        for (int j = 0; j<4 ; j++){
            printf("%d, ",ar2d[i][j]);
        }
        printf("\n");
    } 

    // Creo un puntatore a vettori di 4 elementi
    int (*ar4i)[4];
    // Assegnamento corretto puntatore a puntatore
    for(ar4i = ar2d; // Equivalente a er4i = &ar2d[0]
        // Controllo di essere nell'ultimo vettore da 4 elementi
        ar4i <= &(ar2d[4]) ; 
        // Aritmetica dei puntatori il ++ mi fa avanzare di 4 elementi di tipo intero
        ar4i++){
        // Dereferenzio il puntatore ed utilizzo ed accedo al terzo l'elemento 
        (*ar4i)[2] = 0;
    }
    
    printf("\n");
    for (int i = 0; i<5 ;i++){
        for (int j = 0; j<4 ; j++){
            printf("%d, ",ar2d[i][j]);
        }
        printf("\n");
    } 
}