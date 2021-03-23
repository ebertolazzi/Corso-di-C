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
    // Ciclo i mei puntatori next_polinomio
    for(; poly != NULL; poly = poly->next_polinomio){
        for(j = 0 ; j < poly->size /*importante togliere il meno 1*/; j++){
            if( (poly->next_polinomio == NULL) && (j == poly->size-1) ){
                printf("%d]\n", poly->vett[j]);
            }else{
                printf("%d,", poly->vett[j]);
            }
        }
    }
    
}

// Inserisco prima il vettore è una soluzione che non è molto buona!!!
int inserisci_elemento_polinomio_OLD(struct polinomio* poly){
    //Stringa 
    char s[5];
    //Intero letto
    int n;
    // Salvo quanti vettori ho gia' visitato
    int vett_ind = 0;
    
    // Controlliamo di non uscire dal vettore
    while(poly->size >= SIZE){
        // Qui va spiegato molto bene!
        if(poly->next_polinomio == NULL){
            printf("Allocazione nuovo vettore\n");
            poly->next_polinomio = malloc(sizeof(struct polinomio));
            poly = poly->next_polinomio;
            poly->size = 0;
            poly->next_polinomio = NULL;
        }else{
            poly = poly->next_polinomio;
        }
        vett_ind += SIZE;
    }
    
    printf("Inserisci il coefficente %d:",vett_ind + poly->size);
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

    return 0;
}

int inserisci_elemento_polinomio(struct polinomio* poly){
    //Stringa 
    char s[5];
    //Intero letto
    int n;
    // Salvo quanti vettori ho gia' visitato
    int vett_ind = 0;
    // Salvo quanti vettori ho in totale
    int tot_structs = 1;

    //Prima devo definire la dimensione massima
    for(; poly->next_polinomio != NULL; poly = poly->next_polinomio){
        tot_structs += 1;
    }   

    // Stampa del coefficente
    printf("Inserisci il coefficente %d:",poly->size+(tot_structs-1)*SIZE);
    // Leggo una stringa
    scanf(" %5s",s);
    printf("Strina letta: %s\n",s);
    
    //Controllo per verifare se ho letto 'f'
    if( s[0] == 'f' ){
        return 1;
    }

    //Se il vettore è pieno alloco un altro elemento
    if(poly->size == SIZE){
        printf("Allocazione nuovo vettore\n");
        poly->next_polinomio = malloc(sizeof(struct polinomio));
        poly = poly->next_polinomio;
        poly->size = 0;
        poly->next_polinomio = NULL;
    }

    //Conversione della stringa s in intero
    //https://en.cppreference.com/w/cpp/string/byte/atoi
    n = atoi(s);
    //Inserisco l'elemento dentro al vettore
    poly->vett[(poly->size)++] = n;

    return 0;
}

