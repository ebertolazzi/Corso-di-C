
static int rr = 0;

int g;

static int fun(const int *p){
    int r = (*p);
    //(*p) = 4;
}

int fun2(int *p){
    static int count = 0; 
    count++;
    p[2] = 4;
    int r = (*p);
    rr = count;
    //(*p) = 4;
}
