
#include <stdlib.h>
#include <stdio.h>

#include "lib/lista.h"

void print_lista(Elem *base){
    printf("\n");
    for(Elem *aux = base; aux != NULL; aux=aux->next){
        printf("%d ",aux->data);
    }
    printf("\n");
}

int main(){
    // Creazione del puntatore base
    Elem *base = NULL;

    // Elemento che voglio inserire un elemento
    // Creo un elemento
    Elem *elem = malloc(sizeof(Elem));
    elem->data = 3;
    elem->next = NULL;
    // Inserico utilizzando la nostra funzione
    inserisci_in_cima(&base, elem);

    print_lista(base);

    // Creo un elemento
    Elem *elem2 = malloc(sizeof(Elem));
    elem2->data = 6;
    elem2->next = NULL;
    // Inserico utilizzando la nostra funzione
    inserisci_in_fondo(&base, elem2);

    print_lista(base);

    // Inserico utilizzando la nostra funzione
    inserisci_at(&base, calloc(1,sizeof(Elem)), 1);print_lista(base);
    inserisci_at(&base, calloc(1,sizeof(Elem)), 0);print_lista(base);
    inserisci_at(&base, calloc(1,sizeof(Elem)), 1);print_lista(base);
    inserisci_at(&base, calloc(1,sizeof(Elem)), 5);print_lista(base);

    free(rimuovi_at(&base, 4)); print_lista(base);
    free(rimuovi_at(&base, 4)); print_lista(base);
    free(rimuovi_at(&base, 4)); print_lista(base);
    free(rimuovi_at(&base, 4)); print_lista(base);
    free(rimuovi_at(&base, 4)); print_lista(base);
    free(rimuovi_at(&base, 4)); print_lista(base);
    free(rimuovi_at(&base, 4)); print_lista(base);
}