
// Macro che definisce la dimensione massima del polinomio
#define SIZE 5

// Approccio a lista di vettori
struct      // Parola chiave del linguaggio per definire strutture
polinomio   // Nome della struttura
{   
    // Qui vengono inseriti i campi della struttura
    // Vettore degli elementi dei polinomi
    int vett[SIZE];
    // Dimensione del polinomio
    int size;
    // Successivo vettore
    struct polinomio* next_polinomio;
};

// Approccio a vettore dinamico
struct          // Parola chiave del linguaggio per definire strutture
polinomio_vett  // Nome della struttura
{   
    // Qui vengono inseriti i campi della struttura
    // Puntatore a vettore dinamico
    int *vett;
    // Dimensione del polinomio
    int size;
};

// Approccio a lista
struct              // Parola chiave del linguaggio per definire strutture
polinomio_elem {    // Nome della struttura
    // Valore dell'elemento
    int value;
    // Elemento successimo
    struct polinomio_elem* next_value;
};

// Questa funzione stampa del vettore di polinomi
void stampa_vettore_polinomio(const struct polinomio* poly);

// Questa funzione inserisce un numero nell'elemento vett di poly
// in posizione 'poly->size' e ne incrementa il valore
// ritorna 1 se viene letto il carattere 'f'
// altrimenti torna 0
int inserisci_elemento_polinomio(struct polinomio* poly);

// Creare un nuovo polinomio
void nuovo_polinomio(struct polinomio* poly);

// Salva un polinomio su FILE
void salva_polinomio(const struct polinomio* poly);

// Carica un polinomio da FILE
void carica_polinomio(struct polinomio* poly);

// Stampa il polinomio a video
void mostra_polinomio(const struct polinomio* poly);

// Valuta polinomio con il metodo di Horner
void valuta_polinomio(const struct polinomio* poly);

// Funzione che somma due polinomi
void somma_polinomi(const struct polinomio* a, const struct polinomio* b, struct polinomio* r);

// Funzione che moltiplica due polinomi
void moltiplica_polinomi(const struct polinomio* a, const struct polinomio* b, struct polinomio* r);