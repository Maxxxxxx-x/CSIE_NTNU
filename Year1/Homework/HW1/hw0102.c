#include <stdio.h>
#include <stdint.h>

int main(){
    int32_t First, Second;
    printf("Please enter the first  number: ");
    int state;
    state = scanf("%d", &First);
    if (state != 1){
        printf("Invalid input");
        return 1;
    }
    if (First > 999 && First < 100){
        printf("Number is not a 3 digit non-negative integer.\n");
        return 1;
    }
    printf("Please enter the second number: ");
    state = scanf("%d", &Second);
    if (state != 1){
        printf("Invalid input");
        return 1;
    }
    if (Second > 999 && Second < 100){
        printf("Number is not a 3 digit non-negative integer.\n");
        return 1;
    }
    int32_t Result = First - Second;
    int32_t AType;
    if (Result < 0){
        AType = -1;
        Result *= -1;
    }
    int32_t F1, F2, F3;
    int32_t S1, S2, S3;
    int32_t R1, R2, R3;
    F1 = (First / 100) % 10;
    F2 = (First / 10) % 10;
    F3 = First % 10;
    printf("\n");
    S1 = (Second / 100) % 10;
    S2 = (Second / 10) % 10;
    S3 = Second % 10;
    printf("\n");
    if (Result >= 100){
        R1 = (Second / 100) % 10;
        R2 = (Second / 10) % 10;
        R3 = Second % 10;
    }else if (Result >= 10 && Result <= 100){
        R2 = (Result / 10) % 10;
        R3 = Result % 10;
    } else if (Result > 0 && Result < 10){
        R3 = Result;
    }
    printf("\n");

    printf("   %d %d %d\n", F1, F2, F3);
    printf("-) %d %d %d\n", S1, S2, S3);
    printf("--------\n");
    if (AType == -1){
        if (Result >= 100){
            printf(" - %d %d %d\n", R1, R2, R3);
            return 0;
        }
        if (Result >= 10 && Result < 100){
            printf(" -   %d %d\n", R2, R3);
            return 0;
        }
        if (Result >= 0 && Result < 10){
            printf(" -     %d\n", R3);
            return 0;
        }
    }
    if (Result >= 100){
        printf("   %d %d %d\n", R1, R2, R3);
        return 0;
    }
    if (Result >= 10 && Result < 100){
        printf("     %d %d\n", R2, R3);
        return 0;
    }
    if (Result >= 0 && Result < 10){
        printf("       %d\n", R3);
        return 0;
    }
    return 0;
}       