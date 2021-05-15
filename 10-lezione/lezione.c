#include <stdlib.h>
#include <stdio.h>


struct oggetto {
    char nome[20];
    int data;
};

struct elem {
    struct oggetto obj;
    struct elem *next;
};

typedef struct elem Elem;

// Elem s; // struct elem s;
void inserisci_in_cima(Elem **base, Elem *el){

    Elem *aux = (*base);

    (*base) = el;

    el->next = aux;
}

void inserisci_at(Elem **base, Elem *el, int ind){
    Elem *aux = (*base);
    if(ind == 0 || aux == NULL){
        (*base) = el;
        el->next = aux;
    }else{
        for(int i = 1; i < ind && aux->next != NULL; aux = aux->next, i++);
        el->next = aux->next;
        aux->next = el;
    }
}

void inserisci_in_fondo(Elem **base, Elem *el){

}

Elem* rimuovi_at(Elem **base, int ind){

}

int main(){
    Elem *base = NULL;

    Elem *el = malloc(sizeof(Elem));
    el->obj.data = 7;
    el->next = NULL;
    inserisci_in_cima(&base,el);

    el = malloc(sizeof(Elem));
    el->obj.data = 12;
    el->next = NULL;
    inserisci_in_cima(&base,el);

    el = malloc(sizeof(Elem));
    el->obj.data = 15;
    el->next = NULL;
    inserisci_in_cima(&base,el);

    printf("[");
    for(Elem *aux = base; aux != NULL; aux = aux->next){
        printf("%d",aux->obj.data);
        if(aux->next != NULL){
            printf(",");
        }
    }
    printf("]\n");
}