#include <time.h>

// Elemento della lista
struct elem
{
    // Dato salvato nella lista
    struct oggetto obj;
    // Puntatore all'elemento successivo
    struct elem *next;
};

struct oggetto{
    char nome[20];
    time_t ora;
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