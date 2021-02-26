
#include <stdio.h>

// Link ai Bitfield
// https://publications.gbdirect.co.uk/c_book/chapter6/bitfields.html
struct bitfield
{   
    // Link ai tipi C
    // https://en.wikipedia.org/wiki/C_data_types

    // Dimensione della nostra struttura: 2 byte = 16 bit
    // short unsigned primo : 1;  // Questa variabile a dimensione 1 bit
    // short unsigned secondo : 15; 
    
    // Dimensione della nostra struttura: 4 byte = 32 bit
    // short unsigned primo : 1;     // Questa variabile a dimensione 1 bit
    // short unsigned secondo : 16;  // Questa variabile a dimensione 16 bit

    // Dimensione della nostra struttura: 4 byte = 32 bit   
    // short unsigned primo : 1;  
    // short unsigned secondo : 15; 
    // unsigned terzo : 3;
    // unsigned quarto : 13;

    // Dimensione della nostra struttura: 8 byte = 64 bit
    // No padding
    // short unsigned primo : 1;  
    // short unsigned secondo : 15; 
    // unsigned terzo : 3;
    // unsigned quarto : 13;
    // int quinto;

    // Dimensione della nostra struttura: 12 byte = 96 bit
    // short signed primo : 1;  
    // short unsigned secondo : 15; 
    // unsigned terzo : 3;
    // unsigned quarto : 13;
    // short sesto : 1; // Questo short occupa in realtà ben 4 byte
    // int quinto;

    short signed primo : 3;  
}bits;


int main(){
    printf("Dimensione di un short unsigned: %lu byte = %lu bit\n", sizeof(short unsigned), sizeof(short unsigned)*8);
    printf("Dimensione di un unsigned: %lu byte = %lu bit\n", sizeof(unsigned), sizeof(unsigned)*8);
    printf("Dimensione di un unsigned: %lu byte = %lu bit\n", sizeof(int), sizeof(int)*8);
    printf("Dimensione della nostra struttura: %lu byte = %lu bit\n", sizeof(struct bitfield), sizeof(struct bitfield)*8);

    printf("Valori assunti dai nostri dati:\n");
    for(int i = 0; i < 32; i++){
        printf("%d ",bits.primo++);
    }
    printf("\n");
}

