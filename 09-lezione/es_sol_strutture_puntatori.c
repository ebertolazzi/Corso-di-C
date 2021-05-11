/* Scrivere una libreria che gestisce la configurazione di incroci stradali
 * L'incrocio è caratterizzado da connettere 4 strade.
 * Ogni strada ha un nome ed è connessa a un elemento che può essere strada o un incrocio.
 * Scrivere un set di istruzioni che funzioni:
 * 1. Assegnare una strada ad un incrocio in una certa posizione.
 * 2. Assegnare a una strada cosa è connessa.
 * 3. Fare una funzione che partendo da una strada scelta percorre la strada mostrado il
 * nume della via percorsa fino ad incontrare un incrocio e a quel punto chiede all'utente 
 * di scegliere dove andare tra le strade disponibili nell'incrocio, termina quando la strada 
 * non è connessa a niente.
 */
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define STR_DIM 20

union tipo{
    struct strada *s;
    struct incrocio *i;
};

enum tipo_elemento{
    STRADA, INCROCIO, SENZA_USCITA
};
char *nome_tipo_elemento[] = {"Strada","Incrocio","Chiusa"};

struct strada {
    char nome[STR_DIM];
    enum tipo_elemento next_tipo;
    union tipo next;
};

struct incrocio{
    struct strada *uscita[4];
};

void mostra_incrocio(struct incrocio *i);

void percorro(struct strada *s){
    printf("Sto percorrendo %s.\n", s->nome);

    switch(s->next_tipo){
        case STRADA:
            percorro(s->next.s);
            break;
        case INCROCIO:
            mostra_incrocio(s->next.i);
            break;
        case SENZA_USCITA:
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
    int scelta;
    scanf("%d",&scelta);
    printf("Imbocco la strada: %s\n",i->uscita[scelta]->nome);
    percorro(i->uscita[scelta]);
}

struct strada* crea_strada(char *nome){
    struct strada *ss = malloc(sizeof(struct strada));
    strcpy(ss->nome ,nome);
    ss->next.s = NULL;
    ss->next_tipo = SENZA_USCITA;   
}

void connetti_strade(struct strada *A, struct strada *B){
    A->next.s = B;
    A->next_tipo = STRADA;
}

void connetti_strade_incrocio(struct strada *A, struct incrocio *B){
    A->next.i = B;
    A->next_tipo = INCROCIO;
}

void connetti_incrocio_strada(struct incrocio *A, int uscita, struct strada *B){
    A->uscita[uscita] = B;
}

struct strada* crea_connetti(struct strada *A, char *name){
    struct strada* aa = crea_strada(name);
    connetti_strade(A, aa);
    return aa;
}

struct incrocio* crea_connetti_strada_incrocio(struct strada *A){
    struct incrocio *ii = malloc(sizeof(struct incrocio));
    connetti_strade_incrocio(A, ii);
    return ii;
}

struct strada* crea_connetti_incrocio_strada(struct incrocio *A, int uscita, char *name){
    struct strada* aa = crea_strada(name);
    connetti_incrocio_strada(A, uscita, aa);
    return aa;
}



int main(){
    struct strada *ss = malloc(sizeof(struct strada));
    strcpy(ss->nome ,"Giacomo Leopardi");
    // Errore Non ho inizializzato tutta la struttura
    // percorro(ss); 
    // Meglio fare una funzione che crea una strada
    struct strada *ss1 = crea_strada("24 Maggio");
    percorro(ss1); 
    struct incrocio *i = crea_connetti_strada_incrocio(ss1);
    crea_connetti_incrocio_strada(i,0,"Antonio Bello");
    crea_connetti_incrocio_strada(i,1,"Maria Luce");
    crea_connetti_incrocio_strada(i,2,"Bolzano");
    percorro(ss1); 
    // struct strada ss[10];
    // struct incrocio ii[3];
    // strcpy(ss[0].nome ,"Giacomo Leopardi");
    // ss[0].next_tipo = STRADA;
    // ss[0].next.s = &ss[1];
    // strcpy(ss[1].nome ,"Vittorio Emanuele");
    // ss[1].next_tipo = INCROCIO;
    // ss[1].next.i = &ii[0];
    // ii[0].uscita[0] = &ss[2];
    // ii[0].uscita[1] = &ss[3];
    // ii[0].uscita[2] = 0;
    // ii[0].uscita[3] = 0;
    // strcpy(ss[2].nome ,"Paolina Bonaparte");
    // ss[2].next_tipo = STRADA;
    // ss[2].next.s = &ss[1]; 
    // strcpy(ss[3].nome ,"24 Maggio");
    // ss[3].next_tipo = STRADA;
    // ss[3].next.s = &ss[0]; 
    // percorro(&ss[0]);  
}