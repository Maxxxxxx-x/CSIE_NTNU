#include <stdio.h>
#include <stdint.h>

char Separator[] = "--------\n";

int GetDigit(int32_t Num, int32_t pos){
 
    switch(pos){
        case 1:
        printf("%d", (Num / 100) % 10);
        return (Num / 100) % 10;
        
        case 2:
        printf("%d", (Num / 10) % 10);
        return (Num / 10) % 10;
        
        case 3:
        printf("%d", Num % 10);
        return Num % 10;
    }
}

int FormatPrint(int32_t First, int32_t Second, int32_t Result){
    int32_t AType;
    if (Result < 0){
        AType = -1;
        Result *= -1;
    }
    int32_t F1, F2, F3;
    int32_t S1, S2, S3;
    int32_t R1, R2, R3;
    F1 = GetDigit(First, 1);
    F2 = GetDigit(First, 2);
    F3 = GetDigit(First, 3);
    printf("\n");
    S1 = GetDigit(Second, 1);
    S2 = GetDigit(Second, 2);
    S3 = GetDigit(Second, 3);
    printf("\n");
    if (Result >= 100){
        R1 = GetDigit(Result, 1);
        R2 = GetDigit(Result, 2);
        R3 = GetDigit(Result, 3);
    }else if (Result >= 10 && Result <= 100){
        R2 = GetDigit(Result, 2);
        R3 = GetDigit(Result, 3);
    } else if (Result > 0 && Result < 10){
        R3 = Result;
    }
    printf("\n");

    printf("   %d %d %d\n", F1, F2, F3);
    printf("-) %d %d %d\n", S1, S2, S3);
    printf("%s", Separator);
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

int ask(char Question[]){
    int32_t Tmp;
    printf("%s", Question);
    int32_t state = scanf("%d", &Tmp);
    if (state == 0){
        printf("Unexpeted input.\n");
        return -1;
    }
    if (Tmp > 999 && Tmp < 100){
        printf("Inputted number is not a 3 digit non-negative integer.\n");
        return -1;
    }
    return Tmp;
}

int main(){
    int32_t First = ask("Please enter the first  number: ");
    if (First == -1){
        return 1;
    }
    int32_t Second = ask("Please enter the second number: ");
    if (Second == -1){
        return 1;
    }
    int32_t Result = First - Second;
    FormatPrint(First, Second, Result);
    return 0;
}