/* Scrivere una libreria che gestisce la configurazione di 
 * incroci stradali.
 * L'incrocio è caratterizzado da connettere 4 strade.
 * Ogni strada ha un nome ed è connessa a un elemento che può essere strada o un incrocio.
 * Scrivere un set di istruzioni che funzioni:
 * 1. Assegnare una strada ad un incrocio in una certa posizione.
 * 2. Connettere una strada ad un incrocio o ad un altra strada.
 * 3. Fare una funzione che partendo da una strada scelta percorre la strada mostrado il
 * nome della via percorsa fino ad incontrare un incrocio e a quel punto chiede all'utente 
 * di scegliere dove andare tra le strade disponibili nell'incrocio, termina quando la strada 
 * non è connessa a niente.
 */

#include <stdio.h>
#include <string.h>
#include "str_inc_lib.h"

int main(){
    struct strada *ss = crea_strada("24 Maggio");
    percorro(ss); 
    struct incrocio *i = crea_connetti_strada_incrocio(ss);
    crea_connetti_incrocio_strada(i,0,"Antonio Amato");
    crea_connetti_incrocio_strada(i,1,"Maria Vergine");
    crea_connetti_incrocio_strada(i,2,"Bolzano");
    percorro(ss); 
    cancella_geometria_stradale(ss);
}