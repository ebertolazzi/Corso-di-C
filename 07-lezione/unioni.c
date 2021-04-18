#include <stdio.h>


// Questo elemento occupa lo spazio del più grande
// e può essere inizializzado con uno o l'altro tipo
union generico {
    double reale;
    int intero;
};

// Creo una struttura con un campo unione
// L'ementento può essere uno di quei tre
// e per sapere che tipo è leggo il contenuto di tipo_union
struct var_tipo{
      int tipo_union;
      union {
              float   reale;
              char    carattere;
              int     intero;
      } elem;
};

int main(){
    union generico var; 
    var.reale = 23.5;
    printf("var = %f (%ld, dim union: %ld)\n", var.reale,sizeof(var.reale),sizeof(var));
    var.intero = 5;
    printf("var = %d (%ld, dim union: %ld)\n", var.intero,sizeof(var.intero),sizeof(var));
    
    return 0;
}