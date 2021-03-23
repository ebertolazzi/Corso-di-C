// Macro che definisce la dimensione massima del polinomio
#define SIZE 10

struct     // Parola chiave per creare strutture
polinomio{ // Nome della struttura, la struttura è un nuovo tipo variabile.
    // Qui all'interno ci sono i campi della struttura
    // Vettore degli elementi del polinomio
    int vett[SIZE];
    // Dimensione del polinomio
    int size;
}poly_vett[10];     // Creazione di variabile di tipo polinomio

//Funzione inserisci elemento usando una struttura
int inserisci_elemento_polinomio(struct polinomio *poly);

// Creare un nuovo polinomio
void nuovo_polinomio(struct polinomio *poly);

// Salva un polinomio su FILE
void salva_polinomio(const struct polinomio *poly);

// Carica un polinomio da FILE
void carica_polinomio(struct polinomio *poly);

// Stampa il polinomio a video
void mostra_polinomio(const struct polinomio *poly);

// Valuta polinomio con il metodo di Horner
void valuta_polinomio(const struct polinomio *poly);

// Somma polinomi
void somma(const struct polinomio *a, const struct polinomio *b, struct polinomio *r);

// Moltiplica polinomi
void moltiplica(const struct polinomio *a, const struct polinomio *b, struct polinomio *r);