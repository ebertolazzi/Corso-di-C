#include <stdio.h>
#include <stdlib.h>

// Riferimento alla libreria poly perché usiamo SIZE e struct polinomio
#include "lib_poly.h"

//Libreria per le funzioni su file
#include "lib_file.h"

void stampa_vettore_polinomio(const struct polinomio* poly){
    //Indice per il for
    int j;
    //Controllo polinomio è vuoto
    if(poly->size == 0){
        printf("Il polinomio è vuoto\n");
        return;
    }
    //Stampare il contenuto di vett
    printf("Il vettore del polinomio è composto da:\n[");
    for(j = 0 ; j < poly->size - 1 ; j++){
        printf("%d,",poly->vett[j]);
    }
    printf("%d]\n",poly->vett[j]);
}

int inserisci_elemento_polinomio(struct polinomio* poly){
    //Stringa 
    char s[5];
    //Intero letto
    int n;
    
    // Controlliamo di non uscire dal vettore
    if(poly->size >= SIZE){
        printf("Polinomio è pieno!\n");
        return 1;
    }
    
    printf("Inserisci il coefficente %d:",poly->size);
    //c = getchar(); getchar(); 
    // Leggo una stringa
    scanf(" %5s",s);
    printf("Strina letta: %s\n",s);
    
    //Controllo per verifare se ho letto 'f'
    if( s[0] == 'f' ){
        return 1;
    }

    //Conversione della stringa s in intero
    //https://en.cppreference.com/w/cpp/string/byte/atoi
    n = atoi(s);
    //Inserisco l'elemento dentro al vettore
    poly->vett[(poly->size)++] = n;
    // Questa è equivalente
    // poly->vett[poly->size] = n;
    // poly->size++; // Oppure poly->size += 1; 
    
    // Non è equivalente a questa
    // poly->vett[++(poly->size)] = n;
    // E equivalente a
    // poly->size++;
    // poly->vett[poly->size] = n;

    return 0;
}

// Creare un nuovo polinomio
void nuovo_polinomio(struct polinomio* poly){
    // Variabile di ciclo
    int fine = 0;
    // Reset della dimensione del polinomio
    poly->size = 0;

    //Controllo se ho letto 'f' e se size < SIZE
    while(fine == 0 && poly->size < SIZE){
        // Inserisco un elemento nel vettore
        fine = inserisci_elemento_polinomio(poly);
        // Stampa del vettore
        stampa_vettore_polinomio(poly);
    }
    // Il polinomio è
    mostra_polinomio(poly);
}

// Salva un polinomio su FILE
void salva_polinomio(const struct polinomio* poly){
    // Variabile nome del file del polinomio
    char s[10];

    // Puntatore al file dove sara salvato il polinomio
    FILE *file;

    // Variabile del ciclo di stampa
    int j;

    // Verifica del polinomio
    if(poly->size == 0){
        printf("Polinomio vuoto\n");
        return;
    }

    printf("Inserisci nome del polinomio:");
    //Lettura del nome del file del polinomio
    scanf(" %10s",s);

    // Apertura file polinomio
    file = apri_file(s,"w");

    // Stampare il polinomio su file
    // Stampo la dimensione per prima cosi so quanti coefficenti è composto il polinomio nel momento in cui dovro' caricarlo
    fprintf(file, "%d\n", poly->size);
    // Stampa degli elementi del polinomio
    fprintf(file, "[");
    for(j = 0; j < poly->size-1; j++){
        fprintf(file, "%d,", poly->vett[j]);
    }
    fprintf(file, "%d]", poly->vett[j]);

    // Chiudere il file
    fclose(file);
}

// Carica un polinomio da FILE
void carica_polinomio(struct polinomio* poly){
    // Variabile nome del file del polinomio
    char s[10];

    // Puntatore al file del polinomio che sara caricato
    FILE *file;

    // Variabile del ciclo di lettura
    int j;

    printf("Inserisci nome del polinomio da caricare:");
    //Lettura del nome del file del polinomio
    scanf(" %10s",s);

    // Apertura file polinomio
    file = apri_file(s,"r");

    // Leggiamo il polinomio da file
    // Leggo la dimensione del polinomio
    fscanf(file, "%d\n", &poly->size);
    // Leggo gli elementi del polinomio
    fscanf(file, "[");
    for(j = 0; j < poly->size-1; j++){
        // Leggo i coefficenti del polinomio
        fscanf(file, "%d,", &poly->vett[j]);
    }
    fscanf(file, "%d]", &poly->vett[j]);

    // Stampa del polinomio
    mostra_polinomio(poly);

    // Chiudere il file
    fclose(file);
}

