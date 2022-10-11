#include <stdio.h>
#include <stdint.h>

int main(){
    int32_t A_X, A_Y, B_X, B_Y, C_X, C_Y;
    int State_A, State_B, State_C;
    printf("Please enter the point A (x,y): ");
    State_A = scanf("%d,%d", &A_X, &A_Y);
    if (State_A != 2){
        printf("Invalid input.\n");
        return 1;
    }
    printf("Please enter the point B (x,y): ");
    State_B = scanf("%d,%d", &B_X, &B_Y);
    if (State_B != 2){
        printf("Invalid input.\n");
        return 1;
    }
    printf("Please enter the point C (x,y): ");
    State_C = scanf("%d,%d", &C_X, &C_Y);
    if (State_C != 2){
        printf("Invalid input.\n");
        return 1;
    }
    if (A_X == B_X && A_Y == B_Y){
        printf("Point A and B cannot be the same!\n");
        return 1;
    }
    float A_X_1 = A_X;
    float A_Y_1 = A_Y;
    float B_X_1 = B_X;
    float B_Y_1 = B_Y;
    float C_X_1 = C_X;
    float C_Y_1 = C_Y;

    if (A_X_1 - B_X_1 == 0 || A_Y_1 - B_Y_1 == 0){
        if (A_Y_1 - B_Y_1 == 0){
            printf("The line: x = %d\n", C_X);
            return 0;
        }
        printf("The line: y = %d\n", C_Y); 
        return 0;
    }

    double SlopeAB = (A_Y_1 - B_Y_1) / (A_X_1 - B_X_1);
    double SlopeCD = -1 / SlopeAB;
    double C = (SlopeCD * C_X_1 * -1) + C_Y_1;
    if (C < 0){
        printf("The line: y = %lf * x - %.6lf\n", SlopeCD, C * -1);
        return 0;
    }
    printf("The line: y = %lf * x + %.6lf\n", SlopeCD, C);
    return 0;
}