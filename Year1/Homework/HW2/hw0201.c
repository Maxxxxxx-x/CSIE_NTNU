#include <math.h>
#include <stdio.h>
#include <stdint.h>
#include <stdlib.h>

void Throw(char Error[], int Code){
    printf("%s\n", Error);
    exit(Code);
}

void Compare(int Num, int Required){
    if (Num == Required) return;
    Throw("Invalid input!", 1);
}

void OutputResults(double C_Pi, double N_Pi, double pi){
    double C_diff = fabs(pi - C_Pi);
    double N_diff = fabs(pi - N_Pi);
    printf("    Gregory – Leibniz series: %lf (%f)\n    Nilakantha series: %lf (%f)\n", C_Pi, C_diff, N_Pi, N_diff);
}

void Handle(int Num){
    double pi = 3.14159265358979323846;
    double C_Pi = 0;
    double N_Pi = 3;

    for (int i = 1; i <= Num; i++){
        printf("n = %d:\n", i);
        float NewDenom = 0;
        for (int j = 0; j < i; j++){
            NewDenom = i + j;
        }
        if (i % 2 == 0){
            C_Pi -= 4 / NewDenom;
            N_Pi += 4 / ((NewDenom - 1) * NewDenom * (NewDenom + 1));
        }else{
            C_Pi += 4 / NewDenom;
            if (i != 1){
                N_Pi -= 4 / ((NewDenom - 1) * NewDenom * (NewDenom + 1));
            }
        }
        //printf("%d\n", NewDenom);
        OutputResults(C_Pi, N_Pi, pi);
    }
}

int main(){
    uint16_t Num;
    printf("Please enter n (16-bits unsigned): ");
    int state = scanf("%d", &Num);
    Compare(state, 1);
    Handle(Num);
    return 0;
}