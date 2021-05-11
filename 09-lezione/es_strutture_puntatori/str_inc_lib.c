/* Scrivere una libreria che gestisce la configurazione di incroci stradali
 * L'incrocio è caratterizzado da connettere 4 strade.
 * Ogni strada ha un nome ed è connessa a un elemento che può essere strada o un incrocio.
 * Scrivere un set di istruzioni che funzioni:
 * 1. Assegnare una strada ad un incrocio in una certa posizione.
 * 2. Connettere una strada ad un incrocio o ad un altra strada.
 * 3. Fare una funzione che partendo da una strada scelta percorre la strada mostrado il
 * nume della via percorsa fino ad incontrare un incrocio e a quel punto chiede all'utente 
 * di scegliere dove andare tra le strade disponibili nell'incrocio, termina quando la strada 
 * non è connessa a niente.
 */

#include <string.h>
#include <stdlib.h>
#include <stdio.h>
#include "str_inc_lib.h"

// Qui c'è allocazione di memoria
char *nome_tipo_el[] = {"Strada", "Incrocio", "Chiusa"};
// Inserisco qui le funzioni che operano 
// sulla struttura dati

void mostra_incrocio(struct incrocio *i);

void percorro(struct strada *s){
    printf("Sto percorrendo %s.\n", s->nome);

    switch(s->tipo_next){
        case STRADA:
            percorro(s->next.s);
            break;
        case INCROCIO:
            mostra_incrocio(s->next.i);
            break;
        case CHIUSA:
            printf("La strada è senza uscita.\n");
            break;
    }
}

void mostra_incrocio(struct incrocio *i){
    printf("Sono all'incrocio\n");
    printf("Queste sono le strade:\n");
    for(int j=0 ; j<4 ; j++){
        if(i->uscita[j] != 0){
            printf("%d %s\n",j,i->uscita[j]->nome);
        }
    }
    int scelta = -1;
    while(scelta == -1){
        scanf("%d",&scelta);
        if(scelta < 0 || scelta >= 4){
            scelta = -1;
        }else{
            if(i->uscita[scelta] == NULL){
                scelta = -1;
            }
        }
    }

    printf("Imbocco la strada: %s\n",i->uscita[scelta]->nome);
    percorro(i->uscita[scelta]);
}

// 2. Connettere una strada ad un incrocio o ad un altra strada.
void connetti_strade(struct strada *A, struct strada *B){
    A->next.s = B;
    A->tipo_next = STRADA;
}

// 2. Connettere una strada ad un incrocio o ad un altra strada.
void connetti_strade_incrocio(struct strada *A, struct incrocio *B){
    A->next.i = B;
    A->tipo_next = INCROCIO;
}

// * 1. Assegnare una strada ad un incrocio in una certa posizione.
void connetti_incrocio_strada(struct incrocio *A, int uscita, struct strada *B){
    A->uscita[uscita] = B;
}


// FUNZIONI CON MEMERIA DINAMICA
// QUESTE FUNZIONI NON ERANO RICHESTE DALLA TRACCIA
// funzione che crea una strada e ne ritorna il puntatore
struct strada* crea_strada(char *nome){
    struct strada *ss = malloc(sizeof(struct strada));
    strcpy(ss->nome ,nome);
    ss->next.s = NULL;
    ss->tipo_next = CHIUSA;   
    return ss;
}

// funzione che crea una strada e la connette alla strada A
struct strada* crea_connetti(struct strada *A, char *name){
    struct strada* aa = crea_strada(name);
    connetti_strade(A, aa);
    return aa;
}

// funzione che crea una incrocio e lo connette alla strada A
struct incrocio* crea_connetti_strada_incrocio(struct strada *A){
    struct incrocio *ii = malloc(sizeof(struct incrocio));
    connetti_strade_incrocio(A, ii);
    for(int i = 0; i <INCR_DIM;i++){
        ii->uscita[i] = NULL;
    }
    return ii;
}

// funzione che crea e connette una strada ad un incrocio A in posizione "uscita"
struct strada* crea_connetti_incrocio_strada(struct incrocio *A, int uscita, char *name){
    struct strada* aa = crea_strada(name);
    connetti_incrocio_strada(A, uscita, aa);
    return aa;
}

// Funzione che percorre tutte le strade e dealloca la memoria allocata
void cancella_geometria_stradale(struct strada *A){
    struct strada* a = A;
    struct incrocio* i;
    switch(a->tipo_next){
        case STRADA:
            cancella_geometria_stradale(A->next.s);
            break;
        case INCROCIO:
            i = A->next.i;
            for(int j=0 ; j<4 ; j++){
                if(i->uscita[j] != NULL){
                    cancella_geometria_stradale(i->uscita[j]);
                }
            }
            printf("Cancello incrocio\n");
            free(i);
            break;
        case CHIUSA:
            break;
    }
    printf("Cancello strada: %s\n",A->nome);
    free(A);
}