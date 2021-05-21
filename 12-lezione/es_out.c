// Scrivi una funzione che conta le ricorrenze di ogni numero all'interno del vettore di ingresso
// e riempie un vettore allocato dinamicamente con il valore di queste ricorrenze in ordine cresente
#include "lista.h"

int *count(int array[], int size)


{
    if (size == 0)
    {
        return NULL;
    }
    Elem *base = calloc(1,sizeof(Elem));
    base->val = array[0];
    base->count = 1;
    base->next = NULL;
    int dim_lista = 1;
    for (int i = 1; i < size; i++)
    {
        for(Elem *aux = base;aux != NULL; aux = aux->next){
            if(aux->val == array[i]){
                aux->count++;
                inserisci_ordinato(&base, rimuovi_elem(&base, aux));
            }else{
                if(aux->next == NULL){
                    aux->next = calloc(1,sizeof(Elem));
                    base->val = array[i];
                    base->count = 1;
                    base->next = NULL;
                    dim_lista++;
                }
            }
        }
    }
    Data *res = calloc(dim_lista,sizeof(Data));
    int min = -1;
    for(int i = 0; i<dim_lista; i++){
        Data *min_el = base;
        for(Data *aux = base;aux != NULL; aux = aux->next){
            if(min == -1 || aux->count <= min){
                min_el = aux;
                min = aux->count;
            }
        }
    }
    return res;
}