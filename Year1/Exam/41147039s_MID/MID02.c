#include "binp.h"
#include <stdio.h>
#include <stdint.h>
#include <stdlib.h>

void throw(char error[], int code){
    printf("%s\n", error);
    exit(code);
}

void CompareInt(int Num, int Req){
    if (Num == Req) return;
    throw("Invalid input!", 1);
}

int main(){
    
    return 0;
}