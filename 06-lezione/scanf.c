 #include<stdio.h>
 #include<stdlib.h>
 
 int main(){
    //Stringa 
    char s[5];
    //Intero letto
    int n;

    // Leggo fino a trovare un intero
    while(!scanf(" %d", &n))
    {
        // Funzione per pulire il buffer leggo qualunque cosa fino all'accapo.
        scanf("%*[^\n]");
        printf("Non ho letto un intero!\n");
    }

    printf("Inserisci un numero:");
    // Leggo una stringa
    scanf(" %s",s);
    printf("Strina letta: %s\n",s);

    //Conversione della stringa s in intero
    //https://en.cppreference.com/w/cpp/string/byte/atoi
    n = atoi(s);
    printf("%d",n);
 }