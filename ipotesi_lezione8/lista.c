#include "lista.h"

void inserisci_incima(Elem** base, Elem* el){
    Elem* appoggio;
    appoggio = (*base);
    (*base) = el;
    el->p = appoggio;
}

void inserisci_in_fondo(Elem **base, Elem *el){
    // Copio l'indirizzo del primo elemento puntato dalla base in una variabile di appoggio
    Elem *aux = *base;
    if(aux == NULL){
        // Modifico la base così che punti al nuovo elemento
        (*base) = el;
        // Il puntatore next dell'elemento inserito punta al vecchio primo elemento
        el->next = aux;        
    }else{
        // Scorre la lista
        for(; aux->next != NULL; aux = aux->next);
        // Assegnare al puntatore next dell'ultimo elemento il nuovo elemento
        aux->next = el;
    }
}

           case 's':
                ind = scegli_indice("Scegli l'indice del polinomio da salvare:");
                for(i = 0, p = base_poly; p != NULL && i < ind; p = p->next, i++);
                if(p == NULL){
                    printf("Indice errato\n");
                }else{
                    salva_polinomio(&p->poly);
                }
                break;

            case 'v':
                // ind = scegli_indice("Scegli l'indice del polinomio da valutare:");
                //valuta_polinomio(&vett_poly[ind]);
                break;

            case 'm':
                for(i = 0, p = base_poly; p != NULL; p = p->next, i++){
                    printf("Il polinomio in posizione %d è:\n",i);
                    mostra_polinomio(&p->poly);
                }
                
                break;

    free(rimuovi_at(&base,0));print_lista(base);
    free(rimuovi_at(&base,0));print_lista(base);
    free(rimuovi_at(&base,0));print_lista(base);
    free(rimuovi_at(&base,0));print_lista(base);
    free(rimuovi_at(&base,0));print_lista(base);
    free(rimuovi_at(&base,0));print_lista(base);
    free(rimuovi_at(&base,0));print_lista(base);
    inserisci_at(&base, calloc(1,sizeof(Elem)), 0);print_lista(base);
    inserisci_at(&base, calloc(1,sizeof(Elem)), 0);print_lista(base);
    inserisci_at(&base, calloc(1,sizeof(Elem)), 0);print_lista(base);
    inserisci_at(&base, calloc(1,sizeof(Elem)), 0);print_lista(base);

void inserisci_at(Elem **base, Elem *el, int ind){
    // Recupero puntatore primo elemento
    Elem *aux = (*base);
    // Controllo se voglio inserire in testa
    if(ind == 0 || aux == NULL){
        // Modifico la base così che punti al nuovo elemento
        (*base) = el;
        // Il puntatore next dell'elemento inserito punta al vecchio primo elemento
        el->next = aux;
    }else{
        // Scorre la lista
        for(int i = 1; aux->next != NULL && i < ind; aux = aux->next, i++);
        // prendo il nuovo elemento e lo faccio puntare al successivo
        el->next = aux->next;
        // modifico ora aux-next e lo faccio puntare al mio nuovo elemento
        aux->next = el;
    }
}

Elem* rimuovi_at(Elem **base, int ind){
    if(*base == NULL){
        return NULL;
    }
    // Recupero puntatore primo elemento
    Elem *aux = (*base);

    if(ind == 0 || aux->next == NULL){
        // Modifico la base così che punti al nuovo elemento
        (*base) = aux->next;
        // ritorno l'elemento rimosso
        return aux;
    }
    // Scorre la lista
    for(int i = 1; aux->next != NULL && i < ind; aux = aux->next, i++);
    if(aux->next == NULL){
        Elem *to_null = *base;
        for(; to_null->next != aux; to_null = to_null->next);
        to_null->next = NULL;
        // ritorno l'ultimo
        return aux;
    }else{
        Elem *ret = aux->next;
        aux->next = ret->next;
        return ret;
    }    
}