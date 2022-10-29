#include <math.h>
#include <stdio.h>
#include <limits.h>
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

int GetDigits(int64_t Num){
    return Num % 10;
}

void Calculate(uint Num){
    int length =  (int)(log10(Num) + 1);
    if (length < 0) Throw("Unexpected error: Array length is < 0", 1);
    int Digits[length];
    int Count = 0;
    int Sum = 0;
    if (Num < 10){
        printf("Final: %d\n", Num);
        return;
    }

    while (Num > 0){
        int Digit = GetDigits(Num);
        Digits[Count] = Digit;
        Num /= 10;
        Count += 1;
    }

    for (int i = Count - 1; i >= 0; i--){
        Sum += Digits[i];
        if (i != 0 ){
            printf("%d + ", Digits[i]);
            continue;
        }
        printf("%d = ", Digits[i]);
    }
    printf("%d\n", Sum);
    Calculate(Sum);
    return;
}


int main(){
    uint32_t Num;
    printf("Please enter a number: ");
    int State = scanf("%d", &Num);
    Compare(State, 1);
    if (Num > INT32_MAX){
        printf("Overflow occured!!!\n");
        uint New = 2147483647 + (2147483649 + Num);
        Calculate(New);
        return 0;
    }
    Calculate(Num);
    return 0;
}