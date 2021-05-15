#include "lista.h"
#include <stdio.h>
#include <stdlib.h>

int main(){
    Elem *base;
    Elem *el = malloc(sizeof(Elem));
    el->obj.data = 5;
    inserisci_in_cima(&base,el);
    el = malloc(sizeof(Elem));
    el->obj.data = 7;
    inserisci_in_fondo(&base,el);
    el = malloc(sizeof(Elem));
    el->obj.data = 12;
    inserisci_at(&base,el,1);

    printf("[");
    for(Elem *aux = base; aux != NULL; aux = aux->next){
        printf("%d",aux->obj.data);
        if(aux->next != NULL){
            printf(",");
        }
    }
    printf("]\n");
}