#include <stdio.h>

void fun(int r[5],int dim){
    for(int i=0;i<dim;i++){
        printf("%d,",r[i]);
    }
}

void stampa(char str[]){
    int i = 0;
    printf("%s\n\n",str);
    while(str[i]!='\0'){
        printf("%c",str[i]);
        i++;
    }
}

int main(){
    char str2[]={'G','a','s','\0'};
    char str[]="Gastone"; //'\0'

    int dim = 12;
    int r[] = {1,2,3,4,5};
    int m[2][3] = {1,2,3,4,5,6};
    // for(int i=0;i<2;i++){
    //     for(int j=0;j<3;j++){
    //         printf("%d,",m[i][j]);
    //     }
    // }
    // fun(r,dim);
    stampa(str2);
}