// Creare un nuovo polinomio
void nuovo_polinomio(struct polinomio* poly){
    // Variabile di ciclo
    int fine = 0;
    // Reset della dimensione del polinomio
    poly->size = 0;
    // Bisogna inizilizzare anche il puntatore a NULL
    poly->next_polinomio = NULL;

    // Controllo se ho letto 'f'
    // Abbiamo tolto il size
    while(fine == 0){
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
    // Mi salvo il primo polinomio della lista
    const struct polinomio* base = poly;

    // Variabile nome del file del polinomio
    char s[10];

    // Puntatore al file dove sara salvato il polinomio
    FILE *file;

    // Variabile del ciclo di stampa
    int j;

    // Salvo quanti vettori ho in totale
    int tot_structs = 1;

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

    //Prima devo definire la dimensione massima
    for(; poly->next_polinomio != NULL; poly = poly->next_polinomio){
        tot_structs += 1;
    }           

    // Stampare il polinomio su file
    // Stampo la dimensione per prima cosi so quanti coefficenti è composto il polinomio nel momento in cui dovro' caricarlo
    fprintf(file, "%d\n", poly->size+(tot_structs-1)*SIZE);
    // Stampa degli elementi del polinomio
    fprintf(file, "[");

    // Tutte le volte riparto dal primo e scorro la lista
    poly = base;

    // Ciclo tutti i vettori
    for(; poly != NULL; poly = poly->next_polinomio){
        // Ciclo tutti gli elementi del vettore
        for(j = 0 ; j < poly->size /*importante togliere il meno 1*/; j++){
            if( (poly->next_polinomio == NULL) && (j == poly->size-1) ){
                fprintf(file,"%d]\n", poly->vett[j]);
            }else{
                fprintf(file,"%d,", poly->vett[j]);
            }
        }
    }

    // Chiudere il file
    fclose(file);
}

// Carica un polinomio da FILE
void carica_polinomio(struct polinomio* poly){
    // Mi salvo il primo polinomio della lista
    const struct polinomio* base = poly;

    // Variabile nome del file del polinomio
    char s[10];

    // Puntatore al file del polinomio che sara caricato
    FILE *file;

    // Variabile del ciclo di lettura
    int j,k;

    // Dimensione polinomio e dimensione ultimo vettore
    int total_size, last_size;

    // Salvo quanti vettori ho in totale
    int tot_structs;

    printf("Inserisci nome del polinomio da caricare:");
    //Lettura del nome del file del polinomio
    scanf(" %10s",s);

    // Apertura file polinomio
    file = apri_file(s,"r");

    // Leggiamo il polinomio da file
    // Leggo la dimensione del polinomio
    fscanf(file, "%d\n", &total_size);

    tot_structs = total_size / SIZE;
    if(total_size % SIZE > 0){
        tot_structs += 1;
        last_size = total_size % SIZE;
    }else{
        last_size = SIZE;
    }

    // Leggo gli elementi del polinomio
    fscanf(file, "[");
    for(k = 1; k <= tot_structs ; k++){

        // Se non è l'ultima struttura alloco il vettore successivo
        if(k < tot_structs){
            poly->size = SIZE;
            printf("Allocazione nuovo vettore\n");
            poly->next_polinomio = malloc(sizeof(struct polinomio));
        }else{
            poly->size = last_size;
            poly->next_polinomio = NULL;
        }

        // Ciclo tutti gli elementi del vettore
        for(j = 0 ; j < poly->size; j++){
            // Se sono all'ultimo ciclo e l'ultimo elemento
            if( k == tot_structs && (j == poly->size-1) ){
                fscanf(file, "%d]", &poly->vett[j]);
            }else{
                fscanf(file, "%d,", &poly->vett[j]);
            }
        }

        // Proseguo nella lista
        if(k < tot_structs){
            poly = poly->next_polinomio;
        }  
    }

    // Stampa del polinomio uso la bese perché poly punta all'ultimo
    mostra_polinomio(base);

    // Chiudere il file
    fclose(file);
}

void mostra_polinomio(const struct polinomio* poly){

    // Mi salvo il primo polinomio della lista
    const struct polinomio* base = poly;

    // Variabile di ciclo
    int j,i,k;
    // variabile di appoggio per la stampa
    int n;
    // Salvo quanti vettori ho in totale
    int tot_structs = 1;
    // Primo elemento da stampare
    int primo = 1;


    // Verifica del polinomio
    if(poly->size == 0){
        printf("Polinomio vuoto\n");
        return;
    }

    printf("Il polinomio è:\n");
    // Ciclo del polinomio per la stampa
    for(; poly->next_polinomio != NULL; poly = poly->next_polinomio){
        tot_structs += 1;
    }

    printf("Numero di vettori è %d, numero coefficenti %d.\n",tot_structs,poly->size+(tot_structs-1)*SIZE);
    for(k = tot_structs; k > 0 ; k--){
        // Tutte le volte riparto dal primo e scorro la lista
        poly = base;
        // Vado al secondo solo se ho almeno due strutture
        for(int i = 1; i < k; i++){
            poly = poly->next_polinomio;
        }        
        for(j = poly->size-1; j >= 0 ; j--){
            if(poly->vett[j] < 0){
                printf("-");
                n = -poly->vett[j];
            }else{
                // Se non è il primo elemento e non è un elemento nullo
                if(primo == 0 && poly->vett[j] != 0){
                    printf("+");
                }
                n = poly->vett[j];
            }
            if(n != 0){
                primo = 0;
            }
            switch (j+(k-1)*SIZE)
            {
                case 0:
                    if(n != 0)
                        printf(" %d",n);
                    break;

                case 1:
                    if(n != 0)
                        printf(" %d x ",n);
                    break;
            
                default:
                    if(n != 0)
                        printf(" %d x^%d ",n,j+(k-1)*SIZE);
                    break;
            }

        }
    }

    printf("\n");
}

void valuta_polinomio(const struct polinomio* poly){
    // Mi salvo il primo polinomio della lista
    const struct polinomio* base = poly;

    // File per la valutazione del polinomio
    FILE *file;

    // Variabile ausiliarie
    double da, a, p, x, fx;

    if(poly->size == 0){
        printf("Polinomio vuoto\n");
        return;
    }

    // Salvo quanti vettori ho in totale
    int tot_structs = 1;

    // Ciclo del polinomio per la valutazione
    for(; poly->next_polinomio != NULL; poly = poly->next_polinomio){
        tot_structs += 1;
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
 
        for(int k = tot_structs; k > 0 ; k--){
            // Tutte le volte riparto dal primo e scorro la lista
            poly = base;
            // Vado al secondo solo se ho almeno due strutture
            for(int i = 1; i < k; i++){
                poly = poly->next_polinomio;
            } 
            // Valutazione del polinomio
            if(k == tot_structs){
                fx = poly->vett[poly->size-1]; 
                for(int j = poly->size-2; j >= 0 ; j--){
                    fx = fx * x + poly->vett[j];
                }
            }else{
                for(int j = poly->size-1; j >= 0 ; j--){
                    fx = fx * x + poly->vett[j];
                }                
            }
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
void moltiplica_polinomi(const struct polinomio* a, const struct polinomio* b, struct polinomio* r){
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