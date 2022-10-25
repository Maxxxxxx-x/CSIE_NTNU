#include <math.h>
#include <stdio.h>
#include <stdlib.h>
#include <stdint.h>

void Throw(char Error[], int Code){
    printf("%s\n", Error);
    exit(Code);
}

void CompareState(int State, int Required){
    if (State == Required) return;
    Throw("Invalid input.", 1);
}

void CompareInt(uint16_t Val){
    if (Val <= INT16_MAX) return;
    Throw("Given integer is not 16 bits.", 1);
}

void Gregory(int i){
    if (i % 2 == 0) i += 1;
    double New = (double) i;
    double Ans = 4 / New;
    printf("    Gregory – Leibniz series: %f\n", Ans);
    return;
}   


int main(){
    uint16_t Val;
    printf("Please enter n (16-bits unsigned): ");
    int State = scanf("%d", &Val);
    CompareState(State, 1);
    CompareInt(Val);
    double N_Pi;
    double N_S = 1;
    for (int i = 1; i <= Val; i++){
        printf("n = %d\n", i);
        Gregory(i);
        //Nilakantha
        double N_Pi;
        double N_S = 1;
        for (double k = 2; k <= i * 2; k += 2){
            N_Pi = N_Pi + N_S * (4 / (k * (k + 1) * (k + 2)));
            N_S = -N_S;
        }
        double Between = 3.14159265358979323846 - N_Pi;
        printf("    Nilakantha series: %f (%f)\n", N_Pi, Between);
    }
    return 0;
}

