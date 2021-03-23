enum tipo_elem{
    MATRICE,
    ELEMENTO
};
typedef enum tipo_elem Tipo;

struct matrice
{
    unsigned int size_x;
    unsigned int size_y;
    double** val;
};
typedef struct matrice Matrice;

struct unionmat
{   
    Tipo tipo : 1;
    union{
        double val;
        Matrice mat;
    }data;
};
typedef struct unionmat UnionMat;

void stampa_matrice(const UnionMat* mat);

void nuovo_matrice(UnionMat* mat);

// UnionMat somma_matrice(const UnionMat* a, const UnionMat* b);

// UnionMat moltiplica_matrice(const UnionMat* a, const UnionMat* b);