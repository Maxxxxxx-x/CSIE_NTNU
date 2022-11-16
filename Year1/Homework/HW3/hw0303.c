#include <stdlib.h>
#include <stdint.h>
#include <limits.h>
#include <stdio.h>

#include "resistance.h"

void throw(char Error[], int code){
    printf("%s\n", Error);
    exit(code);
}

void CompareState(int state, int required){
    if (state == required) return;
    throw("Invalid input!", 1);
}

int32_t AskResistance(){
    int32_t tmp;
    printf("Please enter the resistance (1 - 100): ");
    int state = scanf("%d", &tmp);
    if (tmp > 2147483647){
        printf("Invalid input! Inputted Resistance was not a 32-bit integer!\n");
        AskResistance();
    }
    if (tmp < 1 || tmp > 100){
        printf("Invalid input! Resistance out of range!\n");
        AskResistance();
    }
    return tmp;
}

int32_t AskN(){
    int32_t tmp;
    printf("Please enter n (1 - 100): ");
    int state = scanf("%d", &tmp);
    if (tmp > 2147483647){
        printf("Invalid input! Inputted n was not a 32-bit integer!\n");
        AskN();
    }
    if (tmp < 1 || tmp > 100){
        printf("Invalid input! n out of range!\n");
        AskN();
    }
    return tmp;
}

int main(){
    int32_t res = AskResistance();
    int32_t n = AskN();
    double Ans = CalculateResistance(res, n);
    printf("Ans: %f\n", Ans);
    return 0;
}