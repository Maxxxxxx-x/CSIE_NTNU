#include <stdio.h>
#include <stdlib.h>

int HandleError(int state, int req, char err[]){
    if (state != req){
        printf("%s\n", err);
        exit(1);
    }
}

int GetSlope(int X1, int Y1, int X2, int Y2){
    if (!X1 && !Y1 && !X2 && !Y2){
        HandleError(0, 1, "Unexpected error.");
    };
    int Slope;
    Slope = (Y2 - Y1) / (X2 - X1);
    return Slope;
}

int main(){
    int A_X, A_Y, B_X, B_Y, C_X, C_Y;
    int State_A, State_B, State_C;
    printf("Please enter the point A (x,y): ");
    State_A = scanf("%d,%d", &A_X, &A_Y);
    HandleError(State_A, 2, "Invalid input.");
    printf("Please enter the point B (x,y): ");
    State_B = scanf("%d,%d", &B_X, &B_Y);
    HandleError(State_B, 2, "Invalid input.");
    printf("Please enter the point C (x,y): ");
    State_C = scanf("%d,%d", &C_X, &C_Y);
    HandleError(State_C, 2, "Invalid input.");
    if (A_X == B_X && A_Y == B_Y){
        printf("Error 404: Brain not found.\n");
        return 1;
    }
    int SlopeAB = GetSlope(A_X, A_Y, B_X, B_Y);
    int SlopeCD = -1 / SlopeAB;
    //y-y1 = m(x-x1)
    int SlopeCDTimesC_X = SlopeCD * C_X;
    char Symbol[1];
    if (SlopeCDTimesC_X < 0){
        char Symbol[1] = "-";
    } else {
        char Symbol[1] = "+";
    }
    printf("y = %d * x %s %d\n", SlopeCD, Symbol, SlopeCD * C_X);
    return 0;
}