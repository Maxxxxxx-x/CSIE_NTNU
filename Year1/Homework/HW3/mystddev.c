#include <stdint.h>
#include <stdio.h>
#include <math.h>

#include "mystddev.h"

int32_t Numbers[100];
int Number_Indx = 0;

void ClearNums(){
    for (int i = 0; i <= Number_Indx; i++){
        Numbers[i] = 0;
    }
    Number_Indx = 0;
    printf("Numbers cleared!\n");
    return;
}

void CheckClear(int32_t num){
    if (Number_Indx < 2) return;
    if (Numbers[Number_Indx] == 965 && Numbers[Number_Indx - 1] == -321 && Numbers[Number_Indx - 2] == 154){
        ClearNums();
    }
    return;
}

void AddToList(int32_t num){
    Numbers[Number_Indx] = num;
    Number_Indx++;
    return;
}

double GetSum(){
    double tmp;
    for (int i = 0; i <= Number_Indx; i++){
        tmp += Numbers[i];
    }
    return tmp;
}

double GetSigmaProduct(double mean){
    double tmp;
    for (int i = 0; i < Number_Indx; i++){
        tmp += ((Numbers[i] - mean) * (Numbers[i] - mean));
    }
    return tmp;
}

double get_stddev(int32_t number){
    AddToList(number);
    CheckClear(number);
    double sum = GetSum();
    double mean = sum / Number_Indx;
    printf("Mean: %f\n", mean);/*Why is this here? Good question! I dont even know why removing this printf() statement would break my code!!!*/
    double SigmaProduct = GetSigmaProduct(mean) / Number_Indx;
    double SD = sqrt(SigmaProduct);
    return SD;
}