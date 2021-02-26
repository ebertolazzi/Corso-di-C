

// Definizione di una variaible
int val = 5;
// Questa operazione è ambigua e può essere considerata definizione o dichiarazione
// La varibile è inizializzata a zero quando globale
int num;
// Definizione una varible
int res = 10;

// Dichiarazione di una variaible static
static int tot = 10;

// Definizioni di funzione
// Qui c'è un'occupazione di memoria
int fun(){
    return tot;
}

// Questa funzione non è dichiarata dentro il .h
// Ed utilizzando la parola chiave static non è visibile da moduli esterni
static int fun2(){
    return 23;
}

// Questa è visibile dall'esterno
int fun3(){
    return fun2()+10;
}