/*
 * Scrivere un gruppo di funzioni che opera sulla struttura veicolo e garage.
 * Il veicolo è caratterizzato dal peso, e dalle sue dimensioni (x,y,z).
 * Il garage è caratterizzato dalla sua dimensione (x,y,z) e dalla resistenza delle fondamenta e
 * da quale veicolo contine. Un garage può contenere un solo veicolo.
 * Scrivere una funzione che controlla se un veicolo è adatto a quel garage cioè se le dimensioni
 * e la resistenza dell fondamenta sono adeguate al veicolo in questione.
 * Scrivere una funzione che dato un vettore di veicoli ritorna quello più pesante.
 * Scrivere una funzione che dato un vettore di veicoli ritorna quello più grande (maggior volume).
 * Scrivere una funzione che assegna al garage il veicolo corrispondente.
 */
#include <stdio.h>

struct veicolo{
    double dim_x,dim_y,dim_z;
    double peso;   
};

struct garage{
    double dim_x,dim_y,dim_z;
    double res;
    struct veicolo *v;
};
