#include "myfunc.h"
#include <stdbool.h>
#include <stdlib.h>
#include <stdio.h>
#include <math.h>

/*
Setup a quadratic function
This function must be called before all other functions
If a == 0, return -1; otherwise, return 0.
*/

bool SetupCompleted = 0;

void CheckSetup(){
    if (SetupCompleted == 1) return;
    printf("You have to call the setup() function first!!!\n");
    exit(1);
}

int32_t quad_a, quad_b, quad_c;
int32_t setup(int32_t a, int32_t b, int32_t c){
    if (a == 0) return -1;
    SetupCompleted = 1;
    quad_a = a;
    quad_b = b;
    quad_c = c;
    return 0;
}

//Return f(x)
double Value(double x){
    CheckSetup();
    return (quad_a * (x * x)) + (b * x) + c;
}

/*
Return the minimum value of f(x) between m and n
m may be greater than / equal to / smaller than n
*/
// c - b 2 / 4a
double min(double m, double n){
    CheckSetup();
    //x = -b / 2a
    if (quad_a < 0){
        if (Value(m) < Value(n)) return Value(m);
        return Value(n);
    }
    if (m == n) return Value(m);
    double tmp_vx = -b / (2 * quad_a);
    if ((m < n) && (m < tmp_vx) && (tmp_vx < n) || (m > n) && (n < tmp_vx) && (tmp_vx < m)){
        return quad_c - ((quad_b * quad_b) / (4 * quad_a));
    }
    if (Value(m) < Value(n)) return Value(m);
    return Value(n);

}

double max(double m, double n){
    CheckSetup();
    if (quad_a > 0){
        if (Value(m) < Value(n)) return Value(m);
        return Value(n);
    }
    if (m == n) return Value(m);
    double tmp_vx = -b / (2 * quad_a);
    if ((m < n) && (m < tmp_vx) && (tmp_vx < n) || (m > n) && (n < tmp_vx) && (tmp_vx < m)){
        return quad_c - ((quad_b * quad_b) / (4 * quad_a));
    }
    if (Value(m) > Value(n)) return Value(m);
    return Value(n);
}

double slope(double t){
    CheckSetup();
    return (2 * quad_a * t) + quad_b;
}