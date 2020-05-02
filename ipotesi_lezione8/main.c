 
#include <stdio.h>
#include <stdlib.h>

#include "lista.h"


int main(){
    Elem* base;
    Elem* el = malloc(sizeof(Elem)); 
    el->data = 3;
    inserisci_in_cima(&base,el);
    
    printf("primo elemento: %d", base->data);
}