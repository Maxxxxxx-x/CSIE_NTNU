#include <stdint.h>
#include <stdlib.h>
#include <stdio.h>

void Error(char Error[]){
    printf("Error: %s\n", Error);
}

/*
NOTES FOR SELF

First element will not be zero!

All elements are in range 0-9

Given integer is 100% positive
*/

void division(uint8_t **ppQuotient, u   int8_t *pQuotientSize, uint8_t **ppRemainder, uint8_t *pRemainderSize, uint8_t *pX, uint8_t xSize, uint8_t *pY, uint8_t ySize){
    for (int i = 0; i < xSize; i++){
        for (int j = 0; j < ySize; j++){
            int xDigit = pX[i];
            int yDigit = pY[j];
            if (xDigit <= 0) return;
            xDigit - yDigit;
        }
    }
}