#include <stdlib.h>
#include "lista.h"

void inserisci_in_cima(Elem **base, Elem *el){
    // Copio l'indirizzo del primo elemento puntato dalla base in una variabile di appoggio
    Elem *aux = (*base);
    // Modifico la base così che punti al nuovo elemento
    (*base) = el;
    // Il puntatore next dell'elemento inserito punta al vecchio primo elemento
    el->next = aux;
}

void inserisci_ordinato(Elem **base, Elem *el){
    // Recupero puntatore primo elemento
    Elem *aux = (*base);
    // Controllo se voglio inserire in testa o la lista è vuota
    if(aux == NULL){
        // Modifico la base così che punti al nuovo elemento
        (*base) = el;
        // Il puntatore next dell'elemento inserito punta al vecchio primo elemento
        el->next = aux;
    }else{
        // Scorre la lista
        for(aux->next != NULL && aux->next->count <= el->count ; aux = aux->next);
        // prendo il nuovo elemento e lo faccio puntare al successivo
        el->next = aux->next;
        // modifico ora aux-next e lo faccio puntare al mio nuovo elemento
        aux->next = el;
    }
}


void inserisci_in_fondo(Elem **base, Elem *el){
    // Copio l'indirizzo del primo elemento puntato dalla base in una variabile di appoggio
    Elem *aux = (*base);
    // Controllo se la lista è vuota
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

void inserisci_at(Elem **base, Elem *el, int ind){
    // Recupero puntatore primo elemento
    Elem *aux = (*base);
    // Controllo se voglio inserire in testa o la lista è vuota
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

Elem* rimuovi_elem(Elem **base, Elem *el){
    // Controllo se la lista non è vuota
    if(*base == NULL){
        return NULL;
    }
    // Recupero puntatore primo elemento
    Elem *aux = (*base);

    // Modifico la base se ho chiesto di estrarre il primo elemento
    // oppure perché c'è un solo elemento
    if(el == base){
        // Modifico la base
        (*base) = aux->next;
        // Ritorno l'elemento
        return aux;
    }else{
        // Scorre la lista
        for(aux->next != NULL && aux->next != el; aux = aux->next); 
        // Scorrendo la lista sono arrivato all'ultimo elemento       
        if(aux->next == NULL){
            // Elemento non presente
            return NULL;       
        }else{
            // Creaiamo un puntatore per l'elemento da ritornare
            Elem* ret = aux->next;
            // modifichiamo il valore del campo next dell'elemento precedente
            aux->next = ret->next;
            // Ritorniamo l'elemento
            return ret;
        }
    }
}

Elem* rimuovi_at(Elem **base, int ind){
    // Controllo se la lista non è vuota
    if(*base == NULL){
        return NULL;
    }
    // Recupero puntatore primo elemento
    Elem *aux = (*base);

    // Modifico la base se ho chiesto di estrarre il primo elemento
    // oppure perché c'è un solo elemento
    if(ind == 0 || aux->next == NULL){
        // Modifico la base
        (*base) = aux->next;
        // Ritorno l'elemento
        return aux;
    }else{
        // Scorre la lista
        for(int i = 1; aux->next != NULL && i < ind; aux = aux->next, i++); 
        // Scorrendo la lista sono arrivato all'ultimo elemento       
        if(aux->next == NULL){
            // Creaiamo un nuovo puntatore al penultimo elemento che sarà settato a null
            Elem *to_null = (*base);
            // Sto scorrendo la lista cercando il penultimo elemento
            for(; to_null->next != aux ; to_null = to_null->next);   
            // Setto a null il valore del next del penultimo elemento che diventerà l'ultimo
            to_null->next = NULL;
            // Ritorno l'ultimo elemento
            return aux;       
        }else{
            // Creaiamo un puntatore per l'elemento da ritornare
            Elem* ret = aux->next;
            // modifichiamo il valore del campo next dell'elemento precedente
            aux->next = ret->next;
            // Ritorniamo l'elemento
            return ret;
        }
    }
}
