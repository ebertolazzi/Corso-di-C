/*
 * Scrivere un gruppo di funzioni che opera sulla 
 * struttura treno. Il treno è identificato dal 
 * numero di carrozze, dal tipo di trazione 
 * (elettrica o a gasolio).
 * La funzione aggiungi carrozza che aumenta 
 * le carrozze del treno.
 * La funzione rimuovi carrozza che 
 * diminuisce le carrozze del treno.
 * Un ultima funzione che prende un treno 
 * e un tipo di trazione ed assegna la trazione 
 * al treno.
 * Fare una funzione che connette 
 * due treni modificando il primo.
 */

#include <stdio.h>

enum tipo_trazione{
    ELETTRICO, GASOLIO
};
char *str_tipo_trazione[] = {"EL","GA"};



struct treno {
    int num_carrozze;
    enum tipo_trazione trazione;
};

// struct treno {
//     int num_carozze;
//     enum {
//         ELETTRICO, GASOLIO
//     } trazione;
// };

void aumenta_carrozze(struct treno *t){
    t->num_carrozze++; /* (*t).num_carozze++; */
}

void diminuisci_carrozze(struct treno *t){
    t->num_carrozze--;
}

void assegna_trazione(struct treno *t, enum tipo_trazione tipo){
    t->trazione = tipo;
}

void connetti(struct treno *t1, struct treno *t2){
    t1->num_carrozze += t2->num_carrozze;
    t2->num_carrozze = 0;
}

int main(){
    struct treno A = {5, ELETTRICO};
    // A.num_carozze++;
    // A.trazione = GASOLIO;
    aumenta_carrozze(&A);
    diminuisci_carrozze(&A);
    assegna_trazione(&A,GASOLIO);
    printf("Il treno ha %d carrozze e utilizza %s come trazione.\n",A.num_carrozze,str_tipo_trazione[A.trazione]);

    struct treno B = {4, ELETTRICO};
    connetti(&A,&B);
    printf("Il treno ha %d carrozze e utilizza %s come trazione.\n",A.num_carrozze,str_tipo_trazione[A.trazione]);
    printf("Il treno ha %d carrozze e utilizza %s come trazione.\n",B.num_carrozze,str_tipo_trazione[B.trazione]);
}