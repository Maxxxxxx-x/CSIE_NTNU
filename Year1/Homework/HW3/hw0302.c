#include <stdint.h>
#include <stdio.h>

#include "mystddev.h"

void a(){
    int32_t input;
    scanf("%d",&input);
    double sd = get_stddev(input); 
    printf("SD: %f\n", sd);
    a();
}

int main(){
    a();
}