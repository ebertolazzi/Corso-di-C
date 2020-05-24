
#include <stdio.h>

int somma(int a, int b){
    return a + b;
}

int sottrazione(int a, int b){
    return a - b;
}

int moltiplicazione(int a, int b){
    return a * b;
}

int divisione(int a, int b){
    return a / b;
}

// Definisco il mio vettore di puntatori a funzione
int (*operazione[3])(int,int);

int main(){
    //Assegno le varie operazioni
    operazione[0] = somma;
    operazione[1] = divisione;
    operazione[2] = sottrazione;
    char op[]={'+','/','-'};
    
    // Variabili utilizzate per l'esempio
    int res = 5;
    int vett[] = {3,2,4};
    // operazioni che vado ad eseguire
    // 5 + 2 = 8
    // 8 / 2 = 4
    // 4 - 4 = 0
    for(int i = 0 ; i < 3 ; i ++){
        printf("%d %c %d = ",res,op[i],vett[i]);
        res = operazione[i](res,vett[i]);
        printf("%d\n",res);
    }
}