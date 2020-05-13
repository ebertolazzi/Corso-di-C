

int main(){
    // Definizione di due interi
    int n, g;
    // Definizione di un puntatore ad intero const
    const int* a = &g;
    // Questa notazione è equivalente
    int const* aa = &g;
    // Cioè non posso modificare il valore di g attraverso a
    // (*a) = 5;

    // Putatori constanti
    // Questi puntatori non possono puntate a qualcosa di diverso
    int *const b = &n;
    // Quindi questa operazione è illecita
    //b = &g;

    // Casistica finale
    // Puntatore costante a const int
    const int *const c = &n;
    // Non posso modificare il contentuo e non posso modificare l'indirizzo
    //c = &g;
    //(*c) = 5;

    //https://stackoverflow.com/questions/1143262/what-is-the-difference-between-const-int-const-int-const-and-int-const
}