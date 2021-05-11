#include <stdio.h>

// L'utilizzo di euste strutture è uguale alle altre strutture
// unica differenza è che si sceglie la dimensione rispetto al numero di bit per ogni campo.
struct info{
    // Questo numero intero è senza segno ed occupa 4 bit
    unsigned f:4;
    //I tipi ammessi sono quelli per gli interi
    // double g:2; Questo non è ammesso
    // Questo numero intero con segno il segno da 2 bit (valori ammissibili -2 -1 0 1)
    signed g:2;
    // Numero intero con segno da 1 bit (valori ammissibili -1 0)
    signed t:1;
};

struct info2{
    unsigned f:4;
    signed g:2;
    signed t:1;
    unsigned k:30;
};

int main(){
    struct info el;
    printf("dimensione: %ld, numero di bit totali: %ld\n",sizeof(el),sizeof(el)*8);
    printf("dimensione: %ld, numero di bit totali: %ld\n",sizeof(struct info2),sizeof(struct info2)*8);
}