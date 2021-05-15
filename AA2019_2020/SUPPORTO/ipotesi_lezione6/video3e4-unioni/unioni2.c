// Libreria di input-output
#include <stdio.h>

// Sedonda parte 
// Esampio di come possono essere utilizzate
// Creo una struttura con duntro un unione uso la variabile tipo per capire come leggere l'unione
struct example2{
      int type;
      // creo una unione senza nome del tipo cioè può essere allocato sono centro la struttura example2
      union{
        float f; // type = 0
        int i;   // type = 1
        char c;  // type = 2
      }el;
      // Se invece facevo così union example el;
      // definivo un nuovo tipo.
};

void stampa_unione(struct example2 e){
    switch (e.type)
    {
    case 0:
        printf("%f\n",e.el.f);
        break;
    case 1:
        printf("%d\n",e.el.i);
        break;
    case 2:
        printf("%c\n",e.el.c);
        break;   
    default:
        printf("tipo non riconosciuto\n");
        break;
    }
}

int main(){
    // Creo una struttura con dentro un unione
    struct example2 p;
    //Esempio di float
    p.el.f = 2.3;
    p.type = 0;
    stampa_unione(p);
    //Esempio di char
    p.el.c = 'C';
    p.type = 2;
    stampa_unione(p);
}
