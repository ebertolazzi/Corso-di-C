#include <time.h>


// Elemento della lista
struct elem
{
    int count;
    int val;
    // Puntatore all'elemento successivo
    struct elem *next;
};

// Shortcut per definire oggetti di tipo struct elem
typedef struct elem Elem;

// Funzione che inserisce in testa alla lista
void inserisci_in_cima(Elem **base, Elem *el);

// Funzione che inserisce in fondo alla lista
void inserisci_in_fondo(Elem **base, Elem *el);

// Funzione che inserisce in una posizione data
void inserisci_at(Elem **base, Elem *el, int ind);

// Rimuovi elemento i-esimo
Elem* rimuovi_at(Elem **base, int ind);