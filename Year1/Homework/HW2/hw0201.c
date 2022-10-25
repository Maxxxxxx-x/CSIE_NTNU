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

void Handle(int Num){
    double pi = 3.14159265358979323846;
    double C_Pi, N_Pi;
    int Count = 0;
    for (int i = 1; i <= Num; i++){
        printf("n = %d\n", (int)(i / 2) + 1);
        if (i == 1){
            C_Pi = 4;
            N_Pi = 3;
            printf("    Gregory – Leibniz series: %f (%lf)\n", C_Pi, fabs(pi - C_Pi));
            printf("    Nilakanthaseries: %f (%lf)\n", N_Pi, fabs(pi - N_Pi));
            continue;
        }
        if (i % 2 != 0){
            C_Pi -= (4 / (double) i);
            N_Pi += 4 / (double)((i - 1) * i * (i + 1));
        }else{
            C_Pi += 4 / (double) i;
            N_Pi -= 4 / (double)((i - 1) * i * (i + 1) + 1);
        }
        printf("    Gregory – Leibniz series: %lf (%lf)\n", C_Pi, fabs(pi - C_Pi));
        printf("    Nilakanthaseries: %lf (%lf)\n", N_Pi, fabs(pi - N_Pi));
    }
    return;
}

int main(){
    uint16_t Num;
    printf("Please enter n (16-bits unsigned):");
    int state = scanf("%d", &Num);
    Compare(state, 1);
    Handle(Num);
    return 0;
}