
// Macro che definisce la dimensione massima del polinomio
#define SIZE 20

// Modalità statica
// struct      // Parola chiave del linguaggio per definire strutture
// polinomio   // Nome della struttura
// {   
//     // Qui vengono inseriti i campi della struttura
//     // Vettore degli elementi dei polinomi
//     int vett[SIZE];
//     // Dimensione del polinomio
//     int size;
// };

// Vettore dinamico
struct polinomio   
{   
    // Puntatore ad un vettore dinamico
    int *vett;
    // Dimensione del polinomio
    int size;
};

// Lista
// struct polinomio   
// {   
//     // Valore del coefficente del polinomio
//     int valore;
//     // puntatore al successivo
//     struct polinomio* next;
// };

// Ibrido
// struct polinomio   
// {   
//     // Dimensione del polinomio
//     int size;
//     // Valore del coefficente del polinomio
//     int vett[SIZE];
//     // Dimensione del polinomio
//     struct polinomio* next;
// };

typedef struct polinomio Polinomio;

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
struct polinomio somma_polinomi_valore(const struct polinomio* a, const struct polinomio* b);

// Funzione che somma due polinomi
void somma_polinomi(const struct polinomio* a, const struct polinomio* b, struct polinomio* r);

// Funzione che moltiplica due polinomi
void moltiplica_polinomi(const struct polinomio* a, const struct polinomio* b, struct polinomio* r);

// Libera memoria
void free_polinomio(struct polinomio* poly);