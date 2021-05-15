//Libreria di input-output
#include <stdio.h>
// Libreria per allocazione dinamica
#include <stdlib.h>
// Libreria stringhe
#include <string.h>

//Libreria funzioni sui polinomi
#include "lib/lib_lista_poly.h"

// Vettore di polinomi
Elem *base_poly = NULL;

int scegli_indice(char *string){
    int d;
    printf("%s",string);
    scanf(" %d",&d);
    return d;
}

int leggo_parametro(int argc, char *argv[], int *ind /* Indica la posizione a cui sono arrivato*/){ 
    if((*ind) >= argc){
        printf("Parametri finiti\n");
        return EXIT_FAILURE;
    }
    if(strlen(argv[*ind]) == 2){
        switch (argv[*ind][1] /* Leggo il secondo carattere che indica il comando */)
        {
        case 'q': // Zero parametri
            exit(EXIT_SUCCESS);
            /*printf("Lettura zero parametri successivi\n");
            (*ind) += 1;*/

        case 'c': // Un parametro
            if((*ind) + 1 < argc){
                Elem * p = calloc(1,sizeof(Elem));
                carica_polinomio_stringa(argv[(*ind) + 1],&p->poly);
                int pos = inserisci_in_fondo(&base_poly, p);
                printf("Il polinomio caricato da file in posizione %d è:\n",pos);
                mostra_polinomio(&p->poly);
                (*ind) += 2;
                return EXIT_SUCCESS;
            }
            break;

        case 's':
            if((*ind) + 1 < argc){
                Elem *p;
                int i = 0;
                int ind_poly = atoi(argv[(*ind) + 1]);
                for(i = 0, p = base_poly; p != NULL && i < ind_poly; p = p->next, i++);
                if(p == NULL){
                    printf("Indice errato\n");
                }else{
                    salva_polinomio(&p->poly);
                }
                (*ind) += 2;
                return EXIT_SUCCESS;
            }
            break;

        case 'd': // Due parametro
            /*if((*ind) + 2 < argc){
                printf("Lettura due parametri successivi: %s, %s\n", argv[(*ind) + 1], argv[(*ind) + 2]);
                (*ind) += 3;
                return EXIT_SUCCESS;
            }*/
            break;   

        default:
            printf("Parametro non riconosciuto\n");
            return EXIT_FAILURE;
        }
        printf("Numero parametri errato\n");
        return EXIT_FAILURE;        
    }else{
        printf("Parametro non conforme\n");
        return EXIT_FAILURE;        
    }
}

void ciclo_principale(){
    // Caratte di input
    char c;
    // Fine programma
    int fine = 0;
    // Elemento ausiliario della lista
    Elem *p, *pp, *ppp;
    // indici utili per le operazioni sui polinomi
    int i, ind, inda, indb, indr;
    // Ciclo do while delle operazioni
    do{
        printf("Scegli comando:\n");
        printf("n - crea nu nuovo polinomio\n");
        printf("c - carica un polinomio\n");
        printf("s - salva polinomio corrente\n");
        printf("v - valuta polinomio corrente\n");
        printf("m - mostra a schermo un polinomio\n");
        printf("p - somma due polinomi\n");
        printf("x - moltiplica due polinomi\n");        
        printf("q - per terminare\n");

        scanf(" %c", &c);

        switch (c) {
            case 'n':
                p = calloc(1,sizeof(Elem));
                nuovo_polinomio(&p->poly);
                inserisci_in_cima(&base_poly, p);
                printf("Il nuovo polinomio in posizione 0 è:\n");
                mostra_polinomio(&p->poly);
                break;

            case 'c':
                p = malloc(sizeof(Elem));
                carica_polinomio(&p->poly);
                inserisci_in_cima(&base_poly, p);
                printf("Il polinomio caricato da file in posizione 0 è:\n");
                mostra_polinomio(&p->poly);
                break;

            case 's':
                ind = scegli_indice("Scegli l'indice del polinomio da salvare:");
                for(i = 0, p = base_poly; p != NULL && i < ind; p = p->next, i++);
                if(p == NULL){
                    printf("Indice errato\n");
                }else{
                    salva_polinomio(&p->poly);
                }
                break;

            case 'v':
                ind = scegli_indice("Scegli l'indice del polinomio da valutare:");
                for(i = 0, p = base_poly; p != NULL && i < ind; p = p->next, i++);
                if(p == NULL){
                    printf("Indice errato\n");
                }else{
                    valuta_polinomio(&p->poly);
                }
                break;

            case 'm':
                for(i = 0, p = base_poly; p != NULL ; p = p->next, i++){
                    printf("Il polinomio in posizione %d è:\n",i);
                    mostra_polinomio(&p->poly);
                }
                break;

            case 'p':
                inda = scegli_indice("Somma due polinomi, scegli l'indice del primo:");
                for(i = 0, p = base_poly; p != NULL && i < inda; p = p->next, i++);
                if(p == NULL){
                    printf("Indice errato\n");
                    break;
                }else{
                    mostra_polinomio(&p->poly);
                }
                indb = scegli_indice("Scegli l'indice del secondo:");
                for(i = 0, pp = base_poly; pp != NULL && i < indb; pp = pp->next, i++);
                if(pp == NULL){
                    printf("Indice errato\n");
                    break;
                }else{
                    mostra_polinomio(&pp->poly);
                }
                ppp = malloc(sizeof(Elem));
                somma_polinomi(&p->poly,&pp->poly,&ppp->poly);
                //ppp->poly = somma_polinomi_valore(&p->poly,&pp->poly);
                inserisci_in_cima(&base_poly, ppp);
                printf("Il polinomio risultato in posizione 0 è:\n");
                mostra_polinomio(&ppp->poly);
                break;

            case 'x':
                inda = scegli_indice("Moltiplica due polinomi, scegli l'indice del primo:");
                for(i = 0, p = base_poly; p != NULL && i < inda; p = p->next, i++);
                if(p == NULL){
                    printf("Indice errato\n");
                    break;
                }else{
                    mostra_polinomio(&p->poly);
                }
                indb = scegli_indice("Scegli l'indice del secondo:");
                for(i = 0, pp = base_poly; pp != NULL && i < indb; pp = pp->next, i++);
                if(pp == NULL){
                    printf("Indice errato\n");
                    break;
                }else{
                    mostra_polinomio(&pp->poly);
                }
                ppp = malloc(sizeof(Elem));
                moltiplica_polinomi(&p->poly,&pp->poly,&ppp->poly);
                inserisci_in_cima(&base_poly, ppp);
                printf("Il polinomio risultato in posizione 0 è:\n");
                mostra_polinomio(&ppp->poly);
                break;

            case 'q':
                fine = 1;
                break;
                    
            default:
                printf("Comando errato.\n");
                break;
        }
    }while(fine == 0);

    // Pulizia memoria
    while (base_poly != NULL){
        p = rimuovi_at(&base_poly, 0);
        free_polinomio(&p->poly);
        free(p);
    }
}


int main(int argc, char* argv[]){
    // Lettura dei parametri
    int ind = 1;
    while(leggo_parametro(argc, argv, &ind) == 0);
    // Ciclo principale
    ciclo_principale();
}