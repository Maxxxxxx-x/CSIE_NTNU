#include <time.h>
#include <stdio.h>
#include <stdlib.h>

char Separator[] = "--------\n";

int GetErrorCode(){
    srand(time(0));
    for (int i = 0; i < 1; i++){
        int num = (rand() % (499 - 400 + 1)) + 400;
        return num;
    }
}

void GetDigits(int Num, int Type, int IsAns) {
    int arr[100];
    int i = 0;
    int tmp1;
    if (IsAns == 0){
        printf("%s", Separator);
    }
    switch(Type){
        case -1:
            Num = -Num;
            printf(" - ");
            break;
        case 0:
            printf("   ");
            break;
        case 1:
            printf("-) ");
            break;
        default:
            break;
    }

    while (Num != 0) {
        tmp1 = Num % 10;
        arr[i] = tmp1;
        i += 1;
        Num /= 10;
    };
    switch(i){
        case 1:
            printf("    ");
            break;
        case 2:
            printf("  ");
    }
    for (int tmp2 = i - 1; tmp2 > -1; tmp2--){
        printf("%d ", arr[tmp2]);
    }
    printf("\n");
}

void Calculate(int Num1, int Num2){
    int Ans = Num1 - Num2;
    int AType = 0;
    if (Ans < 0){
        AType = -1;
    }
    GetDigits(Num1, 0, 1);
    GetDigits(Num2, 1, 1);
    GetDigits(Ans, AType, 0);
}

int validate(int state, int num){
    if (state == 0){
        printf("Input must be an integer.\n");
        return 1;
    }
    if (num > 999 || num < 100){
        printf("Inputted integer is not a positive 3-digit integer.\n");
        return 1;
    }
    return 0;
}

int ask(char question[]){
    int input;
    printf("%s", question);
    int state = scanf("%d", &input);
    if (validate(state, input) != 0) return -1;
    return input;
}

int main(){
    int Num1 = ask("Please enter the first  number: ");
    if (Num1 == -1){
        printf("Error %d: Invalid Input!\n", GetErrorCode());
        return 1;
    }
    int Num2 = ask("Please enter the second number: ");
    if (Num2 == -1){
        printf("Error %d: Invalid Input!\n", GetErrorCode());
        return 1;
    }
    Calculate(Num1, Num2);
    return 0;
}