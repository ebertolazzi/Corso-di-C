
enum tipo_elem{
    MATRICE,
    VETTORE_RIGA,
    VETTORE_COLONNA,
    ELEMENTO
};
typedef enum tipo_elem Tipo;

struct matrice
{
   unsigned int size_x;
   unsigned int size_y;
   double **val;
};
typedef struct matrice Matrice;

struct vettore
{
    unsigned int size;
    double *val;
};
typedef struct vettore Vettore;

struct unionmat
{
    Tipo tipo : 2;
    union
    {
        double val;
        Vettore vet;
        Matrice mat;
    }data;
};
typedef struct unionmat UnionMat;

void stampa_matrice(const UnionMat* mat);

void nuova_matrice(UnionMat* mat);

// UnionMat somma_matrice(const UnionMat* a, const UnionMat* b);

// UnionMat moltiplica_matrice(const UnionMat* a, const UnionMat* b);

// int determinante(const UnionMat* mat);