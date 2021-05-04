#define STR_DIM 30
#define INCR_DIM 4

union tipo {
    struct strada *s;
    struct incrocio *i;
};

enum tipo_el{
    STRADA, INCROCIO, CHIUSA
};


struct strada{
    char nome[STR_DIM];
    enum tipo_el tipo_next;
    union tipo next;
};

struct incrocio{
    struct strada *uscita[INCR_DIM];
}; 

void percorro(struct strada *s);

void mostra_incrocio(struct incrocio *i);

struct strada* crea_strada(char *nome);

void connetti_strade(struct strada *A, struct strada *B);

void connetti_strade_incrocio(struct strada *A, struct incrocio *B);

void connetti_incrocio_strada(struct incrocio *A, int uscita, struct strada *B);

struct strada* crea_connetti(struct strada *A, char *name);

struct incrocio* crea_connetti_strada_incrocio(struct strada *A);

struct strada* crea_connetti_incrocio_strada(struct incrocio *A, int uscita, char *name);

void cancella_geometria_stradale(struct strada *A);