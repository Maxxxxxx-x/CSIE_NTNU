#include <stdint.h>
#include <stdio.h>
#include <math.h>

#include "riemann.h"

double riemann_sum(int32_t coefficients[], int32_t powers[], int32_t size, double a, double b, int32_t n){
    double sum = 0;
    double h = (b - a) / n;
    for (int i = 0; i < n; i++){
        double x = a + (h * i);
        double y = 0;
        for (int j = 0; j < size; j++){
            y += coefficients[j] * pow(x, powers[j]);
        }
        sum += y * h;
    }
    return sum;
}