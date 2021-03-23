// Macro che definisce la dimensione massima del polinomio
#define SIZE 10

// Creare un nuovo polinomio
void nuovo_polinomio(int vett[], int *size);

// Salva un polinomio su FILE
void salva_polinomio(const int vett[],const int *size);

// Carica un polinomio da FILE
void carica_polinomio(int vett[], int *size);

// Stampa il polinomio a video
void mostra_polinomio(const int vett[], const int *size);

// Valuta polinomio con il metodo di Horner
void valuta_polinomio(const int vett[],const int* size);
