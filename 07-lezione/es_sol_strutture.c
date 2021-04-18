/*
 * Scrivere un gruppo di funzioni che opera sulla struttura treno
 * Il treno è identificato dal numero di carrozze, dal tipo di trazione (elettrica o a gasolio).
 * La funzione aggiungi carrozza che aumenta le carrozze del treno
 * La funzione rimuovi carrozza che diminuisce le carrozze del treno
 * ed un ultima funzione che prende un treno e un tipo di trazione ed assegna la trazione al treno.
 * Fare una funzione che connette due treni modificando il primo.
 */
#include <stdio.h>

struct treno{
    int num_carozze;
    char trazione; /* 'e' o 'g' */
};

void aumenta_carrozze(struct treno *t){
    t->num_carozze++;
};

void diminuisci_carrozze(struct treno *t){
    t->num_carozze--;
};

void cambia_trazione(struct treno *t, char tipo){
    t->trazione = tipo;
};

int main(){
    struct treno A = {4,'e'};
    aumenta_carrozze(&A);
    printf("Il treno ha %d carrozze e utilizza %c trazione.\n",A.num_carozze,A.trazione);
}