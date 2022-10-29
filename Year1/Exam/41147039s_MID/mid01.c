#include <math.h>
#include <stdio.h>
#include <stdlib.h>

void throw(char Error[], int Code){
    printf("%s", Error);
    exit(Code);
}

void CompareInt(int Num, int Req){
    if (Num == Req) return;
    throw("Invalid input!", 1);
}

void CompareDouble(double Num1, double Num2){
    if (abs(Num1) == abs(Num2)) return;
    throw("Not a rectangle!", 1);
}

void IsRightAngle(double X1, double Y1, double X2, double Y2, double X3, double Y3){
    double a = sqrt(((X2 - X1) * (X2 - X1)) + ((Y2 - Y1) * (Y2 - Y1)));
    double b = sqrt(((X3 - X2) * (X3 - X2)) + ((Y3 - Y2) * (Y3 - Y2)));
    double c = sqrt(((X3 - X1) * (X3 - X1)) + ((Y3 - Y1) * (Y3 - Y1)));
    if (abs(a * a + b * b) == abs(c * c)) return;
    throw("Not a rectangle!", 1);
}

double GetLength(double X1, double Y1, double X2, double Y2){
    double tmp = sqrt(((X2 - X1) * (X2 - X1)) + ((Y2 - Y1) * (Y2 - Y1)));
    return tmp;
}  

void GetLine(double X1, double Y1, double X2, double Y2){ //X1, Y1 = Center of rectangle, X2, Y2 = P
    printf("Line: ");
    if (X1 == X2 && Y1 == Y2){
        printf("y = %0.2f\n", X1);
        return;
    }
    double a = (Y2- Y1) / (X2 - X1);
    double b = (a * X1 * -1) + Y1;
    if (b < 0){
        printf("y = %0.2f * x - %0.2f\n", a, b);
        return;
    }
    printf("y = %0.2f * x + %0.2f\n", a, b);
    return;
}

int main(){
    char c;
    double P1_X, P1_Y, P2_X, P2_Y, P3_X, P3_Y, P4_X, P4_Y, P_X, P_Y;
    int state;
    printf("P1(x,y): ");
    state = scanf("%lf,%lf", &P1_X, &P1_Y);
    CompareInt(state, 2);
    printf("P2(x,y): ");
    state = scanf("%lf,%lf", &P2_X, &P2_Y);
    CompareInt(state, 2);
    printf("P3(x,y): ");
    state = scanf("%lf,%lf", &P3_X, &P3_Y);
    CompareInt(state, 2);
    printf("P4(x,y): ");
    state = scanf("%lf,%lf", &P4_X, &P4_Y);
    CompareInt(state, 2);
    printf("P(x,y): ");
    state = scanf("%lf,%lf", &P_X, &P_Y);
    CompareInt(state, 2);
    //Compare lengths
    //Length
    double P1P2_Length = GetLength(P1_X, P1_Y, P2_X, P2_Y);
    double P3P4_Length = GetLength(P3_X, P3_Y, P4_X, P4_Y);
    //Width
    double P2P3_Length = GetLength(P2_X, P2_Y, P3_X, P3_Y);
    double P1P4_Length = GetLength(P1_X, P1_Y, P4_X, P4_Y);
    CompareDouble(P1P2_Length, P3P4_Length); //Compare lines P1P2, P3P4
    CompareDouble(P2P3_Length, P1P4_Length); //Compare lines P2P3, P1P4
    //Compare Angles
    IsRightAngle(P4_X, P4_Y, P1_X, P1_Y, P2_X, P2_Y); //Angle P412
    IsRightAngle(P1_X, P1_Y, P2_X, P2_Y, P3_X, P3_Y); //Angle P123
    IsRightAngle(P2_X, P2_Y, P3_X, P3_Y, P4_X, P4_Y); //Angle P234
    IsRightAngle(P3_X, P3_Y, P4_X, P4_Y, P1_X, P1_Y); //Angle P341
    double Center_X = P1P2_Length / 2;
    double Center_Y = P1P4_Length / 2;
    printf("Center of Rectangle: X = %lf, Y = %lf\n", Center_X, Center_Y);
    GetLine(Center_X, Center_Y, P_X, P_Y);
    return 0;
}