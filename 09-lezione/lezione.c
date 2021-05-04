#include <stdlib.h>
#include <stdio.h>

#define DIM 15

int* fun(int val){
    int *a = malloc(sizeof(int));
    (*a) = val;
    return a;
}

void stampa_vett(double *v, int dim){
    // for(int i = 0;i < dim; i++){
    //     if(i == dim - 1){
    //         printf("%f]",v[i]);
    //     }else{
    //         printf("%f,",v[i]); 
    //     }
    // }  
    int i = 0;
    printf("[");
    for(;i < dim - 1; i++){
       printf("%f,",v[i]); 
       
    }
    printf("%f]\n",v[i]);
}

struct data{
    double r;
    int i;
    char str[10];
};

int main(){
    int *b = fun(6);
    printf("numero: %d\n",(*b));
    free(b);

    double *vett = malloc(sizeof(double)*DIM);
    vett[2] = 5;
    stampa_vett(vett,DIM);
    free(vett);

    struct data *d = malloc(sizeof(struct data));
    d->r = 5.3; //(*d).r = 5.3
    free(d);

    struct data t;
    t.r = 4.5;

    struct data *dd = malloc(sizeof(struct data)*DIM);
    (dd+2)->i = 5; 
    (*(dd+2)).i = 5;
    dd[2].i = 5;
    free(dd);

    int *g = calloc(1,sizeof(int));

    double *vv = calloc(DIM,sizeof(double));
    vv[2] = 15.3;
    stampa_vett(vv,DIM);

    //double *vv = realloc(vv,sizeof(double)*DIM*2);
    double *vv_new = realloc(vv,sizeof(double)*DIM*2);
    if(vv_new != NULL){
        vv = vv_new;
    }else{
        return 0;
    }
    free(vv);
    //vv = calloc(DIM,sizeof(double));
    vv = malloc(sizeof(double)*DIM);
    stampa_vett(vv,DIM);
}