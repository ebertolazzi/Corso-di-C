

#include <stdio.h>

int main(){
    int r,t = 0;
    while(r < 4/*CONDIZIONE PRIMA OPERAZIONE*/){
        /*CORPO*/
        printf("%d\n",r);
        r++;
    }

    do{
        printf("DO:%d\n",r);
        r--;
        /*CORPO PRIMA OPERAZIONE*/
    }while(r >= 0/*CONDIZIONE*/);
    printf("%d\n",r);


    for(r = 0 /*1 - INIZIALIZZAZIONE*/;r < 4 /*4 - CONDIZIONE*/; r++ /*3 - UPDATE*/){
        printf("FOR:%d\n",r);/*2 - CORPO*/
    }
    r = 0;
    do{
        printf("DO:%d\n",r);
        r++;
    }while(r < 4);
    //printf("%d\n",r);

    r = 2;
    switch(r){
        case 0:
            printf("ZERO\n");
            break;

        case 1:
            printf("UNO\n");
            break;

        case 2:
        case 3:
            printf("DUE O TRE\n");
            break;

        case 4:
            printf("QUATTRO\n");
            break;    

        default:
            printf("BHO\n");
            break;
    }

    char p = '2';
    switch(p){
        case 'o':
            printf("o\n");
            break;

        case '2':
            printf("2\n");
            break;
    }

    for(r = 0 /*1 - INIZIALIZZAZIONE*/;r < 4 /*4 - CONDIZIONE*/; r++ /*3 - UPDATE*/){
        printf("FOR:%d\n",r);/*2 - CORPO*/
        if(r == 2){
            break;/*INTERROMPE IL CICLO*/
        }
        printf("SECONDA FOR:%d\n",r);/*2 - CORPO*/
    }

    for(r = 0 /*1 - INIZIALIZZAZIONE*/;r < 4 /*4 - CONDIZIONE*/; r++ /*3 - UPDATE*/){
        printf("FOR:%d\n",r);/*2 - CORPO*/
        if(r == 2){
            continue;/*VA AL TEST DELLA CONDIZIONE*/
        }
        printf("SECONDA FOR:%d\n",r);/*2 - CORPO*/
    }

    int i = 0;
    vai:
        i++;
        if(i < 10){
            printf("i");
            goto end;
        }
    end:
        if(i < 10){
            goto vai;
        }
}