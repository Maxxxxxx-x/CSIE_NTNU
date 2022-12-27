#ifndef RIEMANN_H_
#define RIEMANN_H_
#include <math.h>
#include <stdio.h>
#include <stdint.h>
double riemann_sum(int32_t coefficients[], int32_t powers[], int32_t size, double a, double b, int32_t n);
#endif