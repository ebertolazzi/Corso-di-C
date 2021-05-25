// Fare una macchina che calcola il resto dato il costo di un prodotto la soldi inseriti dal compratore.
// Il resto deve essere ottenuto con il numero minimo di monete
// Le monete utilizzabili per il resto sono 
// 1 centesimo
// 2 centesimi
// 5 centesimi
// 10 centesimi
// 50 centesimi
// 1 euro
// 2 euro
// Esempio:
// 20 euro utilizzati 17,32 costo -> [0.01,0.02,0.05,0.10,0.5,2.0]
// La funzione ritorni 0 se l'importo pagato è minore del costo altrimenti il ritorno sarà la
// dimensione del vettore
#include <stdio.h>
#include <stdlib.h>
#include "lib_stampa.h"

#define SIZE 8

int calcola_resto(const int costo, const int pagato, double *vett_resto){
    const int monete[] = {1,2,5,10,20,50,100,200};
    int num_monete[] = {0,0,0,0,0,0,0,0};
    int resto = pagato - costo;
    if(resto < 0){
        return 0;
    }

    int i = SIZE-1;
    int resto_rimasto = resto;
    
    do{
        num_monete[i] = resto_rimasto / monete[i];
        resto_rimasto = resto_rimasto % monete[i];
        i--;
    }while(i >= 0 && resto_rimasto != 0);
    stampa(num_monete, SIZE);
    
    vett_resto = malloc(sizeof(double) * 1);
    double* aux;
    int dim = 0;
    for(int i = 0; i<SIZE ; i++){
        if(num_monete[i] != 0){
            for(int j = 0; j<num_monete[i];j++){
                aux = realloc(vett_resto, sizeof(double)*(dim+1));
                if(aux != NULL){
                    vett_resto = aux;
                }
                vett_resto[dim] = monete[i];
                dim+=1;
            }
        }
    }
    stampa_double(vett_resto,dim);
    return dim;
};


int main(){
    double *vett_resto;
    int size = calcola_resto(1732,2000,vett_resto);
}
