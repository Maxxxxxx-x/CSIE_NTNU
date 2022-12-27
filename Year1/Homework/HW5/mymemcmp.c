int mymemcmp(void *a, void *b, int n){
    unsigned char *c = a;
    unsigned char *d = b;
    while (n > 0){
        if (*c != *d){return *c - *d;}
        n--;
        c++;
        d++;
    }
    return 0;
}