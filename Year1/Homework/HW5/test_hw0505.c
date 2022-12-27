#include <stdio.h>

#include "hw0505.h"

int main(){
    uint8_t code[] = {5, 4};
    csie_interpreter(code, sizeof(code), 100);
    return 0;
}