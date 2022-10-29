#ifndef mid05_h
# define mid05_h

#include <math.h>

double P1_X, P1_Y;
double P2_X, P2_Y;
double P3_X, P3_Y;

int set_point_1(double x, double y){
    if (!x || !y) return 1;
    P1_X = x;
    P1_Y = y;
    return 0;
}

int set_point_2(double x, double y){
    if (!x || !y) return 1;
    P2_X = x;
    P2_Y = y;
    return 0;
}

int set_point_3(double x, double y){
    if (!x || !y) return 1;
    P3_X = x;
    P3_Y = y;
    return 0;
}

int check(void){
    
    double GetAngle(double x1, double y1, double x2, double y2, double x3, double y3){
        double tmp1 = x1- x2;
        double tmp2 = y1 - y2
        double tmp3 = x1 - x3;
        double tmp4 = y1 - y3;
        double feta = arccos()
    }
    double a, b, c;
    a = GetAngle(P1_X, P1_Y, P2_X, P2_Y, P3_X, P3_Y);
    b = GetAngle(P1_X, P1_Y, P3_X, P3_Y, P2_X, P2_Y);
    c = GetAngle(P3_X, P3_Y, P1_x, P1_Y, p2_X, P2_Y);
}


#endif