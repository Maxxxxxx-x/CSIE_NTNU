#include <stdio.h>
#include <stdlib.h>

void Throw(char Error[], int Code){
    printf("%s", Error);
    exit(Code);
}