#include <stdio.h>
#include <stdint.h>
#include <stdlib.h>

int CompareState(int State){
    if (State != 2){
        printf("Invalid input.\n");
        exit(1); //state mismatch
    } 
}

int ComparePoints(int32_t A_X, int32_t A_Y, int32_t B_X, int32_t B_Y){ 
    if (A_X == B_X && A_Y == B_Y){ //Same point
        printf("Point A and B cannot be the same!\n");
        exit(1);
    }}

float GetSlope(float A_X, float A_Y, float B_X, float B_Y){
    return (A_Y - B_Y) / (A_X - B_X);
}

int HandleCalculations(int32_t A_X, int32_t A_Y, int32_t B_X, int32_t B_Y, int32_t C_X, int32_t C_Y){
    //y = ax+ b
    //a = slope, b = (slope * C_X) + C_Y
    float A_X_1 = A_X;
    float A_Y_1 = A_Y;
    float B_X_1 = B_X;
    float B_Y_1 = B_Y;
    float C_X_1 = C_X;
    float C_Y_1 = C_Y;

    printf("%lf | %lf\n", A_X_1 - B_X_1, A_Y_1 - B_Y_1);
    printf("DEBUG AX - BX and AY - BY != 0\n");

    if (A_X_1 - B_X_1 == 0 || A_Y_1 - B_Y_1 == 0){
        if (A_Y_1 - B_Y_1 == 0){
            printf("The line: x = %d\n", C_X);
            return 0;
        }
        printf("The line: y = %d\n", C_Y); 
        return 0;
    }

    double SlopeAB = GetSlope(A_X_1, A_Y_1, B_X_1, B_Y_1);
    printf("SlopeAB = %lf\n", SlopeAB); //rmv later
    double SlopeCD = -1 / SlopeAB;
    double C = (SlopeCD * C_X_1 * -1) + C_Y_1;
    printf("C is actually %.15f\n", C);
    if (C < 0){
        printf("C < 0\n");
        printf("The line: y = %lf * x - %.6lf\n", SlopeCD, C * -1);
        return 0;
    }
    printf("The line: y = %lf * x + %.6lf\n", SlopeCD, C);
    return 0;
}

int main(){
    int32_t A_X, A_Y, B_X, B_Y, C_X, C_Y;
    int State_A, State_B, State_C;
    printf("Please enter the point A (x,y): ");
    State_A = scanf("%d,%d", &A_X, &A_Y);
    CompareState(State_A);
    printf("Please enter the point B (x,y): ");
    State_B = scanf("%d,%d", &B_X, &B_Y);
    CompareState(State_B);
    printf("Please enter the point C (x,y): ");
    State_C = scanf("%d,%d", &C_X, &C_Y);
    CompareState(State_C);
    ComparePoints(A_X, A_Y, B_X, B_Y);
    HandleCalculations(A_X, A_Y, B_X, B_Y, C_X, C_Y);
}