void mostra_polinomio(const struct polinomio* poly){
    // Variabile di ciclo
    int j;
    // variabile di appoggio per la stampa
    int n;

    // Verifica del polinomio
    if(poly->size == 0){
        printf("Polinomio vuoto\n");
        return;
    }

    printf("Il polinomio è:");
    // Ciclo del polinomio per la stampa
    for(j = poly->size-1; j >= 0 ; j--){
        if(poly->vett[j] < 0){
            printf("-");
            n = -poly->vett[j];
        }else{
            if(j != poly->size-1){
                printf("+");
            }
            n = poly->vett[j];
        }
        switch (j)
        {
            case 0:
                printf(" %d",n);
                break;

            case 1:
                printf(" %d x ",n);
                break;
        
            default:
                printf(" %d x^%d ",n,j);
                break;
        }
    }
    printf("\n");
}

void valuta_polinomio(const struct polinomio* poly){
    // File per la valutazione del polinomio
    FILE *file;

    // Variabile ausiliarie
    double da, a, p, x, fx;

    if(poly->size == 0){
        printf("Polinomio vuoto\n");
        return;
    }

    // Recupero dall'utente i parametri per valutazione del polinomio
    printf("Valuta polinomio da:");
    scanf("%lf", &da);
    printf("a:");
    scanf("%lf", &a);
    printf("Passo da utilizzare:");
    scanf("%lf", &p);

    // Apro il file dove salvo i valore del polinomio valutato
    file = apri_file("valori" ,"a");

    // Valutazione del polinomio dal valore di 'x=da' al valore di 'x=a'
    x = da;
    while(x < a){
        // Valutazione di un polinomio utilizzando il metodo di Horner
        // https://it.wikipedia.org/wiki/Regola_di_Horner
        // Assegno a fx il valore del coefficente più significativo
        fx = poly->vett[poly->size-1];
        for(int j = poly->size-2 ; j >= 0; j--){
            // Moltiplico al valore precedente di fx il valore di x poi sommo il coefficente j
            fx = fx * x + poly->vett[j];
        }
        //Stampo sul file i falore di x ed fx
        fprintf(file, "%lf\t%lf\n", x, fx);
        x += p;
    }

    //Chiudere il file
    fclose(file);
} 

// Funzione che somma due polinomi
void somma_polinomi(const struct polinomio* a, const struct polinomio* b, struct polinomio* r){

    // Polinomio dimensioni massime e minime
    int max_size, min_size;

    // Determina quale polinomio e' più grande
    if(a->size < b->size){
        min_size = a->size;
        max_size = b->size;
    }else{
        min_size = b->size;
        max_size = a->size;
    }

    // Configurato la dimensione di res
    r->size = max_size;
    // Ciclo fino alla dimensione del polinomio piu' grande
    for(int j = 0; j < max_size; j++){
        if(j < min_size){
            // Configuro gli elementi fino a min_size
            r->vett[j] = a->vett[j] + b->vett[j];
        }else{
            // Configuro gli elementi da min_size a max_size
            if(max_size == b->size){
                r->vett[j] = b->vett[j];
            }else{
                r->vett[j] = a->vett[j];
            }
        }
    }
}

// Funzione che moltiplica due polinomi
void moltiplica_polinomi(const struct polinomio* a, const struct polinomio* b, struct polinomio* res){
    // Variabile di ciclo
    int i, j;

    // La dimensione è la somma delle dimensioni
    r->size = a->size + b->size - 1;

    // Pulisco il vettore
    for(i = 0; i < r->size; i++){
        r->vett[i] = 0;
    }

    // Determino la massima dimensione
    // Ogni elemento di a è moltiplicato per ogni elemento di b e sommato al valore già calcolato
    for(j = 0; j < a->size; j++){
        for(i = 0; i < b->size; i++){
            r->vett[i+j] += a->vett[j] * b->vett[i];
        }
    }    
}