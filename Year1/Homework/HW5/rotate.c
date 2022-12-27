#include <math.h>

#include "rotate.h"

void rotate(double *x, double *y, double theta){
    double rx, ry;
    theta *= (M_PI / 180);
    rx = *x * cos(theta) - *y * sin(theta);
    ry = *x * sin(theta) + *y * cos(theta);
    *x = rx;
    *y = ry;      
}