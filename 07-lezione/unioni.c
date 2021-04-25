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
enum tipo{
    REALE=0, CARATTERE=1, INTERO=2
};

tipo_union = CARATTERE;

struct var_tipo{
      enum tipo tipo_union;
      union {
              float   reale;
              char    carattere;
              int     intero;
      } elem;
};

int main(){
    union generico var; 
    var.reale = 239293293293.5;
    printf("var = %f (%ld, dim union: %ld)\n", var.reale,sizeof(var.reale),sizeof(var));
    printf("var = %d (%ld, dim union: %ld)\n", var.intero,sizeof(var.intero),sizeof(var));
    var.intero = 5;
    printf("var = %d (%ld, dim union: %ld)\n", var.intero,sizeof(var.intero),sizeof(var));
    
    return 0;
}