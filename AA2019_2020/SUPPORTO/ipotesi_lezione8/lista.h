
struct elem {
    int data;
    struct elem *p;
};

// https://publications.gbdirect.co.uk/c_book/chapter8/typedef.html
typedef struct elem Elem;

void inserisci_in_cima(Elem **base, Elem *el);
void inserisci_in_fondo(Elem *base, Elem *el);
void rimuovi(Elem *base, int ind);
Elem* get(Elem *base, int ind);
Elem* set(Elem *base, int ind, int data);





